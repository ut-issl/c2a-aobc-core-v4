#pragma section REPRO
/**
* @file   ina260.c
* @brief  INA260のDriver
*/

#include "ina260.h"

#include <string.h>
#include <src_core/library/print.h>
#include <src_core/library/endian.h>
#include <src_user/settings/component_driver/driver_buffer_define.h>

#define INA260_STREAM_TLM_CMD  (0)
#define INA260_RX_FRAME_SIZE   (2)

const static uint8_t  INA260_kCmdIdSetConfig_     = 0x00;
const static uint8_t  INA260_kCmdIdReadCurrent_   = 0x01;
const static uint8_t  INA260_kCmdIdReadVoltage_   = 0x02;
const static uint8_t  INA260_kCmdIdLimitMask_     = 0x06;
const static uint8_t  INA260_kCmdIdSetLimitValue_ = 0x07;
const static float    INA260_kConvertObservation_ = 1.25f; //!< 観測電流・電圧値をmA, mV単位に直す係数
const static float    INA260_kConvertOverCurrent_ = 0.8f;  //!< 過電流閾値をレジスタに書き込むときの変換係数

static uint8_t INA260_tlm_id_ = 0x00; //!< 今読んでいるデータのTLM ID、コマンドIDと対応する

static CDS_ERR_CODE INA260_load_driver_super_init_settings_(ComponentDriverSuper* p_super);
static CDS_ERR_CODE INA260_analyze_rec_data_(CDS_StreamConfig* p_stream_config, void* p_driver);
static CDS_CMD_ERR_CODE INA260_set_parameter_(INA260_Driver* ina260_driver, uint8_t cmd_id, uint16_t parameter);
static CDS_CMD_ERR_CODE INA260_observe_(INA260_Driver* ina260_driver, uint8_t cmd_id);
static float INA260_convert_current_mA_(const int16_t current_raw);
static float INA260_convert_voltage_V_(uint16_t voltage_raw);
static uint16_t INA260_set_mode_with_bit_shift_(const uint16_t mode,
                                                const uint16_t param,
                                                const uint16_t mask,
                                                const uint8_t  shift_value);

CDS_INIT_ERR_CODE INA260_init(INA260_Driver* ina260_driver, uint8_t ch, uint8_t i2c_address, CDS_StreamRecBuffer* rx_buffer)
{
  ina260_driver->info.current_mA = 0.0f;
  ina260_driver->info.voltage_V = 0.0f;
  ina260_driver->info.current_raw = 0;
  ina260_driver->info.voltage_raw = 0;
  ina260_driver->info.oc_threshold_raw = 0;
  ina260_driver->info.averaging_mode = INA260_AVERAGING_MODE_1;
  ina260_driver->info.voltage_conversion_time = INA260_CONVERSION_TIME_1MS;
  ina260_driver->info.current_conversion_time = INA260_CONVERSION_TIME_1MS;

  CDS_ERR_CODE ret;

  ina260_driver->driver.i2c_config.ch = ch;
  ina260_driver->driver.i2c_config.device_address = i2c_address;
  ina260_driver->driver.i2c_config.frequency_khz = 100;
  ina260_driver->driver.i2c_config.stop_flag = 1;
  ina260_driver->driver.i2c_config.timeout_threshold = 500;

  ret = CDS_init(&(ina260_driver->driver.super),
                 &(ina260_driver->driver.i2c_config),
                 rx_buffer,
                 INA260_load_driver_super_init_settings_);
  if (ret != CDS_ERR_CODE_OK) return CDS_INIT_CDS_INIT_ERR;
  return CDS_INIT_OK;
}

CDS_CMD_ERR_CODE INA260_set_mode(INA260_Driver* ina260_driver,
                                 INA260_AVERAGING_MODE averaging_mode,
                                 INA260_CONVERSION_TIME voltage_conversion_time,
                                 INA260_CONVERSION_TIME current_conversion_time)
{
  if (averaging_mode >= INA260_AVERAGING_MODE_MAX) return CDS_CMD_ILLEGAL_PARAMETER;
  if (voltage_conversion_time >= INA260_CONVERSION_TIME_MAX) return CDS_CMD_ILLEGAL_PARAMETER;
  if (current_conversion_time >= INA260_CONVERSION_TIME_MAX) return CDS_CMD_ILLEGAL_PARAMETER;

  uint16_t mode = 0x6007; // 初期値は固定
  mode = INA260_set_mode_with_bit_shift_(mode, (uint16_t)(averaging_mode), 0x0e00, 9);
  mode = INA260_set_mode_with_bit_shift_(mode, (uint16_t)(voltage_conversion_time), 0x01c0, 6);
  mode = INA260_set_mode_with_bit_shift_(mode, (uint16_t)(current_conversion_time), 0x0038, 3);

  CDS_CMD_ERR_CODE ret = INA260_set_parameter_(ina260_driver, INA260_kCmdIdSetConfig_, mode);
  if (ret == CDS_CMD_OK)
  {
    ina260_driver->info.averaging_mode = averaging_mode;
    ina260_driver->info.voltage_conversion_time = voltage_conversion_time;
    ina260_driver->info.current_conversion_time = current_conversion_time;
  }

  return ret;
}

CDS_CMD_ERR_CODE INA260_set_over_current_threshold(INA260_Driver* ina260_driver, float threshold_current_mA)
{
  const float kMaxOverCurrentMa = 80000.0f; //!< 過電流閾値最大電流 [mA]

  if (threshold_current_mA < 0.0f) return CDS_CMD_ILLEGAL_PARAMETER;
  if (threshold_current_mA > kMaxOverCurrentMa) return CDS_CMD_ILLEGAL_PARAMETER;

  uint16_t threshold_u16 = (uint16_t)(threshold_current_mA * INA260_kConvertOverCurrent_);

  CDS_CMD_ERR_CODE ret = INA260_set_parameter_(ina260_driver, INA260_kCmdIdSetLimitValue_, threshold_u16);

  if (ret == CDS_CMD_OK)
  {
    ina260_driver->info.oc_threshold_raw = threshold_u16;
  }

  return ret;
}

CDS_CMD_ERR_CODE INA260_enable_over_current_protection(INA260_Driver* ina260_driver)
{
  const uint16_t kEnableOverCurrentProtection = 0x8001;
  return INA260_set_parameter_(ina260_driver, INA260_kCmdIdLimitMask_, kEnableOverCurrentProtection);
}

CDS_CMD_ERR_CODE INA260_observe_current(INA260_Driver* ina260_driver)
{
  return INA260_observe_(ina260_driver, INA260_kCmdIdReadCurrent_);
}

CDS_CMD_ERR_CODE INA260_observe_voltage(INA260_Driver* ina260_driver)
{
  return INA260_observe_(ina260_driver, INA260_kCmdIdReadVoltage_);
}

CDS_CMD_ERR_CODE INA260_read_mask_register(INA260_Driver* ina260_driver)
{
  return INA260_observe_(ina260_driver, INA260_kCmdIdLimitMask_);
}

static CDS_CMD_ERR_CODE INA260_set_parameter_(INA260_Driver* ina260_driver, uint8_t cmd_id, uint16_t parameter)
{
  CDS_ERR_CODE ret;
  CDS_StreamConfig* p_stream_config;
  const uint8_t cmd_size = 3;
  uint8_t cmd[cmd_size];

  p_stream_config = &(ina260_driver->driver.super.stream_config[INA260_STREAM_TLM_CMD]);

  cmd[0] = cmd_id;
  ENDIAN_memcpy(cmd + 1, &parameter, sizeof(parameter));
  CDSSC_set_tx_frame(p_stream_config, cmd);
  CDSSC_set_tx_frame_size(p_stream_config, cmd_size);

  ret = CDS_send_general_cmd(&(ina260_driver->driver.super), INA260_STREAM_TLM_CMD);
  if (ret == CDS_ERR_CODE_OK)
  {
    return CDS_CMD_OK;
  }
  else
  {
    return CDS_CMD_DRIVER_SUPER_ERR;
  }
}

static CDS_CMD_ERR_CODE INA260_observe_(INA260_Driver* ina260_driver, uint8_t cmd_id)
{
  CDS_ERR_CODE ret;
  CDS_StreamConfig* p_stream_config;

  p_stream_config = &(ina260_driver->driver.super.stream_config[INA260_STREAM_TLM_CMD]);

  // Rx settings
  I2C_set_rx_length(&(ina260_driver->driver.i2c_config), (uint32_t)INA260_RX_FRAME_SIZE);
  CDS_clear_rx_buffer(&(ina260_driver->driver.super));

  // Send command
  INA260_tlm_id_ = cmd_id;
  CDSSC_set_tx_frame(p_stream_config, &cmd_id);
  CDSSC_set_tx_frame_size(p_stream_config, sizeof(cmd_id));
  ret = CDS_send_req_tlm_cmd(&(ina260_driver->driver.super), INA260_STREAM_TLM_CMD);
  if (ret != CDS_ERR_CODE_OK) return CDS_CMD_DRIVER_SUPER_ERR;

  // Receive data
  ret = CDS_receive(&(ina260_driver->driver.super));
  if (ret != CDS_ERR_CODE_OK)
  {
    return CDS_CMD_DRIVER_SUPER_ERR;
  }
  if (CDSSC_get_rec_status(p_stream_config)->status_code != CDS_STREAM_REC_STATUS_FIXED_FRAME)
  {
    return CDS_CMD_DRIVER_SUPER_ERR;
  }

  ret = CDS_analyze_rec_data(&(ina260_driver->driver.super), INA260_STREAM_TLM_CMD, ina260_driver);
  if (ret == CDS_ERR_CODE_OK)
  {
    return CDS_CMD_OK;
  }
  else
  {
    return CDS_CMD_DRIVER_SUPER_ERR;
  }
}

static CDS_ERR_CODE INA260_load_driver_super_init_settings_(ComponentDriverSuper* p_super)
{
  CDS_StreamConfig* p_stream_config;

  p_super->hal_handler_id = HAL_HANDLER_ID_I2C;

  p_stream_config = &(p_super->stream_config[INA260_STREAM_TLM_CMD]);

  CDSC_set_hal_rx_buffer_size(p_super, CDS_STREAM_REC_BUFFER_SIZE_SYNCHRONOUS_SMALL);

  CDSSC_enable(p_stream_config);
  CDSSC_set_rx_frame_size(p_stream_config, INA260_RX_FRAME_SIZE);
  CDSSC_set_data_analyzer(p_stream_config, INA260_analyze_rec_data_);

  return CDS_ERR_CODE_OK;
}

static CDS_ERR_CODE INA260_analyze_rec_data_(CDS_StreamConfig* p_stream_config, void* p_driver)
{
  const uint8_t* ina260_rx_data = CDSSC_get_rx_frame(p_stream_config);

  INA260_Driver* ina260_driver = (INA260_Driver*)p_driver;

  // analyze
  if (INA260_tlm_id_ == INA260_kCmdIdReadCurrent_)
  {
    ENDIAN_memcpy(&ina260_driver->info.current_raw, ina260_rx_data, sizeof(ina260_driver->info.current_raw));
    ina260_driver->info.current_mA = INA260_convert_current_mA_(ina260_driver->info.current_raw);
  }
  else if (INA260_tlm_id_ == INA260_kCmdIdReadVoltage_)
  {
    ENDIAN_memcpy(&ina260_driver->info.voltage_raw, ina260_rx_data, sizeof(ina260_driver->info.voltage_raw));
    ina260_driver->info.voltage_V = INA260_convert_voltage_V_(ina260_driver->info.voltage_raw);
  }
  else
  {
    return CDS_ERR_CODE_ERR;
  }

  return CDS_ERR_CODE_OK;
}

static float INA260_convert_current_mA_(const int16_t current_raw)
{
  return (float)(current_raw) * INA260_kConvertObservation_;
}

static float INA260_convert_voltage_V_(uint16_t voltage_raw)
{
  const float kThousand = 1000.0f;

  return (float)(voltage_raw) * INA260_kConvertObservation_ / kThousand;
}

static uint16_t INA260_set_mode_with_bit_shift_(const uint16_t mode,
                                                const uint16_t param,
                                                const uint16_t mask,
                                                const uint8_t shift_value)
{
  return mode | (mask & (param << shift_value));
}

#pragma section

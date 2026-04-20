#pragma section REPRO
/**
* @file   stim377h.c
* @brief  STIM377HのDriver
* @note   データシート: ts1673-r5-datasheet-stim377h.pdf
*/

#include "stim377h.h"
#include <src_core/library/endian.h>
#include <src_core/library/print.h>
#include <string.h>
#include <src_user/library/vector3.h>
#include <src_user/library/matrix33.h>
#include <src_user/library/crc32.h>


#define STIM377H_STREAM_TLM_CMD (0)       //!< テレコマで使うストリーム
#define STIM377H_TX_MAX_DATA_SIZE (15)    //!< TXの最大サイズ（フッターを含む）
#define STIM377H_TX_FOOTER_SIZE (1)       //!< TXのフッターサイズ
#define STIM377H_RX_HEADER_SIZE (1)       //!< RXのヘッダーサイズ
#define STIM377H_RX_FOOTER_SIZE (2)       //!< RXのフッターサイズ（CRLFあり）
#define STIM377H_RX_FOOTER_NONE_SIZE (0)  //!< RXのフッターサイズ（CRLFなし）

#define STIM377H_RX_GYRO_OUTPUT_SIZE (3)    //!< テレメのジャイロ出力バイト数 (1軸あたり)
#define STIM377H_RX_TEMPERATURE_SIZE (2)    //!< テレメの温度計出力バイト数 (1軸あたり)
#define STIM377H_RX_LATENCY_SIZE (2)        //!< テレメの遅延時間バイト数

static const float STIM377H_kMaxAngVelBias_rad_s_ = 0.3f; //!< 角速度バイアスノルム最大値 rad/s

// #define STIM377H_DEBUG_SHOW_REC_DATA (0)  //!< テレメのデバッグ表示をありにする場合は定義する

//!< ヘッダーフッター
static uint8_t STIM377H_rx_header_[STIM377H_RX_HEADER_SIZE] = { 0x90 };                  //!< RXのヘッダー。ノーマルモードのフォーマットによって可変。
static const uint8_t STIM377H_rx_footer_crlf_[STIM377H_RX_FOOTER_SIZE] = { 0x0d, 0x0a }; //!< RXのフッター。終端子がCRLFの時のみ使用。
static const uint8_t STIM377H_tx_footer_[STIM377H_TX_FOOTER_SIZE] = { 0x0d };             //!< TXのフッター。常に用いる。

//!< ノーマルモード識別子 (データシート Table 5-21)
static const uint8_t STIM377H_normal_mode_format_idx_[STIM377H_NORMAL_MODE_MAX] = {
  0x90, 0x91, 0x92, 0x93, 0x94, 0xA5, 0xA6, 0xA7,
  0x98, 0x99, 0x9A, 0x9B, 0x9C, 0xAD, 0xAE, 0xAF
};

//!< ノーマルモードRXフレームサイズ (CRLFなし)
static const int16_t STIM377H_normal_mode_rx_frame_size_none_[STIM377H_NORMAL_MODE_MAX] = {
  18, 28, 28, 38, 25, 42, 42, 59, 22, 32, 32, 42, 29, 46, 46, 63
};

//!< ノーマルモードRXフレームサイズ (CRLFあり, +2byte)
static const int16_t STIM377H_normal_mode_rx_frame_size_crlf_[STIM377H_NORMAL_MODE_MAX] = {
  20, 30, 30, 40, 27, 44, 44, 61, 24, 34, 34, 44, 31, 48, 48, 65
};

//!< CRC-32計算時にフレームの後ろに付加するダミー0x00バイト数 (データシート Table 5-22)
static const uint8_t STIM377H_normal_mode_crc_dummy_bytes_[STIM377H_NORMAL_MODE_MAX] = {
  2, 0, 0, 2, 3, 2, 2, 1, 2, 3, 2, 2, 1, 0, 0, 0
};

//!< 工学値変換スケール
//!< 角速度: 24bit 2の補数 / 2^14 [deg/s], バイトあたり {2^16, 2^8, 1} * (1/2^14)
static const float STIM377H_kScaleRaw2AngVel_[STIM377H_RX_GYRO_OUTPUT_SIZE] = { 4.0f, 0.015625f, 6.103515e-5f };
//!< 角度積分: 24bit 2の補数 / 2^21 [deg], バイトあたり {2^16, 2^8, 1} * (1/2^21)
static const float STIM377H_kScaleRaw2Ang_[STIM377H_RX_GYRO_OUTPUT_SIZE] = { 0.03125f, 1.2207031e-4f, 4.7683716e-7f };
//!< 温度: 16bit 2の補数 / 2^8 [degC], バイトあたり {2^8, 1} * (1/2^8)
static const float STIM377H_kScaleRaw2Temperature_[STIM377H_RX_TEMPERATURE_SIZE] = { 1.0f, 3.90625e-3f };

static const float STIM377H_kMaxAngVelRadSec_ = 512.0f;
static const float STIM377H_kMaxAngRad_ = 2.0f;
static const float STIM377H_kMaxTemperatureDegC_ = 128.0f;

//!< CRC-32 初期値 (データシート Section 7.5.2.3)
static const uint32_t STIM377H_kCrcInitial_ = 0xFFFFFFFF;

static const char STIM377H_normal_mode_format_char_[STIM377H_NORMAL_MODE_MAX] = {
  '0', '1', '2', '3', '4', '5', '6', '7',
  '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
};

static CDS_CMD_ERR_CODE STIM377H_send_cmd_(STIM377H_Driver* stim377h_driver, uint8_t param_size, const char* cmd_param);
static CDS_ERR_CODE STIM377H_load_driver_super_init_settings_(ComponentDriverSuper* p_super);
static CDS_ERR_CODE STIM377H_analyze_rec_data_(CDS_StreamConfig* stream_config, void* p_driver);
static CDS_CMD_ERR_CODE STIM377H_set_rec_frame_size_(STIM377H_Driver* stim377h_driver);
static int STIM377H_analyze_normal_mode_format_idx_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx);
static int STIM377H_analyze_gyro_output_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx);
static int STIM377H_analyze_gyro_status_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx);
static int STIM377H_skip_bytes_(const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx, uint8_t n_bytes);
static int STIM377H_analyze_temperature_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx);
static int STIM377H_analyze_counter_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx);
static int STIM377H_analyze_latency_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx);
static int STIM377H_analyze_crc_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx);
static int STIM377H_convert_gyro_output_(STIM377H_Driver* stim377h_driver, const uint8_t* gyro_output_bytes);
static int STIM377H_convert_temperature_(STIM377H_Driver* stim377h_driver, const uint8_t* temperature_bytes);

static void STIM377H_calc_ang_vel_calibration_(STIM377H_Info* info);

CDS_INIT_ERR_CODE STIM377H_init(STIM377H_Driver* stim377h_driver,
                               uint8_t ch,
                               uint8_t ch_gpio_trig,
                               uint8_t ch_gpio_reset,
                               CDS_StreamRecBuffer* rx_buffer)
{
  CDS_ERR_CODE ret;
  GPIO_ERR_CODE ret_gpio_trig_setting, ret_gpio_reset_setting;

  stim377h_driver->driver.uart_config.ch = ch;
  stim377h_driver->driver.uart_config.baudrate = 460800;
  stim377h_driver->driver.uart_config.parity_settings = PARITY_SETTINGS_NONE;
  stim377h_driver->driver.uart_config.data_length = UART_DATA_LENGTH_8BIT;
  stim377h_driver->driver.uart_config.stop_bit = UART_STOP_BIT_1BIT;

  ret = CDS_init(&(stim377h_driver->driver.super),
                &(stim377h_driver->driver.uart_config),
                rx_buffer,
                STIM377H_load_driver_super_init_settings_);
  if (ret != CDS_ERR_CODE_OK) return CDS_INIT_CDS_INIT_ERR;

  stim377h_driver->driver.ch_gpio_trig = ch_gpio_trig;
  stim377h_driver->driver.ch_gpio_reset = ch_gpio_reset;

  ret_gpio_trig_setting  = (GPIO_ERR_CODE)GPIO_set_direction(stim377h_driver->driver.ch_gpio_trig, GPIO_OUTPUT);
  ret_gpio_reset_setting = (GPIO_ERR_CODE)GPIO_set_direction(stim377h_driver->driver.ch_gpio_reset, GPIO_OUTPUT);

  if ((ret_gpio_trig_setting != GPIO_OK) || (ret_gpio_reset_setting != GPIO_OK)) return CDS_INIT_OTHER_ERR;

  ret_gpio_trig_setting  = (GPIO_ERR_CODE)GPIO_set_output(stim377h_driver->driver.ch_gpio_trig, GPIO_HIGH); // HIGHで初期化する
  ret_gpio_reset_setting = (GPIO_ERR_CODE)GPIO_set_output(stim377h_driver->driver.ch_gpio_reset, GPIO_LOW); // LOWで初期化する

  if ((ret_gpio_trig_setting != GPIO_OK) || (ret_gpio_reset_setting != GPIO_OK)) return CDS_INIT_OTHER_ERR;

  stim377h_driver->info.frame_transform_c2b = QUATERNION_make_unit();
  MATRIX33_make_unit(stim377h_driver->info.ang_vel_scale_factor_compo);
  for (uint8_t axis = 0; axis < PHYSICAL_CONST_THREE_DIM; axis++)
  {
    stim377h_driver->info.ang_vel_bias_compo_rad_sec[axis] = 0.0f;
  }

  STIM377H_reset_param(stim377h_driver);
  return CDS_INIT_OK;
}

int STIM377H_reset_param(STIM377H_Driver* stim377h_driver)
{
  for (uint8_t axis = 0; axis < PHYSICAL_CONST_THREE_DIM; axis++)
  {
    stim377h_driver->info.ang_vel_raw_compo_rad_sec[axis] = 0.0f;
    stim377h_driver->info.ang_compo_rad[axis] = 0.0f;
    stim377h_driver->info.temperature_compo_degC[axis] = 0.0f;
  }

  STIM377H_calc_ang_vel_calibration_(&(stim377h_driver->info));

  stim377h_driver->info.status = 1; // 0がVALID、1がINVALIDなので観測のしていない初期値は1
  stim377h_driver->info.counter = 0;
  stim377h_driver->info.latency_sec = 0;
  stim377h_driver->info.operation_mode = STIM377H_OPERATION_INIT_MODE;
  stim377h_driver->info.normal_mode_format = STIM377H_NORMAL_MODE_RATE;
  stim377h_driver->info.gyro_output_mode = STIM377H_GYRO_OUTPUT_ANGULAR_RATE;
  stim377h_driver->info.termination_mode = STIM377H_TERMINATION_OFF;
  stim377h_driver->info.low_pass_filter_frequency = STIM377H_LPF_262HZ;
  stim377h_driver->info.sample_rate = STIM377H_SAMPLE_RATE_2000HZ;
  stim377h_driver->info.crc_state = STIM377H_CRC_STATE_OK;

  return 0;
}

// ---------- UART Telemetry ----------
CDS_REC_ERR_CODE STIM377H_rec(STIM377H_Driver* stim377h_driver)
{
  CDS_ERR_CODE ret;
  CDS_StreamConfig* stream_config;

  // NORMAL Modeだけデータを受け取る
  if (stim377h_driver->info.operation_mode != STIM377H_OPERATION_NORMAL_MODE) return CDS_REC_OTHER_ERR;

  STIM377H_set_rec_frame_size_(stim377h_driver);
  ret = CDS_receive(&(stim377h_driver->driver.super));
  stream_config = &(stim377h_driver->driver.super.stream_config[STIM377H_STREAM_TLM_CMD]);

  if (ret != CDS_ERR_CODE_OK)
  {
    return CDS_REC_CDS_RECEIVE_ERR;
  }

  if (CDSSC_get_rec_status(stream_config)->status_code != CDS_STREAM_REC_STATUS_FIXED_FRAME)
  {
    return CDS_REC_OTHER_ERR;
  }

  ret = CDS_analyze_rec_data(&(stim377h_driver->driver.super), STIM377H_STREAM_TLM_CMD, stim377h_driver);

  if (ret != CDS_ERR_CODE_OK)
  {
    return CDS_REC_ANALYZE_ERR;
  }

  return CDS_REC_OK;
}

// ---------- GPIO ----------
int STIM377H_send_tlm_by_gpio(STIM377H_Driver* stim377h_driver)
{
  int ret;
  ret = GPIO_set_output(stim377h_driver->driver.ch_gpio_trig, GPIO_LOW);
  if (ret != 0) return ret;
  // GPIO LOWを250ns以上キープする
  ret = GPIO_set_output(stim377h_driver->driver.ch_gpio_trig, GPIO_HIGH);
  return ret;
}

int STIM377H_reset_by_gpio(STIM377H_Driver* stim377h_driver)
{
  int ret;
  ret = GPIO_set_output(stim377h_driver->driver.ch_gpio_reset, GPIO_HIGH);
  if (ret != 0) return ret;
  // GPIO HIGHを1us以上キープする
  ret = GPIO_set_output(stim377h_driver->driver.ch_gpio_reset, GPIO_LOW);
  if (ret != 0) return ret;
  return STIM377H_reset_param(stim377h_driver);
}

// ---------- UART Command ----------
CDS_CMD_ERR_CODE STIM377H_set_service_mode(STIM377H_Driver* stim377h_driver)
{
  CDS_CMD_ERR_CODE ret;
  char code[STIM377H_TX_MAX_DATA_SIZE];
  uint8_t len = 0;

  strcpy(code, "SERVICEMODE");
  len = strlen(code);

  if (stim377h_driver->info.operation_mode == STIM377H_OPERATION_SERVICE_MODE) return CDS_CMD_ILLEGAL_CONTEXT;

  ret = STIM377H_send_cmd_(stim377h_driver, len, code);
  if (ret != CDS_CMD_OK) return ret;

  stim377h_driver->info.operation_mode = STIM377H_OPERATION_SERVICE_MODE;

  return ret;
}

CDS_CMD_ERR_CODE STIM377H_set_normal_mode_format(STIM377H_Driver* stim377h_driver, STIM377H_NORMAL_MODE_FORMAT normal_mode_format)
{
  CDS_CMD_ERR_CODE ret;
  char code[STIM377H_TX_MAX_DATA_SIZE];
  uint8_t len = 0;

  if (stim377h_driver->info.operation_mode != STIM377H_OPERATION_SERVICE_MODE) return CDS_CMD_ILLEGAL_CONTEXT;
  if (normal_mode_format >= STIM377H_NORMAL_MODE_MAX) return CDS_CMD_ILLEGAL_PARAMETER;

  code[0] = 'd';
  code[1] = ' ';
  code[2] = STIM377H_normal_mode_format_char_[normal_mode_format];
  code[3] = ',';
  code[4] = (stim377h_driver->info.termination_mode == STIM377H_TERMINATION_CRLF) ? '1' : '0';
  code[5] = '\0';
  len = 5;

  ret = STIM377H_send_cmd_(stim377h_driver, len, code);
  if (ret != CDS_CMD_OK) return ret;

  stim377h_driver->info.normal_mode_format = normal_mode_format;

  return ret;
}

CDS_CMD_ERR_CODE STIM377H_set_sample_rate(STIM377H_Driver* stim377h_driver, STIM377H_SAMPLE_RATE sample_rate)
{
  CDS_CMD_ERR_CODE ret;
  char code[STIM377H_TX_MAX_DATA_SIZE];
  uint8_t len = 0;

  if (stim377h_driver->info.operation_mode != STIM377H_OPERATION_SERVICE_MODE) return CDS_CMD_ILLEGAL_CONTEXT;

  switch (sample_rate)
  {
  case STIM377H_SAMPLE_RATE_EXTERNAL_TRIGGER:
    strcpy(code, "m 0");
    break;
  case STIM377H_SAMPLE_RATE_125HZ:
    strcpy(code, "m 1");
    break;
  case STIM377H_SAMPLE_RATE_250HZ:
    strcpy(code, "m 2");
    break;
  case STIM377H_SAMPLE_RATE_500HZ:
    strcpy(code, "m 3");
    break;
  case STIM377H_SAMPLE_RATE_1000HZ:
    strcpy(code, "m 4");
    break;
  case STIM377H_SAMPLE_RATE_2000HZ:
    strcpy(code, "m 5");
    break;
  default:
    return CDS_CMD_ILLEGAL_PARAMETER;
  }

  len = strlen(code);
  ret = STIM377H_send_cmd_(stim377h_driver, len, code);
  if (ret != CDS_CMD_OK) return ret;

  stim377h_driver->info.sample_rate = sample_rate;

  return ret;
}

CDS_CMD_ERR_CODE STIM377H_set_gyro_output(STIM377H_Driver* stim377h_driver, STIM377H_GYRO_OUTPUT_MODE gyro_output_mode)
{
  CDS_CMD_ERR_CODE ret;
  char code[STIM377H_TX_MAX_DATA_SIZE];
  uint8_t len = 0;

  if (stim377h_driver->info.operation_mode != STIM377H_OPERATION_SERVICE_MODE) return CDS_CMD_ILLEGAL_CONTEXT;

  switch (gyro_output_mode)
  {
  case STIM377H_GYRO_OUTPUT_ANGULAR_RATE:
    strcpy(code, "u g,0");
    break;
  case STIM377H_GYRO_OUTPUT_INCREMENTAL_ANGLE:
    strcpy(code, "u g,1");
    break;
  case STIM377H_GYRO_OUTPUT_AVERAGE_ANGULAR_RATE:
    strcpy(code, "u g,2");
    break;
  case STIM377H_GYRO_OUTPUT_INTEGRATED_ANGLE:
    strcpy(code, "u g,3");
    break;
  default:
    return CDS_CMD_ILLEGAL_PARAMETER;
  }

  len = strlen(code);
  ret = STIM377H_send_cmd_(stim377h_driver, len, code);
  if (ret != CDS_CMD_OK) return ret;

  stim377h_driver->info.gyro_output_mode = gyro_output_mode;

  return ret;
}

CDS_CMD_ERR_CODE STIM377H_set_termination_mode(STIM377H_Driver* stim377h_driver, STIM377H_TERMINATION_MODE termination_mode)
{
  CDS_CMD_ERR_CODE ret;
  char code[STIM377H_TX_MAX_DATA_SIZE];
  uint8_t len = 0;

  if (stim377h_driver->info.operation_mode != STIM377H_OPERATION_SERVICE_MODE) return CDS_CMD_ILLEGAL_CONTEXT;
  if (termination_mode >= STIM377H_TERMINATION_MODE_MAX) return CDS_CMD_ILLEGAL_PARAMETER;

  code[0] = 'd';
  code[1] = ' ';
  code[2] = STIM377H_normal_mode_format_char_[stim377h_driver->info.normal_mode_format];
  code[3] = ',';
  code[4] = (termination_mode == STIM377H_TERMINATION_CRLF) ? '1' : '0';
  code[5] = '\0';
  len = 5;

  ret = STIM377H_send_cmd_(stim377h_driver, len, code);
  if (ret != CDS_CMD_OK) return ret;

  stim377h_driver->info.termination_mode = termination_mode;

  return ret;
}

CDS_CMD_ERR_CODE STIM377H_set_low_pass_filter(STIM377H_Driver* stim377h_driver, STIM377H_LPF low_pass_filter_frequency)
{
  CDS_CMD_ERR_CODE ret;
  char code[STIM377H_TX_MAX_DATA_SIZE];
  uint8_t len = 0;

  if (stim377h_driver->info.operation_mode != STIM377H_OPERATION_SERVICE_MODE) return CDS_CMD_ILLEGAL_CONTEXT;

  switch (low_pass_filter_frequency)
  {
  case STIM377H_LPF_16HZ:
    strcpy(code, "f 0");
    break;
  case STIM377H_LPF_33HZ:
    strcpy(code, "f 1");
    break;
  case STIM377H_LPF_66HZ:
    strcpy(code, "f 2");
    break;
  case STIM377H_LPF_131HZ:
    strcpy(code, "f 3");
    break;
  case STIM377H_LPF_262HZ:
    strcpy(code, "f 4");
    break;
  default:
    return CDS_CMD_ILLEGAL_PARAMETER;
  }

  len = strlen(code);
  ret = STIM377H_send_cmd_(stim377h_driver, len, code);
  if (ret != CDS_CMD_OK) return ret;

  stim377h_driver->info.low_pass_filter_frequency = low_pass_filter_frequency;

  return ret;
}

CDS_CMD_ERR_CODE STIM377H_set_normal_mode(STIM377H_Driver* stim377h_driver)
{
  CDS_CMD_ERR_CODE ret;
  char code[STIM377H_TX_MAX_DATA_SIZE];
  uint8_t len = 0;

  strcpy(code, "x N");
  len = strlen(code);

  if (stim377h_driver->info.operation_mode != STIM377H_OPERATION_SERVICE_MODE) return CDS_CMD_ILLEGAL_CONTEXT;

  ret = STIM377H_send_cmd_(stim377h_driver, len, code);
  if (ret != CDS_CMD_OK) return ret;

  stim377h_driver->info.operation_mode = STIM377H_OPERATION_NORMAL_MODE;

  return ret;
}

C2A_MATH_ERROR STIM377H_set_frame_transform_c2b(STIM377H_Driver* stim377h_driver, const Quaternion q_c2b)
{
  C2A_MATH_ERROR ret;
  ret = QUATERNION_is_normalized(q_c2b);
  if (ret != C2A_MATH_ERROR_OK) return ret;

  stim377h_driver->info.frame_transform_c2b = q_c2b;
  return ret;
}

C2A_MATH_ERROR STIM377H_set_ang_vel_bias_compo_rad_s(STIM377H_Driver* stim377h_driver, const float ang_vel_bias_compo_rad_s[PHYSICAL_CONST_THREE_DIM])
{
  float norm_rad_s = VECTOR3_norm(ang_vel_bias_compo_rad_s);
  if (norm_rad_s > STIM377H_kMaxAngVelBias_rad_s_) return C2A_MATH_ERROR_RANGE_OVER;

  VECTOR3_copy(stim377h_driver->info.ang_vel_bias_compo_rad_sec, ang_vel_bias_compo_rad_s);

  return C2A_MATH_ERROR_OK;
}

C2A_MATH_ERROR STIM377H_set_ang_vel_scale_factor_compo(STIM377H_Driver* stim377h_driver,
                                                      const float ang_vel_scale_factor_compo[PHYSICAL_CONST_THREE_DIM][PHYSICAL_CONST_THREE_DIM])
{
  MATRIX33_copy(stim377h_driver->info.ang_vel_scale_factor_compo, ang_vel_scale_factor_compo);
  return C2A_MATH_ERROR_OK;
}

// *****************************************************************************
//  内部モジュール
// *****************************************************************************


/*
 * @private
 * @brief ドライバ初期化設定
 */
static CDS_ERR_CODE STIM377H_load_driver_super_init_settings_(ComponentDriverSuper* p_super)
{
  CDS_StreamConfig* stream_config;

  p_super->hal_handler_id = HAL_HANDLER_ID_UART;

  // streamは0のみ
  stream_config = &(p_super->stream_config[STIM377H_STREAM_TLM_CMD]);

  CDSC_set_hal_rx_buffer_size(p_super, CDS_HAL_RX_BUFFER_SIZE_STIM377H);

  CDSSC_enable(stream_config);

  // 定期的な受信はするがフォーマットによって異なるので、STIM377H_set_rec_frame_size_で設定する

  CDSSC_set_rx_header(stream_config, STIM377H_rx_header_, STIM377H_RX_HEADER_SIZE);
  CDSSC_set_data_analyzer(stream_config, STIM377H_analyze_rec_data_);

  return CDS_ERR_CODE_OK;
}

/*
 * @private
 * @brief テレメトリのフレームサイズとヘッダー・フッターを指定する関数。
 */
static CDS_CMD_ERR_CODE STIM377H_set_rec_frame_size_(STIM377H_Driver* stim377h_driver)
{
  CDS_StreamConfig* stream_config;
  stream_config = &(stim377h_driver->driver.super.stream_config[STIM377H_STREAM_TLM_CMD]);

  // Headerはノーマルモードのフォーマットによって可変
  STIM377H_rx_header_[0] = STIM377H_normal_mode_format_idx_[(int8_t)stim377h_driver->info.normal_mode_format];

  if (stim377h_driver->info.termination_mode == STIM377H_TERMINATION_CRLF)
  {
    CDSSC_set_rx_footer(stream_config, STIM377H_rx_footer_crlf_, STIM377H_RX_FOOTER_SIZE);
    CDSSC_set_rx_frame_size(stream_config, STIM377H_normal_mode_rx_frame_size_crlf_[stim377h_driver->info.normal_mode_format]);
  }
  else
  {
    CDSSC_set_rx_footer(stream_config, STIM377H_rx_footer_crlf_, STIM377H_RX_FOOTER_NONE_SIZE); // CRLF OFFではフッターなし
    CDSSC_set_rx_frame_size(stream_config, STIM377H_normal_mode_rx_frame_size_none_[stim377h_driver->info.normal_mode_format]);
  }

  return CDS_CMD_OK;
}

/*
 * @private
 * @brief 汎用コマンド送信関数
 */
static CDS_CMD_ERR_CODE STIM377H_send_cmd_(STIM377H_Driver* stim377h_driver, uint8_t param_size, const char* cmd_param)
{
  CDS_StreamConfig* stream_config;
  CDS_ERR_CODE ret;
  uint8_t cmd[STIM377H_TX_MAX_DATA_SIZE];
  uint8_t i = 0;
  if (param_size + STIM377H_TX_FOOTER_SIZE > STIM377H_TX_MAX_DATA_SIZE) return CDS_CMD_ILLEGAL_LENGTH;

  for (i = 0; i < param_size; i++)
  {
    cmd[i] = cmd_param[i];
  }

  cmd[param_size] = STIM377H_tx_footer_[0]; // TXのフッターを追加

  stream_config = &(stim377h_driver->driver.super.stream_config[STIM377H_STREAM_TLM_CMD]);
  CDSSC_set_tx_frame_size(stream_config, param_size + STIM377H_TX_FOOTER_SIZE);
  CDSSC_set_tx_frame(stream_config, cmd);

  ret = CDS_send_general_cmd(&(stim377h_driver->driver.super), STIM377H_STREAM_TLM_CMD);
  if (ret != CDS_ERR_CODE_OK) return CDS_CMD_DRIVER_SUPER_ERR;

  return CDS_CMD_OK;
}

/*
 * @private
 * @brief 受け取ったデータを変数に格納していく
 */
static CDS_ERR_CODE STIM377H_analyze_rec_data_(CDS_StreamConfig* stream_config, void* p_driver)
{
  uint8_t tlm_body_idx = 0;
  STIM377H_Driver* stim377h_driver = (STIM377H_Driver*)p_driver;
  const uint8_t* stim377h_rx_data = CDSSC_get_rx_frame(stream_config);

#ifdef STIM377H_DEBUG_SHOW_REC_DATA
  Printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n",
    stim377h_rx_data[0], stim377h_rx_data[1], stim377h_rx_data[2], stim377h_rx_data[3], stim377h_rx_data[4], stim377h_rx_data[5],
    stim377h_rx_data[6], stim377h_rx_data[7], stim377h_rx_data[8], stim377h_rx_data[9], stim377h_rx_data[10], stim377h_rx_data[11],
    stim377h_rx_data[12], stim377h_rx_data[13], stim377h_rx_data[14], stim377h_rx_data[15], stim377h_rx_data[16], stim377h_rx_data[17],
    stim377h_rx_data[18], stim377h_rx_data[19], stim377h_rx_data[20], stim377h_rx_data[21], stim377h_rx_data[22]);
#endif

  if (stim377h_driver->info.operation_mode != STIM377H_OPERATION_NORMAL_MODE) return CDS_ERR_CODE_OK;

  tlm_body_idx = STIM377H_analyze_normal_mode_format_idx_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
  tlm_body_idx = STIM377H_analyze_gyro_output_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
  tlm_body_idx = STIM377H_analyze_gyro_status_(stim377h_driver, stim377h_rx_data, tlm_body_idx);

  switch (stim377h_driver->info.normal_mode_format)
  {
  case STIM377H_NORMAL_MODE_RATE:
    break;

  case STIM377H_NORMAL_MODE_RATE_ACC:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 10);
    break;

  case STIM377H_NORMAL_MODE_RATE_INCL:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 10);
    break;

  case STIM377H_NORMAL_MODE_RATE_ACC_INCL:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 20);
    break;

  case STIM377H_NORMAL_MODE_RATE_TEMPERATURE:
    tlm_body_idx = STIM377H_analyze_temperature_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 1);
    break;

  case STIM377H_NORMAL_MODE_RATE_ACC_TEMP:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 10);
    tlm_body_idx = STIM377H_analyze_temperature_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 1);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 7);
    break;

  case STIM377H_NORMAL_MODE_RATE_INCL_TEMP:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 10);
    tlm_body_idx = STIM377H_analyze_temperature_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 1);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 7);
    break;

  case STIM377H_NORMAL_MODE_RATE_ACC_INCL_TEMP:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 20);
    tlm_body_idx = STIM377H_analyze_temperature_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 1);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 14);
    break;

  case STIM377H_NORMAL_MODE_RATE_AUX:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 4);
    break;

  case STIM377H_NORMAL_MODE_RATE_ACC_AUX:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 14);
    break;

  case STIM377H_NORMAL_MODE_RATE_INCL_AUX:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 14);
    break;

  case STIM377H_NORMAL_MODE_RATE_ACC_INCL_AUX:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 24);
    break;

  case STIM377H_NORMAL_MODE_RATE_TEMP_AUX:
    tlm_body_idx = STIM377H_analyze_temperature_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 1);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 4);
    break;

  case STIM377H_NORMAL_MODE_RATE_ACC_TEMP_AUX:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 10);
    tlm_body_idx = STIM377H_analyze_temperature_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 1);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 11);
    break;

  case STIM377H_NORMAL_MODE_RATE_INCL_TEMP_AUX:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 10);
    tlm_body_idx = STIM377H_analyze_temperature_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 1);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 11);
    break;

  case STIM377H_NORMAL_MODE_RATE_ACC_INCL_TEMP_AUX:
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 20);
    tlm_body_idx = STIM377H_analyze_temperature_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 1);
    tlm_body_idx = STIM377H_skip_bytes_(stim377h_rx_data, tlm_body_idx, 18);
    break;

  default:
    break;
  }

  tlm_body_idx = STIM377H_analyze_counter_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
  tlm_body_idx = STIM377H_analyze_latency_(stim377h_driver, stim377h_rx_data, tlm_body_idx);
  tlm_body_idx = STIM377H_analyze_crc_(stim377h_driver, stim377h_rx_data, tlm_body_idx);

  return CDS_ERR_CODE_OK;
}

static int STIM377H_analyze_normal_mode_format_idx_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx)
{
  uint8_t format_idx = 0;
  size_t size = sizeof(format_idx);
  ENDIAN_memcpy(&(format_idx), &(stim377h_rx_data[tlm_body_idx]), size);
  tlm_body_idx += size;

  // ヘッダーとしてノーマルモードフォーマットとの整合性を確認されているのでこの値はinfoに格納しない
  (void)stim377h_driver;

  return tlm_body_idx;
}

static int STIM377H_analyze_gyro_output_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx)
{
  size_t size = 0;
  uint8_t idx = 0;
  uint8_t gyro_output[STIM377H_RX_GYRO_OUTPUT_SIZE * PHYSICAL_CONST_THREE_DIM];

  // endian_memcpyすると反転するので1byteずつ行っている
  for (idx = 0; idx < STIM377H_RX_GYRO_OUTPUT_SIZE * PHYSICAL_CONST_THREE_DIM; idx++)
  {
    size = sizeof(gyro_output[idx]);
    ENDIAN_memcpy(&(gyro_output[idx]), &(stim377h_rx_data[tlm_body_idx]), size);
    tlm_body_idx += size;
  }

  STIM377H_convert_gyro_output_(stim377h_driver, gyro_output);

  return tlm_body_idx;
}

static int STIM377H_analyze_gyro_status_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx)
{
  size_t size = sizeof(stim377h_driver->info.status);
  ENDIAN_memcpy(&(stim377h_driver->info.status), &(stim377h_rx_data[tlm_body_idx]), size);
  tlm_body_idx += size;

  return tlm_body_idx;
}

/*
 * @private
 * @brief 指定バイト数を読み飛ばす (Acc/Incl/AUX など現状は格納先のないデータに使用)
 */
static int STIM377H_skip_bytes_(const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx, uint8_t n_bytes)
{
  (void)stim377h_rx_data;
  return tlm_body_idx + n_bytes;
}

static int STIM377H_analyze_temperature_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx)
{
  size_t size = 0;
  uint8_t idx = 0;
  uint8_t temperature_bytes[STIM377H_RX_TEMPERATURE_SIZE * PHYSICAL_CONST_THREE_DIM];

  for (idx = 0; idx < STIM377H_RX_TEMPERATURE_SIZE * PHYSICAL_CONST_THREE_DIM; idx++)
  {
    size = sizeof(temperature_bytes[idx]);
    ENDIAN_memcpy(&(temperature_bytes[idx]), &(stim377h_rx_data[tlm_body_idx]), size);
    tlm_body_idx += size;
  }

  STIM377H_convert_temperature_(stim377h_driver, temperature_bytes);

  return tlm_body_idx;
}

static int STIM377H_analyze_counter_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx)
{
  size_t size = sizeof(stim377h_driver->info.counter);
  ENDIAN_memcpy(&(stim377h_driver->info.counter), &(stim377h_rx_data[tlm_body_idx]), size);
  tlm_body_idx += size;

  return tlm_body_idx;
}

static int STIM377H_analyze_latency_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx)
{
  uint16_t latency_us = 0;
  size_t size = sizeof(latency_us);
  ENDIAN_memcpy(&latency_us, &(stim377h_rx_data[tlm_body_idx]), size);
  tlm_body_idx += size;

  stim377h_driver->info.latency_sec = latency_us;

  return tlm_body_idx;
}

static int STIM377H_analyze_crc_(STIM377H_Driver* stim377h_driver, const uint8_t* stim377h_rx_data, uint8_t tlm_body_idx)
{
  uint8_t i;
  uint8_t dummy = 0x00;
  uint8_t n_dummy;
  uint32_t crc_calc;

  size_t crc_size = sizeof(stim377h_driver->info.crc);
  ENDIAN_memcpy(&(stim377h_driver->info.crc), &(stim377h_rx_data[tlm_body_idx]), crc_size);
  tlm_body_idx += crc_size;

  crc_calc = crc_32_stim377h(STIM377H_kCrcInitial_, stim377h_rx_data, tlm_body_idx - crc_size);

  n_dummy = STIM377H_normal_mode_crc_dummy_bytes_[stim377h_driver->info.normal_mode_format];
  for (i = 0; i < n_dummy; i++)
  {
    crc_calc = crc_32_stim377h(crc_calc, &dummy, 1);
  }

  stim377h_driver->info.crc_state = (crc_calc == stim377h_driver->info.crc)
    ? STIM377H_CRC_STATE_OK : STIM377H_CRC_STATE_NG;

  return tlm_body_idx;
}

static int STIM377H_convert_gyro_output_(STIM377H_Driver* stim377h_driver, const uint8_t* gyro_output_bytes)
{
  uint8_t axis = 0;
  uint8_t idx = 0;
  float ang_vel_compo_deg_sec[PHYSICAL_CONST_THREE_DIM] = { 0.0f, 0.0f, 0.0f };
  float ang_compo_deg[PHYSICAL_CONST_THREE_DIM] = { 0.0f, 0.0f, 0.0f };

  if ((stim377h_driver->info.gyro_output_mode == STIM377H_GYRO_OUTPUT_ANGULAR_RATE) ||
      (stim377h_driver->info.gyro_output_mode == STIM377H_GYRO_OUTPUT_AVERAGE_ANGULAR_RATE))
  {
    for (axis = 0; axis < PHYSICAL_CONST_THREE_DIM; axis++)
    {
      for (idx = 0; idx < STIM377H_RX_GYRO_OUTPUT_SIZE; idx++)
      {
        ang_vel_compo_deg_sec[axis] += gyro_output_bytes[axis * STIM377H_RX_GYRO_OUTPUT_SIZE + idx] * STIM377H_kScaleRaw2AngVel_[idx];
      }
      if (ang_vel_compo_deg_sec[axis] > STIM377H_kMaxAngVelRadSec_)
      {
        ang_vel_compo_deg_sec[axis] -= STIM377H_kMaxAngVelRadSec_ * 2.0f;
      }
      stim377h_driver->info.ang_vel_raw_compo_rad_sec[axis] = PHYSICAL_CONST_degree_to_radian(ang_vel_compo_deg_sec[axis]);
    }
    STIM377H_calc_ang_vel_calibration_(&(stim377h_driver->info));
  }
  else if ((stim377h_driver->info.gyro_output_mode == STIM377H_GYRO_OUTPUT_INCREMENTAL_ANGLE) ||
           (stim377h_driver->info.gyro_output_mode == STIM377H_GYRO_OUTPUT_INTEGRATED_ANGLE))
  {
    for (axis = 0; axis < PHYSICAL_CONST_THREE_DIM; axis++)
    {
      for (idx = 0; idx < STIM377H_RX_GYRO_OUTPUT_SIZE; idx++)
      {
        ang_compo_deg[axis] += gyro_output_bytes[axis * STIM377H_RX_GYRO_OUTPUT_SIZE + idx] * STIM377H_kScaleRaw2Ang_[idx];
      }
      if (ang_compo_deg[axis] > STIM377H_kMaxAngRad_)
      {
        ang_compo_deg[axis] -= STIM377H_kMaxAngRad_ * 2.0f;
      }
      stim377h_driver->info.ang_compo_rad[axis] = PHYSICAL_CONST_degree_to_radian(ang_compo_deg[axis]);
    }
  }

  return 0;
}

static int STIM377H_convert_temperature_(STIM377H_Driver* stim377h_driver, const uint8_t* temperature_bytes)
{
  uint8_t axis = 0;
  uint8_t idx = 0;
  float temperature_degC[PHYSICAL_CONST_THREE_DIM] = { 0.0f, 0.0f, 0.0f };

  for (axis = 0; axis < PHYSICAL_CONST_THREE_DIM; axis++)
  {
    for (idx = 0; idx < STIM377H_RX_TEMPERATURE_SIZE; idx++)
    {
      temperature_degC[axis] += temperature_bytes[axis * STIM377H_RX_TEMPERATURE_SIZE + idx] * STIM377H_kScaleRaw2Temperature_[idx];
    }
    if (temperature_degC[axis] > STIM377H_kMaxTemperatureDegC_)
    {
      temperature_degC[axis] -= STIM377H_kMaxTemperatureDegC_ * 2.0f;
    }
    stim377h_driver->info.temperature_compo_degC[axis] = temperature_degC[axis];
  }

  return 0;
}

static void STIM377H_calc_ang_vel_calibration_(STIM377H_Info* info)
{
  // Scale Factor and Bias calibration: y = SF*x - BIAS
  MATRIX33_multiply_matrix_vector(info->ang_vel_compo_rad_sec,
                                  info->ang_vel_scale_factor_compo,
                                  info->ang_vel_raw_compo_rad_sec);
  VECTOR3_subtract(info->ang_vel_compo_rad_sec,
                  info->ang_vel_compo_rad_sec,
                  info->ang_vel_bias_compo_rad_sec);

  QUATERNION_trans_coordinate(info->ang_vel_body_rad_sec,
                              info->frame_transform_c2b,
                              info->ang_vel_compo_rad_sec);

  return;
}

#pragma section

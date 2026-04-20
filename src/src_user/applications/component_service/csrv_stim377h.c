#pragma section REPRO
/**
* @file   csrv_stim377h.c
* @brief  STIM377HのComponent Service
*/

#include "csrv_stim377h.h"

#include <src_core/library/print.h>
#include <src_core/system/event_manager/event_logger.h>
#include <src_core/tlm_cmd/common_packet/common_cmd_packet_util.h>
#include "../../settings/port_config.h"
#include "../../settings/component_driver/driver_buffer_define.h"
#include "../user_defined/Power/power_switch_control.h"
#include "../../library/matrix33.h"

// Satellite Parameters
#include "../../settings/SatelliteParameters/stim377h_parameters.h"

#define CDS_STREAM_REC_BUFFER_SIZE_STIM377H (CDS_HAL_RX_BUFFER_SIZE_STIM377H * 2)  //!< CDS_StreamRecBuffer のバッファサイズ（非同期通信なので2倍している）

static void CSRV_STIM377H_init_(void);
static void CSRV_STIM377H_update_(void);
static void CSRV_STIM377H_temperature_calibration_(void);

static STIM377H_Driver stim377h_driver_[STIM377H_IDX_MAX];
const  STIM377H_Driver* const stim377h_driver[STIM377H_IDX_MAX] = {&stim377h_driver_[STIM377H_IDX_IN_UNIT]};

static CsrvStim377H        csrv_stim377h_[STIM377H_IDX_MAX];
const  CsrvStim377H* const csrv_stim377h [STIM377H_IDX_MAX] = {&csrv_stim377h_[STIM377H_IDX_IN_UNIT]};

// バッファ
// 面倒くさいので要素数一つと仮定してバッファを確保する
static CDS_StreamRecBuffer CSRV_STIM377H_rx_buffer_;
static uint8_t CSRV_STIM377H_rx_buffer_allocation_[CDS_STREAM_REC_BUFFER_SIZE_STIM377H];

AppInfo CSRV_STIM377H_update(void)
{
  return AI_create_app_info("update_CSRV_STIM377H", CSRV_STIM377H_init_, CSRV_STIM377H_update_);
}

static void CSRV_STIM377H_init_(void)
{
  CDS_ERR_CODE ret1;
  CDS_INIT_ERR_CODE ret2;
  int ret;

  ret1 = CDS_init_stream_rec_buffer(&CSRV_STIM377H_rx_buffer_,
                                   CSRV_STIM377H_rx_buffer_allocation_,
                                   sizeof(CSRV_STIM377H_rx_buffer_allocation_));
  if (ret1 != CDS_ERR_CODE_OK)
  {
    Printf("STIM377H buffer init Failed ! %d \n", ret1);
  }

  // 面倒くさいので要素数一つと仮定して初期化する
  ret2 = STIM377H_init(&stim377h_driver_[STIM377H_IDX_IN_UNIT],
                       PORT_CH_UART_STIM,
                       PORT_CH_GPIO_OUT_STIM_TRIG,
                       PORT_CH_GPIO_OUT_STIM_RST,
                       &CSRV_STIM377H_rx_buffer_);
  if (ret2 != CDS_INIT_OK)
  {
    Printf("STIM377H init Failed ! %d \n", ret2);
  }

  C2A_MATH_ERROR ret_math;
  Quaternion q_c2b;
  QUATERNION_make_from_euler_angles(&q_c2b,
                                    PHYSICAL_CONST_degree_to_radian(90.0f),
                                    PHYSICAL_CONST_degree_to_radian(-90.0f),
                                    PHYSICAL_CONST_degree_to_radian(0.0f),
                                    EULER_ANGLE_ROTATION_ORDER_321);
  ret_math = STIM377H_set_frame_transform_c2b(&stim377h_driver_[STIM377H_IDX_IN_UNIT], q_c2b);
  if (ret_math != C2A_MATH_ERROR_OK)
  {
    Printf("STIM377H: q_c2b set error.\n");  // 初期化時のエラーはデバッグ表示して知らせるだけ
  }

  // 温度補正
  const float kRangeLow  = STIM377H_PARAMETERS_temperature_range_low_degC;
  const float kRangeHigh = STIM377H_PARAMETERS_temperature_range_high_degC;
  // 計測値から設定するが温度依存性はかなり小さい
  // 特にSFは取付誤差と見分けづらいのでなしとする
  // SF,バイアスは y = SF*x - BIASという式を想定
  // X軸
  ret = POLYNOMIAL_APPROX_initialize(&(csrv_stim377h_[STIM377H_IDX_IN_UNIT].bias_compo_rad_s[0]),
                                     STIM377H_PARAMETERS_kNumCoeffTempCalib, STIM377H_PARAMETERS_bias_coeff_compo_x, kRangeLow, kRangeHigh);
  if (ret < 0) Printf("STIM377H Gyro-X Bias Temperature Calibration init Failed ! \n");
  ret = POLYNOMIAL_APPROX_initialize(&(csrv_stim377h_[STIM377H_IDX_IN_UNIT].scale_factor_compo[0]),
                                     STIM377H_PARAMETERS_kNumCoeffTempCalib, STIM377H_PARAMETERS_scale_factor_coeff_compo_x, kRangeLow, kRangeHigh);
  if (ret < 0) Printf("STIM377H Gyro-X SF Temperature Calibration init Failed ! \n");

  // Y軸
  ret = POLYNOMIAL_APPROX_initialize(&(csrv_stim377h_[STIM377H_IDX_IN_UNIT].bias_compo_rad_s[1]),
                                     STIM377H_PARAMETERS_kNumCoeffTempCalib, STIM377H_PARAMETERS_bias_coeff_compo_y, kRangeLow, kRangeHigh);
  if (ret < 0) Printf("STIM377H Gyro-Y Bias Temperature Calibration init Failed ! \n");
  ret = POLYNOMIAL_APPROX_initialize(&(csrv_stim377h_[STIM377H_IDX_IN_UNIT].scale_factor_compo[1]),
                                     STIM377H_PARAMETERS_kNumCoeffTempCalib, STIM377H_PARAMETERS_scale_factor_coeff_compo_y, kRangeLow, kRangeHigh);
  if (ret < 0) Printf("STIM377H Gyro-Y SF Temperature Calibration init Failed ! \n");

  // Z軸
  ret = POLYNOMIAL_APPROX_initialize(&(csrv_stim377h_[STIM377H_IDX_IN_UNIT].bias_compo_rad_s[2]),
                                     STIM377H_PARAMETERS_kNumCoeffTempCalib, STIM377H_PARAMETERS_bias_coeff_compo_z, kRangeLow, kRangeHigh);
  if (ret < 0) Printf("STIM377H Gyro-Z Bias Temperature Calibration init Failed ! \n");
  ret = POLYNOMIAL_APPROX_initialize(&(csrv_stim377h_[STIM377H_IDX_IN_UNIT].scale_factor_compo[2]),
                                     STIM377H_PARAMETERS_kNumCoeffTempCalib, STIM377H_PARAMETERS_scale_factor_coeff_compo_z, kRangeLow, kRangeHigh);
  if (ret < 0) Printf("STIM377H Gyro-Z SF Temperature Calibration init Failed ! \n");

  return;
}


static void CSRV_STIM377H_update_(void)
{
  if ((power_switch_control->switch_state_unreg[APP_PSC_UNREG_IDX_STIM377H] == APP_PSC_STATE_ON) &&
      (stim377h_driver[STIM377H_IDX_IN_UNIT])->info.operation_mode == STIM377H_OPERATION_NORMAL_MODE)
  {
    // TODO_L: サービスモード時のアノマリ処理追加
    int ret_gpio = STIM377H_send_tlm_by_gpio(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]));
    if (ret_gpio != 0)
    {
      // Printf("STIM377H gpio failed ! %d \n", ret_gpio);
    }

    // テレメ送信は86us後に始まる
    CDS_REC_ERR_CODE ret_rec = STIM377H_rec(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]));

    if (stim377h_driver_->driver.super.config.info.rec_status_.ret_from_hal_rx == 0) return;

    if (ret_rec != CDS_REC_OK)
    {
      EL_record_event(EL_GROUP_TLM_ERROR_STIM377H, (uint32_t)STIM377H_IDX_IN_UNIT, EL_ERROR_LEVEL_HIGH, (uint32_t)ret_rec);
    }

    STIM377H_CRC_STATE state = stim377h_driver_->info.crc_state;
    uint8_t status = stim377h_driver_->info.status;

    if (state != STIM377H_CRC_STATE_OK)
    {
      EL_record_event(EL_GROUP_CRC_ERROR_STIM377H, (uint32_t)STIM377H_IDX_IN_UNIT, EL_ERROR_LEVEL_HIGH, (uint32_t)state);
    }
    else if (status != 0)
    {
      // EL_record_event(EL_GROUP_ERROR_STIM377H, (uint32_t)STIM377H_IDX_IN_UNIT, EL_ERROR_LEVEL_HIGH, (uint32_t)STIM377H_EL_NOTE_STATUS_ERROR);
    }
    else
    {
      // NOT REACHED
    }

    CSRV_STIM377H_temperature_calibration_();
  }
  else if (power_switch_control->switch_state_unreg[APP_PSC_UNREG_IDX_STIM377H] == APP_PSC_STATE_OFF)
  {
    // 電源リセット後はinitモードから始まるようにする
    STIM377H_reset_param(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]));
  }
}

static void CSRV_STIM377H_temperature_calibration_(void)
{
  for (int stim_idx = 0; stim_idx < STIM377H_IDX_MAX; stim_idx++)
  {
    float gyro_bias_compo_rad_s[PHYSICAL_CONST_THREE_DIM];
    float gyro_scale_factor_compo[PHYSICAL_CONST_THREE_DIM][PHYSICAL_CONST_THREE_DIM];
    MATRIX33_make_unit(gyro_scale_factor_compo);

    for (int axis_id = 0; axis_id < PHYSICAL_CONST_THREE_DIM; axis_id++)
    {
      float temperature_degC = stim377h_driver_[stim_idx].info.temperature_compo_degC[axis_id];
      CsrvStim377H temp_cal = csrv_stim377h_[stim_idx];
      int ret;
      ret = POLYNOMIAL_APPROX_calc_output(&gyro_bias_compo_rad_s[axis_id],
                                          temp_cal.bias_compo_rad_s[axis_id],
                                          temperature_degC);
      if (ret < 0) gyro_bias_compo_rad_s[axis_id] = 0.0f; // 異常時はバイアス補正はしない
      ret = POLYNOMIAL_APPROX_calc_output(&gyro_scale_factor_compo[axis_id][axis_id],
                                          temp_cal.scale_factor_compo[axis_id],
                                          temperature_degC);
      if (ret < 0) gyro_scale_factor_compo[axis_id][axis_id] = 1.0f; // 異常時はSF補正はしない
    }
    STIM377H_set_ang_vel_bias_compo_rad_s(&(stim377h_driver_[stim_idx]), gyro_bias_compo_rad_s);
    STIM377H_set_ang_vel_scale_factor_compo(&(stim377h_driver_[stim_idx]), gyro_scale_factor_compo);
  }
}

CCP_CmdRet Cmd_CSRV_STIM377H_INIT(const CommonCmdPacket* packet)
{
  CDS_CMD_ERR_CODE ret;

  ret = STIM377H_set_service_mode(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]));
  ret = STIM377H_set_normal_mode(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]));

  return CDS_conv_cmd_err_to_ccp_cmd_ret(ret);
}

CCP_CmdRet Cmd_CSRV_STIM377H_SET_MODE(const CommonCmdPacket* packet)
{
  CDS_CMD_ERR_CODE ret;
  const uint8_t* param = CCP_get_param_head(packet);

  STIM377H_OPERATION_MODE mode = (STIM377H_OPERATION_MODE)param[0];
  if (mode >= STIM377H_OPERATION_MODE_MAX)  return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  if (mode == STIM377H_OPERATION_NORMAL_MODE)
  {
    ret = STIM377H_set_normal_mode(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]));
  }
  else if (mode == STIM377H_OPERATION_SERVICE_MODE)
  {
    ret = STIM377H_set_service_mode(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]));
  }
  else
  {
    return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);
  }

  return CDS_conv_cmd_err_to_ccp_cmd_ret(ret);
}

CCP_CmdRet Cmd_CSRV_STIM377H_SET_NORMAL_MODE_FORMAT(const CommonCmdPacket* packet)
{
  CDS_CMD_ERR_CODE ret;
  const uint8_t* param = CCP_get_param_head(packet);

  STIM377H_NORMAL_MODE_FORMAT format = (STIM377H_NORMAL_MODE_FORMAT)param[0];
  if (format >= STIM377H_NORMAL_MODE_MAX) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  ret = STIM377H_set_normal_mode_format(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]), format);

  return CDS_conv_cmd_err_to_ccp_cmd_ret(ret);
}

CCP_CmdRet Cmd_CSRV_STIM377H_SET_SAMPLE_RATE(const CommonCmdPacket* packet)
{
  CDS_CMD_ERR_CODE ret;
  const uint8_t* param = CCP_get_param_head(packet);

  STIM377H_SAMPLE_RATE sample_rate = (STIM377H_SAMPLE_RATE)param[0];
  if (sample_rate >= STIM377H_SAMPLE_RATE_MAX) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  ret = STIM377H_set_sample_rate(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]), sample_rate);

  return CDS_conv_cmd_err_to_ccp_cmd_ret(ret);
}

CCP_CmdRet Cmd_CSRV_STIM377H_SET_GYRO_OUTPUT(const CommonCmdPacket* packet)
{
  CDS_CMD_ERR_CODE ret;
  const uint8_t* param = CCP_get_param_head(packet);

  STIM377H_GYRO_OUTPUT_MODE gyro_output_mode = (STIM377H_GYRO_OUTPUT_MODE)param[0];
  if (gyro_output_mode >= STIM377H_GYRO_OUTPUT_MODE_MAX) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  ret = STIM377H_set_gyro_output(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]), gyro_output_mode);

  return CDS_conv_cmd_err_to_ccp_cmd_ret(ret);
}

CCP_CmdRet Cmd_CSRV_STIM377H_SET_TERMINATION_MODE(const CommonCmdPacket* packet)
{
  CDS_CMD_ERR_CODE ret;
  const uint8_t* param = CCP_get_param_head(packet);

  STIM377H_TERMINATION_MODE termination_mode = (STIM377H_TERMINATION_MODE)param[0];
  if (termination_mode >= STIM377H_TERMINATION_MODE_MAX) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  ret = STIM377H_set_termination_mode(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]), termination_mode);

  return CDS_conv_cmd_err_to_ccp_cmd_ret(ret);
}

CCP_CmdRet Cmd_CSRV_STIM377H_SET_LOW_PASS_FILTER(const CommonCmdPacket* packet)
{
  CDS_CMD_ERR_CODE ret;
  const uint8_t* param = CCP_get_param_head(packet);

  STIM377H_LPF low_pass_filter_frequency = (STIM377H_LPF)param[0];
  if (low_pass_filter_frequency >= STIM377H_LPF_MAX) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  ret = STIM377H_set_low_pass_filter(&(stim377h_driver_[STIM377H_IDX_IN_UNIT]), low_pass_filter_frequency);

  return CDS_conv_cmd_err_to_ccp_cmd_ret(ret);
}

CCP_CmdRet Cmd_CSRV_STIM377H_SET_FRAME_TRANSFORMATION_QUATERNION_C2B(const CommonCmdPacket* packet)
{
  const uint8_t* param = CCP_get_param_head(packet);

  STIM377H_IDX idx;
  idx = (STIM377H_IDX)param[0];
  if (idx >= STIM377H_IDX_MAX) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  float q_array_c2b[PHYSICAL_CONST_QUATERNION_DIM];
  for (int axis = 0; axis < PHYSICAL_CONST_QUATERNION_DIM; axis++)
  {
    ENDIAN_memcpy(&q_array_c2b[axis], param + 1 + axis * sizeof(float), sizeof(float));
  }

  Quaternion quaternion_c2b;
  C2A_MATH_ERROR ret;
  ret = QUATERNION_make_from_array(&quaternion_c2b, q_array_c2b, QUATERNION_SCALAR_POSITION_LAST);
  if (ret != C2A_MATH_ERROR_OK) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  STIM377H_set_frame_transform_c2b(&stim377h_driver_[idx], quaternion_c2b);

  return CCP_make_cmd_ret_without_err_code(CCP_EXEC_SUCCESS);
}

CCP_CmdRet Cmd_CSRV_STIM377H_SET_ANG_VEL_BIAS_COMPO_RAD_S(const CommonCmdPacket* packet)
{
  const uint8_t* param = CCP_get_param_head(packet);

  STIM377H_IDX idx;
  idx = (STIM377H_IDX)param[0];

  if (idx >= STIM377H_IDX_MAX) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  float ang_vel_bias_compo_rad_s[PHYSICAL_CONST_THREE_DIM];
  for (int axis = 0; axis < PHYSICAL_CONST_THREE_DIM; axis++)
  {
    ENDIAN_memcpy(&ang_vel_bias_compo_rad_s[axis], param + 1 + axis * sizeof(float), sizeof(float));
  }

  C2A_MATH_ERROR ret;
  ret = STIM377H_set_ang_vel_bias_compo_rad_s(&stim377h_driver_[idx], ang_vel_bias_compo_rad_s);

  if (ret != C2A_MATH_ERROR_OK) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  return CCP_make_cmd_ret_without_err_code(CCP_EXEC_SUCCESS);
}

CCP_CmdRet Cmd_CSRV_STIM377H_SET_ANG_VEL_BIAS_TEMP_CALIB(const CommonCmdPacket* packet)
{
  const uint8_t* param = CCP_get_param_head(packet);
  uint8_t offset = 0;

  // TODO_L: コマンド引数サイズ制限的にSTIM377H_IDXは入れ込めない。必要になったら対応する
  uint8_t axis;
  axis = param[0];
  offset += 1;
  if (axis >= PHYSICAL_CONST_THREE_DIM) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  float range_low_degC, range_high_degC;
  ENDIAN_memcpy(&range_low_degC, param + offset, sizeof(float));
  offset += sizeof(float);
  ENDIAN_memcpy(&range_high_degC, param + offset, sizeof(float));
  offset += sizeof(float);

  float coeff[STIM377H_PARAMETERS_kNumCoeffTempCalib];
  for (uint8_t coeff_idx = 0; coeff_idx < STIM377H_PARAMETERS_kNumCoeffTempCalib; coeff_idx++)
  {
    ENDIAN_memcpy(&coeff[coeff_idx], param + offset, sizeof(float));
    offset += sizeof(float);
  }

  int ret = POLYNOMIAL_APPROX_initialize(&(csrv_stim377h_[STIM377H_IDX_IN_UNIT].bias_compo_rad_s[axis]),
                                         STIM377H_PARAMETERS_kNumCoeffTempCalib, coeff, range_low_degC, range_high_degC);
  if (ret < 0)  return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_CONTEXT);

  return CCP_make_cmd_ret_without_err_code(CCP_EXEC_SUCCESS);
}

CCP_CmdRet Cmd_CSRV_STIM377H_SET_ANG_VEL_SF_TEMP_CALIB(const CommonCmdPacket* packet)
{
  const uint8_t* param = CCP_get_param_head(packet);
  uint8_t offset = 0;

  // TODO_L: コマンド引数サイズ制限的にSTIM377H_IDXは入れ込めない。必要になったら対応する
  uint8_t axis;
  axis = param[0];
  offset += 1;
  if (axis >= PHYSICAL_CONST_THREE_DIM) return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_PARAMETER);

  float range_low_degC, range_high_degC;
  ENDIAN_memcpy(&range_low_degC, param + offset, sizeof(float));
  offset += sizeof(float);
  ENDIAN_memcpy(&range_high_degC, param + offset, sizeof(float));
  offset += sizeof(float);

  float coeff[STIM377H_PARAMETERS_kNumCoeffTempCalib];
  for (uint8_t coeff_idx = 0; coeff_idx < STIM377H_PARAMETERS_kNumCoeffTempCalib; coeff_idx++)
  {
    ENDIAN_memcpy(&coeff[coeff_idx], param + offset, sizeof(float));
    offset += sizeof(float);
  }

  int ret = POLYNOMIAL_APPROX_initialize(&(csrv_stim377h_[STIM377H_IDX_IN_UNIT].scale_factor_compo[axis]),
                                         STIM377H_PARAMETERS_kNumCoeffTempCalib, coeff, range_low_degC, range_high_degC);
  if (ret < 0)  return CCP_make_cmd_ret_without_err_code(CCP_EXEC_ILLEGAL_CONTEXT);

  return CCP_make_cmd_ret_without_err_code(CCP_EXEC_SUCCESS);
}

#pragma section

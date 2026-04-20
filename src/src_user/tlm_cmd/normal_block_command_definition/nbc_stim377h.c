#pragma section REPRO
/**
 * @file
 * @brief  ブロックコマンド定義
 * @note   このコードは自動生成されています！
 */
#include <src_user/tlm_cmd/normal_block_command_definition/nbc_header.h>
#include <src_user/tlm_cmd/telemetry_definitions.h>
#include <src_user/applications/component_service/csrv_stim377h.h>


void BCL_load_power_on_stim377h(void)
{
  // Initialize
  BCL_tool_register_cmd(1, Cmd_CODE_CSRV_STIM377H_INIT);
  // Set service mode
  BCL_tool_prepare_param_uint8(STIM377H_OPERATION_SERVICE_MODE);
  BCL_tool_register_cmd(11, Cmd_CODE_CSRV_STIM377H_SET_MODE);
  // Set normal mode format
  BCL_tool_prepare_param_uint8(STIM377H_NORMAL_MODE_RATE_TEMPERATURE);
  BCL_tool_register_cmd(21, Cmd_CODE_CSRV_STIM377H_SET_NORMAL_MODE_FORMAT);
  // Set gyro output
  BCL_tool_prepare_param_uint8(STIM377H_GYRO_OUTPUT_AVERAGE_ANGULAR_RATE);
  BCL_tool_register_cmd(31, Cmd_CODE_CSRV_STIM377H_SET_GYRO_OUTPUT);
  // Set sample rate
  BCL_tool_prepare_param_uint8(STIM377H_SAMPLE_RATE_EXTERNAL_TRIGGER);
  BCL_tool_register_cmd(41, Cmd_CODE_CSRV_STIM377H_SET_SAMPLE_RATE);
  // Set low pass filter
  BCL_tool_prepare_param_uint8(STIM377H_LPF_16HZ);
  BCL_tool_register_cmd(51, Cmd_CODE_CSRV_STIM377H_SET_LOW_PASS_FILTER);
  // Go to normal mode
  BCL_tool_prepare_param_uint8(STIM377H_OPERATION_NORMAL_MODE);
  BCL_tool_register_cmd(81, Cmd_CODE_CSRV_STIM377H_SET_MODE);
}

#pragma section

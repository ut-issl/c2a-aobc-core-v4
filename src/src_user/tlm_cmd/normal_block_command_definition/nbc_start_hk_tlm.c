#pragma section REPRO
/**
 * @file
 * @brief  ブロックコマンド定義
 * @note   このコードは自動生成されています！
 */
#include <src_user/tlm_cmd/normal_block_command_definition/nbc_header.h>
#include <src_user/tlm_cmd/telemetry_definitions.h>


void BCL_load_hk_cyclic_tlm(void)
{
  // HK General
  BCL_tool_prepare_param_uint8(Tlm_CODE_AOBC_HK_GEN);
  BCL_tool_register_cmd(1, Cmd_CODE_TG_GENERATE_RT_TLM);
  // HK Components
  BCL_tool_prepare_param_uint8(Tlm_CODE_AOBC_HK_COMPO);
  BCL_tool_register_cmd(2, Cmd_CODE_TG_GENERATE_RT_TLM);
  // HK Algorithm
  BCL_tool_prepare_param_uint8(Tlm_CODE_AOBC_HK_ALGO);
  BCL_tool_register_cmd(4, Cmd_CODE_TG_GENERATE_RT_TLM);
  BCL_tool_register_deploy(10, BC_HK_CYCLIC_TLM, TLCD_ID_DEPLOY_TLM);
}

#pragma section

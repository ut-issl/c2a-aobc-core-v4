#pragma section REPRO
/**
 * @file
 * @brief  ブロックコマンド定義
 * @note   このコードは自動生成されています！
 */
#include "tl_elem_tlm_cmd_hirate.h"

#include <src_user/applications/app_registry.h>
#include <src_user/tlm_cmd/block_command_definitions.h>

#include <src_core/tlm_cmd/block_command_loader.h>


void BCL_load_ac_tlm_cmd_hirate(void)
{
  BCL_tool_register_app(0, AR_RTC_DISPATCHER);
  BCL_tool_register_app(1, AR_TLC_DISPATCHER_BC);
  BCL_tool_register_app(2, AR_TLC_DISPATCHER_TLM);
  BCL_tool_register_app(3, AR_CSRV_MOBC_RT_TLM_PH);
}

#pragma section

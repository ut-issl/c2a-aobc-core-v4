#pragma section REPRO
/**
 * @file
 * @brief  ブロックコマンド定義
 * @note   このコードは自動生成されています！
 */
#include "tl_elem_cdh_update.h"

#include <src_user/applications/app_registry.h>
#include <src_user/tlm_cmd/block_command_definitions.h>

#include <src_core/tlm_cmd/block_command_loader.h>


void BCL_load_ac_cdh_update(void)
{
  BCL_tool_register_app(0, AR_CSRV_MOBC_CMD_PH);
  BCL_tool_register_app(1, AR_GSC_DISPATCHER);
  BCL_tool_register_app(2, AR_TLC_DISPATCHER_GS);
  BCL_tool_register_app(3, AR_RTC_DISPATCHER);
  BCL_tool_register_app(4, AR_TLC_DISPATCHER_BC);
  BCL_tool_register_app(5, AR_TLC_DISPATCHER_TLM);
  BCL_tool_register_app(6, AR_CSRV_MOBC_RT_TLM_PH);
  BCL_tool_register_app(7, AR_EVENT_UTILITY);
  BCL_tool_register_app(8, AR_APP_AOCS_DATA_RECORDER);
  BCL_tool_register_app(9, AR_APP_NVM_BC);
}

#pragma section

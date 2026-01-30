#pragma section REPRO
/**
 * @file
 * @brief  ブロックコマンド定義
 * @note   このコードは自動生成されています！
 */
#include "sl_initial.h"

#include <src_user/tlm_cmd/block_command_definitions.h>
#include <src_user/tlm_cmd/command_definitions.h>

#include <src_core/applications/timeline_command_dispatcher_id_define.h>
#include <src_core/tlm_cmd/block_command_loader.h>
#include <src_core/system/time_manager/obc_time.h>


void BCL_load_sl_start_up_to_initial(void)
{
  // HK出力開始
  BCL_tool_register_deploy(10, BC_HK_CYCLIC_TLM, TLCD_ID_DEPLOY_TLM);
}

#pragma section

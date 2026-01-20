#pragma section REPRO
/**
 * @file
 * @brief  ブロックコマンド定義
 * @note   このコードは自動生成されています！
 */
#include "tl_start_up.h"

#include <src_user/applications/app_registry.h>
#include <src_user/tlm_cmd/block_command_definitions.h>

#include <src_core/tlm_cmd/block_command_loader.h>


void BCL_load_tl_start_up(void)
{
  // 23step以上
  BCL_tool_register_combine(0, BC_AC_CDH_UPDATE);
  BCL_tool_register_rotate(95, BC_AR_DEBUG_DISPLAY_INI);
}

#pragma section

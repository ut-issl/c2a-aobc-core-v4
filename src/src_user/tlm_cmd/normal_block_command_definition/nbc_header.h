/**
 * @file
 * @brief  ブロックコマンド定義
 * @note   このコードは自動生成されています！
 */
#ifndef BC_HEADER_H_
#define BC_HEADER_H_

#include "../block_command_definitions.h"
#include <src_core/tlm_cmd/block_command_loader.h>
#include <src_core/tlm_cmd/block_command_table.h>
#include <string.h> // for memcpy
#include "../command_definitions.h"
#include "src_user/settings/system/event_handler_rules/event_handler_rules.h"
#include "src_user/settings/system/event_logger_group.h"

void BCL_load_sl_start_up_to_initial(void);
void BCL_load_tl_start_up(void);
void BCL_load_tl_initial(void);
void BCL_load_ar_debug_display_ini(void);
void BCL_load_ac_cdh_update(void);
void BCL_load_ac_tlm_cmd_hirate(void);
void BCL_load_hk_cyclic_tlm(void);

#endif

#pragma section REPRO
/**
 * @file
 * @brief  ブロックコマンド定義
 * @note   このコードは自動生成されています！
 */
#include "nbc_header.h"
#include "../telemetry_definitions.h"


void BCL_load_hk_cyclic_tlm(void)
{
  BCL_tool_register_deploy(10, BC_HK_CYCLIC_TLM, TLCD_ID_DEPLOY_TLM);
}

#pragma section

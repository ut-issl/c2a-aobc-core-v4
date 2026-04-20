/**
 * @file
 * @brief  ブロックコマンド定義
 * @note   このコードは自動生成されています！
 */
#ifndef BLOCK_COMMAND_DEFINITIONS_H_
#define BLOCK_COMMAND_DEFINITIONS_H_

// 登録されるBlockCommandTableのblock番号を規定
typedef enum
{
  BC_SL_START_UP_TO_INITIAL = 0,
  BC_TL_START_UP = 10,
  BC_TL_INITIAL = 11,
  BC_AR_DEBUG_DISPLAY_INI = 17,
  BC_AC_CDH_UPDATE = 19,
  BC_AC_TLM_CMD_HIRATE = 50,
  BC_HK_CYCLIC_TLM = 60,

  BC_POWER_ON_STIM377H = 70,

  BC_ID_MAX    // BCT 自体のサイズは BCT_MAX_BLOCKS で規定
} BC_DEFAULT_ID;

void BC_load_defaults(void);

#endif

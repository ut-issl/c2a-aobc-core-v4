/**
 * @file
 * @brief  HW 依存 Print, つまり ログ情報のフォーマット出力（デバッグ出力）
 */

#include <src_core/library/print.h>

#include <stdio.h>
#include <stdarg.h>

// #include "./print_arduino.h"
#include "../settings/sils_define.h"
#include "./RTT/SEGGER_RTT.h"

// バッファサイズよりでかい文字列が来ると死ぬ
static char PRINT_buffer_[512];

#ifndef SILS_FW

#include <src_core/system/watchdog_timer/watchdog_timer.h>

void Printf(const char* format, ...)
{
  // int threshold = 0;
  va_list argptr;

  WDT_clear_wdt();

  va_start(argptr, format);
  // threshold = vsprintf(PRINT_buffer_, format, argptr);
  SEGGER_RTT_vprintf(0, format, &argptr);

  // printf_debug(PRINT_buffer_); // H/W dependent
  va_end(argptr);

  WDT_clear_wdt();
}

#else // SILS用

void Printf(const char* format, ...)
{
  #ifdef SHOW_DEBUG_PRINT_ON_SILS
  va_list args;
  va_start(args, format);
  vsprintf(PRINT_buffer_, format, args);

  printf("%s", PRINT_buffer_);
  fflush(stdout);

  va_end(args);
#else
  // なにも表示しない
#endif
}

#endif

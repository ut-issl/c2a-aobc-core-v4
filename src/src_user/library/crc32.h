/**
 * @file  crc32.h
 * @brief CRC32用のライブラリ
 */
#ifndef CRC32_H_
#define CRC32_H_

#include <stdint.h>

/**
  * @brief CRC-32 (STIM377H用)
  *
  *        生成多項式: 0x04C11DB7 (x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1)
  *        ビット送り: 左送り (MSB-first), 反転なし
  *        初期値: 0xFFFFFFFF
  *        読み出し: 4byte(32 bit)
  * @param[in] crc: CRC初期値または前回の計算結果
  * @param[in] data: CRCを計算するbyte列
  * @param[in] length: 列の長さ
  * @return uint32_t: 計算結果
  */
uint32_t crc_32_stim377h(uint32_t crc, const uint8_t* data, uint32_t length);

#endif

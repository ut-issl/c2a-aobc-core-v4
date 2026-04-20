/**
 * @file crc32.c
 * @brief CRC32用のライブラリ
 */
#include "crc32.h"

static const uint32_t CRC32_STIM377H_POLYNOMIAL_ = 0x04C11DB7u;

uint32_t crc_32_stim377h(uint32_t crc, const uint8_t* data, uint32_t length)
{
  uint32_t i;
  int bit;

  for (i = 0; i < length; i++)
  {
    crc ^= (uint32_t)data[i] << 24;
    for (bit = 0; bit < 8; bit++)
    {
      crc = (crc & 0x80000000u) ? (crc << 1) ^ CRC32_STIM377H_POLYNOMIAL_ : crc << 1;
    }
  }

  return crc;
}

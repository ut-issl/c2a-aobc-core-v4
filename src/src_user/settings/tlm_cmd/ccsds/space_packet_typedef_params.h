/**
 * @file
 * @brief SpacePacketの パケット型に関するユーザー設定
 */
#ifndef SPACE_PACKET_TYPEDEF_PARAMS_H_
#define SPACE_PACKET_TYPEDEF_PARAMS_H_

#undef TSP_MAX_LEN
#undef CSP_MAX_LEN

// 240 だったが、STM32評価基盤に書き込む際にメモリ不足のエラーが出たので、
// src/src_core/examples/subobc/src/src_user/settings/tlm_cmd/ccsds/space_packet_typedef_params.h 
// と同じく432にした。
#define TSP_MAX_LEN  (432)

// double引数6個程度確保できるので64byteで十分
#define CSP_MAX_LEN  (64) // 内15byteはヘッダなど

#endif

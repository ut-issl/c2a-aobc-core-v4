/**
* @file   csrv_stim377h.h
* @brief  STIM377HのComponent Service
*/
#ifndef CSRV_STIM377H_H_
#define CSRV_STIM377H_H_

#include "../../component_driver/Aocs/stim377h.h"
#include <src_core/system/application_manager/app_info.h>
#include "../../library/SignalProcess/polynomial_approximation.h"

/**
 * @enum  STIM377H_IDX
 * @brief 搭載されているSTIM377Hの管理番号
 * @note  uint8_tを想定
 * @note  要素数が変わった場合、cファイル側の初期化部分の修正が必要になる点に注意する
 */
typedef enum
{
  STIM377H_IDX_IN_UNIT = 0,
  STIM377H_IDX_MAX,
} STIM377H_IDX;

/**
 * @enum  STIM377H_EL_NOTE
 * @brief STIM377Hに関連するELの詳細
 * @note  型はuint8_tを想定
 */
typedef enum
{
  STIM377H_EL_NOTE_STATUS_ERROR = 0,
  STIM377H_EL_NOTE_NOISE_REMOVED,
  STIM377H_EL_NOTE_MAX,
} STIM377H_EL_NOTE;

/**
 * @struct CsrvStim377H
 * @brief STIM377H CSRVに関する外部公開情報用構造体
 */
typedef struct
{
  // 温度補正
  PolynomialApprox bias_compo_rad_s[PHYSICAL_CONST_THREE_DIM];   //!< コンポ座標でのセンサバイアス温度補正パラメータ [rad/s]
  PolynomialApprox scale_factor_compo[PHYSICAL_CONST_THREE_DIM]; //!< コンポ座標でのセンサスケールファクタ温度補正パラメータ [-]
} CsrvStim377H;

extern const STIM377H_Driver* const stim377h_driver[STIM377H_IDX_MAX];
extern const CsrvStim377H* const csrv_stim377h[STIM377H_IDX_MAX];

/**
 * @brief  STIM377H定期実行アプリ生成関数
 * @param  void
 * @return AppInfo
 */
AppInfo CSRV_STIM377H_update(void);

CCP_CmdRet Cmd_CSRV_STIM377H_INIT(const CommonCmdPacket* packet);
CCP_CmdRet Cmd_CSRV_STIM377H_SET_MODE(const CommonCmdPacket* packet);
CCP_CmdRet Cmd_CSRV_STIM377H_SET_NORMAL_MODE_FORMAT(const CommonCmdPacket* packet);
CCP_CmdRet Cmd_CSRV_STIM377H_SET_GYRO_OUTPUT(const CommonCmdPacket* packet);
CCP_CmdRet Cmd_CSRV_STIM377H_SET_SAMPLE_RATE(const CommonCmdPacket* packet);
CCP_CmdRet Cmd_CSRV_STIM377H_SET_TERMINATION_MODE(const CommonCmdPacket* packet);
CCP_CmdRet Cmd_CSRV_STIM377H_SET_LOW_PASS_FILTER(const CommonCmdPacket* packet);
CCP_CmdRet Cmd_CSRV_STIM377H_SET_FRAME_TRANSFORMATION_QUATERNION_C2B(const CommonCmdPacket* packet);
CCP_CmdRet Cmd_CSRV_STIM377H_SET_ANG_VEL_BIAS_COMPO_RAD_S(const CommonCmdPacket* packet);
// 温度補正
CCP_CmdRet Cmd_CSRV_STIM377H_SET_ANG_VEL_BIAS_TEMP_CALIB(const CommonCmdPacket* packet);
CCP_CmdRet Cmd_CSRV_STIM377H_SET_ANG_VEL_SF_TEMP_CALIB(const CommonCmdPacket* packet);

#endif

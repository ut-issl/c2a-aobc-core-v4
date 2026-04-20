/**
* @file   stim377H.h
* @brief  STIM377Hジャイロセンサのドライバ
*/

#ifndef STIM377H_H_
#define STIM377H_H_

#include <src_core/hal/uart.h>
#include <src_core/component_driver/driver_super.h>

#include <src_user/hal/GPIO.h>
#include <src_user/library/physical_constants.h>
#include <src_user/library/quaternion.h>

#define CDS_HAL_RX_BUFFER_SIZE_STIM377H (72)  //!< HAL_RXのバッファサイズ (最大フレーム65byte + 余裕)

/**
 * @enum   STIM377H_OPERATION_MODE
 * @brief  STIM377Hの運用モード
 * @note   uint8_tを想定
 */
typedef enum
{
  STIM377H_OPERATION_INIT_MODE = 0,
  STIM377H_OPERATION_NORMAL_MODE,
  STIM377H_OPERATION_SERVICE_MODE,
  STIM377H_OPERATION_MODE_MAX
} STIM377H_OPERATION_MODE;

/**
 * @enum   STIM377H_NORMAL_MODE_FORMAT
 * @brief  ノーマルモードの出力設定 (16種類, データシートTable 5-21)
 * @note   uint8_tを想定
 */
typedef enum
{
  STIM377H_NORMAL_MODE_RATE = 0,
  STIM377H_NORMAL_MODE_RATE_ACC,
  STIM377H_NORMAL_MODE_RATE_INCL,
  STIM377H_NORMAL_MODE_RATE_ACC_INCL,
  STIM377H_NORMAL_MODE_RATE_TEMPERATURE,
  STIM377H_NORMAL_MODE_RATE_ACC_TEMP,
  STIM377H_NORMAL_MODE_RATE_INCL_TEMP,
  STIM377H_NORMAL_MODE_RATE_ACC_INCL_TEMP,
  STIM377H_NORMAL_MODE_RATE_AUX,
  STIM377H_NORMAL_MODE_RATE_ACC_AUX,
  STIM377H_NORMAL_MODE_RATE_INCL_AUX,
  STIM377H_NORMAL_MODE_RATE_ACC_INCL_AUX,
  STIM377H_NORMAL_MODE_RATE_TEMP_AUX,
  STIM377H_NORMAL_MODE_RATE_ACC_TEMP_AUX,
  STIM377H_NORMAL_MODE_RATE_INCL_TEMP_AUX,
  STIM377H_NORMAL_MODE_RATE_ACC_INCL_TEMP_AUX,
  STIM377H_NORMAL_MODE_MAX
} STIM377H_NORMAL_MODE_FORMAT;

/**
 * @enum   STIM377H_GYRO_OUTPUT_MODE
 * @brief  ジャイロ出力モード
 * @note   uint8_tを想定
 */
typedef enum
{
  STIM377H_GYRO_OUTPUT_ANGULAR_RATE = 0,
  STIM377H_GYRO_OUTPUT_INCREMENTAL_ANGLE,
  STIM377H_GYRO_OUTPUT_AVERAGE_ANGULAR_RATE,
  STIM377H_GYRO_OUTPUT_INTEGRATED_ANGLE,
  STIM377H_GYRO_OUTPUT_MODE_MAX
} STIM377H_GYRO_OUTPUT_MODE;

/**
 * @enum   STIM377H_TERMINATION_MODE
 * @brief  データグラムのCRLF終端設定 (0: なし, 1: CRLF付与)
 * @note   uint8_tを想定
 */
typedef enum
{
  STIM377H_TERMINATION_OFF = 0,
  STIM377H_TERMINATION_CRLF,
  STIM377H_TERMINATION_MODE_MAX
} STIM377H_TERMINATION_MODE;

/**
 * @enum   STIM377H_LPF
 * @brief  ジャイロ出力ローパスフィルタの指定可能なカットオフ周波数
 * @note   uint8_tを想定
 */
typedef enum
{
  STIM377H_LPF_16HZ = 0,
  STIM377H_LPF_33HZ,
  STIM377H_LPF_66HZ,
  STIM377H_LPF_131HZ,
  STIM377H_LPF_262HZ,
  STIM377H_LPF_MAX
} STIM377H_LPF;

/**
 * @enum   STIM377H_SAMPLE_RATE
 * @brief  ジャイロ出力のサンプルレート
 * @note   uint8_tを想定
 */
typedef enum
{
  STIM377H_SAMPLE_RATE_EXTERNAL_TRIGGER = 0,
  STIM377H_SAMPLE_RATE_125HZ,
  STIM377H_SAMPLE_RATE_250HZ,
  STIM377H_SAMPLE_RATE_500HZ,
  STIM377H_SAMPLE_RATE_1000HZ,
  STIM377H_SAMPLE_RATE_2000HZ,
  STIM377H_SAMPLE_RATE_MAX
} STIM377H_SAMPLE_RATE;

/**
 * @enum  STIM377H_CRC_STATE
 * @brief STIM377Hから送られてきたデータのCRC計算結果
 * @note  uint8_tを想定
 */
typedef enum
{
  STIM377H_CRC_STATE_OK = 0,
  STIM377H_CRC_STATE_NG = 1
} STIM377H_CRC_STATE;

/**
 * @struct STIM377H_Info
 * @brief  STIM377Hのモードや変数などを格納する
 */
typedef struct
{
  float ang_vel_raw_compo_rad_sec[PHYSICAL_CONST_THREE_DIM];  //!< 補正前角速度 @ component frame [rad/s]
  float ang_vel_compo_rad_sec[PHYSICAL_CONST_THREE_DIM];      //!< 補正後角速度 @ component frame [rad/s]
  float ang_vel_body_rad_sec [PHYSICAL_CONST_THREE_DIM];      //!< 補正後角速度 @ body frame [rad/s]
  float ang_vel_bias_compo_rad_sec[PHYSICAL_CONST_THREE_DIM]; //!< 角速度バイアス @ component frame [rad/s]
  float ang_vel_scale_factor_compo[PHYSICAL_CONST_THREE_DIM][PHYSICAL_CONST_THREE_DIM]; //!< scale factor of angular velocity @ component frame [-]

  float ang_compo_rad[PHYSICAL_CONST_THREE_DIM];           //!< 前回の観測から今回の観測までの各軸の角速度積分値 @ component frame[rad]
  float temperature_compo_degC[PHYSICAL_CONST_THREE_DIM];  //!< 温度 (Rateセンサ) @ component frame [degC]
  Quaternion frame_transform_c2b;                          //!< frame transformation quaternion from component frame to body frame

  uint8_t status;        //!< ジャイロ出力のステータス (0: OK, >0: NG)
  uint8_t counter;       //!< STIM377H内部サンプルカウンタ
  uint16_t latency_sec;  //!< 外部トリガ時の観測遅延時間 [µs]
  uint8_t buffer[3];     //!< buffer for future use
  uint32_t crc;          //!< CRC-32チェック用の変数

  STIM377H_OPERATION_MODE operation_mode;          //!< 運用モード
  STIM377H_NORMAL_MODE_FORMAT normal_mode_format;  //!< ノーマルモード時の出力フォーマット
  STIM377H_GYRO_OUTPUT_MODE gyro_output_mode;      //!< ジャイロ出力モード
  STIM377H_TERMINATION_MODE termination_mode;      //!< CRLF終端設定
  STIM377H_LPF low_pass_filter_frequency;          //!< ローパスフィルタカットオフ周波数設定
  STIM377H_SAMPLE_RATE sample_rate;                //!< 出力のサンプリングレート設定
  STIM377H_CRC_STATE crc_state;                    //!< 受信したCRCが正しいか

} STIM377H_Info;

/**
 * @struct STIM377H_Driver
 * @brief STIM377H_Driver構造体
 */
typedef struct
{
  struct
  {
    ComponentDriverSuper super;        //!< ComponentDriverSuper class
    UART_Config uart_config;  //!< UART class
    uint8_t ch_gpio_trig;     //!< GPIO port for external trigger
    uint8_t ch_gpio_reset;    //!< GPIO port for sending reset signal to STIM377H
  } driver;
  STIM377H_Info info;
} STIM377H_Driver;

// 基本関数

/**
 * @brief  STIM377H初期化
 *
 *         STIM377H_Driver構造体のポインタを渡すことでポートを初期化し，STIM377H_Driverの各メンバも初期化する
 * @param  stim377h_driver    : 初期化するSTIM377H_Driver構造体へのポインタ
 * @param  ch      : STIM377Hが接続されているUARTポート番号
 * @param  ch_gpio_trig  : STIM377Hが接続されているテレメトリ送出信号送信用GPIOポート番号
 * @param  ch_gpio_reset : STIM377Hが接続されているReset信号送信用GPIOポート番号
 * @param  rx_buffer: 受信バッファ
 * @return CDS_INIT_ERR_CODE
 */
CDS_INIT_ERR_CODE STIM377H_init(STIM377H_Driver* stim377h_driver,
                               uint8_t ch,
                               uint8_t ch_gpio_trig,
                               uint8_t ch_gpio_reset,
                               CDS_StreamRecBuffer* rx_buffer);

/**
 * @brief  STIM377Hのパラメータを初期値にリセットする。
 *
 *         電源OFF時のみ実行可能。それ以外の時は異常終了する。
 * @param  stim377h_driver    : STIM377H_Driver構造体へのポインタ
 * @retval 0       : 正常終了
 * @retval 0以外   : 異常終了
 */
int STIM377H_reset_param(STIM377H_Driver* stim377h_driver);

/**
 * @brief  STIM377Hのデータ（テレメ）受信
 *
 *         ノーマルモードのみ実行可能。それ以外の時は異常終了する。
 * @param  stim377h_driver : STIM377H_Driver構造体へのポインタ
 * @retval CDS_REC_ERR_CODEに準拠
 */
CDS_REC_ERR_CODE STIM377H_rec(STIM377H_Driver* stim377h_driver);

/**
 * @brief  GPIOを用いたSTIM377Hのテレメ送信
 * @param  stim377h_driver : STIM377H_Driver構造体へのポインタ
 * @retval 0     : 正常終了
 * @retval 0以外 : 異常終了
 * @note   GPIO LOWを250ns以上キープする。テレメ送信は86us後に始まる。
 */
int STIM377H_send_tlm_by_gpio(STIM377H_Driver* stim377h_driver);

/**
 * @brief  GPIOを用いたSTIM377Hのリセット
 * @param  stim377h_driver : STIM377H_Driver構造体へのポインタ
 * @retval 0     : 正常終了
 * @retval 0以外 : 異常終了
 * @note   GPIO HIGHを1us以上キープする。パラメータもリセットする。
 */
int STIM377H_reset_by_gpio(STIM377H_Driver* stim377h_driver);

/**
 * @brief  STIM377Hの運用モードをサービスモードにする
 *
 *         ノーマルモードと初期モードで実行可能。それ以外の時は異常終了する。
 * @param  stim377h_driver : STIM377H_Driver構造体へのポインタ
 * @return CDS_CMD_ERR_CODEを参照
 */
CDS_CMD_ERR_CODE STIM377H_set_service_mode(STIM377H_Driver* stim377h_driver);

/**
 * @brief  STIM377Hのノーマルモードでの出力フォーマットを変更する
 *
 *         サービスモードのみ実行可能。それ以外の時は異常終了する。
 * @param  stim377h_driver : STIM377H_Driver構造体へのポインタ
 * @param  normal_mode_format : 出力フォーマット
 * @return CDS_CMD_ERR_CODEを参照
 */
CDS_CMD_ERR_CODE STIM377H_set_normal_mode_format(STIM377H_Driver* stim377h_driver, STIM377H_NORMAL_MODE_FORMAT normal_mode_format);

/**
 * @brief  STIM377Hのノーマルモードのサンプルレートを変更する
 *
 *         サービスモードのみ実行可能。
 * @param  stim377h_driver : STIM377H_Driver構造体へのポインタ
 * @param  sample_rate : サンプルレート
 * @return CDS_CMD_ERR_CODEを参照
 */
CDS_CMD_ERR_CODE STIM377H_set_sample_rate(STIM377H_Driver* stim377h_driver, STIM377H_SAMPLE_RATE sample_rate);

/**
 * @brief  STIM377Hのノーマルモードでのジャイロ出力を変更する
 *
 *         サービスモードのみ実行可能。それ以外の時は異常終了する。
 * @param  stim377h_driver : STIM377H_Driver構造体へのポインタ
 * @param  gyro_output_mode : ジャイロ出力
 * @return CDS_CMD_ERR_CODEを参照
 */
CDS_CMD_ERR_CODE STIM377H_set_gyro_output(STIM377H_Driver* stim377h_driver, STIM377H_GYRO_OUTPUT_MODE gyro_output_mode);

/**
 * @brief  STIM377HのデータグラムのCRLF終端を変更する
 *
 *         サービスモードのみ実行可能。それ以外の時は異常終了する。
 * @param  stim377h_driver : STIM377H_Driver構造体へのポインタ
 * @param  termination_mode : CRLF終端設定
 * @return CDS_CMD_ERR_CODEを参照
 */
CDS_CMD_ERR_CODE STIM377H_set_termination_mode(STIM377H_Driver* stim377h_driver, STIM377H_TERMINATION_MODE termination_mode);

/**
 * @brief  STIM377HのLPFのカットオフ周波数を変更する
 *
 *         サービスモードのみ実行可能。それ以外の時は異常終了する。
 * @param  stim377h_driver : STIM377H_Driver構造体へのポインタ
 * @param  low_pass_filter_frequency : LPFのカットオフ周波数
 * @return CDS_CMD_ERR_CODEを参照
 */
CDS_CMD_ERR_CODE STIM377H_set_low_pass_filter(STIM377H_Driver* stim377h_driver, STIM377H_LPF low_pass_filter_frequency);

/**
 * @brief  STIM377Hをノーマルモードに移行する
 *
 *         サービスモードのみ実行可能。それ以外の時は異常終了する。
 * @param  stim377h_driver : STIM377H_Driver構造体へのポインタ
 * @return CDS_CMD_ERR_CODEを参照
 */
CDS_CMD_ERR_CODE STIM377H_set_normal_mode(STIM377H_Driver* stim377h_driver);

/**
 * @brief  座標変換行列設定関数
 * @param  stim377h_driver  : STIM377H_Driver構造体へのポインタ
 * @param  q_c2b            : コンポ座標からボディ座標への座標変換Quaternion
 * @return C2A_MATH_ERRORに準じる
 */
C2A_MATH_ERROR STIM377H_set_frame_transform_c2b(STIM377H_Driver* stim377h_driver, const Quaternion q_c2b);

/**
 * @brief  角速度バイアス補正値設定関数
 * @param  stim377h_driver  : STIM377H_Driver構造体へのポインタ
 * @param  ang_vel_bias_compo_rad_s : コンポ座標での角速度バイアス補正値(計測値からこの値を差し引く)
 * @return C2A_MATH_ERROR_RANGE_OVER : 補正値が大きすぎる場合
 */
C2A_MATH_ERROR STIM377H_set_ang_vel_bias_compo_rad_s(STIM377H_Driver* stim377h_driver, const float ang_vel_bias_compo_rad_s[PHYSICAL_CONST_THREE_DIM]);

/**
 * @brief  角速度スケールファクタ行列設定関数
 * @param  stim377h_driver  : STIM377H_Driver構造体へのポインタ
 * @param  ang_vel_scale_factor_compo : コンポ座標でのスケールファクタ行列
 * @return C2A_MATH_ERRORに準じる
 */
C2A_MATH_ERROR STIM377H_set_ang_vel_scale_factor_compo(STIM377H_Driver* stim377h_driver,
                                                      const float ang_vel_scale_factor_compo[PHYSICAL_CONST_THREE_DIM][PHYSICAL_CONST_THREE_DIM]);

#endif

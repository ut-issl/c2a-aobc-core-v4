#pragma section REPRO
/**
 * @file
 * @brief  テレメトリ定義
 * @note   このコードは自動生成されています！
 */
#include <src_core/tlm_cmd/telemetry_frame.h>
#include "telemetry_definitions.h"
#include "telemetry_source.h"

static TF_TLM_FUNC_ACK Tlm_AOBC_OBC_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_TL_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_BL_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_CA_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_TF_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_DCU_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_MM_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_AM_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_APP_TIME_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_EL_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_EL_TLOG_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_EL_CLOG_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_EH_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_EH_RULE_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_EH_LOG_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_EH_INDEX_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_GIT_REV_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_HK_GEN_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_HK_COMPO_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_HK_ALGO_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_COMPONENTS_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_POWER_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_FRAME_TRANSFORMATION_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_CONTROL_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_BIAS_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_TEMP_CALIB_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_INTERPOLATION_TARGET1_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_INTERPOLATION_TARGET2_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_NON_VOLATILE_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_ORBIT_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_AOCS_MANAGER_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_SUN_POINTING_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_THREE_AXIS_MTQ_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_THREE_AXIS_RW_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_FILTERS_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_ANOMALY_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_APP_TIME_2_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA_SET1_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA_SET2_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA_READ1_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA_READ2_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_STT_GYRO_EKF1_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_STT_GYRO_EKF2_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_GPSR_RANGE_P1_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_GPSR_RANGE_P2_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_ORBIT2_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_FILTERS_2_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_DR_ALGORITHM_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_RW_DETAILED_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA1_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA2_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA3_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA4_(uint8_t* packet, uint16_t* len, uint16_t max_len);
static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA5_(uint8_t* packet, uint16_t* len, uint16_t max_len);

void TF_load_tlm_table(TF_TlmInfo tlm_table[TF_MAX_TLMS])
{
  tlm_table[Tlm_CODE_AOBC_OBC].tlm_func = Tlm_AOBC_OBC_;
  tlm_table[Tlm_CODE_AOBC_TL].tlm_func = Tlm_AOBC_TL_;
  tlm_table[Tlm_CODE_AOBC_BL].tlm_func = Tlm_AOBC_BL_;
  tlm_table[Tlm_CODE_AOBC_CA].tlm_func = Tlm_AOBC_CA_;
  tlm_table[Tlm_CODE_AOBC_TF].tlm_func = Tlm_AOBC_TF_;
  tlm_table[Tlm_CODE_AOBC_DCU].tlm_func = Tlm_AOBC_DCU_;
  tlm_table[Tlm_CODE_AOBC_MM].tlm_func = Tlm_AOBC_MM_;
  tlm_table[Tlm_CODE_AOBC_AM].tlm_func = Tlm_AOBC_AM_;
  tlm_table[Tlm_CODE_AOBC_APP_TIME].tlm_func = Tlm_AOBC_APP_TIME_;
  tlm_table[Tlm_CODE_AOBC_EL].tlm_func = Tlm_AOBC_EL_;
  tlm_table[Tlm_CODE_AOBC_EL_TLOG].tlm_func = Tlm_AOBC_EL_TLOG_;
  tlm_table[Tlm_CODE_AOBC_EL_CLOG].tlm_func = Tlm_AOBC_EL_CLOG_;
  tlm_table[Tlm_CODE_AOBC_EH].tlm_func = Tlm_AOBC_EH_;
  tlm_table[Tlm_CODE_AOBC_EH_RULE].tlm_func = Tlm_AOBC_EH_RULE_;
  tlm_table[Tlm_CODE_AOBC_EH_LOG].tlm_func = Tlm_AOBC_EH_LOG_;
  tlm_table[Tlm_CODE_AOBC_EH_INDEX].tlm_func = Tlm_AOBC_EH_INDEX_;
  tlm_table[Tlm_CODE_AOBC_GIT_REV].tlm_func = Tlm_AOBC_GIT_REV_;
  tlm_table[Tlm_CODE_AOBC_HK_GEN].tlm_func = Tlm_AOBC_HK_GEN_;
  tlm_table[Tlm_CODE_AOBC_HK_COMPO].tlm_func = Tlm_AOBC_HK_COMPO_;
  tlm_table[Tlm_CODE_AOBC_HK_ALGO].tlm_func = Tlm_AOBC_HK_ALGO_;
  tlm_table[Tlm_CODE_AOBC_COMPONENTS].tlm_func = Tlm_AOBC_COMPONENTS_;
  tlm_table[Tlm_CODE_AOBC_POWER].tlm_func = Tlm_AOBC_POWER_;
  tlm_table[Tlm_CODE_AOBC_FRAME_TRANSFORMATION].tlm_func = Tlm_AOBC_FRAME_TRANSFORMATION_;
  tlm_table[Tlm_CODE_AOBC_CONTROL].tlm_func = Tlm_AOBC_CONTROL_;
  tlm_table[Tlm_CODE_AOBC_BIAS].tlm_func = Tlm_AOBC_BIAS_;
  tlm_table[Tlm_CODE_AOBC_TEMP_CALIB].tlm_func = Tlm_AOBC_TEMP_CALIB_;
  tlm_table[Tlm_CODE_AOBC_INTERPOLATION_TARGET1].tlm_func = Tlm_AOBC_INTERPOLATION_TARGET1_;
  tlm_table[Tlm_CODE_AOBC_INTERPOLATION_TARGET2].tlm_func = Tlm_AOBC_INTERPOLATION_TARGET2_;
  tlm_table[Tlm_CODE_AOBC_NON_VOLATILE].tlm_func = Tlm_AOBC_NON_VOLATILE_;
  tlm_table[Tlm_CODE_AOBC_ORBIT].tlm_func = Tlm_AOBC_ORBIT_;
  tlm_table[Tlm_CODE_AOBC_AOCS_MANAGER].tlm_func = Tlm_AOBC_AOCS_MANAGER_;
  tlm_table[Tlm_CODE_AOBC_SUN_POINTING].tlm_func = Tlm_AOBC_SUN_POINTING_;
  tlm_table[Tlm_CODE_AOBC_THREE_AXIS_MTQ].tlm_func = Tlm_AOBC_THREE_AXIS_MTQ_;
  tlm_table[Tlm_CODE_AOBC_THREE_AXIS_RW].tlm_func = Tlm_AOBC_THREE_AXIS_RW_;
  tlm_table[Tlm_CODE_AOBC_FILTERS].tlm_func = Tlm_AOBC_FILTERS_;
  tlm_table[Tlm_CODE_AOBC_ANOMALY].tlm_func = Tlm_AOBC_ANOMALY_;
  tlm_table[Tlm_CODE_AOBC_APP_TIME_2].tlm_func = Tlm_AOBC_APP_TIME_2_;
  tlm_table[Tlm_CODE_AOBC_SAGITTA_SET1].tlm_func = Tlm_AOBC_SAGITTA_SET1_;
  tlm_table[Tlm_CODE_AOBC_SAGITTA_SET2].tlm_func = Tlm_AOBC_SAGITTA_SET2_;
  tlm_table[Tlm_CODE_AOBC_SAGITTA_READ1].tlm_func = Tlm_AOBC_SAGITTA_READ1_;
  tlm_table[Tlm_CODE_AOBC_SAGITTA_READ2].tlm_func = Tlm_AOBC_SAGITTA_READ2_;
  tlm_table[Tlm_CODE_AOBC_STT_GYRO_EKF1].tlm_func = Tlm_AOBC_STT_GYRO_EKF1_;
  tlm_table[Tlm_CODE_AOBC_STT_GYRO_EKF2].tlm_func = Tlm_AOBC_STT_GYRO_EKF2_;
  tlm_table[Tlm_CODE_AOBC_GPSR_RANGE_P1].tlm_func = Tlm_AOBC_GPSR_RANGE_P1_;
  tlm_table[Tlm_CODE_AOBC_GPSR_RANGE_P2].tlm_func = Tlm_AOBC_GPSR_RANGE_P2_;
  tlm_table[Tlm_CODE_AOBC_ORBIT2].tlm_func = Tlm_AOBC_ORBIT2_;
  tlm_table[Tlm_CODE_AOBC_FILTERS_2].tlm_func = Tlm_AOBC_FILTERS_2_;
  tlm_table[Tlm_CODE_AOBC_DR_ALGORITHM].tlm_func = Tlm_AOBC_DR_ALGORITHM_;
  tlm_table[Tlm_CODE_AOBC_RW_DETAILED].tlm_func = Tlm_AOBC_RW_DETAILED_;
  tlm_table[Tlm_CODE_AOBC_SAGITTA1].tlm_func = Tlm_AOBC_SAGITTA1_;
  tlm_table[Tlm_CODE_AOBC_SAGITTA2].tlm_func = Tlm_AOBC_SAGITTA2_;
  tlm_table[Tlm_CODE_AOBC_SAGITTA3].tlm_func = Tlm_AOBC_SAGITTA3_;
  tlm_table[Tlm_CODE_AOBC_SAGITTA4].tlm_func = Tlm_AOBC_SAGITTA4_;
  tlm_table[Tlm_CODE_AOBC_SAGITTA5].tlm_func = Tlm_AOBC_SAGITTA5_;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_OBC_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (215 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u32(&packet[26], (uint32_t)(TMGR_get_master_clock().mode_cycle));
  TF_copy_u8(&packet[30], (uint8_t)(mode_manager->stat));
  TF_copy_u8(&packet[31], (uint8_t)(mode_manager->current_id));
  TF_copy_u8(&packet[32], (uint8_t)(mode_manager->previous_id));
  TF_copy_u8(&packet[33], (uint8_t)(task_dispatcher->task_list_id));
  TF_copy_u32(&packet[34], (uint32_t)(task_dispatcher->tskd.prev_err.time.total_cycle));
  TF_copy_u8(&packet[38], (uint8_t)(task_dispatcher->tskd.prev_err.time.step));
  TF_copy_u16(&packet[39], (uint16_t)(task_dispatcher->tskd.prev_err.code));
  TF_copy_u8(&packet[41], (uint8_t)(task_dispatcher->tskd.prev_err.cmd_ret.exec_sts));
  TF_copy_u32(&packet[42], (uint32_t)(task_dispatcher->tskd.prev_err.cmd_ret.err_code));
  TF_copy_u32(&packet[46], PH_gs_cmd_list.executed_nodes_);
  TF_copy_u32(&packet[50], (uint32_t)(gs_command_dispatcher->prev.time.total_cycle));
  TF_copy_u16(&packet[54], (uint16_t)(gs_command_dispatcher->prev.code));
  TF_copy_u8(&packet[56], (uint8_t)(gs_command_dispatcher->prev.cmd_ret.exec_sts));
  TF_copy_u32(&packet[57], (uint32_t)(gs_command_dispatcher->prev.cmd_ret.err_code));
  TF_copy_u32(&packet[61], (uint32_t)(gs_command_dispatcher->prev_err.time.total_cycle));
  TF_copy_u16(&packet[65], (uint16_t)(gs_command_dispatcher->prev_err.code));
  TF_copy_u8(&packet[67], (uint8_t)(gs_command_dispatcher->prev_err.cmd_ret.exec_sts));
  TF_copy_u32(&packet[68], (uint32_t)(gs_command_dispatcher->prev_err.cmd_ret.err_code));
  TF_copy_u32(&packet[72], (uint32_t)(gs_command_dispatcher->error_counter));
  TF_copy_u32(&packet[76], PH_rt_cmd_list.executed_nodes_);
  TF_copy_u32(&packet[80], (uint32_t)(realtime_command_dispatcher->prev.time.total_cycle));
  TF_copy_u16(&packet[84], (uint16_t)(realtime_command_dispatcher->prev.code));
  TF_copy_u8(&packet[86], (uint8_t)(realtime_command_dispatcher->prev.cmd_ret.exec_sts));
  TF_copy_u32(&packet[87], (uint32_t)(realtime_command_dispatcher->prev.cmd_ret.err_code));
  TF_copy_u32(&packet[91], (uint32_t)(realtime_command_dispatcher->prev_err.time.total_cycle));
  TF_copy_u16(&packet[95], (uint16_t)(realtime_command_dispatcher->prev_err.code));
  TF_copy_u8(&packet[97], (uint8_t)(realtime_command_dispatcher->prev_err.cmd_ret.exec_sts));
  TF_copy_u32(&packet[98], (uint32_t)(realtime_command_dispatcher->prev_err.cmd_ret.err_code));
  TF_copy_u32(&packet[102], (uint32_t)(realtime_command_dispatcher->error_counter));
  TF_copy_u32(&packet[106], PH_tl_cmd_list[TLCD_ID_FROM_GS].executed_nodes_);
  TF_copy_u8(&packet[110], (uint8_t)(PH_tl_cmd_list[TLCD_ID_FROM_GS].active_nodes_));
  TF_copy_u32(&packet[111], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev.time.total_cycle));
  TF_copy_u16(&packet[115], (uint16_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev.code));
  TF_copy_u8(&packet[117], (uint8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev.cmd_ret.exec_sts));
  TF_copy_u32(&packet[118], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev.cmd_ret.err_code));
  TF_copy_u32(&packet[122], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev_err.time.total_cycle));
  TF_copy_u16(&packet[126], (uint16_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev_err.code));
  TF_copy_u8(&packet[128], (uint8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev_err.cmd_ret.exec_sts));
  TF_copy_u32(&packet[129], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev_err.cmd_ret.err_code));
  TF_copy_u32(&packet[133], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].error_counter));
  TF_copy_u8(&packet[137], (uint8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].stop_on_error));
  TF_copy_u8(&packet[138], (uint8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].lockout));
  TF_copy_u32(&packet[139], (PL_is_empty(&(PH_tl_cmd_list[TLCD_ID_FROM_GS])) ? 0 : CCP_get_ti((const CommonCmdPacket*)(PL_get_head(&(PH_tl_cmd_list[TLCD_ID_FROM_GS]))->packet))));
  TF_copy_u16(&packet[143], (uint16_t)(PL_is_empty(&(PH_tl_cmd_list[TLCD_ID_FROM_GS])) ? 0 : CCP_get_id((const CommonCmdPacket*)(PL_get_head(&(PH_tl_cmd_list[TLCD_ID_FROM_GS]))->packet))));
  TF_copy_u32(&packet[145], PH_tl_cmd_list[TLCD_ID_DEPLOY_BC].executed_nodes_);
  TF_copy_u8(&packet[149], (uint8_t)(PH_tl_cmd_list[TLCD_ID_DEPLOY_BC].active_nodes_));
  TF_copy_u32(&packet[150], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].prev.time.total_cycle));
  TF_copy_u16(&packet[154], (uint16_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].prev.code));
  TF_copy_i8(&packet[156], (int8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].prev.cmd_ret.exec_sts));
  TF_copy_u32(&packet[157], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].prev_err.time.total_cycle));
  TF_copy_u16(&packet[161], (uint16_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].prev_err.code));
  TF_copy_i8(&packet[163], (int8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].prev_err.cmd_ret.exec_sts));
  TF_copy_u32(&packet[164], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].error_counter));
  TF_copy_u8(&packet[168], (uint8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].stop_on_error));
  TF_copy_u8(&packet[169], (uint8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].lockout));
  TF_copy_u32(&packet[170], (PL_is_empty(&(PH_tl_cmd_list[TLCD_ID_DEPLOY_BC])) ? 0 : CCP_get_ti((const CommonCmdPacket*)(PL_get_head(&(PH_tl_cmd_list[TLCD_ID_DEPLOY_BC]))->packet))));
  TF_copy_u16(&packet[174], (uint16_t)(PL_is_empty(&(PH_tl_cmd_list[TLCD_ID_DEPLOY_BC])) ? 0 : CCP_get_id((const CommonCmdPacket*)(PL_get_head(&(PH_tl_cmd_list[TLCD_ID_DEPLOY_BC]))->packet))));
  TF_copy_u32(&packet[176], PH_tl_cmd_list[TLCD_ID_DEPLOY_TLM].executed_nodes_);
  TF_copy_u8(&packet[180], (uint8_t)(PH_tl_cmd_list[TLCD_ID_DEPLOY_TLM].active_nodes_));
  TF_copy_u32(&packet[181], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].prev.time.total_cycle));
  TF_copy_u16(&packet[185], (uint16_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].prev.code));
  TF_copy_i8(&packet[187], (int8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].prev.cmd_ret.exec_sts));
  TF_copy_u32(&packet[188], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].prev_err.time.total_cycle));
  TF_copy_u16(&packet[192], (uint16_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].prev_err.code));
  TF_copy_i8(&packet[194], (int8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].prev_err.cmd_ret.exec_sts));
  TF_copy_u32(&packet[195], (uint32_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].error_counter));
  TF_copy_u8(&packet[199], (uint8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].stop_on_error));
  TF_copy_u8(&packet[200], (uint8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].lockout));
  TF_copy_u32(&packet[201], (PL_is_empty(&(PH_tl_cmd_list[TLCD_ID_DEPLOY_TLM])) ? 0 : CCP_get_ti((const CommonCmdPacket*)(PL_get_head(&(PH_tl_cmd_list[TLCD_ID_DEPLOY_TLM]))->packet))));
  TF_copy_u16(&packet[205], (uint16_t)(PL_is_empty(&(PH_tl_cmd_list[TLCD_ID_DEPLOY_TLM])) ? 0 : CCP_get_id((const CommonCmdPacket*)(PL_get_head(&(PH_tl_cmd_list[TLCD_ID_DEPLOY_TLM]))->packet))));
  TF_copy_u8(&packet[207], (uint8_t)(block_command_table->pos.block));
  TF_copy_u8(&packet[208], (uint8_t)(block_command_table->pos.cmd));
  TF_copy_u32(&packet[209], ((block_command_table->pos.cmd == 0) ? 0 : (uint32_t)BCT_get_ti(block_command_table->pos.block, (uint8_t)(block_command_table->pos.cmd-1))));
  TF_copy_u16(&packet[213], (uint16_t)((block_command_table->pos.cmd == 0) ? 0 : BCT_get_id(block_command_table->pos.block, (uint8_t)(block_command_table->pos.cmd-1))));
#endif

  *len = 215;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_TL_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  int offset = TL_TLM_PAGE_SIZE*(timeline_command_dispatcher->tlm_info_.page_no);

  if (224 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], TLCD_update_tl_list_for_tlm(timeline_command_dispatcher->tlm_info_.id));
  TF_copy_u8(&packet[27], timeline_command_dispatcher->tlm_info_.page_no);
  TF_copy_u32(&packet[28], timeline_command_dispatcher->tlm_info_.updated_at);
  TF_copy_u16(&packet[32], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+0]));
  TF_copy_u32(&packet[34], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+0]));
  TF_copy_u8(&packet[38], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+0])[0]);
  TF_copy_u8(&packet[39], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+0])[1]);
  TF_copy_u8(&packet[40], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+0])[2]);
  TF_copy_u8(&packet[41], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+0])[3]);
  TF_copy_u8(&packet[42], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+0])[4]);
  TF_copy_u8(&packet[43], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+0])[5]);
  TF_copy_u16(&packet[44], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+1]));
  TF_copy_u32(&packet[46], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+1]));
  TF_copy_u8(&packet[50], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+1])[0]);
  TF_copy_u8(&packet[51], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+1])[1]);
  TF_copy_u8(&packet[52], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+1])[2]);
  TF_copy_u8(&packet[53], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+1])[3]);
  TF_copy_u8(&packet[54], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+1])[4]);
  TF_copy_u8(&packet[55], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+1])[5]);
  TF_copy_u16(&packet[56], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+2]));
  TF_copy_u32(&packet[58], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+2]));
  TF_copy_u8(&packet[62], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+2])[0]);
  TF_copy_u8(&packet[63], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+2])[1]);
  TF_copy_u8(&packet[64], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+2])[2]);
  TF_copy_u8(&packet[65], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+2])[3]);
  TF_copy_u8(&packet[66], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+2])[4]);
  TF_copy_u8(&packet[67], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+2])[5]);
  TF_copy_u16(&packet[68], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+3]));
  TF_copy_u32(&packet[70], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+3]));
  TF_copy_u8(&packet[74], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+3])[0]);
  TF_copy_u8(&packet[75], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+3])[1]);
  TF_copy_u8(&packet[76], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+3])[2]);
  TF_copy_u8(&packet[77], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+3])[3]);
  TF_copy_u8(&packet[78], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+3])[4]);
  TF_copy_u8(&packet[79], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+3])[5]);
  TF_copy_u16(&packet[80], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+4]));
  TF_copy_u32(&packet[82], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+4]));
  TF_copy_u8(&packet[86], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+4])[0]);
  TF_copy_u8(&packet[87], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+4])[1]);
  TF_copy_u8(&packet[88], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+4])[2]);
  TF_copy_u8(&packet[89], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+4])[3]);
  TF_copy_u8(&packet[90], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+4])[4]);
  TF_copy_u8(&packet[91], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+4])[5]);
  TF_copy_u16(&packet[92], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+5]));
  TF_copy_u32(&packet[94], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+5]));
  TF_copy_u8(&packet[98], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+5])[0]);
  TF_copy_u8(&packet[99], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+5])[1]);
  TF_copy_u8(&packet[100], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+5])[2]);
  TF_copy_u8(&packet[101], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+5])[3]);
  TF_copy_u8(&packet[102], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+5])[4]);
  TF_copy_u8(&packet[103], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+5])[5]);
  TF_copy_u16(&packet[104], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+6]));
  TF_copy_u32(&packet[106], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+6]));
  TF_copy_u8(&packet[110], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+6])[0]);
  TF_copy_u8(&packet[111], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+6])[1]);
  TF_copy_u8(&packet[112], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+6])[2]);
  TF_copy_u8(&packet[113], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+6])[3]);
  TF_copy_u8(&packet[114], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+6])[4]);
  TF_copy_u8(&packet[115], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+6])[5]);
  TF_copy_u16(&packet[116], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+7]));
  TF_copy_u32(&packet[118], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+7]));
  TF_copy_u8(&packet[122], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+7])[0]);
  TF_copy_u8(&packet[123], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+7])[1]);
  TF_copy_u8(&packet[124], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+7])[2]);
  TF_copy_u8(&packet[125], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+7])[3]);
  TF_copy_u8(&packet[126], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+7])[4]);
  TF_copy_u8(&packet[127], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+7])[5]);
  TF_copy_u16(&packet[128], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+8]));
  TF_copy_u32(&packet[130], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+8]));
  TF_copy_u8(&packet[134], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+8])[0]);
  TF_copy_u8(&packet[135], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+8])[1]);
  TF_copy_u8(&packet[136], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+8])[2]);
  TF_copy_u8(&packet[137], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+8])[3]);
  TF_copy_u8(&packet[138], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+8])[4]);
  TF_copy_u8(&packet[139], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+8])[5]);
  TF_copy_u16(&packet[140], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+9]));
  TF_copy_u32(&packet[142], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+9]));
  TF_copy_u8(&packet[146], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+9])[0]);
  TF_copy_u8(&packet[147], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+9])[1]);
  TF_copy_u8(&packet[148], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+9])[2]);
  TF_copy_u8(&packet[149], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+9])[3]);
  TF_copy_u8(&packet[150], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+9])[4]);
  TF_copy_u8(&packet[151], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+9])[5]);
  TF_copy_u16(&packet[152], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+10]));
  TF_copy_u32(&packet[154], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+10]));
  TF_copy_u8(&packet[158], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+10])[0]);
  TF_copy_u8(&packet[159], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+10])[1]);
  TF_copy_u8(&packet[160], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+10])[2]);
  TF_copy_u8(&packet[161], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+10])[3]);
  TF_copy_u8(&packet[162], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+10])[4]);
  TF_copy_u8(&packet[163], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+10])[5]);
  TF_copy_u16(&packet[164], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+11]));
  TF_copy_u32(&packet[166], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+11]));
  TF_copy_u8(&packet[170], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+11])[0]);
  TF_copy_u8(&packet[171], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+11])[1]);
  TF_copy_u8(&packet[172], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+11])[2]);
  TF_copy_u8(&packet[173], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+11])[3]);
  TF_copy_u8(&packet[174], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+11])[4]);
  TF_copy_u8(&packet[175], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+11])[5]);
  TF_copy_u16(&packet[176], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+12]));
  TF_copy_u32(&packet[178], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+12]));
  TF_copy_u8(&packet[182], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+12])[0]);
  TF_copy_u8(&packet[183], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+12])[1]);
  TF_copy_u8(&packet[184], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+12])[2]);
  TF_copy_u8(&packet[185], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+12])[3]);
  TF_copy_u8(&packet[186], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+12])[4]);
  TF_copy_u8(&packet[187], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+12])[5]);
  TF_copy_u16(&packet[188], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+13]));
  TF_copy_u32(&packet[190], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+13]));
  TF_copy_u8(&packet[194], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+13])[0]);
  TF_copy_u8(&packet[195], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+13])[1]);
  TF_copy_u8(&packet[196], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+13])[2]);
  TF_copy_u8(&packet[197], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+13])[3]);
  TF_copy_u8(&packet[198], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+13])[4]);
  TF_copy_u8(&packet[199], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+13])[5]);
  TF_copy_u16(&packet[200], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+14]));
  TF_copy_u32(&packet[202], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+14]));
  TF_copy_u8(&packet[206], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+14])[0]);
  TF_copy_u8(&packet[207], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+14])[1]);
  TF_copy_u8(&packet[208], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+14])[2]);
  TF_copy_u8(&packet[209], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+14])[3]);
  TF_copy_u8(&packet[210], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+14])[4]);
  TF_copy_u8(&packet[211], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+14])[5]);
  TF_copy_u16(&packet[212], (uint16_t)CCP_get_id(timeline_command_dispatcher->tlm_info_.tl_list[offset+15]));
  TF_copy_u32(&packet[214], CCP_get_ti(timeline_command_dispatcher->tlm_info_.tl_list[offset+15]));
  TF_copy_u8(&packet[218], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+15])[0]);
  TF_copy_u8(&packet[219], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+15])[1]);
  TF_copy_u8(&packet[220], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+15])[2]);
  TF_copy_u8(&packet[221], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+15])[3]);
  TF_copy_u8(&packet[222], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+15])[4]);
  TF_copy_u8(&packet[223], CCP_get_param_head(timeline_command_dispatcher->tlm_info_.tl_list[offset+15])[5]);
#endif

  *len = 224;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_BL_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (234 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u16(&packet[26], block_command_table->pos.block);
  TF_copy_u8(&packet[28], block_command_table->pos.cmd);
  TF_copy_u8(&packet[29], BCT_get_bc_length(block_command_table->pos.block));
  TF_copy_u8(&packet[30], BCE_get_bc_exe_params(block_command_table->pos.block)->rotate.next_cmd);
  TF_copy_u16(&packet[31], BCE_get_bc_exe_params(block_command_table->pos.block)->rotate.counter);
  TF_copy_u16(&packet[33], BCE_get_bc_exe_params(block_command_table->pos.block)->rotate.interval);
  TF_copy_u16(&packet[35], BCE_get_bc_exe_params(block_command_table->pos.block)->timelimit_combine.call_num);
  TF_copy_u16(&packet[37], BCE_get_bc_exe_params(block_command_table->pos.block)->timelimit_combine.timeover_num);
  TF_copy_u8(&packet[39], BCE_get_bc_exe_params(block_command_table->pos.block)->timelimit_combine.last_timeover_cmd_pos);
  TF_copy_u8(&packet[40], BCE_get_bc_exe_params(block_command_table->pos.block)->timelimit_combine.worst_cmd_pos);
  TF_copy_u8(&packet[41], BCE_get_bc_exe_params(block_command_table->pos.block)->is_active);
  TF_copy_u16(&packet[42], (uint16_t)BCT_get_id(block_command_table->pos.block, 0));
  TF_copy_u32(&packet[44], (uint32_t)BCT_get_ti(block_command_table->pos.block, 0));
  TF_copy_u8(&packet[48], BCT_get_param_head(block_command_table->pos.block, 0)[0]);
  TF_copy_u8(&packet[49], BCT_get_param_head(block_command_table->pos.block, 0)[1]);
  TF_copy_u8(&packet[50], BCT_get_param_head(block_command_table->pos.block, 0)[2]);
  TF_copy_u8(&packet[51], BCT_get_param_head(block_command_table->pos.block, 0)[3]);
  TF_copy_u8(&packet[52], BCT_get_param_head(block_command_table->pos.block, 0)[4]);
  TF_copy_u8(&packet[53], BCT_get_param_head(block_command_table->pos.block, 0)[5]);
  TF_copy_u16(&packet[54], (uint16_t)BCT_get_id(block_command_table->pos.block, 1));
  TF_copy_u32(&packet[56], (uint32_t)BCT_get_ti(block_command_table->pos.block, 1));
  TF_copy_u8(&packet[60], BCT_get_param_head(block_command_table->pos.block, 1)[0]);
  TF_copy_u8(&packet[61], BCT_get_param_head(block_command_table->pos.block, 1)[1]);
  TF_copy_u8(&packet[62], BCT_get_param_head(block_command_table->pos.block, 1)[2]);
  TF_copy_u8(&packet[63], BCT_get_param_head(block_command_table->pos.block, 1)[3]);
  TF_copy_u8(&packet[64], BCT_get_param_head(block_command_table->pos.block, 1)[4]);
  TF_copy_u8(&packet[65], BCT_get_param_head(block_command_table->pos.block, 1)[5]);
  TF_copy_u16(&packet[66], (uint16_t)BCT_get_id(block_command_table->pos.block, 2));
  TF_copy_u32(&packet[68], (uint32_t)BCT_get_ti(block_command_table->pos.block, 2));
  TF_copy_u8(&packet[72], BCT_get_param_head(block_command_table->pos.block, 2)[0]);
  TF_copy_u8(&packet[73], BCT_get_param_head(block_command_table->pos.block, 2)[1]);
  TF_copy_u8(&packet[74], BCT_get_param_head(block_command_table->pos.block, 2)[2]);
  TF_copy_u8(&packet[75], BCT_get_param_head(block_command_table->pos.block, 2)[3]);
  TF_copy_u8(&packet[76], BCT_get_param_head(block_command_table->pos.block, 2)[4]);
  TF_copy_u8(&packet[77], BCT_get_param_head(block_command_table->pos.block, 2)[5]);
  TF_copy_u16(&packet[78], (uint16_t)BCT_get_id(block_command_table->pos.block, 3));
  TF_copy_u32(&packet[80], (uint32_t)BCT_get_ti(block_command_table->pos.block, 3));
  TF_copy_u8(&packet[84], BCT_get_param_head(block_command_table->pos.block, 3)[0]);
  TF_copy_u8(&packet[85], BCT_get_param_head(block_command_table->pos.block, 3)[1]);
  TF_copy_u8(&packet[86], BCT_get_param_head(block_command_table->pos.block, 3)[2]);
  TF_copy_u8(&packet[87], BCT_get_param_head(block_command_table->pos.block, 3)[3]);
  TF_copy_u8(&packet[88], BCT_get_param_head(block_command_table->pos.block, 3)[4]);
  TF_copy_u8(&packet[89], BCT_get_param_head(block_command_table->pos.block, 3)[5]);
  TF_copy_u16(&packet[90], (uint16_t)BCT_get_id(block_command_table->pos.block, 4));
  TF_copy_u32(&packet[92], (uint32_t)BCT_get_ti(block_command_table->pos.block, 4));
  TF_copy_u8(&packet[96], BCT_get_param_head(block_command_table->pos.block, 4)[0]);
  TF_copy_u8(&packet[97], BCT_get_param_head(block_command_table->pos.block, 4)[1]);
  TF_copy_u8(&packet[98], BCT_get_param_head(block_command_table->pos.block, 4)[2]);
  TF_copy_u8(&packet[99], BCT_get_param_head(block_command_table->pos.block, 4)[3]);
  TF_copy_u8(&packet[100], BCT_get_param_head(block_command_table->pos.block, 4)[4]);
  TF_copy_u8(&packet[101], BCT_get_param_head(block_command_table->pos.block, 4)[5]);
  TF_copy_u16(&packet[102], (uint16_t)BCT_get_id(block_command_table->pos.block, 5));
  TF_copy_u32(&packet[104], (uint32_t)BCT_get_ti(block_command_table->pos.block, 5));
  TF_copy_u8(&packet[108], BCT_get_param_head(block_command_table->pos.block, 5)[0]);
  TF_copy_u8(&packet[109], BCT_get_param_head(block_command_table->pos.block, 5)[1]);
  TF_copy_u8(&packet[110], BCT_get_param_head(block_command_table->pos.block, 5)[2]);
  TF_copy_u8(&packet[111], BCT_get_param_head(block_command_table->pos.block, 5)[3]);
  TF_copy_u8(&packet[112], BCT_get_param_head(block_command_table->pos.block, 5)[4]);
  TF_copy_u8(&packet[113], BCT_get_param_head(block_command_table->pos.block, 5)[5]);
  TF_copy_u16(&packet[114], (uint16_t)BCT_get_id(block_command_table->pos.block, 6));
  TF_copy_u32(&packet[116], (uint32_t)BCT_get_ti(block_command_table->pos.block, 6));
  TF_copy_u8(&packet[120], BCT_get_param_head(block_command_table->pos.block, 6)[0]);
  TF_copy_u8(&packet[121], BCT_get_param_head(block_command_table->pos.block, 6)[1]);
  TF_copy_u8(&packet[122], BCT_get_param_head(block_command_table->pos.block, 6)[2]);
  TF_copy_u8(&packet[123], BCT_get_param_head(block_command_table->pos.block, 6)[3]);
  TF_copy_u8(&packet[124], BCT_get_param_head(block_command_table->pos.block, 6)[4]);
  TF_copy_u8(&packet[125], BCT_get_param_head(block_command_table->pos.block, 6)[5]);
  TF_copy_u16(&packet[126], (uint16_t)BCT_get_id(block_command_table->pos.block, 7));
  TF_copy_u32(&packet[128], (uint32_t)BCT_get_ti(block_command_table->pos.block, 7));
  TF_copy_u8(&packet[132], BCT_get_param_head(block_command_table->pos.block, 7)[0]);
  TF_copy_u8(&packet[133], BCT_get_param_head(block_command_table->pos.block, 7)[1]);
  TF_copy_u8(&packet[134], BCT_get_param_head(block_command_table->pos.block, 7)[2]);
  TF_copy_u8(&packet[135], BCT_get_param_head(block_command_table->pos.block, 7)[3]);
  TF_copy_u8(&packet[136], BCT_get_param_head(block_command_table->pos.block, 7)[4]);
  TF_copy_u8(&packet[137], BCT_get_param_head(block_command_table->pos.block, 7)[5]);
  TF_copy_u16(&packet[138], (uint16_t)BCT_get_id(block_command_table->pos.block, 8));
  TF_copy_u32(&packet[140], (uint32_t)BCT_get_ti(block_command_table->pos.block, 8));
  TF_copy_u8(&packet[144], BCT_get_param_head(block_command_table->pos.block, 8)[0]);
  TF_copy_u8(&packet[145], BCT_get_param_head(block_command_table->pos.block, 8)[1]);
  TF_copy_u8(&packet[146], BCT_get_param_head(block_command_table->pos.block, 8)[2]);
  TF_copy_u8(&packet[147], BCT_get_param_head(block_command_table->pos.block, 8)[3]);
  TF_copy_u8(&packet[148], BCT_get_param_head(block_command_table->pos.block, 8)[4]);
  TF_copy_u8(&packet[149], BCT_get_param_head(block_command_table->pos.block, 8)[5]);
  TF_copy_u16(&packet[150], (uint16_t)BCT_get_id(block_command_table->pos.block, 9));
  TF_copy_u32(&packet[152], (uint32_t)BCT_get_ti(block_command_table->pos.block, 9));
  TF_copy_u8(&packet[156], BCT_get_param_head(block_command_table->pos.block, 9)[0]);
  TF_copy_u8(&packet[157], BCT_get_param_head(block_command_table->pos.block, 9)[1]);
  TF_copy_u8(&packet[158], BCT_get_param_head(block_command_table->pos.block, 9)[2]);
  TF_copy_u8(&packet[159], BCT_get_param_head(block_command_table->pos.block, 9)[3]);
  TF_copy_u8(&packet[160], BCT_get_param_head(block_command_table->pos.block, 9)[4]);
  TF_copy_u8(&packet[161], BCT_get_param_head(block_command_table->pos.block, 9)[5]);
  TF_copy_u16(&packet[162], (uint16_t)BCT_get_id(block_command_table->pos.block, 10));
  TF_copy_u32(&packet[164], (uint32_t)BCT_get_ti(block_command_table->pos.block, 10));
  TF_copy_u8(&packet[168], BCT_get_param_head(block_command_table->pos.block, 10)[0]);
  TF_copy_u8(&packet[169], BCT_get_param_head(block_command_table->pos.block, 10)[1]);
  TF_copy_u8(&packet[170], BCT_get_param_head(block_command_table->pos.block, 10)[2]);
  TF_copy_u8(&packet[171], BCT_get_param_head(block_command_table->pos.block, 10)[3]);
  TF_copy_u8(&packet[172], BCT_get_param_head(block_command_table->pos.block, 10)[4]);
  TF_copy_u8(&packet[173], BCT_get_param_head(block_command_table->pos.block, 10)[5]);
  TF_copy_u16(&packet[174], (uint16_t)BCT_get_id(block_command_table->pos.block, 11));
  TF_copy_u32(&packet[176], (uint32_t)BCT_get_ti(block_command_table->pos.block, 11));
  TF_copy_u8(&packet[180], BCT_get_param_head(block_command_table->pos.block, 11)[0]);
  TF_copy_u8(&packet[181], BCT_get_param_head(block_command_table->pos.block, 11)[1]);
  TF_copy_u8(&packet[182], BCT_get_param_head(block_command_table->pos.block, 11)[2]);
  TF_copy_u8(&packet[183], BCT_get_param_head(block_command_table->pos.block, 11)[3]);
  TF_copy_u8(&packet[184], BCT_get_param_head(block_command_table->pos.block, 11)[4]);
  TF_copy_u8(&packet[185], BCT_get_param_head(block_command_table->pos.block, 11)[5]);
  TF_copy_u16(&packet[186], (uint16_t)BCT_get_id(block_command_table->pos.block, 12));
  TF_copy_u32(&packet[188], (uint32_t)BCT_get_ti(block_command_table->pos.block, 12));
  TF_copy_u8(&packet[192], BCT_get_param_head(block_command_table->pos.block, 12)[0]);
  TF_copy_u8(&packet[193], BCT_get_param_head(block_command_table->pos.block, 12)[1]);
  TF_copy_u8(&packet[194], BCT_get_param_head(block_command_table->pos.block, 12)[2]);
  TF_copy_u8(&packet[195], BCT_get_param_head(block_command_table->pos.block, 12)[3]);
  TF_copy_u8(&packet[196], BCT_get_param_head(block_command_table->pos.block, 12)[4]);
  TF_copy_u8(&packet[197], BCT_get_param_head(block_command_table->pos.block, 12)[5]);
  TF_copy_u16(&packet[198], (uint16_t)BCT_get_id(block_command_table->pos.block, 13));
  TF_copy_u32(&packet[200], (uint32_t)BCT_get_ti(block_command_table->pos.block, 13));
  TF_copy_u8(&packet[204], BCT_get_param_head(block_command_table->pos.block, 13)[0]);
  TF_copy_u8(&packet[205], BCT_get_param_head(block_command_table->pos.block, 13)[1]);
  TF_copy_u8(&packet[206], BCT_get_param_head(block_command_table->pos.block, 13)[2]);
  TF_copy_u8(&packet[207], BCT_get_param_head(block_command_table->pos.block, 13)[3]);
  TF_copy_u8(&packet[208], BCT_get_param_head(block_command_table->pos.block, 13)[4]);
  TF_copy_u8(&packet[209], BCT_get_param_head(block_command_table->pos.block, 13)[5]);
  TF_copy_u16(&packet[210], (uint16_t)BCT_get_id(block_command_table->pos.block, 14));
  TF_copy_u32(&packet[212], (uint32_t)BCT_get_ti(block_command_table->pos.block, 14));
  TF_copy_u8(&packet[216], BCT_get_param_head(block_command_table->pos.block, 14)[0]);
  TF_copy_u8(&packet[217], BCT_get_param_head(block_command_table->pos.block, 14)[1]);
  TF_copy_u8(&packet[218], BCT_get_param_head(block_command_table->pos.block, 14)[2]);
  TF_copy_u8(&packet[219], BCT_get_param_head(block_command_table->pos.block, 14)[3]);
  TF_copy_u8(&packet[220], BCT_get_param_head(block_command_table->pos.block, 14)[4]);
  TF_copy_u8(&packet[221], BCT_get_param_head(block_command_table->pos.block, 14)[5]);
  TF_copy_u16(&packet[222], (uint16_t)BCT_get_id(block_command_table->pos.block, 15));
  TF_copy_u32(&packet[224], (uint32_t)BCT_get_ti(block_command_table->pos.block, 15));
  TF_copy_u8(&packet[228], BCT_get_param_head(block_command_table->pos.block, 15)[0]);
  TF_copy_u8(&packet[229], BCT_get_param_head(block_command_table->pos.block, 15)[1]);
  TF_copy_u8(&packet[230], BCT_get_param_head(block_command_table->pos.block, 15)[2]);
  TF_copy_u8(&packet[231], BCT_get_param_head(block_command_table->pos.block, 15)[3]);
  TF_copy_u8(&packet[232], BCT_get_param_head(block_command_table->pos.block, 15)[4]);
  TF_copy_u8(&packet[233], BCT_get_param_head(block_command_table->pos.block, 15)[5]);
#endif

  *len = 234;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_CA_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (139 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], (uint8_t)(command_analyze->tlm_page_no));
  TF_copy_u32(&packet[27], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+0].cmd_func));
  TF_copy_u8(&packet[31], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+0].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+0].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[32], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+0].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+0].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[33], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+0].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+0].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[34], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+1].cmd_func));
  TF_copy_u8(&packet[38], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+1].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+1].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[39], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+1].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+1].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[40], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+1].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+1].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[41], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+2].cmd_func));
  TF_copy_u8(&packet[45], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+2].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+2].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[46], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+2].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+2].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[47], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+2].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+2].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[48], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+3].cmd_func));
  TF_copy_u8(&packet[52], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+3].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+3].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[53], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+3].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+3].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[54], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+3].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+3].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[55], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+4].cmd_func));
  TF_copy_u8(&packet[59], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+4].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+4].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[60], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+4].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+4].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[61], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+4].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+4].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[62], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+5].cmd_func));
  TF_copy_u8(&packet[66], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+5].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+5].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[67], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+5].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+5].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[68], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+5].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+5].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[69], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+6].cmd_func));
  TF_copy_u8(&packet[73], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+6].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+6].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[74], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+6].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+6].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[75], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+6].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+6].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[76], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+7].cmd_func));
  TF_copy_u8(&packet[80], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+7].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+7].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[81], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+7].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+7].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[82], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+7].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+7].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[83], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+8].cmd_func));
  TF_copy_u8(&packet[87], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+8].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+8].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[88], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+8].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+8].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[89], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+8].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+8].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[90], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+9].cmd_func));
  TF_copy_u8(&packet[94], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+9].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+9].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[95], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+9].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+9].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[96], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+9].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+9].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[97], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+10].cmd_func));
  TF_copy_u8(&packet[101], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+10].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+10].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[102], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+10].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+10].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[103], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+10].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+10].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[104], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+11].cmd_func));
  TF_copy_u8(&packet[108], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+11].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+11].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[109], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+11].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+11].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[110], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+11].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+11].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[111], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+12].cmd_func));
  TF_copy_u8(&packet[115], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+12].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+12].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[116], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+12].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+12].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[117], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+12].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+12].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[118], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+13].cmd_func));
  TF_copy_u8(&packet[122], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+13].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+13].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[123], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+13].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+13].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[124], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+13].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+13].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[125], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+14].cmd_func));
  TF_copy_u8(&packet[129], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+14].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+14].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[130], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+14].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+14].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[131], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+14].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+14].param_size_infos[2].packed_info.bit.second & 0x0f)));
  TF_copy_u32(&packet[132], (uint32_t)(command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+15].cmd_func));
  TF_copy_u8(&packet[136], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+15].param_size_infos[0].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+15].param_size_infos[0].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[137], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+15].param_size_infos[1].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+15].param_size_infos[1].packed_info.bit.second & 0x0f)));
  TF_copy_u8(&packet[138], (uint8_t)(((command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+15].param_size_infos[2].packed_info.bit.first & 0x0f) << 4) | (command_analyze->cmd_table[CA_TLM_PAGE_SIZE*(command_analyze->tlm_page_no)+15].param_size_infos[2].packed_info.bit.second & 0x0f)));
#endif

  *len = 139;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_TF_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  uint8_t page = telemetry_frame->tlm_page_no;
  int offset = TF_TLM_PAGE_SIZE * (telemetry_frame->tlm_page_no);

  if (155 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], page);
  TF_copy_u32(&packet[27], (uint32_t)(telemetry_frame->tlm_table[offset+0].tlm_func));
  TF_copy_u32(&packet[31], (uint32_t)(telemetry_frame->tlm_table[offset+1].tlm_func));
  TF_copy_u32(&packet[35], (uint32_t)(telemetry_frame->tlm_table[offset+2].tlm_func));
  TF_copy_u32(&packet[39], (uint32_t)(telemetry_frame->tlm_table[offset+3].tlm_func));
  TF_copy_u32(&packet[43], (uint32_t)(telemetry_frame->tlm_table[offset+4].tlm_func));
  TF_copy_u32(&packet[47], (uint32_t)(telemetry_frame->tlm_table[offset+5].tlm_func));
  TF_copy_u32(&packet[51], (uint32_t)(telemetry_frame->tlm_table[offset+6].tlm_func));
  TF_copy_u32(&packet[55], (uint32_t)(telemetry_frame->tlm_table[offset+7].tlm_func));
  TF_copy_u32(&packet[59], (uint32_t)(telemetry_frame->tlm_table[offset+8].tlm_func));
  TF_copy_u32(&packet[63], (uint32_t)(telemetry_frame->tlm_table[offset+9].tlm_func));
  TF_copy_u32(&packet[67], (uint32_t)(telemetry_frame->tlm_table[offset+10].tlm_func));
  TF_copy_u32(&packet[71], (uint32_t)(telemetry_frame->tlm_table[offset+11].tlm_func));
  TF_copy_u32(&packet[75], (uint32_t)(telemetry_frame->tlm_table[offset+12].tlm_func));
  TF_copy_u32(&packet[79], (uint32_t)(telemetry_frame->tlm_table[offset+13].tlm_func));
  TF_copy_u32(&packet[83], (uint32_t)(telemetry_frame->tlm_table[offset+14].tlm_func));
  TF_copy_u32(&packet[87], (uint32_t)(telemetry_frame->tlm_table[offset+15].tlm_func));
  TF_copy_u32(&packet[91], (uint32_t)(telemetry_frame->tlm_table[offset+16].tlm_func));
  TF_copy_u32(&packet[95], (uint32_t)(telemetry_frame->tlm_table[offset+17].tlm_func));
  TF_copy_u32(&packet[99], (uint32_t)(telemetry_frame->tlm_table[offset+18].tlm_func));
  TF_copy_u32(&packet[103], (uint32_t)(telemetry_frame->tlm_table[offset+19].tlm_func));
  TF_copy_u32(&packet[107], (uint32_t)(telemetry_frame->tlm_table[offset+20].tlm_func));
  TF_copy_u32(&packet[111], (uint32_t)(telemetry_frame->tlm_table[offset+21].tlm_func));
  TF_copy_u32(&packet[115], (uint32_t)(telemetry_frame->tlm_table[offset+22].tlm_func));
  TF_copy_u32(&packet[119], (uint32_t)(telemetry_frame->tlm_table[offset+23].tlm_func));
  TF_copy_u32(&packet[123], (uint32_t)(telemetry_frame->tlm_table[offset+24].tlm_func));
  TF_copy_u32(&packet[127], (uint32_t)(telemetry_frame->tlm_table[offset+25].tlm_func));
  TF_copy_u32(&packet[131], (uint32_t)(telemetry_frame->tlm_table[offset+26].tlm_func));
  TF_copy_u32(&packet[135], (uint32_t)(telemetry_frame->tlm_table[offset+27].tlm_func));
  TF_copy_u32(&packet[139], (uint32_t)(telemetry_frame->tlm_table[offset+28].tlm_func));
  TF_copy_u32(&packet[143], (uint32_t)(telemetry_frame->tlm_table[offset+29].tlm_func));
  TF_copy_u32(&packet[147], (uint32_t)(telemetry_frame->tlm_table[offset+30].tlm_func));
  TF_copy_u32(&packet[151], (uint32_t)(telemetry_frame->tlm_table[offset+31].tlm_func));
#endif

  *len = 155;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_DCU_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_MM_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (101 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], (uint8_t)(mode_manager->current_id));
  TF_copy_u8(&packet[27], (uint8_t)(mode_manager->previous_id));
  TF_copy_u8(&packet[28], (uint8_t)(mode_manager->stat));
  TF_copy_u8(&packet[29], (uint8_t)(mode_manager->mode_list[0]));
  TF_copy_u8(&packet[30], (uint8_t)(mode_manager->mode_list[1]));
  TF_copy_u8(&packet[31], (uint8_t)(mode_manager->mode_list[2]));
  TF_copy_u8(&packet[32], (uint8_t)(mode_manager->mode_list[3]));
  TF_copy_u8(&packet[33], (uint8_t)(mode_manager->mode_list[4]));
  TF_copy_u8(&packet[34], (uint8_t)(mode_manager->mode_list[5]));
  TF_copy_u8(&packet[35], (uint8_t)(mode_manager->mode_list[6]));
  TF_copy_u8(&packet[36], (uint8_t)(mode_manager->mode_list[7]));
  TF_copy_u8(&packet[37], (uint8_t)(mode_manager->transition_table[0][0]));
  TF_copy_u8(&packet[38], (uint8_t)(mode_manager->transition_table[0][1]));
  TF_copy_u8(&packet[39], (uint8_t)(mode_manager->transition_table[0][2]));
  TF_copy_u8(&packet[40], (uint8_t)(mode_manager->transition_table[0][3]));
  TF_copy_u8(&packet[41], (uint8_t)(mode_manager->transition_table[0][4]));
  TF_copy_u8(&packet[42], (uint8_t)(mode_manager->transition_table[0][5]));
  TF_copy_u8(&packet[43], (uint8_t)(mode_manager->transition_table[0][6]));
  TF_copy_u8(&packet[44], (uint8_t)(mode_manager->transition_table[0][7]));
  TF_copy_u8(&packet[45], (uint8_t)(mode_manager->transition_table[1][0]));
  TF_copy_u8(&packet[46], (uint8_t)(mode_manager->transition_table[1][1]));
  TF_copy_u8(&packet[47], (uint8_t)(mode_manager->transition_table[1][2]));
  TF_copy_u8(&packet[48], (uint8_t)(mode_manager->transition_table[1][3]));
  TF_copy_u8(&packet[49], (uint8_t)(mode_manager->transition_table[1][4]));
  TF_copy_u8(&packet[50], (uint8_t)(mode_manager->transition_table[1][5]));
  TF_copy_u8(&packet[51], (uint8_t)(mode_manager->transition_table[1][6]));
  TF_copy_u8(&packet[52], (uint8_t)(mode_manager->transition_table[1][7]));
  TF_copy_u8(&packet[53], (uint8_t)(mode_manager->transition_table[2][0]));
  TF_copy_u8(&packet[54], (uint8_t)(mode_manager->transition_table[2][1]));
  TF_copy_u8(&packet[55], (uint8_t)(mode_manager->transition_table[2][2]));
  TF_copy_u8(&packet[56], (uint8_t)(mode_manager->transition_table[2][3]));
  TF_copy_u8(&packet[57], (uint8_t)(mode_manager->transition_table[2][4]));
  TF_copy_u8(&packet[58], (uint8_t)(mode_manager->transition_table[2][5]));
  TF_copy_u8(&packet[59], (uint8_t)(mode_manager->transition_table[2][6]));
  TF_copy_u8(&packet[60], (uint8_t)(mode_manager->transition_table[2][7]));
  TF_copy_u8(&packet[61], (uint8_t)(mode_manager->transition_table[3][0]));
  TF_copy_u8(&packet[62], (uint8_t)(mode_manager->transition_table[3][1]));
  TF_copy_u8(&packet[63], (uint8_t)(mode_manager->transition_table[3][2]));
  TF_copy_u8(&packet[64], (uint8_t)(mode_manager->transition_table[3][3]));
  TF_copy_u8(&packet[65], (uint8_t)(mode_manager->transition_table[3][4]));
  TF_copy_u8(&packet[66], (uint8_t)(mode_manager->transition_table[3][5]));
  TF_copy_u8(&packet[67], (uint8_t)(mode_manager->transition_table[3][6]));
  TF_copy_u8(&packet[68], (uint8_t)(mode_manager->transition_table[3][7]));
  TF_copy_u8(&packet[69], (uint8_t)(mode_manager->transition_table[4][0]));
  TF_copy_u8(&packet[70], (uint8_t)(mode_manager->transition_table[4][1]));
  TF_copy_u8(&packet[71], (uint8_t)(mode_manager->transition_table[4][2]));
  TF_copy_u8(&packet[72], (uint8_t)(mode_manager->transition_table[4][3]));
  TF_copy_u8(&packet[73], (uint8_t)(mode_manager->transition_table[4][4]));
  TF_copy_u8(&packet[74], (uint8_t)(mode_manager->transition_table[4][5]));
  TF_copy_u8(&packet[75], (uint8_t)(mode_manager->transition_table[4][6]));
  TF_copy_u8(&packet[76], (uint8_t)(mode_manager->transition_table[4][7]));
  TF_copy_u8(&packet[77], (uint8_t)(mode_manager->transition_table[5][0]));
  TF_copy_u8(&packet[78], (uint8_t)(mode_manager->transition_table[5][1]));
  TF_copy_u8(&packet[79], (uint8_t)(mode_manager->transition_table[5][2]));
  TF_copy_u8(&packet[80], (uint8_t)(mode_manager->transition_table[5][3]));
  TF_copy_u8(&packet[81], (uint8_t)(mode_manager->transition_table[5][4]));
  TF_copy_u8(&packet[82], (uint8_t)(mode_manager->transition_table[5][5]));
  TF_copy_u8(&packet[83], (uint8_t)(mode_manager->transition_table[5][6]));
  TF_copy_u8(&packet[84], (uint8_t)(mode_manager->transition_table[5][7]));
  TF_copy_u8(&packet[85], (uint8_t)(mode_manager->transition_table[6][0]));
  TF_copy_u8(&packet[86], (uint8_t)(mode_manager->transition_table[6][1]));
  TF_copy_u8(&packet[87], (uint8_t)(mode_manager->transition_table[6][2]));
  TF_copy_u8(&packet[88], (uint8_t)(mode_manager->transition_table[6][3]));
  TF_copy_u8(&packet[89], (uint8_t)(mode_manager->transition_table[6][4]));
  TF_copy_u8(&packet[90], (uint8_t)(mode_manager->transition_table[6][5]));
  TF_copy_u8(&packet[91], (uint8_t)(mode_manager->transition_table[6][6]));
  TF_copy_u8(&packet[92], (uint8_t)(mode_manager->transition_table[6][7]));
  TF_copy_u8(&packet[93], (uint8_t)(mode_manager->transition_table[7][0]));
  TF_copy_u8(&packet[94], (uint8_t)(mode_manager->transition_table[7][1]));
  TF_copy_u8(&packet[95], (uint8_t)(mode_manager->transition_table[7][2]));
  TF_copy_u8(&packet[96], (uint8_t)(mode_manager->transition_table[7][3]));
  TF_copy_u8(&packet[97], (uint8_t)(mode_manager->transition_table[7][4]));
  TF_copy_u8(&packet[98], (uint8_t)(mode_manager->transition_table[7][5]));
  TF_copy_u8(&packet[99], (uint8_t)(mode_manager->transition_table[7][6]));
  TF_copy_u8(&packet[100], (uint8_t)(mode_manager->transition_table[7][7]));
#endif

  *len = 101;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_AM_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (219 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], (uint8_t)(app_manager->page_no));
  TF_copy_u32(&packet[27], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+0].initializer));
  TF_copy_u32(&packet[31], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+0].entry_point));
  TF_copy_u8(&packet[35], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+0].init_duration));
  TF_copy_u8(&packet[36], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+0].prev));
  TF_copy_u8(&packet[37], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+0].min));
  TF_copy_u8(&packet[38], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+0].max));
  TF_copy_u32(&packet[39], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+1].initializer));
  TF_copy_u32(&packet[43], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+1].entry_point));
  TF_copy_u8(&packet[47], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+1].init_duration));
  TF_copy_u8(&packet[48], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+1].prev));
  TF_copy_u8(&packet[49], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+1].min));
  TF_copy_u8(&packet[50], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+1].max));
  TF_copy_u32(&packet[51], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+2].initializer));
  TF_copy_u32(&packet[55], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+2].entry_point));
  TF_copy_u8(&packet[59], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+2].init_duration));
  TF_copy_u8(&packet[60], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+2].prev));
  TF_copy_u8(&packet[61], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+2].min));
  TF_copy_u8(&packet[62], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+2].max));
  TF_copy_u32(&packet[63], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+3].initializer));
  TF_copy_u32(&packet[67], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+3].entry_point));
  TF_copy_u8(&packet[71], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+3].init_duration));
  TF_copy_u8(&packet[72], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+3].prev));
  TF_copy_u8(&packet[73], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+3].min));
  TF_copy_u8(&packet[74], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+3].max));
  TF_copy_u32(&packet[75], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+4].initializer));
  TF_copy_u32(&packet[79], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+4].entry_point));
  TF_copy_u8(&packet[83], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+4].init_duration));
  TF_copy_u8(&packet[84], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+4].prev));
  TF_copy_u8(&packet[85], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+4].min));
  TF_copy_u8(&packet[86], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+4].max));
  TF_copy_u32(&packet[87], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+5].initializer));
  TF_copy_u32(&packet[91], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+5].entry_point));
  TF_copy_u8(&packet[95], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+5].init_duration));
  TF_copy_u8(&packet[96], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+5].prev));
  TF_copy_u8(&packet[97], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+5].min));
  TF_copy_u8(&packet[98], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+5].max));
  TF_copy_u32(&packet[99], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+6].initializer));
  TF_copy_u32(&packet[103], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+6].entry_point));
  TF_copy_u8(&packet[107], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+6].init_duration));
  TF_copy_u8(&packet[108], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+6].prev));
  TF_copy_u8(&packet[109], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+6].min));
  TF_copy_u8(&packet[110], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+6].max));
  TF_copy_u32(&packet[111], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+7].initializer));
  TF_copy_u32(&packet[115], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+7].entry_point));
  TF_copy_u8(&packet[119], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+7].init_duration));
  TF_copy_u8(&packet[120], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+7].prev));
  TF_copy_u8(&packet[121], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+7].min));
  TF_copy_u8(&packet[122], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+7].max));
  TF_copy_u32(&packet[123], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+8].initializer));
  TF_copy_u32(&packet[127], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+8].entry_point));
  TF_copy_u8(&packet[131], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+8].init_duration));
  TF_copy_u8(&packet[132], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+8].prev));
  TF_copy_u8(&packet[133], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+8].min));
  TF_copy_u8(&packet[134], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+8].max));
  TF_copy_u32(&packet[135], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+9].initializer));
  TF_copy_u32(&packet[139], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+9].entry_point));
  TF_copy_u8(&packet[143], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+9].init_duration));
  TF_copy_u8(&packet[144], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+9].prev));
  TF_copy_u8(&packet[145], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+9].min));
  TF_copy_u8(&packet[146], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+9].max));
  TF_copy_u32(&packet[147], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+10].initializer));
  TF_copy_u32(&packet[151], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+10].entry_point));
  TF_copy_u8(&packet[155], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+10].init_duration));
  TF_copy_u8(&packet[156], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+10].prev));
  TF_copy_u8(&packet[157], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+10].min));
  TF_copy_u8(&packet[158], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+10].max));
  TF_copy_u32(&packet[159], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+11].initializer));
  TF_copy_u32(&packet[163], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+11].entry_point));
  TF_copy_u8(&packet[167], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+11].init_duration));
  TF_copy_u8(&packet[168], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+11].prev));
  TF_copy_u8(&packet[169], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+11].min));
  TF_copy_u8(&packet[170], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+11].max));
  TF_copy_u32(&packet[171], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+12].initializer));
  TF_copy_u32(&packet[175], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+12].entry_point));
  TF_copy_u8(&packet[179], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+12].init_duration));
  TF_copy_u8(&packet[180], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+12].prev));
  TF_copy_u8(&packet[181], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+12].min));
  TF_copy_u8(&packet[182], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+12].max));
  TF_copy_u32(&packet[183], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+13].initializer));
  TF_copy_u32(&packet[187], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+13].entry_point));
  TF_copy_u8(&packet[191], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+13].init_duration));
  TF_copy_u8(&packet[192], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+13].prev));
  TF_copy_u8(&packet[193], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+13].min));
  TF_copy_u8(&packet[194], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+13].max));
  TF_copy_u32(&packet[195], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+14].initializer));
  TF_copy_u32(&packet[199], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+14].entry_point));
  TF_copy_u8(&packet[203], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+14].init_duration));
  TF_copy_u8(&packet[204], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+14].prev));
  TF_copy_u8(&packet[205], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+14].min));
  TF_copy_u8(&packet[206], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+14].max));
  TF_copy_u32(&packet[207], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+15].initializer));
  TF_copy_u32(&packet[211], (uint32_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+15].entry_point));
  TF_copy_u8(&packet[215], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+15].init_duration));
  TF_copy_u8(&packet[216], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+15].prev));
  TF_copy_u8(&packet[217], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+15].min));
  TF_copy_u8(&packet[218], (uint8_t)(app_manager->ais[(AM_TLM_PAGE_SIZE*app_manager->page_no)+15].max));
#endif

  *len = 219;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_APP_TIME_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (226 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], (uint8_t)(app_manager->ais[0].init_duration));
  TF_copy_u8(&packet[27], (uint8_t)(app_manager->ais[0].prev));
  TF_copy_u8(&packet[28], (uint8_t)(app_manager->ais[0].min));
  TF_copy_u8(&packet[29], (uint8_t)(app_manager->ais[0].max));
  TF_copy_u8(&packet[30], (uint8_t)(app_manager->ais[1].init_duration));
  TF_copy_u8(&packet[31], (uint8_t)(app_manager->ais[1].prev));
  TF_copy_u8(&packet[32], (uint8_t)(app_manager->ais[1].min));
  TF_copy_u8(&packet[33], (uint8_t)(app_manager->ais[1].max));
  TF_copy_u8(&packet[34], (uint8_t)(app_manager->ais[2].init_duration));
  TF_copy_u8(&packet[35], (uint8_t)(app_manager->ais[2].prev));
  TF_copy_u8(&packet[36], (uint8_t)(app_manager->ais[2].min));
  TF_copy_u8(&packet[37], (uint8_t)(app_manager->ais[2].max));
  TF_copy_u8(&packet[38], (uint8_t)(app_manager->ais[3].init_duration));
  TF_copy_u8(&packet[39], (uint8_t)(app_manager->ais[3].prev));
  TF_copy_u8(&packet[40], (uint8_t)(app_manager->ais[3].min));
  TF_copy_u8(&packet[41], (uint8_t)(app_manager->ais[3].max));
  TF_copy_u8(&packet[42], (uint8_t)(app_manager->ais[4].init_duration));
  TF_copy_u8(&packet[43], (uint8_t)(app_manager->ais[4].prev));
  TF_copy_u8(&packet[44], (uint8_t)(app_manager->ais[4].min));
  TF_copy_u8(&packet[45], (uint8_t)(app_manager->ais[4].max));
  TF_copy_u8(&packet[46], (uint8_t)(app_manager->ais[5].init_duration));
  TF_copy_u8(&packet[47], (uint8_t)(app_manager->ais[5].prev));
  TF_copy_u8(&packet[48], (uint8_t)(app_manager->ais[5].min));
  TF_copy_u8(&packet[49], (uint8_t)(app_manager->ais[5].max));
  TF_copy_u8(&packet[50], (uint8_t)(app_manager->ais[6].init_duration));
  TF_copy_u8(&packet[51], (uint8_t)(app_manager->ais[6].prev));
  TF_copy_u8(&packet[52], (uint8_t)(app_manager->ais[6].min));
  TF_copy_u8(&packet[53], (uint8_t)(app_manager->ais[6].max));
  TF_copy_u8(&packet[54], (uint8_t)(app_manager->ais[7].init_duration));
  TF_copy_u8(&packet[55], (uint8_t)(app_manager->ais[7].prev));
  TF_copy_u8(&packet[56], (uint8_t)(app_manager->ais[7].min));
  TF_copy_u8(&packet[57], (uint8_t)(app_manager->ais[7].max));
  TF_copy_u8(&packet[58], (uint8_t)(app_manager->ais[8].init_duration));
  TF_copy_u8(&packet[59], (uint8_t)(app_manager->ais[8].prev));
  TF_copy_u8(&packet[60], (uint8_t)(app_manager->ais[8].min));
  TF_copy_u8(&packet[61], (uint8_t)(app_manager->ais[8].max));
  TF_copy_u8(&packet[62], (uint8_t)(app_manager->ais[9].init_duration));
  TF_copy_u8(&packet[63], (uint8_t)(app_manager->ais[9].prev));
  TF_copy_u8(&packet[64], (uint8_t)(app_manager->ais[9].min));
  TF_copy_u8(&packet[65], (uint8_t)(app_manager->ais[9].max));
  TF_copy_u8(&packet[66], (uint8_t)(app_manager->ais[10].init_duration));
  TF_copy_u8(&packet[67], (uint8_t)(app_manager->ais[10].prev));
  TF_copy_u8(&packet[68], (uint8_t)(app_manager->ais[10].min));
  TF_copy_u8(&packet[69], (uint8_t)(app_manager->ais[10].max));
  TF_copy_u8(&packet[70], (uint8_t)(app_manager->ais[11].init_duration));
  TF_copy_u8(&packet[71], (uint8_t)(app_manager->ais[11].prev));
  TF_copy_u8(&packet[72], (uint8_t)(app_manager->ais[11].min));
  TF_copy_u8(&packet[73], (uint8_t)(app_manager->ais[11].max));
  TF_copy_u8(&packet[74], (uint8_t)(app_manager->ais[12].init_duration));
  TF_copy_u8(&packet[75], (uint8_t)(app_manager->ais[12].prev));
  TF_copy_u8(&packet[76], (uint8_t)(app_manager->ais[12].min));
  TF_copy_u8(&packet[77], (uint8_t)(app_manager->ais[12].max));
  TF_copy_u8(&packet[78], (uint8_t)(app_manager->ais[13].init_duration));
  TF_copy_u8(&packet[79], (uint8_t)(app_manager->ais[13].prev));
  TF_copy_u8(&packet[80], (uint8_t)(app_manager->ais[13].min));
  TF_copy_u8(&packet[81], (uint8_t)(app_manager->ais[13].max));
  TF_copy_u8(&packet[82], (uint8_t)(app_manager->ais[14].init_duration));
  TF_copy_u8(&packet[83], (uint8_t)(app_manager->ais[14].prev));
  TF_copy_u8(&packet[84], (uint8_t)(app_manager->ais[14].min));
  TF_copy_u8(&packet[85], (uint8_t)(app_manager->ais[14].max));
  TF_copy_u8(&packet[86], (uint8_t)(app_manager->ais[15].init_duration));
  TF_copy_u8(&packet[87], (uint8_t)(app_manager->ais[15].prev));
  TF_copy_u8(&packet[88], (uint8_t)(app_manager->ais[15].min));
  TF_copy_u8(&packet[89], (uint8_t)(app_manager->ais[15].max));
  TF_copy_u8(&packet[90], (uint8_t)(app_manager->ais[16].init_duration));
  TF_copy_u8(&packet[91], (uint8_t)(app_manager->ais[16].prev));
  TF_copy_u8(&packet[92], (uint8_t)(app_manager->ais[16].min));
  TF_copy_u8(&packet[93], (uint8_t)(app_manager->ais[16].max));
  TF_copy_u8(&packet[94], (uint8_t)(app_manager->ais[17].init_duration));
  TF_copy_u8(&packet[95], (uint8_t)(app_manager->ais[17].prev));
  TF_copy_u8(&packet[96], (uint8_t)(app_manager->ais[17].min));
  TF_copy_u8(&packet[97], (uint8_t)(app_manager->ais[17].max));
  TF_copy_u8(&packet[98], (uint8_t)(app_manager->ais[18].init_duration));
  TF_copy_u8(&packet[99], (uint8_t)(app_manager->ais[18].prev));
  TF_copy_u8(&packet[100], (uint8_t)(app_manager->ais[18].min));
  TF_copy_u8(&packet[101], (uint8_t)(app_manager->ais[18].max));
  TF_copy_u8(&packet[102], (uint8_t)(app_manager->ais[19].init_duration));
  TF_copy_u8(&packet[103], (uint8_t)(app_manager->ais[19].prev));
  TF_copy_u8(&packet[104], (uint8_t)(app_manager->ais[19].min));
  TF_copy_u8(&packet[105], (uint8_t)(app_manager->ais[19].max));
  TF_copy_u8(&packet[106], (uint8_t)(app_manager->ais[20].init_duration));
  TF_copy_u8(&packet[107], (uint8_t)(app_manager->ais[20].prev));
  TF_copy_u8(&packet[108], (uint8_t)(app_manager->ais[20].min));
  TF_copy_u8(&packet[109], (uint8_t)(app_manager->ais[20].max));
  TF_copy_u8(&packet[110], (uint8_t)(app_manager->ais[21].init_duration));
  TF_copy_u8(&packet[111], (uint8_t)(app_manager->ais[21].prev));
  TF_copy_u8(&packet[112], (uint8_t)(app_manager->ais[21].min));
  TF_copy_u8(&packet[113], (uint8_t)(app_manager->ais[21].max));
  TF_copy_u8(&packet[114], (uint8_t)(app_manager->ais[22].init_duration));
  TF_copy_u8(&packet[115], (uint8_t)(app_manager->ais[22].prev));
  TF_copy_u8(&packet[116], (uint8_t)(app_manager->ais[22].min));
  TF_copy_u8(&packet[117], (uint8_t)(app_manager->ais[22].max));
  TF_copy_u8(&packet[118], (uint8_t)(app_manager->ais[23].init_duration));
  TF_copy_u8(&packet[119], (uint8_t)(app_manager->ais[23].prev));
  TF_copy_u8(&packet[120], (uint8_t)(app_manager->ais[23].min));
  TF_copy_u8(&packet[121], (uint8_t)(app_manager->ais[23].max));
  TF_copy_u8(&packet[122], (uint8_t)(app_manager->ais[24].init_duration));
  TF_copy_u8(&packet[123], (uint8_t)(app_manager->ais[24].prev));
  TF_copy_u8(&packet[124], (uint8_t)(app_manager->ais[24].min));
  TF_copy_u8(&packet[125], (uint8_t)(app_manager->ais[24].max));
  TF_copy_u8(&packet[126], (uint8_t)(app_manager->ais[25].init_duration));
  TF_copy_u8(&packet[127], (uint8_t)(app_manager->ais[25].prev));
  TF_copy_u8(&packet[128], (uint8_t)(app_manager->ais[25].min));
  TF_copy_u8(&packet[129], (uint8_t)(app_manager->ais[25].max));
  TF_copy_u8(&packet[130], (uint8_t)(app_manager->ais[26].init_duration));
  TF_copy_u8(&packet[131], (uint8_t)(app_manager->ais[26].prev));
  TF_copy_u8(&packet[132], (uint8_t)(app_manager->ais[26].min));
  TF_copy_u8(&packet[133], (uint8_t)(app_manager->ais[26].max));
  TF_copy_u8(&packet[134], (uint8_t)(app_manager->ais[27].init_duration));
  TF_copy_u8(&packet[135], (uint8_t)(app_manager->ais[27].prev));
  TF_copy_u8(&packet[136], (uint8_t)(app_manager->ais[27].min));
  TF_copy_u8(&packet[137], (uint8_t)(app_manager->ais[27].max));
  TF_copy_u8(&packet[138], (uint8_t)(app_manager->ais[28].init_duration));
  TF_copy_u8(&packet[139], (uint8_t)(app_manager->ais[28].prev));
  TF_copy_u8(&packet[140], (uint8_t)(app_manager->ais[28].min));
  TF_copy_u8(&packet[141], (uint8_t)(app_manager->ais[28].max));
  TF_copy_u8(&packet[142], (uint8_t)(app_manager->ais[29].init_duration));
  TF_copy_u8(&packet[143], (uint8_t)(app_manager->ais[29].prev));
  TF_copy_u8(&packet[144], (uint8_t)(app_manager->ais[29].min));
  TF_copy_u8(&packet[145], (uint8_t)(app_manager->ais[29].max));
  TF_copy_u8(&packet[146], (uint8_t)(app_manager->ais[30].init_duration));
  TF_copy_u8(&packet[147], (uint8_t)(app_manager->ais[30].prev));
  TF_copy_u8(&packet[148], (uint8_t)(app_manager->ais[30].min));
  TF_copy_u8(&packet[149], (uint8_t)(app_manager->ais[30].max));
  TF_copy_u8(&packet[150], (uint8_t)(app_manager->ais[31].init_duration));
  TF_copy_u8(&packet[151], (uint8_t)(app_manager->ais[31].prev));
  TF_copy_u8(&packet[152], (uint8_t)(app_manager->ais[31].min));
  TF_copy_u8(&packet[153], (uint8_t)(app_manager->ais[31].max));
  TF_copy_u8(&packet[154], (uint8_t)(app_manager->ais[32].init_duration));
  TF_copy_u8(&packet[155], (uint8_t)(app_manager->ais[32].prev));
  TF_copy_u8(&packet[156], (uint8_t)(app_manager->ais[32].min));
  TF_copy_u8(&packet[157], (uint8_t)(app_manager->ais[32].max));
  TF_copy_u8(&packet[158], (uint8_t)(app_manager->ais[33].init_duration));
  TF_copy_u8(&packet[159], (uint8_t)(app_manager->ais[33].prev));
  TF_copy_u8(&packet[160], (uint8_t)(app_manager->ais[33].min));
  TF_copy_u8(&packet[161], (uint8_t)(app_manager->ais[33].max));
  TF_copy_u8(&packet[162], (uint8_t)(app_manager->ais[34].init_duration));
  TF_copy_u8(&packet[163], (uint8_t)(app_manager->ais[34].prev));
  TF_copy_u8(&packet[164], (uint8_t)(app_manager->ais[34].min));
  TF_copy_u8(&packet[165], (uint8_t)(app_manager->ais[34].max));
  TF_copy_u8(&packet[166], (uint8_t)(app_manager->ais[35].init_duration));
  TF_copy_u8(&packet[167], (uint8_t)(app_manager->ais[35].prev));
  TF_copy_u8(&packet[168], (uint8_t)(app_manager->ais[35].min));
  TF_copy_u8(&packet[169], (uint8_t)(app_manager->ais[35].max));
  TF_copy_u8(&packet[170], (uint8_t)(app_manager->ais[36].init_duration));
  TF_copy_u8(&packet[171], (uint8_t)(app_manager->ais[36].prev));
  TF_copy_u8(&packet[172], (uint8_t)(app_manager->ais[36].min));
  TF_copy_u8(&packet[173], (uint8_t)(app_manager->ais[36].max));
  TF_copy_u8(&packet[174], (uint8_t)(app_manager->ais[37].init_duration));
  TF_copy_u8(&packet[175], (uint8_t)(app_manager->ais[37].prev));
  TF_copy_u8(&packet[176], (uint8_t)(app_manager->ais[37].min));
  TF_copy_u8(&packet[177], (uint8_t)(app_manager->ais[37].max));
  TF_copy_u8(&packet[178], (uint8_t)(app_manager->ais[38].init_duration));
  TF_copy_u8(&packet[179], (uint8_t)(app_manager->ais[38].prev));
  TF_copy_u8(&packet[180], (uint8_t)(app_manager->ais[38].min));
  TF_copy_u8(&packet[181], (uint8_t)(app_manager->ais[38].max));
  TF_copy_u8(&packet[182], (uint8_t)(app_manager->ais[39].init_duration));
  TF_copy_u8(&packet[183], (uint8_t)(app_manager->ais[39].prev));
  TF_copy_u8(&packet[184], (uint8_t)(app_manager->ais[39].min));
  TF_copy_u8(&packet[185], (uint8_t)(app_manager->ais[39].max));
  TF_copy_u8(&packet[186], (uint8_t)(app_manager->ais[40].init_duration));
  TF_copy_u8(&packet[187], (uint8_t)(app_manager->ais[40].prev));
  TF_copy_u8(&packet[188], (uint8_t)(app_manager->ais[40].min));
  TF_copy_u8(&packet[189], (uint8_t)(app_manager->ais[40].max));
  TF_copy_u8(&packet[190], (uint8_t)(app_manager->ais[41].init_duration));
  TF_copy_u8(&packet[191], (uint8_t)(app_manager->ais[41].prev));
  TF_copy_u8(&packet[192], (uint8_t)(app_manager->ais[41].min));
  TF_copy_u8(&packet[193], (uint8_t)(app_manager->ais[41].max));
  TF_copy_u8(&packet[194], (uint8_t)(app_manager->ais[42].init_duration));
  TF_copy_u8(&packet[195], (uint8_t)(app_manager->ais[42].prev));
  TF_copy_u8(&packet[196], (uint8_t)(app_manager->ais[42].min));
  TF_copy_u8(&packet[197], (uint8_t)(app_manager->ais[42].max));
  TF_copy_u8(&packet[198], (uint8_t)(app_manager->ais[43].init_duration));
  TF_copy_u8(&packet[199], (uint8_t)(app_manager->ais[43].prev));
  TF_copy_u8(&packet[200], (uint8_t)(app_manager->ais[43].min));
  TF_copy_u8(&packet[201], (uint8_t)(app_manager->ais[43].max));
  TF_copy_u8(&packet[202], (uint8_t)(app_manager->ais[44].init_duration));
  TF_copy_u8(&packet[203], (uint8_t)(app_manager->ais[44].prev));
  TF_copy_u8(&packet[204], (uint8_t)(app_manager->ais[44].min));
  TF_copy_u8(&packet[205], (uint8_t)(app_manager->ais[44].max));
  TF_copy_u8(&packet[206], (uint8_t)(app_manager->ais[45].init_duration));
  TF_copy_u8(&packet[207], (uint8_t)(app_manager->ais[45].prev));
  TF_copy_u8(&packet[208], (uint8_t)(app_manager->ais[45].min));
  TF_copy_u8(&packet[209], (uint8_t)(app_manager->ais[45].max));
  TF_copy_u8(&packet[210], (uint8_t)(app_manager->ais[46].init_duration));
  TF_copy_u8(&packet[211], (uint8_t)(app_manager->ais[46].prev));
  TF_copy_u8(&packet[212], (uint8_t)(app_manager->ais[46].min));
  TF_copy_u8(&packet[213], (uint8_t)(app_manager->ais[46].max));
  TF_copy_u8(&packet[214], (uint8_t)(app_manager->ais[47].init_duration));
  TF_copy_u8(&packet[215], (uint8_t)(app_manager->ais[47].prev));
  TF_copy_u8(&packet[216], (uint8_t)(app_manager->ais[47].min));
  TF_copy_u8(&packet[217], (uint8_t)(app_manager->ais[47].max));
  TF_copy_u8(&packet[218], (uint8_t)(app_manager->ais[48].init_duration));
  TF_copy_u8(&packet[219], (uint8_t)(app_manager->ais[48].prev));
  TF_copy_u8(&packet[220], (uint8_t)(app_manager->ais[48].min));
  TF_copy_u8(&packet[221], (uint8_t)(app_manager->ais[48].max));
  TF_copy_u8(&packet[222], (uint8_t)(app_manager->ais[49].init_duration));
  TF_copy_u8(&packet[223], (uint8_t)(app_manager->ais[49].prev));
  TF_copy_u8(&packet[224], (uint8_t)(app_manager->ais[49].min));
  TF_copy_u8(&packet[225], (uint8_t)(app_manager->ais[49].max));
#endif

  *len = 226;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_EL_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (214 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u32(&packet[26], event_logger->statistics.record_counter_total);
  TF_copy_u32(&packet[30], event_logger->statistics.record_counters[EL_ERROR_LEVEL_HIGH]);
  TF_copy_u32(&packet[34], event_logger->statistics.record_counters[EL_ERROR_LEVEL_MIDDLE]);
  TF_copy_u32(&packet[38], event_logger->statistics.record_counters[EL_ERROR_LEVEL_LOW]);
  TF_copy_u32(&packet[42], event_logger->statistics.record_counters[EL_ERROR_LEVEL_EL]);
  TF_copy_u32(&packet[46], event_logger->statistics.record_counters[EL_ERROR_LEVEL_EH]);
  TF_copy_u8(&packet[50], event_logger->tlm_info.tlog.page_no);
  TF_copy_u8(&packet[51], (uint8_t)event_logger->tlm_info.tlog.err_level);
  TF_copy_u8(&packet[52], event_logger->tlm_info.clog.page_no);
  TF_copy_u8(&packet[53], (uint8_t)event_logger->tlm_info.clog.err_level);
  TF_copy_u32(&packet[54], (uint32_t)event_logger->latest_event.group);
  TF_copy_u32(&packet[58], event_logger->latest_event.local);
  TF_copy_u8(&packet[62], (uint8_t)event_logger->latest_event.err_level);
  TF_copy_u32(&packet[63], event_logger->latest_event.time.total_cycle);
  TF_copy_u8(&packet[67], (uint8_t)event_logger->latest_event.time.step);
  TF_copy_u32(&packet[68], event_logger->latest_event.note);
  TF_copy_u8(&packet[72], event_logger->is_logging_enable[0]);
  TF_copy_u8(&packet[73], event_logger->is_logging_enable[1]);
  TF_copy_u8(&packet[74], event_logger->is_logging_enable[2]);
  TF_copy_u8(&packet[75], event_logger->is_logging_enable[3]);
  TF_copy_u8(&packet[76], event_logger->is_logging_enable[4]);
  TF_copy_u8(&packet[77], event_logger->is_logging_enable[5]);
  TF_copy_u8(&packet[78], event_logger->is_logging_enable[6]);
  TF_copy_u8(&packet[79], event_logger->is_logging_enable[7]);
  TF_copy_u8(&packet[80], event_logger->is_logging_enable[8]);
  TF_copy_u8(&packet[81], event_logger->is_logging_enable[9]);
  TF_copy_u8(&packet[82], event_logger->is_logging_enable[10]);
  TF_copy_u8(&packet[83], event_logger->is_logging_enable[11]);
  TF_copy_u8(&packet[84], event_logger->is_logging_enable[12]);
  TF_copy_u8(&packet[85], event_logger->is_logging_enable[13]);
  TF_copy_u8(&packet[86], event_logger->is_logging_enable[14]);
  TF_copy_u8(&packet[87], event_logger->is_logging_enable[15]);
  TF_copy_u8(&packet[88], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 0)->group);
  TF_copy_u32(&packet[89], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 0)->local);
  TF_copy_u32(&packet[93], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 0)->time.total_cycle);
  TF_copy_u8(&packet[97], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 0)->time.step);
  TF_copy_u32(&packet[98], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 0)->note);
  TF_copy_u8(&packet[102], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 1)->group);
  TF_copy_u32(&packet[103], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 1)->local);
  TF_copy_u32(&packet[107], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 1)->time.total_cycle);
  TF_copy_u8(&packet[111], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 1)->time.step);
  TF_copy_u32(&packet[112], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 1)->note);
  TF_copy_u8(&packet[116], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 2)->group);
  TF_copy_u32(&packet[117], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 2)->local);
  TF_copy_u32(&packet[121], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 2)->time.total_cycle);
  TF_copy_u8(&packet[125], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 2)->time.step);
  TF_copy_u32(&packet[126], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 2)->note);
  TF_copy_u8(&packet[130], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 0)->group);
  TF_copy_u32(&packet[131], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 0)->local);
  TF_copy_u32(&packet[135], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 0)->time.total_cycle);
  TF_copy_u8(&packet[139], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 0)->time.step);
  TF_copy_u32(&packet[140], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 0)->note);
  TF_copy_u8(&packet[144], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 1)->group);
  TF_copy_u32(&packet[145], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 1)->local);
  TF_copy_u32(&packet[149], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 1)->time.total_cycle);
  TF_copy_u8(&packet[153], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 1)->time.step);
  TF_copy_u32(&packet[154], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 1)->note);
  TF_copy_u8(&packet[158], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 2)->group);
  TF_copy_u32(&packet[159], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 2)->local);
  TF_copy_u32(&packet[163], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 2)->time.total_cycle);
  TF_copy_u8(&packet[167], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 2)->time.step);
  TF_copy_u32(&packet[168], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 2)->note);
  TF_copy_u8(&packet[172], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EL, 0)->group);
  TF_copy_u32(&packet[173], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EL, 0)->local);
  TF_copy_u32(&packet[177], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EL, 0)->time.total_cycle);
  TF_copy_u8(&packet[181], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EL, 0)->time.step);
  TF_copy_u32(&packet[182], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EL, 0)->note);
  TF_copy_u8(&packet[186], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EL, 1)->group);
  TF_copy_u32(&packet[187], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EL, 1)->local);
  TF_copy_u32(&packet[191], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EL, 1)->time.total_cycle);
  TF_copy_u8(&packet[195], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EL, 1)->time.step);
  TF_copy_u32(&packet[196], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EL, 1)->note);
  TF_copy_u8(&packet[200], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EH, 0)->group);
  TF_copy_u32(&packet[201], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EH, 0)->local);
  TF_copy_u32(&packet[205], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EH, 0)->time.total_cycle);
  TF_copy_u8(&packet[209], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EH, 0)->time.step);
  TF_copy_u32(&packet[210], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_EH, 0)->note);
#endif

  *len = 214;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_EL_TLOG_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  EL_ERROR_LEVEL err_level = event_logger->tlm_info.tlog.err_level;
  uint16_t offset = EL_TLOG_TLM_PAGE_SIZE * event_logger->tlm_info.tlog.page_no;
  const EL_Event* events = event_logger->tlogs[err_level].events;

  if (216 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], event_logger->tlm_info.tlog.page_no);
  TF_copy_u8(&packet[27], (uint8_t)((err_level << 4 & 0xf0) | (event_logger->tlogs[err_level].is_enable_overwrite << 3 & 0x08) | ( event_logger->tlogs[err_level].is_table_overflow << 2 & 0x04)));
  TF_copy_u32(&packet[28], event_logger->statistics.record_counter_total);
  TF_copy_u32(&packet[32], event_logger->statistics.record_counters[err_level]);
  TF_copy_u16(&packet[36], event_logger->tlogs[err_level].log_capacity);
  TF_copy_u16(&packet[38], event_logger->tlogs[err_level].log_wp);
  TF_copy_u8(&packet[40], (uint8_t)events[offset+0].group);
  TF_copy_u32(&packet[41], events[offset+0].local);
  TF_copy_u32(&packet[45], events[offset+0].time.total_cycle);
  TF_copy_u8(&packet[49], (uint8_t)events[offset+0].time.step);
  TF_copy_u8(&packet[50], (uint8_t)events[offset+0].note);
  TF_copy_u8(&packet[51], (uint8_t)events[offset+1].group);
  TF_copy_u32(&packet[52], events[offset+1].local);
  TF_copy_u32(&packet[56], events[offset+1].time.total_cycle);
  TF_copy_u8(&packet[60], (uint8_t)events[offset+1].time.step);
  TF_copy_u8(&packet[61], (uint8_t)events[offset+1].note);
  TF_copy_u8(&packet[62], (uint8_t)events[offset+2].group);
  TF_copy_u32(&packet[63], events[offset+2].local);
  TF_copy_u32(&packet[67], events[offset+2].time.total_cycle);
  TF_copy_u8(&packet[71], (uint8_t)events[offset+2].time.step);
  TF_copy_u8(&packet[72], (uint8_t)events[offset+2].note);
  TF_copy_u8(&packet[73], (uint8_t)events[offset+3].group);
  TF_copy_u32(&packet[74], events[offset+3].local);
  TF_copy_u32(&packet[78], events[offset+3].time.total_cycle);
  TF_copy_u8(&packet[82], (uint8_t)events[offset+3].time.step);
  TF_copy_u8(&packet[83], (uint8_t)events[offset+3].note);
  TF_copy_u8(&packet[84], (uint8_t)events[offset+4].group);
  TF_copy_u32(&packet[85], events[offset+4].local);
  TF_copy_u32(&packet[89], events[offset+4].time.total_cycle);
  TF_copy_u8(&packet[93], (uint8_t)events[offset+4].time.step);
  TF_copy_u8(&packet[94], (uint8_t)events[offset+4].note);
  TF_copy_u8(&packet[95], (uint8_t)events[offset+5].group);
  TF_copy_u32(&packet[96], events[offset+5].local);
  TF_copy_u32(&packet[100], events[offset+5].time.total_cycle);
  TF_copy_u8(&packet[104], (uint8_t)events[offset+5].time.step);
  TF_copy_u8(&packet[105], (uint8_t)events[offset+5].note);
  TF_copy_u8(&packet[106], (uint8_t)events[offset+6].group);
  TF_copy_u32(&packet[107], events[offset+6].local);
  TF_copy_u32(&packet[111], events[offset+6].time.total_cycle);
  TF_copy_u8(&packet[115], (uint8_t)events[offset+6].time.step);
  TF_copy_u8(&packet[116], (uint8_t)events[offset+6].note);
  TF_copy_u8(&packet[117], (uint8_t)events[offset+7].group);
  TF_copy_u32(&packet[118], events[offset+7].local);
  TF_copy_u32(&packet[122], events[offset+7].time.total_cycle);
  TF_copy_u8(&packet[126], (uint8_t)events[offset+7].time.step);
  TF_copy_u8(&packet[127], (uint8_t)events[offset+7].note);
  TF_copy_u8(&packet[128], (uint8_t)events[offset+8].group);
  TF_copy_u32(&packet[129], events[offset+8].local);
  TF_copy_u32(&packet[133], events[offset+8].time.total_cycle);
  TF_copy_u8(&packet[137], (uint8_t)events[offset+8].time.step);
  TF_copy_u8(&packet[138], (uint8_t)events[offset+8].note);
  TF_copy_u8(&packet[139], (uint8_t)events[offset+9].group);
  TF_copy_u32(&packet[140], events[offset+9].local);
  TF_copy_u32(&packet[144], events[offset+9].time.total_cycle);
  TF_copy_u8(&packet[148], (uint8_t)events[offset+9].time.step);
  TF_copy_u8(&packet[149], (uint8_t)events[offset+9].note);
  TF_copy_u8(&packet[150], (uint8_t)events[offset+10].group);
  TF_copy_u32(&packet[151], events[offset+10].local);
  TF_copy_u32(&packet[155], events[offset+10].time.total_cycle);
  TF_copy_u8(&packet[159], (uint8_t)events[offset+10].time.step);
  TF_copy_u8(&packet[160], (uint8_t)events[offset+10].note);
  TF_copy_u8(&packet[161], (uint8_t)events[offset+11].group);
  TF_copy_u32(&packet[162], events[offset+11].local);
  TF_copy_u32(&packet[166], events[offset+11].time.total_cycle);
  TF_copy_u8(&packet[170], (uint8_t)events[offset+11].time.step);
  TF_copy_u8(&packet[171], (uint8_t)events[offset+11].note);
  TF_copy_u8(&packet[172], (uint8_t)events[offset+12].group);
  TF_copy_u32(&packet[173], events[offset+12].local);
  TF_copy_u32(&packet[177], events[offset+12].time.total_cycle);
  TF_copy_u8(&packet[181], (uint8_t)events[offset+12].time.step);
  TF_copy_u8(&packet[182], (uint8_t)events[offset+12].note);
  TF_copy_u8(&packet[183], (uint8_t)events[offset+13].group);
  TF_copy_u32(&packet[184], events[offset+13].local);
  TF_copy_u32(&packet[188], events[offset+13].time.total_cycle);
  TF_copy_u8(&packet[192], (uint8_t)events[offset+13].time.step);
  TF_copy_u8(&packet[193], (uint8_t)events[offset+13].note);
  TF_copy_u8(&packet[194], (uint8_t)events[offset+14].group);
  TF_copy_u32(&packet[195], events[offset+14].local);
  TF_copy_u32(&packet[199], events[offset+14].time.total_cycle);
  TF_copy_u8(&packet[203], (uint8_t)events[offset+14].time.step);
  TF_copy_u8(&packet[204], (uint8_t)events[offset+14].note);
  TF_copy_u8(&packet[205], (uint8_t)events[offset+15].group);
  TF_copy_u32(&packet[206], events[offset+15].local);
  TF_copy_u32(&packet[210], events[offset+15].time.total_cycle);
  TF_copy_u8(&packet[214], (uint8_t)events[offset+15].time.step);
  TF_copy_u8(&packet[215], (uint8_t)events[offset+15].note);
#endif

  *len = 216;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_EL_CLOG_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  EL_ERROR_LEVEL err_level = event_logger->tlm_info.clog.err_level;
  uint16_t offset = EL_CLOG_TLM_PAGE_SIZE * event_logger->tlm_info.clog.page_no;
  const uint16_t* log_orders = event_logger->clogs[err_level].log_orders;
  const EL_CLogElement* logs = event_logger->clogs[err_level].logs;

  if (218 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], event_logger->tlm_info.clog.page_no);
  TF_copy_u8(&packet[27], (uint8_t)err_level);
  TF_copy_u32(&packet[28], event_logger->statistics.record_counter_total);
  TF_copy_u32(&packet[32], event_logger->statistics.record_counters[err_level]);
  TF_copy_u16(&packet[36], event_logger->clogs[err_level].log_capacity);
  TF_copy_u8(&packet[38], (uint8_t)logs[log_orders[offset+0]].event.group);
  TF_copy_u32(&packet[39], logs[log_orders[offset+0]].event.local);
  TF_copy_u32(&packet[43], logs[log_orders[offset+0]].event.time.total_cycle);
  TF_copy_u8(&packet[47], (uint8_t)logs[log_orders[offset+0]].event.time.step);
  TF_copy_u8(&packet[48], (uint8_t)logs[log_orders[offset+0]].event.note);
  TF_copy_u16(&packet[49], logs[log_orders[offset+0]].count);
  TF_copy_u32(&packet[51], logs[log_orders[offset+0]].delta_record_time.total_cycle);
  TF_copy_u8(&packet[55], (uint8_t)logs[log_orders[offset+0]].delta_record_time.step);
  TF_copy_u8(&packet[56], (uint8_t)logs[log_orders[offset+1]].event.group);
  TF_copy_u32(&packet[57], logs[log_orders[offset+1]].event.local);
  TF_copy_u32(&packet[61], logs[log_orders[offset+1]].event.time.total_cycle);
  TF_copy_u8(&packet[65], (uint8_t)logs[log_orders[offset+1]].event.time.step);
  TF_copy_u8(&packet[66], (uint8_t)logs[log_orders[offset+1]].event.note);
  TF_copy_u16(&packet[67], logs[log_orders[offset+1]].count);
  TF_copy_u32(&packet[69], logs[log_orders[offset+1]].delta_record_time.total_cycle);
  TF_copy_u8(&packet[73], (uint8_t)logs[log_orders[offset+1]].delta_record_time.step);
  TF_copy_u8(&packet[74], (uint8_t)logs[log_orders[offset+2]].event.group);
  TF_copy_u32(&packet[75], logs[log_orders[offset+2]].event.local);
  TF_copy_u32(&packet[79], logs[log_orders[offset+2]].event.time.total_cycle);
  TF_copy_u8(&packet[83], (uint8_t)logs[log_orders[offset+2]].event.time.step);
  TF_copy_u8(&packet[84], (uint8_t)logs[log_orders[offset+2]].event.note);
  TF_copy_u16(&packet[85], logs[log_orders[offset+2]].count);
  TF_copy_u32(&packet[87], logs[log_orders[offset+2]].delta_record_time.total_cycle);
  TF_copy_u8(&packet[91], (uint8_t)logs[log_orders[offset+2]].delta_record_time.step);
  TF_copy_u8(&packet[92], (uint8_t)logs[log_orders[offset+3]].event.group);
  TF_copy_u32(&packet[93], logs[log_orders[offset+3]].event.local);
  TF_copy_u32(&packet[97], logs[log_orders[offset+3]].event.time.total_cycle);
  TF_copy_u8(&packet[101], (uint8_t)logs[log_orders[offset+3]].event.time.step);
  TF_copy_u8(&packet[102], (uint8_t)logs[log_orders[offset+3]].event.note);
  TF_copy_u16(&packet[103], logs[log_orders[offset+3]].count);
  TF_copy_u32(&packet[105], logs[log_orders[offset+3]].delta_record_time.total_cycle);
  TF_copy_u8(&packet[109], (uint8_t)logs[log_orders[offset+3]].delta_record_time.step);
  TF_copy_u8(&packet[110], (uint8_t)logs[log_orders[offset+4]].event.group);
  TF_copy_u32(&packet[111], logs[log_orders[offset+4]].event.local);
  TF_copy_u32(&packet[115], logs[log_orders[offset+4]].event.time.total_cycle);
  TF_copy_u8(&packet[119], (uint8_t)logs[log_orders[offset+4]].event.time.step);
  TF_copy_u8(&packet[120], (uint8_t)logs[log_orders[offset+4]].event.note);
  TF_copy_u16(&packet[121], logs[log_orders[offset+4]].count);
  TF_copy_u32(&packet[123], logs[log_orders[offset+4]].delta_record_time.total_cycle);
  TF_copy_u8(&packet[127], (uint8_t)logs[log_orders[offset+4]].delta_record_time.step);
  TF_copy_u8(&packet[128], (uint8_t)logs[log_orders[offset+5]].event.group);
  TF_copy_u32(&packet[129], logs[log_orders[offset+5]].event.local);
  TF_copy_u32(&packet[133], logs[log_orders[offset+5]].event.time.total_cycle);
  TF_copy_u8(&packet[137], (uint8_t)logs[log_orders[offset+5]].event.time.step);
  TF_copy_u8(&packet[138], (uint8_t)logs[log_orders[offset+5]].event.note);
  TF_copy_u16(&packet[139], logs[log_orders[offset+5]].count);
  TF_copy_u32(&packet[141], logs[log_orders[offset+5]].delta_record_time.total_cycle);
  TF_copy_u8(&packet[145], (uint8_t)logs[log_orders[offset+5]].delta_record_time.step);
  TF_copy_u8(&packet[146], (uint8_t)logs[log_orders[offset+6]].event.group);
  TF_copy_u32(&packet[147], logs[log_orders[offset+6]].event.local);
  TF_copy_u32(&packet[151], logs[log_orders[offset+6]].event.time.total_cycle);
  TF_copy_u8(&packet[155], (uint8_t)logs[log_orders[offset+6]].event.time.step);
  TF_copy_u8(&packet[156], (uint8_t)logs[log_orders[offset+6]].event.note);
  TF_copy_u16(&packet[157], logs[log_orders[offset+6]].count);
  TF_copy_u32(&packet[159], logs[log_orders[offset+6]].delta_record_time.total_cycle);
  TF_copy_u8(&packet[163], (uint8_t)logs[log_orders[offset+6]].delta_record_time.step);
  TF_copy_u8(&packet[164], (uint8_t)logs[log_orders[offset+7]].event.group);
  TF_copy_u32(&packet[165], logs[log_orders[offset+7]].event.local);
  TF_copy_u32(&packet[169], logs[log_orders[offset+7]].event.time.total_cycle);
  TF_copy_u8(&packet[173], (uint8_t)logs[log_orders[offset+7]].event.time.step);
  TF_copy_u8(&packet[174], (uint8_t)logs[log_orders[offset+7]].event.note);
  TF_copy_u16(&packet[175], logs[log_orders[offset+7]].count);
  TF_copy_u32(&packet[177], logs[log_orders[offset+7]].delta_record_time.total_cycle);
  TF_copy_u8(&packet[181], (uint8_t)logs[log_orders[offset+7]].delta_record_time.step);
  TF_copy_u8(&packet[182], (uint8_t)logs[log_orders[offset+8]].event.group);
  TF_copy_u32(&packet[183], logs[log_orders[offset+8]].event.local);
  TF_copy_u32(&packet[187], logs[log_orders[offset+8]].event.time.total_cycle);
  TF_copy_u8(&packet[191], (uint8_t)logs[log_orders[offset+8]].event.time.step);
  TF_copy_u8(&packet[192], (uint8_t)logs[log_orders[offset+8]].event.note);
  TF_copy_u16(&packet[193], logs[log_orders[offset+8]].count);
  TF_copy_u32(&packet[195], logs[log_orders[offset+8]].delta_record_time.total_cycle);
  TF_copy_u8(&packet[199], (uint8_t)logs[log_orders[offset+8]].delta_record_time.step);
  TF_copy_u8(&packet[200], (uint8_t)logs[log_orders[offset+9]].event.group);
  TF_copy_u32(&packet[201], logs[log_orders[offset+9]].event.local);
  TF_copy_u32(&packet[205], logs[log_orders[offset+9]].event.time.total_cycle);
  TF_copy_u8(&packet[209], (uint8_t)logs[log_orders[offset+9]].event.time.step);
  TF_copy_u8(&packet[210], (uint8_t)logs[log_orders[offset+9]].event.note);
  TF_copy_u16(&packet[211], logs[log_orders[offset+9]].count);
  TF_copy_u32(&packet[213], logs[log_orders[offset+9]].delta_record_time.total_cycle);
  TF_copy_u8(&packet[217], (uint8_t)logs[log_orders[offset+9]].delta_record_time.step);
#endif

  *len = 218;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_EH_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (101 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], event_utility->is_enabled_eh_execution);
  TF_copy_u32(&packet[27], event_handler->el_event_counter.counter_total);
  TF_copy_u32(&packet[31], event_handler->el_event_counter.counters[EL_ERROR_LEVEL_HIGH]);
  TF_copy_u32(&packet[35], event_handler->el_event_counter.counters[EL_ERROR_LEVEL_MIDDLE]);
  TF_copy_u32(&packet[39], event_handler->el_event_counter.counters[EL_ERROR_LEVEL_LOW]);
  TF_copy_u32(&packet[43], event_handler->el_event_counter.counters[EL_ERROR_LEVEL_EL]);
  TF_copy_u32(&packet[47], event_handler->el_event_counter.counters[EL_ERROR_LEVEL_EH]);
  TF_copy_u32(&packet[51], event_handler->log_table.respond_counter);
  TF_copy_u16(&packet[55], event_handler->log_table.log_wp);
  TF_copy_u8(&packet[57], event_handler->exec_settings.max_response_num);
  TF_copy_u16(&packet[58], event_handler->exec_settings.max_check_event_num);
  TF_copy_u8(&packet[60], event_handler->exec_settings.max_multi_level_num);
  TF_copy_u8(&packet[61], (uint8_t)event_handler->reg_from_cmd.rule_id);
  TF_copy_u8(&packet[62], (uint8_t)event_handler->reg_from_cmd.settings.event.group);
  TF_copy_u32(&packet[63], event_handler->reg_from_cmd.settings.event.local);
  TF_copy_u8(&packet[67], (uint8_t)((((uint8_t)event_handler->reg_from_cmd.settings.event.err_level) << 5 & 0xe0) | (event_handler->reg_from_cmd.settings.should_match_err_level << 4 & 0x10) | (event_handler->reg_from_cmd.settings.is_active << 3 & 0x08) | (((uint8_t)event_handler->reg_from_cmd.settings.condition.type) & 0x07)));
  TF_copy_u16(&packet[68], event_handler->reg_from_cmd.settings.condition.count_threshold);
  TF_copy_u32(&packet[70], event_handler->reg_from_cmd.settings.condition.time_threshold_ms);
  TF_copy_u16(&packet[74], (uint16_t)event_handler->reg_from_cmd.settings.deploy_bct_id);
  TF_copy_u8(&packet[76], (uint8_t)event_handler->reg_from_cmd.register_ack);
  TF_copy_u8(&packet[77], event_handler->tlm_info.rule.page_no);
  TF_copy_u8(&packet[78], (uint8_t)event_handler->tlm_info.rule.target_rule_id);
  TF_copy_u8(&packet[79], event_handler->tlm_info.rule_sorted_index.page_no);
  TF_copy_u8(&packet[80], event_handler->tlm_info.log.page_no);
  TF_copy_u8(&packet[81], (uint8_t)event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].settings.event.group);
  TF_copy_u32(&packet[82], event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].settings.event.local);
  TF_copy_u8(&packet[86], (uint8_t)((((uint8_t)event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].settings.event.err_level) << 5 & 0xe0) | (event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].settings.should_match_err_level << 4 & 0x10) | (event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].settings.is_active << 3 & 0x08) | (((uint8_t)event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].settings.condition.type) & 0x07)));
  TF_copy_u16(&packet[87], event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].settings.condition.count_threshold);
  TF_copy_u32(&packet[89], event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].settings.condition.time_threshold_ms);
  TF_copy_u16(&packet[93], (uint16_t)event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].settings.deploy_bct_id);
  TF_copy_u16(&packet[95], event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].counter);
  TF_copy_u32(&packet[97], (uint32_t)event_handler->rule_table.rules[event_handler->tlm_info.rule.target_rule_id].last_event_time.total_cycle);
#endif

  *len = 101;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_EH_RULE_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  uint16_t offset = event_handler->tlm_info.rule.page_no * EH_RULE_TLM_PAGE_SIZE;
  const EH_Rule* rules = event_handler->rule_table.rules;

  if (189 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], event_handler->tlm_info.rule.page_no);
  TF_copy_u16(&packet[27], event_handler->rule_table.registered_rule_num);
  TF_copy_u8(&packet[29], (uint8_t)rules[0 + offset].settings.event.group);
  TF_copy_u32(&packet[30], rules[0 + offset].settings.event.local);
  TF_copy_u8(&packet[34], (uint8_t)((((uint8_t)rules[0 + offset].settings.event.err_level) << 5 & 0xe0) | (rules[0 + offset].settings.should_match_err_level << 4 & 0x10) | (rules[0 + offset].settings.is_active << 3 & 0x08) | (((uint8_t)rules[0 + offset].settings.condition.type) & 0x07)));
  TF_copy_u16(&packet[35], rules[0 + offset].settings.condition.count_threshold);
  TF_copy_u32(&packet[37], rules[0 + offset].settings.condition.time_threshold_ms);
  TF_copy_u16(&packet[41], (uint16_t)rules[0 + offset].settings.deploy_bct_id);
  TF_copy_u16(&packet[43], rules[0 + offset].counter);
  TF_copy_u32(&packet[45], (uint32_t)rules[0 + offset].last_event_time.total_cycle);
  TF_copy_u8(&packet[49], (uint8_t)rules[1 + offset].settings.event.group);
  TF_copy_u32(&packet[50], rules[1 + offset].settings.event.local);
  TF_copy_u8(&packet[54], (uint8_t)((((uint8_t)rules[1 + offset].settings.event.err_level) << 5 & 0xe0) | (rules[1 + offset].settings.should_match_err_level << 4 & 0x10) | (rules[1 + offset].settings.is_active << 3 & 0x08) | (((uint8_t)rules[1 + offset].settings.condition.type) & 0x07)));
  TF_copy_u16(&packet[55], rules[1 + offset].settings.condition.count_threshold);
  TF_copy_u32(&packet[57], rules[1 + offset].settings.condition.time_threshold_ms);
  TF_copy_u16(&packet[61], (uint16_t)rules[1 + offset].settings.deploy_bct_id);
  TF_copy_u16(&packet[63], rules[1 + offset].counter);
  TF_copy_u32(&packet[65], (uint32_t)rules[1 + offset].last_event_time.total_cycle);
  TF_copy_u8(&packet[69], (uint8_t)rules[2 + offset].settings.event.group);
  TF_copy_u32(&packet[70], rules[2 + offset].settings.event.local);
  TF_copy_u8(&packet[74], (uint8_t)((((uint8_t)rules[2 + offset].settings.event.err_level) << 5 & 0xe0) | (rules[2 + offset].settings.should_match_err_level << 4 & 0x10) | (rules[2 + offset].settings.is_active << 3 & 0x08) | (((uint8_t)rules[2 + offset].settings.condition.type) & 0x07)));
  TF_copy_u16(&packet[75], rules[2 + offset].settings.condition.count_threshold);
  TF_copy_u32(&packet[77], rules[2 + offset].settings.condition.time_threshold_ms);
  TF_copy_u16(&packet[81], (uint16_t)rules[2 + offset].settings.deploy_bct_id);
  TF_copy_u16(&packet[83], rules[2 + offset].counter);
  TF_copy_u32(&packet[85], (uint32_t)rules[2 + offset].last_event_time.total_cycle);
  TF_copy_u8(&packet[89], (uint8_t)rules[3 + offset].settings.event.group);
  TF_copy_u32(&packet[90], rules[3 + offset].settings.event.local);
  TF_copy_u8(&packet[94], (uint8_t)((((uint8_t)rules[3 + offset].settings.event.err_level) << 5 & 0xe0) | (rules[3 + offset].settings.should_match_err_level << 4 & 0x10) | (rules[3 + offset].settings.is_active << 3 & 0x08) | (((uint8_t)rules[3 + offset].settings.condition.type) & 0x07)));
  TF_copy_u16(&packet[95], rules[3 + offset].settings.condition.count_threshold);
  TF_copy_u32(&packet[97], rules[3 + offset].settings.condition.time_threshold_ms);
  TF_copy_u16(&packet[101], (uint16_t)rules[3 + offset].settings.deploy_bct_id);
  TF_copy_u16(&packet[103], rules[3 + offset].counter);
  TF_copy_u32(&packet[105], (uint32_t)rules[3 + offset].last_event_time.total_cycle);
  TF_copy_u8(&packet[109], (uint8_t)rules[4 + offset].settings.event.group);
  TF_copy_u32(&packet[110], rules[4 + offset].settings.event.local);
  TF_copy_u8(&packet[114], (uint8_t)((((uint8_t)rules[4 + offset].settings.event.err_level) << 5 & 0xe0) | (rules[4 + offset].settings.should_match_err_level << 4 & 0x10) | (rules[4 + offset].settings.is_active << 3 & 0x08) | (((uint8_t)rules[4 + offset].settings.condition.type) & 0x07)));
  TF_copy_u16(&packet[115], rules[4 + offset].settings.condition.count_threshold);
  TF_copy_u32(&packet[117], rules[4 + offset].settings.condition.time_threshold_ms);
  TF_copy_u16(&packet[121], (uint16_t)rules[4 + offset].settings.deploy_bct_id);
  TF_copy_u16(&packet[123], rules[4 + offset].counter);
  TF_copy_u32(&packet[125], (uint32_t)rules[4 + offset].last_event_time.total_cycle);
  TF_copy_u8(&packet[129], (uint8_t)rules[5 + offset].settings.event.group);
  TF_copy_u32(&packet[130], rules[5 + offset].settings.event.local);
  TF_copy_u8(&packet[134], (uint8_t)((((uint8_t)rules[5 + offset].settings.event.err_level) << 5 & 0xe0) | (rules[5 + offset].settings.should_match_err_level << 4 & 0x10) | (rules[5 + offset].settings.is_active << 3 & 0x08) | (((uint8_t)rules[5 + offset].settings.condition.type) & 0x07)));
  TF_copy_u16(&packet[135], rules[5 + offset].settings.condition.count_threshold);
  TF_copy_u32(&packet[137], rules[5 + offset].settings.condition.time_threshold_ms);
  TF_copy_u16(&packet[141], (uint16_t)rules[5 + offset].settings.deploy_bct_id);
  TF_copy_u16(&packet[143], rules[5 + offset].counter);
  TF_copy_u32(&packet[145], (uint32_t)rules[5 + offset].last_event_time.total_cycle);
  TF_copy_u8(&packet[149], (uint8_t)rules[6 + offset].settings.event.group);
  TF_copy_u32(&packet[150], rules[6 + offset].settings.event.local);
  TF_copy_u8(&packet[154], (uint8_t)((((uint8_t)rules[6 + offset].settings.event.err_level) << 5 & 0xe0) | (rules[6 + offset].settings.should_match_err_level << 4 & 0x10) | (rules[6 + offset].settings.is_active << 3 & 0x08) | (((uint8_t)rules[6 + offset].settings.condition.type) & 0x07)));
  TF_copy_u16(&packet[155], rules[6 + offset].settings.condition.count_threshold);
  TF_copy_u32(&packet[157], rules[6 + offset].settings.condition.time_threshold_ms);
  TF_copy_u16(&packet[161], (uint16_t)rules[6 + offset].settings.deploy_bct_id);
  TF_copy_u16(&packet[163], rules[6 + offset].counter);
  TF_copy_u32(&packet[165], (uint32_t)rules[6 + offset].last_event_time.total_cycle);
  TF_copy_u8(&packet[169], (uint8_t)rules[7 + offset].settings.event.group);
  TF_copy_u32(&packet[170], rules[7 + offset].settings.event.local);
  TF_copy_u8(&packet[174], (uint8_t)((((uint8_t)rules[7 + offset].settings.event.err_level) << 5 & 0xe0) | (rules[7 + offset].settings.should_match_err_level << 4 & 0x10) | (rules[7 + offset].settings.is_active << 3 & 0x08) | (((uint8_t)rules[7 + offset].settings.condition.type) & 0x07)));
  TF_copy_u16(&packet[175], rules[7 + offset].settings.condition.count_threshold);
  TF_copy_u32(&packet[177], rules[7 + offset].settings.condition.time_threshold_ms);
  TF_copy_u16(&packet[181], (uint16_t)rules[7 + offset].settings.deploy_bct_id);
  TF_copy_u16(&packet[183], rules[7 + offset].counter);
  TF_copy_u32(&packet[185], (uint32_t)rules[7 + offset].last_event_time.total_cycle);
#endif

  *len = 189;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_EH_LOG_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  uint16_t offset = event_handler->tlm_info.log.page_no * EH_LOG_TLM_PAGE_SIZE;

  if (153 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], event_handler->tlm_info.log.page_no);
  TF_copy_u32(&packet[27], event_handler->log_table.respond_counter);
  TF_copy_u16(&packet[31], event_handler->log_table.log_wp);
  TF_copy_u8(&packet[33], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(0 + offset))->rule_id);
  TF_copy_u32(&packet[34], EH_get_the_nth_log_from_the_latest((uint16_t)(0 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[38], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(0 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[39], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(1 + offset))->rule_id);
  TF_copy_u32(&packet[40], EH_get_the_nth_log_from_the_latest((uint16_t)(1 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[44], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(1 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[45], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(2 + offset))->rule_id);
  TF_copy_u32(&packet[46], EH_get_the_nth_log_from_the_latest((uint16_t)(2 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[50], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(2 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[51], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(3 + offset))->rule_id);
  TF_copy_u32(&packet[52], EH_get_the_nth_log_from_the_latest((uint16_t)(3 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[56], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(3 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[57], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(4 + offset))->rule_id);
  TF_copy_u32(&packet[58], EH_get_the_nth_log_from_the_latest((uint16_t)(4 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[62], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(4 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[63], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(5 + offset))->rule_id);
  TF_copy_u32(&packet[64], EH_get_the_nth_log_from_the_latest((uint16_t)(5 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[68], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(5 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[69], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(6 + offset))->rule_id);
  TF_copy_u32(&packet[70], EH_get_the_nth_log_from_the_latest((uint16_t)(6 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[74], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(6 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[75], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(7 + offset))->rule_id);
  TF_copy_u32(&packet[76], EH_get_the_nth_log_from_the_latest((uint16_t)(7 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[80], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(7 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[81], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(8 + offset))->rule_id);
  TF_copy_u32(&packet[82], EH_get_the_nth_log_from_the_latest((uint16_t)(8 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[86], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(8 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[87], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(9 + offset))->rule_id);
  TF_copy_u32(&packet[88], EH_get_the_nth_log_from_the_latest((uint16_t)(9 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[92], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(9 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[93], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(10 + offset))->rule_id);
  TF_copy_u32(&packet[94], EH_get_the_nth_log_from_the_latest((uint16_t)(10 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[98], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(10 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[99], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(11 + offset))->rule_id);
  TF_copy_u32(&packet[100], EH_get_the_nth_log_from_the_latest((uint16_t)(11 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[104], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(11 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[105], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(12 + offset))->rule_id);
  TF_copy_u32(&packet[106], EH_get_the_nth_log_from_the_latest((uint16_t)(12 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[110], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(12 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[111], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(13 + offset))->rule_id);
  TF_copy_u32(&packet[112], EH_get_the_nth_log_from_the_latest((uint16_t)(13 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[116], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(13 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[117], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(14 + offset))->rule_id);
  TF_copy_u32(&packet[118], EH_get_the_nth_log_from_the_latest((uint16_t)(14 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[122], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(14 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[123], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(15 + offset))->rule_id);
  TF_copy_u32(&packet[124], EH_get_the_nth_log_from_the_latest((uint16_t)(15 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[128], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(15 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[129], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(16 + offset))->rule_id);
  TF_copy_u32(&packet[130], EH_get_the_nth_log_from_the_latest((uint16_t)(16 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[134], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(16 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[135], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(17 + offset))->rule_id);
  TF_copy_u32(&packet[136], EH_get_the_nth_log_from_the_latest((uint16_t)(17 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[140], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(17 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[141], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(18 + offset))->rule_id);
  TF_copy_u32(&packet[142], EH_get_the_nth_log_from_the_latest((uint16_t)(18 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[146], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(18 + offset))->deploy_cmd_ack);
  TF_copy_u8(&packet[147], (uint8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(19 + offset))->rule_id);
  TF_copy_u32(&packet[148], EH_get_the_nth_log_from_the_latest((uint16_t)(19 + offset))->respond_time_in_master_cycle);
  TF_copy_i8(&packet[152], (int8_t)EH_get_the_nth_log_from_the_latest((uint16_t)(19 + offset))->deploy_cmd_ack);
#endif

  *len = 153;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_EH_INDEX_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  uint16_t offset = event_handler->tlm_info.rule_sorted_index.page_no * EH_RULE_TLM_PAGE_SIZE;

  if (83 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], event_handler->tlm_info.rule_sorted_index.page_no);
  TF_copy_u8(&packet[27], (uint8_t)event_handler->sorted_idxes[0 + offset].group);
  TF_copy_u32(&packet[28], event_handler->sorted_idxes[0 + offset].local);
  TF_copy_u8(&packet[32], event_handler->sorted_idxes[0 + offset].duplicate_id);
  TF_copy_u8(&packet[33], (uint8_t)event_handler->sorted_idxes[0 + offset].rule_id);
  TF_copy_u8(&packet[34], (uint8_t)event_handler->sorted_idxes[1 + offset].group);
  TF_copy_u32(&packet[35], event_handler->sorted_idxes[1 + offset].local);
  TF_copy_u8(&packet[39], event_handler->sorted_idxes[1 + offset].duplicate_id);
  TF_copy_u8(&packet[40], (uint8_t)event_handler->sorted_idxes[1 + offset].rule_id);
  TF_copy_u8(&packet[41], (uint8_t)event_handler->sorted_idxes[2 + offset].group);
  TF_copy_u32(&packet[42], event_handler->sorted_idxes[2 + offset].local);
  TF_copy_u8(&packet[46], event_handler->sorted_idxes[2 + offset].duplicate_id);
  TF_copy_u8(&packet[47], (uint8_t)event_handler->sorted_idxes[2 + offset].rule_id);
  TF_copy_u8(&packet[48], (uint8_t)event_handler->sorted_idxes[3 + offset].group);
  TF_copy_u32(&packet[49], event_handler->sorted_idxes[3 + offset].local);
  TF_copy_u8(&packet[53], event_handler->sorted_idxes[3 + offset].duplicate_id);
  TF_copy_u8(&packet[54], (uint8_t)event_handler->sorted_idxes[3 + offset].rule_id);
  TF_copy_u8(&packet[55], (uint8_t)event_handler->sorted_idxes[4 + offset].group);
  TF_copy_u32(&packet[56], event_handler->sorted_idxes[4 + offset].local);
  TF_copy_u8(&packet[60], event_handler->sorted_idxes[4 + offset].duplicate_id);
  TF_copy_u8(&packet[61], (uint8_t)event_handler->sorted_idxes[4 + offset].rule_id);
  TF_copy_u8(&packet[62], (uint8_t)event_handler->sorted_idxes[5 + offset].group);
  TF_copy_u32(&packet[63], event_handler->sorted_idxes[5 + offset].local);
  TF_copy_u8(&packet[67], event_handler->sorted_idxes[5 + offset].duplicate_id);
  TF_copy_u8(&packet[68], (uint8_t)event_handler->sorted_idxes[5 + offset].rule_id);
  TF_copy_u8(&packet[69], (uint8_t)event_handler->sorted_idxes[6 + offset].group);
  TF_copy_u32(&packet[70], event_handler->sorted_idxes[6 + offset].local);
  TF_copy_u8(&packet[74], event_handler->sorted_idxes[6 + offset].duplicate_id);
  TF_copy_u8(&packet[75], (uint8_t)event_handler->sorted_idxes[6 + offset].rule_id);
  TF_copy_u8(&packet[76], (uint8_t)event_handler->sorted_idxes[7 + offset].group);
  TF_copy_u32(&packet[77], event_handler->sorted_idxes[7 + offset].local);
  TF_copy_u8(&packet[81], event_handler->sorted_idxes[7 + offset].duplicate_id);
  TF_copy_u8(&packet[82], (uint8_t)event_handler->sorted_idxes[7 + offset].rule_id);
#endif

  *len = 83;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_GIT_REV_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (108 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], (uint8_t)GIT_REV_CORE[0]);
  TF_copy_u8(&packet[27], (uint8_t)GIT_REV_CORE[1]);
  TF_copy_u8(&packet[28], (uint8_t)GIT_REV_CORE[2]);
  TF_copy_u8(&packet[29], (uint8_t)GIT_REV_CORE[3]);
  TF_copy_u8(&packet[30], (uint8_t)GIT_REV_CORE[4]);
  TF_copy_u8(&packet[31], (uint8_t)GIT_REV_CORE[5]);
  TF_copy_u8(&packet[32], (uint8_t)GIT_REV_CORE[6]);
  TF_copy_u8(&packet[33], (uint8_t)GIT_REV_CORE[7]);
  TF_copy_u8(&packet[34], (uint8_t)GIT_REV_CORE[8]);
  TF_copy_u8(&packet[35], (uint8_t)GIT_REV_CORE[9]);
  TF_copy_u8(&packet[36], (uint8_t)GIT_REV_CORE[10]);
  TF_copy_u8(&packet[37], (uint8_t)GIT_REV_CORE[11]);
  TF_copy_u8(&packet[38], (uint8_t)GIT_REV_CORE[12]);
  TF_copy_u8(&packet[39], (uint8_t)GIT_REV_CORE[13]);
  TF_copy_u8(&packet[40], (uint8_t)GIT_REV_CORE[14]);
  TF_copy_u8(&packet[41], (uint8_t)GIT_REV_CORE[15]);
  TF_copy_u8(&packet[42], (uint8_t)GIT_REV_CORE[16]);
  TF_copy_u8(&packet[43], (uint8_t)GIT_REV_CORE[17]);
  TF_copy_u8(&packet[44], (uint8_t)GIT_REV_CORE[18]);
  TF_copy_u8(&packet[45], (uint8_t)GIT_REV_CORE[19]);
  TF_copy_u8(&packet[46], (uint8_t)GIT_REV_CORE[20]);
  TF_copy_u8(&packet[47], (uint8_t)GIT_REV_CORE[21]);
  TF_copy_u8(&packet[48], (uint8_t)GIT_REV_CORE[22]);
  TF_copy_u8(&packet[49], (uint8_t)GIT_REV_CORE[23]);
  TF_copy_u8(&packet[50], (uint8_t)GIT_REV_CORE[24]);
  TF_copy_u8(&packet[51], (uint8_t)GIT_REV_CORE[25]);
  TF_copy_u8(&packet[52], (uint8_t)GIT_REV_CORE[26]);
  TF_copy_u8(&packet[53], (uint8_t)GIT_REV_CORE[27]);
  TF_copy_u8(&packet[54], (uint8_t)GIT_REV_CORE[28]);
  TF_copy_u8(&packet[55], (uint8_t)GIT_REV_CORE[29]);
  TF_copy_u8(&packet[56], (uint8_t)GIT_REV_CORE[30]);
  TF_copy_u8(&packet[57], (uint8_t)GIT_REV_CORE[31]);
  TF_copy_u8(&packet[58], (uint8_t)GIT_REV_CORE[32]);
  TF_copy_u8(&packet[59], (uint8_t)GIT_REV_CORE[33]);
  TF_copy_u8(&packet[60], (uint8_t)GIT_REV_CORE[34]);
  TF_copy_u8(&packet[61], (uint8_t)GIT_REV_CORE[35]);
  TF_copy_u8(&packet[62], (uint8_t)GIT_REV_CORE[36]);
  TF_copy_u8(&packet[63], (uint8_t)GIT_REV_CORE[37]);
  TF_copy_u8(&packet[64], (uint8_t)GIT_REV_CORE[38]);
  TF_copy_u8(&packet[65], (uint8_t)GIT_REV_CORE[39]);
  TF_copy_u8(&packet[66], (uint8_t)GIT_REV_CORE[40]);
  TF_copy_u8(&packet[67], (uint8_t)GIT_REV_USER[0]);
  TF_copy_u8(&packet[68], (uint8_t)GIT_REV_USER[1]);
  TF_copy_u8(&packet[69], (uint8_t)GIT_REV_USER[2]);
  TF_copy_u8(&packet[70], (uint8_t)GIT_REV_USER[3]);
  TF_copy_u8(&packet[71], (uint8_t)GIT_REV_USER[4]);
  TF_copy_u8(&packet[72], (uint8_t)GIT_REV_USER[5]);
  TF_copy_u8(&packet[73], (uint8_t)GIT_REV_USER[6]);
  TF_copy_u8(&packet[74], (uint8_t)GIT_REV_USER[7]);
  TF_copy_u8(&packet[75], (uint8_t)GIT_REV_USER[8]);
  TF_copy_u8(&packet[76], (uint8_t)GIT_REV_USER[9]);
  TF_copy_u8(&packet[77], (uint8_t)GIT_REV_USER[10]);
  TF_copy_u8(&packet[78], (uint8_t)GIT_REV_USER[11]);
  TF_copy_u8(&packet[79], (uint8_t)GIT_REV_USER[12]);
  TF_copy_u8(&packet[80], (uint8_t)GIT_REV_USER[13]);
  TF_copy_u8(&packet[81], (uint8_t)GIT_REV_USER[14]);
  TF_copy_u8(&packet[82], (uint8_t)GIT_REV_USER[15]);
  TF_copy_u8(&packet[83], (uint8_t)GIT_REV_USER[16]);
  TF_copy_u8(&packet[84], (uint8_t)GIT_REV_USER[17]);
  TF_copy_u8(&packet[85], (uint8_t)GIT_REV_USER[18]);
  TF_copy_u8(&packet[86], (uint8_t)GIT_REV_USER[19]);
  TF_copy_u8(&packet[87], (uint8_t)GIT_REV_USER[20]);
  TF_copy_u8(&packet[88], (uint8_t)GIT_REV_USER[21]);
  TF_copy_u8(&packet[89], (uint8_t)GIT_REV_USER[22]);
  TF_copy_u8(&packet[90], (uint8_t)GIT_REV_USER[23]);
  TF_copy_u8(&packet[91], (uint8_t)GIT_REV_USER[24]);
  TF_copy_u8(&packet[92], (uint8_t)GIT_REV_USER[25]);
  TF_copy_u8(&packet[93], (uint8_t)GIT_REV_USER[26]);
  TF_copy_u8(&packet[94], (uint8_t)GIT_REV_USER[27]);
  TF_copy_u8(&packet[95], (uint8_t)GIT_REV_USER[28]);
  TF_copy_u8(&packet[96], (uint8_t)GIT_REV_USER[29]);
  TF_copy_u8(&packet[97], (uint8_t)GIT_REV_USER[30]);
  TF_copy_u8(&packet[98], (uint8_t)GIT_REV_USER[31]);
  TF_copy_u8(&packet[99], (uint8_t)GIT_REV_USER[32]);
  TF_copy_u8(&packet[100], (uint8_t)GIT_REV_USER[33]);
  TF_copy_u8(&packet[101], (uint8_t)GIT_REV_USER[34]);
  TF_copy_u8(&packet[102], (uint8_t)GIT_REV_USER[35]);
  TF_copy_u8(&packet[103], (uint8_t)GIT_REV_USER[36]);
  TF_copy_u8(&packet[104], (uint8_t)GIT_REV_USER[37]);
  TF_copy_u8(&packet[105], (uint8_t)GIT_REV_USER[38]);
  TF_copy_u8(&packet[106], (uint8_t)GIT_REV_USER[39]);
  TF_copy_u8(&packet[107], (uint8_t)GIT_REV_USER[40]);
#endif

  *len = 108;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_HK_GEN_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (133 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u32(&packet[26], (uint32_t)(TMGR_get_master_clock().mode_cycle));
  TF_copy_u8(&packet[30], (uint8_t)(mode_manager->current_id));
  TF_copy_u8(&packet[31], (uint8_t)( ((uint8_t)(mode_manager->stat) << 7 & 0x80) | ((uint8_t)(mode_manager->previous_id) & 0x7F) ));
  TF_copy_u16(&packet[32], task_dispatcher->task_list_id);
  TF_copy_u8(&packet[34], (uint8_t)(PH_gs_cmd_list.executed_nodes_));
  TF_copy_u32(&packet[35], (uint32_t)gs_command_dispatcher->prev.time.total_cycle);
  TF_copy_u16(&packet[39], (uint16_t)(gs_command_dispatcher->prev.code));
  TF_copy_u8(&packet[41], (uint8_t)(gs_command_dispatcher->prev.cmd_ret.exec_sts));
  TF_copy_u8(&packet[42], (uint8_t)(gs_command_dispatcher->error_counter));
  TF_copy_u32(&packet[43], (uint32_t)gs_command_dispatcher->prev_err.time.total_cycle);
  TF_copy_u16(&packet[47], (uint16_t)(gs_command_dispatcher->prev_err.code));
  TF_copy_u8(&packet[49], (uint8_t)(gs_command_dispatcher->prev_err.cmd_ret.exec_sts));
  TF_copy_u16(&packet[50], (uint16_t)(gs_command_dispatcher->prev_err.cmd_ret.err_code));
  TF_copy_u8(&packet[52], (uint8_t)(PH_tl_cmd_list[TLCD_ID_FROM_GS].executed_nodes_));
  TF_copy_u8(&packet[53], (uint8_t)(PH_tl_cmd_list[TLCD_ID_FROM_GS].active_nodes_));
  TF_copy_u32(&packet[54], (uint32_t)timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev.time.total_cycle);
  TF_copy_u16(&packet[58], (uint16_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev.code));
  TF_copy_u8(&packet[60], (uint8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev.cmd_ret.exec_sts));
  TF_copy_u8(&packet[61], (uint8_t)timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].error_counter);
  TF_copy_u32(&packet[62], (uint32_t)timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev_err.time.total_cycle);
  TF_copy_u16(&packet[66], (uint16_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev_err.code));
  TF_copy_u8(&packet[68], (uint8_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev_err.cmd_ret.exec_sts));
  TF_copy_u16(&packet[69], (uint16_t)(timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].prev_err.cmd_ret.err_code));
  TF_copy_u32(&packet[71], (PL_is_empty(&(PH_tl_cmd_list[TLCD_ID_FROM_GS])) ? 0 : CCP_get_ti((const CommonCmdPacket*)(PL_get_head(&(PH_tl_cmd_list[TLCD_ID_FROM_GS]))->packet))));
  TF_copy_u16(&packet[75], (uint16_t)(PL_is_empty(&(PH_tl_cmd_list[TLCD_ID_FROM_GS])) ? 0 : CCP_get_id((const CommonCmdPacket*)(PL_get_head(&(PH_tl_cmd_list[TLCD_ID_FROM_GS]))->packet))));
  TF_copy_u8(&packet[77], (uint8_t)(PH_tl_cmd_list[TLCD_ID_DEPLOY_BC].executed_nodes_));
  TF_copy_u8(&packet[78], (uint8_t)(PH_tl_cmd_list[TLCD_ID_DEPLOY_BC].active_nodes_));
  TF_copy_u8(&packet[79], (uint8_t)(PH_tl_cmd_list[TLCD_ID_DEPLOY_TLM].executed_nodes_));
  TF_copy_u8(&packet[80], (uint8_t)(PH_tl_cmd_list[TLCD_ID_DEPLOY_TLM].active_nodes_));
  TF_copy_u8(&packet[81], (uint8_t)(((uint8_t)timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].stop_on_error << 7 & 0x80) | ((uint8_t)timeline_command_dispatcher->dispatcher[TLCD_ID_FROM_GS].lockout << 6 & 0x40) | ((uint8_t)timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].stop_on_error << 5 & 0x20) | ((uint8_t)timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_BC].lockout << 4 & 0x10) | ((uint8_t)timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].stop_on_error << 3 & 0x08) | ((uint8_t)timeline_command_dispatcher->dispatcher[TLCD_ID_DEPLOY_TLM].lockout << 2 & 0x04) | (0 << 2 & 0x02) | (0 << 2 & 0x01) ));
  TF_copy_u32(&packet[82], event_logger->statistics.record_counter_total);
  TF_copy_u16(&packet[86], (uint16_t)event_logger->statistics.record_counters[EL_ERROR_LEVEL_HIGH]);
  TF_copy_u16(&packet[88], (uint16_t)event_logger->statistics.record_counters[EL_ERROR_LEVEL_LOW]);
  TF_copy_u16(&packet[90], (uint16_t)event_logger->statistics.record_counters[EL_ERROR_LEVEL_EL]);
  TF_copy_u16(&packet[92], (uint16_t)event_logger->statistics.record_counters[EL_ERROR_LEVEL_EH]);
  TF_copy_u8(&packet[94], (uint8_t)event_logger->latest_event.err_level);
  TF_copy_u8(&packet[95], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 0)->group);
  TF_copy_u32(&packet[96], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 0)->local);
  TF_copy_u32(&packet[100], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 0)->time.total_cycle);
  TF_copy_u8(&packet[104], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 0)->time.step);
  TF_copy_u32(&packet[105], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_LOW, 0)->note);
  TF_copy_u8(&packet[109], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 0)->group);
  TF_copy_u32(&packet[110], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 0)->local);
  TF_copy_u32(&packet[114], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 0)->time.total_cycle);
  TF_copy_u8(&packet[118], (uint8_t)EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 0)->time.step);
  TF_copy_u32(&packet[119], EL_get_the_nth_tlog_from_the_latest(EL_ERROR_LEVEL_HIGH, 0)->note);
  TF_copy_u32(&packet[123], event_handler->log_table.respond_counter);
  TF_copy_u16(&packet[127], (uint16_t)EH_get_the_nth_log_from_the_latest(0)->rule_id);
  TF_copy_u32(&packet[129], (uint32_t)EH_get_the_nth_log_from_the_latest(0)->respond_time_in_master_cycle);
#endif

  *len = 133;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_HK_COMPO_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_HK_ALGO_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_COMPONENTS_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (35 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], (uint8_t)(stim377h_driver[STIM377H_IDX_IN_UNIT]->info.counter));
  TF_copy_u16(&packet[27], (uint16_t)(stim377h_driver[STIM377H_IDX_IN_UNIT]->info.latency_sec));
  TF_copy_u8(&packet[29], (uint8_t)(stim377h_driver[STIM377H_IDX_IN_UNIT]->info.normal_mode_format));
  TF_copy_u8(&packet[30], (uint8_t)(stim377h_driver[STIM377H_IDX_IN_UNIT]->info.gyro_output_mode));
  TF_copy_u8(&packet[31], (uint8_t)(stim377h_driver[STIM377H_IDX_IN_UNIT]->info.termination_mode));
  TF_copy_u8(&packet[32], (uint8_t)(stim377h_driver[STIM377H_IDX_IN_UNIT]->info.low_pass_filter_frequency));
  TF_copy_u8(&packet[33], (uint8_t)(stim377h_driver[STIM377H_IDX_IN_UNIT]->info.sample_rate));
  TF_copy_u8(&packet[34], (uint8_t)(stim377h_driver[STIM377H_IDX_IN_UNIT]->info.status));
#endif

  *len = 35;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_POWER_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_FRAME_TRANSFORMATION_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_CONTROL_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_BIAS_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_TEMP_CALIB_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_INTERPOLATION_TARGET1_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_INTERPOLATION_TARGET2_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_NON_VOLATILE_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_ORBIT_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_AOCS_MANAGER_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_SUN_POINTING_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_THREE_AXIS_MTQ_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_THREE_AXIS_RW_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_FILTERS_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_ANOMALY_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_APP_TIME_2_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (146 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
  TF_copy_u8(&packet[26], (uint8_t)(app_manager->ais[50].init_duration));
  TF_copy_u8(&packet[27], (uint8_t)(app_manager->ais[50].prev));
  TF_copy_u8(&packet[28], (uint8_t)(app_manager->ais[50].min));
  TF_copy_u8(&packet[29], (uint8_t)(app_manager->ais[50].max));
  TF_copy_u8(&packet[30], (uint8_t)(app_manager->ais[51].init_duration));
  TF_copy_u8(&packet[31], (uint8_t)(app_manager->ais[51].prev));
  TF_copy_u8(&packet[32], (uint8_t)(app_manager->ais[51].min));
  TF_copy_u8(&packet[33], (uint8_t)(app_manager->ais[51].max));
  TF_copy_u8(&packet[34], (uint8_t)(app_manager->ais[52].init_duration));
  TF_copy_u8(&packet[35], (uint8_t)(app_manager->ais[52].prev));
  TF_copy_u8(&packet[36], (uint8_t)(app_manager->ais[52].min));
  TF_copy_u8(&packet[37], (uint8_t)(app_manager->ais[52].max));
  TF_copy_u8(&packet[38], (uint8_t)(app_manager->ais[53].init_duration));
  TF_copy_u8(&packet[39], (uint8_t)(app_manager->ais[53].prev));
  TF_copy_u8(&packet[40], (uint8_t)(app_manager->ais[53].min));
  TF_copy_u8(&packet[41], (uint8_t)(app_manager->ais[53].max));
  TF_copy_u8(&packet[42], (uint8_t)(app_manager->ais[54].init_duration));
  TF_copy_u8(&packet[43], (uint8_t)(app_manager->ais[54].prev));
  TF_copy_u8(&packet[44], (uint8_t)(app_manager->ais[54].min));
  TF_copy_u8(&packet[45], (uint8_t)(app_manager->ais[54].max));
  TF_copy_u8(&packet[46], (uint8_t)(app_manager->ais[55].init_duration));
  TF_copy_u8(&packet[47], (uint8_t)(app_manager->ais[55].prev));
  TF_copy_u8(&packet[48], (uint8_t)(app_manager->ais[55].min));
  TF_copy_u8(&packet[49], (uint8_t)(app_manager->ais[55].max));
  TF_copy_u8(&packet[50], (uint8_t)(app_manager->ais[56].init_duration));
  TF_copy_u8(&packet[51], (uint8_t)(app_manager->ais[56].prev));
  TF_copy_u8(&packet[52], (uint8_t)(app_manager->ais[56].min));
  TF_copy_u8(&packet[53], (uint8_t)(app_manager->ais[56].max));
  TF_copy_u8(&packet[54], (uint8_t)(app_manager->ais[57].init_duration));
  TF_copy_u8(&packet[55], (uint8_t)(app_manager->ais[57].prev));
  TF_copy_u8(&packet[56], (uint8_t)(app_manager->ais[57].min));
  TF_copy_u8(&packet[57], (uint8_t)(app_manager->ais[57].max));
  TF_copy_u8(&packet[58], (uint8_t)(app_manager->ais[58].init_duration));
  TF_copy_u8(&packet[59], (uint8_t)(app_manager->ais[58].prev));
  TF_copy_u8(&packet[60], (uint8_t)(app_manager->ais[58].min));
  TF_copy_u8(&packet[61], (uint8_t)(app_manager->ais[58].max));
  TF_copy_u8(&packet[62], (uint8_t)(app_manager->ais[59].init_duration));
  TF_copy_u8(&packet[63], (uint8_t)(app_manager->ais[59].prev));
  TF_copy_u8(&packet[64], (uint8_t)(app_manager->ais[59].min));
  TF_copy_u8(&packet[65], (uint8_t)(app_manager->ais[59].max));
  TF_copy_u8(&packet[66], (uint8_t)(app_manager->ais[60].init_duration));
  TF_copy_u8(&packet[67], (uint8_t)(app_manager->ais[60].prev));
  TF_copy_u8(&packet[68], (uint8_t)(app_manager->ais[60].min));
  TF_copy_u8(&packet[69], (uint8_t)(app_manager->ais[60].max));
  TF_copy_u8(&packet[70], (uint8_t)(app_manager->ais[61].init_duration));
  TF_copy_u8(&packet[71], (uint8_t)(app_manager->ais[61].prev));
  TF_copy_u8(&packet[72], (uint8_t)(app_manager->ais[61].min));
  TF_copy_u8(&packet[73], (uint8_t)(app_manager->ais[61].max));
  TF_copy_u8(&packet[74], (uint8_t)(app_manager->ais[62].init_duration));
  TF_copy_u8(&packet[75], (uint8_t)(app_manager->ais[62].prev));
  TF_copy_u8(&packet[76], (uint8_t)(app_manager->ais[62].min));
  TF_copy_u8(&packet[77], (uint8_t)(app_manager->ais[62].max));
  TF_copy_u8(&packet[78], (uint8_t)(app_manager->ais[63].init_duration));
  TF_copy_u8(&packet[79], (uint8_t)(app_manager->ais[63].prev));
  TF_copy_u8(&packet[80], (uint8_t)(app_manager->ais[63].min));
  TF_copy_u8(&packet[81], (uint8_t)(app_manager->ais[63].max));
  TF_copy_u8(&packet[82], (uint8_t)(app_manager->ais[64].init_duration));
  TF_copy_u8(&packet[83], (uint8_t)(app_manager->ais[64].prev));
  TF_copy_u8(&packet[84], (uint8_t)(app_manager->ais[64].min));
  TF_copy_u8(&packet[85], (uint8_t)(app_manager->ais[64].max));
  TF_copy_u8(&packet[86], (uint8_t)(app_manager->ais[65].init_duration));
  TF_copy_u8(&packet[87], (uint8_t)(app_manager->ais[65].prev));
  TF_copy_u8(&packet[88], (uint8_t)(app_manager->ais[65].min));
  TF_copy_u8(&packet[89], (uint8_t)(app_manager->ais[65].max));
  TF_copy_u8(&packet[90], (uint8_t)(app_manager->ais[66].init_duration));
  TF_copy_u8(&packet[91], (uint8_t)(app_manager->ais[66].prev));
  TF_copy_u8(&packet[92], (uint8_t)(app_manager->ais[66].min));
  TF_copy_u8(&packet[93], (uint8_t)(app_manager->ais[66].max));
  TF_copy_u8(&packet[94], (uint8_t)(app_manager->ais[67].init_duration));
  TF_copy_u8(&packet[95], (uint8_t)(app_manager->ais[67].prev));
  TF_copy_u8(&packet[96], (uint8_t)(app_manager->ais[67].min));
  TF_copy_u8(&packet[97], (uint8_t)(app_manager->ais[67].max));
  TF_copy_u8(&packet[98], (uint8_t)(app_manager->ais[68].init_duration));
  TF_copy_u8(&packet[99], (uint8_t)(app_manager->ais[68].prev));
  TF_copy_u8(&packet[100], (uint8_t)(app_manager->ais[68].min));
  TF_copy_u8(&packet[101], (uint8_t)(app_manager->ais[68].max));
  TF_copy_u8(&packet[102], (uint8_t)(app_manager->ais[69].init_duration));
  TF_copy_u8(&packet[103], (uint8_t)(app_manager->ais[69].prev));
  TF_copy_u8(&packet[104], (uint8_t)(app_manager->ais[69].min));
  TF_copy_u8(&packet[105], (uint8_t)(app_manager->ais[69].max));
  TF_copy_u8(&packet[106], (uint8_t)(app_manager->ais[70].init_duration));
  TF_copy_u8(&packet[107], (uint8_t)(app_manager->ais[70].prev));
  TF_copy_u8(&packet[108], (uint8_t)(app_manager->ais[70].min));
  TF_copy_u8(&packet[109], (uint8_t)(app_manager->ais[70].max));
  TF_copy_u8(&packet[110], (uint8_t)(app_manager->ais[71].init_duration));
  TF_copy_u8(&packet[111], (uint8_t)(app_manager->ais[71].prev));
  TF_copy_u8(&packet[112], (uint8_t)(app_manager->ais[71].min));
  TF_copy_u8(&packet[113], (uint8_t)(app_manager->ais[71].max));
  TF_copy_u8(&packet[114], (uint8_t)(app_manager->ais[72].init_duration));
  TF_copy_u8(&packet[115], (uint8_t)(app_manager->ais[72].prev));
  TF_copy_u8(&packet[116], (uint8_t)(app_manager->ais[72].min));
  TF_copy_u8(&packet[117], (uint8_t)(app_manager->ais[72].max));
  TF_copy_u8(&packet[118], (uint8_t)(app_manager->ais[73].init_duration));
  TF_copy_u8(&packet[119], (uint8_t)(app_manager->ais[73].prev));
  TF_copy_u8(&packet[120], (uint8_t)(app_manager->ais[73].min));
  TF_copy_u8(&packet[121], (uint8_t)(app_manager->ais[73].max));
  TF_copy_u8(&packet[122], (uint8_t)(app_manager->ais[74].init_duration));
  TF_copy_u8(&packet[123], (uint8_t)(app_manager->ais[74].prev));
  TF_copy_u8(&packet[124], (uint8_t)(app_manager->ais[74].min));
  TF_copy_u8(&packet[125], (uint8_t)(app_manager->ais[74].max));
  TF_copy_u8(&packet[126], (uint8_t)(app_manager->ais[75].init_duration));
  TF_copy_u8(&packet[127], (uint8_t)(app_manager->ais[75].prev));
  TF_copy_u8(&packet[128], (uint8_t)(app_manager->ais[75].min));
  TF_copy_u8(&packet[129], (uint8_t)(app_manager->ais[75].max));
  TF_copy_u8(&packet[130], (uint8_t)(app_manager->ais[76].init_duration));
  TF_copy_u8(&packet[131], (uint8_t)(app_manager->ais[76].prev));
  TF_copy_u8(&packet[132], (uint8_t)(app_manager->ais[76].min));
  TF_copy_u8(&packet[133], (uint8_t)(app_manager->ais[76].max));
  TF_copy_u8(&packet[134], (uint8_t)(app_manager->ais[77].init_duration));
  TF_copy_u8(&packet[135], (uint8_t)(app_manager->ais[77].prev));
  TF_copy_u8(&packet[136], (uint8_t)(app_manager->ais[77].min));
  TF_copy_u8(&packet[137], (uint8_t)(app_manager->ais[77].max));
  TF_copy_u8(&packet[138], (uint8_t)(app_manager->ais[78].init_duration));
  TF_copy_u8(&packet[139], (uint8_t)(app_manager->ais[78].prev));
  TF_copy_u8(&packet[140], (uint8_t)(app_manager->ais[78].min));
  TF_copy_u8(&packet[141], (uint8_t)(app_manager->ais[78].max));
  TF_copy_u8(&packet[142], (uint8_t)(app_manager->ais[79].init_duration));
  TF_copy_u8(&packet[143], (uint8_t)(app_manager->ais[79].prev));
  TF_copy_u8(&packet[144], (uint8_t)(app_manager->ais[79].min));
  TF_copy_u8(&packet[145], (uint8_t)(app_manager->ais[79].max));
#endif

  *len = 146;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA_SET1_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA_SET2_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA_READ1_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA_READ2_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_STT_GYRO_EKF1_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_STT_GYRO_EKF2_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_GPSR_RANGE_P1_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_GPSR_RANGE_P2_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_ORBIT2_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_FILTERS_2_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_DR_ALGORITHM_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_RW_DETAILED_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA1_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA2_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA3_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA4_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

static TF_TLM_FUNC_ACK Tlm_AOBC_SAGITTA5_(uint8_t* packet, uint16_t* len, uint16_t max_len)
{
  if (26 > max_len) return TF_TLM_FUNC_ACK_TOO_SHORT_LEN;

#ifndef BUILD_SETTINGS_FAST_BUILD
#endif

  *len = 26;
  return TF_TLM_FUNC_ACK_SUCCESS;
}

#pragma section

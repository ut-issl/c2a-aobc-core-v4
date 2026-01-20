cmake_minimum_required(VERSION 3.13)

project(C2A_USER_CMD_TLM)

set(C2A_SRCS
  block_command_definitions.c
  block_command_user_settings.c
  command_definitions.c
  telemetry_definitions.c
  user_packet_handler.c
  # common_cmd_packet.c
  # common_tlm_cmd_packet.c
  # common_tlm_packet.c
  normal_block_command_definition/nbc_start_hk_tlm.c
  # normal_block_command_definition/nbc_mpu9250.c
  # normal_block_command_definition/nbc_rm3100.c
  # normal_block_command_definition/nbc_nanossoc_d60.c
  # normal_block_command_definition/nbc_stim210.c
  # normal_block_command_definition/nbc_sagitta.c
  # normal_block_command_definition/nbc_oem7600.c
  # normal_block_command_definition/nbc_mtq.c
  # normal_block_command_definition/nbc_rw0003.c
  # normal_block_command_definition/nbc_ina260.c
)

if(C2A_BUILD_AS_CXX)
  set_source_files_properties(${C2A_SRCS} PROPERTIES LANGUAGE CXX)  # C++
endif()

add_library(${PROJECT_NAME} OBJECT ${C2A_SRCS})

include(${C2A_USER_DIR}/common.cmake)
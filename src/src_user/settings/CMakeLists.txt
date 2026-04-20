cmake_minimum_required(VERSION 3.13)

project(C2A_USER_SETTINGS)

set(C2A_SRCS
  component_driver/hal_handler_registry.c
  # Settings
  # Applications/NvmParams/non_volatile_memory_normal_parameters.c
  # Applications/NvmParams/non_volatile_memory_redundant_parameters.c
  modes/mode_definitions.c
  # TaskList
  # modes/task_lists/tl_bdot.c
  modes/task_lists/tl_start_up.c
  modes/task_lists/tl_initial.c
  # modes/task_lists/tl_rough_sun_pointing.c
  # modes/task_lists/tl_rough_three_axis.c
  # modes/task_lists/tl_rough_three_axis_rw.c
  # modes/task_lists/tl_fine_three_axis.c
  
  modes/task_lists/elements/tl_elem_debug_display.c
  # modes/task_lists/elements/tl_elem_drivers_update.c
  # modes/task_lists/elements/tl_elem_gs_related_process.c
  modes/task_lists/elements/tl_elem_tlm_cmd_hirate.c
  modes/task_lists/elements/tl_elem_cdh_update.c
  # modes/task_lists/elements/tl_elem_inertial_ref_update.c
  # modes/task_lists/elements/tl_elem_sun_vector_update.c
  # modes/task_lists/elements/tl_elem_mtq_update.c
  # modes/task_lists/elements/tl_elem_basic_sensor_update.c
  # modes/task_lists/elements/tl_elem_rw_update.c
  # modes/task_lists/elements/tl_elem_rm3100_update.c
  # modes/task_lists/elements/tl_elem_stim210_update.c
  # modes/task_lists/elements/tl_elem_oem7600_update.c
  # modes/task_lists/elements/tl_elem_stt_update.c
  # system
  system/event_logger_settings.c
  system/event_handler_rules/event_handler_rules.c
  # system/event_handler_rules/event_handler_rule_tlmcmd.c
  # system/event_handler_rules/event_handler_rule_hw_oc.c
  # system/event_handler_rules/event_handler_rule_sw_oc.c
  # Transition
  modes/transitions/sl_nop.c
  modes/transitions/sl_initial.c
  # modes/transitions/sl_bdot.c
  # modes/transitions/sl_rough_sun_pointing.c
  # modes/transitions/sl_rough_three_axis.c
  # modes/transitions/sl_rough_three_axis_rw.c
  # modes/transitions/sl_fine_three_axis.c
  # TlmCmd
  tlm_cmd/common_cmd_packet_define.c
  tlm_cmd/common_tlm_packet_define.c
  tlm_cmd/ccsds/apid_define.c
  # Satellite Parameters
  # ${C2A_SATELLITE_PARAMETERS_DIR}/orbit_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/structure_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/attitude_target_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/attitude_determination_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/attitude_control_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/fdir_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/ina260_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/mpu9250_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/rm3100_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/nanossoc_d60_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/oem7600_parameters.c
  SatelliteParameters/stim377h_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/sagitta_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/seiren_mtq_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/rw0003_parameters.c
  # ${C2A_SATELLITE_PARAMETERS_DIR}/component_selector_parameters.c
)

if(C2A_BUILD_AS_CXX)
  set_source_files_properties(${C2A_SRCS} PROPERTIES LANGUAGE CXX)  # C++
endif()

add_library(${PROJECT_NAME} OBJECT ${C2A_SRCS})

include(${C2A_USER_DIR}/common.cmake)
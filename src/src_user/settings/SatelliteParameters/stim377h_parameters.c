#pragma section REPRO
/**
 * @file  stim377h_parameters.c
 * @brief STIM377Hに関する衛星固有パラメータを管理する
 */

#include "stim377h_parameters.h"

// Gyro Bias and scale factor temperature calibration
const float STIM377H_PARAMETERS_temperature_range_high_degC = 60.0f;
const float STIM377H_PARAMETERS_temperature_range_low_degC  = -40.0f;

const float STIM377H_PARAMETERS_bias_coeff_compo_x[STIM377H_PARAMETERS_kNumCoeffTempCalib]         = {0.0f, 0.0f};
const float STIM377H_PARAMETERS_scale_factor_coeff_compo_x[STIM377H_PARAMETERS_kNumCoeffTempCalib] = {1.0f, 0.0f};
const float STIM377H_PARAMETERS_bias_coeff_compo_y[STIM377H_PARAMETERS_kNumCoeffTempCalib]         = {0.0f, 0.0f};
const float STIM377H_PARAMETERS_scale_factor_coeff_compo_y[STIM377H_PARAMETERS_kNumCoeffTempCalib] = {1.0f, 0.0f};
const float STIM377H_PARAMETERS_bias_coeff_compo_z[STIM377H_PARAMETERS_kNumCoeffTempCalib]         = {0.0f, 0.0f};
const float STIM377H_PARAMETERS_scale_factor_coeff_compo_z[STIM377H_PARAMETERS_kNumCoeffTempCalib] = {1.0f, 0.0f};

// Gyro filter
const float   STIM377H_PARAMETERS_gyro_cut_off_freq_lpf_1st_Hz[PHYSICAL_CONST_THREE_DIM]                        = {100.0f, 100.0f, 100.0f};
const uint8_t STIM377H_PARAMETERS_gyro_spike_count_limit_to_accept[PHYSICAL_CONST_THREE_DIM]                    = {3, 3, 3};
const uint8_t STIM377H_PARAMETERS_gyro_spike_count_limit_to_reject_continued_warning[PHYSICAL_CONST_THREE_DIM]  = {60, 60, 60};
const float   STIM377H_PARAMETERS_gyro_spike_reject_threshold_rad_s[PHYSICAL_CONST_THREE_DIM]                   = {0.5f, 0.5f, 0.5f};
const float   STIM377H_PARAMETERS_gyro_spike_amplitude_limit_to_accept_as_step_rad_s[PHYSICAL_CONST_THREE_DIM]  = {1.0f, 1.0f, 1.0f};

// Magnetic sensor bias calibration
const float STIM377H_mag_bias_rm3100_ext_compo_nT[PHYSICAL_CONST_THREE_DIM] = {0.0f, 0.0f, 0.0f};

#pragma section

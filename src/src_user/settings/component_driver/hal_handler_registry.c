#pragma section REPRO
#include "hal_handler_registry.h"

#include <stddef.h>

int (*HAL_init_handlers[])(void* config) = { UART_init, I2C_init };

int (*HAL_rx_handlers[])(void* config, void* buffer, int buffer_size) = { UART_rx, I2C_rx };

int (*HAL_tx_handlers[])(void* config, void* data, int data_size) = { UART_tx, I2C_tx };

int (*HAL_reopen_handlers[])(void* config, int reason) = { UART_reopen, I2C_reopen };

#pragma section

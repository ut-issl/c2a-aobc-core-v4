#pragma section REPRO

#ifdef __cplusplus
extern "C" {
#endif


#include "../GPIO.h"

int GPIO_set_direction(const uint8_t port, const GPIO_DIRECTION direction)
{
  return (int)GPIO_OK;
}

int GPIO_set_output(const uint8_t port, const GPIO_HL output)
{
  return (int)GPIO_OK;
}

int GPIO_read_input(const uint8_t port)
{
  return (int)GPIO_OK;
}

#ifdef __cplusplus
}
#endif

#pragma section

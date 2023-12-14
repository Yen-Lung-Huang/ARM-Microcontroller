/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CORE_H
#define CORE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "usart.h"
#include "cJSON.h"
#include "servo.h"
#include "74HC595.h"
#include "motor_shield_v1.h"


/* FUNCTION (Prototype) DEFINITIONS */
void core_config(void);
float map(float x, float in_min, float in_max, float out_min, float out_max);
double max(double a, double b);
void print_binary(uint8_t byteData);
bool json_action(char *JSON_STRING, uint16_t token_size);

extern Motor_Shield_V1 my_motor_shield;

#ifdef __cplusplus
}
#endif

#endif /* CORE_H */

/*****END OF FILE*****/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SERVO_H
#define SERVO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"
#include "tim.h"

#define servo_init(...) servo_constructor((ServoTypeDef){.pwm_min=25, .pwm_max=125, .pwm_value=0, .physical_min=-90, .physical_max=90, .reverse=false, __VA_ARGS__});

typedef struct{
	TIM_HandleTypeDef* timer;
	uint32_t channel;
	unsigned int pwm_min;
	unsigned int pwm_max;
	unsigned int pwm_value;
	short int physical_min;
	short int physical_max;
	bool reverse;
}ServoTypeDef;


extern uint32_t last_time;
extern uint32_t sub_last_time;
extern bool rotate_dir;
extern uint8_t selected_servo;
extern uint8_t selected_servo_prev;
extern ServoTypeDef servo[6];


ServoTypeDef servo_constructor(ServoTypeDef servo_struct);
volatile uint32_t* timer_ch2ccr(TIM_HandleTypeDef* timer, uint32_t channel);
void servo_pwm_set(ServoTypeDef* servo, unsigned int pwm_value);
void json2servo(char *JSON_STRING, uint16_t token_size );

#ifdef __cplusplus
}
#endif

#endif /* SERVO_H */

/*****END OF FILE*****/

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
#include <math.h>
#include "main.h"
#include "tim.h"


#define servo_init(...) servo_constructor((ServoTypeDef){.pwm_min=25, .pwm_max=125, .pwm_value=0, .physical_min=-90, .physical_max=90,\
												.offset=0, .reverse=false, .complementary=false, .latch=false, .return_pwm=75, __VA_ARGS__});

typedef struct{
	TIM_HandleTypeDef* timer;
	uint32_t channel;
	uint16_t pwm_min;
	uint16_t pwm_max;
	uint16_t pwm_value;
	short int physical_min;
	short int physical_max;
	short int offset;
	bool reverse;
	bool complementary;
	bool latch;
	uint16_t return_pwm;
}ServoTypeDef;

extern uint32_t last_time;
extern uint32_t sub_last_time;
extern bool rotate_dir;
extern uint8_t selected_servo;
extern uint8_t selected_servo_prev;

ServoTypeDef servo_constructor(ServoTypeDef servo_struct);
volatile uint32_t* timer_ch2ccr(TIM_HandleTypeDef* timer, uint32_t channel);
void servos_init(ServoTypeDef servo[12]);

float map(float x, float in_min, float in_max, float out_min, float out_max);
double max(double a, double b);

uint16_t reverse_pwm(ServoTypeDef* servo, uint16_t pwm_value);
void servo_pwm_stop(ServoTypeDef* servo);
void arm_pwm_stop(void);
void all_pwm_stop(void);
void servo_pwm_set(ServoTypeDef* servo, uint16_t pwm_value);
void servo_wild_set(ServoTypeDef* servo, uint16_t pwm_value);
void servo_degree_set(ServoTypeDef* servo, float degree);
float servo_get_degree(ServoTypeDef* servo);

void arm_pwm_set(uint16_t pwm_dest[5]);
void arm_set(uint16_t pwm_0, uint16_t pwm_1, uint16_t pwm_2, uint16_t pwm_3, uint16_t pwm_4);
void shoulder_set(uint16_t pwm_value);

#ifdef __cplusplus
}
#endif

#endif /* SERVO_H */

/*****END OF FILE*****/

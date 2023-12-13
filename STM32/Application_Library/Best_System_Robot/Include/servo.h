/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SERVO_H
#define SERVO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "main.h"


#define servo_init(...) servo_constructor((ServoTypeDef){.pwm_min=25, .pwm_max=125, .pwm_value=0,\
																	.physical_min=-90, .physical_max=90, .offset=0, .return_pwm=75,\
																	.reverse=false, .complementary=false, .latch=false, __VA_ARGS__});

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


typedef struct{
	uint16_t destination;
	uint16_t current;
	uint16_t difference;
	bool crescendo;
	float interval_time;
	uint16_t last_time;
}PwmTypeDef;

typedef struct{
	float destination;
	float current;
	float difference;
	bool crescendo;
	float interval_time;
	uint16_t last_time;
}PhysicalTypeDef;

extern uint32_t last_time;
extern uint32_t sub_last_time;
extern bool rotate_dir;
extern uint8_t selected_servo;
extern uint8_t selected_servo_prev;

ServoTypeDef servo_constructor(ServoTypeDef servo_struct);
volatile uint32_t* timer_ch2ccr(TIM_HandleTypeDef* timer, uint32_t channel);
void servos_init(ServoTypeDef servo_test);
void servos_pwm_init(void);
uint16_t reverse_pwm(ServoTypeDef* servo, uint16_t pwm_value);
float reverse_physical(ServoTypeDef* servo, float physical_value);
void servo_pwm_set(ServoTypeDef* servo, uint16_t pwm_value);
void servo_wild_set(ServoTypeDef* servo, uint16_t pwm_value);
void servo_physical_set(ServoTypeDef* servo, float degree);
float servo_get_physical(ServoTypeDef* servo);
void servo_pwm_stop(ServoTypeDef* servo);
void all_pwm_stop(void);




#ifdef __cplusplus
}
#endif

#endif /* SERVO_H */

/*****END OF FILE*****/

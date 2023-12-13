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
#include <stdarg.h>
#include <math.h>
#include "tim.h"


#define servo_init(...) pwm_constructor((PWM_TypeDef){.pwm_min=25, .pwm_max=125, .pwm_value=0,\
																					.physical_min=-90, .physical_max=90, .offset=0,\
																					.reverse=false, .complementary=false, .latch=false, __VA_ARGS__});

#define pwm_set(...) pwm_set_func(__VA_ARGS__)

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
}PWM_TypeDef;


//typedef struct{
//	uint16_t destination;
//	uint16_t current;
//	uint16_t difference;
//	bool crescendo;
//	float interval_time;
//	uint16_t last_time;
//}PwmTypeDef;

//typedef struct{
//	float destination;
//	float current;
//	float difference;
//	bool crescendo;
//	float interval_time;
//	uint16_t last_time;
//}PhysicalTypeDef;

//extern uint32_t last_time;
//extern uint32_t sub_last_time;
//extern bool rotate_dir;
//extern uint8_t selected_servo;
//extern uint8_t selected_servo_prev;

PWM_TypeDef pwm_constructor(PWM_TypeDef pwm_struct);
volatile uint32_t* timer_ch2ccr(TIM_HandleTypeDef* timer, uint32_t channel);
uint16_t reverse_pwm(PWM_TypeDef* servo, uint16_t pwm_value);
float reverse_physical(PWM_TypeDef* servo, float physical_value);
int pwm_set_func(PWM_TypeDef* servo, ...);
void pwm_physical_set(PWM_TypeDef* servo, float degree);
void pwm_stop(PWM_TypeDef* servo);
void all_pwm_stop(void);
float get_pwm_physical(PWM_TypeDef* servo);
uint16_t get_limit_pwm(PWM_TypeDef* servo);




#ifdef __cplusplus
}
#endif

#endif /* SERVO_H */

/*****END OF FILE*****/

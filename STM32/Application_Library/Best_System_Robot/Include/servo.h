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
#include "tim.h"


#define servo_init(...) pwm_constructor((PWM_TypeDef){.pwm_min=25, .pwm_max=125, .pwm_value=0,\
																					.physical_min=-90, .physical_max=90, .offset=0,\
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
}PWM_TypeDef;


extern PWM_TypeDef servo[];

// Define an enum type variable to store the robot arm servos names and values
enum robot_servo {S1, S2, S3};

// Define an enum type variable to store the servo control modes
enum pwm_control_mode {PWM, ANGLE};

PWM_TypeDef pwm_constructor(PWM_TypeDef pwm_struct);
void servos_init(void);
float map(float x, float in_min, float in_max, float out_min, float out_max);
volatile uint32_t* timer_ch2ccr(TIM_HandleTypeDef* timer, uint32_t channel);
uint16_t reverse_pwm(PWM_TypeDef* servo, uint16_t pwm_value);
float reverse_physical(PWM_TypeDef* servo, float physical_value);
void pwm_set(PWM_TypeDef* servo, uint16_t pwm_value, bool limit);

void pwm_physical_set(PWM_TypeDef *servo, float physical_value, bool limit);
void servo_control(PWM_TypeDef *servo, float servo_input, bool mode, bool limit);
void pwm_stop(PWM_TypeDef* servo);
void all_pwm_stop(void);

float get_pwm_physical(PWM_TypeDef* servo);
uint16_t get_limit_pwm(PWM_TypeDef* servo);


#ifdef __cplusplus
}
#endif

#endif /* SERVO_H */

/*****END OF FILE*****/

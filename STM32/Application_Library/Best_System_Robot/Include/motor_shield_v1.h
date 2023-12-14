/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MOTOR_SHIELD_V1_H
#define MOTOR_SHIELD_V1_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include "servo.h"
#include "74HC595.h"
#include "tim.h"

// Define a structure for Motor_Shield_V1
typedef struct {
	HC595 hc595;
	PWM_TypeDef M1_PWM;      // PWM signal for motor 1
	PWM_TypeDef M2_PWM;      // PWM signal for motor 2
	PWM_TypeDef M3_PWM;      // PWM signal for motor 3
	PWM_TypeDef M4_PWM;      // PWM signal for motor 4
	PWM_TypeDef S1_PWM;      // PWM signal for servo 1
	PWM_TypeDef S2_PWM;      // PWM signal for servo 2
} Motor_Shield_V1;

// Declare the global objects with extern keyword
extern Motor_Shield_V1 motor_shield_v1;


/* FUNCTION (Prototype) DEFINITIONS */
void motor_shield_v1_pwm_init(void);


#ifdef __cplusplus
}
#endif

#endif /* MOTOR_SHIELD_V1_H */

/*****END OF FILE*****/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MOTOR_SHIELD_V1_H
#define MOTOR_SHIELD_V1_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include "servo.h"
#include "74HC595.h"


// Define a structure for Motor_Shield_V1
typedef struct {
	HC595 hc595;
	ServoTypeDef M1_PWM;      // PWM signal for motor 1
	ServoTypeDef M2_PWM;      // PWM signal for motor 2
	ServoTypeDef M3_PWM;      // PWM signal for motor 3
	ServoTypeDef M4_PWM;      // PWM signal for motor 4
	ServoTypeDef S1_PWM;      // PWM signal for servo 1
	ServoTypeDef S2_PWM;      // PWM signal for servo 2
} Motor_Shield_V1;

extern Motor_Shield_V1 motor_shield_v1;

/* FUNCTION (Prototype) DEFINITIONS */
//e.g. void hello_world(void)...


#ifdef __cplusplus
}
#endif

#endif /* MOTOR_SHIELD_V1_H */

/*****END OF FILE*****/

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


// Define an enum type variable to store the motor names and values
enum motor_shield_v1_motor {M1 = 1, M2, M3, M4};

// Define an enum type variable to store the servo names and values
// enum motor_shield_v1_servo {S1, S2};


/* FUNCTION (Prototype) DEFINITIONS */
void ms1_pwm_init(void);
void ms1_motor_control(Motor_Shield_V1 *motor_shield, uint8_t dc_motor_number, float motor_input);
void ms1_servo_control(Motor_Shield_V1 *motor_shield, uint8_t servo_number, float servo_input, bool mode);

#ifdef __cplusplus
}
#endif

#endif /* MOTOR_SHIELD_V1_H */

/*****END OF FILE*****/

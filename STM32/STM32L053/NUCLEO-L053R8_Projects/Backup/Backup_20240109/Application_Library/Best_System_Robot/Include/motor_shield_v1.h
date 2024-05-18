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

// Define a structure for EN pin
typedef struct {
	My_GPIO_TypeDef GPIO; // GPIO for EN pin
	PWM_TypeDef PWM;      // PWM for EN pin
	bool enable_pwm;      // Enable PWM mode or not
} DC_Motor_EN_TypeDef;

// Define a structure for DC motor
typedef struct {
	My_GPIO_TypeDef IN1;    // GPIO for IN1 pin
	My_GPIO_TypeDef IN2;    // GPIO for IN2 pin
	DC_Motor_EN_TypeDef EN; // Enable signal for DC motor
} DC_Motor_TypeDef;

// Define a structure for Motor_Shield_V1
typedef struct {
	HC595 hc595;
	DC_Motor_TypeDef M1; // Enable signal for motor 1
	DC_Motor_TypeDef M2; // Enable signal for motor 2
	DC_Motor_TypeDef M3; // Enable signal for motor 3
	DC_Motor_TypeDef M4; // Enable signal for motor 4
	PWM_TypeDef S1_PWM;  // PWM signal for servo 1
	PWM_TypeDef S2_PWM;  // PWM signal for servo 2
} Motor_Shield_V1;

// Define a structure for Motor_Shield_l29xx
typedef struct {
	DC_Motor_TypeDef M1; // Enable signal for motor 1
	DC_Motor_TypeDef M2; // Enable signal for motor 2
	DC_Motor_TypeDef M3; // Enable signal for motor 3
	DC_Motor_TypeDef M4; // Enable signal for motor 4
} Motor_Shield_L29XX;

// Define a structure for L293D、l298P、L298N
typedef struct {
	DC_Motor_TypeDef M1; // DC motor 1
	DC_Motor_TypeDef M2; // DC motor 2
} L29XX;


// Declare the global objects with extern keyword
extern Motor_Shield_V1 motor_shield_v1;
extern Motor_Shield_L29XX motor_shield_l29xx;

// Define an enum type to indicate the type of motor shield
enum Motor_Shield_Type {MS_V1, MS_L29XX};

// Define an enum type variable to store the motor names and values
enum motor_shield_v1_motor {M1 = 1, M2, M3, M4};

// Define an enum type variable to store the servo names and values
// enum motor_shield_v1_servo {S1, S2};


/* FUNCTION (Prototype) DEFINITIONS */
void ms_init(enum Motor_Shield_Type type, bool enable_pwm);
void ms_pwm_init(enum Motor_Shield_Type type);
void ms_gpio_init(enum Motor_Shield_Type type);

void ms_motor_control(void *motor_shield, enum Motor_Shield_Type type, uint8_t dc_motor_number, float motor_input);
void ms_v1_servo_control(Motor_Shield_V1 *motor_shield, uint8_t servo_number, float servo_input, bool mode);

#ifdef __cplusplus
}
#endif

#endif /* MOTOR_SHIELD_V1_H */

/*****END OF FILE*****/

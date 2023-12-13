#include "motor_shield_v1.h"

// Declare a Motor_Shield_V1 structure with the defined ports and pins
Motor_Shield_V1 motor_shield_v1 = {
	.hc595 = { // Assign the values of HC595 structure
		.LATCH_Port = GPIOA, .LATCH_Pin = GPIO_PIN_6,
		.CLOCK_Port = GPIOB, .CLOCK_Pin = GPIO_PIN_5,
		.DATA_Port  = GPIOA, .DATA_Pin  = GPIO_PIN_9
	}
};

// Initialize the servos with servo_constructor function
void motor_shield_v1_pwm_init() {
	motor_shield_v1.M1_PWM = servo_constructor((ServoTypeDef){.pwm_min=0, .pwm_max=999, .pwm_value=0,\
																	.physical_min=0, .physical_max=999, .offset=0, .return_pwm=0,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.M2_PWM = servo_constructor((ServoTypeDef){.pwm_min=25, .pwm_max=125, .pwm_value=0,\
																	.physical_min=-90, .physical_max=90, .offset=0, .return_pwm=75,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.M3_PWM = servo_constructor((ServoTypeDef){.pwm_min=25, .pwm_max=125, .pwm_value=0,\
																	.physical_min=-90, .physical_max=90, .offset=0, .return_pwm=75,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.M4_PWM = servo_constructor((ServoTypeDef){.pwm_min=25, .pwm_max=125, .pwm_value=0,\
																	.physical_min=-90, .physical_max=90, .offset=0, .return_pwm=75,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.S1_PWM = servo_constructor((ServoTypeDef){.pwm_min=25, .pwm_max=125, .pwm_value=0,\
																	.physical_min=-90, .physical_max=90, .offset=0, .return_pwm=75,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.S2_PWM = servo_constructor((ServoTypeDef){.pwm_min=25, .pwm_max=125, .pwm_value=0,\
																	.physical_min=-90, .physical_max=90, .offset=0, .return_pwm=75,\
																	.reverse=false, .complementary=false, .latch=false});
}

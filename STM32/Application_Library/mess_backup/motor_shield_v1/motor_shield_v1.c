#include "motor_shield_v1.h"

/* Motor_Shield_V1 Configuration--------------------------------------------------------*/

// Declare a Motor_Shield_V1 structure with the defined ports and pins
Motor_Shield_V1 motor_shield_v1 = {
	.hc595 = { // Assign the values of HC595 structure
		.LATCH_Port = GPIOA, .LATCH_Pin = GPIO_PIN_6,
		.CLOCK_Port = GPIOB, .CLOCK_Pin = GPIO_PIN_5,
		.DATA_Port  = GPIOA, .DATA_Pin  = GPIO_PIN_9
	}
};

// Initialize the servos with pwm_constructor function
void ms1_pwm_init(void) { // The timers are for NUCLEO-F446RE.
	motor_shield_v1.M1_PWM = pwm_constructor((PWM_TypeDef){.timer=&htim3, .channel=TIM_CHANNEL_2, .pwm_min=0,\
																	.pwm_max=999, .physical_min=0, .physical_max=999, .offset=0,.pwm_value=0,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.M2_PWM = pwm_constructor((PWM_TypeDef){.timer=&htim2, .channel=TIM_CHANNEL_2, .pwm_min=0,\
																	.pwm_max=999, .physical_min=0, .physical_max=999, .offset=0,.pwm_value=0,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.M3_PWM = pwm_constructor((PWM_TypeDef){.timer=&htim3, .channel=TIM_CHANNEL_1, .pwm_min=0,\
																	.pwm_max=999, .physical_min=0, .physical_max=999, .offset=0,.pwm_value=0,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.M4_PWM = pwm_constructor((PWM_TypeDef){.timer=&htim2, .channel=TIM_CHANNEL_3, .pwm_min=0,\
																	.pwm_max=999, .physical_min=0, .physical_max=999, .offset=0,.pwm_value=0,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.S1_PWM = pwm_constructor((PWM_TypeDef){.timer=&htim4, .channel=TIM_CHANNEL_1, .pwm_min=26,\
																	.pwm_max=123, .physical_min=0, .physical_max=180, .offset=0,.pwm_value=0,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.S2_PWM = pwm_constructor((PWM_TypeDef){.timer=&htim8, .channel=TIM_CHANNEL_2, .pwm_min=26,\
																	.pwm_max=123, .physical_min=0, .physical_max=180, .offset=0,.pwm_value=0,\
																	.reverse=false, .complementary=false, .latch=false});
}

/* Motor_Shield_V1 Control--------------------------------------------------------*/

// Define a function to control the motor direction and speed
void ms1_motor_control(Motor_Shield_V1 *motor_shield, uint8_t dc_motor_number, bool direction, uint16_t pwm_speed) {
  // Check the validity of the arguments
  if (motor_shield == NULL) return; // Invalid pointer
  
	// Define an enum type variable to store the bit names and values
	enum motor_shield_v1_74hc595 {M4_A = 0, M2_A, M1_A, M1_B, M2_B, M3_A, M4_B, M3_B};
	
  // Select the corresponding PWM structure and the index of the bits to be set or cleared
  PWM_TypeDef *pwm = NULL;
  uint8_t out1, out2; // Declare the variables
	
  switch (dc_motor_number) { // Use a switch statement to assign different values
    case M1: // If dc_motor_number is M1
      pwm = &(motor_shield->M1_PWM); // Select the M1_PWM structure
      out1 = M1_A; // The lower bit of the pair
      out2 = M1_B; // The higher bit of the pair
      break; // Break the switch statement
    case M2: // If dc_motor_number is M2
      pwm = &(motor_shield->M2_PWM); // Select the M2_PWM structure
      out1 = M2_A; // The lower bit of the pair
      out2 = M2_B; // The higher bit of the pair
      break; // Break the switch statement
    case M3: // If dc_motor_number is M3
      pwm = &(motor_shield->M3_PWM); // Select the M3_PWM structure
      out1 = M3_A; // The lower bit of the pair
      out2 = M3_B; // The higher bit of the pair
      break; // Break the switch statement
    case M4: // If dc_motor_number is M4
      pwm = &(motor_shield->M4_PWM); // Select the M4_PWM structure
      out1 = M4_A; // The lower bit of the pair
      out2 = M4_B; // The higher bit of the pair
      break; // Break the switch statement
    default: // If dc_motor_number is not valid
      return; // Return from the function
  }
  
  // Set the PWM value
  pwm_set(pwm, pwm_speed);
  
  // Set or clear the bits according to the direction
  if (direction) { // Clockwise
    HC595_SetBit(&(motor_shield->hc595), out1, 1); // Set the lower bit to 1
    HC595_SetBit(&(motor_shield->hc595), out2, 0); // Clear the higher bit to 0
  } else { // Counterclockwise
    HC595_SetBit(&(motor_shield->hc595), out1, 0); // Clear the lower bit to 0
    HC595_SetBit(&(motor_shield->hc595), out2, 1); // Set the higher bit to 1
  }
}

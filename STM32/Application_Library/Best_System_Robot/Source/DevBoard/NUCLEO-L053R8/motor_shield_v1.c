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
void ms1_pwm_init(void) { // The timers are for NUCLEO-L053R8.
	motor_shield_v1.M1_PWM = pwm_constructor((PWM_TypeDef){.timer=&htim22, .channel=TIM_CHANNEL_2, .pwm_min=0,\
																	.pwm_max=999, .physical_min=0, .physical_max=999, .offset=0,.pwm_value=0,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.M2_PWM = pwm_constructor((PWM_TypeDef){.timer=&htim2, .channel=TIM_CHANNEL_2, .pwm_min=0,\
																	.pwm_max=999, .physical_min=0, .physical_max=999, .offset=0,.pwm_value=0,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.M3_PWM = pwm_constructor((PWM_TypeDef){.timer=&htim2, .channel=TIM_CHANNEL_3, .pwm_min=0,\
																	.pwm_max=999, .physical_min=0, .physical_max=999, .offset=0,.pwm_value=0,\
																	.reverse=false, .complementary=false, .latch=false});
	motor_shield_v1.M4_PWM = pwm_constructor((PWM_TypeDef){.timer=&htim22, .channel=TIM_CHANNEL_1, .pwm_min=0,\
																	.pwm_max=999, .physical_min=0, .physical_max=999, .offset=0,.pwm_value=0,\
																	.reverse=false, .complementary=false, .latch=false});
	
	// Since NUCLEO-L053R8 has insufficient PWM output on the servo pwm pin of motor shield v1, \
																	the timers and channels for servo pwm need to be self-defined.
	motor_shield_v1.S1_PWM = servo[S1];
	motor_shield_v1.S2_PWM = servo[S2];
}

/* Motor_Shield_V1 Control--------------------------------------------------------*/

// Define a function to control the motor direction and speed with one input
void ms1_motor_control(Motor_Shield_V1 *motor_shield, uint8_t dc_motor_number, float motor_input) {
  // Check the validity of the arguments
  if (motor_shield == NULL) return; // Invalid pointer
  
	// Define an enum type variable to store the bit names and values
	enum motor_shield_v1_74hc595 {M4_A = 0, M2_A, M1_A, M1_B, M2_B, M3_A, M4_B, M3_B};
	// enum motor_shield_v1_74hc595 {M3_A = 0, M2_A, M1_A, M1_B, M2_B, M4_A, M3_B, M4_B};
	
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
  
	float abs_motor_input = motor_input < 0 ? -motor_input : motor_input;
	if(abs_motor_input != 0 && abs_motor_input <= 1){
		abs_motor_input = map(abs_motor_input,0,1,pwm->pwm_min,pwm->pwm_max);
	}
  // Set the PWM value
  pwm_set(pwm, (int)abs_motor_input, true); // Use the absolute value of 
	// printf("pwm_input= %d\r\n",(int)abs_motor_input); // Print for debug.
  
  // Set or clear the bits according to the sign of motor_input
  if (motor_input > 0) { // Clockwise
    HC595_SendBit(&(motor_shield->hc595), out1, 1); // Set the lower bit to 1
    HC595_SendBit(&(motor_shield->hc595), out2, 0); // Clear the higher bit to 0
  } else if (motor_input < 0) { // Counterclockwise
    HC595_SendBit(&(motor_shield->hc595), out1, 0); // Clear the lower bit to 0
    HC595_SendBit(&(motor_shield->hc595), out2, 1); // Set the higher bit to 1
  } else { // Stop
    HC595_SendBit(&(motor_shield->hc595), out1, 0); // Clear the lower bit to 0
    HC595_SendBit(&(motor_shield->hc595), out2, 0); // Clear the higher bit to 0
  }
}

// Define a function to control the servo angle with one input
void ms1_servo_control(Motor_Shield_V1 *motor_shield, uint8_t servo_number, float servo_input, bool mode) { // Add a mode parameter
  // Check the validity of the arguments
  if (motor_shield == NULL) return; // Invalid pointer
  
  // Select the corresponding PWM structure
  PWM_TypeDef *pwm = NULL;
  
  switch (servo_number) { // Use a switch statement to assign different values
    case S1: // If servo_number is S1
      pwm = &(motor_shield->S1_PWM); // Select the S1_PWM structure
      break; // Break the switch statement
    case S2: // If servo_number is S2
      pwm = &(motor_shield->S2_PWM); // Select the S2_PWM structure
      break; // Break the switch statement
    default: // If servo_number is not valid
      return; // Return from the function
  }
  
  // Check the mode parameter
  if (mode == PWM) { // If the mode is PWM
    // Set the PWM value
    pwm_set(pwm, (int)servo_input, true); // Use the pwm_set function
  } else if (mode == ANGLE) { // If the mode is ANGLE
    // Set the PWM value according to the servo angle
    pwm_physical_set(pwm, servo_input, true); // Use the pwm_physical_set function
  } else { // If the mode is not valid
    return; // Return from the function
  }
}



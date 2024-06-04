#include "motor_shield_v1.h"

#define DC_MOTOR_MIN 0
#define DC_MOTOR_MAX 999

/* Motor_Shield_V1 Configuration--------------------------------------------------------*/

// Declare a Motor_Shield_V1 structure with the defined ports and pins
Motor_Shield_V1 motor_shield_v1;
Motor_Shield_L29XX motor_shield_l29xx;


// Initialize the motor shield
void ms_init(enum Motor_Shield_Type type, bool enable_pwm)
{
    if (type == MS_V1) { // If using Motor Shield V1
        // Initialize the HC595 pins
        gpio_pin_set(&motor_shield_v1.hc595.LATCH, GPIOA, GPIO_PIN_6);
        gpio_pin_set(&motor_shield_v1.hc595.CLOCK, GPIOB, GPIO_PIN_5);
        gpio_pin_set(&motor_shield_v1.hc595.DATA,  GPIOA, GPIO_PIN_9);

        // Initialize the servos with pwm_constructor function
        // Since NUCLEO-L053R8 has insufficient PWM output on the servo pwm pin of motor shield v1, \
        the timers and channels for servo pwm need to be self-defined.
        motor_shield_v1.S1_PWM = servo[S1];
        motor_shield_v1.S2_PWM = servo[S2];
    } else if (type == MS_L29XX) {
        gpio_pin_set(&motor_shield_l29xx.M1.IN1, GPIOB, GPIO_PIN_1 ); // M1_IN1: PB1
        gpio_pin_set(&motor_shield_l29xx.M1.IN2, GPIOB, GPIO_PIN_2 ); // M1_IN2: PB2
        gpio_pin_set(&motor_shield_l29xx.M2.IN1, GPIOC, GPIO_PIN_4 ); // M2_IN1: PC4
        gpio_pin_set(&motor_shield_l29xx.M2.IN2, GPIOB, GPIO_PIN_15); // M2_IN2: PB15
        gpio_pin_set(&motor_shield_l29xx.M3.IN1, GPIOA, GPIO_PIN_12); // M3_IN1: PA12
        gpio_pin_set(&motor_shield_l29xx.M3.IN2, GPIOC, GPIO_PIN_5 ); // M3_IN2: PC5
        gpio_pin_set(&motor_shield_l29xx.M4.IN1, GPIOB, GPIO_PIN_12); // M4_IN1: PB12
        gpio_pin_set(&motor_shield_l29xx.M4.IN2, GPIOA, GPIO_PIN_11); // M4_IN2: PA11
    }

    if (enable_pwm) { // If using PWM mode
        ms_pwm_init(type); // Call the ms_pwm_init function with the type parameter
    } else { // If using GPIO mode
        ms_gpio_init(type); // Call the ms_gpio_init function with the type parameter
    }
}

// Initialize the PWM mode for the motor shield
void ms_pwm_init(enum Motor_Shield_Type type)
{
    if (type == MS_V1) { // If using Motor Shield V1
        // The timers are for NUCLEO-L053R8.
        motor_shield_v1.M1.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer=&htim22, .channel=TIM_CHANNEL_2, .pwm_min=DC_MOTOR_MIN,\
                                     .pwm_max=DC_MOTOR_MAX, .physical_min=DC_MOTOR_MIN, .physical_max=DC_MOTOR_MAX, .offset=0,.pwm_value=0,\
                                              .reverse=false, .complementary=false, .latch=false
        });
        motor_shield_v1.M2.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer=&htim2, .channel=TIM_CHANNEL_2, .pwm_min=DC_MOTOR_MIN,\
                                    .pwm_max=DC_MOTOR_MAX, .physical_min=DC_MOTOR_MIN, .physical_max=DC_MOTOR_MAX, .offset=0,.pwm_value=0,\
                                             .reverse=false, .complementary=false, .latch=false
        });
        motor_shield_v1.M3.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer=&htim2, .channel=TIM_CHANNEL_3, .pwm_min=DC_MOTOR_MIN,\
                                    .pwm_max=DC_MOTOR_MAX, .physical_min=DC_MOTOR_MIN, .physical_max=DC_MOTOR_MAX, .offset=0,.pwm_value=0,\
                                             .reverse=false, .complementary=false, .latch=false
        });
        motor_shield_v1.M4.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer=&htim22, .channel=TIM_CHANNEL_1, .pwm_min=DC_MOTOR_MIN,\
                                     .pwm_max=DC_MOTOR_MAX, .physical_min=DC_MOTOR_MIN, .physical_max=DC_MOTOR_MAX, .offset=0,.pwm_value=0,\
                                              .reverse=false, .complementary=false, .latch=false
        });

        motor_shield_v1.M1.EN.enable_pwm = true;
        motor_shield_v1.M2.EN.enable_pwm = true;
        motor_shield_v1.M3.EN.enable_pwm = true;
        motor_shield_v1.M4.EN.enable_pwm = true;
    } else if (type == MS_L29XX) { // If using Motor Shield L29XX
        // The timers are for NUCLEO-L053R8.
        motor_shield_l29xx.M1.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer=&htim2, .channel=TIM_CHANNEL_2, .pwm_min=DC_MOTOR_MIN,\
                                    .pwm_max=DC_MOTOR_MAX, .physical_min=DC_MOTOR_MIN, .physical_max=DC_MOTOR_MAX, .offset=0,.pwm_value=0,\
                                             .reverse=false, .complementary=false, .latch=false
        });
        motor_shield_l29xx.M2.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer=&htim22, .channel=TIM_CHANNEL_2, .pwm_min=DC_MOTOR_MIN,\
                                     .pwm_max=DC_MOTOR_MAX, .physical_min=DC_MOTOR_MIN, .physical_max=DC_MOTOR_MAX, .offset=0,.pwm_value=0,\
                                              .reverse=false, .complementary=false, .latch=false
        });
        motor_shield_l29xx.M3.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer=&htim22, .channel=TIM_CHANNEL_1, .pwm_min=DC_MOTOR_MIN,\
                                     .pwm_max=DC_MOTOR_MAX, .physical_min=DC_MOTOR_MIN, .physical_max=DC_MOTOR_MAX, .offset=0,.pwm_value=0,\
                                              .reverse=false, .complementary=false, .latch=false
        });
        motor_shield_l29xx.M4.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer=&htim2, .channel=TIM_CHANNEL_1, .pwm_min=DC_MOTOR_MIN,\
                                    .pwm_max=DC_MOTOR_MAX, .physical_min=DC_MOTOR_MIN, .physical_max=DC_MOTOR_MAX, .offset=0,.pwm_value=0,\
                                             .reverse=false, .complementary=false, .latch=false
        });

        motor_shield_l29xx.M1.EN.enable_pwm = true;
        motor_shield_l29xx.M2.EN.enable_pwm = true;
        motor_shield_l29xx.M3.EN.enable_pwm = true;
        motor_shield_l29xx.M4.EN.enable_pwm = true;
    }
}

// Initialize the GPIO mode for the motor shield
void ms_gpio_init(enum Motor_Shield_Type type)
{
    if (type == MS_V1) { // If using Motor Shield V1
        // The pins are for NUCLEO-L053R8.
        gpio_pin_set(&motor_shield_v1.M1.EN.GPIO, GPIOA, GPIO_PIN_7 );
        gpio_pin_set(&motor_shield_v1.M2.EN.GPIO, GPIOB, GPIO_PIN_3 );
        gpio_pin_set(&motor_shield_v1.M3.EN.GPIO, GPIOB, GPIO_PIN_10);
        gpio_pin_set(&motor_shield_v1.M4.EN.GPIO, GPIOB, GPIO_PIN_4 );

        motor_shield_v1.M1.EN.enable_pwm = false;
        motor_shield_v1.M2.EN.enable_pwm = false;
        motor_shield_v1.M3.EN.enable_pwm = false;
        motor_shield_v1.M4.EN.enable_pwm = false;
    } else if (type == MS_L29XX) { // If using Motor Shield L29XX
        // The pins are for NUCLEO-L053R8.
        gpio_pin_set(&motor_shield_l29xx.M1.EN.GPIO, GPIOA, GPIO_PIN_1 );
        gpio_pin_set(&motor_shield_l29xx.M2.EN.GPIO, GPIOC, GPIO_PIN_7 );
        gpio_pin_set(&motor_shield_l29xx.M3.EN.GPIO, GPIOC, GPIO_PIN_6);
        gpio_pin_set(&motor_shield_l29xx.M4.EN.GPIO, GPIOA, GPIO_PIN_0 );

        motor_shield_l29xx.M1.EN.enable_pwm = false;
        motor_shield_l29xx.M2.EN.enable_pwm = false;
        motor_shield_l29xx.M3.EN.enable_pwm = false;
        motor_shield_l29xx.M4.EN.enable_pwm = false;
    }
}


/* Motor_Shield_V1 Control--------------------------------------------------------------*/

// Define a function to control the motor direction and speed with one input
void ms_motor_control(void *motor_shield, enum Motor_Shield_Type type, uint8_t dc_motor_number, float motor_input)
{
    // Check the validity of the arguments
    if (motor_shield == NULL) {
        return;    // Invalid pointer
    }

    // Define an enum type variable to store the bit names and values
    enum motor_shield_74hc595 {M4_A = 0, M2_A, M1_A, M1_B, M2_B, M3_A, M4_B, M3_B};

    // Declare a pointer variable to store the current motor structure
    DC_Motor_TypeDef *motor = NULL;
    // Declare a boolean variable to store the current mode
    bool pwm_mode = false;
    // Declare two variables to store the index of the bits to be set or cleared
    uint8_t out1, out2;

    switch (dc_motor_number) { // Use a switch statement to assign different values
    case M1: // If dc_motor_number is M1
        out1 = M1_A; // The lower bit of the pair
        out2 = M1_B; // The higher bit of the pair
        break; // Break the switch statement
    case M2: // If dc_motor_number is M2
        out1 = M2_A; // The lower bit of the pair
        out2 = M2_B; // The higher bit of the pair
        break; // Break the switch statement
    case M3: // If dc_motor_number is M3
        out1 = M3_A; // The lower bit of the pair
        out2 = M3_B; // The higher bit of the pair
        break; // Break the switch statement
    case M4: // If dc_motor_number is M4
        out1 = M4_A; // The lower bit of the pair
        out2 = M4_B; // The higher bit of the pair
        break; // Break the switch statement
    default: // If dc_motor_number is not valid
        return; // Return from the function
    }

    switch (type) { // Use a switch statement to select different motor shield types
    case MS_V1: // If using Motor Shield V1
        motor = &(((Motor_Shield_V1 *)motor_shield)->M1) + dc_motor_number - 1; // Select the corresponding motor structure
        pwm_mode = motor->EN.enable_pwm; // Select the corresponding mode
        break; // Break the switch statement
    case MS_L29XX: // If using Motor Shield L29XX
        motor = &(((Motor_Shield_L29XX *)motor_shield)->M1) + dc_motor_number - 1; // Select the corresponding motor structure
        pwm_mode = motor->EN.enable_pwm; // Select the corresponding mode
        break; // Break the switch statement
    default: // If the type is not valid
        return; // Return from the function
    }

    float abs_motor_input = motor_input < 0 ? -motor_input : motor_input;
    if(abs_motor_input != 0 && abs_motor_input <= 1) {
        if (pwm_mode) { // If PWM mode is enabled
            abs_motor_input = map(abs_motor_input,0,1,motor->EN.PWM.pwm_min,motor->EN.PWM.pwm_max); // Map the input to PWM range
        } else { // If GPIO mode is enabled
            abs_motor_input = map(abs_motor_input,0,1,0,1); // Map the input to 0 or 1
        }
    }
    // Set the PWM value or GPIO state
    if (pwm_mode) { // If PWM mode is enabled
        pwm_set(&(motor->EN.PWM), (int)abs_motor_input, true); // Use the absolute value of the input
    } else { // If GPIO mode is enabled
        HAL_GPIO_WritePin(motor->EN.GPIO.Port, motor->EN.GPIO.Pin, (int)abs_motor_input); // Use the absolute value of the input
    }

    // Set or clear the bits according to the sign of motor_input
    if (type == MS_V1) { // If using Motor Shield V1
        if (motor_input > 0) { // Clockwise
            HC595_SendBit(&(((Motor_Shield_V1 *)motor_shield)->hc595), out1, 1); // Set the lower bit to 1
            HC595_SendBit(&(((Motor_Shield_V1 *)motor_shield)->hc595), out2, 0); // Clear the higher bit to 0
        } else if (motor_input < 0) { // Counterclockwise
            HC595_SendBit(&(((Motor_Shield_V1 *)motor_shield)->hc595), out1, 0); // Clear the lower bit to 0
            HC595_SendBit(&(((Motor_Shield_V1 *)motor_shield)->hc595), out2, 1); // Set the higher bit to 1
        } else { // Stop
            HC595_SendBit(&(((Motor_Shield_V1 *)motor_shield)->hc595), out1, 0); // Clear the lower bit to 0
            HC595_SendBit(&(((Motor_Shield_V1 *)motor_shield)->hc595), out2, 0); // Clear the higher bit to 0
        }
    } else if (type == MS_L29XX) { // If using Motor Shield L29XX
        if (motor_input > 0) { // Clockwise
            HAL_GPIO_WritePin(motor->IN1.Port, motor->IN1.Pin, GPIO_PIN_SET); // Set the lower bit to high
            HAL_GPIO_WritePin(motor->IN2.Port, motor->IN2.Pin, GPIO_PIN_RESET); // Set the higher bit to low
        } else if (motor_input < 0) { // Counterclockwise
            HAL_GPIO_WritePin(motor->IN1.Port, motor->IN1.Pin, GPIO_PIN_RESET); // Set the lower bit to low
            HAL_GPIO_WritePin(motor->IN2.Port, motor->IN2.Pin, GPIO_PIN_SET); // Set the higher bit to high
        } else { // Stop
            HAL_GPIO_WritePin(motor->IN1.Port, motor->IN1.Pin, GPIO_PIN_RESET); // Set the lower bit to low
            HAL_GPIO_WritePin(motor->IN2.Port, motor->IN2.Pin, GPIO_PIN_RESET); // Set the higher bit to low
        }
    }
}


// Define a function to control the servo angle with one input
void ms_v1_servo_control(Motor_Shield_V1 *motor_shield, uint8_t servo_number, float servo_input, bool mode)   // Add a mode parameter
{
    // Check the validity of the arguments
    if (motor_shield == NULL) {
        return;    // Invalid pointer
    }

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


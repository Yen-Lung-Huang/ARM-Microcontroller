#include "motor_shield_v1.h"

#define DC_MOTOR_MIN 0
#define DC_MOTOR_MAX 999
#define STATIC_FRICTION_THRESHOLD 200
#define LOW_SPEED_THRESHOLD 100
#define MAX_ACCELERATION 1000
#define MAX_ADJUSTMENT_FACTOR 0.8f
#define MIN_ADJUSTMENT_FACTOR 0.3f
#define KP 1.0f
#define KI 0.1f
#define KD 0.01f
#define K_BACK_EMF 0.01f

/* Motor_Shield_V1 Configuration--------------------------------------------------------*/

// Declare a Motor_Shield_V1 structure with the defined ports and pins
Motor_Shield_V1 motor_shield_v1;
Motor_Shield_L29XX motor_shield_l29xx;

// Initialize the motor shield

void ms_init(enum Motor_Shield_Type type, bool enable_pwm)
{
    ms_gpio_init(type);

    if (enable_pwm) {
        ms_pwm_init(type);
    }

    ms_encoder_init(type);

    if (type == MS_V1) {
        init_motor_shield_v1();
    } else if (type == MS_L29XX) {
        init_motor_shield_l29xx();
    }
}

void init_motor_shield_v1()
{
    // Initialize the HC595 pins
    gpio_pin_set(&motor_shield_v1.hc595.LATCH, GPIOA, GPIO_PIN_6);
    gpio_pin_set(&motor_shield_v1.hc595.CLOCK, GPIOB, GPIO_PIN_5);
    gpio_pin_set(&motor_shield_v1.hc595.DATA, GPIOA, GPIO_PIN_9);

    for (uint8_t i = M1; i <= M4; i++) {
        get_dc_motor(&motor_shield_v1, MS_V1, i)->EN.soft_control_delay = CreateNonBlockingDelay();
    }

    motor_shield_v1.S1_PWM = servo[S1];
    motor_shield_v1.S2_PWM = servo[S2];
}

void init_motor_shield_l29xx()
{
    gpio_pin_set(&motor_shield_l29xx.M1.IN1, GPIOB, GPIO_PIN_1);
    gpio_pin_set(&motor_shield_l29xx.M1.IN2, GPIOB, GPIO_PIN_2);
    gpio_pin_set(&motor_shield_l29xx.M2.IN1, GPIOC, GPIO_PIN_4);
    gpio_pin_set(&motor_shield_l29xx.M2.IN2, GPIOB, GPIO_PIN_15);
    gpio_pin_set(&motor_shield_l29xx.M3.IN1, GPIOA, GPIO_PIN_12);
    gpio_pin_set(&motor_shield_l29xx.M3.IN2, GPIOC, GPIO_PIN_5);
    gpio_pin_set(&motor_shield_l29xx.M4.IN1, GPIOB, GPIO_PIN_12);
    gpio_pin_set(&motor_shield_l29xx.M4.IN2, GPIOA, GPIO_PIN_11);

    motor_shield_l29xx.M1.reverse = false;
    motor_shield_l29xx.M2.reverse = true;
    motor_shield_l29xx.M3.reverse = false;
    motor_shield_l29xx.M4.reverse = false;

    for (uint8_t i = M1; i <= M4; i++) {
        get_dc_motor(&motor_shield_l29xx, MS_L29XX, i)->EN.soft_control_delay = CreateNonBlockingDelay();
    }
}

// Initialize the PWM mode for the motor shield
void ms_pwm_init(enum Motor_Shield_Type type)
{
    if (type == MS_V1) {
        // If using Motor Shield V1
        // The timers are for NUCLEO-L053R8.
        motor_shield_v1.M1.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer = &htim22, .channel = TIM_CHANNEL_2, .pwm_min = DC_MOTOR_MIN, .pwm_max = DC_MOTOR_MAX, .physical_min = DC_MOTOR_MIN, .physical_max = DC_MOTOR_MAX, .offset = 0, .pwm_value = 0, .reverse = false, .complementary = false, .latch = false
        });
        motor_shield_v1.M2.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer = &htim2, .channel = TIM_CHANNEL_2, .pwm_min = DC_MOTOR_MIN, .pwm_max = DC_MOTOR_MAX, .physical_min = DC_MOTOR_MIN, .physical_max = DC_MOTOR_MAX, .offset = 0, .pwm_value = 0, .reverse = false, .complementary = false, .latch = false
        });
        motor_shield_v1.M3.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer = &htim2, .channel = TIM_CHANNEL_3, .pwm_min = DC_MOTOR_MIN, .pwm_max = DC_MOTOR_MAX, .physical_min = DC_MOTOR_MIN, .physical_max = DC_MOTOR_MAX, .offset = 0, .pwm_value = 0, .reverse = false, .complementary = false, .latch = false
        });
        motor_shield_v1.M4.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer = &htim22, .channel = TIM_CHANNEL_1, .pwm_min = DC_MOTOR_MIN, .pwm_max = DC_MOTOR_MAX, .physical_min = DC_MOTOR_MIN, .physical_max = DC_MOTOR_MAX, .offset = 0, .pwm_value = 0, .reverse = false, .complementary = false, .latch = false
        });

        motor_shield_v1.M1.EN.enable_pwm = true;
        motor_shield_v1.M2.EN.enable_pwm = true;
        motor_shield_v1.M3.EN.enable_pwm = true;
        motor_shield_v1.M4.EN.enable_pwm = true;
    } else if (type == MS_L29XX) {
        // If using Motor Shield L29XX
        // The timers are for NUCLEO-L053R8.
        motor_shield_l29xx.M1.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer = &htim2, .channel = TIM_CHANNEL_2, .pwm_min = DC_MOTOR_MIN, .pwm_max = DC_MOTOR_MAX, .physical_min = DC_MOTOR_MIN, .physical_max = DC_MOTOR_MAX, .offset = 0, .pwm_value = 0, .reverse = false, .complementary = false, .latch = false
        });
        motor_shield_l29xx.M2.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer = &htim22, .channel = TIM_CHANNEL_2, .pwm_min = DC_MOTOR_MIN, .pwm_max = DC_MOTOR_MAX, .physical_min = DC_MOTOR_MIN, .physical_max = DC_MOTOR_MAX, .offset = 0, .pwm_value = 0, .reverse = false, .complementary = false, .latch = false
        });
        motor_shield_l29xx.M3.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer = &htim22, .channel = TIM_CHANNEL_1, .pwm_min = DC_MOTOR_MIN, .pwm_max = DC_MOTOR_MAX, .physical_min = DC_MOTOR_MIN, .physical_max = DC_MOTOR_MAX, .offset = 0, .pwm_value = 0, .reverse = false, .complementary = false, .latch = false
        });
        motor_shield_l29xx.M4.EN.PWM = pwm_constructor((PWM_TypeDef) {
            .timer = &htim2, .channel = TIM_CHANNEL_1, .pwm_min = DC_MOTOR_MIN, .pwm_max = DC_MOTOR_MAX, .physical_min = DC_MOTOR_MIN, .physical_max = DC_MOTOR_MAX, .offset = 0, .pwm_value = 0, .reverse = false, .complementary = false, .latch = false
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
    if (type == MS_V1) {
        // If using Motor Shield V1
        // The pins are for NUCLEO-L053R8.
        gpio_pin_set(&motor_shield_v1.M1.EN.GPIO, GPIOA, GPIO_PIN_7);
        gpio_pin_set(&motor_shield_v1.M2.EN.GPIO, GPIOB, GPIO_PIN_3);
        gpio_pin_set(&motor_shield_v1.M3.EN.GPIO, GPIOB, GPIO_PIN_10);
        gpio_pin_set(&motor_shield_v1.M4.EN.GPIO, GPIOB, GPIO_PIN_4);

        motor_shield_v1.M1.EN.enable_pwm = false;
        motor_shield_v1.M2.EN.enable_pwm = false;
        motor_shield_v1.M3.EN.enable_pwm = false;
        motor_shield_v1.M4.EN.enable_pwm = false;
    } else if (type == MS_L29XX) {
        // If using Motor Shield L29XX
        // The pins are for NUCLEO-L053R8.
        gpio_pin_set(&motor_shield_l29xx.M1.EN.GPIO, GPIOA, GPIO_PIN_1);
        gpio_pin_set(&motor_shield_l29xx.M2.EN.GPIO, GPIOC, GPIO_PIN_7);
        gpio_pin_set(&motor_shield_l29xx.M3.EN.GPIO, GPIOC, GPIO_PIN_6);
        gpio_pin_set(&motor_shield_l29xx.M4.EN.GPIO, GPIOA, GPIO_PIN_0);

        motor_shield_l29xx.M1.EN.enable_pwm = false;
        motor_shield_l29xx.M2.EN.enable_pwm = false;
        motor_shield_l29xx.M3.EN.enable_pwm = false;
        motor_shield_l29xx.M4.EN.enable_pwm = false;
    }
}

void ms_encoder_init(enum Motor_Shield_Type type)
{
    if (type == MS_L29XX) {
        // M1 Encoder
        gpio_pin_set(&motor_shield_l29xx.M1.encoder.A, GPIOC, GPIO_PIN_8);
        gpio_pin_set(&motor_shield_l29xx.M1.encoder.B, GPIOC, GPIO_PIN_9);
        motor_shield_l29xx.M1.has_encoder = true;

        // M2 Encoder
        gpio_pin_set(&motor_shield_l29xx.M2.encoder.A, GPIOB, GPIO_PIN_8);
        gpio_pin_set(&motor_shield_l29xx.M2.encoder.B, GPIOB, GPIO_PIN_9);
        motor_shield_l29xx.M2.has_encoder = true;

        // M3 Encoder
        gpio_pin_set(&motor_shield_l29xx.M3.encoder.A, GPIOB, GPIO_PIN_6);
        gpio_pin_set(&motor_shield_l29xx.M3.encoder.B, GPIOA, GPIO_PIN_10);
        motor_shield_l29xx.M3.has_encoder = true;

        // M4 Encoder
        gpio_pin_set(&motor_shield_l29xx.M4.encoder.A, GPIOA, GPIO_PIN_4);
        gpio_pin_set(&motor_shield_l29xx.M4.encoder.B, GPIOB, GPIO_PIN_0);
        motor_shield_l29xx.M4.has_encoder = true;
    }
    // If needed, Add encoder initialization for MS_V1
}

/* Motor_Shield_V1 Control--------------------------------------------------------------*/

// Helper function to get the DC motor object based on the motor shield type and motor number
DC_Motor_TypeDef *get_dc_motor(void *motor_shield, enum Motor_Shield_Type type, uint8_t dc_motor_number)
{
    switch (type) {
    case MS_V1:
        return &(((Motor_Shield_V1 *)motor_shield)->M1) + dc_motor_number;
    case MS_L29XX:
        return &(((Motor_Shield_L29XX *)motor_shield)->M1) + dc_motor_number;
    // Add cases for other motor shield types if necessary
    default:
        return NULL; // If the motor object is not found, exit the function
    }
}

// Helper function to get the bit index of a specific motor
uint8_t get_motor_bit(uint8_t dc_motor_number, uint8_t bit_index)
{
    static const uint8_t motor_bits[4][2] = {{2, 3}, {1, 4}, {5, 7}, {0, 6}};
    return motor_bits[dc_motor_number][bit_index];
}

// Define a function to control the motor direction and speed with one input
void ms_motor_control(void *motor_shield, enum Motor_Shield_Type type, uint8_t dc_motor_number, float motor_input)
{
    DC_Motor_TypeDef *motor = get_dc_motor(motor_shield, type, dc_motor_number);
    if (motor == NULL) {
        return;
    }

    // Apply the reverse setting
    if (motor->reverse) {
        motor_input = -motor_input;
    }

    // Determine the motor direction
    bool forward_rotation = motor_input >= 0;

    // Get the PWM value
    float abs_motor_input = fabs(motor_input);
    int pwm_value;
    if (motor->EN.enable_pwm) {
        pwm_value = (int)map(abs_motor_input, 0, 1, motor->EN.PWM.pwm_min, motor->EN.PWM.pwm_max);
    } else {
        pwm_value = (abs_motor_input > 0) ? 1 : 0;
    }

    // Set PWM or GPIO
    if (motor->EN.enable_pwm) {
        pwm_set(&(motor->EN.PWM), pwm_value, true);
    } else {
        HAL_GPIO_WritePin(motor->EN.GPIO.Port, motor->EN.GPIO.Pin, pwm_value);
    }

    // Set the direction
    if (type == MS_V1) {
        HC595_SendBit(&(((Motor_Shield_V1 *)motor_shield)->hc595), get_motor_bit(dc_motor_number, 0), forward_rotation);
        HC595_SendBit(&(((Motor_Shield_V1 *)motor_shield)->hc595), get_motor_bit(dc_motor_number, 1), !forward_rotation);
    } else if (type == MS_L29XX) {
        HAL_GPIO_WritePin(motor->IN1.Port, motor->IN1.Pin, forward_rotation ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->IN2.Port, motor->IN2.Pin, forward_rotation ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
}

// Define a function to control the servo angle with one input
void ms_v1_servo_control(Motor_Shield_V1 *motor_shield, uint8_t servo_number, float servo_input, bool mode) // Add a mode parameter
{
    // Check the validity of the arguments
    if (motor_shield == NULL) {
        return; // Invalid pointer
    }

    // Select the corresponding PWM structure
    PWM_TypeDef *pwm = NULL;

    switch (servo_number) {
    // Use a switch statement to assign different values
    case S1:                           // If servo_number is S1
        pwm = &(motor_shield->S1_PWM); // Select the S1_PWM structure
        break;                         // Break the switch statement
    case S2:                           // If servo_number is S2
        pwm = &(motor_shield->S2_PWM); // Select the S2_PWM structure
        break;                         // Break the switch statement
    default:                           // If servo_number is not valid
        return;                        // Return from the function
    }

    // Check the mode parameter
    if (mode == PWM) {
        // If the mode is PWM
        // Set the PWM value
        pwm_set(pwm, (int)servo_input, true); // Use the pwm_set function
    } else if (mode == ANGLE) {
        // If the mode is ANGLE
        // Set the PWM value according to the servo angle
        pwm_physical_set(pwm, servo_input, true); // Use the pwm_physical_set function
    } else {
        // If the mode is not valid
        return; // Return from the function
    }
}

/* Soft Motor Control ---------------------------------------------------------------*/

// Define a function to control the motor with one input
void soft_motor_control(void *motor_shield, enum Motor_Shield_Type type, uint8_t dc_motor_number, int target_speed)
{
    DC_Motor_TypeDef *motor = get_dc_motor(motor_shield, type, dc_motor_number);
    if (motor == NULL) {
        printf("Error: Motor not found\n");
        return;
    }

    target_speed = (target_speed > DC_MOTOR_MAX) ? DC_MOTOR_MAX : (target_speed < -DC_MOTOR_MAX ? -DC_MOTOR_MAX : target_speed);
    motor->target_speed = target_speed;
    printf("Current Speed: %d, Target Speed: %d, Static Friction Overcome: %d\n", motor->current_speed, motor->target_speed, motor->static_friction_overcome);

    uint32_t current_time = HAL_GetTick();

    if (motor->EN.soft_control_delay.IsExpired(&motor->EN.soft_control_delay)) {
        float dt = (current_time - motor->last_update_time) / 1000.0f;
        int speed_diff = motor->target_speed - motor->current_speed;

        if (target_speed == 0) {
            // Logic for stopping when target speed is 0
            if (abs(motor->current_speed) > LOW_SPEED_THRESHOLD) {
                motor->current_speed -= (motor->current_speed > 0) ? MAX_ACCELERATION * dt : -MAX_ACCELERATION * dt;
                if (abs(motor->current_speed) < LOW_SPEED_THRESHOLD) {
                    motor->current_speed = 0;
                }
            } else {
                motor->current_speed = 0;
            }
            motor->static_friction_overcome = false;
        } else {
            // Logic for non-zero target speeds
            int effective_target_speed = (abs(target_speed) < LOW_SPEED_THRESHOLD) ?
                                         (target_speed > 0 ? LOW_SPEED_THRESHOLD : -LOW_SPEED_THRESHOLD) : target_speed;

            // Check if direction has changed
            if (motor->current_speed * effective_target_speed < 0) {
                // Handle direction change
                motor->current_speed -= (motor->current_speed > 0) ? MAX_ACCELERATION * dt : -MAX_ACCELERATION * dt;
                if (abs(motor->current_speed) < LOW_SPEED_THRESHOLD) {
                    motor->current_speed = 0;
                    motor->static_friction_overcome = false;  // Reset static friction flag
                }
            } else {
                if (!motor->static_friction_overcome || abs(motor->current_speed) < LOW_SPEED_THRESHOLD) {
                    motor->current_speed = (effective_target_speed > 0) ? STATIC_FRICTION_THRESHOLD : -STATIC_FRICTION_THRESHOLD;
                    motor->static_friction_overcome = true;
                } else {
                    float speed_ratio = (float)abs(motor->current_speed) / DC_MOTOR_MAX;
                    float adjustment_factor = MAX_ADJUSTMENT_FACTOR - speed_ratio * (MAX_ADJUSTMENT_FACTOR - MIN_ADJUSTMENT_FACTOR);

                    adjustment_factor *= (abs(effective_target_speed) > abs(motor->current_speed)) ? 1.2f : 0.8f;

                    int speed_change = (int)((effective_target_speed - motor->current_speed) * adjustment_factor);
                    int max_speed_change = MAX_ACCELERATION * dt;

                    speed_change = (abs(speed_change) > max_speed_change) ?
                                   ((speed_change > 0) ? max_speed_change : -max_speed_change) : speed_change;

                    motor->current_speed += speed_change;

                    if ((speed_diff > 0 && motor->current_speed > effective_target_speed) ||
                            (speed_diff < 0 && motor->current_speed < effective_target_speed)) {
                        motor->current_speed = effective_target_speed;
                    }
                }
            }
        }

        float back_emf = K_BACK_EMF * motor->current_speed;
        float compensated_speed = motor->current_speed + back_emf;
        float motor_input = compensated_speed / DC_MOTOR_MAX;
        motor_input = (motor_input > 1.0f) ? 1.0f : (motor_input < -1.0f ? -1.0f : motor_input);

        ms_motor_control(motor_shield, type, dc_motor_number, motor_input);

        motor->previous_error = speed_diff;
        motor->last_update_time = current_time;
        motor->EN.soft_control_delay.Start(&motor->EN.soft_control_delay, 1);
    }
}

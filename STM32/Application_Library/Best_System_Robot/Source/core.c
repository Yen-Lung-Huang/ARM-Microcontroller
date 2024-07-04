#include "core.h"

/* Initial Configuration---------------------------------------*/
void core_init(void)
{
    servos_init();
    ms_init(MS_V1, false);
    ms_init(MS_L29XX, true);
}

/* Loop Configuration---------------------------------------*/
void core_loop(void)
{
    for (int i = 0; i < NUM_BUTTONS; Button_CheckState(&button[i++]));
    for (int i = 0; i < 3; HC_SR04_GetDistance(&hc_sr04[i++]));
    // UpdateRoboticArmState();

    for (uint8_t i = M1; i <= M4; i++) {
        soft_motor_control(&motor_shield_l29xx, MS_L29XX, i, get_dc_motor(&motor_shield_l29xx, MS_L29XX, i)->target_speed);
    }
}

#if !defined(SERVO_H)
/* Math--------------------------------------------------------*/
float map(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

double max(double a, double b)
{
    double q = sqrt((a - b) * (a - b));
    return ((a + b) + q) / 2;
}
#endif

/* Debug--------------------------------------------------------*/
void print_binary(uint8_t byteData)
{
    int size = sizeof(byteData) * 8;
    uint8_t bits[size + 1];

    for (int i = size - 1; i >= 0; i--) {
        // Check the bit is 1 or 0 and write it into bits
        bits[i] = (byteData & (1 << i)) ? '1' : '0';
    }
    bits[size] = '\0';      // Add the end symbol
    printf("%s\r\n", bits); // Use printf function, and use %s format symbol to output binary
}

/* Robot with JSON--------------------------------------------------------*/
bool json_action(char *JSON_STRING, uint16_t token_size) // sizeof(char)*strlen(JSON_STRING)
{
    cJSON *root = cJSON_ParseWithLength(JSON_STRING, token_size);
    if (root == NULL) {
        printf("invalid JSON\r\n"); // Print for debug.
        cJSON_Delete(root);         // Free the root pointer
        return false;
    }

    for (cJSON *token = root->child; token != NULL; token = token->next) {
        if (!strcmp(token->string, "motor")) {
            // Check if the key is "motor"
            if (cJSON_IsObject(token)) {
                // Check if the value is an object
                cJSON *motor = token; // Get the "Motor" object
                cJSON *item = NULL;   // Declare a pointer to store each item in the object
                cJSON_ArrayForEach(item, motor) {
                    // Loop through all the items in the object
                    // Get the key and value of the current item
                    char *key = item->string;        // The key is the motor number, such as "M1" or "W1"
                    float value = item->valuedouble; // The value is the motor input
                    // int value = item->valueint; // The value is the motor input, such as -100

                    // Convert the key to an integer, using the enum type defined in ms_v1_motor_control
                    uint8_t dc_motor_number = 0;
                    if (strcmp(key, "M1") == 0 || strcmp(key, "W1") == 0) {
                        dc_motor_number = M1;
                    } else if (strcmp(key, "M2") == 0 || strcmp(key, "W2") == 0) {
                        dc_motor_number = M2;
                    } else if (strcmp(key, "M3") == 0 || strcmp(key, "W3") == 0) {
                        dc_motor_number = M3;
                    } else if (strcmp(key, "M4") == 0 || strcmp(key, "W4") == 0) {
                        dc_motor_number = M4;
                    } else {
                        printf("invalid motor number\r\n"); // Print for debug.
                        return false;                       // Invalid motor number
                    }
                    // Call the ms_motor_control function with the motor shield type, the motor number and input
                    if (key[0] == 'M') {
                        // If the key starts with 'M', use MS_V1 type
                        // get_dc_motor(&motor_shield_v1, MS_V1, dc_motor_number)->target_speed = value;
                        // soft_motor_control(&motor_shield_v1, MS_V1, dc_motor_number, value);
                        ms_motor_control(&motor_shield_v1, MS_V1, dc_motor_number, value);
                    } else if (key[0] == 'W') {
                        // If the key starts with 'W', use MS_L29XX type
                        get_dc_motor(&motor_shield_l29xx, MS_L29XX, dc_motor_number)->target_speed = value;
                        // soft_motor_control(&motor_shield_l29xx, MS_L29XX, dc_motor_number, value);
                        // ms_motor_control(&motor_shield_l29xx, MS_L29XX, dc_motor_number, value);
                    } else {
                        printf("invalid motor shield type\r\n"); // Print for debug.
                        return false;                            // Invalid motor shield type
                    }
                    // CheckButtonsAndStopMotors();
                    // print_binary(motor_shield_v1.hc595.byte); // Print for debug.
                }
            } else {
                printf("invalid motor value\r\n"); // Print for debug.
                return false;                      // Invalid motor value
            }
        }

        if (!strcmp(token->string, "servo")) {
            // Check if the key is "servo"
            if (cJSON_IsObject(token)) {
                // Check if the value is an object
                cJSON *servo_obj = token; // Get the "Servo" object
                cJSON *item = NULL;       // Declare a pointer to store each item in the object
                cJSON_ArrayForEach(item, servo_obj) {
                    // Loop through all the items in the object
                    // Get the key and value of the current item
                    char *key = item->string; // The key is the servo number, such as "S1"
                    float value = 0;          // Declare a variable to store the servo input

                    // Convert the key to an integer, using the enum type defined in ms_v1_servo_control
                    uint8_t servo_number = 0; // Declare and initialize servo_number at the beginning of the loop
                    if (strcmp(key, "S1") == 0) {
                        servo_number = S1;
                    } else if (strcmp(key, "S2") == 0) {
                        servo_number = S2;
                    } else if (strcmp(key, "S3") == 0) {
                        servo_number = S3;
                    } else {
                        printf("invalid servo number\r\n"); // Print for debug.
                        return false;                       // Invalid servo number
                    }

                    // Check if the value is a number or a string
                    if (cJSON_IsNumber(item)) {
                        // If the value is a number
                        value = item->valuedouble; // The value is the pwm value
                        // Use servo_control function with PWM mode and limit, and pass the PWM_TypeDef pointer
                        servo_control(&servo[servo_number], value, PWM, true);
                    } else if (cJSON_IsString(item)) {
                        // If the value is a string
                        char *str = item->valuestring; // The value is the angle string, such as "90 deg" or "stop"
                        // Check if the value is "stop"
                        if (strcmp(str, "stop") == 0) {
                            // If the value is "stop"
                            // Call the pwm_stop function with the PWM_TypeDef pointer
                            pwm_stop(&servo[servo_number]);
                            continue; // Skip the rest of the loop
                        }
                        // Parse the string to get the angle value
                        char *endptr;                 // Declare a pointer to store the end of the parsed string
                        value = strtof(str, &endptr); // Convert the string to a float
                        if (endptr == str) {
                            // If no conversion was performed
                            printf("invalid servo value\r\n"); // Print for debug.
                            continue;                          // Skip the rest of the loop
                        }
                        // No need to check if the string has a "deg" suffix
                        // Use servo_control function with ANGLE mode and limit, and pass the PWM_TypeDef pointer
                        servo_control(&servo[servo_number], value, ANGLE, true);
                    } else {
                        // If the value is neither a number nor a string
                        printf("invalid servo value\r\n"); // Print for debug.
                        continue;                          // Skip the rest of the loop
                    }
                }
            } else {
                printf("invalid servo value\r\n"); // Print for debug.
                continue;                          // Skip the rest of the loop
            }
        }

        else if (!strcmp(token->string, "74HC595")) {
            int size = cJSON_GetArraySize(token); // Get the number of elements in the array
            uint8_t byteData = 0;                 // Initialize byteData to 0

            if (size == 8) {
                // Check if the array is 8 elements long
                for (int i = 0; i < size; i++) {
                    // Loop through each element in the array
                    int value = cJSON_GetArrayItem(token, i)->valueint; // Get the value of the current element

                    // Set the corresponding bit of byteData to 1 or 0 by using the value
                    if (value == 1) {
                        byteData |= (1 << i); // Use bit-wise or operator to set the corresponding bit to 1
                    } else {
                        byteData &= ~(1 << i); // Use bit-wise and operator to set the corresponding bit to 0
                    }
                }
                HC595_SendByte(&motor_shield_v1.hc595, byteData); // Call HC595_SendByte function to pass byteData as a parameter
                printf("(state changed) ");
            }
            // Print the state of 74HC595 regardless of the number of elements in the array
            printf("74HC595(L->H): ");
            print_binary(motor_shield_v1.hc595.byte); // Print for debug.
        }

        else if (!strcmp(token->string, "HC-SR04")) {
            if (cJSON_IsNumber(token)) {
                int sensor_number = token->valueint;

                // Call hc_sr04_trig function
                switch (sensor_number) {
                case 0:
                    // printf("Distance: %6.2f cm\n", HC_SR04_GetDistance(&hc_sr04[0]));
                    printf("Distance: %6.2f cm\n", hc_sr04[0].distance);
                    break;
                case 1:
                    // printf("Distance: %6.2f cm\n", HC_SR04_GetDistance(&hc_sr04[1]));
                    printf("Distance: %6.2f cm\n", hc_sr04[1].distance);
                    break;
                case 2:
                    // printf("Distance: %6.2f cm\n", HC_SR04_GetDistance(&hc_sr04[2]));
                    printf("Distance: %6.2f cm\n", hc_sr04[2].distance);
                    break;
                
                default:
                    printf("Invalid sensor number\n");
                    break;
                }
            }
        }

        else if (!strcmp(token->string, "defect_result")) {
            if (cJSON_IsBool(token)) {
                defect_result = cJSON_IsTrue(token);
                defect_result_received = true;
            } else {
                printf("defect_result is not a boolean\n");
            }
        }

        else if (!strcmp(token->string, "relay")) {
            if (cJSON_IsBool(token)) {
                if (cJSON_IsTrue(token)) {
                    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
                } else {
                    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
                }
            } else {
                printf("value is not a boolean\n");
            }
        }

        else if (!strcmp(token->string, "adc")) {
            // printf("%f\r\n",read_adc()); // send adc value
            // printf("%d\n",(int)map(read_adc(),0,3.26,0,100)); // send adc value by %
            printf("%d\r\n", (int)map((10800000 - (float)HAL_GetTick()) / 10800000, 0, 1, 0, 82.5));
        }
    }
    cJSON_Delete(root);
    return true; // JSON action completed successfully
}

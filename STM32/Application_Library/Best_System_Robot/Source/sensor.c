#include "sensor.h"

/* Buttons--------------------------------------------------------*/

// Define the button array
Button_TypeDef button[NUM_BUTTONS] = {
    {GPIOC, GPIO_PIN_0,  true , false, 0, 0, Button1_Pressed}, // SW_Middle_Up,      pull-up trigger
    {GPIOC, GPIO_PIN_1,  true , false, 0, 0, Button2_Pressed}, // SW_Middle_Down,    pull-up trigger
    {GPIOC, GPIO_PIN_2,  true , false, 0, 0, Button3_Pressed}, // SW_Left,           pull-up trigger
    {GPIOC, GPIO_PIN_3,  true , false, 0, 0, Button4_Pressed}, // SW_Right,          pull-up trigger
    {GPIOA, GPIO_PIN_15, true , false, 0, 0, Button5_Pressed}, // SW_Revolver_Left,  pull-up trigger
    {GPIOB, GPIO_PIN_7,  true , false, 0, 0, Button6_Pressed}, // SW_Revolver_Right, pull-up trigger
    {GPIOC, GPIO_PIN_13, false, false, 0, 0, Button7_Pressed}  // SW_Middle_Bracket, pull-down trigger
};

// Check the button state
void Button_CheckState(Button_TypeDef* button)
{
    uint32_t current_time = HAL_GetTick();

    if(button->debounce_flag && (current_time - button->last_debounce_time) >= button->debounce_delay) {
        GPIO_PinState pin_state = HAL_GPIO_ReadPin(button->port, button->pin);
        if((button->is_pull_up && pin_state == GPIO_PIN_SET) || (!button->is_pull_up && pin_state == GPIO_PIN_RESET)) {
            button->callback();
        }
        button->debounce_flag = false; // Reset the debounce flag
    }
}

bool Button_IsPressed(Button_TypeDef* button)
{
    GPIO_PinState pin_state = HAL_GPIO_ReadPin(button->port, button->pin);
    return (button->is_pull_up && pin_state == GPIO_PIN_SET) || (!button->is_pull_up && pin_state == GPIO_PIN_RESET);
}

// Button interrupt handler function
void Button_HandleInterrupt(uint16_t GPIO_Pin, Button_TypeDef* buttons, int num_buttons)
{
    for(int i = 0; i < num_buttons; i++) {
        if(GPIO_Pin == buttons[i].pin) {
            uint32_t current_time = HAL_GetTick();
            if(!buttons[i].debounce_flag) {
                buttons[i].last_debounce_time = current_time;
                buttons[i].debounce_flag = true;
            }
        }
    }
}

// Implementation of button press callback functions
void Button1_Pressed(void) // SW_Middle_Up
{
    ms_motor_control(&motor_shield_v1, MS_V1, M1, 0);
    printf("(button 1 pressed)\n");
}

void Button2_Pressed(void) // SW_Middle_Down
{
    ms_motor_control(&motor_shield_v1, MS_V1, M1, 0);
    printf("(button 2 pressed)\n");
}

void Button3_Pressed(void) // SW_Left
{
    ms_motor_control(&motor_shield_v1, MS_V1, M2, 0);
    ms_motor_control(&motor_shield_v1, MS_V1, M3, 0);
    printf("(button 3 pressed)\n");
}

void Button4_Pressed(void) // SW_Right
{
    ms_motor_control(&motor_shield_v1, MS_V1, M2, 0);
    ms_motor_control(&motor_shield_v1, MS_V1, M4, 0);
    printf("(button 4 pressed)\n");
}

void Button5_Pressed(void) // SW_Revolver_Left
{
    ms_motor_control(&motor_shield_v1, MS_V1, M3, 0);
    printf("(button 5 pressed)\n");
}

void Button6_Pressed(void) // SW_Revolver_Right
{
    ms_motor_control(&motor_shield_v1, MS_V1, M4, 0);
    printf("(button 6 pressed)\n");
}

void Button7_Pressed(void) // SW_Middle_Bracket
{
    // Perform the action when the button is pressed
    printf("(button 7 pressed)\n");
}



// Interrupt Service Routine
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    // Handle button interrupt
    Button_HandleInterrupt(GPIO_Pin, button, NUM_BUTTONS);

    // Check if the echo_pin of any HC-SR04 sensor triggered the interrupt
    HC_SR04_HandleInterrupt(GPIO_Pin, hc_sr04, 3);
}


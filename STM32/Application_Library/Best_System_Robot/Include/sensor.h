/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SENSOR_H
#define SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include "main.h"
#include "motor_shield_v1.h"
#include "HC-SR04.h"

#define NUM_BUTTONS 7
#define DEBOUNCE_DELAY 50 // Debounce delay time 50ms


// Define the button structure
typedef struct {
    GPIO_TypeDef* port;
    uint16_t pin;
    bool is_pull_up; // 表示按鈕是上拉或下拉觸發
    bool debounce_flag;
    uint32_t last_debounce_time;
    void (*callback)(void); // 按鈕按下時的回調函數
} Button_TypeDef;

// Define an enum type variable to store the robot arm servos names and values
enum robot_button {B1, B2, B3, B4, B5, B6, B7};

// Declare the global objects with extern keyword
extern Button_TypeDef button[];

/* FUNCTION (Prototype) DEFINITIONS */
void Button_CheckState(Button_TypeDef* button);
bool Button_IsPressed(Button_TypeDef* button);
void Button_HandleInterrupt(uint16_t GPIO_Pin, Button_TypeDef* buttons, int num_buttons);


// 按鈕回調函數原型
void Button1_Pressed(void);
void Button2_Pressed(void);
void Button3_Pressed(void);
void Button4_Pressed(void);
void Button5_Pressed(void);
void Button6_Pressed(void);
void Button7_Pressed(void);


#ifdef __cplusplus
}
#endif

#endif /* SENSOR_H */

/*****END OF FILE*****/

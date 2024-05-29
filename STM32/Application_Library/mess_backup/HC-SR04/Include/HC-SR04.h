/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HC_SR04_H
#define HC_SR04_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include <stdbool.h>
#include "main.h"
#include "tim.h"
#include "usart.h"

// Define the HC-SR04 structure
typedef struct {
    GPIO_TypeDef* trig_port;
    uint16_t trig_pin;
    GPIO_TypeDef* echo_port;
    uint16_t echo_pin;
    volatile float distance;
    volatile bool pulseDetected;
    volatile bool waiting_for_end; // Add a flag to indicate we're waiting for a pulse end
    volatile uint32_t pulseStart; // Start time of the pulse
    volatile uint32_t pulseEnd;   // End time of the pulse
    volatile uint32_t echo_duration; // Duration of the pulse
    volatile uint32_t overflow_count; // Counter for timer overflows
} HC_SR04_TypeDef;


// Declare the global objects with extern keyword
extern HC_SR04_TypeDef hc_sr04[3];

/* FUNCTION (Prototype) DEFINITIONS */
void delay_us(uint16_t us);
float HC_SR04_GetDistance(HC_SR04_TypeDef* hc_sr04);
void HC_SR04_HandleInterrupt(HC_SR04_TypeDef* hc_sr04);


#ifdef __cplusplus
}
#endif

#endif /* HC_SR04_H */

/*****END OF FILE*****/

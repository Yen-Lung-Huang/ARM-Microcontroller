/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HC_SR04_H
#define HC_SR04_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include "main.h"
#include "timing_delays.h"
#include "usart.h"

// Define the HC-SR04 structure
typedef struct {
  GPIO_TypeDef* trig_port;
  uint16_t trig_pin;
  GPIO_TypeDef* echo_port;
  uint16_t echo_pin;
  volatile uint32_t pulseStart;
  volatile uint32_t pulseEnd;
  volatile uint32_t overflow_count;
  volatile float distance;
  volatile uint8_t pulseDetected;
} HC_SR04_TypeDef;


// Declare the global objects with extern keyword
extern HC_SR04_TypeDef hc_sr04[];

/* FUNCTION (Prototype) DEFINITIONS */
float HC_SR04_GetDistance(HC_SR04_TypeDef* sensor);
void HC_SR04_HandleInterrupt(uint16_t GPIO_Pin, HC_SR04_TypeDef* sensors, int num_sensors);


#ifdef __cplusplus
}
#endif

#endif /* HC_SR04_H */

/*****END OF FILE*****/

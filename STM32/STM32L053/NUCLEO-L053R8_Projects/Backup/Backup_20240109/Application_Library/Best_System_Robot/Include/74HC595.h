/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _74HC595_H_
#define _74HC595_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include <stdbool.h>
#include "gpio.h"

// Define a structure for GPIO
typedef struct {
	GPIO_TypeDef *Port; // Port for GPIO
	uint16_t Pin;       // Pin for GPIO
} My_GPIO_TypeDef;

// Define a structure for 74HC595
typedef struct {
	My_GPIO_TypeDef LATCH; // GPIO for latch
	My_GPIO_TypeDef CLOCK; // GPIO for clock
	My_GPIO_TypeDef DATA;  // GPIO for data
	uint8_t byte;					 // byte for storing the output bits
} HC595;

/* FUNCTION (Prototype) DEFINITIONS */
void gpio_pin_set(My_GPIO_TypeDef *gpio, GPIO_TypeDef *port, uint16_t pin);
void HC595_SendByte(HC595 *hc595, uint8_t byte);
void HC595_SendBit(HC595 *hc595, uint8_t bit, bool value);


#ifdef __cplusplus
}
#endif

#endif /* _74HC595_H_ */

/*****END OF FILE*****/

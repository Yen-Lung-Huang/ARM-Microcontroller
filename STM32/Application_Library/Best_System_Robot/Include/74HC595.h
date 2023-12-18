/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _74HC595_H_
#define _74HC595_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include <stdbool.h>
#include "gpio.h"

// Define a structure for 74HC595
typedef struct {
	GPIO_TypeDef *LATCH_Port; // Port for latch pin
	uint16_t LATCH_Pin;       // Pin for latch
	GPIO_TypeDef *CLOCK_Port; // Port for clock pin
	uint16_t CLOCK_Pin;       // Pin for clock
	GPIO_TypeDef *DATA_Port;  // Port for data pin
	uint16_t DATA_Pin;        // Pin for data
	uint8_t byte;							// byte for storing the output bits
} HC595;

/* FUNCTION (Prototype) DEFINITIONS */
void HC595_SendByte(HC595 *hc595, uint8_t byte);
void HC595_SetBit(HC595 *hc595, uint8_t bit, bool value);


#ifdef __cplusplus
}
#endif

#endif /* _74HC595_H_ */

/*****END OF FILE*****/

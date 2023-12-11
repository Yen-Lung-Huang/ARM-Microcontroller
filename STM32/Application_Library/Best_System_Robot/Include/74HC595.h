/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _74HC595_H_
#define _74HC595_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include "main.h"
#include "gpio.h"

#define LATCH_Port		GPIOA
#define LATCH_Pin			GPIO_PIN_6
#define CLOCK_Port		GPIOB
#define CLOCK_Pin			GPIO_PIN_5
#define DATA_Port			GPIOA
#define DATA_Pin			GPIO_PIN_9

/* FUNCTION (Prototype) DEFINITIONS */
void HC595_SendByte(uint8_t byte);


#ifdef __cplusplus
}
#endif

#endif /* _74HC595_H_ */

/*****END OF FILE*****/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef GD32F10X_USART_CONFIG_H
#define GD32F10X_USART_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif


#include "gd32f10x.h"
#include <stdio.h>
#include <stdbool.h>

void usart_config(uint32_t usart_periph, uint32_t baudRate);
int fputc(int ch, FILE *f);



#ifdef __cplusplus
}
#endif

#endif /* GD32F10X_USART_CONFIG_H */

/*****END OF FILE*****/

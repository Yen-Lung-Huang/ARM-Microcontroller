/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef GD32F10X_USART_CONFIG_H
#define GD32F10X_USART_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gd32f10x.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ALL 10 /*All enable USART*/
#define va_list void*
#define va_arg(arg, type) *(type*)arg; arg = (char*)arg + sizeof(type);
#define va_start(arg, start) arg = (va_list)(((char*)&(start)) + sizeof(start))

static bool usart_periph_enable[3] = {false,false,false};

void usart_config(uint32_t usart_periph, uint32_t baudRate);
int fputc(int ch, FILE *f);
void printNum(unsigned long num, int base, uint32_t usart_periph);
void printFloat(double f, uint32_t usart_periph);
void print(uint32_t usart_periph, char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* GD32F10X_USART_CONFIG_H */

/*****END OF FILE*****/

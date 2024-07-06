/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DATA_BUFFER_SIZE_H
#define DATA_BUFFER_SIZE_H

#ifdef __cplusplus
extern "C" {
#endif



#include "gd32f10x.h"
#include <stdio.h>
#include <string.h>

#define SIZEOF(type) ((char *)(&type+1)-(char*)(&type))

typedef enum {TX = 0, RX = !TX} UartDirection;

void usart_dma_config(uint32_t usart_periph, UartDirection uart_direction,	uint8_t* dma_buffer, uint32_t transfer_amount, ControlStatus circular_mode);
void usart_dma_deinit(dma_parameter_struct *dma_init_struct, dma_channel_enum channelx, uint32_t transfer_amount, uint32_t circular_mode);
dma_channel_enum usart_rx_dma_channel(uint32_t usart_periph);
uint32_t usart_data_amount(uint32_t usart_periph, uint32_t transfer_amount);
bool usart_rx_IRQHandler(uint32_t usart_periph, uint8_t* dma_buffer, uint8_t* data_buffer, uint32_t transfer_amount);
bool usart0_rx_IRQHandler(void);



#ifdef __cplusplus
}
#endif

#endif /* DATA_BUFFER_SIZE_H */

/*****END OF FILE*****/

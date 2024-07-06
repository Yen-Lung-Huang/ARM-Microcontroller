#include "main.h"
#include "gd32f10x_usart_config.h"
#include "gd32f10x_dma_config.h"

uint32_t usart0_dma_buffer[DATA_BUFFER_SIZE];
uint32_t usart0_data_buffer[DATA_BUFFER_SIZE];
uint32_t usart0_data_num;

int main(void)
{
	usart_config(USART0,115200);
	usart_dma_config(USART0,RX,usart0_dma_buffer,DATA_BUFFER_SIZE,DISABLE);
	printf("any length receive test\n");
	while(1);
}

#include "gd32f10x.h"
#include <stdio.h>
#include "init.h"

uint8_t dma_buffer[DATA_BUFFER_SIZE];      //組數 設定給 RX
uint8_t rx_buffer[DATA_BUFFER_SIZE];
uint8_t usart_data_num;


int main(void)
{
    usart_dma_config(dma_buffer, DATA_BUFFER_SIZE);
    printf("any length receive test\n");
    while(1);
}

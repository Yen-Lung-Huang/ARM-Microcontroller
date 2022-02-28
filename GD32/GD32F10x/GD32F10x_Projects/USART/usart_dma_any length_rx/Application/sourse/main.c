#include "gd32f10x.h"
#include <stdio.h>
#include "init.h"
#include "systick.h"

uint8_t dma_buffer[256];      //組數 設定給 RX
uint8_t rx_buffer[256];
uint8_t usart_data_num = 0;


int main(void)
{
    systick_config();
    usart_dma_config();
    led_init();
    printf("any length receive test\n");
    while(1);
}

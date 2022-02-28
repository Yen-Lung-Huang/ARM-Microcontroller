#ifndef INIT_H
#define INIT_H

#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "gd32f10x.h"


void led_init(void);
void led_flash(int);
void usart_dma_config(uint8_t* dma_buffer, uint32_t transfer_amount);
int fputc(int ch, FILE *f);
//void memcopy(uint8_t rx_buffer[], uint8_t dma_buffer[], int data_num);
bool irq(uint8_t* dma_buffer, uint8_t* rx_buffer, uint32_t transfer_amount);
#endif /* INIT_H */

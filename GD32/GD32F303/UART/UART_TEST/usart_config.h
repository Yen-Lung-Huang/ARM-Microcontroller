#ifndef USART_CONFIG_H  /* include guard */ 
#define USART_CONFIG_H

#define USART1_BUF_LEN 32

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "gd32f10x.h"
#include "stdint.h"

extern uint8_t USART1_TX_BUF[];  // DMA發送緩衝區
extern uint8_t USART1_RX_BUF[];  // DMA接收緩衝區
extern uint8_t USART1_RX_STAT;	 // 接受狀態 0x01:已接收到資料 0x03:接收緩衝區半滿 0x07:接收緩衝區全滿
extern uint32_t USART1_RX_NUM;   // 待處理數據個數：大於1為有數據待處理，0為沒有數據待處理
extern bool DMA_BUF_BUSY;

void USART1_init(uint32_t baudrate);
void USART1_transmit(uint8_t* data);
void USART1_IRQHandler(void);
void USART1_vsprintf(const char* format,...);
void DMA0_Channel6_IRQHandler(void);
void DMA0_Channel5_IRQHandler(void);

#endif /* USART_CONFIG_H */ 

#ifndef USART_CONFIG_H  /* include guard */ 
#define USART_CONFIG_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "gd32f10x.h"

/* 函數原型宣告 */
void usart1_config(uint32_t baudrate);
void uart1_transmit(uint8_t *data);
void USART1_IRQHandler(void);
void DMA0_Channel6_IRQHandler(void);
void DMA0_Channel5_IRQHandler(void);
void USART1_vsprintf(const char* format,...);

/* 定義發送緩存 */
extern uint8_t UART1_TX_BUF[]; 		/* 發送緩衝區 */
extern uint8_t DMA_BUF_BUSY ;					/* 緩衝區是否已被佔用 */

/* 定義接收緩存 */
extern uint8_t UART1_RX_BUF[]; /* 雙接收緩衝區 */
extern uint8_t UART1_RX_STAT;					/* 接受狀態 0x01:已接收到資料  0x03:接收緩衝區半滿  0x07:接收緩衝區全滿 */
extern uint32_t UART1_RX_NUM;					/* 接收到的資料個數 */
extern uint8_t rx1_data_buffer[];// 待處理串列數據緩衝區

#endif /* USART_CONFIG_H */ 

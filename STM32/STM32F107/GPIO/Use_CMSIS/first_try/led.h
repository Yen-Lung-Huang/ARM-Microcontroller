
#ifndef __LED_H
#define __LED_H
#include "stm32f4xx.h"
 
//定義宏為寄存器位址的解引用，到時候直接操作宏就是操作寄存器，方便程式設計。
//加上volatile關鍵字是為了防止編譯器進行優化，導致操作寄存器位址失敗。（提醒編譯器，這個值是容易變化的。）
#define RCC_AHB1ENR		*(volatile unsigned int *)(0x40023800+0x30UL)  //外設時鐘使能寄存器
#define GPIOF_MODER		*(volatile unsigned int *)(0x40021400+0x00UL)  //GPIO埠模式寄存器
#define GPIOF_OTYPER	*(volatile unsigned int *)(0x40021400+0x04UL)  //GPIO埠輸出類型寄存器
#define GPIOF_OSPEEDR	*(volatile unsigned int *)(0x40021400+0x08UL)  //GPIO埠速度寄存器
#define GPIOF_PUPDR 	*(volatile unsigned int *)(0x40021400+0x0CUL)  //GPIO埠上拉/下拉寄存器
#define GPIOF_BSRR 	  *(volatile unsigned int *)(0x40021400+0x18UL)  //GPIO埠置位/ 復位寄存器
 
 
void LED_Init(void);
 
 
 
#endif

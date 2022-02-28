/*!
    \file    gd32f10x_it.c
    \brief   interrupt service routines
 
    \version 2015-11-16, V1.0.0, demo for GD32F10x
    \version 2017-06-30, V2.0.0, demo for GD32F10x
    \version 2021-04-30, V2.1.0, demo for GD32F10x
*/


#include "gd32f10x_it.h"
#include "main.h"
#include "systick.h"
#include "gd32f10x_dma_config.h"
#include <stdbool.h>

//extern bool buttonState; // true: The button has been released. false: The button has been pressed.
//extern bool ledState; // true: LED on. false: LED off. 
extern int i;

/*!
    \brief      this function handles NMI exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void NMI_Handler(void)
{
}

/*!
    \brief      this function handles HardFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void HardFault_Handler(void)
{
    /* if Hard Fault exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles MemManage exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void MemManage_Handler(void)
{
    /* if Memory Manage exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles BusFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void BusFault_Handler(void)
{
    /* if Bus Fault exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles UsageFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void UsageFault_Handler(void)
{
    /* if Usage Fault exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles SVC exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SVC_Handler(void)
{
}

/*!
    \brief      this function handles DebugMon exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DebugMon_Handler(void)
{
}

/*!
    \brief      this function handles PendSV exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PendSV_Handler(void)
{
}

/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SysTick_Handler(void)
{
    delay_decrement();
}

extern uint32_t *usart0_dma_buffer;
extern uint32_t *usart0_data_buffer;
extern uint32_t usart0_data_num;

void USART0_IRQHandler(void)
{
	if(usart_rx_IRQHandler(USART0,usart0_dma_buffer,usart0_data_buffer,DATA_BUFFER_SIZE,&usart0_data_num)){
		printf("receive %d data : %s\n", usart0_data_num, (char*)usart0_data_buffer);
		usart0_data_num = 0;
	}
}

void USART1_IRQHandler(void)
{
	
}
void USART2_IRQHandler(void)
{

}

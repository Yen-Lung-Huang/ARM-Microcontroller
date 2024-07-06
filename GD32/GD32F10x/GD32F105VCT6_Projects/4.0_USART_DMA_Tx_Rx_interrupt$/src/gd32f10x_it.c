/*!
    \file    gd32e10x_it.c
    \brief   interrupt service routines
    

*/



#include "gd32f10x_it.h"
#include <string.h>



extern __IO FlagStatus g_transfer_complete;                                     // Controls when the reception ends 
extern uint8_t rxbuffer[];                                                      // Cyclic reception buffer
extern uint8_t rxtotal[];                                                       // Buffer storing total bytes to being received
extern const uint16_t rx_buf_size;                                              // Sets the sise of cyclic reception buffer
extern const uint16_t rx_tot_size;                                              // Sets total buffer storing size
extern const uint16_t rx_buf_half;                                              // For Half Transfer Interrupt (HTF) flag control
uint32_t cnt = 0;                                                               // Counter control for received bytes


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
    while (1);
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
    while (1);
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
    while (1);
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
    while (1);
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
}

/*!
    \brief      this function handles DMA0_Channel3_IRQHandler (Tx) interrupt
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DMA0_Channel3_IRQHandler(void)
{
    if(dma_interrupt_flag_get(DMA0, DMA_CH3, DMA_INT_FLAG_FTF)){     
        dma_interrupt_flag_clear(DMA0, DMA_CH3, DMA_INT_FLAG_G);
        g_transfer_complete = SET;
    }
}

/*!
    \brief      this function handles DMA0_Channel4_IRQHandler (Rx) interrupt
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DMA0_Channel4_IRQHandler(void)
{
 
    if(dma_interrupt_flag_get(DMA0, DMA_CH4, DMA_INT_FLAG_HTF)){         
        for (int i = 0; i < rx_buf_half; i++){
            rxtotal[cnt+i] = rxbuffer[i];
        }
        cnt+=rx_buf_half;
        dma_interrupt_flag_clear(DMA0, DMA_CH4, DMA_INT_FLAG_G);
        g_transfer_complete = SET;     
    }
    
     if(dma_interrupt_flag_get(DMA0, DMA_CH4, DMA_INT_FLAG_FTF)){          
        for(int i = 0; i < rx_buf_half; i++){
           rxtotal[cnt+i] = rxbuffer[rx_buf_half+i]; 
        }
        cnt+=rx_buf_half;
        dma_interrupt_flag_clear(DMA0, DMA_CH4, DMA_INT_FLAG_G);
        g_transfer_complete = SET;                    
    }
     if(cnt < rx_tot_size) g_transfer_complete = RESET;
       
  
}

#include "gd32f10x.h"
#include <stdio.h>

uint8_t rxbuffer[40];
uint16_t rxcount = 0;
void usart_config(void);
uint8_t txbuffer[] = "usart interrupt transmis & receive test";

int main()
{

	nvic_irq_enable(USART0_IRQn, 0, 0); //uart 中斷初始化 優先級 子優先級 設定
	usart_config(); 	//gpio  uart 初始化

	printf("%s", txbuffer);
	
	usart_interrupt_enable(USART0, USART_INT_RBNE);
	while(rxcount < 40){
  }
	printf("%s", rxbuffer);
	
  
	
		

}

void usart_config(void)
{
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOA);

    /* enable USART clock */
    rcu_periph_clock_enable(RCU_USART0);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);

    /* connect port to USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_10);

    /* USART configure */
    usart_deinit(USART0);
    usart_word_length_set(USART0, USART_WL_8BIT);
    usart_stop_bit_set(USART0, USART_STB_1BIT);
    usart_parity_config(USART0, USART_PM_NONE);
    usart_baudrate_set(USART0, 115200U);
    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);
    usart_enable(USART0);
}

int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART0, (uint8_t)ch);
    while(RESET == usart_flag_get(USART0, USART_FLAG_TBE));
    return ch;
}

void USART0_IRQHandler(void)
{																					//儲存空間沒有消耗完   
    if(RESET != usart_interrupt_flag_get(USART0, USART_INT_FLAG_RBNE)){  //read data buffer not empty interrupt and flag
        /* read one byte from the receive data register */
        rxbuffer[rxcount++] = (uint8_t)usart_data_receive(USART0); // i = 0 a[i++] 先輸出a[0] i才++

        if(rxcount >= 40) //當 儲存結束 離開中斷
        {
            /* disable the USART0 receive interrupt */
            usart_interrupt_disable(USART0, USART_INT_RBNE);
        }
    }       
}

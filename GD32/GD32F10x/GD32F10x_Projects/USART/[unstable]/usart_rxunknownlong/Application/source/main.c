#include "gd32f10x.h"
#include <stdio.h>
#include "systick.h"
#include <string.h>
uint8_t rxbuffer[40];
uint16_t rxcount = 0;
void usart_config(void);
void led_flash(int );
	
int main()
{
	systick_config();
	rcu_periph_clock_enable(RCU_GPIOD);
	gpio_init(GPIOD,GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_10);
	led_flash(1);
	usart_config(); 	//gpio  uart 初始化
	nvic_irq_enable(USART0_IRQn, 0, 0);  	//uart 中斷初始化 優先級 子優先級 設定
	usart_interrupt_enable(USART0, USART_INT_RBNE);
	usart_interrupt_enable(USART0, USART_INT_IDLE);
	printf("unknown data test\n");
	while(1){

					gpio_bit_write(GPIOD,GPIO_PIN_10,1);
//				delay_1ms(400);
//				gpio_bit_write(GPIOD,GPIO_PIN_10,0);
//				delay_1ms(400);
	}
	
  
	//儲存到 buffer 對應數量的位置 其餘不改變 多次存取將會印出 原先資料
	// buffer 大小不變 最多40筆資料

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


/*void usart_send(uint32_t usart_periph, uint8_t* data, uint16_t len)  // 一般方法 傳送資料 有printf 就不用了
{
	for(int i=0; i<len; i++)
	{
		usart_data_transmit(usart_periph, (uint8_t) (*(data + i)));  // USART发送数据功能
		while(RESET == usart_flag_get(usart_periph, USART_FLAG_TBE));// 获取USART STAT/CHC/RFCS寄存器标志位,USART_FLAG_TBE:发送数据缓冲区空标志
	}
}*/

void USART0_IRQHandler(void)
{
	gpio_bit_write(GPIOD,GPIO_PIN_10,0);
	if(RESET != usart_interrupt_flag_get(USART0, USART_INT_FLAG_RBNE))// 获取USART中断标志位状态
		                                                                // USART_INT_FLAG_RBNE:读数据缓冲区非空中断标志  (rxbuffer接收到數據時) 接收中斷 flag = 1
	{ 
		usart_interrupt_flag_clear(USART0, USART_INT_FLAG_RBNE);// 清除USART中断标志位状态
		usart_interrupt_flag_clear(USART0, USART_INT_FLAG_ERR_ORERR);
		uint8_t ch = (uint8_t)usart_data_receive(USART0);// USART接收数据功能
		
		if(rxcount < 40)
		{
			rxbuffer[rxcount++] = ch;  //i = 0 a[i++] 先輸出a[0] i才++
		}
	}

	if(RESET != usart_interrupt_flag_get(USART0, USART_INT_FLAG_IDLE))// USART_INT_FLAG_IDLE:IDLE线检测中断标志     空閒中斷 (完整接收一個字節 或多個字節) rx接收狀態 空閒沒有資料了 觸發中斷 flag = 1
	{
		usart_interrupt_flag_clear(USART0, USART_INT_FLAG_IDLE);
		usart_interrupt_flag_clear(USART0, USART_INT_FLAG_ERR_ORERR);
		if(rxcount > 0)
		{		
			usart_interrupt_disable(USART0, USART_INT_RBNE);// 失能USART中断
			usart_interrupt_disable(USART0, USART_INT_IDLE);
			
			/* 测试部分，接收到的数据最好在main中处理掉 */
			//usart_send(USART0, rxbuffer, rxcount);	
			printf("%s\n%d\n", rxbuffer, rxcount);
			memset(rxbuffer, 0, 40); // 清空rxbuffer
			rxcount = 0;
			usart_interrupt_enable(USART0, USART_INT_RBNE);
			usart_interrupt_enable(USART0, USART_INT_IDLE);
		}
	}
}

void led_flash(int times)
{
    int i;
    for(i=0; i<times; i++){
				gpio_bit_write(GPIOD,GPIO_PIN_10,1);
				delay_1ms(400);
				gpio_bit_write(GPIOD,GPIO_PIN_10,0);
				delay_1ms(400);
				
    }
}




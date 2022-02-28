#include "gd32f10x.h"
#include <stdio.h>
#include "systick.h"
#include <string.h>

extern uint8_t dma_buffer[];      //組數 設定給 RX
extern uint8_t rx_buffer[];
extern uint8_t usart_data_num;

void usart_dma_config(void)
{
		dma_parameter_struct dma_init_struct;  //設定DMA的結構定義
	
		rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_USART0);
		rcu_periph_clock_enable(RCU_DMA0);   //USART0 對應 DMA0
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_10);

    usart_deinit(USART0);
    usart_word_length_set(USART0, USART_WL_8BIT);
    usart_stop_bit_set(USART0, USART_STB_1BIT);
    usart_parity_config(USART0, USART_PM_NONE);
    usart_baudrate_set(USART0, 115200U);
    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);
    usart_enable(USART0);
	
		//USART0 DMA RX
    dma_deinit(DMA0, DMA_CH4);                              // USART0 DMA 接收配置
    dma_init_struct.direction = DMA_PERIPHERAL_TO_MEMORY;			// 外設到記憶體
		dma_init_struct.memory_addr = (uint32_t)dma_buffer;        //陣列只接傳地址  記憶體接收地址
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;  // 記憶體位址遞增
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;			//記憶體寬度為8位  一次傳8BIT
    dma_init_struct.number = 256;							//傳輸的總數量
    dma_init_struct.periph_addr = ((uint32_t)0x40013804);				//// 連接外設uart地址,USART數據暫存器地址
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE; // 外設地址不遞增
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;	// 外設數據位寬爲8位
    dma_init_struct.priority = DMA_PRIORITY_HIGH;       //DMA優先級高
		dma_init(DMA0, DMA_CH4, &dma_init_struct);
	
	  dma_circulation_disable(DMA0, DMA_CH4);
		dma_memory_to_memory_disable(DMA0, DMA_CH4);
		//dma_transfer_number_config(DMA0, DMA_CH4, 256);
    dma_channel_enable(DMA0, DMA_CH4);   //CH4  RX
	
    usart_dma_receive_config(USART0, USART_DENR_ENABLE);
		nvic_irq_enable(USART0_IRQn, 0, 0);
		usart_interrupt_enable(USART0, USART_INT_IDLE);
}

void led_init(void)
{
    rcu_periph_clock_enable(RCU_GPIOD);
    gpio_init(GPIOD,GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_15);
		
}

void led_flash(int times)
{
    int i;
    for(i=0; i<times; i++){
				gpio_bit_write(GPIOD,GPIO_PIN_15,SET);
				delay_1ms(400);
				gpio_bit_write(GPIOD,GPIO_PIN_15,RESET);
				delay_1ms(400);
				
    }
}

int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART0, (uint8_t)ch);
    while(RESET == usart_flag_get(USART0, USART_FLAG_TBE));
    return ch;
}

bool irq()
{
		if(RESET != usart_interrupt_flag_get(USART0, USART_INT_FLAG_IDLE))
		{
		    usart_interrupt_flag_clear(USART0, USART_INT_FLAG_IDLE);
		    while(0 != dma_flag_get(DMA0, DMA_CH4, DMA_FLAG_FTF)){  // 還沒搬完東西 0 full transfer finish flag of channel
        }
	      usart_data_receive(USART0);
				dma_channel_disable(DMA0, DMA_CH4);
				
				usart_data_num = 256 - dma_transfer_number_get(DMA0, DMA_CH4);
				memcpy(rx_buffer, dma_buffer, usart_data_num);
				rx_buffer[usart_data_num] = '\0';
				
				dma_memory_address_config(DMA0, DMA_CH4, (uint32_t)dma_buffer);
				dma_transfer_number_config(DMA0, DMA_CH4, 256);
				dma_channel_enable(DMA0, DMA_CH4);
				return TRUE;
		}
		else return FALSE;
}

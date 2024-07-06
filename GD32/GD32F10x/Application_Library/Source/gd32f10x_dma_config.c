#include "gd32f10x_dma_config.h"

void usart_dma_config(uint32_t usart_periph, UartDirection uart_direction,	uint8_t *dma_buffer, uint32_t transfer_amount, ControlStatus circular_mode)
{
	uint32_t memory_addr = (uint32_t)dma_buffer;
	
	rcu_periph_clock_enable(RCU_DMA0);     // enable DMA0 clock for USARTx. x=0~2
	dma_parameter_struct dma_init_struct;  //設定DMA的結構定義

	dma_init_struct.periph_addr  = USART_DATA(usart_periph);		// 連接外設(TX、RX)地址,USART數據暫存器地址(USART_DATA)
	dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;		// 外設數據位寬爲8位
	dma_init_struct.periph_inc   = DMA_PERIPH_INCREASE_DISABLE; // 外設地址不遞增
	dma_init_struct.memory_addr  = memory_addr;      				 		// DMA 記憶體地址
	dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;				// 記憶體寬度為8位
	dma_init_struct.memory_inc   = DMA_MEMORY_INCREASE_ENABLE;  // 記憶體位址遞增
	dma_init_struct.number       = transfer_amount;							// DMA 傳輸的總數量
	dma_init_struct.priority     = DMA_PRIORITY_HIGH;      			// DMA優先級高
	dma_init_struct.direction = uart_direction ? DMA_PERIPHERAL_TO_MEMORY : DMA_MEMORY_TO_PERIPHERAL; // ...? if( == RX) : if(TX == TX);

	switch (usart_periph){
		case USART0:
			uart_direction ? usart_dma_deinit(&dma_init_struct, DMA_CH4, transfer_amount, circular_mode)  //RX
										 : usart_dma_deinit(&dma_init_struct, DMA_CH3, transfer_amount, circular_mode); //TX
			nvic_irq_enable(USART0_IRQn, 0, 0);
			break;
		case USART1:
			uart_direction ? usart_dma_deinit(&dma_init_struct, DMA_CH5, transfer_amount, circular_mode)  //RX
										 : usart_dma_deinit(&dma_init_struct, DMA_CH6, transfer_amount, circular_mode); //TX
			nvic_irq_enable(USART1_IRQn, 0, 0);
			break;
		case USART2:
			uart_direction ? usart_dma_deinit(&dma_init_struct, DMA_CH2, transfer_amount, circular_mode)  //RX
										 : usart_dma_deinit(&dma_init_struct, DMA_CH1, transfer_amount, circular_mode); //TX
			nvic_irq_enable(USART2_IRQn, 0, 0);
			break;
	}
	
	usart_dma_receive_config(usart_periph, USART_DENR_ENABLE);
	usart_interrupt_enable(usart_periph, USART_INT_IDLE);
}

void usart_dma_deinit(dma_parameter_struct *dma_init_struct, dma_channel_enum channelx, uint32_t transfer_amount, uint32_t circular_mode){
	dma_deinit(DMA0, channelx);
	dma_init(DMA0, channelx, dma_init_struct);
	circular_mode ? dma_circulation_enable(DMA0, channelx) : dma_circulation_disable(DMA0, channelx);
	dma_memory_to_memory_disable(DMA0, channelx);
	dma_transfer_number_config(DMA0, channelx, transfer_amount);
	dma_channel_enable(DMA0, channelx);
}

bool usart_rx_IRQHandler(uint32_t usart_periph, uint8_t* dma_buffer, uint8_t* data_buffer, uint32_t transfer_amount)
{
	if(RESET != usart_interrupt_flag_get(usart_periph, USART_INT_FLAG_IDLE)){
		dma_channel_enum channelx = usart_rx_dma_channel(usart_periph);
		
		usart_interrupt_flag_clear(usart_periph, USART_INT_FLAG_IDLE);
		while(0 != dma_flag_get(DMA0, channelx, DMA_FLAG_FTF)){}  // full transfer finish flag of channel
		
		usart_data_receive(usart_periph);
		dma_channel_disable(DMA0, channelx);

		uint32_t usart_data_num = usart_data_amount(usart_periph,transfer_amount);
		memcpy(data_buffer, dma_buffer, usart_data_num);
		data_buffer[usart_data_num] = '\0';

		dma_memory_address_config(DMA0, channelx, (uint32_t)dma_buffer);
		dma_transfer_number_config(DMA0, channelx, transfer_amount);
		dma_channel_enable(DMA0, channelx);
		return TRUE;
	}
	else return FALSE;
}

dma_channel_enum usart_rx_dma_channel(uint32_t usart_periph)
{
	if     (usart_periph==USART0) return DMA_CH4;
	else if(usart_periph==USART1) return DMA_CH5;
	else if(usart_periph==USART2) return DMA_CH2;
	return DMA_CH4;
}

uint32_t usart_data_amount(uint32_t usart_periph, uint32_t transfer_amount)
{
	return transfer_amount - dma_transfer_number_get(DMA0, usart_rx_dma_channel(usart_periph));
}

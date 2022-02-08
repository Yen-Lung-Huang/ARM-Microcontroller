#include "gd32f10x_usart_config.h"

bool usart_periph_enable[3] = {false,false,false};

void usart_config(uint32_t usart_periph, uint32_t baudRate)
{
	switch(usart_periph){
		case USART0:
			usart_periph_enable[0] = true;
			rcu_periph_clock_enable(RCU_GPIOA); /* enable GPIO clock */
			rcu_periph_clock_enable(RCU_USART0); /* enable USART clock */
			gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9); /* connect port to USART0_TX */
			gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_10); /* connect port to USART0_RX */
			break;
		case USART1:
			usart_periph_enable[1] = true;
			rcu_periph_clock_enable(RCU_GPIOA); /* enable GPIO clock */
			rcu_periph_clock_enable(RCU_USART1); /* enable USART clock */
			gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2); /* connect port to USART1_TX */
			gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_3); /* connect port to USART1_RX */
			break;
		case USART2:
			usart_periph_enable[2] = true;
			rcu_periph_clock_enable(RCU_GPIOB); /* enable GPIO clock */
			rcu_periph_clock_enable(RCU_USART2); /* enable USART clock */
			gpio_init(GPIOB, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10); /* connect port to USART2_TX */
			gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_11); /* connect port to USART2_RX */
			break;
	}
	
	/* USART configure */
	usart_deinit(usart_periph);
	usart_word_length_set(usart_periph, USART_WL_8BIT);
	usart_stop_bit_set(usart_periph, USART_STB_1BIT);
	usart_parity_config(usart_periph, USART_PM_NONE);
	usart_baudrate_set(usart_periph, baudRate);
	usart_receive_config(usart_periph, USART_RECEIVE_ENABLE);
	usart_transmit_config(usart_periph, USART_TRANSMIT_ENABLE);
	usart_enable(usart_periph);
}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
	if(usart_periph_enable[0] == true){
    usart_data_transmit(USART0, (uint8_t)ch);
		while(RESET == usart_flag_get(USART0, USART_FLAG_TBE)||RESET == usart_flag_get(USART0, USART_FLAG_TC));
	}
	if(usart_periph_enable[1] == true){
    usart_data_transmit(USART1, (uint8_t)ch);
		while(RESET == usart_flag_get(USART1, USART_FLAG_TBE)||RESET == usart_flag_get(USART1, USART_FLAG_TC));
	}
	if(usart_periph_enable[2] == true){
    usart_data_transmit(USART2, (uint8_t)ch);
		while(RESET == usart_flag_get(USART2, USART_FLAG_TBE)||RESET == usart_flag_get(USART2, USART_FLAG_TC));
	}
	return ch;
}

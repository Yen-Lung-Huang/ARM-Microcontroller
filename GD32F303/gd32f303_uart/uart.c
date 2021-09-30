/* 串口硬體初始化 */
#include "uart.h"

/* 發送緩存 */
#define UART0_TX_LEN		256				/* 單次最大發送緩存位元組數 */
uint8_t UART0_TX_BUF[UART0_TX_LEN]; 		/* 發送緩衝區 */
uint8_t DMA_BUF_BUSY = 0 ;					/* 緩衝區是否已被佔用 */

#ifdef UART0_RX
	/* 接收緩存 */
	#define UART0_RX_LEN		256				/* 單個緩存區位元組數 */
	uint8_t UART0_RX_BUF[UART0_RX_LEN*2]; 		/* 雙接收緩衝區 */
	uint8_t UART0_RX_STAT = 0;					/* 接受狀態 0x01:已接收到資料  0x03:接收緩衝區半滿  0x07:接收緩衝區全滿 */
	uint32_t UART0_RX_NUM = 0;					/* 接收到的資料個數 */
#endif


/* USART0串口初始化函數
 * 參數：串列傳輸速率
 * 返回值：無	*/
void uart0_init(uint32_t bound)
{	
	/* 使能 GPIOA 時鐘 */
    rcu_periph_clock_enable(RCU_GPIOA);

    /* 使能 USART0 時鐘 */
    rcu_periph_clock_enable(RCU_USART0);

    /* PA9  複用為 USART0_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_9);

    /* PA10 複用為 USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ,GPIO_PIN_10);

    /* USART0 初始化配置 */
    usart_deinit(USART0);
    usart_baudrate_set(USART0, bound);						/* 設置串列傳輸速率 */
    usart_receive_config(USART0, USART_RECEIVE_ENABLE);		/* 使能接收 */
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);	/* 使能發送 */	
		usart_enable(USART0); /* 使能串口0 */
	

	#ifdef UART0_DMA
		/* 定義一個DMA配置結構體 */
		dma_parameter_struct dma_init_struct;
    /* 使能 DMA 時鐘 */
    rcu_periph_clock_enable(RCU_DMA0);
	
		/* 初始化 DMA0 通道3 */
    dma_deinit(DMA0, DMA_CH3);
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;		/* 記憶體到外設方向 */
    dma_init_struct.memory_addr = (uint32_t)UART0_TX_BUF;		/* 記憶體基底位址 */
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;	/* 記憶體位址自增 */
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;		/* 記憶體位寬為8位 */
    dma_init_struct.number = UART0_TX_LEN;						/* 傳輸資料個數 */
    dma_init_struct.periph_addr = ((uint32_t)0x40013804);		/* 外設基底位址，即USART資料寄存器位址 */
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;	/* 外設地址固定不變 */
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;	/* 外設資料位元寬為8位元 */
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;			/* 軟體優先順序為極高*/
    dma_init(DMA0, DMA_CH3, dma_init_struct);
    
    /* DMA迴圈模式配置，不使用迴圈模式 */
    dma_circulation_disable(DMA0, DMA_CH3);
		/* DMA記憶體到記憶體模式模式配置，不使用記憶體到記憶體模式*/
    dma_memory_to_memory_disable(DMA0, DMA_CH3);

    /* USART DMA 發送使能 */
    usart_dma_transmit_config(USART0, USART_DENT_ENABLE);
		/* DMA0 通道3 中斷優先順序設置並使能 */
		nvic_irq_enable(DMA0_Channel3_IRQn, 0, 0);
		/* 使能 DMA0 通道3 傳輸完成、傳輸錯誤中斷 */
    dma_interrupt_enable(DMA0, DMA_CH3, DMA_INT_FTF|DMA_INT_ERR);
    /* 使能 DMA0 通道3 */
    dma_channel_enable(DMA0, DMA_CH3);
	#endif

	#ifdef UART0_RX
		#ifndef UART0_DMA
			/* 定義一個DMA配置結構體 */
			dma_parameter_struct dma_init_struct;
			/* 使能 DMA 時鐘 */
			rcu_periph_clock_enable(RCU_DMA0);
		#endif
		
		/* 初始化 DMA0 通道4 */
    dma_deinit(DMA0, DMA_CH4);
    dma_init_struct.direction = DMA_PERIPHERAL_TO_MEMORY;		/* 外設到記憶體方向 */
    dma_init_struct.memory_addr = (uint32_t)UART0_RX_BUF;		/* 記憶體基底位址 */
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;	/* 記憶體位址自增 */
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;		/* 記憶體位寬為8位 */
    dma_init_struct.number = UART0_RX_LEN*2;					/* 傳輸資料個數 */
    dma_init_struct.periph_addr = ((uint32_t)0x40013804);		/* 外設基底位址，即USART資料寄存器位址 */
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;	/* 外設地址固定不變 */
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;	/* 外設資料位元寬為8位元 */
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;			/* 軟體優先順序為極高*/
    dma_init(DMA0, DMA_CH4, dma_init_struct);
    
    /* DMA迴圈模式配置，不使用迴圈模式 */
    dma_circulation_disable(DMA0, DMA_CH4);
		/* DMA記憶體到記憶體模式模式配置，不使用記憶體到記憶體模式*/
    dma_memory_to_memory_disable(DMA0, DMA_CH4);

    /* USART DMA 發送和接收使能 */
    usart_dma_transmit_config(USART0, USART_DENT_ENABLE|USART_DENR_ENABLE);
		/* DMA0 通道4 中斷優先順序設置並使能 */
		nvic_irq_enable(DMA0_Channel4_IRQn, 0, 0);
		/* 使能 DMA0 通道4 半傳輸、傳輸完成、傳輸錯誤中斷 */
    dma_interrupt_enable(DMA0, DMA_CH4, DMA_INT_FTF|DMA_INT_HTF|DMA_INT_ERR);
    /* 使能 DMA0 通道4 */
    dma_channel_enable(DMA0, DMA_CH4);

		/* USART中斷設置，搶佔優先順序0，子優先順序0 */
		nvic_irq_enable(USART0_IRQn, 0, 0); 
		/* 使能USART0空閒中斷 */
    usart_interrupt_enable(USART0, USART_INT_IDLE);
	#endif
}

#ifdef UART0_DMA
/* 自訂UART0 printf 函數
 * 參數：帶發送的字串，確保一次發送資料不超過UART0_TX_LEN位元組
 * 返回值：無	*/
void u1_printf(char* fmt,...)  
{
	uint32_t i;
	va_list ap; 
	va_start(ap,fmt);
	
	while(DMA_BUF_BUSY == 1);
	DMA_BUF_BUSY = 1;
	
	vsprintf((char*)UART0_TX_BUF,fmt,ap);
	va_end(ap);
	UART0_TX_BUF[UART0_TX_LEN-1] = '\0';
	
	/* 計算此次發送資料的長度 */
	i=strlen((const char*)(UART0_TX_BUF));
	
	/* 設置DMA傳輸 */
	dma_channel_disable(DMA0, DMA_CH3);		/* 關閉DMA傳輸才可以進行設置 */
	dma_memory_address_config(DMA0,DMA_CH3,(uint32_t)(UART0_TX_BUF));
	dma_transfer_number_config(DMA0,DMA_CH3,i);
	dma_channel_enable(DMA0, DMA_CH3);		/* 開啟DMA傳輸 */
}
#else
/* 加入以下代碼,支援printf函數,而不需要選擇use MicroLIB	*/  
#pragma import(__use_no_semihosting)             
/* 標準庫需要的支援函數 */                
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
/* 定義_sys_exit()以避免使用半主機模式  */  
void _sys_exit(int x) 
{ 
	x = x; 
} 

/* 重定義fputc函數 */
int fputc(int ch, FILE *f)
{   
	while (RESET == usart_flag_get(USART0, USART_FLAG_TBE))
		;	
	usart_data_transmit(USART0, (uint8_t)ch);

	return ch;
}
#endif


/* DMA0 通道3 中斷服務函數
 * 參數：無
 * 返回值：無	*/
void DMA0_Channel3_IRQHandler(void)
{
	/* 清除DMA0 通道3 中斷標誌位元 */
	dma_interrupt_flag_clear(DMA0, DMA_CH3, DMA_INT_FLAG_G);
	/* 進入中斷，表示已經傳輸完成緩衝區，釋放緩衝區 */
	if(DMA_BUF_BUSY == 1) DMA_BUF_BUSY = 0;
}

#ifdef UART0_RX
/* USART0 中斷服務函數
 * 參數：無
 * 返回值：無	*/
/* 串口0中斷服務程式 */
void USART0_IRQHandler(void)	
{
    if(RESET != usart_interrupt_flag_get(USART0, USART_INT_FLAG_IDLE)) //空閒中斷
	{
		usart_interrupt_flag_clear(USART0,USART_INT_FLAG_IDLE);	/* 清除空閒中斷標誌位元 */
		usart_data_receive(USART0);								/* 清除接收完成標誌位元 */
		dma_channel_disable(DMA0, DMA_CH4);						/* 關閉DMA傳輸 */
		
		UART0_RX_NUM = sizeof(UART0_RX_BUF) - dma_transfer_number_get(DMA0,DMA_CH4);
		UART0_RX_BUF[UART0_RX_NUM] = '\0';	/* 添加字串結束符 */
		UART0_RX_STAT = 0x01;				/* 接受狀態 0x01:已接收到資料 */
		
		/* 重新設置DMA傳輸 */
		dma_memory_address_config(DMA0,DMA_CH4,(uint32_t)UART0_RX_BUF);
		dma_transfer_number_config(DMA0,DMA_CH4,sizeof(UART0_RX_BUF));
		dma_channel_enable(DMA0, DMA_CH4);		/* 開啟DMA傳輸 */
    }
}


/* DMA0 通道4 中斷服務函數
 * 參數：無
 * 返回值：無	*/
void DMA0_Channel4_IRQHandler(void)
{
	/* 清除DMA0 通道4 中斷標誌位元 */
	dma_interrupt_flag_clear(DMA0, DMA_CH4, DMA_INT_FLAG_G);
	if(dma_interrupt_flag_get(DMA0, DMA_CH4, DMA_INT_FLAG_HTF))
	{
		UART0_RX_NUM = UART0_RX_LEN;
		UART0_RX_BUF[UART0_RX_LEN] = '\0';		/* 添加字串結束符 */
		UART0_RX_STAT = 0x03;					/* 接受狀態 0x03:接收緩衝區半滿 */
	}
	if(dma_interrupt_flag_get(DMA0, DMA_CH4, DMA_INT_FLAG_FTF))
	{
		UART0_RX_NUM = UART0_RX_LEN*2;
		UART0_RX_BUF[UART0_RX_LEN*2-1] = '\0';	/* 添加字串結束符 */
		UART0_RX_STAT = 0x07;					/* 接受狀態 0x07:接收緩衝區全滿 */
	}
}

#endif


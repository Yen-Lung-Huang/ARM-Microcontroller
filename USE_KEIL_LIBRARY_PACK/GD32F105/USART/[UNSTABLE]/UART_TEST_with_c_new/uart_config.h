#ifndef __USART_H
	#define __USART_H
	#include "gd32f10x.h"
	#include <stdio.h>
	#include <string.h>	
	#include <stdarg.h>
	#define UART1_RX
	#define UART1_DMA
#endif

/* 定義串口週邊地址 */
#define USART1_TDATA_ADDRESS (USART1 + 0x00000004U)// 串口TX週邊地址
#define USART1_RDATA_ADDRESS (USART1 + 0x00000004U)// 串口RX週邊地址

/* 函數原型宣告 */
void usart1_config(uint32_t baudrate);
void uart1_transmit(uint8_t *data);
void USART1_IRQHandler(void);
void DMA0_Channel6_IRQHandler(void);
void DMA0_Channel5_IRQHandler(void);
void USART1_vsprintf(const char* format,...);

/* 定義發送緩存 */
#define UART1_TX_LEN 32				/* 單次最大發送緩存位元組數 */
static uint8_t UART1_TX_BUF[UART1_TX_LEN]; 		/* 發送緩衝區 */
static uint8_t DMA_BUF_BUSY = 0 ;					/* 緩衝區是否已被佔用 */

#ifdef UART1_RX
/* 定義接收緩存 */
#define UART1_RX_LEN 32				/* 單個緩存區位元組數 */
static uint8_t UART1_RX_BUF[UART1_RX_LEN*2]; /* 雙接收緩衝區 */
static uint8_t UART1_RX_STAT = 0;					/* 接受狀態 0x01:已接收到資料  0x03:接收緩衝區半滿  0x07:接收緩衝區全滿 */
static uint32_t UART1_RX_NUM = 0;					/* 接收到的資料個數 */
static uint8_t rx1_data_buffer[32];// 待處理串列數據緩衝區
#endif

/* USART1串口初始化函數
 * 參數：串列傳輸速率
 * 返回值：無	*/
void usart1_config(uint32_t baudrate)
{	
	rcu_periph_clock_enable(RCU_GPIOA);	//enable GPIOA clock, PA2/PA3
	rcu_periph_clock_enable(RCU_USART1);	//enable UART1 clock
	gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2);	//PA2--TX /* PA2  複用為 USART1_Tx */
	gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_3);	//PA3--RX /* PA3 複用為 USART1_Rx */
				
	/* USART1 初始化配置 */ //UART1: 115200-8-1-N
	usart_deinit(USART1);
	usart_baudrate_set(USART1, baudrate);	/* 設置串列傳輸速率 */
	usart_word_length_set(USART1, USART_WL_8BIT);
    //usart_stop_bit_set(USART1, USART_STB_1BIT);
    //usart_parity_config(USART1, USART_PM_NONE);
    //usart_hardware_flow_rts_config(USART1, USART_RTS_DISABLE);
    //usart_hardware_flow_cts_config(USART1, USART_CTS_DISABLE);
	usart_receive_config(USART1, USART_RECEIVE_ENABLE); /* 使能接收 */
	usart_transmit_config(USART1, USART_TRANSMIT_ENABLE);	/* 使能發送 */	
	usart_enable(USART1);	/* 使能串列1 */
	

	#ifdef UART1_DMA
		dma_parameter_struct dma_init_struct; //定義一個DMA配置結構體
    rcu_periph_clock_enable(RCU_DMA0); //使能 DMA 時鐘
	
		/* 初始化USART1_TX的DMA(DMA0 通道6) */
    dma_deinit(DMA0, DMA_CH6); //復位DMA0通道6的所有寄存器
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;		/* 記憶體到外設方向 */ // DMA通道數據傳輸方向
    dma_init_struct.memory_addr = (uint32_t)UART1_TX_BUF;		/* 記憶體基底位址 */
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;	/* 記憶體位址自增 */ // 記憶體地址生成算法模式
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;		//記憶體數據傳輸寬度設為8位元
    dma_init_struct.number = UART1_TX_LEN;						/* 傳輸資料個數 */ // DMA通道數據傳輸量 
    dma_init_struct.periph_addr = USART1_TDATA_ADDRESS;		/* 外設基底位址，即USART資料寄存器位址 */
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;	/* 外設地址固定不變 */ // 外設地址生成算法模式
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;	/* 外設資料位元寬度為8位元 */
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;			/* DMA通道傳輸軟體優先順序為極高*/
    dma_init(DMA0, DMA_CH6, &dma_init_struct); // 初始化DMA0通道6
    dma_circulation_disable(DMA0, DMA_CH6); /* DMA迴圈模式配置，不使用迴圈模式 */
    //dma_memory_to_memory_disable(DMA0, DMA_CH6); /* DMA記憶體到記憶體模式模式配置，不使用記憶體到記憶體模式*/
    
		usart_dma_transmit_config(USART1, USART_DENT_ENABLE); /* USART DMA 發送使能 */

		nvic_irq_enable(DMA0_Channel6_IRQn, 0, 0); 	/* DMA0 通道6 中斷優先順序設置並使能 */
    dma_interrupt_enable(DMA0, DMA_CH6, DMA_INT_FTF|DMA_INT_ERR); /* 使能 DMA0 通道6 */
    dma_channel_enable(DMA0, DMA_CH6); /* 使能 DMA0 通道6 */
	#endif

	#ifdef UART1_RX
		#ifndef UART1_DMA
			/* 定義一個DMA配置結構體 */
			dma_parameter_struct dma_init_struct;
			/* 使能 DMA 時鐘 */
			rcu_periph_clock_enable(RCU_DMA0);
		#endif
	
		/* 初始化 DMA0 通道5 (RX)*/
    dma_deinit(DMA0, DMA_CH5);
    dma_init_struct.direction = DMA_PERIPHERAL_TO_MEMORY;		/* 外設到記憶體方向 */
    dma_init_struct.memory_addr = (uint32_t)UART1_RX_BUF;		/* 記憶體基底位址 */
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;	/* 記憶體位址自增 */
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;		/* 記憶體位寬為8位 */
    dma_init_struct.number = UART1_RX_LEN*2;					/* 傳輸資料個數 */
    dma_init_struct.periph_addr = USART1_RDATA_ADDRESS;		/* 外設基底位址，即USART資料寄存器位址 */
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;	/* 外設地址固定不變 */
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;	/* 外設資料位元寬為8位元 */
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;			/* 軟體優先順序為極高*/
    dma_init(DMA0, DMA_CH5, &dma_init_struct);
    
    /* DMA迴圈模式配置，不使用迴圈模式 */
    dma_circulation_disable(DMA0, DMA_CH5);
		/* DMA記憶體到記憶體模式模式配置，不使用記憶體到記憶體模式*/
    dma_memory_to_memory_disable(DMA0, DMA_CH5);

    /* USART DMA 發送和接收使能 */
    usart_dma_transmit_config(USART1, USART_DENT_ENABLE|USART_DENR_ENABLE);
		/* DMA0 通道5 中斷優先順序設置並使能 */
		nvic_irq_enable(DMA0_Channel5_IRQn, 0, 0);
		/* 使能 DMA0 通道5 半傳輸、傳輸完成、傳輸錯誤中斷 */
    dma_interrupt_enable(DMA0, DMA_CH5, DMA_INT_FTF|DMA_INT_HTF|DMA_INT_ERR);
    /* 使能 DMA0 通道5 */
    dma_channel_enable(DMA0, DMA_CH5);
	
		/* USART中斷設置，搶佔優先順序0，子優先順序0 */
		nvic_irq_enable(USART1_IRQn, 0, 0); 
		/* 使能USART1空閒中斷 */
    usart_interrupt_enable(USART1, USART_INT_IDLE);
	#endif
}

#ifdef UART1_DMA
	/* 自訂UART1 printf 函數
	 * 參數：帶發送的字串，確保一次發送資料不超過UART1_TX_LEN位元組
	 * 返回值：無	*/
	void uart1_transmit(uint8_t *data) { //UART1 發送數據函數
		uint32_t i;
		for(i=0; i<strlen((char*)data); i++) {
			usart_data_transmit(USART1, data[i]);
			while (RESET == usart_flag_get(USART1, USART_FLAG_TBE));
		}
		
		/* 設置DMA傳輸 */
		dma_channel_disable(DMA0, DMA_CH6);		/* 關閉DMA傳輸才可以進行設置 */
		dma_memory_address_config(DMA0,DMA_CH6,(uint32_t)(UART1_TX_BUF));
		dma_transfer_number_config(DMA0,DMA_CH6,i);
		dma_channel_enable(DMA0, DMA_CH6);		/* 開啟DMA傳輸 */
	}
	
	void USART1_vsprintf(const char* format,...)  
{
	va_list argptr;
	va_start(argptr,format);
	
	while(DMA_BUF_BUSY == 1);
	DMA_BUF_BUSY = 1;
	
	vsprintf((char*)UART1_TX_BUF,format,argptr);
	va_end(argptr);
	UART1_TX_BUF[sizeof(UART1_TX_BUF)-1] = '\0';
	
	/* 設置DMA傳輸 */
	dma_channel_disable(DMA0, DMA_CH6); // 關閉DMA傳輸才可以進行設置
	dma_memory_address_config(DMA0,DMA_CH6,(uint32_t)(UART1_TX_BUF));
	dma_transfer_number_config(DMA0,DMA_CH6,strlen((const char*)(UART1_TX_BUF))); // strlen(...)：計算此次發送數據的長度
	dma_channel_enable(DMA0, DMA_CH6); // 開啓DMA傳輸
}
#endif


/* DMA0 通道6 中斷服務函數
 * 參數：無
 * 返回值：無	*/
void DMA0_Channel6_IRQHandler(void)
{
	/* 清除DMA0 通道6 中斷標誌位元 */
	dma_interrupt_flag_clear(DMA0, DMA_CH6, DMA_INT_FLAG_G);
	/* 進入中斷，表示已經傳輸完成緩衝區，釋放緩衝區 */
	if(DMA_BUF_BUSY == 1) DMA_BUF_BUSY = 0;
	for(uint32_t i=0; i<sizeof(UART1_TX_BUF);i++){ //清空傳輸Buffer
		UART1_TX_BUF[i]=NULL;
	}
}

#ifdef UART1_RX
	/* USART1 中斷服務函數
	 * 參數：無
	 * 返回值：無	*/
	/* 串口1中斷服務程式 */
	void USART1_IRQHandler(void)	
	{
		if(RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_IDLE)){ //空閒中斷
			usart_interrupt_flag_clear(USART1,USART_INT_FLAG_IDLE);	/* 清除空閒中斷標誌位元 */
			
			usart_data_receive(USART1); /* 清除接收完成標誌位元 */
			dma_channel_disable(DMA0, DMA_CH5);						/* 關閉DMA傳輸 */
			
			UART1_RX_NUM = sizeof(UART1_RX_BUF) - dma_transfer_number_get(DMA0,DMA_CH5);
			//memcpy(rx1_data_buffer,UART1_RX_BUF,UART1_RX_NUM); // 轉存數據到待處理數據緩衝區
			UART1_RX_BUF[UART1_RX_NUM] = '\0';	/* 添加字串結束符 */
			UART1_RX_STAT = 0x01;				/* 接受狀態 0x01:已接收到資料 */
				
			/* 重新設置DMA傳輸 */
			dma_memory_address_config(DMA0,DMA_CH5,(uint32_t)UART1_RX_BUF);
			dma_transfer_number_config(DMA0,DMA_CH5,sizeof(UART1_RX_BUF));
			dma_channel_enable(DMA0, DMA_CH5);		/* 開啟DMA傳輸 */
			
		}
	}

	/* DMA0 通道5 中斷服務函數
	 * 參數：無
	 * 返回值：無	*/
	void DMA0_Channel5_IRQHandler(void)
	{
		/* 清除DMA0 通道5 中斷標誌位元 */
		dma_interrupt_flag_clear(DMA0, DMA_CH5, DMA_INT_FLAG_G);
		if(dma_interrupt_flag_get(DMA0, DMA_CH5, DMA_INT_FLAG_HTF)){
			UART1_RX_NUM = UART1_RX_LEN;
			UART1_RX_BUF[UART1_RX_LEN] = '\0';		/* 添加字串結束符 */
			UART1_RX_STAT = 0x03;					/* 接受狀態 0x03:接收緩衝區半滿 */
			uart1_transmit((uint8_t*)"\r\ntest_接受狀態 0x03:接收緩衝區半滿\n");
		}
		if(dma_interrupt_flag_get(DMA0, DMA_CH5, DMA_INT_FLAG_FTF)){
			UART1_RX_NUM = UART1_RX_LEN*2;
			UART1_RX_BUF[UART1_RX_LEN*2-1] = '\0';	/* 添加字串結束符 */
			UART1_RX_STAT = 0x07;					/* 接受狀態 0x07:接收緩衝區全滿 */
			uart1_transmit((uint8_t*)"\r\ntest_接受狀態 0x07:接收緩衝區全滿\n");
		}
	}
#endif

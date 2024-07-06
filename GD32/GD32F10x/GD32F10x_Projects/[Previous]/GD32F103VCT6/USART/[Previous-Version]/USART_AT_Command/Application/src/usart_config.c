#include "usart_config.h"

/* 定義串列外設地址 */
#define USART1_TDATA_ADDRESS (USART1 + 0x00000004U)// 串口TX週邊地址
#define USART1_RDATA_ADDRESS (USART1 + 0x00000004U)// 串口RX週邊地址 /*GD32f10x串列的TX及RX共用同個外設地址*/


uint8_t USART1_TX_BUF[USART1_BUF_LEN];   // DMA發送緩衝區
uint8_t USART1_RX_BUF[USART1_BUF_LEN];   // DMA接收緩衝區
uint8_t USART1_RX_STAT = 0;	 // 接受狀態 0x01:已接收到資料  0x03:接收緩衝區半滿  0x07:接收緩衝區全滿
uint32_t USART1_RX_NUM = 0;   // 待處理數據個數：大於1為有數據待處理，0為沒有數據待處理
bool DMA_BUF_BUSY = 0;

void USART1_init(uint32_t baudrate)
{
	rcu_periph_clock_enable(RCU_GPIOA);		// 啟用 GPIOA 時鐘, PA2/PA3
  rcu_periph_clock_enable(RCU_USART1);	// 啟用 USART1 時鐘
	rcu_periph_clock_enable(RCU_DMA0);		// 啟用 DMA0 時鐘 // CH6:TX, CH5:RX
	dma_parameter_struct dma_init_struct; // 定義一個DMA配置參數結構體
	
	gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_2);       // PA2 復用為 USART1_TX
	gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ,GPIO_PIN_3); // PA3 復用為 USART1_RX
	
	
	usart_deinit(USART1);                                 // USART1 初始化配置
	usart_baudrate_set(USART1, baudrate);                 // 設定 USART1 的 Baud
	usart_receive_config(USART1, USART_RECEIVE_ENABLE);		// 啟用接收
	usart_transmit_config(USART1, USART_TRANSMIT_ENABLE);	// 啟用發送	
	usart_enable(USART1); // 啟用USART1
	
	/* USART1_TX DMA0_CH6 init*/
	dma_deinit(DMA0, DMA_CH6);                                     // USART1 DMA發送配置
	dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;          // 記憶體到外設方向
	dma_init_struct.memory_addr = (uint32_t)USART1_TX_BUF;		     // 記憶體基地址
	dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;	     // 記憶體地址遞增
	dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;		       // 記憶體位寬為8位
	dma_init_struct.number = sizeof(USART1_TX_BUF);						     // 傳輸數據數
	dma_init_struct.periph_addr = ((uint32_t)USART1_TDATA_ADDRESS);// 外設基地址,即USART數據暫存器地址
	dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;	     // 外設地址固定不變
	dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;	     // 外設數據位寬爲8位
	dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;		         // DMA通道優先級設為極高
	dma_init(DMA0, DMA_CH6, &dma_init_struct);                     // 按照結構體的配置初始化DMA0_CH6
	dma_circulation_disable(DMA0, DMA_CH6);                        // DMA迴圈模式配置,不使用迴圈模式
	dma_memory_to_memory_disable(DMA0, DMA_CH6);                   // DMA記憶體到記憶體模式配置，不使用記憶體到記憶體模式

	usart_dma_transmit_config(USART1, USART_DENT_ENABLE);          // 啟用USART1 TX DMA發送

	nvic_irq_enable(DMA0_Channel6_IRQn, 0, 0);                     // DMA0通道6中斷優先級設置搶佔優先級0、子優先級0並啟用
	dma_interrupt_enable(DMA0, DMA_CH6, DMA_INT_FTF|DMA_INT_ERR);  // 啟用DMA0通道6傳輸完成、傳輸錯誤中斷
	dma_channel_enable(DMA0, DMA_CH6);                             // 啟用DMA0_CH5傳輸
	
	/* USART1_RX DMA0_CH5 init*/
	dma_deinit(DMA0, DMA_CH5);                                     // USART1 DMA 接收配置
	dma_init_struct.direction = DMA_PERIPHERAL_TO_MEMORY;		       // 外設到記憶體方向
	dma_init_struct.memory_addr = (uint32_t)USART1_RX_BUF;			   // 設定記憶體接收Base地址
	dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;	     // 記憶體地址遞增
	dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;		       // 記憶體位寬為8位
	dma_init_struct.number = sizeof(USART1_RX_BUF)*2;              // 傳輸數據數
	dma_init_struct.periph_addr = ((uint32_t)USART1_RDATA_ADDRESS);// 外設基地址,USART數據暫存器地址
	dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;			 // 外設地址不遞增
	dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;      // 外設數據位寬爲8位
	dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;			       // DMA通道優先級設為極高
	dma_init(DMA0, DMA_CH5, &dma_init_struct); 					           // 按照結構體的配置初始化DMA0_CH5
	dma_circulation_disable(DMA0, DMA_CH5);			                   // DMA迴圈模式配置,不使用迴圈模式
	dma_memory_to_memory_disable(DMA0, DMA_CH5);	                 // DMA記憶體到記憶體模式模式配置，不使用記憶體到記憶體模式
	
	usart_dma_receive_config(USART1, USART_DENT_ENABLE|USART_DENR_ENABLE);   // 啟用USART1 RX DMA發送和接收 //?
	
  nvic_irq_enable(DMA0_Channel5_IRQn, 0, 0);
	dma_interrupt_enable(DMA0, DMA_CH5, DMA_INT_FTF|DMA_INT_HTF|DMA_INT_ERR);// 啟用DMA0_CH5 半傳輸、傳輸完成、傳輸錯誤中斷
	dma_channel_enable(DMA0, DMA_CH5);	                                     // 啟用DMA0_CH5傳輸
	nvic_irq_enable(USART1_IRQn, 0, 0);	                                     // USART中斷優先級設置搶佔優先級0、子優先級0並啟用
	usart_interrupt_enable(USART1, USART_INT_IDLE);                          // 啟用發送完成中斷、空閒中斷 (別加USART_INT_TC|)

}

void USART1_transmit(uint8_t* data)
{
	uint16_t i;
	for(i=0; i<strlen((char*)data); i++){
		usart_data_transmit(USART1, data[i]); // USART發送數據功能
    while(RESET == usart_flag_get(USART1, USART_FLAG_TBE)); // 獲取 USART STAT/CHC/RFCS寄存器標誌位址
	}
}

void DMA0_Channel6_IRQHandler(void)
{
	dma_interrupt_flag_clear(DMA0, DMA_CH6, DMA_INT_FLAG_G); // 清除DMA0通道6中斷標誌位
	if(DMA_BUF_BUSY == 1) DMA_BUF_BUSY = 0; // 進入中斷，表示已經傳輸完成緩衝區，釋放緩衝區
	/*for(uint32_t i=0; i<sizeof(USART1_TX_BUF);i++){ //清空傳輸Buffer
		USART1_TX_BUF[i]=NULL;
	}*/
}

void DMA0_Channel5_IRQHandler(void)
	{
		/* 清除DMA0 通道5 中斷標誌位元 */
		dma_interrupt_flag_clear(DMA0, DMA_CH5, DMA_INT_FLAG_G);
		if(dma_interrupt_flag_get(DMA0, DMA_CH5, DMA_INT_FLAG_HTF)){
			USART1_RX_NUM = strlen((char*)USART1_RX_BUF);
			USART1_RX_BUF[strlen((char*)USART1_RX_BUF)] = '\0';		/* 添加字串結束符 */
			USART1_RX_STAT = 0x03;					/* 接受狀態 0x03:接收緩衝區半滿 */
			USART1_transmit((uint8_t*)"\r\ntest_接受狀態 0x03:接收緩衝區半滿\n");
		}
		if(dma_interrupt_flag_get(DMA0, DMA_CH5, DMA_INT_FLAG_FTF)){
			USART1_RX_NUM = strlen((char*)USART1_RX_BUF)*2;
			USART1_RX_BUF[strlen((char*)USART1_RX_BUF)*2-1] = '\0';	/* 添加字串結束符 */
			USART1_RX_STAT = 0x07;					/* 接受狀態 0x07:接收緩衝區全滿 */
			USART1_transmit((uint8_t*)"\r\ntest_接受狀態 0x07:接收緩衝區全滿\n");
		}
	}

void USART1_IRQHandler(void)	//串列1中斷服務程序
{
	if(RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_IDLE)) // 空閒中斷
	{
		usart_interrupt_flag_clear(USART1,USART_INT_FLAG_IDLE);	// 清除空閒中斷標誌位址
		usart_data_receive(USART1);	// 清除接收完成標誌位址
		dma_channel_disable(DMA0, DMA_CH5); // 關閉DMA傳輸
		
		USART1_RX_NUM = sizeof(USART1_RX_BUF) - dma_transfer_number_get(DMA0,DMA_CH5);
		USART1_RX_BUF[USART1_RX_NUM] = '\0'; // 添加字符串結束符
		USART1_RX_STAT = 0x01;				// 接受狀態 0x01:已接收到資料
		
		/* 重新設置DMA傳輸 */
		dma_memory_address_config(DMA0,DMA_CH5,(uint32_t)USART1_RX_BUF);
		dma_transfer_number_config(DMA0,DMA_CH5,sizeof(USART1_RX_BUF));
		dma_channel_enable(DMA0, DMA_CH5); // 開啟DMA傳輸
    }
}

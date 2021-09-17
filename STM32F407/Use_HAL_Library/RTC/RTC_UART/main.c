# include "stm32f4xx_hal.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void SystemClock_Config(void);
void Error_Handler(void);
void LED_Config(void);
void RTC_Config(void);
void RTC_Alarm_IRQHandler(void);
void SysTick_Handler(void);
void UART_Config(void);
void DMA_Config(void);
void DMA1_Stream5_IRQHandler(void);
uint8_t year_thousands_digit(int);
uint8_t year_tens_digit(int);
char *strsep(char **stringp, const char *delim);
void set_date(RTC_DateTypeDef*, int, uint8_t,uint8_t);
void set_time(RTC_TimeTypeDef*, uint8_t,uint8_t, uint8_t);

static UART_HandleTypeDef myUARThandle;
static DMA_HandleTypeDef myDMA_Uart2Handle;
static RTC_HandleTypeDef myRtcHandle;
static RTC_AlarmTypeDef myAlarm;
static int year;
static RTC_DateTypeDef sDate;
static RTC_TimeTypeDef sTime;

static char txData[21];
static char rxData[18];

void setDateTimeByString(char dateAndtimeString[]);

int main(void)
{
	// HAL_Initialise
	HAL_Init();
	SystemClock_Config();
	LED_Config();
	RTC_Config();
	// UART_Initialise
	UART_Config();
	// DMA_Initialise
	DMA_Config();
	
	HAL_UART_Receive_DMA(&myUARThandle, (uint8_t *)rxData, 18);
	
	//Set date And Time 
	setDateTimeByString("0/0/0_0:0:0");
	//OR..
	
	//1) Set date
	//set_date(&sDate,year,7,21);
	//2) Set time 
	//set_time(&sTime,14,37,45);
	

	while (1)
  {
		HAL_RTC_GetTime(&myRtcHandle, &sTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&myRtcHandle, &sDate, RTC_FORMAT_BIN);
		HAL_Delay(400);
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
		
		sprintf(txData, "\r%02d%02d/%02d/%02d_%02d:%02d:%02d",year_thousands_digit(year), sDate.Year, sDate.Month, sDate.Date, sTime.Hours, sTime.Minutes, sTime.Seconds);
		HAL_UART_Transmit(&myUARThandle, (uint8_t *)txData, (unsigned short)strlen(txData),10);
		HAL_Delay(1000);
	}
}

char *strsep(char **stringp, const char *delim) {
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0; }
    return rv;
}

void setDateTimeByString(char dateAndTimeString[])
{
	char *s = dateAndTimeString,*token;
  char delim[] = "/_: ";

  int temp[6], i=0;
  for(token = strsep(&s, delim); token != NULL; token = strsep(&s, delim), i++) {
        temp[i] = atoi(token);
    }
    year = temp[0];
		set_date(&sDate,year,(uint8_t)temp[1],(uint8_t)temp[2]);
		set_time(&sTime,(uint8_t)temp[3],(uint8_t)temp[4],(uint8_t)temp[5]);
}

void set_date(RTC_DateTypeDef *rtc_date ,int perpetual_year, uint8_t month, uint8_t date)
{
	rtc_date->Year = year_tens_digit(perpetual_year);
	rtc_date->Month = month; //RTC_MONTH_DECEMBER
	rtc_date->Date = date;
	//rtc_date->WeekDay = RTC_WEEKDAY_SUNDAY;
	HAL_RTC_SetDate(&myRtcHandle, &sDate, RTC_FORMAT_BIN);
}

void set_time(RTC_TimeTypeDef *rtc_time ,uint8_t hours,uint8_t minutes, uint8_t seconds)
{
	rtc_time->Hours = hours;
	rtc_time->Minutes = minutes;
	rtc_time->Seconds = seconds;
	HAL_RTC_SetTime(&myRtcHandle, &sTime, RTC_FORMAT_BIN);
}

uint8_t year_thousands_digit(int perpetual_year)
{
    int thousand = perpetual_year / 1000;
    int hundred = (perpetual_year - thousand * 1000) / 100;
    return (uint8_t)(thousand * 10 + hundred);
}
uint8_t year_tens_digit(int perpetual_year)
{
    return (uint8_t)(perpetual_year - year_thousands_digit(perpetual_year) * 100);
}


void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hrtc);
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_RTC_AlarmAEventCallback could be implemented in the user file
   */
	
	HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
}

/** @brief System Clock Configuration */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

void LED_Config(void)
{
	//Enable Port D clock
	__HAL_RCC_GPIOF_CLK_ENABLE();
	//GPIO OUTPUT init
	GPIO_InitTypeDef ledInit;
	ledInit.Pin = GPIO_PIN_9|GPIO_PIN_10;
	ledInit.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOF,&ledInit);
}

void RTC_Config(void)
{
	//Enable RTC clock
	__HAL_RCC_RTC_ENABLE();
	//RTC Configurations
	myRtcHandle.Instance = RTC;
	myRtcHandle.Init.AsynchPrediv = 127;
	myRtcHandle.Init.SynchPrediv = 255;
	myRtcHandle.Init.OutPut = RTC_OUTPUT_DISABLE;
	HAL_RTC_Init(&myRtcHandle);
	//Alarm Configurations
	myAlarm.Alarm = RTC_ALARM_A;
	myAlarm.AlarmTime.Hours = 0;
	myAlarm.AlarmTime.Minutes = 0;
	myAlarm.AlarmTime.Seconds = 10;
	myAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	myAlarm.AlarmDateWeekDay = 1;
	HAL_RTC_SetAlarm_IT(&myRtcHandle, &myAlarm, RTC_FORMAT_BIN);
	
	HAL_NVIC_SetPriority(RTC_Alarm_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(RTC_Alarm_IRQn);
}

void RTC_Alarm_IRQHandler(void)
{
	HAL_RTC_AlarmIRQHandler(&myRtcHandle);
}

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void UART_Config(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART2_CLK_ENABLE();
	
	GPIO_InitTypeDef myUartDef;
	myUartDef.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	myUartDef.Mode = GPIO_MODE_AF_PP;
	myUartDef.Pull = GPIO_PULLUP;
	myUartDef.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	myUartDef.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOA, &myUartDef);
	//UART Configuration
	myUARThandle.Instance = USART2;
	myUARThandle.Init.BaudRate = 115200;
	myUARThandle.Init.Mode = UART_MODE_TX_RX;
	myUARThandle.Init.WordLength = UART_WORDLENGTH_8B;
	myUARThandle.Init.StopBits = UART_STOPBITS_1;
	myUARThandle.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&myUARThandle);
	
	//Systick interrupt enable
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void DMA_Config(void)
{
	__HAL_RCC_DMA1_CLK_ENABLE();
	myDMA_Uart2Handle.Instance = DMA1_Stream5;
	myDMA_Uart2Handle.Init.Channel = DMA_CHANNEL_4;
	myDMA_Uart2Handle.Init.Direction = DMA_PERIPH_TO_MEMORY;
	myDMA_Uart2Handle.Init.PeriphInc = DMA_PINC_DISABLE; 
	myDMA_Uart2Handle.Init.MemInc = DMA_MINC_ENABLE;
	myDMA_Uart2Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	myDMA_Uart2Handle.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	myDMA_Uart2Handle.Init.Mode = DMA_CIRCULAR;
	myDMA_Uart2Handle.Init.Priority = DMA_PRIORITY_LOW;
	myDMA_Uart2Handle.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	HAL_DMA_Init(&myDMA_Uart2Handle);
	
	__HAL_LINKDMA(&myUARThandle, hdmarx, myDMA_Uart2Handle);
	
	//Enable DMA1 Stream 5 interrupt
	HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
}

void DMA1_Stream5_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&myDMA_Uart2Handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	/* Prevent unused argument(s) compilation warning*/
	UNUSED(huart);
	/* NOTE: This function Should not be modified, when the callback is needed,
	the HAL_UART_TxCpltCallback could be implemented in the user file*/
	setDateTimeByString(rxData);
}

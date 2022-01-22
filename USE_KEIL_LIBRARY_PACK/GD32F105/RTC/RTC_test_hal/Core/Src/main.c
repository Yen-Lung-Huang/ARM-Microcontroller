#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

RTC_HandleTypeDef hrtc;

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_RTC_Init(void);
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

void setDateTimeByString(char dateAndtimeString[]);

static UART_HandleTypeDef myUARThandle;
static DMA_HandleTypeDef myDMA_Uart2Handle;
static RTC_HandleTypeDef myRtcHandle;
static RTC_AlarmTypeDef myAlarm;
static int year;
static RTC_DateTypeDef sDate;
static RTC_TimeTypeDef sTime;

char rxData[19];
char txData[20];

int main(void)
{
  HAL_Init(); /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  SystemClock_Config(); /* Configure the system clock */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
	
  MX_RTC_Init();
  
	strcpy(txData,"RTC_test\r\n");
	HAL_UART_Transmit(&huart2,(uint8_t*)txData, strlen(txData),10);
	
	//Set date And Time 
	setDateTimeByString("0/0/0_0:0:0");
	
	/* Infinite loop */
  while (1)
  {
    HAL_UART_Receive_DMA(&huart2, (uint8_t*)rxData, 18);
		HAL_RTC_GetTime(&myRtcHandle, &sTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&myRtcHandle, &sDate, RTC_FORMAT_BIN);
		HAL_Delay(400);
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

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  RCC_OscInitStruct.PLL2.PLL2State = RCC_PLL_NONE;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the Systick interrupt time
  */
  __HAL_RCC_PLLI2S_ENABLE();
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef DateToUpdate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
  hrtc.Init.OutPut = RTC_OUTPUTSOURCE_ALARM;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0;
  sTime.Minutes = 0;
  sTime.Seconds = 0;

  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  DateToUpdate.WeekDay = RTC_WEEKDAY_THURSDAY;
  DateToUpdate.Month = RTC_MONTH_AUGUST;
  DateToUpdate.Date = 26;
  DateToUpdate.Year = 21;

  if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel6_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel6_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxCpltCallback could be implemented in the user file
   */
	//HAL_UART_Transmit(huart,(uint8_t*)"RxCpltCallback", strlen("RxCpltCallback"),10);
	//sprintf(rxData,"%s\n",rxData);

	setDateTimeByString(rxData);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
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

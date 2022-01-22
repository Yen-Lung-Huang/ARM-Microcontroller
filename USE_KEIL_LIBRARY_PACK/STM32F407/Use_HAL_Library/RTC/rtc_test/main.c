# include "stm32f4xx_hal.h"

void SystemClock_Config(void);
void Error_Handler(void);
void LED_Config(void);
void RTC_Config(void);
void RTC_Alarm_IRQHandler(void);
void SysTick_Handler(void);

static RTC_HandleTypeDef myRtcHandle;
static RTC_AlarmTypeDef myAlarm;
static RTC_TimeTypeDef sTime;
static RTC_DateTypeDef sDate;

int main(void)
{
	// HAL_Initialise
	HAL_Init();
	SystemClock_Config();
	LED_Config();
	RTC_Config();
	
	//1) Set time 
	sTime.Hours = 23;
	sTime.Minutes = 59;
	sTime.Seconds = 45;
	HAL_RTC_SetTime(&myRtcHandle, &sTime, RTC_FORMAT_BIN);
	//2) Set date 
	sDate.Date = 31;
	sDate.Month = RTC_MONTH_DECEMBER;
	sDate.WeekDay = RTC_WEEKDAY_SUNDAY;
	sDate.Year = 20;
	HAL_RTC_SetDate(&myRtcHandle, &sDate, RTC_FORMAT_BIN);

while (1)
  {
		HAL_RTC_GetTime(&myRtcHandle, &sTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&myRtcHandle, &sDate, RTC_FORMAT_BIN);
		HAL_Delay(400);
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	}
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

#include <main.h>
#include <stdio.h>
#include <string.h>
#include "MPU6050.h"

#define PI 3.14159265358979323846

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
UART_HandleTypeDef huart2;
static DMA_HandleTypeDef myDMA_Uart2Handle;
const float RAD_TO_DEG = (180.0 / PI);
static char txData[100];

int minVal=265;
int maxVal=402;
float degree_x;
float degree_y;
float degree_z;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);

long map(long, long, long, long, long);

static void UART_Config(void);
static void DMA_Config(void);
static void SysTick_Handler(void);
void DMA1_Stream5_IRQHandler(void);

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
RawData_Def myAccelRaw, myGyroRaw;
ScaledData_Def myAccelScaled, myGyroScaled;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	MPU_ConfigTypeDef myMpuConfig;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

	// HAL_Initialise
	HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
	UART_Config(); // UART_Initialise
	DMA_Config(); // DMA_Initialise
  /* USER CODE BEGIN 2 */
	//1. Initialise the MPU6050 module and I2C
	MPU6050_Init(&hi2c1);
	//2. Configure Accel and Gyro parameters
	myMpuConfig.Accel_Full_Scale = AFS_SEL_4g;
	myMpuConfig.ClockSource = Internal_8MHz;
	myMpuConfig.CONFIG_DLPF = DLPF_184A_188G_Hz;
	myMpuConfig.Gyro_Full_Scale = FS_SEL_500;
	myMpuConfig.Sleep_Mode_Bit = 0;  //1: sleep mode, 0: normal mode
	MPU6050_Config(&myMpuConfig);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		//Raw data
		MPU6050_Get_Accel_RawData(&myAccelRaw);
		MPU6050_Get_Gyro_RawData(&myGyroRaw);
		
		//Scaled data
		MPU6050_Get_Accel_Scale(&myAccelScaled);
		MPU6050_Get_Gyro_Scale(&myGyroScaled);
		
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		
		//int xAng = map(myAccelScaled.x,minVal,maxVal,-90,90);
		//int yAng = map(myAccelScaled.y,minVal,maxVal,-90,90);
		//int zAng = map(myAccelScaled.z,minVal,maxVal,-90,90);
		int xAng = map(myAccelRaw.x,minVal,maxVal,-90,90);
		int yAng = map(myAccelRaw.y,minVal,maxVal,-90,90);
		int zAng = map(myAccelRaw.z,minVal,maxVal,-90,90);
		degree_x = RAD_TO_DEG* (atan2(-yAng, -zAng)+PI);
		degree_y = RAD_TO_DEG* (atan2(-xAng, -zAng)+PI);
		degree_z = RAD_TO_DEG* (atan2(-yAng, -xAng)+PI);
		if(degree_x >180){degree_x-=360;}
		if(degree_y >180){degree_y-=360;}
		if(degree_z >180){degree_z-=360;}
		
		sprintf(txData, "\rAngle: x= %+011f, y= %+011f, z= %+011f", degree_x, degree_y, degree_z);
		//sprintf(txData, "\rG-Sensor: x= %+011f, y= %+011f, z= %+011f", (float)myGyroScaled.x, (float)myGyroScaled.y, (float)myGyroScaled.z);
		
		HAL_UART_Transmit(&huart2, (uint8_t *)txData, strlen(txData),10);
		//HAL_Delay(10);
		HAL_Delay(450);
  }
  /* USER CODE END 3 */
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/** @brief System Clock Configuration */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/** @brief I2C1 Initialization Function */
static void MX_I2C1_Init(void)
{
  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
}

/** @brief USART2 Initialization Function */
static void UART_Config(void)
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
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&huart2);
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
	//Systick interrupt enable
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
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
	
	__HAL_LINKDMA(&huart2, hdmarx, myDMA_Uart2Handle);
	
	//Enable DMA1 Stream 5 interrupt
	HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
}

void DMA1_Stream5_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&myDMA_Uart2Handle);
}

/**@brief GPIO Initialization Function */
 static void MX_GPIO_Init(void)
{
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
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

#ifdef  USE_FULL_ASSERT
#endif /* USE_FULL_ASSERT */
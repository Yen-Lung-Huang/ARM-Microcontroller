/**
  ******************************************************************************
  * @brief   The SysTick configuration file.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "gd32f10x.h"
#include "systick.h"



/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;
__IO uint32_t MsCnt=0;
static __IO uint32_t Time1SCnt =0;
static __IO uint32_t  IWDGCounter =0;
extern uint32_t u32delayno;



/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Configure SysTick.
  * @param  None
  * @retval None
  */
void SysTick_Configuration(void)
{    
    /* Setup SysTick Timer for 1000Hz interrupts */
    if (SysTick_Config(SystemCoreClock / 1000))
    {
        /* Capture error */
        while (1);
    }
    /* Configure the SysTick handler priority */
    NVIC_SetPriority(SysTick_IRQn, 0x00);
}

/**
* @brief  Insert a delay time.
* @param  nTime: specifie the delay time length, in milliseconds.
* @retval None
*/
void Delay_1ms(uint32_t nTime)
{  
    TimingDelay = nTime;
    while(TimingDelay != 0);
	
}

/**
* @brief  Decrement the TimingDelay variable.
* @param  None.
* @retval None
*/
void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00)
    { 
        TimingDelay--;
    }
		IWDGCounter ++;
		//100MS喂狗
		if(IWDGCounter>100) 
		{
			IWDGCounter = 0;
			
		}
		//开启软件定时
//		u32delayno ++;
		Time1SCnt++;
		if(Time1SCnt>30000)
		{
			MsCnt = 1;
			Time1SCnt = 0;
		}
		//1s定时
//		if(Time1SCnt>1000)
//		{
//			Time1SCnt =0;
//						TimeStartCnt++;
//		  if(TestTimeStartCnt<10)
//			{
//				TestTimeStartCnt++;
//			}
//		}
}
   

/*******************************************************************************
* File Name          : usrtimer.c
* Author             : xuaige
* Description        : This file provides all the usrtimer functions.

* History:
* 2018/12/29 : version V1.00
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "usrtimer.h"
#include "control.h"
#include "Adc_Function.h"
#include "uart_driver.h"
#include "flow.h"
#include "display.h"
#include "buzzer.h"
#include "fliter.h"
#include "tds.h"
#include "modem.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
TIMER AdcCheckStatusTimer;
TIMER NoTouchKeyTimer;
TIMER CheckSysStatusTimer;
TIMER CheckFunStatusTimer;
TIMER ModemATInitTimer;
TIMER USART1ReceiveTimeoutTimer;
TIMER USART2ReceiveTimeoutTimer;
TIMER USART3ReceiveTimeoutTimer;
TIMER LEDShowBattLevelTimer;
TIMER SysEvtRptSendingTimer;
TIMER FliterWarmingTimeTimer;
TIMER WashTimeTimer;
TIMER UvLedTimeTimer;
TIMER TapLedTimeTimer;
TIMER TocCheckTimer;
TIMER FlowCheckTimer;
TIMER TdsOriginalCheckTimer;
TIMER TdsCleanCheckTimer;
TIMER ConnectInternetTimer;
TIMER PeriodReportDisplayTimer;
TIMER WaitModemStatusTimer;
TIMER ReportDeviceParameterTimer;
TIMER GetModemInformationTimer;
TIMER CheckSystemTimeTimer;
TIMER ConnectInternetLedTimer;	
TIMER MateritalLedTimer;
TIMER SwitchCheckTimer;
TIMER ResetKeyTimeOutTimer;
TIMER DisplayTimer;
TIMER TxAckTimeOutTimer;
TIMER BuzzerTimer;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

// Init All Software Timer
void InitSoftwareTimers(void)
{
	// Adc Check Status
	SoftwareTimerCreate(&AdcCheckStatusTimer,1,AdcCheckStatusTimerCallback,ADC_CHECK_STAT_TIMEOUT);
	SoftwareTimerStart(&AdcCheckStatusTimer);

	// Touch Key Check Status
	SoftwareTimerCreate(&NoTouchKeyTimer,1,NoTouchKeyTimerCallback,NO_TOUCH_KEY_TIME);
//	SoftwareTimerStart(&NoTouchKeyTimer);

//	// Check Sys Status
//	SoftwareTimerCreate(&CheckSysStatusTimer,1,CheckSysStatusTimerCallback,CHECK_SYS_STAT_TIMEOUT);
//	SoftwareTimerStart(&CheckSysStatusTimer);

//	// Check Function Status
//	SoftwareTimerCreate(&CheckFunStatusTimer,1,CheckFunStatusTimerCallback,CHECK_FUN_STAT_TIMEOUT);
//	SoftwareTimerStart(&CheckFunStatusTimer);

//	//	// Modem AT Init Status
//	//	SoftwareTimerCreate(&ModemATInitTimer,1,ModemATInitTimerCallback,MODEM_AT_INIT_LOOP_TIMEOUT);
//	//	//SoftwareTimerStart(&ModemATInitTimer);
//	//	
//	UART1 Receive timer
	SoftwareTimerCreate(&USART1ReceiveTimeoutTimer,1,USART1ReceiveTimeoutTimerCallback,USART1_DATA_RECEIVE_TIMEOUT);
//	SoftwareTimerStart(&UART1ReceiveTimeoutTimer);

//	UART2 Receive timer
	SoftwareTimerCreate(&USART2ReceiveTimeoutTimer,1,USART2ReceiveTimeoutTimerCallback,USART2_DATA_RECEIVE_TIMEOUT);
//	//SoftwareTimerStart(&UART2ReceiveTimeoutTimer);

//	UART3 Receive timer
	SoftwareTimerCreate(&USART3ReceiveTimeoutTimer,1,USART3ReceiveTimeoutTimerCallback,USART3_DATA_RECEIVE_TIMEOUT);
//	//	SoftwareTimerStart(&UART0ReceiveTimeoutTimer);

//	Sys Event eport sending Process
//	SoftwareTimerCreate(&SysEvtRptSendingTimer,1,SysEvtRptSendingCallback,SYS_EVT_RPT_SENDING_TIMEOUT);
//	SoftwareTimerStart(&SysEvtRptSendingTimer);

//	//Fliter warm timer
	SoftwareTimerCreate(&FliterWarmingTimeTimer,1,FliterWarmingTimeCallback,FLITER_WARMING_3_TIME_TIMEOUT);
//	SoftwareTimerStart(&FliterWarmingTimeTimer);

//	//Wash Timer
	SoftwareTimerCreate(&WashTimeTimer,1,WashTimeCallback,WASH_TIME);
	//SoftwareTimerStart(&WashTimeTimer);

//	//Uv Led Timer
//	SoftwareTimerCreate(&UvLedTimeTimer,1,UvLedTimeCallback,UV_LED_TIME_TIMEOUT);
//	//SoftwareTimerStart(&UvLedTimeTimer);

	//Tap Led Timer
	SoftwareTimerCreate(&TapLedTimeTimer,1,TapLedTimeCallback,TAP_LED_FAST_TIME_TIMEOUT);
//	//SoftwareTimerStart(&UvLedTimeTimer);

//	//TOC Check Timer
//	SoftwareTimerCreate(&TocCheckTimer,1,TocCheckCallback,TOC_CHECK_3S);
////	SoftwareTimerStart(&TocCheckTimer);

//	//Flow Check Timer
	SoftwareTimerCreate(&FlowCheckTimer,1,FlowCheckCallback,FLOW_CHECK_TIMEOUT);
	SoftwareTimerStart(&FlowCheckTimer);

	//TDS Check Timer
  	SoftwareTimerCreate(&TdsOriginalCheckTimer,1,TdsOriginalCheckCallback,TDS_ORIGINAL_CHECK_TIMEOUT);
	 SoftwareTimerStart(&TdsOriginalCheckTimer);

	//TDS Check Timer
   	SoftwareTimerCreate(&TdsCleanCheckTimer,1,TdsCleanCheckCallback,TDS_CLEAN_CHECK_TIMEOUT);
	 SoftwareTimerStart(&TdsCleanCheckTimer);

	//Connect Internet Timer
	SoftwareTimerCreate(&ConnectInternetTimer,1,ConnectInternetCallback,CONNECT_INTERNET_TIMEOUT);  

	//Period Report Display Timer
	SoftwareTimerCreate(&PeriodReportDisplayTimer,1,PeriodReportDisplayCallback,PERIOD_REPORT_DISPLAY_TIMEOUT);
	SoftwareTimerStart(&PeriodReportDisplayTimer);	 

	//Wait Modem Status Timer
	SoftwareTimerCreate(&WaitModemStatusTimer,1,WaitModemStatusCallback,WAIT_MODEM_STATUS_TIMEOUT);
	SoftwareTimerStart(&WaitModemStatusTimer);	  

	//Period Report Device Parameter Timer
	SoftwareTimerCreate(&ReportDeviceParameterTimer,1,ReportDeviceParameterCallback,REPORT_DEVICE_PARAMETER_TIMEOUT);
	//	SoftwareTimerStart(&ReportDeviceParameterTimer);	 

	//Period Report Device Parameter Timer
	SoftwareTimerCreate(&GetModemInformationTimer,1,GetModemInformationCallback,PERIOD_GET_MODEM_INFORMATION_TIMEOUT);
	SoftwareTimerStart(&GetModemInformationTimer);	 

	//Check System Time Timer
	SoftwareTimerCreate(&CheckSystemTimeTimer,1,CheckSystemTimeCallback,CHECK_SYSTEM_TIME_TIMEOUT);
	SoftwareTimerStart(&CheckSystemTimeTimer);	 

	//Connect Internet LED Time Timer
//	SoftwareTimerCreate(&ConnectInternetLedTimer,1,ConnectInternetLedCallback,CONNECT_INTERNET_LED_TIMEOUT);
//	SoftwareTimerStart(&ConnectInternetLedTimer);	

	//Materital LED Time Timer
	//SoftwareTimerCreate(&MateritalLedTimer,1,MateritalLedCallback,1000);
	//SoftwareTimerStart(&MateritalLedTimer);

	//SwitchCheck Time Timer
	SoftwareTimerCreate(&SwitchCheckTimer,1,SwitchCheckCallback,SWITCH_CHECK_TIME_TIMEOUT);
	SoftwareTimerStart(&SwitchCheckTimer);
//	
	//Reset Key Time Out Timer
//	SoftwareTimerCreate(&ResetKeyTimeOutTimer,1,ResetKeyTimeOutCallback,RESET_KEY_TIMEOUT);
//	SoftwareTimerStart(&ResetKeyTimeOutTimer);

	//Display Time Timer
	SoftwareTimerCreate(&DisplayTimer,1,DisplayTimerCallback,DISPLAY_500MS_TIMEOUT);
	//SoftwareTimerStart(&DisplayTimer);
	
	//Tx Ack TimeOut Timer
	SoftwareTimerCreate(&TxAckTimeOutTimer,1,TxAckTimeOutTimerCallback,TXACK_TIME_TIMEOUT);
	SoftwareTimerStart(&TxAckTimeOutTimer);
	
	SoftwareTimerCreate(&BuzzerTimer,1,BuzzerTimerCallback,BUZZER_30MS_TIMEOUT);
	SoftwareTimerStart(&BuzzerTimer);
}

// Software Timer Counter
void SoftwareTimerCounter(void)
{
	// Batt Check Status
	if(AdcCheckStatusTimer.TimerStartCounter == TRUE)
	{
		AdcCheckStatusTimer.TimeOutVal++;
	}

	// touch key Check Status
	if(NoTouchKeyTimer.TimerStartCounter == TRUE)
	{
		NoTouchKeyTimer.TimeOutVal++;
	}

	// Check Sys Status
	if(CheckSysStatusTimer.TimerStartCounter == TRUE)
	{
		CheckSysStatusTimer.TimeOutVal++;
	}

	// Check Function Status
	if(CheckFunStatusTimer.TimerStartCounter == TRUE)
	{
		CheckFunStatusTimer.TimeOutVal++;
	}

	// Modem AT Init Status
	if(ModemATInitTimer.TimerStartCounter == TRUE)
	{
		ModemATInitTimer.TimeOutVal++;
	}

	// UART1 Receive timer
	if(USART1ReceiveTimeoutTimer.TimerStartCounter == TRUE)
	{
		USART1ReceiveTimeoutTimer.TimeOutVal++;
	}

	// UART2 Receive timer
	if(USART2ReceiveTimeoutTimer.TimerStartCounter == TRUE)
	{
		USART2ReceiveTimeoutTimer.TimeOutVal++;
	}

	// UART3 Receive timer
	if(USART3ReceiveTimeoutTimer.TimerStartCounter == TRUE)
	{
		USART3ReceiveTimeoutTimer.TimeOutVal++;
	}

	//LEDShowBattLevel Process
	if(LEDShowBattLevelTimer.TimerStartCounter == TRUE)
	{
		LEDShowBattLevelTimer.TimeOutVal++;
	}

	//Sys Event eport sending Process
	if(SysEvtRptSendingTimer.TimerStartCounter == TRUE)
	{
		SysEvtRptSendingTimer.TimeOutVal++;
	}

	//Periodic sync timer
	if(FliterWarmingTimeTimer.TimerStartCounter == TRUE)
	{
		FliterWarmingTimeTimer.TimeOutVal++;
	}

	//Wash timer
	if(WashTimeTimer.TimerStartCounter == TRUE)
	{
		WashTimeTimer.TimeOutVal++;
	}

	//DisplayLed timer
	if(UvLedTimeTimer.TimerStartCounter == TRUE)
	{
		UvLedTimeTimer.TimeOutVal++;
	}

	//DisplayLed timer
	if(TapLedTimeTimer.TimerStartCounter == TRUE)
	{
		TapLedTimeTimer.TimeOutVal++;
	}

	//Toc Check timer
	if(TocCheckTimer.TimerStartCounter == TRUE)
	{
		TocCheckTimer.TimeOutVal++;
	}

	//Flow Check timer
	if(FlowCheckTimer.TimerStartCounter == TRUE)
	{
		FlowCheckTimer.TimeOutVal++;
	}

	//TDS Check timer
	if(TdsOriginalCheckTimer.TimerStartCounter == TRUE)
	{
		TdsOriginalCheckTimer.TimeOutVal++;
	}

	//TDS Check timer
	if(TdsCleanCheckTimer.TimerStartCounter == TRUE)
	{
		TdsCleanCheckTimer.TimeOutVal++;
	}

	if(ConnectInternetTimer.TimerStartCounter == TRUE)
	{
		ConnectInternetTimer.TimeOutVal++;
	}	  

	if(PeriodReportDisplayTimer.TimerStartCounter == TRUE)
	{
		PeriodReportDisplayTimer.TimeOutVal++;
	}  

	if(WaitModemStatusTimer.TimerStartCounter == TRUE)
	{
		WaitModemStatusTimer.TimeOutVal++;
	} 

	if(ReportDeviceParameterTimer.TimerStartCounter == TRUE)
	{
		ReportDeviceParameterTimer.TimeOutVal++;
	} 

	if(GetModemInformationTimer.TimerStartCounter == TRUE)
	{
		GetModemInformationTimer.TimeOutVal++;
	} 

	if(CheckSystemTimeTimer.TimerStartCounter == TRUE)
	{
		CheckSystemTimeTimer.TimeOutVal++;
	} 

	if(ConnectInternetLedTimer.TimerStartCounter == TRUE)
	{
		ConnectInternetLedTimer.TimeOutVal++;
	} 

	if(MateritalLedTimer.TimerStartCounter == TRUE)
	{
		MateritalLedTimer.TimeOutVal++;
	} 
	
	if(SwitchCheckTimer.TimerStartCounter == TRUE)
	{
		SwitchCheckTimer.TimeOutVal++;
	} 
	
	if(ResetKeyTimeOutTimer.TimerStartCounter == TRUE)
	{
		ResetKeyTimeOutTimer.TimeOutVal++;
	}
	
	if(DisplayTimer.TimerStartCounter == TRUE)
	{
		DisplayTimer.TimeOutVal++;
	}
	
	if(TxAckTimeOutTimer.TimerStartCounter == TRUE)
	{
		TxAckTimeOutTimer.TimeOutVal++;
	}
	
	if(BuzzerTimer.TimerStartCounter == TRUE)
	{
		BuzzerTimer.TimeOutVal++;
	}
	
}

// Software Check Timer Status
void SoftwareCheckTimerStatus(void)
{
	// Batt Check Status
	if (IsSoftwareTimeOut(&AdcCheckStatusTimer) == TRUE)
	{

	}

	// Batt Check Status
	if (IsSoftwareTimeOut(&NoTouchKeyTimer) == TRUE)
	{

	}

	// Check Sys Status
	if (IsSoftwareTimeOut(&CheckSysStatusTimer) == TRUE)
	{

	}

	// Check Function Status
	if (IsSoftwareTimeOut(&CheckFunStatusTimer) == TRUE)
	{

	}

	// Modem AT Init Status
	if (IsSoftwareTimeOut(&ModemATInitTimer) == TRUE)
	{

	}

	// UART1 Receive timer
	if (IsSoftwareTimeOut(&USART1ReceiveTimeoutTimer) == TRUE)
	{

	}

	// UART2 Receive timer
	if (IsSoftwareTimeOut(&USART2ReceiveTimeoutTimer) == TRUE)
	{

	}

	// UART3 Receive timer
	if (IsSoftwareTimeOut(&USART3ReceiveTimeoutTimer) == TRUE)
	{

	}

	//LEDShowBattLevel Process
	if(IsSoftwareTimeOut(&LEDShowBattLevelTimer) == TRUE)
	{

	}

	//Sys Event eport sending Process
	if(IsSoftwareTimeOut(&SysEvtRptSendingTimer) == TRUE)
	{

	}

	//Periodic sync timer
	if(IsSoftwareTimeOut(&FliterWarmingTimeTimer) == TRUE)
	{

	}

	//Wash timer
	if(IsSoftwareTimeOut(&WashTimeTimer) == TRUE)
	{

	}

	//DisplayLed timer
	if(IsSoftwareTimeOut(&UvLedTimeTimer) == TRUE)
	{

	}  

	//DisplayLed timer
	if(IsSoftwareTimeOut(&TapLedTimeTimer) == TRUE)
	{

	}  

	//Toc Check timer
	if(IsSoftwareTimeOut(&TocCheckTimer) == TRUE)
	{

	}  

	//Flow Check timer
	if(IsSoftwareTimeOut(&FlowCheckTimer) == TRUE)
	{

	}  

	//TDS Check timer
	if(IsSoftwareTimeOut(&TdsOriginalCheckTimer) == TRUE)
	{

	} 

	//TDS Check timer
	if(IsSoftwareTimeOut(&TdsCleanCheckTimer) == TRUE)
	{

	} 

	if(IsSoftwareTimeOut(&ConnectInternetTimer) == TRUE)
	{

	}	 

	if(IsSoftwareTimeOut(&PeriodReportDisplayTimer) == TRUE)
	{

	} 

	if(IsSoftwareTimeOut(&WaitModemStatusTimer) == TRUE)
	{

	} 

	if(IsSoftwareTimeOut(&ReportDeviceParameterTimer) == TRUE)
	{

	} 		

	if(IsSoftwareTimeOut(&GetModemInformationTimer) == TRUE)
	{

	} 

	if(IsSoftwareTimeOut(&CheckSystemTimeTimer) == TRUE)
	{

	}

	if(IsSoftwareTimeOut(&ConnectInternetLedTimer) == TRUE)   
	{

	}

	if(IsSoftwareTimeOut(&MateritalLedTimer) == TRUE)   
	{

	}
	
	if(IsSoftwareTimeOut(&SwitchCheckTimer) == TRUE)   
	{

	}
	
	if(IsSoftwareTimeOut(&ResetKeyTimeOutTimer) == TRUE)   
	{

	}
	
	if(IsSoftwareTimeOut(&DisplayTimer) == TRUE)   
	{

	}
	
	if(IsSoftwareTimeOut(&TxAckTimeOutTimer) == TRUE)   
	{

	}
	if(IsSoftwareTimeOut(&BuzzerTimer) == TRUE)   
	{

	}
}

// Software Timer Start
void SoftwareTimerStart(TIMER *timer)
{		
	timer->TimerStartCounter  = TRUE;
}

// Software Timer Stop
void SoftwareTimerStop(TIMER *timer)
{		
	timer->TimerStartCounter  = FALSE;
	timer->TimeOutVal = 0;				      //time out value
}

// Software Timer Reset
void SoftwareTimerReset(TIMER *timer,void (*Routine)(u8),u32 timeout)
{
	timer->TimerStartCounter  = FALSE;	//timer stop
	timer->RecTickVal = timeout;			  //softtimer setting value
	timer->TimeOutVal = 0;				      //time out value
	timer->IsTimeOverflow  = FALSE;	 	  //time out flag
	timer->Routine = Routine;
}

// Software Timer Create
void SoftwareTimerCreate(TIMER *timer,u8 TimeId,void (*Routine)(u8),u32 timeout)
{
	timer->TimeId = TimeId;
	timer->RecTickVal = timeout;			  //softtimer setting value
	timer->TimeOutVal = 0;				      //time out value
	timer->IsTimeOverflow  = FALSE;		  //time out flag
	timer->TimerStartCounter  = FALSE;	//timer stop
	timer->Routine  = Routine;
}

// Check whether time out.
u8 IsSoftwareTimeOut(TIMER *timer)
{		
	//ET0 = 0;
	if(!timer->IsTimeOverflow)
	{
		//After gSysTick and timer->TimeOutVal overflow, 
		//the software timer function can still work well
		//the next statement is equivalent to:
		//(gSysTick - timer->TimeOutVal) < 0x80000000 
		if(timer->TimeOutVal > timer->RecTickVal)
		{
			timer->IsTimeOverflow = TRUE;
			SoftwareTimerStop(timer);
			timer->Routine(timer->TimeId);
		}
	}	
	//ET0 = 1;

	return timer->IsTimeOverflow;				
}


/*******************************************************************************
End Of The File
*******************************************************************************/


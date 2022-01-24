/*******************************************************************************
* File Name          : rtcclock.c
* Author             : lizhifei
* Description        : This file provides all the rtcclock functions.

* History:
* 2020/03/19 : version V1.00
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "rtcclock.h"
#include "uart_driver.h"
//#include "atcmd.h"
#include "main.h"
#include "gd32f10x.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
const char *weekstring[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
static const int8 norm_month_table[] = {31,28,31,30,31,30,31,31,30,31,30,31};
static char SysDate[25] = {'\0'};
static u8 RTCAlarmHappenFlag = FALSE;
/* Public variables ---------------------------------------------------------*/
#ifdef MONITOR_SYS_RUNNING_TIME
u8 SystemStartupRecordTimFlag = FALSE;
TimeTableT SysStartTime = RTC_DEFAULT_TIME;
u32 SysRunningTime = 0;
#endif

//static const char *SyncRtcTye[] = {
//	"ATCMD",   
//	"DPSLEEP",   
//	"INITIAL",   
//	"MODEM",   
//	"SETTIM",   
//	"INTHAP",   
//	"PROTO",
//	"UNKNOWN",};


RTCConfigParam gRTCParam = {0};

/* Public function prototypes -----------------------------------------------*/
//extern RTC_HandleTypeDef hrtc;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void SetRTCAlarmStatus(u8 Status)
{
	RTCAlarmHappenFlag = Status;
}

u8 GetRTCAlarmStatus(void)
{
	return RTCAlarmHappenFlag;
}

int datetoweek(int yr, int mn,int day)
{
	int i;
	int days=0;
	int s;
	int week;
	int mont[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	if((0==yr%4 && 0!=yr%100)||0==yr%400)
  {
		mont[2]=29;
  }
	else
  {
		mont[2]=28;
  }
	for (i=0;i<mn;i++)
  {
    days+=mont[i];
  }
	days+=day;
	s=yr-1+(int)((yr-1)/4)-(int)((yr-1)/100)+(int)((yr-1)/400)+days;
	week=s%7;

	return week;
}

u8 bcd2bin(u8 val)
{
	return (val & 0x0f) + (val >> 4) * 10;
}

u8 bin2bcd(u8 val)
{
	return ((val / 10) << 4) + val % 10;
}

void DectoBCD(int Dec, u8 *Bcd, int length)
{
	int i;
	int temp;
	for(i=length-1; i>=0; i--)
	{
		temp = Dec%100;
		Bcd[i] = ((temp/10)<<4) + ((temp%10) & 0x0F);
		Dec /= 100;
	}
}

u32 Divide(u32 Second, u32 value, u32 *returnValue)
{
  *returnValue = Second%value;
  return Second/value;
}

int8 GetMonthFromDays(u32 days,u32 year, u32 *returnDays)
{
   int i =0;
   u32 totalday = 0;
   for(i =0; i < 12 ; i++) 
   {
     if(days < totalday) 
     {
       break;
     }
     
     if(((year&0x3) == 0)&&(i == 1))
     {
       totalday += 29;
     }
     else 
     {
       totalday += norm_month_table[i];
     }
   }
   if(((year&0x3) == 0)&&(i == 2))
   {
      *returnDays = days - totalday + 29 + 1;
   }
   else 
   {
      *returnDays = days - totalday + norm_month_table[i - 1] + 1;
   }
   return i;
}

TimeTableT SecondsToTimeTable(u32 seconds)
{
  TimeTableT timeTable;
  u32 days;
	u32 leap; 
  
  seconds+= BASE_OFFSET;

  //get seconds, minute and hour;
  seconds = Divide(seconds, 60, &timeTable.second);
  seconds = Divide(seconds, 60, &timeTable.minute);
  seconds = Divide(seconds, 24, &timeTable.hour);

  //count how many leap_loop be included;
  leap = Divide(seconds, LEAP_LOOP, &days);
  timeTable.year = BASE_YEAR + 4*leap;

  //get surplus days to determine the appointed year;
  if(days < 366) 
  {
    
  }
  else if(days < (366 + 365)) 
  {
    timeTable.year+=1;
    days -= (366);
  }
  else if(days < (366 + 365*2)) 
  {
    timeTable.year+=2; 
    days -= (366 + 365);
  }
  else if(days < (366 + 365*3)) 
  {
    timeTable.year+=3;
    days -= (366 + 365*2);
  }
  
  timeTable.month = GetMonthFromDays(days,timeTable.year,&timeTable.day);
  return timeTable;
}

u32 TimeTableToSeconds(TimeTableT timeTable)
{
  u32  seconds =0;  
  int32 i;

  //get total days from 1980 not included nowyear
  for(i = BASE_YEAR;i < timeTable.year; i++) 
  {
    //if %4 != 0;
    if((i&0x3)!= 0) 
    {
      seconds += NORM_YEAR;
    }
    else 
    {
      seconds += LEAP_YEAR;
    }
  }
  //get nowyears total days not included this month;
  for(i = 1; i < timeTable.month; i++) 
  {
    //if leap year and 2th month;
    if(((timeTable.year&0x3) == 0)&&(i == 2))
    {
       seconds += 29;
    }
    else 
    {
       seconds += norm_month_table[i - 1];
    }
  }
  //get this month's days;
  seconds += timeTable.day - 1;
  seconds = seconds * 24 + timeTable.hour;
  seconds = seconds * 60 + timeTable.minute;
  seconds = seconds * 60 + timeTable.second;
  
  seconds -= BASE_OFFSET;
  return seconds;   
}

char *FmtTimeShow(void)
{
	//int week = 0;
	char *tstr = SysDate;
	// UTC TIME ADD 8 HOURS
	TimeTableT timeTable;// = SecondsToTimeTable(TimeTableToSeconds(GetRTCDatetime()));
	/* Display time Format : hh:mm:ss */
	//week = datetoweek(timeTable.year, timeTable.month, timeTable.day);
	/* Show Time */
	timeTable=GetRTCDatetime();
	sprintf(tstr,"%04d/%02d/%02d %02d:%02d:%02d", \
    timeTable.year, \
		timeTable.month, \
		timeTable.day, \
		/*week, */\
		timeTable.hour, \
		timeTable.minute, \
		timeTable.second);
	return tstr;
}
//void WriteInternetTime(
//    unsigned char inYear, unsigned char inMonth,  unsigned char inDay, 
//    unsigned char inHour, unsigned char inMinute, unsigned char inSecond
//)
//{
//		TimeStartCnt=inHour*3600+inMinute*60+inSecond;
//}
//TimeTableT GetRTCDatetime(void)
//{
//	TimeTableT timeTable;
//	S_RTC_TIME_DATA_T sCurTime;
	/* Get the current time */
//	RTC_GetDateAndTime(&sCurTime);
//	printf(" Current Time:%d/%02d/%02d %02d:%02d:%02d\n",sCurTime.u32Year,sCurTime.u32Month,sCurTime.u32Day,sCurTime.u32Hour,sCurTime.u32Minute,sCurTime.u32Second);
//	timeTable.year = sCurTime.u32Year;
//	timeTable.month = sCurTime.u32Month;
//	timeTable.day = sCurTime.u32Day;
//	timeTable.hour = sCurTime.u32Hour;
//	timeTable.minute = sCurTime.u32Minute;
//	timeTable.second = sCurTime.u32Second;
//  RTC_DateTypeDef sdatestructureget = {0};
//  RTC_TimeTypeDef stimestructureget = {0};
//  
//  /* Get the RTC current Time */
//  HAL_RTC_GetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
//  /* Get the RTC current Date */
//  HAL_RTC_GetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);
//  /* Display time Format : hh:mm:ss */

//  timeTable.year = sdatestructureget.Year+2000;
//  timeTable.month = sdatestructureget.Month;
//  timeTable.day = sdatestructureget.Date;
//  timeTable.hour = stimestructureget.Hours;
//  timeTable.minute = stimestructureget.Minutes;
//  timeTable.second = stimestructureget.Seconds;
//  
//  return timeTable;
//}

int SetRTCDatetime(TimeTableT *tm, u8 isbcdtype)
{
//  RTC_TimeTypeDef sTime = {0};
//  RTC_DateTypeDef sDate = {0};

//  if(isbcdtype == TRUE)
//  {
//    // Date
//    sDate.Year = tm->year;
//    sDate.Month = tm->month;
//    sDate.Date = tm->day;
//    // Time
//    sTime.Hours = tm->hour;
//    sTime.Minutes = tm->minute;
//    sTime.Seconds = tm->second;
//    // Week
//    sDate.WeekDay = datetoweek(bcd2bin(tm->year) + 2000, bcd2bin(tm->month), bcd2bin(tm->day));
//  }
//  else
//  {
//    // Data
//    if(tm->year < 1900)
//    {
//      DectoBCD(tm->year+2000, &sDate.Year, 1);
//    }
//    else
//    {
//      DectoBCD(tm->year, &sDate.Year, 1);
//    }
//    
//    DectoBCD(tm->month, &sDate.Month, 1);
//    DectoBCD(tm->day, &sDate.Date, 1);
//    // Time
//    DectoBCD(tm->hour, &sTime.Hours, 1);
//    DectoBCD(tm->minute, &sTime.Minutes, 1);
//    DectoBCD(tm->second, &sTime.Seconds, 1);
//    // Week
//    sDate.WeekDay =  datetoweek(tm->year, tm->month, tm->day);
//    if(sDate.WeekDay == 0)
//    {
//      sDate.WeekDay = 7;
//    }
//  }
//  // Print out
//  Seria1DbgPrintf(LogInfoCtl,"\r\nUpdateRtcTime: %X-%X-%X %X:%X:%X %s", \
//	sDate.Year,sDate.Month,sDate.Date, \
//	sTime.Hours,sTime.Minutes,sTime.Seconds, \
//	weekstring[sDate.WeekDay]);

//	MX_RTC_Init(sDate.Year,sDate.Month,sDate.Date,sTime.Hours,sTime.Minutes,sTime.Seconds);
////  HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD);
////  HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD);
//  
//	//RTC Alarm 20s 
//	SetRTCAlarmTime(20,TRUE);
//  
  return 0;
}

u8 SetRTCAlarmTime(u32 seconds, u8 Status)
{
	u8 ErrCode = 0;
//	u8 BCDday;
//	u8 BCDhour;
//	u8 BCDmin;
//	u8 BCDSec;
//	u32  CurrentSecs =0;  
//	TimeTableT    Timetable;
//	RTC_AlarmTypeDef sAlarm;
//	// Get seconds of current time
//	CurrentSecs = TimeTableToSeconds(GetRTCDatetime());
//	CurrentSecs += seconds;
//	Timetable =  SecondsToTimeTable(CurrentSecs);
//  // Converted to BCD Code
//	DectoBCD(Timetable.day, &BCDday, 1);
//	DectoBCD(Timetable.hour, &BCDhour, 1);
//	DectoBCD(Timetable.minute, &BCDmin, 1);
//	DectoBCD(Timetable.second, &BCDSec, 1);
//	// Set Alarm Values
//	sAlarm.AlarmTime.Hours = BCDhour;
//	sAlarm.AlarmTime.Minutes = BCDmin;
//	sAlarm.AlarmTime.Seconds = BCDSec;

//	sAlarm.Alarm = RTC_ALARM_A;
//	ErrCode = (u8)HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BCD);
//	// Print Out
//	Seria1DbgPrintf(RTCInfoCtl,"\r\n");
//	Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: Almset(%d)Next(%02X|%02X:%02X:%02X)Err(%d)", \
//		FmtTimeShow(), seconds,  \
//		BCDday, BCDhour, BCDmin, BCDSec, \
//		ErrCode);
//	// Print Out
//	if(Status == TRUE)
//	{
//		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: Alm Time(%d Secs)",FmtTimeShow(),seconds);
//	}
	return ErrCode;
}

static void CheckCurrentTemperature(void)
{
//	s16 NtcTemp;
//	s16 ShtTemp;
//	s16 Temperature;

//	// Get temperature and humidity 
//	ShtTemp = GetRealShtTemperature();
//	// Check ntc function
//	if(gDeviceParam.Temperature.NtcTemp.enflag != FALSE)
//	{
//		NtcTemp = GetRealNtcTemperature();
//		if(NtcTemp <= NTC_MAXIMUM_TEMP && \
//			NtcTemp >= NTC_MINIMUM_TEMP)
//		{
//			s16 DiffTemp;
//			// Check temp
//			if(ShtTemp > NtcTemp)
//			{
//				DiffTemp= ShtTemp - NtcTemp;
//			}
//			else
//			{
//				DiffTemp= NtcTemp - ShtTemp;
//			}
////			// Print Out
////			Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: NTC enable(%d %d %d) Ntc(%d) Sht(%d) Diff(%d)", \
////				FmtTimeShow(), \
////				gDeviceParam.Temperature.NtcTemp.enflag, \
////				gDeviceParam.Temperature.NtcTemp.Xlimit, \
////				gDeviceParam.Temperature.NtcTemp.Ylimit, \
////				NtcTemp, \
////				ShtTemp, \
////				DiffTemp);
////			// Check diff
////			if(DiffTemp > (gDeviceParam.Temperature.NtcTemp.Xlimit * 100))
////			{
////				Temperature = NtcTemp;
////			}
////			else if(DiffTemp < (gDeviceParam.Temperature.NtcTemp.Ylimit * 100))
////			{
////				Temperature = ShtTemp;
////			}
////			else
////			{
////				Temperature = ShtTemp;
////			}
//		}
//		else
//		{
//			Temperature = ShtTemp;
//			// Print Out
////			Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: NTC overflow(%d) min(%d) max(%d)", \
////				FmtTimeShow(), NtcTemp, \
////				NTC_MINIMUM_TEMP, \
////				NTC_MAXIMUM_TEMP);
//		}
//		// Print Out
////		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: NTC enable, Temp(%d)", FmtTimeShow(), Temperature);
//	}
//	else
//	{
//		Temperature = ShtTemp;
//		// Print Out
////		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: NTC disable, Temp(%d)", FmtTimeShow(), Temperature);
//	}
}

static void CheckPeriodicReportStatus(TimeTableT timeTable)
{
	// Print out
//	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] RTC: ---EVENT PERIODIC---\r\n",FmtTimeShow());
//	// Send out miti-report
//	SendMitiSystemInfoReport(DEVICE_EVENT_NORMAL, timeTable);
}

u32 ReadyToPeriodicReport(u32 CurTimeInSec, TimeTableT timeTable, u8 IsDevcieMovingStatus)
{
	u16 PeriodMoveTime = 0;//gDeviceParam.ReportPeriod.MoveTime * 60;
	u16 PeriodStaticTime = 0;//gDeviceParam.ReportPeriod.StaticTime * 60;

	u16 TimeDiffSecs = 0;
	u32 TheoryTimSecs = 0;

	if(IsDevcieMovingStatus == TRUE)	// MOVE
	{
		// Print Out
//		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: ---MOVE REPORT---Loop[%d Secs]", \
			FmtTimeShow(), PeriodMoveTime);
		// Get times
		TheoryTimSecs = TimeTableToSeconds(gRTCParam.PeriodicRptLastTime) + PeriodMoveTime;
	}
	else
	{
		// Print Out
//		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: ---STATIC REPORT---Loop[%d Secs]", \
			FmtTimeShow(), PeriodStaticTime);
		// Get times
		TheoryTimSecs = TimeTableToSeconds(gRTCParam.PeriodicRptLastTime) + PeriodStaticTime;
	}
	// Print Out
//	Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: Last time(%04d/%02d/%02d %02d:%02d:%02d) cmp(%d)", \
		FmtTimeShow(), \
		gRTCParam.PeriodicRptLastTime.year, \
		gRTCParam.PeriodicRptLastTime.month, \
		gRTCParam.PeriodicRptLastTime.day, \
		gRTCParam.PeriodicRptLastTime.hour, \
		gRTCParam.PeriodicRptLastTime.minute, \
		gRTCParam.PeriodicRptLastTime.second, \
		(TheoryTimSecs > CurTimeInSec));
	// Check times
	if(TheoryTimSecs > CurTimeInSec)
	{
		// Print out
//		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: Collect data diff time(%ld)", \
			FmtTimeShow(), \
			(TheoryTimSecs - CurTimeInSec));
		// Check periodic report
		CheckPeriodicReportStatus(timeTable);
		// Get next periodic report check timing
		// Move time second
		gRTCParam.MoveReportNextTim = PeriodMoveTime + TimeTableToSeconds(timeTable);
		// Static time first
		gRTCParam.StaticReportNextTim =  PeriodStaticTime + TimeTableToSeconds(timeTable);
		// Save time
		gRTCParam.PeriodicRptLastTime = timeTable;
	}
	else
	{
		TimeDiffSecs = CurTimeInSec - TheoryTimSecs;
		// Print out
//		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: Collect data cmp(%d) diff(%ld) loop(%d)", \
			FmtTimeShow(), \
			(TimeDiffSecs ==0 || TimeDiffSecs >= PeriodStaticTime), \
			TimeDiffSecs, \
			PeriodStaticTime);
		if(TimeDiffSecs ==0 || TimeDiffSecs >= PeriodStaticTime)
		{
			// Check periodic report
			CheckPeriodicReportStatus(timeTable);
			// Get next periodic report check timing
			// Move time second
			gRTCParam.MoveReportNextTim = PeriodMoveTime + TimeTableToSeconds(timeTable);
			// Static time first
			gRTCParam.StaticReportNextTim =  PeriodStaticTime + TimeTableToSeconds(timeTable);
			// Save time
			gRTCParam.PeriodicRptLastTime = timeTable;
		}
		else
		{
			// Print out
//			Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: Collect diff time data", FmtTimeShow());
			// Check periodic report
			CheckPeriodicReportStatus(SecondsToTimeTable(TheoryTimSecs));
			// Get next periodic report check timing
			// Move time second
			gRTCParam.MoveReportNextTim = PeriodMoveTime + TimeTableToSeconds(SecondsToTimeTable(TheoryTimSecs));
			// Static time first
			gRTCParam.StaticReportNextTim =  PeriodStaticTime + TimeTableToSeconds(SecondsToTimeTable(TheoryTimSecs));
			// Save time
			gRTCParam.PeriodicRptLastTime = SecondsToTimeTable(TheoryTimSecs);
		}
	}

	// Check current status
	if(IsDevcieMovingStatus == TRUE)	// MOVE
  {
		return PeriodMoveTime;
  }
	else
  {
		return PeriodStaticTime;
  }
}

static u32 CheckPeriodicReportTiming(u32 CurTimeInSec, TimeTableT timeTable)
{
	u32 TimingSecs = 0;
	u32 NextTimeSecs = 0;
	u8 MovementFlag = FALSE;

	MovementFlag = TRUE;

	
	if(gRTCParam.PeriodicReportEnable == TRUE)
	{
		if(MovementFlag == TRUE)
		{
			// Movement
			NextTimeSecs = gRTCParam.MoveReportNextTim;
			// Check timer
			if(NextTimeSecs <= CurTimeInSec)
			{
				TimingSecs = ReadyToPeriodicReport(CurTimeInSec, timeTable, TRUE);
			}
			else
			{
				TimingSecs = NextTimeSecs - CurTimeInSec;
			}
		}
		else
		{
			// Static
			NextTimeSecs = gRTCParam.StaticReportNextTim;
			// Check timer
			// Check timer
			if(NextTimeSecs <= CurTimeInSec)
			{
				TimingSecs = ReadyToPeriodicReport(CurTimeInSec, timeTable, FALSE);
			}
			else
			{
				TimingSecs = NextTimeSecs - CurTimeInSec;
			}
		}
		// Print Out
//		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: Next report(%d:%d %s)", \
//			FmtTimeShow(),
//			TimingSecs/60,TimingSecs%60, \
//			MovementFlag?"MOVE":"STATIC");
	}
	
	return TimingSecs;	
}

static u32 CheckTemperatureDetectTiming(u32 CurTimeInSec)
{
	u32 TimingSecs = 0;
	
	if(gRTCParam.TempDetectEnable == TRUE)
	{
		// Check timer
		if(gRTCParam.TempDetectNextTim <= CurTimeInSec)
		{
			// Get next temp check timing
			TimingSecs = TEMP_CHK_TIME;
			gRTCParam.TempDetectNextTim = TimingSecs + TimeTableToSeconds(GetRTCDatetime());
			// Print Out
//			Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: ---TEMP---", FmtTimeShow());
			// Check temperature
			CheckCurrentTemperature();
		}
		else
		{
			TimingSecs = gRTCParam.TempDetectNextTim - CurTimeInSec;
		}
		// Print Out
//		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: Next temp(%d)",FmtTimeShow(),TimingSecs);
	}
	
	return TimingSecs;	
}

#ifdef SYNCHRONIZATION_TIME_FROM_MODEM
static u32 SynchronizationNetworkTimeTiming(u32 CurTimeInSec)
{	
	u32 TimingSecs = 0;
	
	if(gRTCParam.SyncNetTimEnable == TRUE)
	{
		// Check synchronization time Status
		if(gRTCParam.SyncNetNextTim <= CurTimeInSec)
		{
			// Get next sync sys timing
			TimingSecs = SYNC_SYS_TIME;
			gRTCParam.SyncNetNextTim = TimingSecs + TimeTableToSeconds(GetRTCDatetime());
			// Print Out
//			Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: ---SYNCTIME---", FmtTimeShow());
			// Set flag
//			gDeviceParam.SyncTimeFlag = TRUE;
		}
		else
		{
			TimingSecs = gRTCParam.SyncNetNextTim - CurTimeInSec;
		}
		// Print Out
//		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: Next synctim(%d:%d:%d)", \
//			FmtTimeShow(),\
//			(TimingSecs/3600), \
//			((TimingSecs%3600)/60), \
//			((TimingSecs%3600)%60));
	}

	return TimingSecs;	
}
#endif

void CheckCurrentIllumination(void)
{

}

void AllRtcTimerTimeInit(void)
{
	// Print Out
//	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] RTC: Init realtime timer",FmtTimeShow());

	// Illumination detect
	gRTCParam.LightDetectEnable = TRUE;

	// Movement detect
	gRTCParam.MoveDetectNextTim = MOVE_CHK_TIME + TimeTableToSeconds(GetRTCDatetime());
	gRTCParam.MoveDetectEnable = TRUE;

	// Temperature detect
	gRTCParam.TempDetectNextTim = TEMP_CHK_TIME + TimeTableToSeconds(GetRTCDatetime());
	gRTCParam.TempDetectEnable = TRUE;	
	
	// Periodic report detect
//	gRTCParam.MoveReportNextTim = gDeviceParam.ReportPeriod.MoveTime * 60 + TimeTableToSeconds(GetRTCDatetime());
//	gRTCParam.StaticReportNextTim = gDeviceParam.ReportPeriod.StaticTime * 60 + TimeTableToSeconds(GetRTCDatetime());
	gRTCParam.PeriodicReportEnable = TRUE;

	// Synchronization network time
	#ifdef SYNCHRONIZATION_TIME_FROM_MODEM
	gRTCParam.SyncNetNextTim = SYNC_SYS_TIME + TimeTableToSeconds(GetRTCDatetime());
	gRTCParam.SyncNetTimEnable = TRUE;
	#endif
}

void AllRtcTimerTimeDeinit(void)
{
	// Print Out
//	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] RTC: Deinit realtime timer",FmtTimeShow());

	// Illumination detect
	gRTCParam.LightDetectEnable = FALSE;

	// Movement detect
	gRTCParam.MoveDetectEnable = FALSE;
	gRTCParam.MoveDetectNextTim = 0;

	// Temperature detect
	gRTCParam.TempDetectEnable = FALSE;
	gRTCParam.TempDetectNextTim = 0;
	
	// Periodic report detect
	gRTCParam.PeriodicReportEnable = FALSE;
	gRTCParam.MoveReportNextTim = 0;
	gRTCParam.StaticReportNextTim = 0;

	// Synchronization network time
	#ifdef SYNCHRONIZATION_TIME_FROM_MODEM
	gRTCParam.SyncNetTimEnable = FALSE;
	gRTCParam.SyncNetNextTim = 0;
	#endif
}

void CheckAccurateTiming(RtcSyncT RtcSyncType, TimeTableT timeTable)
{
	#ifdef ENABLE_RTC_INTERRUPT
	u8 ErrorCode = 0;
	u32 TimingSecs = 20;
	u32 NewTimSecs = 0;

	// Periodic report
	NewTimSecs = CheckPeriodicReportTiming(TimeTableToSeconds(timeTable), timeTable);
	if(NewTimSecs != 0 && (TimingSecs == 0 || NewTimSecs < TimingSecs))
	{
		TimingSecs = NewTimSecs;
	}

	// Temperature detect
	NewTimSecs = CheckTemperatureDetectTiming(TimeTableToSeconds(timeTable));
	if(NewTimSecs != 0 && (TimingSecs == 0 || NewTimSecs < TimingSecs))
	{
		TimingSecs = NewTimSecs;
	}
	#ifdef SYNCHRONIZATION_TIME_FROM_MODEM
	// Synchronization Network Time
	NewTimSecs = SynchronizationNetworkTimeTiming(TimeTableToSeconds(timeTable));
	if(NewTimSecs != 0 && (TimingSecs == 0 || NewTimSecs < TimingSecs))
	{
		TimingSecs = NewTimSecs;
	}
	#endif

	// Check Timing
	if(TimingSecs > 1)
	{
//		ErrorCode = SetRTCAlarmTime(TimingSecs,FALSE);
	}
	else
	{
//		ErrorCode = SetRTCAlarmTime(2,TRUE);
	}
	// Print Out Err code
	if(ErrorCode != 0)
	{
//		Seria1DbgPrintf(RTCInfoCtl,"\r\n[%s] RTC: ERR CODE(%d)", \
//			FmtTimeShow(), \
//			ErrorCode);
	}
	// Refresh IWDG: reload counter
  //	TickHardwareWatchdog(TRUE);
	#endif
}

void RealTimeAlmCheckStatus(void)
{
	if(GetRTCAlarmStatus() == TRUE)
	{
		// Refresh IWDG: reload counter
//		TickHardwareWatchdog(TRUE);
		// Reset RTC Alm Flag
		SetRTCAlarmStatus(FALSE);
		// Print Out
//		Seria1DbgPrintf(RTCInfoCtl,"\r\n\r\n[%s] RTC: Int Happen",FmtTimeShow());
		//RTC Alarm 20s 
		SetRTCAlarmTime(20,TRUE);
    
//    HAL_UART_Receive_IT(&huart1, (uint8_t *)&Uart1RxValue, 1); //uart1 receive interrupt
//    HAL_UART_Receive_IT(&huart2, (uint8_t *)&Uart2RxValue, 1); //uart2 receive interrupt
//    HAL_UART_Receive_IT(&huart3, (uint8_t *)&Uart3RxValue, 1); //uart3 receive interrupt
	}
}
u8 IsLeapYear(u32 year)
{
		if(year%4==0)
		{
				if(year%100==0)
				{
					if(year%400==0)
						return 1;
					else
						return 0;
				}
				return 1;
		}
		else 
			return 0;
}
const u8 Month_Tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void WriteInternetTime(u8 syear,u8 smon,u8 sday,u8 shour, u8 smin,u8 sec)
{
		u8 t;
		TimeStartCnt=YEAR_2000_SEC;
		for(t=0;t<syear;t++)
		{
			if(IsLeapYear(2000+t))TimeStartCnt+=LEAP_YEAR_SEC;
			else TimeStartCnt+=NORM_YEAR_SEC;
		}
		for(t=1;t<smon;t++)
		{
				TimeStartCnt+=Month_Tab[t]*DAY_SEC;
				if((t==2)&(IsLeapYear(2000+syear)))TimeStartCnt+=DAY_SEC;
		}
		TimeStartCnt+=(sday-1)*DAY_SEC;
		TimeStartCnt+=shour*HOUR_SEC;
		TimeStartCnt+=smin*MINUTE_SEC;
		TimeStartCnt+=sec;
}

TimeTableT GetRTCDatetime(void)
{

	TimeTableT timeTable;
	u32 temp=0;
	u32 temp1=0;
	u32 daycnt=0;
	temp=TimeStartCnt/DAY_SEC;
	if(daycnt!=temp)
	{
		daycnt=temp;
//		Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] day %d",FmtTimeShow(),temp);
		temp1=1970;
		while(temp>=365)
		{
				if(IsLeapYear(temp1))
				{
					if(temp>=366)
						temp-=366;
					else
					{
						break;
					}
				}
				else
				{
					temp-=365;
				}
				temp1++;
		}
	}
//	Seria1DbgPrintf(LogInfoCtl,"\r\n[%s] day %d",FmtTimeShow(),temp);
	timeTable.year=temp1;
	temp1=1;
	while(temp>=28)
	{
		if(IsLeapYear(timeTable.year)&&temp1==2)
		{
			if(temp>=29)temp-=29;
			else break;
		}
		else
		{
			if(temp>=Month_Tab[temp1])temp-=Month_Tab[temp1];
			else break;
		}
		temp1++;
	}
	timeTable.month=temp1;
	timeTable.day=temp+1;
	temp=TimeStartCnt%DAY_SEC;
	timeTable.hour=temp/HOUR_SEC;
	timeTable.minute=temp%HOUR_SEC/MINUTE_SEC;
	timeTable.second=temp%MINUTE_SEC;
	return timeTable;
}
/*******************************************************************************
End Of The File
*******************************************************************************/


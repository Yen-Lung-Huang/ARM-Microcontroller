/*******************************************************************************
* File Name          : flash.c
* Author             : lizhifei
* Description        : This file provides all the flash functions.

* History:
* 2021/02/03 : version V1.00
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "flash.h"

#include "main.h"

#include "uart_driver.h"
#include "usart.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
#define FMC_PAGE_SIZE                ((uint16_t)0x400) 
//#ifdef REMAP_MEMORY_SRAM
//#if   (defined ( __CC_ARM ))
//  __IO uint32_t VectorTable[48] __attribute__((at(0x20000000)));
//#elif (defined (__ICCARM__))
//#pragma location = 0x20000000
//  __no_init __IO uint32_t VectorTable[48];
//#elif defined   (  __GNUC__  )
//  __IO uint32_t VectorTable[48] __attribute__((section(".RAMVectorTable")));
//#elif defined ( __TASKING__ )
//#endif

////#pragma abs_address:0x7000
//void AppRemapmemorySRAM(void)
//{
//  u8 i =0;
//  for(i = 0; i < 48; i++)
//  {
//    VectorTable[i] = *(__IO uint32_t*)(JUMP_TO_APPLICATION_ADDRESS + (i<<2));
//  }
//  /// Remap SRAM at 0x00000000
////  __HAL_SYSCFG_REMAPMEMORY_SRAM();
//}
//#endif

unsigned char ParameterBuffer[8];
//uint16_t ReferenceValue=0;//临时用
/**
  * @brief  Unlocks Flash for write access
  * @param  None
  * @retval None
  */
//void FLASH_If_Init(void)
//{
//  /* Unlock the Program memory */
//  HAL_FLASH_Unlock();

//  /* Clear all FLASH flags */
//  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR);
//  /* Unlock the Program memory */
//  HAL_FLASH_Lock();
//}

///**
//  * @brief  This function does an erase of all user flash area
//  * @param  start: start of user flash area
//  * @retval FLASHIF_OK : user flash area successfully erased
//  *         FLASHIF_ERASEKO : error occurred
//  */
//uint32_t FLASH_If_Erase(u32 StartAddr, u32 EndAddr)
//{
//  uint32_t NbrOfPages = 0;
//  uint32_t PageError = 0;
//  FLASH_EraseInitTypeDef pEraseInit;
//  HAL_StatusTypeDef status = HAL_OK;

//  /* Unlock the Flash to enable the flash control register access *************/ 
//  HAL_FLASH_Unlock();

//  /* Get the sector where start the user flash area */
//  NbrOfPages = (EndAddr - StartAddr)/FLASH_PAGE_SIZE;

//  pEraseInit.TypeErase = FLASH_TYPEERASE_PAGES;
//  pEraseInit.PageAddress = StartAddr;
//  pEraseInit.Banks = FLASH_BANK_1;
//  pEraseInit.NbPages = NbrOfPages;
//  status = HAL_FLASHEx_Erase(&pEraseInit, &PageError);

//  /* Lock the Flash to disable the flash control register access (recommended
//     to protect the FLASH memory against possible unwanted operation) *********/
//  HAL_FLASH_Lock();

//  if (status != HAL_OK)
//  {
//    /* Error occurred while page erase */
//    return FLASHIF_ERASEKO;
//  }

//  return FLASHIF_OK;
//}

///* Public functions ---------------------------------------------------------*/
///**
//  * @brief  This function writes a data buffer in flash (data are 32-bit aligned).
//  * @note   After writing data buffer, the flash content is checked.
//  * @param  destination: start address for target location
//  * @param  p_source: pointer on buffer with data to write
//  * @param  length: length of data buffer (unit is 32-bit word)
//  * @retval uint32_t 0: Data successfully written to Flash memory
//  *         1: Error occurred while writing data in Flash memory
//  *         2: Written Data in flash memory is different from expected one
//  */
//uint32_t FLASH_If_Write(uint32_t StartAddr, uint32_t EndAddr, uint32_t *p_source, uint32_t length)
//{
//  uint32_t i = 0;

//  /* Unlock the Flash to enable the flash control register access *************/
//  HAL_FLASH_Unlock();

//  for (i = 0; (i < length) && (StartAddr <= (EndAddr-4)); i++)
//  {
//    /* Device voltage range supposed to be [2.7V to 3.6V], the operation will
//       be done by word */ 
//    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, StartAddr, *(uint32_t*)(p_source+i)) == HAL_OK)      
//    {
//     /* Check the written value */
//      if (*(uint32_t*)StartAddr != *(uint32_t*)(p_source+i))
//      {
//        /* Flash content doesn't match SRAM content */
//        return(FLASHIF_WRITINGCTRL_ERROR);
//      }
//      /* Increment FLASH destination address */
//      StartAddr += 4;
//    }
//    else
//    {
//      /* Error occurred while writing data in Flash memory */
//      return (FLASHIF_WRITING_ERROR);
//    }
//  }

//  /* Lock the Flash to disable the flash control register access (recommended
//     to protect the FLASH memory against possible unwanted operation) *********/
//  HAL_FLASH_Lock();

//  return (FLASHIF_OK);
//}


///**
//  * @brief  Returns the write protection status of application flash area.
//  * @param  None
//  * @retval If a sector in application area is write-protected returned value is a combinaison
//            of the possible values : FLASHIF_PROTECTION_WRPENABLED, FLASHIF_PROTECTION_PCROPENABLED, ...
//  *         If no sector is write-protected FLASHIF_PROTECTION_NONE is returned.
//  */
//uint32_t FLASH_If_GetWriteProtectionStatus(void)
//{
//  uint32_t ProtectedPAGE = FLASHIF_PROTECTION_NONE;
//  FLASH_OBProgramInitTypeDef OptionsBytesStruct;

//  /* Unlock the Flash to enable the flash control register access *************/
//  HAL_FLASH_Unlock();

//  /* Check if there are write protected sectors inside the user flash area ****/
//  HAL_FLASHEx_OBGetConfig(&OptionsBytesStruct);

//  /* Lock the Flash to disable the flash control register access (recommended
//     to protect the FLASH memory against possible unwanted operation) *********/
//  HAL_FLASH_Lock();

//  /* Get pages already write protected ****************************************/
//  ProtectedPAGE = ~(OptionsBytesStruct.WRPPage) & FLASH_PAGE_TO_BE_PROTECTED;

//  /* Check if desired pages are already write protected ***********************/
//  if(ProtectedPAGE != 0)
//  {
//    /* Some sectors inside the user flash area are write protected */
//    return FLASHIF_PROTECTION_WRPENABLED;
//  }
//  else
//  { 
//    /* No write protected sectors inside the user flash area */
//    return FLASHIF_PROTECTION_NONE;
//  }
//}


///**
//  * @brief  Configure the write protection status of user flash area.
//  * @param  protectionstate : FLASHIF_WRP_DISABLE or FLASHIF_WRP_ENABLE the protection
//  * @retval uint32_t FLASHIF_OK if change is applied.
//  */
//uint32_t FLASH_If_WriteProtectionConfig(uint32_t protectionstate)
//{
//  uint32_t ProtectedPAGE = 0x0;
//  FLASH_OBProgramInitTypeDef config_new, config_old;
//  HAL_StatusTypeDef result = HAL_OK;
//  

//  /* Get pages write protection status ****************************************/
//  HAL_FLASHEx_OBGetConfig(&config_old);

//  /* The parameter says whether we turn the protection on or off */
//  config_new.WRPState = (protectionstate == FLASHIF_WRP_ENABLE ? OB_WRPSTATE_ENABLE : OB_WRPSTATE_DISABLE);

//  /* We want to modify only the Write protection */
//  config_new.OptionType = OPTIONBYTE_WRP;
//  
//  /* No read protection, keep BOR and reset settings */
//  config_new.RDPLevel = OB_RDP_LEVEL_0;
//  config_new.USERConfig = config_old.USERConfig;  
//  /* Get pages already write protected ****************************************/
//  ProtectedPAGE = config_old.WRPPage | FLASH_PAGE_TO_BE_PROTECTED;

//  /* Unlock the Flash to enable the flash control register access *************/ 
//  HAL_FLASH_Unlock();

//  /* Unlock the Options Bytes *************************************************/
//  HAL_FLASH_OB_Unlock();
//  
//  /* Erase all the option Bytes ***********************************************/
//  result = HAL_FLASHEx_OBErase();
//    
//  if (result == HAL_OK)
//  {
//    config_new.WRPPage    = ProtectedPAGE;
//    result = HAL_FLASHEx_OBProgram(&config_new);
//  }
//  
//  return (result == HAL_OK ? FLASHIF_OK: FLASHIF_PROTECTION_ERRROR);
//}

//void FLASH_Init(void)
//{
//  /* Unlock the Program memory */
//  HAL_FLASH_Unlock();

//  /* Clear all FLASH flags */
//  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR);
//  /* Unlock the Program memory */
//  HAL_FLASH_Lock();
//}

//u32 FlashMemoryWrite(u32 Address, u32 *Data, u32 Len)
//{
//  HAL_FLASH_Unlock();
//  
//  for(int i=0;i<Len;i++)
//  {    
//    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, *Data) == HAL_OK)      
//    {
//     /* Check the written value */
//      if (*(uint32_t*)Address != *(uint32_t*)(Data+i))
//      {
//        /* Flash content doesn't match SRAM content */
//        return(FLASHIF_WRITINGCTRL_ERROR);
//      }
//      /* Increment FLASH destination address */
//      Address += 4;
//    }
//    else
//    {
//      /* Error occurred while writing data in Flash memory */
//      return (FLASHIF_WRITING_ERROR);
//    }
//  }
//  
//	HAL_FLASH_Lock();  
//  
//  return (FLASHIF_OK);
//}

//u32 FlashMemoryRead(u32 Address)
//{
//  return (u32)(*(u32*)Address);
//}

//static HAL_StatusTypeDef FlashMemoryErasePage(u32 StartAddr, u32 EndAddr)
//{
//	u32 PageError = 0;
//	/*Variable used for Erase procedure*/
//	FLASH_EraseInitTypeDef EraseInitStruct;
//	EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
//	EraseInitStruct.PageAddress = StartAddr;
//	EraseInitStruct.NbPages = (EndAddr - StartAddr)/FLASH_PAGE_SIZE;
//	return HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);
//}

void WriteIAPFlagToFlashMemory(u32 Value)
{
	FMC_State FLASHstatus = FMC_READY;
	FMC_Unlock();
	FMC_ClearBitState(FMC_FLAG_PERR|FMC_FLAG_WERR|FMC_FLAG_EOP );
  FLASHstatus=FMC_ErasePage(MCU_OTA_ADDRESS);
	if(FLASHstatus == FMC_READY)
	{
		FLASHstatus = FMC_ProgramWord(MCU_OTA_ADDRESS, Value);
	}
	FMC_Lock(); 
}

void WriteProductTypeToFlashMemory(u32 Value)
{
	FMC_State FLASHstatus = FMC_READY;
	FMC_Unlock();
	FMC_ClearBitState(FMC_FLAG_PERR|FMC_FLAG_WERR|FMC_FLAG_EOP );
  FLASHstatus=FMC_ErasePage(PRODUCT_TYPE_ADDRESS);
	if(FLASHstatus == FMC_READY)
	{
		FLASHstatus = FMC_ProgramWord(PRODUCT_TYPE_ADDRESS, Value);
	}
	FMC_Lock(); 
}

void WriteTocToFlashMemory(u32 Value)
{
	FMC_State FLASHstatus = FMC_READY;
	FMC_Unlock();
	FMC_ClearBitState(FMC_FLAG_PERR|FMC_FLAG_WERR|FMC_FLAG_EOP );
  FLASHstatus=FMC_ErasePage(TOC_CALIBRATION_ADDRESS);
	if(FLASHstatus == FMC_READY)
	{
		FLASHstatus = FMC_ProgramWord(TOC_CALIBRATION_ADDRESS, Value);
	}
	FMC_Lock(); 
}

void WriteProduceToFlashMemory(u32 Value)
{
	FMC_State FLASHstatus = FMC_READY;
	FMC_Unlock();
	FMC_ClearBitState(FMC_FLAG_PERR|FMC_FLAG_WERR|FMC_FLAG_EOP );
	FLASHstatus=FMC_ErasePage(PRODUCE_CHECK);
	if(FLASHstatus == FMC_READY)
	{
		FLASHstatus = FMC_ProgramWord(PRODUCE_CHECK, Value);
	}
	FMC_Lock(); 
}

u32 ReadIAPFlagFromFlashMemory(void)
{
	return (u32)(*(u32*)IAP_FLAG);
}
void FlashMemoryRead(u32 Address,u32 *Data,u32 Len)
{
	u32 i;
	u32* Tempdata;
	for(i=0;i<Len;i++)
	{    
		Tempdata= (uint32_t*)Address ;
		*Data = (u32)*Tempdata;
		Address+=4;
		Data ++;
	}
}
u32 FlashMemoryOneByteRead(u32 Address)
{
	return (u32)(*(u32*)Address);
}
u32 FlashMemoryWrite(u32 Address, u32 *Data, u32 Len)
{
	FMC_State FLASHstatus = FMC_READY;
	int i;
	u32 tempdata;
	FMC_Unlock();
	FMC_ClearBitState(FMC_FLAG_PERR|FMC_FLAG_WERR|FMC_FLAG_EOP );
	FLASHstatus=FMC_ErasePage(Address);
	for( i=0;i<Len;i++)
	{ 
		tempdata=(u32)(*Data);
		if(FLASHstatus == FMC_READY)
		{
			FLASHstatus = FMC_ProgramWord(Address, tempdata);//每次写入完成后地址加4，2个字节写入
			Address += 4;
			Data ++;
		}	
		
	}

	FMC_Lock();   
	return (FLASHIF_OK);
}
//存储参数

//*********************************************************************************
// memcopy
//*********************************************************************************
void memcopy(unsigned char *inStrSrc, unsigned char *inStrDes, unsigned short inLen)
{
    unsigned short TempB;

    for(TempB=0; TempB<inLen; TempB++) 
		{
			inStrDes[TempB] = inStrSrc[TempB];
		}
}

//
uint32_t FLASH_If_Erase(uint32_t start,uint32_t end)
{
  uint32_t NbrOfPages = 0;
  uint32_t PageCnt = 0;
  HAL_StatusTypeDef status = HAL_OK;
	FMC_State FLASHstatus = FMC_READY;

  /* Unlock the Flash to enable the flash control register access *************/ 
  FMC_Unlock();

  /* Get the sector where start the user flash area */
	FMC_ClearBitState(FMC_FLAG_PERR|FMC_FLAG_WERR|FMC_FLAG_EOP );
  NbrOfPages = (end - start)/FLASH_PAGE_SIZE;
	for(PageCnt=0;PageCnt<NbrOfPages;PageCnt++)
	{
			
		  if(FLASHstatus == FMC_READY ) 
			{
				FLASHstatus=FMC_ErasePage(start);
			  start+=FLASH_PAGE_SIZE;
			}
	}
  /* Lock the Flash to disable the flash control register access (recommended
     to protect the FLASH memory against possible unwanted operation) *********/
  FMC_Lock();   

  if (status != HAL_OK)
  {
    /* Error occurred while page erase */
    return FLASHIF_ERASEKO;
  }

  return FLASHIF_OK;
}

uint32_t FLASH_If_Write(uint32_t destination, uint32_t *p_source, uint32_t length)
{
	u32 tempdata;
	int i;
	FMC_State FLASHstatus = FMC_READY;
	FMC_Unlock();
	for(i=0;i<length;i++)
	{ 
		tempdata=(u32)(*p_source);
		if(FLASHstatus == FMC_READY)
		{
			FLASHstatus =FMC_ProgramWord(destination, tempdata);

			/* Check the written value */
			if (*(uint32_t*)destination != tempdata)
			{
				Seria1DbgPrintf(LogInfoCtl,"\r\n Flash error\r\n");
				/* Flash content doesn't match SRAM content */
				return(FLASHIF_WRITINGCTRL_ERROR);
			}
			/* Increment FLASH destination address */
			destination += 4;
			p_source ++;
		}
	}

	FMC_Lock();   
	return (FLASHIF_OK);

}
//extern DeviceParameterT gDeviceParameter;
//unsigned char ReadMacParameter(void)
//{
//	unsigned char *TempPtr;
//	//unsigned char tempA,tempB,tempC,tempD;
//	u8 len = 0;
//	//FlashMemoryRead(PARAMETER_ADDRESS,ParameterBuffer,128);
//	
//	TempPtr = (unsigned char *)MAC_ADDRESS;
//	memcopy(TempPtr, ParameterBuffer, 16);
//	gDeviceParameter.ModemWifiMac[0] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[1] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[2] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[3] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[4] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[5] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[6] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[7] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[8] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[9] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[10] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[11] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[12] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[13] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[14] = ParameterBuffer[len];len ++;
//	gDeviceParameter.ModemWifiMac[15] = ParameterBuffer[len];len ++;
//	return 0;
//}

/*******************************************************************************
End Of The File
*******************************************************************************/


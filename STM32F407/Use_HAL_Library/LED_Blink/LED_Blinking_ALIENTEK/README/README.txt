1.實驗目的：
　新建基於STM32F4固件庫V1.3.0的工程模板

2.實驗現象：
　下載進開發板之後,紅綠燈閃爍

3.注意事項：
　1)新建工程的時候,請確保選擇目標→C / c++選項卡的全部宏定義定義輸入框字符串為:STM32F40_41xxx USE_STDPERIPH_DRIVER

4 .手冊中講解到步驟15的時候的c源碼如下:





#include "stm32f4xx.h"


//ALIENTEK探索者STM32F407開發板實驗0
//STM32F4工程模板-庫函數版本
//技術支持:www.openedv.com
//淘寶店鋪:http://eboard.taobao.com
//廣州市星翼電子科技有限公司
//作者:正點原子@ALIENTEK
  
void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{

  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOF, &GPIO_InitStructure);

  while(1){
		GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		Delay(0x7FFFFF);
		GPIO_ResetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		Delay(0x7FFFFF);
	
	}
}

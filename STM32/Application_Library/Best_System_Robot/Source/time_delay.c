#include "time_delay.h"

__IO float usDelayBase;

void delay_us_init(void)
{
    __IO uint32_t firstms, secondms;
    __IO uint32_t counter = 0;

    firstms = HAL_GetTick()+1;
    secondms = firstms+1;

    while(uwTick!=firstms) ;

    while(uwTick!=secondms) {
        counter++;
    }

    usDelayBase = ((float)counter)/1000;

    delay_us_optimize();
}

void delay_us_t(uint32_t Delay)
{
    __IO uint32_t delayReg;
    __IO uint32_t usNum = (uint32_t)(Delay*usDelayBase);

    delayReg = 0;
    while(delayReg!=usNum) {
        delayReg++;
    }
}

void delay_us_optimize(void)
{
    __IO uint32_t firstms, secondms;
    __IO float coe = 1.0;

    firstms = HAL_GetTick();
    delay_us_t(1000000) ;
    secondms = HAL_GetTick();

    coe = ((float)1000)/(secondms-firstms);
    usDelayBase = coe*usDelayBase;
}

void delay_us(uint32_t Delay)
{
    __IO uint32_t delayReg;

    __IO uint32_t msNum = Delay/1000;
    __IO uint32_t usNum = (uint32_t)((Delay%1000)*usDelayBase);

    if(msNum>0) {
        HAL_Delay(msNum);
    }

    delayReg = 0;
    while(delayReg!=usNum) {
        delayReg++;
    }
}

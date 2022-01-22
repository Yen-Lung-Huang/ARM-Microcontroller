/**
 ******************************************************************************
 *
 * @file        MG32x02z_CSC_Init.h
 *
 * @brief       This file is used to configure CSC setting.
 *              Device : MG32F02U128
 *
 * @par         Project
 *              MG32x02z
 * @version     V0.63
 * @date        2021/11/02 15:11 (H File Generated Date)
 * @author      Megawin Software Center
 * @copyright   Copyright (c) 2020 Megawin Technology Co., Ltd.
 *              All rights reserved.
 *
 ******************************************************************************* 
 * @par         Disclaimer
 * The Demo software is provided "AS IS" without any warranty, either
 * expressed or implied, including, but not limited to, the implied warranties
 * of merchantability and fitness for a particular purpose. The author will
 * not be liable for any special, incidental, consequential or indirect
 * damages due to loss of data or any other reason.
 * These statements agree with the world wide and local dictated laws about
 * authorship and violence against these laws.
 *******************************************************************************
 */
#include "MG32x02z.h"
#include "MG32x02z_CSC.h"
#include "MG32x02z_MEM.h"
#include "MG32x02z_GPIO.h"


#ifndef _MG32x02z_CSC_INIT_H
/*!< _MG32x02z_CSC_INIT_H */ 
#define _MG32x02z_CSC_INIT_H

#define MG32x02z_CSC_INIT_VER            63    // CSC Initial .h Version

//*** <<< Use Configuration Wizard in Context Menu >>> ***
/**
 ******************************************************************************
 *
 * @brief       CSC Initial Configure
 *
 ******************************************************************************
 */

//<h> CSC Initial Configure

//      <o> Enter XOSC Or External Clock Frequency 1~36000000Hz <1-36000000>
//      <i> When use CK_HS = CK_XOSC or CK_EXT, this space must be entered at the correct frequency.
//      <i> CK_XOSC = 1~25000000Hz, CK_EXT = 1~36000000Hz
#define CONF_XOSC_EXTCK_FREQ             12000000    // 1

//      <o.18> Select IHRCO <0=> 12MHz
//                          <1=> 11.059MHz
//      <i> IHRCO clock source frequency select.
#define CONF_CSC_IHRCO_SEL                0x00000000  // 2  [18] IHRCO Select

//          <o.16..17> Select XOSC Gain <0=> Normal Gain For 32 KHz
//                                      <1=> Medium Gain 4 ~ 25MHz
//                                      <2=> Lowest Gain For 32 KHz
//          <i> Xtal oscillator gain select. 
#define CONF_CSC_XOSC_GN                  0x00010000  // 3  [17:16] XOSC Gain

//      <q.4> Disable MCD(Missing Clock Detector)
#define CONF_CSC_MCD_DIS                  0x00000010  // 4  [4] MCD Disable
//      <o.22..23> Select Missing Clock Detection Duration <0=> 125us
//                                                         <1=> 250us
//                                                         <2=> 500us
//                                                         <3=> 1ms
//      <i> MCD detection duration time select. Large time selection makes slow MCD response. 
#define CONF_CSC_MCD_SEL                  0x00000000  // 5  [23:22] MCD Duration Select

//      <o.10..11> Select CK_HS Source <0=> CK_IHRCO
//                                     <1=> CK_XOSC
//                                     <2=> CK_ILRCO
//                                     <3=> CK_EXT
//      <i> When Select CK_HS Source = CK_XOSC, MG32x02z_GPIO_Init.h Wizard PC13 configutaion and PC14 configutaion must disable.
#define CONF_CSC_HS_SEL                   0x00000000  // 6  [11:10] CK_HS Select

//      <o.12..13> Select CK_HS2 Source <0=> CK_IHRCO
//                                      <1=> CK_XOSC
//                                      <3=> CK_EXT
//      <i> When Select CK_HS Source = CK_XOSC, MG32x02z_GPIO_Init.h Wizard PC13 configutaion and PC14 configutaion must disable.
//      <i> This function is only supported for MG32F02U128, MG32F02U064, MG32F02A128, MG32F02A064.
#define CONF_CSC_HS2_SEL                  0x00000000  // 7  [13:12] CK_HS2 Select

//      <h> Configure PLL
//          <o.1> Select PLL Input Clock Source <0=> CK_HS
//                                              <1=> CK_HS2
//      <i> This function is only supported for MG32F02U128, MG32F02U064, MG32F02A128, MG32F02A064.
#define CONF_CSC_PLLI_SEL                 0x00000000  // 8
//          <o.0..1> Select CK_PLLI Divider <0=> CK_HSx/1
//                                          <1=> CK_HSx/2
//                                          <2=> CK_HSx/4
//                                          <3=> CK_HSx/6
#define CONF_CSC_PLLI_DIV                 0x00000001  // 9  [1:0] PLLI DIV
#define CONF_CSC_PLL_MUL                  0x00000000  // 10
//          <o.9..14> Select CK_PLL MultiplicationX Factor <4-32>
//          <i> CK_PLL output frequency = (CK_PLLI PLL input frequency) * (value)
#define CONF_CSC_PLL_MULX                 8192  // 11  [5:0] PLL MUL
//          <o.4..5> Select CK_PLLO Divider <0=> CK_PLL/4
//                                          <1=> CK_PLL/3
//                                          <2=> CK_PLL/2
//                                          <3=> CK_PLL/1
#define CONF_CSC_PLLO_DIV                 0x00000000  // 12  [5:4] PLLO DIV
//      </h>

//      <o.14..15> Select CK_MAIN Source <0=> CK_HS
//                                       <1=> CK_PLLI
//                                       <2=> CK_PLLO 
//      <i> When Select CK_MAIN Source = CK_PPLI, the PLL must enable.
#define CONF_CSC_MAIN_SEL                 0x00000000  // 14  [15:14] CK_MAIN Select

//      <o.8..9> Select CK_LS Source <1=> CK_XOSC
//                                   <2=> CK_ILRCO
//                                   <3=> CK_EXT
//      <i> When Select CK_LS Source = CK_XOSC, MG32x02z_GPIO_Init.h Wizard PC13 configutaion and PC14 configutaion  must disable.
#define CONF_CSC_LS_SEL                   0x00000200  // 15  [9:8] CK_LS Select

//      <o.16> Select CK_ST Source <0=> HCLK/8
//                                 <1=> CK_LS/2
//      <i> System tick timer external clock source select.
//      <i> This function is valid when CPU_CLKSOURCE is set 0(default).
#define CONF_CSC_ST_SEL                   0x00000000  // 16  [16] CK_ST Select

/**/
//      <e.0> IHRCO/PLL Enable or XOSC/EXTCK AFS Pin Disable
//      <i> The functions enable or disable by C-code checking if this CheckBox unchecked.
//      <i> The functions enable or disable by following user setting if this CheckBox checked.
#define CONF_CSC_CKIP_EN                  0x00000000  // 17  [0] 0=C-code auto checking

//            <q.3> IHRCO_EN
//            <i> IHRCO device enable
#define CONF_CSC_CR0_IHRCO_EN             0x00000008  // 18  [3] IHRCO_EN


//            <q.5> PLL_EN
//            <i> PLL device enable
#define CONF_CSC_CR0_PLL_EN               0x00000020  // 19  [5] PLL_EN (CSC_init.c and .h not used)


//            <q.31> XOSC_EN
//            <i> Crystal Oscillator and XIN/XOUT pins enable
#define CONF_CFG_XOSC_EN                  0x00000000  // 20  [31] XOSC_EN


//            <q.31> EXTCK_EN
//            <i> External clock input and XIN pin enable if CK_EXT was selected in any HS/HS2/LS Mux
#define CONF_CFG_EXTCK_EN                 0x00000000  // 21  [31] EXTCK pin enable (CSC_init.c and .h not used)

//      </e>

//      <o.16..18> Select APB Prescaler <0x00=> CK_MAIN/1
//                                      <0x01=> CK_MAIN/2
//                                      <0x02=> CK_MAIN/4
//                                      <0x03=> CK_MAIN/8
//                                      <0x04=> CK_MAIN/16
//          <i> CK_APB frequency = (CK_MAIN frequency) / (selected Divider Value)
#define CONF_CSC_APB_DIV                  0x00000000  // 22  [18:16] APB DIV

//      <o.8..11> Select AHB Prescaler <0x00=> CK_APB/1
//                                     <0x01=> CK_APB/2
//                                     <0x02=> CK_APB/4
//                                     <0x03=> CK_APB/8
//                                     <0x04=> CK_APB/16
//                                     <0x05=> CK_APB/32
//                                     <0x06=> CK_APB/64
//                                     <0x07=> CK_APB/128
//                                     <0x08=> CK_APB/256
//                                     <0x09=> CK_APB/512
//          <i> CK_AHB frequency = (CK_APB frequency) / (selected Divider Value)
#define CONF_CSC_AHB_DIV                  0x00000000  // 23  [11:8] AHB DIV

//      <o.26..27> Select CK_UT Divider <0x00=> ILRCO/32
//                                      <0x01=> ILRCO/8
//                                      <0x02=> ILRCO/16
//                                      <0x03=> ILRCO/128
//          <i> CK_UT frequency = (ILRCO frequency) / (selected Divider Value)
#define CONF_CSC_UT_DIV                   0x00000000  // 24  [27:26] UT DIV

//      <o.20..21> Select USB SIE Divider <0x00=> CK_PLL/1
//                                        <0x01=> CK_PLL/2
//                                        <0x02=> CK_PLL/3
//                                        <0x03=> CK_PLL/4
//          <i> USB SIE frequency = (CK_PLL frequency) / (selected Divider Value)
#define CONF_CSC_USB_DIV                  0x00100000  // 25  [21:20] USB DIV

//      <h> Configure Peripheral ON Mode Clock
//      <i> Peripheral module process clock enable when MCU is running ON mode.
//          <q.0>  Port A
//          <i> PA module process clock and register write-access enable.
#define CONF_CSC_IOPA_EN                  0x00000001  // 30
//          <q.1>  Port B
//          <i> PB module process clock and register write-access enable.
#define CONF_CSC_IOPB_EN                  0x00000002  // 31
//          <q.2>  Port C
//          <i> PC module process clock and register write-access enable.
#define CONF_CSC_IOPC_EN                  0x00000004  // 32
//          <q.3>  Port D
//          <i> PD module process clock and register write-access enable.
#define CONF_CSC_IOPD_EN                  0x00000008  // 33
//          <q.4>  Port E
//          <i> PE module process clock and register write-access enable.
#define CONF_CSC_IOPE_EN                  0x00000010  // 34
//          <q.8>  GPL
//          <i> GPL clock source enable.
#define CONF_CSC_GPL_EN                   0x00000100  // 35
//          <q.12> EMB
//          <i> EMB clock source enable.
#define CONF_CSC_EMB_EN                   0x00001000  // 36
//          <q.15> DMA
//          <i> DMA clock source enable.
#define CONF_CSC_DMA_EN                   0x00008000  // 37
//          <e.0>  ADC0
//          <i> ADC clock source enable.
#define CONF_CSC_ADC0_EN                  0x00000001  // 38
//              <o.0>  Select ADCx_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> ADC Process clock source select.
#define CONF_CSC_ADC0_CKS                 0x00000000  // 39
//          </e>
//          <e.2>  CMP
//          <i> CMP clock source enable.
#define CONF_CSC_CMP_EN                   0x00000004  // 40
//              <o.4>  Select CMP_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> CMP Process clock source select.
#define CONF_CSC_CMP_CKS                  0x00000004  // 41
//          </e>
//          <e.3>  DAC
#define CONF_CSC_DAC_EN                   0x00000008  // 42
//          <i> DAC clock source enable.
//              <o.5>  Select CMP_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> DAC Process clock source select.
#define CONF_CSC_DAC_CKS                  0x00000000  // 43
//          </e>
//          <q.5>  RTC
//          <i> RTC clock source enable.
#define CONF_CSC_RTC_EN                   0x00000020  // 50
//          <q.6>  IWDT
//          <i> IWDT clock source enable.
#define CONF_CSC_IWDT_EN                  0x00000040  // 51
//          <q.7>  WWDT
//          <i> WWDT clock source enable.
#define CONF_CSC_WWDT_EN                  0x00000080  // 52
//          <e.8>  I2C0
//          <i> I2C0 clock source enable.
#define CONF_CSC_I2C0_EN                  0x00000100  // 53
//              <o.0>  Select I2C0_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_I2C0_CKS                 0x00000000  // 54
//          </e>
//          <e.9>  I2C1
//          <i> I2C1 clock source enable.
#define CONF_CSC_I2C1_EN                  0x00000200  // 55
//              <o.2>  Select I2C0_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_I2C1_CKS                 0x00000000  // 56
//          </e>
//          <e.12> SPI0
//          <i> SPI0 clock source enable.
#define CONF_CSC_SPI0_EN                  0x00001000  // 57
//              <o.8>  Select SPI0_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_SPI0_CKS                 0x00000000  // 58
//          </e>
//          <e.16> URT0
//          <i> URT0 clock source enable.
#define CONF_CSC_URT0_EN                  0x00010000  // 59
//              <o.16> Select URT0_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_URT0_CKS                 0x00000000  // 60
//          </e>
//          <e.17> URT1
//          <i> URT1 clock source enable.
#define CONF_CSC_URT1_EN                  0x00020000  // 61
//              <o.18> Select URT1_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_URT1_CKS                 0x00000000  // 62
//          </e>
//          <e.18> URT2
//          <i> URT2 clock source enable.
#define CONF_CSC_URT2_EN                  0x00040000  // 63
//              <o.20> Select URT2_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_URT2_CKS                 0x00000000  // 64
//          </e>
//          <e.20> URT4
//          <i> URT4 clock source enable.
#define CONF_CSC_URT4_EN                  0x00100000  // 67
//              <o.24> Select URT4_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_URT4_CKS                 0x00000000  // 68
//          </e>
//          <e.21> URT5
//          <i> URT5 clock source enable.
#define CONF_CSC_URT5_EN                  0x00200000  // 69
//              <o.26> Select URT5_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_URT5_CKS                 0x00000000  // 70
//          </e>
//          <e.22> URT6
//          <i> URT6 clock source enable.
#define CONF_CSC_URT6_EN                  0x00400000  // 71
//              <o.28> Select URT6_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_URT6_CKS                 0x00000000  // 72
//          </e>
//          <e.23> URT7
//          <i> URT7 clock source enable.
#define CONF_CSC_URT7_EN                  0x00800000  // 73
//              <o.30> Select URT7_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_URT7_CKS                 0x00000000  // 74
//          </e>
//          <e.28> USB
//          <i> USB clock source enable.
#define CONF_CSC_USB_EN                   0x10000000  // 75
//              <o.8> Select USB Source <0=> CK_PLL <1=> CK_SYS
//              <i> Process clock source select.
#define CONF_CSC_USB_CKS                  0x00000000  // 76
//          </e>
//          <e.29> APX
//          <i> APX clock source enable.
#define CONF_CSC_APX_EN                   0x20000000  // 77
//              <o.10> Select APX_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_APX_CKS                  0x00000000  // 78
//          </e>
//          <e.0>  TM00
//          <i> TM00 clock source enable.
#define CONF_CSC_TM00_EN                  0x00000001  // 79
//              <o.0>  Select TM00_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_TM00_CKS                 0x00000000  // 80
//          </e>
//          <e.1>  TM01
//          <i> TM01 clock source enable.
#define CONF_CSC_TM01_EN                  0x00000002  // 81
//              <o.2>  Select TM01_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_TM01_CKS                 0x00000000  // 82
//          </e>
//          <e.4>  TM10
//          <i> TM10 clock source enable.
#define CONF_CSC_TM10_EN                  0x00000010  // 83
//              <o.8>  Select TM10_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_TM10_CKS                 0x00000000  // 84
//          </e>
//          <e.7>  TM16
//          <i> TM16 clock source enable.
#define CONF_CSC_TM16_EN                  0x00000080  // 85
//              <o.14> Select TM16_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_TM16_CKS                 0x00000000  // 86
//          </e>
//          <e.8>  TM20
//          <i> TM20 clock source enable.
#define CONF_CSC_TM20_EN                  0x00000100  // 87
//              <o.16> Select TM20_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_TM20_CKS                 0x00000000  // 88
//          </e>
//          <e.11>  TM26
//          <i> TM20 clock source enable.
#define CONF_CSC_TM26_EN                  0x00000800  // 89
//              <o.22> Select TM26_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_TM26_CKS                 0x00000000  // 90
//          </e>
//          <e.15> TM36
//          <i> TM36 clock source enable.
#define CONF_CSC_TM36_EN                  0x00008000  // 91
//              <o.30> Select TM36_PR Source <0=> CK_APB <1=> CK_AHB
//              <i> Process clock source select.
#define CONF_CSC_TM36_CKS                 0x00000000  // 92
//          </e>
//      </h>

//      <h> Configure Peripheral SLEEP Mode Clock
//      <i> Peripheral module process clock enable when MCU is entering SLEEP mode.
//          <q.0>  ADC0
#define CONF_CSC_SLP_ADC0                 0x00000000  // 100
//          <q.2>  CMP
#define CONF_CSC_SLP_CMP                  0x00000000  // 101
//          <q.3>  DAC
#define CONF_CSC_SLP_DAC                  0x00000000  // 102
//          <q.5>  RTC
#define CONF_CSC_SLP_RTC                  0x00000000  // 103
//          <q.6>  IWDT
#define CONF_CSC_SLP_IWDT                 0x00000000  // 104
//          <q.7>  WWDT
#define CONF_CSC_SLP_WWDT                 0x00000000  // 105
//          <q.8>  I2C0
#define CONF_CSC_SLP_I2C0                 0x00000000  // 106
//          <q.9>  I2C1
#define CONF_CSC_SLP_I2C1                 0x00000000  // 107
//          <q.12> SPI0
#define CONF_CSC_SLP_SPI0                 0x00000000  // 108
//          <q.16> URT0
#define CONF_CSC_SLP_URT0                 0x00000000  // 109
//          <q.17> URT1
#define CONF_CSC_SLP_URT1                 0x00000000  // 110
//          <q.18> URT2
#define CONF_CSC_SLP_URT2                 0x00000000  // 111
//          <q.20> URT4
#define CONF_CSC_SLP_URT4                 0x00000000  // 113
//          <q.21> URT5
#define CONF_CSC_SLP_URT5                 0x00000000  // 114
//          <q.22> URT6
#define CONF_CSC_SLP_URT6                 0x00000000  // 115
//          <q.23> URT7
#define CONF_CSC_SLP_URT7                 0x00000000  // 116
//          <q.28> USB
#define CONF_CSC_SLP_USB                  0x00000000  // 117
//          <q.29> APX
#define CONF_CSC_SLP_APX                  0x00000000  // 118
//          <q.0>  TM00
#define CONF_CSC_SLP_TM00                 0x00000000  // 119
//          <q.1>  TM01
#define CONF_CSC_SLP_TM01                 0x00000000  // 120
//          <q.4>  TM10
#define CONF_CSC_SLP_TM10                 0x00000000  // 121
//          <q.7>  TM16
#define CONF_CSC_SLP_TM16                 0x00000000  // 122
//          <q.8>  TM20
#define CONF_CSC_SLP_TM20                 0x00000000  // 123
//          <q.11> TM26
#define CONF_CSC_SLP_TM26                 0x00000000  // 124
//          <q.15> TM36
#define CONF_CSC_SLP_TM36                 0x00000000  // 125
//          <q.24> SRAM
#define CONF_CSC_SLP_SRAM                 0x00000000  // 126
//          <q.25> FLASH
#define CONF_CSC_SLP_FLASH                0x00000000  // 127
//          <q.29> DMA
#define CONF_CSC_SLP_DMA                  0x00000000  // 128
//          <q.30> EMB
#define CONF_CSC_SLP_EMB                  0x00000000  // 129
//      </h>

//      <h> Configure Peripheral STOP Mode Clock
//      <i> Peripheral module process clock enable when MCU is entering STOP mode.
//          <q.5>  RTC
#define CONF_CSC_STP_RTC                  0x00000000  // 140
//          <q.6>  IWDT
#define CONF_CSC_STP_IWDT                 0x00000000  // 141
//      </h>

//      <e.0> Enable ICKO
//      <i> Internal clock source output enable.
#define CONF_CSC_CKO_EN                   0x00000000  // 150
//          <o.2..3> Select ICKO Divider <0=> ICK/1
//                                       <1=> ICK/2
//                                       <2=> ICK/4
//                                       <3=> ICK/8
//          <i> Internal clock output divider select.
#define CONF_CSC_CKO_DIV                  0x00000008  // 151
//          <o.4..7> Select ICKO <0=> CK_MAIN
//                               <1=> CK_AHB
//                               <2=> CK_APB
//                               <3=> CK_HS
//                               <4=> CK_LS
//                               <5=> CK_XOSC
//          <i> Internal clock output source select.
#define CONF_CSC_CKO_SEL                  0x00000000  // 152
//      </e>
//</h>

//*** <<< end of configuration section >>>    ***

// CSC_INT bit 0 ~ 31
#define CONF_CSC_IEA                      0x00000000          // 000, 000
#define CONF_CSC_XOSC_IE                  0x00000000          // 001, 001
#define CONF_CSC_ILRCO_IE                 0x00000000          // 004, 004
#define CONF_CSC_IHRCO_IE                 0x00000000          // 005, 005
#define CONF_CSC_PLL_IE                   0x00000000          // 006, 006
#define CONF_CSC_MCD_IE                   0x00000000          // 007, 007
                                         
#define CONF_CSC_PLL_MDS                  0x00000001 /*MG32_3RD must be retention and value is 0x00000001 */
                                         
#define CONF_CSC_STA              0X00000000
#define CONF_CSC_INT              (CONF_CSC_IEA | CONF_CSC_XOSC_IE | CONF_CSC_ILRCO_IE | CONF_CSC_IHRCO_IE | CONF_CSC_PLL_IE | CONF_CSC_MCD_IE)
#define CONF_CSC_KEY              0x00000000

#define CONF_CSC_PLL              (CONF_CSC_PLL_MDS | CONF_CSC_PLLI_SEL | CONF_CSC_PLL_MUL | (CONF_CSC_PLL_MULX - 0x00000200) | CONF_CSC_XOSC_GN)
#define CONF_CSC_CR0              (CONF_CSC_MCD_DIS | CONF_CSC_LS_SEL | CONF_CSC_HS_SEL | CONF_CSC_HS2_SEL | CONF_CSC_MAIN_SEL | CONF_CSC_ST_SEL | CONF_CSC_IHRCO_SEL | CONF_CSC_MCD_SEL)

#if USB_TYPE == 1   // When there is a USB module.
    #define CONF_CSC_DIV              (CONF_CSC_PLLI_DIV | CONF_CSC_PLLO_DIV | CONF_CSC_AHB_DIV | CONF_CSC_APB_DIV | CONF_CSC_USB_DIV | CONF_CSC_UT_DIV)
#else               // When there is no USB module.
    #define CONF_CSC_DIV              (CONF_CSC_PLLI_DIV | CONF_CSC_PLLO_DIV | CONF_CSC_AHB_DIV | CONF_CSC_APB_DIV | CONF_CSC_UT_DIV)
#endif
#define CONF_CSC_CKO              (CONF_CSC_CKO_EN | CONF_CSC_CKO_DIV | CONF_CSC_CKO_SEL)
#define CONF_CSC_AHB              (CONF_CSC_IOPA_EN | CONF_CSC_IOPB_EN | CONF_CSC_IOPC_EN | CONF_CSC_IOPD_EN | CONF_CSC_IOPE_EN | CONF_CSC_GPL_EN | CONF_CSC_EMB_EN | CONF_CSC_DMA_EN)

#if USB_TYPE == 1   // When there is a USB module.
    #define CONF_CSC_APB0             (CONF_CSC_ADC0_EN | CONF_CSC_CMP_EN | CONF_CSC_DAC_EN | CONF_CSC_RTC_EN | CONF_CSC_IWDT_EN | CONF_CSC_WWDT_EN | CONF_CSC_I2C0_EN | CONF_CSC_I2C1_EN | CONF_CSC_SPI0_EN | CONF_CSC_URT0_EN | CONF_CSC_URT1_EN | CONF_CSC_URT2_EN | CONF_CSC_URT4_EN | CONF_CSC_URT5_EN | CONF_CSC_URT6_EN | CONF_CSC_URT7_EN | CONF_CSC_USB_EN | CONF_CSC_APX_EN)
#else               // When there is no USB module.
    #define CONF_CSC_APB0             (CONF_CSC_ADC0_EN | CONF_CSC_CMP_EN | CONF_CSC_DAC_EN | CONF_CSC_RTC_EN | CONF_CSC_IWDT_EN | CONF_CSC_WWDT_EN | CONF_CSC_I2C0_EN | CONF_CSC_I2C1_EN | CONF_CSC_SPI0_EN | CONF_CSC_URT0_EN | CONF_CSC_URT1_EN | CONF_CSC_URT2_EN | CONF_CSC_URT4_EN | CONF_CSC_URT5_EN | CONF_CSC_URT6_EN | CONF_CSC_URT7_EN | CONF_CSC_APX_EN)
#endif
#define CONF_CSC_APB1             (CONF_CSC_TM00_EN | CONF_CSC_TM01_EN | CONF_CSC_TM10_EN | CONF_CSC_TM16_EN | CONF_CSC_TM20_EN | CONF_CSC_TM26_EN | CONF_CSC_TM36_EN)

#if USB_TYPE == 1   // When there is a USB module.
    #define CONF_CSC_SLP0             (CONF_CSC_SLP_ADC0 | CONF_CSC_SLP_CMP | CONF_CSC_SLP_DAC | CONF_CSC_SLP_RTC | CONF_CSC_SLP_IWDT | CONF_CSC_SLP_WWDT | CONF_CSC_SLP_I2C0 | CONF_CSC_SLP_I2C1 | CONF_CSC_SLP_SPI0 | CONF_CSC_SLP_URT0 | CONF_CSC_SLP_URT1 | CONF_CSC_SLP_URT2 | CONF_CSC_SLP_URT4 | CONF_CSC_SLP_URT5 | CONF_CSC_SLP_URT6 | CONF_CSC_SLP_URT7 | CONF_CSC_SLP_USB | CONF_CSC_SLP_APX)
#else               // When there is no USB module.
    #define CONF_CSC_SLP0             (CONF_CSC_SLP_ADC0 | CONF_CSC_SLP_CMP | CONF_CSC_SLP_DAC | CONF_CSC_SLP_RTC | CONF_CSC_SLP_IWDT | CONF_CSC_SLP_WWDT | CONF_CSC_SLP_I2C0 | CONF_CSC_SLP_I2C1 | CONF_CSC_SLP_SPI0 | CONF_CSC_SLP_URT0 | CONF_CSC_SLP_URT1 | CONF_CSC_SLP_URT2 | CONF_CSC_SLP_URT4 | CONF_CSC_SLP_URT5 | CONF_CSC_SLP_URT6 | CONF_CSC_SLP_URT7 | CONF_CSC_SLP_APX)
#endif
#define CONF_CSC_SLP1             (CONF_CSC_SLP_TM00 | CONF_CSC_SLP_TM01 | CONF_CSC_SLP_TM10 | CONF_CSC_SLP_TM16 | CONF_CSC_SLP_TM20 | CONF_CSC_SLP_TM26 | CONF_CSC_SLP_TM36 | CONF_CSC_SLP_SRAM | CONF_CSC_SLP_FLASH | CONF_CSC_SLP_DMA | CONF_CSC_SLP_EMB )
#define CONF_CSC_STP0             (CONF_CSC_STP_RTC | CONF_CSC_STP_IWDT)
#define CONF_CSC_STP1             0x00000000

#if USB_TYPE == 1   // When there is a USB module.
    #define CONF_CSC_CSK0             (CONF_CSC_ADC0_CKS |  CONF_CSC_CMP_CKS |  CONF_CSC_DAC_CKS | CONF_CSC_USB_CKS | CONF_CSC_APX_CKS)
#else               // When there is no USB module.
    #define CONF_CSC_CSK0             (CONF_CSC_ADC0_CKS |  CONF_CSC_CMP_CKS |  CONF_CSC_DAC_CKS | CONF_CSC_APX_CKS)
#endif
#define CONF_CSC_CSK1             (CONF_CSC_I2C0_CKS | CONF_CSC_I2C1_CKS | CONF_CSC_SPI0_CKS | CONF_CSC_URT0_CKS | CONF_CSC_URT1_CKS | CONF_CSC_URT2_CKS | CONF_CSC_URT4_CKS | CONF_CSC_URT5_CKS | CONF_CSC_URT6_CKS | CONF_CSC_URT7_CKS)
#define CONF_CSC_CSK2             (CONF_CSC_TM00_CKS | CONF_CSC_TM01_CKS | CONF_CSC_TM10_CKS | CONF_CSC_TM16_CKS | CONF_CSC_TM20_CKS | CONF_CSC_TM26_CKS | CONF_CSC_TM36_CKS)

    /* Calculate CK_xxx Frequency */
// CONF_CK_HS_FREQ
#if CONF_CSC_HS_SEL == 0x00000000
    #if CONF_CSC_IHRCO_SEL == 0x00000000
        #define CONF_CK_HS_FREQ   12000000
    #else
        #define CONF_CK_HS_FREQ   11059200
    #endif
#elif CONF_CSC_HS_SEL == 0x00000400
    #define CONF_CK_HS_FREQ   CONF_XOSC_EXTCK_FREQ
#elif CONF_CSC_HS_SEL == 0x00000800
    #define CONF_CK_HS_FREQ   32000
#elif CONF_CSC_HS_SEL == 0x00000C00
    #define CONF_CK_HS_FREQ   CONF_XOSC_EXTCK_FREQ
#endif
// CONF_CK_HS2_FREQ
#if CONF_CSC_HS2_SEL == 0x00000000 
    #if CONF_CSC_IHRCO_SEL == 0x00000000
        #define CONF_CK_HS2_FREQ   12000000
    #else
        #define CONF_CK_HS2_FREQ   11059200
    #endif
#elif CONF_CSC_HS2_SEL == 0x00001000
    #define CONF_CK_HS2_FREQ   CONF_XOSC_EXTCK_FREQ
#elif CONF_CSC_HS2_SEL == 0x00003000 
    #define CONF_CK_HS2_FREQ   CONF_XOSC_EXTCK_FREQ
#endif    

// CONF_PLLI_DIV
#if CONF_CSC_PLLI_DIV == 0x00000000
    #define CONF_PLLI_DIV     1
#elif CONF_CSC_PLLI_DIV == 0x00000001
    #define CONF_PLLI_DIV     2
#elif CONF_CSC_PLLI_DIV == 0x00000002
    #define CONF_PLLI_DIV     4
#elif CONF_CSC_PLLI_DIV == 0x00000003
    #define CONF_PLLI_DIV     6
#endif

// CONF_PLL_MUL
#if CONF_CSC_PLL_MDS == 0
    #if CONF_CSC_PLL_MUL == 0x00000000
        #define CONF_CSC_PLL_MUL_VAL      16
    #else
        #define CONF_CSC_PLL_MUL_VAL      24
    #endif
// When PLL used multiplication X
#else
    #define CONF_CSC_PLL_MUL_VAL  (CONF_CSC_PLL_MULX >> 9)
#endif
// CONF_PLLO_DIV
#if CONF_CSC_PLLO_DIV == 0x00000000
    #define CONF_PLLO_DIV     4
#elif CONF_CSC_PLLO_DIV == 0x00000010
    #define CONF_PLLO_DIV     3
#elif CONF_CSC_PLLO_DIV == 0x00000020
    #define CONF_PLLO_DIV     2
#elif CONF_CSC_PLLO_DIV == 0x00000030
    #define CONF_PLLO_DIV     1
#endif
// CONF_CK_MAIN_FREQ
#if CONF_CSC_MAIN_SEL == 0x00000000
    #define CONF_CK_MAIN_FREQ     CONF_CK_HS_FREQ
// When CK_AMIN = CK_PLLI
#elif CONF_CSC_MAIN_SEL == 0x00004000
    // When CSC_PLLI_SEL == CK_HS
    #if CONF_CSC_PLLI_SEL == 0x00000000
        #define CONF_CK_MAIN_FREQ     CONF_CK_HS_FREQ/CONF_PLLI_DIV
    // When CSC_PLLI_SEL == CK_HS2
    #else
        #define CONF_CK_MAIN_FREQ     CONF_CK_HS2_FREQ/CONF_PLLI_DIV
    #endif

// When CK_MAIN == CK_PLLO 
#elif CONF_CSC_MAIN_SEL == 0x00008000
    // When CSC_PLLI_SEL == CK_HS
    #if CONF_CSC_PLLI_SEL == 0x00000000
        #define CONF_CK_MAIN_FREQ     CONF_CK_HS_FREQ /CONF_PLLI_DIV *CONF_CSC_PLL_MUL_VAL /CONF_PLLO_DIV
    // When CSC_PLLI_SEL == CK_HS2
    #else
        #define CONF_CK_MAIN_FREQ     CONF_CK_HS2_FREQ /CONF_PLLI_DIV *CONF_CSC_PLL_MUL_VAL /CONF_PLLO_DIV
    #endif
#endif

// CONF_CK_APB_FREQ
#if CONF_CSC_APB_DIV == 0x00000000
    #define CONF_CK_APB_FREQ      CONF_CK_MAIN_FREQ /1
#elif CONF_CSC_APB_DIV == 0x00010000
    #define CONF_CK_APB_FREQ      CONF_CK_MAIN_FREQ /2
#elif CONF_CSC_APB_DIV == 0x00020000
    #define CONF_CK_APB_FREQ      CONF_CK_MAIN_FREQ /4
#elif CONF_CSC_APB_DIV == 0x00030000
    #define CONF_CK_APB_FREQ      CONF_CK_MAIN_FREQ /8
#elif CONF_CSC_APB_DIV == 0x00040000
    #define CONF_CK_APB_FREQ      CONF_CK_MAIN_FREQ /16
#endif

// CONF_CK_AHB_FREQ
#if CONF_CSC_AHB_DIV == 0x00000000
    #define CONF_CK_AHB_FREQ      CONF_CK_APB_FREQ /1
#elif CONF_CSC_AHB_DIV == 0x00000100
    #define CONF_CK_AHB_FREQ      CONF_CK_APB_FREQ /2
#elif CONF_CSC_AHB_DIV == 0x00000200
    #define CONF_CK_AHB_FREQ      CONF_CK_APB_FREQ /4
#elif CONF_CSC_AHB_DIV == 0x00000300
    #define CONF_CK_AHB_FREQ      CONF_CK_APB_FREQ /8
#elif CONF_CSC_AHB_DIV == 0x00000400
    #define CONF_CK_AHB_FREQ      CONF_CK_APB_FREQ /16
#elif CONF_CSC_AHB_DIV == 0x00000500
    #define CONF_CK_AHB_FREQ      CONF_CK_APB_FREQ /32
#elif CONF_CSC_AHB_DIV == 0x00000600
    #define CONF_CK_AHB_FREQ      CONF_CK_APB_FREQ /64
#elif CONF_CSC_AHB_DIV == 0x00000700
    #define CONF_CK_AHB_FREQ      CONF_CK_APB_FREQ /128
#elif CONF_CSC_AHB_DIV == 0x00000800
    #define CONF_CK_AHB_FREQ      CONF_CK_APB_FREQ /256
#elif CONF_CSC_AHB_DIV == 0x00000900
    #define CONF_CK_AHB_FREQ      CONF_CK_APB_FREQ /512
#endif

// Flash wait state setting
#if CONF_CK_AHB_FREQ <= 25000000
    #define CONF_FLASH_WAIT_STATE    MEM_CR0_FWAIT_zero_w
#elif CONF_CK_AHB_FREQ <= 50000000
    #define CONF_FLASH_WAIT_STATE    MEM_CR0_FWAIT_one_w
#elif CONF_CK_AHB_FREQ > 50000000
    #define CONF_FLASH_WAIT_STATE    MEM_CR0_FWAIT_two_w
#endif

/**
 ******************************************************************************
 *
 * @struct      CONF_CSC_InitConfig[]
 *              CSC initial configuration array
 *
 ******************************************************************************
 */
static const unsigned int CSC_InitConfig[] =
{
    CONF_CSC_STA,     /* CSC_STA 0 not use */
    CONF_CSC_INT,     /* CSC_INT 1 not use */
    CONF_CSC_PLL,     /* CSC_PLL 2 */
    CONF_CSC_KEY,     /* CSC_KEY 3 not use */
    CONF_CSC_CR0,     /* CSC_CR0 4 */
    CONF_CSC_DIV,     /* CSC_DIV 5 */
    CONF_CSC_CKO,     /* CSC_CKO 6 */
    CONF_CSC_AHB,     /* CSC_AHB 7 */
    CONF_CSC_APB0,    /* CSC_APB0 8 */
    CONF_CSC_APB1,    /* CSC_APB1 9 */
    CONF_CSC_SLP0,    /* CSC_SLP0 10 */
    CONF_CSC_SLP1,    /* CSC_SLP1 11 */
    CONF_CSC_STP0,    /* CSC_STP0 12 */
    CONF_CSC_STP1,    /* CSC_STP1 13 */
    CONF_CSC_CSK0,    /* CSC_CSK0 14 */
    CONF_CSC_CSK1,    /* CSC_CSK1 15 */
    CONF_CSC_CSK2,    /* CSC_CSK2 16 */
    0x000000000,      /* CSC_OTHER 17 . bit0: 0: extern clock, 1: crystal clock */
    CONF_XOSC_EXTCK_FREQ,    /* XOSC_EXTCLK_FREQ 18 */
    CONF_FLASH_WAIT_STATE,   /* CK_APB_FREQ 19 */
};


/**
 * @name    Function announce
 *   
 */
///@{  
void CSC_Init (uint32_t* CSC_CFG);
///@}


#endif  // _MG32x02z_CSC_INIT_H


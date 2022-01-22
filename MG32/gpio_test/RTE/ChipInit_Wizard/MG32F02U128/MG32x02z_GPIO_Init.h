/**
 ******************************************************************************
 *
 * @file        MG32x02z_GPIO_Init.h
 *
 * @brief       This file is used to configure GPIO setting.
 *              Device : MG32F02U128
 *              Package: LQFP80
 *
 * @par         Project
 *              MG32x02z
 * @version     V0.32
 * @date        2021/09/08 14:54 (H File Generated Date)
 * @author      Megawin Software Center
 * @copyright   Copyright (c) 2020 Megawin Technology Co., Ltd.
 *              All rights reserved.
 *
 ******************************************************************************
 * @par         Disclaimer
 *      The Demo software is provided "AS IS"  without any warranty, either
 *      expressed or implied, including, but not limited to, the implied warranties
 *      of merchantability and fitness for a particular purpose.  The author will
 *      not be liable for any special, incidental, consequential or indirect
 *      damages due to loss of data or any other reason.
 *      These statements agree with the world wide and local dictated laws about
 *      authorship and violence against these laws.
 ******************************************************************************
 @if HIDE
 *Modify History:
 *>>
 *--
 *--
 *>>
 *>>
 *
 @endif
 ******************************************************************************
 */

#ifndef _MG32x02z_GPIO_Init_H

#define _MG32x02z_GPIO_Init_H

#include "MG32x02z.h"
#include "MG32x02z_GPIO.h"

// <<< Use Configuration Wizard in Context Menu >>>

#define MG32x02z_PIN0_Mask        0x0001
#define MG32x02z_PIN1_Mask        0x0002
#define MG32x02z_PIN2_Mask        0x0004
#define MG32x02z_PIN3_Mask        0x0008
#define MG32x02z_PIN4_Mask        0x0010
#define MG32x02z_PIN5_Mask        0x0020
#define MG32x02z_PIN6_Mask        0x0040
#define MG32x02z_PIN7_Mask        0x0080
#define MG32x02z_PIN8_Mask        0x0100
#define MG32x02z_PIN9_Mask        0x0200
#define MG32x02z_PIN10_Mask       0x0400
#define MG32x02z_PIN11_Mask       0x0800
#define MG32x02z_PIN12_Mask       0x1000
#define MG32x02z_PIN13_Mask       0x2000
#define MG32x02z_PIN14_Mask       0x4000
#define MG32x02z_PIN15_Mask       0x8000


#define PA_OUT_ADR               GPIOA_Base + 0
#define PA_FLT_ADR               IOMA_Base + 0x40
#define PA0_CR_ADR               IOMA_Base + 4*0
#define PA1_CR_ADR               IOMA_Base + 4*1
#define PA2_CR_ADR               IOMA_Base + 4*2
#define PA3_CR_ADR               IOMA_Base + 4*3
#define PA4_CR_ADR               IOMA_Base + 4*4
#define PA5_CR_ADR               IOMA_Base + 4*5
#define PA6_CR_ADR               IOMA_Base + 4*6
#define PA7_CR_ADR               IOMA_Base + 4*7
#define PA8_CR_ADR               IOMA_Base + 4*8
#define PA9_CR_ADR               IOMA_Base + 4*9
#define PA10_CR_ADR              IOMA_Base + 4*10
#define PA11_CR_ADR              IOMA_Base + 4*11
#define PA12_CR_ADR              IOMA_Base + 4*12
#define PA13_CR_ADR              IOMA_Base + 4*13
#define PA14_CR_ADR              IOMA_Base + 4*14
#define PA15_CR_ADR              IOMA_Base + 4*15

#define PB_OUT_ADR               GPIOB_Base + 0
#define PB_FLT_ADR               IOMB_Base + 0x40
#define PB0_CR_ADR               IOMB_Base + 4*0
#define PB1_CR_ADR               IOMB_Base + 4*1
#define PB2_CR_ADR               IOMB_Base + 4*2
#define PB3_CR_ADR               IOMB_Base + 4*3
#define PB4_CR_ADR               IOMB_Base + 4*4
#define PB5_CR_ADR               IOMB_Base + 4*5
#define PB6_CR_ADR               IOMB_Base + 4*6
#define PB7_CR_ADR               IOMB_Base + 4*7
#define PB8_CR_ADR               IOMB_Base + 4*8
#define PB9_CR_ADR               IOMB_Base + 4*9
#define PB10_CR_ADR              IOMB_Base + 4*10
#define PB11_CR_ADR              IOMB_Base + 4*11
#define PB12_CR_ADR              IOMB_Base + 4*12
#define PB13_CR_ADR              IOMB_Base + 4*13
#define PB14_CR_ADR              IOMB_Base + 4*14
#define PB15_CR_ADR              IOMB_Base + 4*15

#define PC_OUT_ADR               GPIOC_Base + 0
#define PC_FLT_ADR               IOMC_Base + 0x40
#define PC0_CR_ADR               IOMC_Base + 4*0
#define PC1_CR_ADR               IOMC_Base + 4*1
#define PC2_CR_ADR               IOMC_Base + 4*2
#define PC3_CR_ADR               IOMC_Base + 4*3
#define PC4_CR_ADR               IOMC_Base + 4*4
#define PC5_CR_ADR               IOMC_Base + 4*5
#define PC6_CR_ADR               IOMC_Base + 4*6
#define PC7_CR_ADR               IOMC_Base + 4*7
#define PC8_CR_ADR               IOMC_Base + 4*8
#define PC9_CR_ADR               IOMC_Base + 4*9
#define PC10_CR_ADR              IOMC_Base + 4*10
#define PC11_CR_ADR              IOMC_Base + 4*11
#define PC12_CR_ADR              IOMC_Base + 4*12
#define PC13_CR_ADR              IOMC_Base + 4*13
#define PC14_CR_ADR              IOMC_Base + 4*14
#define PC15_CR_ADR              IOMC_Base + 4*15

#define PD_OUT_ADR               GPIOD_Base + 0
#define PD_FLT_ADR               IOMD_Base + 0x40
#define PD0_CR_ADR               IOMD_Base + 4*0
#define PD1_CR_ADR               IOMD_Base + 4*1
#define PD2_CR_ADR               IOMD_Base + 4*2
#define PD3_CR_ADR               IOMD_Base + 4*3
#define PD4_CR_ADR               IOMD_Base + 4*4
#define PD5_CR_ADR               IOMD_Base + 4*5
#define PD6_CR_ADR               IOMD_Base + 4*6
#define PD7_CR_ADR               IOMD_Base + 4*7
#define PD8_CR_ADR               IOMD_Base + 4*8
#define PD9_CR_ADR               IOMD_Base + 4*9
#define PD10_CR_ADR              IOMD_Base + 4*10
#define PD11_CR_ADR              IOMD_Base + 4*11
#define PD12_CR_ADR              IOMD_Base + 4*12
#define PD13_CR_ADR              IOMD_Base + 4*13
#define PD14_CR_ADR              IOMD_Base + 4*14
#define PD15_CR_ADR              IOMD_Base + 4*15

#define PE_OUT_ADR               GPIOE_Base + 0
#define PE_FLT_ADR               IOME_Base + 0x40
#define PE0_CR_ADR               IOME_Base + 4*0
#define PE1_CR_ADR               IOME_Base + 4*1
#define PE2_CR_ADR               IOME_Base + 4*2
#define PE3_CR_ADR               IOME_Base + 4*3
#define PE4_CR_ADR               IOME_Base + 4*4
#define PE5_CR_ADR               IOME_Base + 4*5
#define PE6_CR_ADR               IOME_Base + 4*6
#define PE7_CR_ADR               IOME_Base + 4*7
#define PE8_CR_ADR               IOME_Base + 4*8
#define PE9_CR_ADR               IOME_Base + 4*9
#define PE10_CR_ADR              IOME_Base + 4*10
#define PE11_CR_ADR              IOME_Base + 4*11
#define PE12_CR_ADR              IOME_Base + 4*12
#define PE13_CR_ADR              IOME_Base + 4*13
#define PE14_CR_ADR              IOME_Base + 4*14
#define PE15_CR_ADR              IOME_Base + 4*15

/**
 ******************************************************************************
 *
 * @brief       GPIO Initial Configure - MG32F02U128 (LQFP80-Package)
 *
 ******************************************************************************
 */
//<h> GPIO Initial Configure - MG32F02U128 (LQFP80-Package)

//
//==============================  PA IO Setting  ===============================
//
//  <e0> GPIOA Configuration
//      <o1> PA Output setting<0x0000-0xFFFF>
//          <i> GPIO PA output data bit 0~15. These bits are mapping to PA0 ~ PA15.
//      <o2> PA Input filter clock source select <0=> CLK_AHB <1=> CLK_AHB_DIV8 <2=> CLK_ILRCO <3=> TM00_TRGO <4=> CK_UT
//          <i> PA port input deglitch filter clock source select for all pins of the port.
//          <i> Default: FCKS = CLK_AHB
//      <e3.0> PA0 Configuration
//          <o4.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o4.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o4.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o4.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o4.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o4.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o4.12..15>     AFS : Alternate function select             <0=> GPA0 <6=> SDT_P0 <7=> CCL_P0 <8=> MA0 <9=> MAD0 <10=> TM36_OC00 <11=> URT4_TX
//          <i> Default: AFS = GPA0
//      </e> 
//      <e3.1> PA1 Configuration
//          <o5.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o5.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o5.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o5.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o5.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o5.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o5.12..15>     AFS : Alternate function select             <0=> GPA1 <7=> CCL_P1 <8=> MA1 <9=> MAD1 <10=> TM36_OC10 <11=> URT4_RX
//          <i> Default: AFS = GPA1
//      </e> 
//      <e3.2> PA2 Configuration
//          <o6.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o6.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o6.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o6.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o6.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o6.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o6.12..15>     AFS : Alternate function select             <0=> GPA2 <6=> SDT_I0 <8=> MA2 <9=> MAD2 <10=> TM36_OC2 <11=> URT5_TX
//          <i> Default: AFS = GPA2
//      </e> 
//      <e3.3> PA3 Configuration
//          <o7.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o7.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o7.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o7.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o7.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o7.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o7.12..15>     AFS : Alternate function select             <0=> GPA3 <6=> SDT_I1 <8=> MA3 <9=> MAD3 <10=> TM36_OC2N <11=> URT5_RX
//          <i> Default: AFS = GPA3
//      </e> 
//      <e3.4> PA4 Configuration
//          <o8.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o8.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o8.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o8.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o8.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o8.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o8.12..15>     AFS : Alternate function select             <0=> GPA4 <8=> MA4 <9=> MAD4 <10=> TM20_OC00 <11=> URT0_TX
//          <i> Default: AFS = GPA4
//      </e> 
//      <e3.5> PA5 Configuration
//          <o9.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o9.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o9.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o9.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o9.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o9.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o9.12..15>     AFS : Alternate function select             <0=> GPA5 <8=> MA5 <9=> MAD5 <10=> TM20_OC10 <11=> URT0_RX
//          <i> Default: AFS = GPA5
//      </e> 
//      <e3.6> PA6 Configuration
//          <o10.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o10.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o10.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o10.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o10.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o10.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o10.12..15>    AFS : Alternate function select             <0=> GPA6 <7=> SPI0_D3 <8=> MA6 <9=> MAD6 <10=> TM20_OC0H <11=> URT0_CLK
//          <i> Default: AFS = GPA6
//      </e> 
//      <e3.7> PA7 Configuration
//          <o11.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o11.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o11.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o11.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o11.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o11.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o11.12..15>    AFS : Alternate function select             <0=> GPA7 <7=> SPI0_D2 <8=> MA7 <9=> MAD7 <10=> TM20_OC1H <11=> URT0_NSS
//          <i> Default: AFS = GPA7
//      </e> 
//      <e3.8> PA8 Configuration
//          <o12.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o12.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o12.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o12.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o12.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o12.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o12.12..15>    AFS : Alternate function select             <0=> GPA8 <1=> DMA_TRG0 <3=> I2C0_SCL <4=> URT2_BRO <5=> SDT_I0 <6=> TM20_IC0 <7=> SPI0_NSS <8=> MA8 <9=> MAD0 <10=> TM36_OC0H <11=> URT4_TX
//          <i> Default: AFS = GPA8
//      </e> 
//      <e3.9> PA9 Configuration
//          <o13.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o13.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o13.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o13.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o13.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o13.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o13.12..15>    AFS : Alternate function select             <0=> GPA9 <1=> DMA_TRG1 <3=> I2C1_SCL <4=> URT2_TMO <6=> TM20_IC1 <7=> SPI0_MISO <8=> MA9 <9=> MAD1 <10=> TM36_OC1H <11=> URT5_TX
//          <i> Default: AFS = GPA9
//      </e> 
//      <e3.10> PA10 Configuration
//          <o14.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o14.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o14.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o14.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o14.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o14.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o14.12..15>    AFS : Alternate function select             <0=> GPA10 <1=> TM36_BK0 <2=> SPI0_D2 <3=> I2C0_SDA <4=> URT2_CTS <5=> SDT_I1 <6=> TM26_IC0 <7=> SPI0_CLK <8=> MA10 <9=> MAD2 <10=> TM36_OC2H <11=> URT4_RX
//          <i> Default: AFS = GPA10
//      </e> 
//      <e3.11> PA11 Configuration
//          <o15.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o15.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o15.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o15.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o15.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o15.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o15.12..15>    AFS : Alternate function select             <0=> GPA11 <1=> DAC_TRG0 <2=> SPI0_D3 <3=> I2C1_SDA <4=> URT2_RTS <6=> TM26_IC1 <7=> SPI0_MOSI <8=> MA11 <9=> MAD3 <10=> TM36_OC3H <11=> URT5_RX
//          <i> Default: AFS = GPA11
//      </e> 
//      <e3.12> PA12 Configuration
//          <o16.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o16.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o16.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o16.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o16.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o16.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o16.12..15>    AFS : Alternate function select             <0=> GPA12 <2=> USB_S0 <4=> URT1_BRO <5=> TM10_ETR <6=> TM36_IC0 <7=> SPI0_D5 <8=> MA12 <9=> MAD4 <10=> TM26_OC00 <11=> URT6_TX
//          <i> Default: AFS = GPA12
//      </e> 
//      <e3.13> PA13 Configuration
//          <o17.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o17.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o17.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o17.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o17.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o17.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o17.12..15>    AFS : Alternate function select             <0=> GPA13 <1=> CPU_TXEV <2=> USB_S1 <3=> URT0_BRO <4=> URT1_TMO <5=> TM10_TRGO <6=> TM36_IC1 <7=> SPI0_D6 <8=> MA13 <9=> MAD5 <10=> TM26_OC10 <11=> URT6_RX
//          <i> Default: AFS = GPA13
//      </e> 
//      <e3.14> PA14 Configuration
//          <o18.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o18.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o18.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o18.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o18.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o18.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o18.12..15>    AFS : Alternate function select             <0=> GPA14 <1=> CPU_RXEV <2=> OBM_I0 <3=> URT0_TMO <4=> URT1_CTS <5=> TM16_ETR <6=> TM36_IC2 <7=> SPI0_D7 <8=> MA14 <9=> MAD6 <10=> TM26_OC0H <11=> URT7_TX
//          <i> Default: AFS = GPA14
//      </e> 
//      <e3.15> PA15 Configuration
//          <o19.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o19.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o19.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o19.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o19.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o19.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o19.12..15>    AFS : Alternate function select             <0=> GPA15 <1=> CPU_NMI <2=> OBM_I1 <3=> URT0_DE <4=> URT1_RTS <5=> TM16_TRGO <6=> TM36_IC3 <7=> SPI0_D4 <8=> MA15 <9=> MAD7 <10=> TM26_OC1H <11=> URT7_RX
//          <i> Default: AFS = GPA15
//      </e> 
        #define CONF_GPIOAInit_EN           0
        #define CONF_PA_OUTPUT_DEFAULT      0xFFFF
        #define CONF_PA_FILTER_CLK          0
        #define CONF_GPIOAInit_Mask         0x0000
        #define CONF_PA0_CR                 0x00000000
        #define CONF_PA1_CR                 0x00000000
        #define CONF_PA2_CR                 0x00000000
        #define CONF_PA3_CR                 0x00000000
        #define CONF_PA4_CR                 0x00000000
        #define CONF_PA5_CR                 0x00000000
        #define CONF_PA6_CR                 0x00000000
        #define CONF_PA7_CR                 0x00000000
        #define CONF_PA8_CR                 0x00000000
        #define CONF_PA9_CR                 0x00000000
        #define CONF_PA10_CR                0x00000000
        #define CONF_PA11_CR                0x00000000
        #define CONF_PA12_CR                0x00000000
        #define CONF_PA13_CR                0x00000000
        #define CONF_PA14_CR                0x00000000
        #define CONF_PA15_CR                0x00000000
//  </e> 

//
//==============================  PB IO Setting  ===============================
//
//  <e0> GPIOB Configuration
//      <o1> PB Output setting<0x0000-0xFFFF>
//          <i> GPIO PB output data bit 0~15. These bits are mapping to PB0 ~ PB15.
//      <o2> PB Input filter clock source select <0=> CLK_AHB <1=> CLK_AHB_DIV8 <2=> CLK_ILRCO <3=> TM00_TRGO <4=> CK_UT
//          <i> PB port input deglitch filter clock source select for all pins of the port.
//          <i> Default: FCKS = CLK_AHB
//      <e3.0> PB0 Configuration
//          <o4.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o4.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o4.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o4.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o4.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o4.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o4.12..15>     AFS : Alternate function select             <0=> GPB0 <1=> I2C1_SCL <2=> SPI0_NSS <3=> TM01_ETR <4=> TM00_CKO <5=> TM16_ETR <6=> TM26_IC0 <7=> TM36_ETR <8=> MA15 <9=> URT1_NSS <10=> URT2_NSS <11=> URT6_TX
//          <i> Default: AFS = GPB0
//      </e> 
//      <e3.1> PB1 Configuration
//          <o5.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o5.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o5.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o5.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o5.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o5.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o5.12..15>     AFS : Alternate function select             <0=> GPB1 <1=> I2C1_SDA <2=> SPI0_MISO <3=> TM01_TRGO <4=> TM10_CKO <5=> TM16_TRGO <6=> TM26_IC1 <7=> TM36_TRGO <9=> URT1_RX <10=> URT2_CLK <11=> URT6_RX
//          <i> Default: AFS = GPB1
//      </e> 
//      <e3.2> PB2 Configuration
//          <o6.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o6.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o6.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o6.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o6.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o6.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o6.12..15>     AFS : Alternate function select             <0=> GPB2 <1=> ADC0_TRG <2=> SPI0_CLK <3=> TM01_CKO <4=> URT2_TX <5=> TM16_CKO <6=> TM26_OC0H <7=> I2C0_SDA <9=> URT1_CLK <10=> URT0_TX <11=> URT7_TX
//          <i> Default: AFS = GPB2
//      </e> 
//      <e3.3> PB3 Configuration
//          <o7.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o7.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o7.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o7.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o7.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o7.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o7.12..15>     AFS : Alternate function select             <0=> GPB3 <1=> ADC0_OUT <2=> SPI0_MOSI <3=> NCO_P0 <4=> URT2_RX <5=> TM36_CKO <6=> TM26_OC1H <7=> I2C0_SCL <9=> URT1_TX <10=> URT0_RX <11=> URT7_RX
//          <i> Default: AFS = GPB3
//      </e> 
//      <e3.4> PB4 Configuration
//          <o8.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o8.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o8.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o8.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o8.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o8.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o8.12..15>     AFS : Alternate function select             <0=> GPB4 <1=> TM01_CKO <2=> SPI0_D3 <3=> TM26_TRGO <4=> URT2_CLK <5=> TM20_IC0 <6=> TM36_IC0 <8=> MALE <9=> MAD8
//          <i> Default: AFS = GPB4
//      </e> 
//      <e3.5> PB5 Configuration
//          <o9.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o9.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o9.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o9.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o9.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o9.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o9.12..15>     AFS : Alternate function select             <0=> GPB5 <1=> TM16_CKO <2=> SPI0_D2 <3=> TM26_ETR <4=> URT2_NSS <5=> TM20_IC1 <6=> TM36_IC1 <8=> MOE <9=> MAD9
//          <i> Default: AFS = GPB5
//      </e> 
//      <e3.6> PB6 Configuration
//          <o10.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o10.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o10.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o10.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o10.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o10.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o10.12..15>    AFS : Alternate function select             <0=> GPB6 <1=> CPU_RXEV <2=> SPI0_NSSI <3=> URT0_BRO <4=> URT2_CTS <5=> TM20_ETR <6=> TM36_IC2 <8=> MWE <9=> MAD10 <11=> URT2_TX
//          <i> Default: AFS = GPB6
//      </e> 
//      <e3.7> PB7 Configuration
//          <o11.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o11.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o11.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o11.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o11.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o11.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o11.12..15>    AFS : Alternate function select             <0=> GPB7 <1=> CPU_TXEV <3=> URT0_TMO <4=> URT2_RTS <5=> TM20_TRGO <6=> TM36_IC3 <8=> MCE <9=> MALE2 <11=> URT2_RX
//          <i> Default: AFS = GPB7
//      </e> 
//      <e3.8> PB8 Configuration
//          <o12.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o12.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o12.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o12.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o12.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o12.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o12.12..15>    AFS : Alternate function select             <0=> GPB8 <1=> CMP0_P0 <2=> RTC_OUT <3=> URT0_TX <4=> URT2_BRO <5=> TM20_OC01 <6=> TM36_OC01 <7=> SPI0_D3 <8=> MAD0 <9=> SDT_P0 <10=> OBM_P0 <11=> URT4_TX
//          <i> Default: AFS = GPB8
//      </e> 
//      <e3.9> PB9 Configuration
//          <o13.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o13.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o13.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o13.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o13.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o13.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o13.12..15>    AFS : Alternate function select             <0=> GPB9 <1=> CMP1_P0 <2=> RTC_TS <3=> URT0_RX <4=> URT2_TMO <5=> TM20_OC02 <6=> TM36_OC02 <7=> SPI0_D2 <8=> MAD1 <9=> MAD8 <10=> OBM_P1 <11=> URT4_RX
//          <i> Default: AFS = GPB9
//      </e> 
//      <e3.10> PB10 Configuration
//          <o14.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o14.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o14.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o14.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o14.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o14.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o14.12..15>    AFS : Alternate function select             <0=> GPB10 <2=> I2C0_SCL <3=> URT0_NSS <4=> URT2_DE <5=> TM20_OC11 <6=> TM36_OC11 <7=> URT1_TX <8=> MAD2 <9=> MAD1 <10=> SPI0_NSSI
//          <i> Default: AFS = GPB10
//      </e> 
//      <e3.11> PB11 Configuration
//          <o15.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o15.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o15.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o15.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o15.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o15.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o15.12..15>    AFS : Alternate function select             <0=> GPB11 <2=> I2C0_SDA <3=> URT0_DE <4=> IR_OUT <5=> TM20_OC12 <6=> TM36_OC12 <7=> URT1_RX <8=> MAD3 <9=> MAD9 <10=> DMA_TRG0 <11=> URT0_CLK
//          <i> Default: AFS = GPB11
//      </e> 
//      <e3.12> PB12 Configuration
//          <o16.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o16.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o16.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o16.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o16.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o16.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o16.12..15>    AFS : Alternate function select             <0=> GPB12 <1=> DMA_TRG0 <2=> NCO_P0 <3=> USB_S0 <7=> URT1_CLK <8=> MAD4 <9=> MAD2 <11=> URT5_TX
//          <i> Default: AFS = GPB12
//      </e> 
//      <e3.13> PB13 Configuration
//          <o17.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o17.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o17.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o17.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o17.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o17.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o17.12..15>    AFS : Alternate function select             <0=> GPB13 <1=> DAC_TRG0 <2=> TM00_ETR <3=> URT0_CTS <5=> TM20_ETR <6=> TM36_ETR <7=> URT0_CLK <8=> MAD5 <9=> MAD10 <10=> CCL_P0 <11=> URT4_RX
//          <i> Default: AFS = GPB13
//      </e> 
//      <e3.14> PB14 Configuration
//          <o18.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o18.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o18.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o18.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o18.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o18.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o18.12..15>    AFS : Alternate function select             <0=> GPB14 <1=> DMA_TRG0 <2=> TM00_TRGO <3=> URT0_RTS <5=> TM20_TRGO <6=> TM36_BK0 <7=> URT0_NSS <8=> MAD6 <9=> MAD3 <10=> CCL_P1 <11=> URT4_TX
//          <i> Default: AFS = GPB14
//      </e> 
//      <e3.15> PB15 Configuration
//          <o19.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o19.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o19.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o19.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o19.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o19.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o19.12..15>    AFS : Alternate function select             <0=> GPB15 <1=> IR_OUT <2=> NCO_CK0 <3=> USB_S1 <7=> URT1_NSS <8=> MAD7 <9=> MAD11 <11=> URT5_RX
//          <i> Default: AFS = GPB15
//      </e> 
        #define CONF_GPIOBInit_EN           0
        #define CONF_PB_OUTPUT_DEFAULT      0xFFFF
        #define CONF_PB_FILTER_CLK          0
        #define CONF_GPIOBInit_Mask         0x0000
        #define CONF_PB0_CR                 0x00000000
        #define CONF_PB1_CR                 0x00000000
        #define CONF_PB2_CR                 0x00000000
        #define CONF_PB3_CR                 0x00000000
        #define CONF_PB4_CR                 0x00000000
        #define CONF_PB5_CR                 0x00000000
        #define CONF_PB6_CR                 0x00000000
        #define CONF_PB7_CR                 0x00000000
        #define CONF_PB8_CR                 0x00000000
        #define CONF_PB9_CR                 0x00000000
        #define CONF_PB10_CR                0x00000000
        #define CONF_PB11_CR                0x00000000
        #define CONF_PB12_CR                0x00000000
        #define CONF_PB13_CR                0x00000000
        #define CONF_PB14_CR                0x00000000
        #define CONF_PB15_CR                0x00000000
//  </e> 

//
//==============================  PC IO Setting  ===============================
//
//  <e0> GPIOC Configuration
//      <o1> PC Output setting<0x0000-0xFFFF>
//          <i> GPIO PC output data bit 0~15. These bits are mapping to PC0 ~ PC15.
//      <o2> PC Input filter clock source select <0=> CLK_AHB <1=> CLK_AHB_DIV8 <2=> CLK_ILRCO <3=> TM00_TRGO <4=> CK_UT
//          <i> PC port input deglitch filter clock source select for all pins of the port.
//          <i> Default: FCKS = CLK_AHB
//      <e3.0> PC0 Configuration
//          <o4.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o4.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o4.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o4.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o4.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o4.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o4.12..15>     AFS : Alternate function select             <0=> GPC0 <1=> ICKO <2=> TM00_CKO <3=> URT0_CLK <4=> URT2_CLK <5=> TM20_OC00 <6=> TM36_OC00 <7=> I2C0_SCL <8=> MCLK <9=> MWE <10=> URT0_TX <11=> URT5_TX
//          <i> Default: AFS = GPC0
//      </e> 
//      <e3.1> PC1 Configuration
//          <o5.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o5.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o5.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o5.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o5.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o5.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o5.12..15>     AFS : Alternate function select             <0=> GPC1 <1=> ADC0_TRG <2=> TM01_CKO <3=> TM36_IC0 <4=> URT1_CLK <5=> TM20_OC0N <6=> TM36_OC0N <7=> I2C0_SDA <8=> MAD8 <9=> MAD4 <10=> URT0_RX <11=> URT5_RX
//          <i> Default: AFS = GPC1
//      </e> 
//      <e3.2> PC2 Configuration
//          <o6.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o6.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o6.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o6.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o6.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o6.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o6.12..15>     AFS : Alternate function select             <0=> GPC2 <1=> ADC0_OUT <2=> TM10_CKO <3=> OBM_P0 <4=> URT2_CLK <5=> TM20_OC10 <6=> TM36_OC10 <7=> SDT_I0 <8=> MAD9 <9=> MAD12
//          <i> Default: AFS = GPC2
//      </e> 
//      <e3.3> PC3 Configuration
//          <o7.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o7.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o7.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o7.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o7.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o7.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o7.12..15>     AFS : Alternate function select             <0=> GPC3 <1=> OBM_P1 <2=> TM16_CKO <3=> URT0_CLK <4=> URT1_CLK <5=> TM20_OC1N <6=> TM36_OC1N <7=> SDT_I1 <8=> MAD10 <9=> MAD5
//          <i> Default: AFS = GPC3
//      </e> 
//      <e3.4> PC4 Configuration
//          <o8.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = QB
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o8.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o8.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = ENABLE
//          <o8.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o8.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o8.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o8.12..15>     AFS : Alternate function select             <0=> GPC4 <1=> SWCLK <2=> I2C0_SCL <3=> URT0_RX <4=> URT1_RX <6=> TM36_OC2 <7=> SDT_I0 <11=> URT6_RX
//          <i> Default: AFS = GPC4
//      </e> 
//      <e3.5> PC5 Configuration
//          <o9.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = QB
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o9.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o9.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = ENABLE
//          <o9.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o9.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o9.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o9.12..15>     AFS : Alternate function select             <0=> GPC5 <1=> SWDIO <2=> I2C0_SDA <3=> URT0_TX <4=> URT1_TX <6=> TM36_OC3 <7=> SDT_I1 <11=> URT6_TX
//          <i> Default: AFS = GPC5
//      </e> 
//      <e3.6> PC6 Configuration
//          <o10.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = QB
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o10.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o10.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = ENABLE
//          <o10.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o10.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o10.12..15>    AFS : Alternate function select             <0=> GPC6 <1=> RSTN <2=> RTC_TS <3=> URT0_NSS <4=> URT1_NSS <5=> TM20_ETR <6=> TM26_ETR <8=> MBW1 <9=> MALE
//          <i> Default: AFS = GPC6
//      </e> 
//      <e3.7> PC7 Configuration
//          <o11.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o11.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o11.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o11.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o11.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o11.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o11.12..15>    AFS : Alternate function select             <0=> GPC7 <1=> ADC0_TRG <2=> RTC_OUT <3=> URT0_DE <4=> URT1_NSS <6=> TM36_TRGO <8=> MBW0 <9=> MCE
//          <i> Default: AFS = GPC7
//      </e> 
//      <e3.8> PC8 Configuration
//          <o12.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o12.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o12.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o12.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o12.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o12.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o12.12..15>    AFS : Alternate function select             <0=> GPC8 <1=> ADC0_OUT <2=> I2C0_SCL <3=> URT0_BRO <4=> URT1_TX <5=> TM20_OC0H <6=> TM36_OC0H <7=> TM36_OC0N <8=> MAD11 <9=> MAD13 <10=> CCL_P0 <11=> URT6_TX
//          <i> Default: AFS = GPC8
//      </e> 
//      <e3.9> PC9 Configuration
//          <o13.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o13.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o13.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o13.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o13.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o13.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o13.12..15>    AFS : Alternate function select             <0=> GPC9 <1=> CMP0_P0 <2=> I2C0_SDA <3=> URT0_TMO <4=> URT1_RX <5=> TM20_OC1H <6=> TM36_OC1H <7=> TM36_OC1N <8=> MAD12 <9=> MAD6 <10=> CCL_P1 <11=> URT6_RX
//          <i> Default: AFS = GPC9
//      </e> 
//      <e3.10> PC10 Configuration
//          <o14.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o14.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o14.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o14.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o14.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o14.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o14.12..15>    AFS : Alternate function select             <0=> GPC10 <1=> CMP1_P0 <2=> I2C1_SCL <3=> URT0_TX <4=> URT2_TX <5=> URT1_TX <6=> TM36_OC2H <7=> TM36_OC2N <8=> MAD13 <9=> MAD14 <11=> URT7_TX
//          <i> Default: AFS = GPC10
//      </e> 
//      <e3.11> PC11 Configuration
//          <o15.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o15.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o15.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o15.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o15.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o15.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o15.12..15>    AFS : Alternate function select             <0=> GPC11 <2=> I2C1_SDA <3=> URT0_RX <4=> URT2_RX <5=> URT1_RX <6=> TM36_OC3H <7=> TM26_OC01 <8=> MAD14 <9=> MAD7 <11=> URT7_RX
//          <i> Default: AFS = GPC11
//      </e> 
//      <e3.12> PC12 Configuration
//          <o16.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o16.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o16.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o16.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o16.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o16.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o16.12..15>    AFS : Alternate function select             <0=> GPC12 <2=> IR_OUT <3=> DAC_TRG0 <4=> URT1_DE <5=> TM10_TRGO <6=> TM36_OC3 <7=> TM26_OC02 <8=> MAD15 <9=> SDT_P0 <10=> URT1_CLK <11=> MAM1
//          <i> Default: AFS = GPC12
//      </e> 
//      <e3.13> PC13 Configuration
//          <o17.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o17.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o17.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o17.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o17.12..15>    AFS : Alternate function select             <0=> GPC13 <1=> XIN <2=> URT1_NSS <3=> URT0_CTS <4=> URT2_RX <5=> TM10_ETR <6=> TM26_ETR <7=> TM36_OC00 <8=> TM20_IC0 <9=> SDT_I0 <11=> URT6_RX
//          <i> Default: AFS = GPC13
//      </e> 
//      <e3.14> PC14 Configuration
//          <o18.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN <4=> QB
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//             <i> [4] QB : Quasi-Bidirectional output drive high one CLK
//          <o18.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o18.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o18.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o18.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o18.12..15>    AFS : Alternate function select             <0=> GPC14 <1=> XOUT <2=> URT1_TMO <3=> URT0_RTS <4=> URT2_TX <5=> TM10_CKO <6=> TM26_TRGO <7=> TM36_OC10 <8=> TM20_IC1 <9=> SDT_I1 <11=> URT6_TX
//          <i> Default: AFS = GPC14
//      </e> 
        #define CONF_GPIOCInit_EN           0
        #define CONF_PC_OUTPUT_DEFAULT      0x7FFF
        #define CONF_PC_FILTER_CLK          0
        #define CONF_GPIOCInit_Mask         0x0000
        #define CONF_PC0_CR                 0x00000000
        #define CONF_PC1_CR                 0x00000000
        #define CONF_PC2_CR                 0x00000000
        #define CONF_PC3_CR                 0x00000000
        #define CONF_PC4_CR                 0x80000024
        #define CONF_PC5_CR                 0x80000024
        #define CONF_PC6_CR                 0x80000024
        #define CONF_PC7_CR                 0x00000000
        #define CONF_PC8_CR                 0x00000000
        #define CONF_PC9_CR                 0x00000000
        #define CONF_PC10_CR                0x00000000
        #define CONF_PC11_CR                0x00000000
        #define CONF_PC12_CR                0x00000000
        #define CONF_PC13_CR                0x00000000
        #define CONF_PC14_CR                0x00000000
        #define CONF_PC15_CR                0x00000000
//  </e> 

//
//==============================  PD IO Setting  ===============================
//
//  <e0> GPIOD Configuration
//      <o1> PD Output setting<0x0000-0xFFFF>
//          <i> GPIO PD output data bit 0~15. These bits are mapping to PD0 ~ PD15.
//      <o2> PD Input filter clock source select <0=> CLK_AHB <1=> CLK_AHB_DIV8 <2=> CLK_ILRCO <3=> TM00_TRGO <4=> CK_UT
//          <i> PD port input deglitch filter clock source select for all pins of the port.
//          <i> Default: FCKS = CLK_AHB
//      <e3.0> PD0 Configuration
//          <o4.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o4.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o4.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o4.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o4.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o4.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o4.12..15>     AFS : Alternate function select             <0=> GPD0 <1=> OBM_I0 <2=> TM10_CKO <3=> URT0_CLK <4=> TM26_OC1N <5=> TM20_CKO <6=> TM36_OC2 <7=> SPI0_NSS <8=> MA0 <9=> MCLK <11=> URT2_NSS
//          <i> Default: AFS = GPD0
//      </e> 
//      <e3.1> PD1 Configuration
//          <o5.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o5.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o5.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o5.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o5.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o5.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o5.12..15>     AFS : Alternate function select             <0=> GPD1 <1=> OBM_I1 <2=> TM16_CKO <3=> URT0_CLK <4=> NCO_CK0 <5=> TM26_CKO <6=> TM36_OC2N <7=> SPI0_CLK <8=> MA1 <11=> URT2_CLK
//          <i> Default: AFS = GPD1
//      </e> 
//      <e3.2> PD2 Configuration
//          <o6.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o6.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o6.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o6.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o6.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o6.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o6.12..15>     AFS : Alternate function select             <0=> GPD2 <1=> USB_S0 <2=> TM00_CKO <3=> URT1_CLK <4=> TM26_OC00 <5=> TM20_CKO <6=> TM36_CKO <7=> SPI0_MOSI <8=> MA2 <9=> MAD4 <11=> URT2_TX
//          <i> Default: AFS = GPD2
//      </e> 
//      <e3.3> PD3 Configuration
//          <o7.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o7.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o7.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o7.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o7.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o7.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o7.12..15>     AFS : Alternate function select             <0=> GPD3 <1=> USB_S1 <2=> TM01_CKO <3=> URT1_CLK <5=> SPI0_MISO <6=> TM26_CKO <7=> SPI0_D3 <8=> MA3 <9=> MAD7 <10=> TM36_TRGO <11=> URT2_RX
//          <i> Default: AFS = GPD3
//      </e> 
//      <e3.4> PD4 Configuration
//          <o8.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o8.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o8.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o8.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o8.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o8.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o8.12..15>     AFS : Alternate function select             <0=> GPD4 <1=> TM00_TRGO <2=> TM01_TRGO <3=> URT1_TX <6=> TM26_OC00 <7=> SPI0_D2 <8=> MA4 <9=> MAD6 <11=> URT2_TX
//          <i> Default: AFS = GPD4
//      </e> 
//      <e3.5> PD5 Configuration
//          <o9.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o9.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o9.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o9.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o9.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o9.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o9.12..15>     AFS : Alternate function select             <0=> GPD5 <1=> TM00_ETR <2=> I2C0_SCL <3=> URT1_RX <6=> TM26_OC01 <7=> SPI0_MISO <8=> MA5 <9=> MAD5 <11=> URT2_RX
//          <i> Default: AFS = GPD5
//      </e> 
//      <e3.6> PD6 Configuration
//          <o10.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o10.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o10.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o10.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o10.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o10.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o10.12..15>    AFS : Alternate function select             <0=> GPD6 <1=> CPU_NMI <2=> I2C0_SDA <3=> URT1_NSS <5=> SPI0_NSSI <6=> TM26_OC02 <7=> SPI0_NSS <8=> MA6 <9=> SDT_P0 <11=> URT2_NSS
//          <i> Default: AFS = GPD6
//      </e> 
//      <e3.7> PD7 Configuration
//          <o11.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o11.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o11.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o11.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o11.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o11.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o11.12..15>    AFS : Alternate function select             <0=> GPD7 <1=> TM00_CKO <2=> TM01_ETR <3=> URT1_DE <5=> SPI0_MISO <6=> TM26_OC0N <7=> SPI0_D4 <8=> MA7 <9=> MAD0 <10=> TM36_IC0
//          <i> Default: AFS = GPD7
//      </e> 
//      <e3.8> PD8 Configuration
//          <o12.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o12.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o12.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o12.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o12.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o12.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o12.12..15>    AFS : Alternate function select             <0=> GPD8 <1=> CPU_TXEV <2=> TM01_TRGO <3=> URT1_RTS <5=> SPI0_D2 <6=> TM26_OC10 <7=> SPI0_D7 <8=> MA8 <9=> MAD3 <10=> TM36_IC1 <11=> SPI0_CLK
//          <i> Default: AFS = GPD8
//      </e> 
//      <e3.9> PD9 Configuration
//          <o13.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o13.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o13.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o13.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o13.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o13.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o13.12..15>    AFS : Alternate function select             <0=> GPD9 <1=> CPU_RXEV <2=> TM00_TRGO <3=> URT1_CTS <5=> SPI0_NSSI <6=> TM26_OC11 <7=> SPI0_D6 <8=> MA9 <9=> MAD2 <10=> TM36_IC2 <11=> SPI0_NSS
//          <i> Default: AFS = GPD9
//      </e> 
//      <e3.10> PD10 Configuration
//          <o14.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o14.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o14.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o14.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o14.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o14.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o14.12..15>    AFS : Alternate function select             <0=> GPD10 <1=> CPU_NMI <2=> TM00_ETR <3=> URT1_BRO <5=> RTC_OUT <6=> TM26_OC12 <7=> SPI0_D5 <8=> MA10 <9=> MAD1 <10=> TM36_IC3 <11=> SPI0_MOSI
//          <i> Default: AFS = GPD10
//      </e> 
//      <e3.11> PD11 Configuration
//          <o15.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o15.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o15.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o15.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o15.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o15.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o15.12..15>    AFS : Alternate function select             <0=> GPD11 <1=> CPU_NMI <2=> DMA_TRG1 <3=> URT1_TMO <5=> SPI0_D3 <6=> TM26_OC1N <7=> SPI0_NSS <8=> MA11 <9=> MWE
//          <i> Default: AFS = GPD11
//      </e> 
//      <e3.12> PD12 Configuration
//          <o16.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o16.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o16.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o16.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o16.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o16.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o16.12..15>    AFS : Alternate function select             <0=> GPD12 <1=> CMP0_P0 <2=> TM10_CKO <3=> OBM_P0 <4=> TM00_CKO <5=> SPI0_CLK <6=> TM20_OC0H <7=> TM26_OC0H <8=> MA12 <9=> MALE2
//          <i> Default: AFS = GPD12
//      </e> 
//      <e3.13> PD13 Configuration
//          <o17.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o17.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o17.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o17.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o17.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o17.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o17.12..15>    AFS : Alternate function select             <0=> GPD13 <1=> CMP1_P0 <2=> TM10_TRGO <3=> OBM_P1 <4=> TM00_TRGO <5=> NCO_CK0 <6=> TM20_OC1H <7=> TM26_OC1H <8=> MA13 <9=> MCE
//          <i> Default: AFS = GPD13
//      </e> 
//      <e3.14> PD14 Configuration
//          <o18.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o18.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o18.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o18.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o18.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o18.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o18.12..15>    AFS : Alternate function select             <0=> GPD14 <2=> TM10_ETR <3=> DAC_TRG0 <4=> TM00_ETR <6=> TM20_IC0 <7=> TM26_IC0 <8=> MA14 <9=> MOE <10=> CCL_P0 <11=> URT5_TX
//          <i> Default: AFS = GPD14
//      </e> 
//      <e3.15> PD15 Configuration
//          <o19.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o19.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o19.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o19.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o19.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o19.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o19.12..15>    AFS : Alternate function select             <0=> GPD15 <2=> NCO_P0 <3=> IR_OUT <4=> DMA_TRG0 <6=> TM20_IC1 <7=> TM26_IC1 <8=> MA15 <10=> CCL_P1 <11=> URT5_RX
//          <i> Default: AFS = GPD15
//      </e> 
        #define CONF_GPIODInit_EN           0
        #define CONF_PD_OUTPUT_DEFAULT      0xFFFF
        #define CONF_PD_FILTER_CLK          0
        #define CONF_GPIODInit_Mask         0x0000
        #define CONF_PD0_CR                 0x00000000
        #define CONF_PD1_CR                 0x00000000
        #define CONF_PD2_CR                 0x00000000
        #define CONF_PD3_CR                 0x00000000
        #define CONF_PD4_CR                 0x00000000
        #define CONF_PD5_CR                 0x00000000
        #define CONF_PD6_CR                 0x00000000
        #define CONF_PD7_CR                 0x00000000
        #define CONF_PD8_CR                 0x00000000
        #define CONF_PD9_CR                 0x00000000
        #define CONF_PD10_CR                0x00000000
        #define CONF_PD11_CR                0x00000000
        #define CONF_PD12_CR                0x00000000
        #define CONF_PD13_CR                0x00000000
        #define CONF_PD14_CR                0x00000000
        #define CONF_PD15_CR                0x00000000
//  </e> 

//
//==============================  PE IO Setting  ===============================
//
//  <e0> GPIOE Configuration
//      <o1> PE Output setting<0x0000-0xFFFF>
//          <i> GPIO PE output data bit 0~15. These bits are mapping to PE0 ~ PE15.
//      <o2> PE Input filter clock source select <0=> CLK_AHB <1=> CLK_AHB_DIV8 <2=> CLK_ILRCO <3=> TM00_TRGO <4=> CK_UT
//          <i> PE port input deglitch filter clock source select for all pins of the port.
//          <i> Default: FCKS = CLK_AHB
//      <e3.0> PE0 Configuration
//          <o4.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o4.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o4.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o4.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o4.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o4.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o4.12..15>     AFS : Alternate function select             <0=> GPE0 <1=> OBM_I0 <3=> URT0_TX <4=> DAC_TRG0 <5=> SPI0_NSS <6=> TM20_OC00 <7=> TM26_OC00 <8=> MALE <9=> MAD8 <11=> URT4_TX
//          <i> Default: AFS = GPE0
//      </e> 
//      <e3.1> PE1 Configuration
//          <o5.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o5.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o5.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o5.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o5.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o5.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o5.12..15>     AFS : Alternate function select             <0=> GPE1 <1=> OBM_I1 <3=> URT0_RX <4=> DMA_TRG1 <5=> SPI0_MISO <6=> TM20_OC01 <7=> TM26_OC01 <8=> MOE <9=> MAD9 <10=> TM36_OC0H <11=> URT4_RX
//          <i> Default: AFS = GPE1
//      </e> 
//      <e3.2> PE2 Configuration
//          <o6.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o6.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o6.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o6.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o6.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o6.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o6.12..15>     AFS : Alternate function select             <0=> GPE2 <1=> OBM_P0 <2=> I2C1_SCL <3=> URT1_TX <4=> NCO_P0 <5=> SPI0_CLK <6=> TM20_OC02 <7=> TM26_OC02 <8=> MWE <9=> MAD10 <10=> TM36_OC1H <11=> URT5_TX
//          <i> Default: AFS = GPE2
//      </e> 
//      <e3.3> PE3 Configuration
//          <o7.0..2>       IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o7.3>          HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o7.5>          PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o7.7>          INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o7.8..9>       ODC : Output drive strength                 <0=> LEVEL0 <1=> LEVEL1 <2=> LEVEL2 <3=> LEVEL3
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [1] LEVEL1 : Drive strength-1/2
//             <i> [2] LEVEL2 : Drive strength-1/4
//             <i> [3] LEVEL3 : Drive strength-1/8
//          <o7.10..11>     FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o7.12..15>     AFS : Alternate function select             <0=> GPE3 <1=> OBM_P1 <2=> I2C1_SDA <3=> URT1_RX <4=> NCO_CK0 <5=> SPI0_MOSI <6=> TM20_OC0N <7=> TM26_OC0N <8=> MCE <9=> MALE2 <11=> URT5_RX
//          <i> Default: AFS = GPE3
//      </e> 
//      <e3.8> PE8 Configuration
//          <o12.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o12.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o12.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o12.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o12.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o12.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o12.12..15>    AFS : Alternate function select             <0=> GPE8 <1=> CPU_TXEV <2=> OBM_I0 <3=> URT2_TX <4=> SDT_I0 <5=> TM36_CKO <6=> TM20_CKO <7=> TM26_CKO <9=> MAD11 <11=> URT4_TX
//          <i> Default: AFS = GPE8
//      </e> 
//      <e3.9> PE9 Configuration
//          <o13.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o13.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o13.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o13.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o13.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o13.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o13.12..15>    AFS : Alternate function select             <0=> GPE9 <1=> CPU_RXEV <2=> OBM_I1 <3=> URT2_RX <4=> SDT_I1 <5=> TM36_TRGO <6=> TM20_TRGO <7=> TM26_TRGO <9=> MOE <11=> URT4_RX
//          <i> Default: AFS = GPE9
//      </e> 
//      <e3.12> PE12 Configuration
//          <o16.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o16.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o16.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o16.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o16.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o16.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o16.12..15>    AFS : Alternate function select             <0=> GPE12 <1=> ADC0_TRG <2=> USB_S0 <4=> TM01_CKO <5=> TM16_CKO <6=> TM20_OC10 <7=> TM26_OC10 <8=> MBW0 <11=> URT6_TX
//          <i> Default: AFS = GPE12
//      </e> 
//      <e3.13> PE13 Configuration
//          <o17.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o17.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o17.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o17.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o17.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o17.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o17.12..15>    AFS : Alternate function select             <0=> GPE13 <1=> ADC0_OUT <2=> USB_S1 <4=> TM01_TRGO <5=> TM16_TRGO <6=> TM20_OC11 <7=> TM26_OC11 <8=> MBW1 <10=> TM36_OC2H <11=> URT6_RX
//          <i> Default: AFS = GPE13
//      </e> 
//      <e3.14> PE14 Configuration
//          <o18.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o18.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o18.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o18.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o18.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o18.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o18.12..15>    AFS : Alternate function select             <0=> GPE14 <1=> RTC_OUT <2=> I2C1_SCL <4=> TM01_ETR <5=> TM16_ETR <6=> TM20_OC12 <7=> TM26_OC12 <8=> MALE2 <9=> CCL_P0 <10=> TM36_OC3H <11=> URT7_TX
//          <i> Default: AFS = GPE14
//      </e> 
//      <e3.15> PE15 Configuration
//          <o19.0..2>      IOM : IO mode control                       <0=> AIO <1=> ODO <2=> PPO <3=> DIN
//          <i> Default: IOM = AIO
//             <i> [0] AIO : analog IO
//             <i> [1] ODO : open drain output
//             <i> [2] PPO : push pull output
//             <i> [3] DIN : Digital input
//          <o19.3>         HS : Output high speed                      <0=> DISABLE <1=> ENABLE
//          <i> Default: HS = DISABLE
//          <o19.5>         PU : Pull-up resister                       <0=> DISABLE <1=> ENABLE
//          <i> Default: PU = DISABLE
//          <o19.7>         INV : Input inverse                         <0=> DISABLE <1=> ENABLE
//          <i> Default: INV = DISABLE
//          <o19.8..9>      ODC : Output drive strength                 <0=> LEVEL0 <2=> LEVEL2
//          <i> Default: ODC = LEVEL0
//             <i> [0] LEVEL0 : Drive strength-full
//             <i> [2] LEVEL2 : Drive strength-1/4
//          <o19.10..11>    FDIV : Input filter clock divider           <0=> BYPASS <1=> DIV1 <2=> DIV4 <3=> DIV16
//          <i> Default: FDIV = BYPASS
//             <i> [0] BYPASS : Bypass filter
//             <i> [1] DIV1 : Divided by 1
//             <i> [2] DIV4 : Divided by 4
//             <i> [3] DIV16 : Divided by 16
//          <o19.12..15>    AFS : Alternate function select             <0=> GPE15 <1=> RTC_TS <2=> I2C1_SDA <4=> TM36_BK0 <5=> TM36_ETR <6=> TM20_OC1N <7=> TM26_OC1N <8=> MALE <9=> CCL_P1 <11=> URT7_RX
//          <i> Default: AFS = GPE15
//      </e> 
        #define CONF_GPIOEInit_EN           0
        #define CONF_PE_OUTPUT_DEFAULT      0xFFFF
        #define CONF_PE_FILTER_CLK          0
        #define CONF_GPIOEInit_Mask         0x0000
        #define CONF_PE0_CR                 0x00000000
        #define CONF_PE1_CR                 0x00000000
        #define CONF_PE2_CR                 0x00000000
        #define CONF_PE3_CR                 0x00000000
        #define CONF_PE4_CR                 0x00000000
        #define CONF_PE5_CR                 0x00000000
        #define CONF_PE6_CR                 0x00000000
        #define CONF_PE7_CR                 0x00000000
        #define CONF_PE8_CR                 0x00000000
        #define CONF_PE9_CR                 0x00000000
        #define CONF_PE10_CR                0x00000000
        #define CONF_PE11_CR                0x00000000
        #define CONF_PE12_CR                0x00000000
        #define CONF_PE13_CR                0x00000000
        #define CONF_PE14_CR                0x00000000
        #define CONF_PE15_CR                0x00000000
//  </e> 
//</h> 

/**
 ******************************************************************************
 *
 * @brief       GPIO Initial Mask Matrix - MG32F02U128 (LQFP80-Package)
 *
 ******************************************************************************
 */
    static const uint32_t GPIO_CFG[]=
    {
        #if CONF_GPIOAInit_EN == 1
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN0_Mask) == MG32x02z_PIN0_Mask
                PA0_CR_ADR,CONF_PA0_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN1_Mask) == MG32x02z_PIN1_Mask
                PA1_CR_ADR,CONF_PA1_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN2_Mask) == MG32x02z_PIN2_Mask
                PA2_CR_ADR,CONF_PA2_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN3_Mask) == MG32x02z_PIN3_Mask
                PA3_CR_ADR,CONF_PA3_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN4_Mask) == MG32x02z_PIN4_Mask
                PA4_CR_ADR,CONF_PA4_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN5_Mask) == MG32x02z_PIN5_Mask
                PA5_CR_ADR,CONF_PA5_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN6_Mask) == MG32x02z_PIN6_Mask
                PA6_CR_ADR,CONF_PA6_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN7_Mask) == MG32x02z_PIN7_Mask
                PA7_CR_ADR,CONF_PA7_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN8_Mask) == MG32x02z_PIN8_Mask
                PA8_CR_ADR,CONF_PA8_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN9_Mask) == MG32x02z_PIN9_Mask
                PA9_CR_ADR,CONF_PA9_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN10_Mask) == MG32x02z_PIN10_Mask
                PA10_CR_ADR,CONF_PA10_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN11_Mask) == MG32x02z_PIN11_Mask
                PA11_CR_ADR,CONF_PA11_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN12_Mask) == MG32x02z_PIN12_Mask
                PA12_CR_ADR,CONF_PA12_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN13_Mask) == MG32x02z_PIN13_Mask
                PA13_CR_ADR,CONF_PA13_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN14_Mask) == MG32x02z_PIN14_Mask
                PA14_CR_ADR,CONF_PA14_CR,
            #endif
            #if (CONF_GPIOAInit_Mask & MG32x02z_PIN15_Mask) == MG32x02z_PIN15_Mask
                PA15_CR_ADR,CONF_PA15_CR,
            #endif
            PA_FLT_ADR,CONF_PA_FILTER_CLK,
            PA_OUT_ADR,CONF_PA_OUTPUT_DEFAULT,
        #endif
        #if CONF_GPIOBInit_EN == 1
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN0_Mask) == MG32x02z_PIN0_Mask
                PB0_CR_ADR,CONF_PB0_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN1_Mask) == MG32x02z_PIN1_Mask
                PB1_CR_ADR,CONF_PB1_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN2_Mask) == MG32x02z_PIN2_Mask
                PB2_CR_ADR,CONF_PB2_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN3_Mask) == MG32x02z_PIN3_Mask
                PB3_CR_ADR,CONF_PB3_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN4_Mask) == MG32x02z_PIN4_Mask
                PB4_CR_ADR,CONF_PB4_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN5_Mask) == MG32x02z_PIN5_Mask
                PB5_CR_ADR,CONF_PB5_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN6_Mask) == MG32x02z_PIN6_Mask
                PB6_CR_ADR,CONF_PB6_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN7_Mask) == MG32x02z_PIN7_Mask
                PB7_CR_ADR,CONF_PB7_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN8_Mask) == MG32x02z_PIN8_Mask
                PB8_CR_ADR,CONF_PB8_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN9_Mask) == MG32x02z_PIN9_Mask
                PB9_CR_ADR,CONF_PB9_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN10_Mask) == MG32x02z_PIN10_Mask
                PB10_CR_ADR,CONF_PB10_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN11_Mask) == MG32x02z_PIN11_Mask
                PB11_CR_ADR,CONF_PB11_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN12_Mask) == MG32x02z_PIN12_Mask
                PB12_CR_ADR,CONF_PB12_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN13_Mask) == MG32x02z_PIN13_Mask
                PB13_CR_ADR,CONF_PB13_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN14_Mask) == MG32x02z_PIN14_Mask
                PB14_CR_ADR,CONF_PB14_CR,
            #endif
            #if (CONF_GPIOBInit_Mask & MG32x02z_PIN15_Mask) == MG32x02z_PIN15_Mask
                PB15_CR_ADR,CONF_PB15_CR,
            #endif
            PB_FLT_ADR,CONF_PB_FILTER_CLK,
            PB_OUT_ADR,CONF_PB_OUTPUT_DEFAULT,
        #endif
        #if CONF_GPIOCInit_EN == 1
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN0_Mask) == MG32x02z_PIN0_Mask
                PC0_CR_ADR,CONF_PC0_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN1_Mask) == MG32x02z_PIN1_Mask
                PC1_CR_ADR,CONF_PC1_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN2_Mask) == MG32x02z_PIN2_Mask
                PC2_CR_ADR,CONF_PC2_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN3_Mask) == MG32x02z_PIN3_Mask
                PC3_CR_ADR,CONF_PC3_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN4_Mask) == MG32x02z_PIN4_Mask
                PC4_CR_ADR,CONF_PC4_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN5_Mask) == MG32x02z_PIN5_Mask
                PC5_CR_ADR,CONF_PC5_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN6_Mask) == MG32x02z_PIN6_Mask
                PC6_CR_ADR,CONF_PC6_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN7_Mask) == MG32x02z_PIN7_Mask
                PC7_CR_ADR,CONF_PC7_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN8_Mask) == MG32x02z_PIN8_Mask
                PC8_CR_ADR,CONF_PC8_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN9_Mask) == MG32x02z_PIN9_Mask
                PC9_CR_ADR,CONF_PC9_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN10_Mask) == MG32x02z_PIN10_Mask
                PC10_CR_ADR,CONF_PC10_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN11_Mask) == MG32x02z_PIN11_Mask
                PC11_CR_ADR,CONF_PC11_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN12_Mask) == MG32x02z_PIN12_Mask
                PC12_CR_ADR,CONF_PC12_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN13_Mask) == MG32x02z_PIN13_Mask
                PC13_CR_ADR,CONF_PC13_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN14_Mask) == MG32x02z_PIN14_Mask
                PC14_CR_ADR,CONF_PC14_CR,
            #endif
            #if (CONF_GPIOCInit_Mask & MG32x02z_PIN15_Mask) == MG32x02z_PIN15_Mask
                PC15_CR_ADR,CONF_PC15_CR,
            #endif
            PC_FLT_ADR,CONF_PC_FILTER_CLK,
            PC_OUT_ADR,CONF_PC_OUTPUT_DEFAULT,
        #endif
        #if CONF_GPIODInit_EN == 1
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN0_Mask) == MG32x02z_PIN0_Mask
                PD0_CR_ADR,CONF_PD0_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN1_Mask) == MG32x02z_PIN1_Mask
                PD1_CR_ADR,CONF_PD1_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN2_Mask) == MG32x02z_PIN2_Mask
                PD2_CR_ADR,CONF_PD2_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN3_Mask) == MG32x02z_PIN3_Mask
                PD3_CR_ADR,CONF_PD3_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN4_Mask) == MG32x02z_PIN4_Mask
                PD4_CR_ADR,CONF_PD4_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN5_Mask) == MG32x02z_PIN5_Mask
                PD5_CR_ADR,CONF_PD5_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN6_Mask) == MG32x02z_PIN6_Mask
                PD6_CR_ADR,CONF_PD6_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN7_Mask) == MG32x02z_PIN7_Mask
                PD7_CR_ADR,CONF_PD7_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN8_Mask) == MG32x02z_PIN8_Mask
                PD8_CR_ADR,CONF_PD8_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN9_Mask) == MG32x02z_PIN9_Mask
                PD9_CR_ADR,CONF_PD9_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN10_Mask) == MG32x02z_PIN10_Mask
                PD10_CR_ADR,CONF_PD10_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN11_Mask) == MG32x02z_PIN11_Mask
                PD11_CR_ADR,CONF_PD11_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN12_Mask) == MG32x02z_PIN12_Mask
                PD12_CR_ADR,CONF_PD12_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN13_Mask) == MG32x02z_PIN13_Mask
                PD13_CR_ADR,CONF_PD13_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN14_Mask) == MG32x02z_PIN14_Mask
                PD14_CR_ADR,CONF_PD14_CR,
            #endif
            #if (CONF_GPIODInit_Mask & MG32x02z_PIN15_Mask) == MG32x02z_PIN15_Mask
                PD15_CR_ADR,CONF_PD15_CR,
            #endif
            PD_FLT_ADR,CONF_PD_FILTER_CLK,
            PD_OUT_ADR,CONF_PD_OUTPUT_DEFAULT,
        #endif
        #if CONF_GPIOEInit_EN == 1
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN0_Mask) == MG32x02z_PIN0_Mask
                PE0_CR_ADR,CONF_PE0_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN1_Mask) == MG32x02z_PIN1_Mask
                PE1_CR_ADR,CONF_PE1_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN2_Mask) == MG32x02z_PIN2_Mask
                PE2_CR_ADR,CONF_PE2_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN3_Mask) == MG32x02z_PIN3_Mask
                PE3_CR_ADR,CONF_PE3_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN4_Mask) == MG32x02z_PIN4_Mask
                PE4_CR_ADR,CONF_PE4_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN5_Mask) == MG32x02z_PIN5_Mask
                PE5_CR_ADR,CONF_PE5_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN6_Mask) == MG32x02z_PIN6_Mask
                PE6_CR_ADR,CONF_PE6_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN7_Mask) == MG32x02z_PIN7_Mask
                PE7_CR_ADR,CONF_PE7_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN8_Mask) == MG32x02z_PIN8_Mask
                PE8_CR_ADR,CONF_PE8_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN9_Mask) == MG32x02z_PIN9_Mask
                PE9_CR_ADR,CONF_PE9_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN10_Mask) == MG32x02z_PIN10_Mask
                PE10_CR_ADR,CONF_PE10_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN11_Mask) == MG32x02z_PIN11_Mask
                PE11_CR_ADR,CONF_PE11_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN12_Mask) == MG32x02z_PIN12_Mask
                PE12_CR_ADR,CONF_PE12_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN13_Mask) == MG32x02z_PIN13_Mask
                PE13_CR_ADR,CONF_PE13_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN14_Mask) == MG32x02z_PIN14_Mask
                PE14_CR_ADR,CONF_PE14_CR,
            #endif
            #if (CONF_GPIOEInit_Mask & MG32x02z_PIN15_Mask) == MG32x02z_PIN15_Mask
                PE15_CR_ADR,CONF_PE15_CR,
            #endif
            PE_FLT_ADR,CONF_PE_FILTER_CLK,
            PE_OUT_ADR,CONF_PE_OUTPUT_DEFAULT,
        #endif
        0,
    };
// <<< end of Configuration section >>>    
 
    
void GPIO_Init(void);    
    
    
#endif  // _MG32x02z_GPIO_Init_H

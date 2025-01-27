<<<<<<< HEAD
/**
 * \file
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAM4S_PWM_INSTANCE_
#define _SAM4S_PWM_INSTANCE_

/* ========== Register definition for PWM peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_PWM_CLK               (0x40020000U) /**< \brief (PWM) PWM Clock Register */
#define REG_PWM_ENA               (0x40020004U) /**< \brief (PWM) PWM Enable Register */
#define REG_PWM_DIS               (0x40020008U) /**< \brief (PWM) PWM Disable Register */
#define REG_PWM_SR                (0x4002000CU) /**< \brief (PWM) PWM Status Register */
#define REG_PWM_IER1              (0x40020010U) /**< \brief (PWM) PWM Interrupt Enable Register 1 */
#define REG_PWM_IDR1              (0x40020014U) /**< \brief (PWM) PWM Interrupt Disable Register 1 */
#define REG_PWM_IMR1              (0x40020018U) /**< \brief (PWM) PWM Interrupt Mask Register 1 */
#define REG_PWM_ISR1              (0x4002001CU) /**< \brief (PWM) PWM Interrupt Status Register 1 */
#define REG_PWM_SCM               (0x40020020U) /**< \brief (PWM) PWM Sync Channels Mode Register */
#define REG_PWM_SCUC              (0x40020028U) /**< \brief (PWM) PWM Sync Channels Update Control Register */
#define REG_PWM_SCUP              (0x4002002CU) /**< \brief (PWM) PWM Sync Channels Update Period Register */
#define REG_PWM_SCUPUPD           (0x40020030U) /**< \brief (PWM) PWM Sync Channels Update Period Update Register */
#define REG_PWM_IER2              (0x40020034U) /**< \brief (PWM) PWM Interrupt Enable Register 2 */
#define REG_PWM_IDR2              (0x40020038U) /**< \brief (PWM) PWM Interrupt Disable Register 2 */
#define REG_PWM_IMR2              (0x4002003CU) /**< \brief (PWM) PWM Interrupt Mask Register 2 */
#define REG_PWM_ISR2              (0x40020040U) /**< \brief (PWM) PWM Interrupt Status Register 2 */
#define REG_PWM_OOV               (0x40020044U) /**< \brief (PWM) PWM Output Override Value Register */
#define REG_PWM_OS                (0x40020048U) /**< \brief (PWM) PWM Output Selection Register */
#define REG_PWM_OSS               (0x4002004CU) /**< \brief (PWM) PWM Output Selection Set Register */
#define REG_PWM_OSC               (0x40020050U) /**< \brief (PWM) PWM Output Selection Clear Register */
#define REG_PWM_OSSUPD            (0x40020054U) /**< \brief (PWM) PWM Output Selection Set Update Register */
#define REG_PWM_OSCUPD            (0x40020058U) /**< \brief (PWM) PWM Output Selection Clear Update Register */
#define REG_PWM_FMR               (0x4002005CU) /**< \brief (PWM) PWM Fault Mode Register */
#define REG_PWM_FSR               (0x40020060U) /**< \brief (PWM) PWM Fault Status Register */
#define REG_PWM_FCR               (0x40020064U) /**< \brief (PWM) PWM Fault Clear Register */
#define REG_PWM_FPV               (0x40020068U) /**< \brief (PWM) PWM Fault Protection Value Register */
#define REG_PWM_FPE               (0x4002006CU) /**< \brief (PWM) PWM Fault Protection Enable Register */
#define REG_PWM_ELMR              (0x4002007CU) /**< \brief (PWM) PWM Event Line 0 Mode Register */
#define REG_PWM_SMMR              (0x400200B0U) /**< \brief (PWM) PWM Stepper Motor Mode Register */
#define REG_PWM_WPCR              (0x400200E4U) /**< \brief (PWM) PWM Write Protect Control Register */
#define REG_PWM_WPSR              (0x400200E8U) /**< \brief (PWM) PWM Write Protect Status Register */
#define REG_PWM_TPR               (0x40020108U) /**< \brief (PWM) Transmit Pointer Register */
#define REG_PWM_TCR               (0x4002010CU) /**< \brief (PWM) Transmit Counter Register */
#define REG_PWM_TNPR              (0x40020118U) /**< \brief (PWM) Transmit Next Pointer Register */
#define REG_PWM_TNCR              (0x4002011CU) /**< \brief (PWM) Transmit Next Counter Register */
#define REG_PWM_PTCR              (0x40020120U) /**< \brief (PWM) Transfer Control Register */
#define REG_PWM_PTSR              (0x40020124U) /**< \brief (PWM) Transfer Status Register */
#define REG_PWM_CMPV0             (0x40020130U) /**< \brief (PWM) PWM Comparison 0 Value Register */
#define REG_PWM_CMPVUPD0          (0x40020134U) /**< \brief (PWM) PWM Comparison 0 Value Update Register */
#define REG_PWM_CMPM0             (0x40020138U) /**< \brief (PWM) PWM Comparison 0 Mode Register */
#define REG_PWM_CMPMUPD0          (0x4002013CU) /**< \brief (PWM) PWM Comparison 0 Mode Update Register */
#define REG_PWM_CMPV1             (0x40020140U) /**< \brief (PWM) PWM Comparison 1 Value Register */
#define REG_PWM_CMPVUPD1          (0x40020144U) /**< \brief (PWM) PWM Comparison 1 Value Update Register */
#define REG_PWM_CMPM1             (0x40020148U) /**< \brief (PWM) PWM Comparison 1 Mode Register */
#define REG_PWM_CMPMUPD1          (0x4002014CU) /**< \brief (PWM) PWM Comparison 1 Mode Update Register */
#define REG_PWM_CMPV2             (0x40020150U) /**< \brief (PWM) PWM Comparison 2 Value Register */
#define REG_PWM_CMPVUPD2          (0x40020154U) /**< \brief (PWM) PWM Comparison 2 Value Update Register */
#define REG_PWM_CMPM2             (0x40020158U) /**< \brief (PWM) PWM Comparison 2 Mode Register */
#define REG_PWM_CMPMUPD2          (0x4002015CU) /**< \brief (PWM) PWM Comparison 2 Mode Update Register */
#define REG_PWM_CMPV3             (0x40020160U) /**< \brief (PWM) PWM Comparison 3 Value Register */
#define REG_PWM_CMPVUPD3          (0x40020164U) /**< \brief (PWM) PWM Comparison 3 Value Update Register */
#define REG_PWM_CMPM3             (0x40020168U) /**< \brief (PWM) PWM Comparison 3 Mode Register */
#define REG_PWM_CMPMUPD3          (0x4002016CU) /**< \brief (PWM) PWM Comparison 3 Mode Update Register */
#define REG_PWM_CMPV4             (0x40020170U) /**< \brief (PWM) PWM Comparison 4 Value Register */
#define REG_PWM_CMPVUPD4          (0x40020174U) /**< \brief (PWM) PWM Comparison 4 Value Update Register */
#define REG_PWM_CMPM4             (0x40020178U) /**< \brief (PWM) PWM Comparison 4 Mode Register */
#define REG_PWM_CMPMUPD4          (0x4002017CU) /**< \brief (PWM) PWM Comparison 4 Mode Update Register */
#define REG_PWM_CMPV5             (0x40020180U) /**< \brief (PWM) PWM Comparison 5 Value Register */
#define REG_PWM_CMPVUPD5          (0x40020184U) /**< \brief (PWM) PWM Comparison 5 Value Update Register */
#define REG_PWM_CMPM5             (0x40020188U) /**< \brief (PWM) PWM Comparison 5 Mode Register */
#define REG_PWM_CMPMUPD5          (0x4002018CU) /**< \brief (PWM) PWM Comparison 5 Mode Update Register */
#define REG_PWM_CMPV6             (0x40020190U) /**< \brief (PWM) PWM Comparison 6 Value Register */
#define REG_PWM_CMPVUPD6          (0x40020194U) /**< \brief (PWM) PWM Comparison 6 Value Update Register */
#define REG_PWM_CMPM6             (0x40020198U) /**< \brief (PWM) PWM Comparison 6 Mode Register */
#define REG_PWM_CMPMUPD6          (0x4002019CU) /**< \brief (PWM) PWM Comparison 6 Mode Update Register */
#define REG_PWM_CMPV7             (0x400201A0U) /**< \brief (PWM) PWM Comparison 7 Value Register */
#define REG_PWM_CMPVUPD7          (0x400201A4U) /**< \brief (PWM) PWM Comparison 7 Value Update Register */
#define REG_PWM_CMPM7             (0x400201A8U) /**< \brief (PWM) PWM Comparison 7 Mode Register */
#define REG_PWM_CMPMUPD7          (0x400201ACU) /**< \brief (PWM) PWM Comparison 7 Mode Update Register */
#define REG_PWM_CMR0              (0x40020200U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 0) */
#define REG_PWM_CDTY0             (0x40020204U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 0) */
#define REG_PWM_CDTYUPD0          (0x40020208U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 0) */
#define REG_PWM_CPRD0             (0x4002020CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 0) */
#define REG_PWM_CPRDUPD0          (0x40020210U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 0) */
#define REG_PWM_CCNT0             (0x40020214U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 0) */
#define REG_PWM_DT0               (0x40020218U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 0) */
#define REG_PWM_DTUPD0            (0x4002021CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 0) */
#define REG_PWM_CMR1              (0x40020220U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 1) */
#define REG_PWM_CDTY1             (0x40020224U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 1) */
#define REG_PWM_CDTYUPD1          (0x40020228U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 1) */
#define REG_PWM_CPRD1             (0x4002022CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 1) */
#define REG_PWM_CPRDUPD1          (0x40020230U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 1) */
#define REG_PWM_CCNT1             (0x40020234U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 1) */
#define REG_PWM_DT1               (0x40020238U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 1) */
#define REG_PWM_DTUPD1            (0x4002023CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 1) */
#define REG_PWM_CMR2              (0x40020240U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 2) */
#define REG_PWM_CDTY2             (0x40020244U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 2) */
#define REG_PWM_CDTYUPD2          (0x40020248U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 2) */
#define REG_PWM_CPRD2             (0x4002024CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 2) */
#define REG_PWM_CPRDUPD2          (0x40020250U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 2) */
#define REG_PWM_CCNT2             (0x40020254U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 2) */
#define REG_PWM_DT2               (0x40020258U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 2) */
#define REG_PWM_DTUPD2            (0x4002025CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 2) */
#define REG_PWM_CMR3              (0x40020260U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 3) */
#define REG_PWM_CDTY3             (0x40020264U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 3) */
#define REG_PWM_CDTYUPD3          (0x40020268U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 3) */
#define REG_PWM_CPRD3             (0x4002026CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 3) */
#define REG_PWM_CPRDUPD3          (0x40020270U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 3) */
#define REG_PWM_CCNT3             (0x40020274U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 3) */
#define REG_PWM_DT3               (0x40020278U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 3) */
#define REG_PWM_DTUPD3            (0x4002027CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 3) */
#else
#define REG_PWM_CLK      (*(RwReg*)0x40020000U) /**< \brief (PWM) PWM Clock Register */
#define REG_PWM_ENA      (*(WoReg*)0x40020004U) /**< \brief (PWM) PWM Enable Register */
#define REG_PWM_DIS      (*(WoReg*)0x40020008U) /**< \brief (PWM) PWM Disable Register */
#define REG_PWM_SR       (*(RoReg*)0x4002000CU) /**< \brief (PWM) PWM Status Register */
#define REG_PWM_IER1     (*(WoReg*)0x40020010U) /**< \brief (PWM) PWM Interrupt Enable Register 1 */
#define REG_PWM_IDR1     (*(WoReg*)0x40020014U) /**< \brief (PWM) PWM Interrupt Disable Register 1 */
#define REG_PWM_IMR1     (*(RoReg*)0x40020018U) /**< \brief (PWM) PWM Interrupt Mask Register 1 */
#define REG_PWM_ISR1     (*(RoReg*)0x4002001CU) /**< \brief (PWM) PWM Interrupt Status Register 1 */
#define REG_PWM_SCM      (*(RwReg*)0x40020020U) /**< \brief (PWM) PWM Sync Channels Mode Register */
#define REG_PWM_SCUC     (*(RwReg*)0x40020028U) /**< \brief (PWM) PWM Sync Channels Update Control Register */
#define REG_PWM_SCUP     (*(RwReg*)0x4002002CU) /**< \brief (PWM) PWM Sync Channels Update Period Register */
#define REG_PWM_SCUPUPD  (*(WoReg*)0x40020030U) /**< \brief (PWM) PWM Sync Channels Update Period Update Register */
#define REG_PWM_IER2     (*(WoReg*)0x40020034U) /**< \brief (PWM) PWM Interrupt Enable Register 2 */
#define REG_PWM_IDR2     (*(WoReg*)0x40020038U) /**< \brief (PWM) PWM Interrupt Disable Register 2 */
#define REG_PWM_IMR2     (*(RoReg*)0x4002003CU) /**< \brief (PWM) PWM Interrupt Mask Register 2 */
#define REG_PWM_ISR2     (*(RoReg*)0x40020040U) /**< \brief (PWM) PWM Interrupt Status Register 2 */
#define REG_PWM_OOV      (*(RwReg*)0x40020044U) /**< \brief (PWM) PWM Output Override Value Register */
#define REG_PWM_OS       (*(RwReg*)0x40020048U) /**< \brief (PWM) PWM Output Selection Register */
#define REG_PWM_OSS      (*(WoReg*)0x4002004CU) /**< \brief (PWM) PWM Output Selection Set Register */
#define REG_PWM_OSC      (*(WoReg*)0x40020050U) /**< \brief (PWM) PWM Output Selection Clear Register */
#define REG_PWM_OSSUPD   (*(WoReg*)0x40020054U) /**< \brief (PWM) PWM Output Selection Set Update Register */
#define REG_PWM_OSCUPD   (*(WoReg*)0x40020058U) /**< \brief (PWM) PWM Output Selection Clear Update Register */
#define REG_PWM_FMR      (*(RwReg*)0x4002005CU) /**< \brief (PWM) PWM Fault Mode Register */
#define REG_PWM_FSR      (*(RoReg*)0x40020060U) /**< \brief (PWM) PWM Fault Status Register */
#define REG_PWM_FCR      (*(WoReg*)0x40020064U) /**< \brief (PWM) PWM Fault Clear Register */
#define REG_PWM_FPV      (*(RwReg*)0x40020068U) /**< \brief (PWM) PWM Fault Protection Value Register */
#define REG_PWM_FPE      (*(RwReg*)0x4002006CU) /**< \brief (PWM) PWM Fault Protection Enable Register */
#define REG_PWM_ELMR     (*(RwReg*)0x4002007CU) /**< \brief (PWM) PWM Event Line 0 Mode Register */
#define REG_PWM_SMMR     (*(RwReg*)0x400200B0U) /**< \brief (PWM) PWM Stepper Motor Mode Register */
#define REG_PWM_WPCR     (*(WoReg*)0x400200E4U) /**< \brief (PWM) PWM Write Protect Control Register */
#define REG_PWM_WPSR     (*(RoReg*)0x400200E8U) /**< \brief (PWM) PWM Write Protect Status Register */
#define REG_PWM_TPR      (*(RwReg*)0x40020108U) /**< \brief (PWM) Transmit Pointer Register */
#define REG_PWM_TCR      (*(RwReg*)0x4002010CU) /**< \brief (PWM) Transmit Counter Register */
#define REG_PWM_TNPR     (*(RwReg*)0x40020118U) /**< \brief (PWM) Transmit Next Pointer Register */
#define REG_PWM_TNCR     (*(RwReg*)0x4002011CU) /**< \brief (PWM) Transmit Next Counter Register */
#define REG_PWM_PTCR     (*(WoReg*)0x40020120U) /**< \brief (PWM) Transfer Control Register */
#define REG_PWM_PTSR     (*(RoReg*)0x40020124U) /**< \brief (PWM) Transfer Status Register */
#define REG_PWM_CMPV0    (*(RwReg*)0x40020130U) /**< \brief (PWM) PWM Comparison 0 Value Register */
#define REG_PWM_CMPVUPD0 (*(WoReg*)0x40020134U) /**< \brief (PWM) PWM Comparison 0 Value Update Register */
#define REG_PWM_CMPM0    (*(RwReg*)0x40020138U) /**< \brief (PWM) PWM Comparison 0 Mode Register */
#define REG_PWM_CMPMUPD0 (*(WoReg*)0x4002013CU) /**< \brief (PWM) PWM Comparison 0 Mode Update Register */
#define REG_PWM_CMPV1    (*(RwReg*)0x40020140U) /**< \brief (PWM) PWM Comparison 1 Value Register */
#define REG_PWM_CMPVUPD1 (*(WoReg*)0x40020144U) /**< \brief (PWM) PWM Comparison 1 Value Update Register */
#define REG_PWM_CMPM1    (*(RwReg*)0x40020148U) /**< \brief (PWM) PWM Comparison 1 Mode Register */
#define REG_PWM_CMPMUPD1 (*(WoReg*)0x4002014CU) /**< \brief (PWM) PWM Comparison 1 Mode Update Register */
#define REG_PWM_CMPV2    (*(RwReg*)0x40020150U) /**< \brief (PWM) PWM Comparison 2 Value Register */
#define REG_PWM_CMPVUPD2 (*(WoReg*)0x40020154U) /**< \brief (PWM) PWM Comparison 2 Value Update Register */
#define REG_PWM_CMPM2    (*(RwReg*)0x40020158U) /**< \brief (PWM) PWM Comparison 2 Mode Register */
#define REG_PWM_CMPMUPD2 (*(WoReg*)0x4002015CU) /**< \brief (PWM) PWM Comparison 2 Mode Update Register */
#define REG_PWM_CMPV3    (*(RwReg*)0x40020160U) /**< \brief (PWM) PWM Comparison 3 Value Register */
#define REG_PWM_CMPVUPD3 (*(WoReg*)0x40020164U) /**< \brief (PWM) PWM Comparison 3 Value Update Register */
#define REG_PWM_CMPM3    (*(RwReg*)0x40020168U) /**< \brief (PWM) PWM Comparison 3 Mode Register */
#define REG_PWM_CMPMUPD3 (*(WoReg*)0x4002016CU) /**< \brief (PWM) PWM Comparison 3 Mode Update Register */
#define REG_PWM_CMPV4    (*(RwReg*)0x40020170U) /**< \brief (PWM) PWM Comparison 4 Value Register */
#define REG_PWM_CMPVUPD4 (*(WoReg*)0x40020174U) /**< \brief (PWM) PWM Comparison 4 Value Update Register */
#define REG_PWM_CMPM4    (*(RwReg*)0x40020178U) /**< \brief (PWM) PWM Comparison 4 Mode Register */
#define REG_PWM_CMPMUPD4 (*(WoReg*)0x4002017CU) /**< \brief (PWM) PWM Comparison 4 Mode Update Register */
#define REG_PWM_CMPV5    (*(RwReg*)0x40020180U) /**< \brief (PWM) PWM Comparison 5 Value Register */
#define REG_PWM_CMPVUPD5 (*(WoReg*)0x40020184U) /**< \brief (PWM) PWM Comparison 5 Value Update Register */
#define REG_PWM_CMPM5    (*(RwReg*)0x40020188U) /**< \brief (PWM) PWM Comparison 5 Mode Register */
#define REG_PWM_CMPMUPD5 (*(WoReg*)0x4002018CU) /**< \brief (PWM) PWM Comparison 5 Mode Update Register */
#define REG_PWM_CMPV6    (*(RwReg*)0x40020190U) /**< \brief (PWM) PWM Comparison 6 Value Register */
#define REG_PWM_CMPVUPD6 (*(WoReg*)0x40020194U) /**< \brief (PWM) PWM Comparison 6 Value Update Register */
#define REG_PWM_CMPM6    (*(RwReg*)0x40020198U) /**< \brief (PWM) PWM Comparison 6 Mode Register */
#define REG_PWM_CMPMUPD6 (*(WoReg*)0x4002019CU) /**< \brief (PWM) PWM Comparison 6 Mode Update Register */
#define REG_PWM_CMPV7    (*(RwReg*)0x400201A0U) /**< \brief (PWM) PWM Comparison 7 Value Register */
#define REG_PWM_CMPVUPD7 (*(WoReg*)0x400201A4U) /**< \brief (PWM) PWM Comparison 7 Value Update Register */
#define REG_PWM_CMPM7    (*(RwReg*)0x400201A8U) /**< \brief (PWM) PWM Comparison 7 Mode Register */
#define REG_PWM_CMPMUPD7 (*(WoReg*)0x400201ACU) /**< \brief (PWM) PWM Comparison 7 Mode Update Register */
#define REG_PWM_CMR0     (*(RwReg*)0x40020200U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 0) */
#define REG_PWM_CDTY0    (*(RwReg*)0x40020204U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 0) */
#define REG_PWM_CDTYUPD0 (*(WoReg*)0x40020208U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 0) */
#define REG_PWM_CPRD0    (*(RwReg*)0x4002020CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 0) */
#define REG_PWM_CPRDUPD0 (*(WoReg*)0x40020210U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 0) */
#define REG_PWM_CCNT0    (*(RoReg*)0x40020214U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 0) */
#define REG_PWM_DT0      (*(RwReg*)0x40020218U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 0) */
#define REG_PWM_DTUPD0   (*(WoReg*)0x4002021CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 0) */
#define REG_PWM_CMR1     (*(RwReg*)0x40020220U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 1) */
#define REG_PWM_CDTY1    (*(RwReg*)0x40020224U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 1) */
#define REG_PWM_CDTYUPD1 (*(WoReg*)0x40020228U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 1) */
#define REG_PWM_CPRD1    (*(RwReg*)0x4002022CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 1) */
#define REG_PWM_CPRDUPD1 (*(WoReg*)0x40020230U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 1) */
#define REG_PWM_CCNT1    (*(RoReg*)0x40020234U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 1) */
#define REG_PWM_DT1      (*(RwReg*)0x40020238U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 1) */
#define REG_PWM_DTUPD1   (*(WoReg*)0x4002023CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 1) */
#define REG_PWM_CMR2     (*(RwReg*)0x40020240U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 2) */
#define REG_PWM_CDTY2    (*(RwReg*)0x40020244U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 2) */
#define REG_PWM_CDTYUPD2 (*(WoReg*)0x40020248U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 2) */
#define REG_PWM_CPRD2    (*(RwReg*)0x4002024CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 2) */
#define REG_PWM_CPRDUPD2 (*(WoReg*)0x40020250U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 2) */
#define REG_PWM_CCNT2    (*(RoReg*)0x40020254U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 2) */
#define REG_PWM_DT2      (*(RwReg*)0x40020258U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 2) */
#define REG_PWM_DTUPD2   (*(WoReg*)0x4002025CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 2) */
#define REG_PWM_CMR3     (*(RwReg*)0x40020260U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 3) */
#define REG_PWM_CDTY3    (*(RwReg*)0x40020264U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 3) */
#define REG_PWM_CDTYUPD3 (*(WoReg*)0x40020268U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 3) */
#define REG_PWM_CPRD3    (*(RwReg*)0x4002026CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 3) */
#define REG_PWM_CPRDUPD3 (*(WoReg*)0x40020270U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 3) */
#define REG_PWM_CCNT3    (*(RoReg*)0x40020274U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 3) */
#define REG_PWM_DT3      (*(RwReg*)0x40020278U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 3) */
#define REG_PWM_DTUPD3   (*(WoReg*)0x4002027CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 3) */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM4S_PWM_INSTANCE_ */
=======
/**
 * \file
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAM4S_PWM_INSTANCE_
#define _SAM4S_PWM_INSTANCE_

/* ========== Register definition for PWM peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_PWM_CLK               (0x40020000U) /**< \brief (PWM) PWM Clock Register */
#define REG_PWM_ENA               (0x40020004U) /**< \brief (PWM) PWM Enable Register */
#define REG_PWM_DIS               (0x40020008U) /**< \brief (PWM) PWM Disable Register */
#define REG_PWM_SR                (0x4002000CU) /**< \brief (PWM) PWM Status Register */
#define REG_PWM_IER1              (0x40020010U) /**< \brief (PWM) PWM Interrupt Enable Register 1 */
#define REG_PWM_IDR1              (0x40020014U) /**< \brief (PWM) PWM Interrupt Disable Register 1 */
#define REG_PWM_IMR1              (0x40020018U) /**< \brief (PWM) PWM Interrupt Mask Register 1 */
#define REG_PWM_ISR1              (0x4002001CU) /**< \brief (PWM) PWM Interrupt Status Register 1 */
#define REG_PWM_SCM               (0x40020020U) /**< \brief (PWM) PWM Sync Channels Mode Register */
#define REG_PWM_SCUC              (0x40020028U) /**< \brief (PWM) PWM Sync Channels Update Control Register */
#define REG_PWM_SCUP              (0x4002002CU) /**< \brief (PWM) PWM Sync Channels Update Period Register */
#define REG_PWM_SCUPUPD           (0x40020030U) /**< \brief (PWM) PWM Sync Channels Update Period Update Register */
#define REG_PWM_IER2              (0x40020034U) /**< \brief (PWM) PWM Interrupt Enable Register 2 */
#define REG_PWM_IDR2              (0x40020038U) /**< \brief (PWM) PWM Interrupt Disable Register 2 */
#define REG_PWM_IMR2              (0x4002003CU) /**< \brief (PWM) PWM Interrupt Mask Register 2 */
#define REG_PWM_ISR2              (0x40020040U) /**< \brief (PWM) PWM Interrupt Status Register 2 */
#define REG_PWM_OOV               (0x40020044U) /**< \brief (PWM) PWM Output Override Value Register */
#define REG_PWM_OS                (0x40020048U) /**< \brief (PWM) PWM Output Selection Register */
#define REG_PWM_OSS               (0x4002004CU) /**< \brief (PWM) PWM Output Selection Set Register */
#define REG_PWM_OSC               (0x40020050U) /**< \brief (PWM) PWM Output Selection Clear Register */
#define REG_PWM_OSSUPD            (0x40020054U) /**< \brief (PWM) PWM Output Selection Set Update Register */
#define REG_PWM_OSCUPD            (0x40020058U) /**< \brief (PWM) PWM Output Selection Clear Update Register */
#define REG_PWM_FMR               (0x4002005CU) /**< \brief (PWM) PWM Fault Mode Register */
#define REG_PWM_FSR               (0x40020060U) /**< \brief (PWM) PWM Fault Status Register */
#define REG_PWM_FCR               (0x40020064U) /**< \brief (PWM) PWM Fault Clear Register */
#define REG_PWM_FPV               (0x40020068U) /**< \brief (PWM) PWM Fault Protection Value Register */
#define REG_PWM_FPE               (0x4002006CU) /**< \brief (PWM) PWM Fault Protection Enable Register */
#define REG_PWM_ELMR              (0x4002007CU) /**< \brief (PWM) PWM Event Line 0 Mode Register */
#define REG_PWM_SMMR              (0x400200B0U) /**< \brief (PWM) PWM Stepper Motor Mode Register */
#define REG_PWM_WPCR              (0x400200E4U) /**< \brief (PWM) PWM Write Protect Control Register */
#define REG_PWM_WPSR              (0x400200E8U) /**< \brief (PWM) PWM Write Protect Status Register */
#define REG_PWM_TPR               (0x40020108U) /**< \brief (PWM) Transmit Pointer Register */
#define REG_PWM_TCR               (0x4002010CU) /**< \brief (PWM) Transmit Counter Register */
#define REG_PWM_TNPR              (0x40020118U) /**< \brief (PWM) Transmit Next Pointer Register */
#define REG_PWM_TNCR              (0x4002011CU) /**< \brief (PWM) Transmit Next Counter Register */
#define REG_PWM_PTCR              (0x40020120U) /**< \brief (PWM) Transfer Control Register */
#define REG_PWM_PTSR              (0x40020124U) /**< \brief (PWM) Transfer Status Register */
#define REG_PWM_CMPV0             (0x40020130U) /**< \brief (PWM) PWM Comparison 0 Value Register */
#define REG_PWM_CMPVUPD0          (0x40020134U) /**< \brief (PWM) PWM Comparison 0 Value Update Register */
#define REG_PWM_CMPM0             (0x40020138U) /**< \brief (PWM) PWM Comparison 0 Mode Register */
#define REG_PWM_CMPMUPD0          (0x4002013CU) /**< \brief (PWM) PWM Comparison 0 Mode Update Register */
#define REG_PWM_CMPV1             (0x40020140U) /**< \brief (PWM) PWM Comparison 1 Value Register */
#define REG_PWM_CMPVUPD1          (0x40020144U) /**< \brief (PWM) PWM Comparison 1 Value Update Register */
#define REG_PWM_CMPM1             (0x40020148U) /**< \brief (PWM) PWM Comparison 1 Mode Register */
#define REG_PWM_CMPMUPD1          (0x4002014CU) /**< \brief (PWM) PWM Comparison 1 Mode Update Register */
#define REG_PWM_CMPV2             (0x40020150U) /**< \brief (PWM) PWM Comparison 2 Value Register */
#define REG_PWM_CMPVUPD2          (0x40020154U) /**< \brief (PWM) PWM Comparison 2 Value Update Register */
#define REG_PWM_CMPM2             (0x40020158U) /**< \brief (PWM) PWM Comparison 2 Mode Register */
#define REG_PWM_CMPMUPD2          (0x4002015CU) /**< \brief (PWM) PWM Comparison 2 Mode Update Register */
#define REG_PWM_CMPV3             (0x40020160U) /**< \brief (PWM) PWM Comparison 3 Value Register */
#define REG_PWM_CMPVUPD3          (0x40020164U) /**< \brief (PWM) PWM Comparison 3 Value Update Register */
#define REG_PWM_CMPM3             (0x40020168U) /**< \brief (PWM) PWM Comparison 3 Mode Register */
#define REG_PWM_CMPMUPD3          (0x4002016CU) /**< \brief (PWM) PWM Comparison 3 Mode Update Register */
#define REG_PWM_CMPV4             (0x40020170U) /**< \brief (PWM) PWM Comparison 4 Value Register */
#define REG_PWM_CMPVUPD4          (0x40020174U) /**< \brief (PWM) PWM Comparison 4 Value Update Register */
#define REG_PWM_CMPM4             (0x40020178U) /**< \brief (PWM) PWM Comparison 4 Mode Register */
#define REG_PWM_CMPMUPD4          (0x4002017CU) /**< \brief (PWM) PWM Comparison 4 Mode Update Register */
#define REG_PWM_CMPV5             (0x40020180U) /**< \brief (PWM) PWM Comparison 5 Value Register */
#define REG_PWM_CMPVUPD5          (0x40020184U) /**< \brief (PWM) PWM Comparison 5 Value Update Register */
#define REG_PWM_CMPM5             (0x40020188U) /**< \brief (PWM) PWM Comparison 5 Mode Register */
#define REG_PWM_CMPMUPD5          (0x4002018CU) /**< \brief (PWM) PWM Comparison 5 Mode Update Register */
#define REG_PWM_CMPV6             (0x40020190U) /**< \brief (PWM) PWM Comparison 6 Value Register */
#define REG_PWM_CMPVUPD6          (0x40020194U) /**< \brief (PWM) PWM Comparison 6 Value Update Register */
#define REG_PWM_CMPM6             (0x40020198U) /**< \brief (PWM) PWM Comparison 6 Mode Register */
#define REG_PWM_CMPMUPD6          (0x4002019CU) /**< \brief (PWM) PWM Comparison 6 Mode Update Register */
#define REG_PWM_CMPV7             (0x400201A0U) /**< \brief (PWM) PWM Comparison 7 Value Register */
#define REG_PWM_CMPVUPD7          (0x400201A4U) /**< \brief (PWM) PWM Comparison 7 Value Update Register */
#define REG_PWM_CMPM7             (0x400201A8U) /**< \brief (PWM) PWM Comparison 7 Mode Register */
#define REG_PWM_CMPMUPD7          (0x400201ACU) /**< \brief (PWM) PWM Comparison 7 Mode Update Register */
#define REG_PWM_CMR0              (0x40020200U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 0) */
#define REG_PWM_CDTY0             (0x40020204U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 0) */
#define REG_PWM_CDTYUPD0          (0x40020208U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 0) */
#define REG_PWM_CPRD0             (0x4002020CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 0) */
#define REG_PWM_CPRDUPD0          (0x40020210U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 0) */
#define REG_PWM_CCNT0             (0x40020214U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 0) */
#define REG_PWM_DT0               (0x40020218U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 0) */
#define REG_PWM_DTUPD0            (0x4002021CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 0) */
#define REG_PWM_CMR1              (0x40020220U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 1) */
#define REG_PWM_CDTY1             (0x40020224U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 1) */
#define REG_PWM_CDTYUPD1          (0x40020228U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 1) */
#define REG_PWM_CPRD1             (0x4002022CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 1) */
#define REG_PWM_CPRDUPD1          (0x40020230U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 1) */
#define REG_PWM_CCNT1             (0x40020234U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 1) */
#define REG_PWM_DT1               (0x40020238U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 1) */
#define REG_PWM_DTUPD1            (0x4002023CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 1) */
#define REG_PWM_CMR2              (0x40020240U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 2) */
#define REG_PWM_CDTY2             (0x40020244U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 2) */
#define REG_PWM_CDTYUPD2          (0x40020248U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 2) */
#define REG_PWM_CPRD2             (0x4002024CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 2) */
#define REG_PWM_CPRDUPD2          (0x40020250U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 2) */
#define REG_PWM_CCNT2             (0x40020254U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 2) */
#define REG_PWM_DT2               (0x40020258U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 2) */
#define REG_PWM_DTUPD2            (0x4002025CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 2) */
#define REG_PWM_CMR3              (0x40020260U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 3) */
#define REG_PWM_CDTY3             (0x40020264U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 3) */
#define REG_PWM_CDTYUPD3          (0x40020268U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 3) */
#define REG_PWM_CPRD3             (0x4002026CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 3) */
#define REG_PWM_CPRDUPD3          (0x40020270U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 3) */
#define REG_PWM_CCNT3             (0x40020274U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 3) */
#define REG_PWM_DT3               (0x40020278U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 3) */
#define REG_PWM_DTUPD3            (0x4002027CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 3) */
#else
#define REG_PWM_CLK      (*(RwReg*)0x40020000U) /**< \brief (PWM) PWM Clock Register */
#define REG_PWM_ENA      (*(WoReg*)0x40020004U) /**< \brief (PWM) PWM Enable Register */
#define REG_PWM_DIS      (*(WoReg*)0x40020008U) /**< \brief (PWM) PWM Disable Register */
#define REG_PWM_SR       (*(RoReg*)0x4002000CU) /**< \brief (PWM) PWM Status Register */
#define REG_PWM_IER1     (*(WoReg*)0x40020010U) /**< \brief (PWM) PWM Interrupt Enable Register 1 */
#define REG_PWM_IDR1     (*(WoReg*)0x40020014U) /**< \brief (PWM) PWM Interrupt Disable Register 1 */
#define REG_PWM_IMR1     (*(RoReg*)0x40020018U) /**< \brief (PWM) PWM Interrupt Mask Register 1 */
#define REG_PWM_ISR1     (*(RoReg*)0x4002001CU) /**< \brief (PWM) PWM Interrupt Status Register 1 */
#define REG_PWM_SCM      (*(RwReg*)0x40020020U) /**< \brief (PWM) PWM Sync Channels Mode Register */
#define REG_PWM_SCUC     (*(RwReg*)0x40020028U) /**< \brief (PWM) PWM Sync Channels Update Control Register */
#define REG_PWM_SCUP     (*(RwReg*)0x4002002CU) /**< \brief (PWM) PWM Sync Channels Update Period Register */
#define REG_PWM_SCUPUPD  (*(WoReg*)0x40020030U) /**< \brief (PWM) PWM Sync Channels Update Period Update Register */
#define REG_PWM_IER2     (*(WoReg*)0x40020034U) /**< \brief (PWM) PWM Interrupt Enable Register 2 */
#define REG_PWM_IDR2     (*(WoReg*)0x40020038U) /**< \brief (PWM) PWM Interrupt Disable Register 2 */
#define REG_PWM_IMR2     (*(RoReg*)0x4002003CU) /**< \brief (PWM) PWM Interrupt Mask Register 2 */
#define REG_PWM_ISR2     (*(RoReg*)0x40020040U) /**< \brief (PWM) PWM Interrupt Status Register 2 */
#define REG_PWM_OOV      (*(RwReg*)0x40020044U) /**< \brief (PWM) PWM Output Override Value Register */
#define REG_PWM_OS       (*(RwReg*)0x40020048U) /**< \brief (PWM) PWM Output Selection Register */
#define REG_PWM_OSS      (*(WoReg*)0x4002004CU) /**< \brief (PWM) PWM Output Selection Set Register */
#define REG_PWM_OSC      (*(WoReg*)0x40020050U) /**< \brief (PWM) PWM Output Selection Clear Register */
#define REG_PWM_OSSUPD   (*(WoReg*)0x40020054U) /**< \brief (PWM) PWM Output Selection Set Update Register */
#define REG_PWM_OSCUPD   (*(WoReg*)0x40020058U) /**< \brief (PWM) PWM Output Selection Clear Update Register */
#define REG_PWM_FMR      (*(RwReg*)0x4002005CU) /**< \brief (PWM) PWM Fault Mode Register */
#define REG_PWM_FSR      (*(RoReg*)0x40020060U) /**< \brief (PWM) PWM Fault Status Register */
#define REG_PWM_FCR      (*(WoReg*)0x40020064U) /**< \brief (PWM) PWM Fault Clear Register */
#define REG_PWM_FPV      (*(RwReg*)0x40020068U) /**< \brief (PWM) PWM Fault Protection Value Register */
#define REG_PWM_FPE      (*(RwReg*)0x4002006CU) /**< \brief (PWM) PWM Fault Protection Enable Register */
#define REG_PWM_ELMR     (*(RwReg*)0x4002007CU) /**< \brief (PWM) PWM Event Line 0 Mode Register */
#define REG_PWM_SMMR     (*(RwReg*)0x400200B0U) /**< \brief (PWM) PWM Stepper Motor Mode Register */
#define REG_PWM_WPCR     (*(WoReg*)0x400200E4U) /**< \brief (PWM) PWM Write Protect Control Register */
#define REG_PWM_WPSR     (*(RoReg*)0x400200E8U) /**< \brief (PWM) PWM Write Protect Status Register */
#define REG_PWM_TPR      (*(RwReg*)0x40020108U) /**< \brief (PWM) Transmit Pointer Register */
#define REG_PWM_TCR      (*(RwReg*)0x4002010CU) /**< \brief (PWM) Transmit Counter Register */
#define REG_PWM_TNPR     (*(RwReg*)0x40020118U) /**< \brief (PWM) Transmit Next Pointer Register */
#define REG_PWM_TNCR     (*(RwReg*)0x4002011CU) /**< \brief (PWM) Transmit Next Counter Register */
#define REG_PWM_PTCR     (*(WoReg*)0x40020120U) /**< \brief (PWM) Transfer Control Register */
#define REG_PWM_PTSR     (*(RoReg*)0x40020124U) /**< \brief (PWM) Transfer Status Register */
#define REG_PWM_CMPV0    (*(RwReg*)0x40020130U) /**< \brief (PWM) PWM Comparison 0 Value Register */
#define REG_PWM_CMPVUPD0 (*(WoReg*)0x40020134U) /**< \brief (PWM) PWM Comparison 0 Value Update Register */
#define REG_PWM_CMPM0    (*(RwReg*)0x40020138U) /**< \brief (PWM) PWM Comparison 0 Mode Register */
#define REG_PWM_CMPMUPD0 (*(WoReg*)0x4002013CU) /**< \brief (PWM) PWM Comparison 0 Mode Update Register */
#define REG_PWM_CMPV1    (*(RwReg*)0x40020140U) /**< \brief (PWM) PWM Comparison 1 Value Register */
#define REG_PWM_CMPVUPD1 (*(WoReg*)0x40020144U) /**< \brief (PWM) PWM Comparison 1 Value Update Register */
#define REG_PWM_CMPM1    (*(RwReg*)0x40020148U) /**< \brief (PWM) PWM Comparison 1 Mode Register */
#define REG_PWM_CMPMUPD1 (*(WoReg*)0x4002014CU) /**< \brief (PWM) PWM Comparison 1 Mode Update Register */
#define REG_PWM_CMPV2    (*(RwReg*)0x40020150U) /**< \brief (PWM) PWM Comparison 2 Value Register */
#define REG_PWM_CMPVUPD2 (*(WoReg*)0x40020154U) /**< \brief (PWM) PWM Comparison 2 Value Update Register */
#define REG_PWM_CMPM2    (*(RwReg*)0x40020158U) /**< \brief (PWM) PWM Comparison 2 Mode Register */
#define REG_PWM_CMPMUPD2 (*(WoReg*)0x4002015CU) /**< \brief (PWM) PWM Comparison 2 Mode Update Register */
#define REG_PWM_CMPV3    (*(RwReg*)0x40020160U) /**< \brief (PWM) PWM Comparison 3 Value Register */
#define REG_PWM_CMPVUPD3 (*(WoReg*)0x40020164U) /**< \brief (PWM) PWM Comparison 3 Value Update Register */
#define REG_PWM_CMPM3    (*(RwReg*)0x40020168U) /**< \brief (PWM) PWM Comparison 3 Mode Register */
#define REG_PWM_CMPMUPD3 (*(WoReg*)0x4002016CU) /**< \brief (PWM) PWM Comparison 3 Mode Update Register */
#define REG_PWM_CMPV4    (*(RwReg*)0x40020170U) /**< \brief (PWM) PWM Comparison 4 Value Register */
#define REG_PWM_CMPVUPD4 (*(WoReg*)0x40020174U) /**< \brief (PWM) PWM Comparison 4 Value Update Register */
#define REG_PWM_CMPM4    (*(RwReg*)0x40020178U) /**< \brief (PWM) PWM Comparison 4 Mode Register */
#define REG_PWM_CMPMUPD4 (*(WoReg*)0x4002017CU) /**< \brief (PWM) PWM Comparison 4 Mode Update Register */
#define REG_PWM_CMPV5    (*(RwReg*)0x40020180U) /**< \brief (PWM) PWM Comparison 5 Value Register */
#define REG_PWM_CMPVUPD5 (*(WoReg*)0x40020184U) /**< \brief (PWM) PWM Comparison 5 Value Update Register */
#define REG_PWM_CMPM5    (*(RwReg*)0x40020188U) /**< \brief (PWM) PWM Comparison 5 Mode Register */
#define REG_PWM_CMPMUPD5 (*(WoReg*)0x4002018CU) /**< \brief (PWM) PWM Comparison 5 Mode Update Register */
#define REG_PWM_CMPV6    (*(RwReg*)0x40020190U) /**< \brief (PWM) PWM Comparison 6 Value Register */
#define REG_PWM_CMPVUPD6 (*(WoReg*)0x40020194U) /**< \brief (PWM) PWM Comparison 6 Value Update Register */
#define REG_PWM_CMPM6    (*(RwReg*)0x40020198U) /**< \brief (PWM) PWM Comparison 6 Mode Register */
#define REG_PWM_CMPMUPD6 (*(WoReg*)0x4002019CU) /**< \brief (PWM) PWM Comparison 6 Mode Update Register */
#define REG_PWM_CMPV7    (*(RwReg*)0x400201A0U) /**< \brief (PWM) PWM Comparison 7 Value Register */
#define REG_PWM_CMPVUPD7 (*(WoReg*)0x400201A4U) /**< \brief (PWM) PWM Comparison 7 Value Update Register */
#define REG_PWM_CMPM7    (*(RwReg*)0x400201A8U) /**< \brief (PWM) PWM Comparison 7 Mode Register */
#define REG_PWM_CMPMUPD7 (*(WoReg*)0x400201ACU) /**< \brief (PWM) PWM Comparison 7 Mode Update Register */
#define REG_PWM_CMR0     (*(RwReg*)0x40020200U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 0) */
#define REG_PWM_CDTY0    (*(RwReg*)0x40020204U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 0) */
#define REG_PWM_CDTYUPD0 (*(WoReg*)0x40020208U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 0) */
#define REG_PWM_CPRD0    (*(RwReg*)0x4002020CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 0) */
#define REG_PWM_CPRDUPD0 (*(WoReg*)0x40020210U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 0) */
#define REG_PWM_CCNT0    (*(RoReg*)0x40020214U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 0) */
#define REG_PWM_DT0      (*(RwReg*)0x40020218U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 0) */
#define REG_PWM_DTUPD0   (*(WoReg*)0x4002021CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 0) */
#define REG_PWM_CMR1     (*(RwReg*)0x40020220U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 1) */
#define REG_PWM_CDTY1    (*(RwReg*)0x40020224U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 1) */
#define REG_PWM_CDTYUPD1 (*(WoReg*)0x40020228U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 1) */
#define REG_PWM_CPRD1    (*(RwReg*)0x4002022CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 1) */
#define REG_PWM_CPRDUPD1 (*(WoReg*)0x40020230U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 1) */
#define REG_PWM_CCNT1    (*(RoReg*)0x40020234U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 1) */
#define REG_PWM_DT1      (*(RwReg*)0x40020238U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 1) */
#define REG_PWM_DTUPD1   (*(WoReg*)0x4002023CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 1) */
#define REG_PWM_CMR2     (*(RwReg*)0x40020240U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 2) */
#define REG_PWM_CDTY2    (*(RwReg*)0x40020244U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 2) */
#define REG_PWM_CDTYUPD2 (*(WoReg*)0x40020248U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 2) */
#define REG_PWM_CPRD2    (*(RwReg*)0x4002024CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 2) */
#define REG_PWM_CPRDUPD2 (*(WoReg*)0x40020250U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 2) */
#define REG_PWM_CCNT2    (*(RoReg*)0x40020254U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 2) */
#define REG_PWM_DT2      (*(RwReg*)0x40020258U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 2) */
#define REG_PWM_DTUPD2   (*(WoReg*)0x4002025CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 2) */
#define REG_PWM_CMR3     (*(RwReg*)0x40020260U) /**< \brief (PWM) PWM Channel Mode Register (ch_num = 3) */
#define REG_PWM_CDTY3    (*(RwReg*)0x40020264U) /**< \brief (PWM) PWM Channel Duty Cycle Register (ch_num = 3) */
#define REG_PWM_CDTYUPD3 (*(WoReg*)0x40020268U) /**< \brief (PWM) PWM Channel Duty Cycle Update Register (ch_num = 3) */
#define REG_PWM_CPRD3    (*(RwReg*)0x4002026CU) /**< \brief (PWM) PWM Channel Period Register (ch_num = 3) */
#define REG_PWM_CPRDUPD3 (*(WoReg*)0x40020270U) /**< \brief (PWM) PWM Channel Period Update Register (ch_num = 3) */
#define REG_PWM_CCNT3    (*(RoReg*)0x40020274U) /**< \brief (PWM) PWM Channel Counter Register (ch_num = 3) */
#define REG_PWM_DT3      (*(RwReg*)0x40020278U) /**< \brief (PWM) PWM Channel Dead Time Register (ch_num = 3) */
#define REG_PWM_DTUPD3   (*(WoReg*)0x4002027CU) /**< \brief (PWM) PWM Channel Dead Time Update Register (ch_num = 3) */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM4S_PWM_INSTANCE_ */
>>>>>>> 16c66438 (Upload from PC.)

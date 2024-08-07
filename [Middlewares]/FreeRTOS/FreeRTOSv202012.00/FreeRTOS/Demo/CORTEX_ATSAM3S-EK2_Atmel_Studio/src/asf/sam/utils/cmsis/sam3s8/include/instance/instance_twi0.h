<<<<<<< HEAD
/**
 * \file
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
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

#ifndef _SAM3S8_TWI0_INSTANCE_
#define _SAM3S8_TWI0_INSTANCE_

/* ========== Register definition for TWI0 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_TWI0_CR            (0x40018000U) /**< \brief (TWI0) Control Register */
#define REG_TWI0_MMR           (0x40018004U) /**< \brief (TWI0) Master Mode Register */
#define REG_TWI0_SMR           (0x40018008U) /**< \brief (TWI0) Slave Mode Register */
#define REG_TWI0_IADR          (0x4001800CU) /**< \brief (TWI0) Internal Address Register */
#define REG_TWI0_CWGR          (0x40018010U) /**< \brief (TWI0) Clock Waveform Generator Register */
#define REG_TWI0_SR            (0x40018020U) /**< \brief (TWI0) Status Register */
#define REG_TWI0_IER           (0x40018024U) /**< \brief (TWI0) Interrupt Enable Register */
#define REG_TWI0_IDR           (0x40018028U) /**< \brief (TWI0) Interrupt Disable Register */
#define REG_TWI0_IMR           (0x4001802CU) /**< \brief (TWI0) Interrupt Mask Register */
#define REG_TWI0_RHR           (0x40018030U) /**< \brief (TWI0) Receive Holding Register */
#define REG_TWI0_THR           (0x40018034U) /**< \brief (TWI0) Transmit Holding Register */
#define REG_TWI0_RPR           (0x40018100U) /**< \brief (TWI0) Receive Pointer Register */
#define REG_TWI0_RCR           (0x40018104U) /**< \brief (TWI0) Receive Counter Register */
#define REG_TWI0_TPR           (0x40018108U) /**< \brief (TWI0) Transmit Pointer Register */
#define REG_TWI0_TCR           (0x4001810CU) /**< \brief (TWI0) Transmit Counter Register */
#define REG_TWI0_RNPR          (0x40018110U) /**< \brief (TWI0) Receive Next Pointer Register */
#define REG_TWI0_RNCR          (0x40018114U) /**< \brief (TWI0) Receive Next Counter Register */
#define REG_TWI0_TNPR          (0x40018118U) /**< \brief (TWI0) Transmit Next Pointer Register */
#define REG_TWI0_TNCR          (0x4001811CU) /**< \brief (TWI0) Transmit Next Counter Register */
#define REG_TWI0_PTCR          (0x40018120U) /**< \brief (TWI0) Transfer Control Register */
#define REG_TWI0_PTSR          (0x40018124U) /**< \brief (TWI0) Transfer Status Register */
#else
#define REG_TWI0_CR   (*(WoReg*)0x40018000U) /**< \brief (TWI0) Control Register */
#define REG_TWI0_MMR  (*(RwReg*)0x40018004U) /**< \brief (TWI0) Master Mode Register */
#define REG_TWI0_SMR  (*(RwReg*)0x40018008U) /**< \brief (TWI0) Slave Mode Register */
#define REG_TWI0_IADR (*(RwReg*)0x4001800CU) /**< \brief (TWI0) Internal Address Register */
#define REG_TWI0_CWGR (*(RwReg*)0x40018010U) /**< \brief (TWI0) Clock Waveform Generator Register */
#define REG_TWI0_SR   (*(RoReg*)0x40018020U) /**< \brief (TWI0) Status Register */
#define REG_TWI0_IER  (*(WoReg*)0x40018024U) /**< \brief (TWI0) Interrupt Enable Register */
#define REG_TWI0_IDR  (*(WoReg*)0x40018028U) /**< \brief (TWI0) Interrupt Disable Register */
#define REG_TWI0_IMR  (*(RoReg*)0x4001802CU) /**< \brief (TWI0) Interrupt Mask Register */
#define REG_TWI0_RHR  (*(RoReg*)0x40018030U) /**< \brief (TWI0) Receive Holding Register */
#define REG_TWI0_THR  (*(WoReg*)0x40018034U) /**< \brief (TWI0) Transmit Holding Register */
#define REG_TWI0_RPR  (*(RwReg*)0x40018100U) /**< \brief (TWI0) Receive Pointer Register */
#define REG_TWI0_RCR  (*(RwReg*)0x40018104U) /**< \brief (TWI0) Receive Counter Register */
#define REG_TWI0_TPR  (*(RwReg*)0x40018108U) /**< \brief (TWI0) Transmit Pointer Register */
#define REG_TWI0_TCR  (*(RwReg*)0x4001810CU) /**< \brief (TWI0) Transmit Counter Register */
#define REG_TWI0_RNPR (*(RwReg*)0x40018110U) /**< \brief (TWI0) Receive Next Pointer Register */
#define REG_TWI0_RNCR (*(RwReg*)0x40018114U) /**< \brief (TWI0) Receive Next Counter Register */
#define REG_TWI0_TNPR (*(RwReg*)0x40018118U) /**< \brief (TWI0) Transmit Next Pointer Register */
#define REG_TWI0_TNCR (*(RwReg*)0x4001811CU) /**< \brief (TWI0) Transmit Next Counter Register */
#define REG_TWI0_PTCR (*(WoReg*)0x40018120U) /**< \brief (TWI0) Transfer Control Register */
#define REG_TWI0_PTSR (*(RoReg*)0x40018124U) /**< \brief (TWI0) Transfer Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3S8_TWI0_INSTANCE_ */
=======
/**
 * \file
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
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

#ifndef _SAM3S8_TWI0_INSTANCE_
#define _SAM3S8_TWI0_INSTANCE_

/* ========== Register definition for TWI0 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_TWI0_CR            (0x40018000U) /**< \brief (TWI0) Control Register */
#define REG_TWI0_MMR           (0x40018004U) /**< \brief (TWI0) Master Mode Register */
#define REG_TWI0_SMR           (0x40018008U) /**< \brief (TWI0) Slave Mode Register */
#define REG_TWI0_IADR          (0x4001800CU) /**< \brief (TWI0) Internal Address Register */
#define REG_TWI0_CWGR          (0x40018010U) /**< \brief (TWI0) Clock Waveform Generator Register */
#define REG_TWI0_SR            (0x40018020U) /**< \brief (TWI0) Status Register */
#define REG_TWI0_IER           (0x40018024U) /**< \brief (TWI0) Interrupt Enable Register */
#define REG_TWI0_IDR           (0x40018028U) /**< \brief (TWI0) Interrupt Disable Register */
#define REG_TWI0_IMR           (0x4001802CU) /**< \brief (TWI0) Interrupt Mask Register */
#define REG_TWI0_RHR           (0x40018030U) /**< \brief (TWI0) Receive Holding Register */
#define REG_TWI0_THR           (0x40018034U) /**< \brief (TWI0) Transmit Holding Register */
#define REG_TWI0_RPR           (0x40018100U) /**< \brief (TWI0) Receive Pointer Register */
#define REG_TWI0_RCR           (0x40018104U) /**< \brief (TWI0) Receive Counter Register */
#define REG_TWI0_TPR           (0x40018108U) /**< \brief (TWI0) Transmit Pointer Register */
#define REG_TWI0_TCR           (0x4001810CU) /**< \brief (TWI0) Transmit Counter Register */
#define REG_TWI0_RNPR          (0x40018110U) /**< \brief (TWI0) Receive Next Pointer Register */
#define REG_TWI0_RNCR          (0x40018114U) /**< \brief (TWI0) Receive Next Counter Register */
#define REG_TWI0_TNPR          (0x40018118U) /**< \brief (TWI0) Transmit Next Pointer Register */
#define REG_TWI0_TNCR          (0x4001811CU) /**< \brief (TWI0) Transmit Next Counter Register */
#define REG_TWI0_PTCR          (0x40018120U) /**< \brief (TWI0) Transfer Control Register */
#define REG_TWI0_PTSR          (0x40018124U) /**< \brief (TWI0) Transfer Status Register */
#else
#define REG_TWI0_CR   (*(WoReg*)0x40018000U) /**< \brief (TWI0) Control Register */
#define REG_TWI0_MMR  (*(RwReg*)0x40018004U) /**< \brief (TWI0) Master Mode Register */
#define REG_TWI0_SMR  (*(RwReg*)0x40018008U) /**< \brief (TWI0) Slave Mode Register */
#define REG_TWI0_IADR (*(RwReg*)0x4001800CU) /**< \brief (TWI0) Internal Address Register */
#define REG_TWI0_CWGR (*(RwReg*)0x40018010U) /**< \brief (TWI0) Clock Waveform Generator Register */
#define REG_TWI0_SR   (*(RoReg*)0x40018020U) /**< \brief (TWI0) Status Register */
#define REG_TWI0_IER  (*(WoReg*)0x40018024U) /**< \brief (TWI0) Interrupt Enable Register */
#define REG_TWI0_IDR  (*(WoReg*)0x40018028U) /**< \brief (TWI0) Interrupt Disable Register */
#define REG_TWI0_IMR  (*(RoReg*)0x4001802CU) /**< \brief (TWI0) Interrupt Mask Register */
#define REG_TWI0_RHR  (*(RoReg*)0x40018030U) /**< \brief (TWI0) Receive Holding Register */
#define REG_TWI0_THR  (*(WoReg*)0x40018034U) /**< \brief (TWI0) Transmit Holding Register */
#define REG_TWI0_RPR  (*(RwReg*)0x40018100U) /**< \brief (TWI0) Receive Pointer Register */
#define REG_TWI0_RCR  (*(RwReg*)0x40018104U) /**< \brief (TWI0) Receive Counter Register */
#define REG_TWI0_TPR  (*(RwReg*)0x40018108U) /**< \brief (TWI0) Transmit Pointer Register */
#define REG_TWI0_TCR  (*(RwReg*)0x4001810CU) /**< \brief (TWI0) Transmit Counter Register */
#define REG_TWI0_RNPR (*(RwReg*)0x40018110U) /**< \brief (TWI0) Receive Next Pointer Register */
#define REG_TWI0_RNCR (*(RwReg*)0x40018114U) /**< \brief (TWI0) Receive Next Counter Register */
#define REG_TWI0_TNPR (*(RwReg*)0x40018118U) /**< \brief (TWI0) Transmit Next Pointer Register */
#define REG_TWI0_TNCR (*(RwReg*)0x4001811CU) /**< \brief (TWI0) Transmit Next Counter Register */
#define REG_TWI0_PTCR (*(WoReg*)0x40018120U) /**< \brief (TWI0) Transfer Control Register */
#define REG_TWI0_PTSR (*(RoReg*)0x40018124U) /**< \brief (TWI0) Transfer Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3S8_TWI0_INSTANCE_ */
>>>>>>> 16c66438 (Upload from PC.)

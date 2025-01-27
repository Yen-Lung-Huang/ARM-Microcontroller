<<<<<<< HEAD
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

#ifndef _SAMA5_TWI1_INSTANCE_
#define _SAMA5_TWI1_INSTANCE_

/* ========== Register definition for TWI1 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_TWI1_CR                    (0xF0018000U) /**< \brief (TWI1) Control Register */
#define REG_TWI1_MMR                   (0xF0018004U) /**< \brief (TWI1) Master Mode Register */
#define REG_TWI1_SMR                   (0xF0018008U) /**< \brief (TWI1) Slave Mode Register */
#define REG_TWI1_IADR                  (0xF001800CU) /**< \brief (TWI1) Internal Address Register */
#define REG_TWI1_CWGR                  (0xF0018010U) /**< \brief (TWI1) Clock Waveform Generator Register */
#define REG_TWI1_SR                    (0xF0018020U) /**< \brief (TWI1) Status Register */
#define REG_TWI1_IER                   (0xF0018024U) /**< \brief (TWI1) Interrupt Enable Register */
#define REG_TWI1_IDR                   (0xF0018028U) /**< \brief (TWI1) Interrupt Disable Register */
#define REG_TWI1_IMR                   (0xF001802CU) /**< \brief (TWI1) Interrupt Mask Register */
#define REG_TWI1_RHR                   (0xF0018030U) /**< \brief (TWI1) Receive Holding Register */
#define REG_TWI1_THR                   (0xF0018034U) /**< \brief (TWI1) Transmit Holding Register */
#define REG_TWI1_WPROT_MODE            (0xF00180E4U) /**< \brief (TWI1) Protection Mode Register */
#define REG_TWI1_WPROT_STATUS          (0xF00180E8U) /**< \brief (TWI1) Protection Status Register */
#else
#define REG_TWI1_CR           (*(WoReg*)0xF0018000U) /**< \brief (TWI1) Control Register */
#define REG_TWI1_MMR          (*(RwReg*)0xF0018004U) /**< \brief (TWI1) Master Mode Register */
#define REG_TWI1_SMR          (*(RwReg*)0xF0018008U) /**< \brief (TWI1) Slave Mode Register */
#define REG_TWI1_IADR         (*(RwReg*)0xF001800CU) /**< \brief (TWI1) Internal Address Register */
#define REG_TWI1_CWGR         (*(RwReg*)0xF0018010U) /**< \brief (TWI1) Clock Waveform Generator Register */
#define REG_TWI1_SR           (*(RoReg*)0xF0018020U) /**< \brief (TWI1) Status Register */
#define REG_TWI1_IER          (*(WoReg*)0xF0018024U) /**< \brief (TWI1) Interrupt Enable Register */
#define REG_TWI1_IDR          (*(WoReg*)0xF0018028U) /**< \brief (TWI1) Interrupt Disable Register */
#define REG_TWI1_IMR          (*(RoReg*)0xF001802CU) /**< \brief (TWI1) Interrupt Mask Register */
#define REG_TWI1_RHR          (*(RoReg*)0xF0018030U) /**< \brief (TWI1) Receive Holding Register */
#define REG_TWI1_THR          (*(WoReg*)0xF0018034U) /**< \brief (TWI1) Transmit Holding Register */
#define REG_TWI1_WPROT_MODE   (*(RwReg*)0xF00180E4U) /**< \brief (TWI1) Protection Mode Register */
#define REG_TWI1_WPROT_STATUS (*(RoReg*)0xF00180E8U) /**< \brief (TWI1) Protection Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAMA5_TWI1_INSTANCE_ */
=======
/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

#ifndef _SAMA5_TWI1_INSTANCE_
#define _SAMA5_TWI1_INSTANCE_

/* ========== Register definition for TWI1 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_TWI1_CR                    (0xF0018000U) /**< \brief (TWI1) Control Register */
#define REG_TWI1_MMR                   (0xF0018004U) /**< \brief (TWI1) Master Mode Register */
#define REG_TWI1_SMR                   (0xF0018008U) /**< \brief (TWI1) Slave Mode Register */
#define REG_TWI1_IADR                  (0xF001800CU) /**< \brief (TWI1) Internal Address Register */
#define REG_TWI1_CWGR                  (0xF0018010U) /**< \brief (TWI1) Clock Waveform Generator Register */
#define REG_TWI1_SR                    (0xF0018020U) /**< \brief (TWI1) Status Register */
#define REG_TWI1_IER                   (0xF0018024U) /**< \brief (TWI1) Interrupt Enable Register */
#define REG_TWI1_IDR                   (0xF0018028U) /**< \brief (TWI1) Interrupt Disable Register */
#define REG_TWI1_IMR                   (0xF001802CU) /**< \brief (TWI1) Interrupt Mask Register */
#define REG_TWI1_RHR                   (0xF0018030U) /**< \brief (TWI1) Receive Holding Register */
#define REG_TWI1_THR                   (0xF0018034U) /**< \brief (TWI1) Transmit Holding Register */
#define REG_TWI1_WPROT_MODE            (0xF00180E4U) /**< \brief (TWI1) Protection Mode Register */
#define REG_TWI1_WPROT_STATUS          (0xF00180E8U) /**< \brief (TWI1) Protection Status Register */
#else
#define REG_TWI1_CR           (*(WoReg*)0xF0018000U) /**< \brief (TWI1) Control Register */
#define REG_TWI1_MMR          (*(RwReg*)0xF0018004U) /**< \brief (TWI1) Master Mode Register */
#define REG_TWI1_SMR          (*(RwReg*)0xF0018008U) /**< \brief (TWI1) Slave Mode Register */
#define REG_TWI1_IADR         (*(RwReg*)0xF001800CU) /**< \brief (TWI1) Internal Address Register */
#define REG_TWI1_CWGR         (*(RwReg*)0xF0018010U) /**< \brief (TWI1) Clock Waveform Generator Register */
#define REG_TWI1_SR           (*(RoReg*)0xF0018020U) /**< \brief (TWI1) Status Register */
#define REG_TWI1_IER          (*(WoReg*)0xF0018024U) /**< \brief (TWI1) Interrupt Enable Register */
#define REG_TWI1_IDR          (*(WoReg*)0xF0018028U) /**< \brief (TWI1) Interrupt Disable Register */
#define REG_TWI1_IMR          (*(RoReg*)0xF001802CU) /**< \brief (TWI1) Interrupt Mask Register */
#define REG_TWI1_RHR          (*(RoReg*)0xF0018030U) /**< \brief (TWI1) Receive Holding Register */
#define REG_TWI1_THR          (*(WoReg*)0xF0018034U) /**< \brief (TWI1) Transmit Holding Register */
#define REG_TWI1_WPROT_MODE   (*(RwReg*)0xF00180E4U) /**< \brief (TWI1) Protection Mode Register */
#define REG_TWI1_WPROT_STATUS (*(RoReg*)0xF00180E8U) /**< \brief (TWI1) Protection Status Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAMA5_TWI1_INSTANCE_ */
>>>>>>> 16c66438 (Upload from PC.)

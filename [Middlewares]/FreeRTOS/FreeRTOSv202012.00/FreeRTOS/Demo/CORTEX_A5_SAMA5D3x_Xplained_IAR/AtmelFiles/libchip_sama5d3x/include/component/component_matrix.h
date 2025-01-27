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

#ifndef _SAMA5_MATRIX_COMPONENT_
#define _SAMA5_MATRIX_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR AHB Bus Matrix */
/* ============================================================================= */
/** \addtogroup SAMA5_MATRIX AHB Bus Matrix */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief MatrixPr hardware registers */
typedef struct {
  RwReg     MATRIX_PRAS;     /**< \brief (MatrixPr Offset: 0x0) Priority Register A for Slave 0 */
  RwReg     MATRIX_PRBS;     /**< \brief (MatrixPr Offset: 0x4) Priority Register B for Slave 0 */
} MatrixPr;
/** \brief Matrix hardware registers */
#define MATRIXPR_NUMBER 16
typedef struct {
  RwReg     MATRIX_MCFG[16]; /**< \brief (Matrix Offset: 0x0000) Master Configuration Register */
  RwReg     MATRIX_SCFG[16]; /**< \brief (Matrix Offset: 0x0040) Slave Configuration Register */
  MatrixPr  MATRIX_PR[MATRIXPR_NUMBER]; /**< \brief (Matrix Offset: 0x0080) 0 .. 15 */
  RwReg     MATRIX_MRCR;     /**< \brief (Matrix Offset: 0x0100) Master Remap Control Register */
  RoReg     Reserved1[3];
  RwReg     MATRIX_SFR[16];  /**< \brief (Matrix Offset: 0x0110) Special Function Register */
  RoReg     Reserved2[37];
  RwReg     MATRIX_WPMR;     /**< \brief (Matrix Offset: 0x01E4) Write Protect Mode Register */
  RoReg     MATRIX_WPSR;     /**< \brief (Matrix Offset: 0x01E8) Write Protect Status Register */
} Matrix;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- MATRIX_MCFG[16] : (MATRIX Offset: 0x0000) Master Configuration Register -------- */
#define MATRIX_MCFG_ULBT_Pos 0
#define MATRIX_MCFG_ULBT_Msk (0x7u << MATRIX_MCFG_ULBT_Pos) /**< \brief (MATRIX_MCFG[16]) Undefined Length Burst Type */
#define MATRIX_MCFG_ULBT(value) ((MATRIX_MCFG_ULBT_Msk & ((value) << MATRIX_MCFG_ULBT_Pos)))
/* -------- MATRIX_SCFG[16] : (MATRIX Offset: 0x0040) Slave Configuration Register -------- */
#define MATRIX_SCFG_SLOT_CYCLE_Pos 0
#define MATRIX_SCFG_SLOT_CYCLE_Msk (0x1ffu << MATRIX_SCFG_SLOT_CYCLE_Pos) /**< \brief (MATRIX_SCFG[16]) Maximum Bus Grant Duration for Masters */
#define MATRIX_SCFG_SLOT_CYCLE(value) ((MATRIX_SCFG_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG_SLOT_CYCLE_Pos)))
#define MATRIX_SCFG_DEFMSTR_TYPE_Pos 16
#define MATRIX_SCFG_DEFMSTR_TYPE_Msk (0x3u << MATRIX_SCFG_DEFMSTR_TYPE_Pos) /**< \brief (MATRIX_SCFG[16]) Default Master Type */
#define MATRIX_SCFG_DEFMSTR_TYPE(value) ((MATRIX_SCFG_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG_DEFMSTR_TYPE_Pos)))
#define MATRIX_SCFG_FIXED_DEFMSTR_Pos 18
#define MATRIX_SCFG_FIXED_DEFMSTR_Msk (0xfu << MATRIX_SCFG_FIXED_DEFMSTR_Pos) /**< \brief (MATRIX_SCFG[16]) Fixed Default Master */
#define MATRIX_SCFG_FIXED_DEFMSTR(value) ((MATRIX_SCFG_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG_FIXED_DEFMSTR_Pos)))
/* -------- MATRIX_PRAS : (MATRIX Offset: N/A) Priority Register A for Slave 0 -------- */
#define MATRIX_PRAS_M0PR_Pos 0
#define MATRIX_PRAS_M0PR_Msk (0x3u << MATRIX_PRAS_M0PR_Pos) /**< \brief (MATRIX_PRAS) Master 0 Priority */
#define MATRIX_PRAS_M0PR(value) ((MATRIX_PRAS_M0PR_Msk & ((value) << MATRIX_PRAS_M0PR_Pos)))
#define MATRIX_PRAS_M1PR_Pos 4
#define MATRIX_PRAS_M1PR_Msk (0x3u << MATRIX_PRAS_M1PR_Pos) /**< \brief (MATRIX_PRAS) Master 1 Priority */
#define MATRIX_PRAS_M1PR(value) ((MATRIX_PRAS_M1PR_Msk & ((value) << MATRIX_PRAS_M1PR_Pos)))
#define MATRIX_PRAS_M2PR_Pos 8
#define MATRIX_PRAS_M2PR_Msk (0x3u << MATRIX_PRAS_M2PR_Pos) /**< \brief (MATRIX_PRAS) Master 2 Priority */
#define MATRIX_PRAS_M2PR(value) ((MATRIX_PRAS_M2PR_Msk & ((value) << MATRIX_PRAS_M2PR_Pos)))
#define MATRIX_PRAS_M3PR_Pos 12
#define MATRIX_PRAS_M3PR_Msk (0x3u << MATRIX_PRAS_M3PR_Pos) /**< \brief (MATRIX_PRAS) Master 3 Priority */
#define MATRIX_PRAS_M3PR(value) ((MATRIX_PRAS_M3PR_Msk & ((value) << MATRIX_PRAS_M3PR_Pos)))
#define MATRIX_PRAS_M4PR_Pos 16
#define MATRIX_PRAS_M4PR_Msk (0x3u << MATRIX_PRAS_M4PR_Pos) /**< \brief (MATRIX_PRAS) Master 4 Priority */
#define MATRIX_PRAS_M4PR(value) ((MATRIX_PRAS_M4PR_Msk & ((value) << MATRIX_PRAS_M4PR_Pos)))
#define MATRIX_PRAS_M5PR_Pos 20
#define MATRIX_PRAS_M5PR_Msk (0x3u << MATRIX_PRAS_M5PR_Pos) /**< \brief (MATRIX_PRAS) Master 5 Priority */
#define MATRIX_PRAS_M5PR(value) ((MATRIX_PRAS_M5PR_Msk & ((value) << MATRIX_PRAS_M5PR_Pos)))
#define MATRIX_PRAS_M6PR_Pos 24
#define MATRIX_PRAS_M6PR_Msk (0x3u << MATRIX_PRAS_M6PR_Pos) /**< \brief (MATRIX_PRAS) Master 6 Priority */
#define MATRIX_PRAS_M6PR(value) ((MATRIX_PRAS_M6PR_Msk & ((value) << MATRIX_PRAS_M6PR_Pos)))
#define MATRIX_PRAS_M7PR_Pos 28
#define MATRIX_PRAS_M7PR_Msk (0x3u << MATRIX_PRAS_M7PR_Pos) /**< \brief (MATRIX_PRAS) Master 7 Priority */
#define MATRIX_PRAS_M7PR(value) ((MATRIX_PRAS_M7PR_Msk & ((value) << MATRIX_PRAS_M7PR_Pos)))
/* -------- MATRIX_PRBS : (MATRIX Offset: N/A) Priority Register B for Slave 0 -------- */
#define MATRIX_PRBS_M8PR_Pos 0
#define MATRIX_PRBS_M8PR_Msk (0x3u << MATRIX_PRBS_M8PR_Pos) /**< \brief (MATRIX_PRBS) Master 8 Priority */
#define MATRIX_PRBS_M8PR(value) ((MATRIX_PRBS_M8PR_Msk & ((value) << MATRIX_PRBS_M8PR_Pos)))
#define MATRIX_PRBS_M9PR_Pos 4
#define MATRIX_PRBS_M9PR_Msk (0x3u << MATRIX_PRBS_M9PR_Pos) /**< \brief (MATRIX_PRBS) Master 9 Priority */
#define MATRIX_PRBS_M9PR(value) ((MATRIX_PRBS_M9PR_Msk & ((value) << MATRIX_PRBS_M9PR_Pos)))
#define MATRIX_PRBS_M10PR_Pos 8
#define MATRIX_PRBS_M10PR_Msk (0x3u << MATRIX_PRBS_M10PR_Pos) /**< \brief (MATRIX_PRBS) Master 10 Priority */
#define MATRIX_PRBS_M10PR(value) ((MATRIX_PRBS_M10PR_Msk & ((value) << MATRIX_PRBS_M10PR_Pos)))
#define MATRIX_PRBS_M11PR_Pos 12
#define MATRIX_PRBS_M11PR_Msk (0x3u << MATRIX_PRBS_M11PR_Pos) /**< \brief (MATRIX_PRBS) Master 11 Priority */
#define MATRIX_PRBS_M11PR(value) ((MATRIX_PRBS_M11PR_Msk & ((value) << MATRIX_PRBS_M11PR_Pos)))
#define MATRIX_PRBS_M12PR_Pos 16
#define MATRIX_PRBS_M12PR_Msk (0x3u << MATRIX_PRBS_M12PR_Pos) /**< \brief (MATRIX_PRBS) Master 12 Priority */
#define MATRIX_PRBS_M12PR(value) ((MATRIX_PRBS_M12PR_Msk & ((value) << MATRIX_PRBS_M12PR_Pos)))
#define MATRIX_PRBS_M13PR_Pos 20
#define MATRIX_PRBS_M13PR_Msk (0x3u << MATRIX_PRBS_M13PR_Pos) /**< \brief (MATRIX_PRBS) Master 13 Priority */
#define MATRIX_PRBS_M13PR(value) ((MATRIX_PRBS_M13PR_Msk & ((value) << MATRIX_PRBS_M13PR_Pos)))
#define MATRIX_PRBS_M14PR_Pos 24
#define MATRIX_PRBS_M14PR_Msk (0x3u << MATRIX_PRBS_M14PR_Pos) /**< \brief (MATRIX_PRBS) Master 14 Priority */
#define MATRIX_PRBS_M14PR(value) ((MATRIX_PRBS_M14PR_Msk & ((value) << MATRIX_PRBS_M14PR_Pos)))
#define MATRIX_PRBS_M15PR_Pos 28
#define MATRIX_PRBS_M15PR_Msk (0x3u << MATRIX_PRBS_M15PR_Pos) /**< \brief (MATRIX_PRBS) Master 15 Priority */
#define MATRIX_PRBS_M15PR(value) ((MATRIX_PRBS_M15PR_Msk & ((value) << MATRIX_PRBS_M15PR_Pos)))
/* -------- MATRIX_MRCR : (MATRIX Offset: 0x0100) Master Remap Control Register -------- */
#define MATRIX_MRCR_RCB0 (0x1u << 0) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB1 (0x1u << 1) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB2 (0x1u << 2) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB3 (0x1u << 3) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB4 (0x1u << 4) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB5 (0x1u << 5) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB6 (0x1u << 6) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB7 (0x1u << 7) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB8 (0x1u << 8) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB9 (0x1u << 9) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB10 (0x1u << 10) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB11 (0x1u << 11) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB12 (0x1u << 12) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB13 (0x1u << 13) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB14 (0x1u << 14) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB15 (0x1u << 15) /**< \brief (MATRIX_MRCR)  */
/* -------- MATRIX_SFR[16] : (MATRIX Offset: 0x0110) Special Function Register -------- */
#define MATRIX_SFR_SFR_Pos 0
#define MATRIX_SFR_SFR_Msk (0xffffffffu << MATRIX_SFR_SFR_Pos) /**< \brief (MATRIX_SFR[16]) Special Function Register Fields */
#define MATRIX_SFR_SFR(value) ((MATRIX_SFR_SFR_Msk & ((value) << MATRIX_SFR_SFR_Pos)))
/* -------- MATRIX_WPMR : (MATRIX Offset: 0x01E4) Write Protect Mode Register -------- */
#define MATRIX_WPMR_WPEN (0x1u << 0) /**< \brief (MATRIX_WPMR) Write Protect Enable */
#define MATRIX_WPMR_WPKEY_Pos 8
#define MATRIX_WPMR_WPKEY_Msk (0xffffffu << MATRIX_WPMR_WPKEY_Pos) /**< \brief (MATRIX_WPMR) Write Protect KEY (Write-only) */
#define MATRIX_WPMR_WPKEY(value) ((MATRIX_WPMR_WPKEY_Msk & ((value) << MATRIX_WPMR_WPKEY_Pos)))
/* -------- MATRIX_WPSR : (MATRIX Offset: 0x01E8) Write Protect Status Register -------- */
#define MATRIX_WPSR_WPVS (0x1u << 0) /**< \brief (MATRIX_WPSR) Write Protect Violation Status */
#define MATRIX_WPSR_WPVSRC_Pos 8
#define MATRIX_WPSR_WPVSRC_Msk (0xffffu << MATRIX_WPSR_WPVSRC_Pos) /**< \brief (MATRIX_WPSR) Write Protect Violation Source */

/*@}*/


#endif /* _SAMA5_MATRIX_COMPONENT_ */
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

#ifndef _SAMA5_MATRIX_COMPONENT_
#define _SAMA5_MATRIX_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR AHB Bus Matrix */
/* ============================================================================= */
/** \addtogroup SAMA5_MATRIX AHB Bus Matrix */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief MatrixPr hardware registers */
typedef struct {
  RwReg     MATRIX_PRAS;     /**< \brief (MatrixPr Offset: 0x0) Priority Register A for Slave 0 */
  RwReg     MATRIX_PRBS;     /**< \brief (MatrixPr Offset: 0x4) Priority Register B for Slave 0 */
} MatrixPr;
/** \brief Matrix hardware registers */
#define MATRIXPR_NUMBER 16
typedef struct {
  RwReg     MATRIX_MCFG[16]; /**< \brief (Matrix Offset: 0x0000) Master Configuration Register */
  RwReg     MATRIX_SCFG[16]; /**< \brief (Matrix Offset: 0x0040) Slave Configuration Register */
  MatrixPr  MATRIX_PR[MATRIXPR_NUMBER]; /**< \brief (Matrix Offset: 0x0080) 0 .. 15 */
  RwReg     MATRIX_MRCR;     /**< \brief (Matrix Offset: 0x0100) Master Remap Control Register */
  RoReg     Reserved1[3];
  RwReg     MATRIX_SFR[16];  /**< \brief (Matrix Offset: 0x0110) Special Function Register */
  RoReg     Reserved2[37];
  RwReg     MATRIX_WPMR;     /**< \brief (Matrix Offset: 0x01E4) Write Protect Mode Register */
  RoReg     MATRIX_WPSR;     /**< \brief (Matrix Offset: 0x01E8) Write Protect Status Register */
} Matrix;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- MATRIX_MCFG[16] : (MATRIX Offset: 0x0000) Master Configuration Register -------- */
#define MATRIX_MCFG_ULBT_Pos 0
#define MATRIX_MCFG_ULBT_Msk (0x7u << MATRIX_MCFG_ULBT_Pos) /**< \brief (MATRIX_MCFG[16]) Undefined Length Burst Type */
#define MATRIX_MCFG_ULBT(value) ((MATRIX_MCFG_ULBT_Msk & ((value) << MATRIX_MCFG_ULBT_Pos)))
/* -------- MATRIX_SCFG[16] : (MATRIX Offset: 0x0040) Slave Configuration Register -------- */
#define MATRIX_SCFG_SLOT_CYCLE_Pos 0
#define MATRIX_SCFG_SLOT_CYCLE_Msk (0x1ffu << MATRIX_SCFG_SLOT_CYCLE_Pos) /**< \brief (MATRIX_SCFG[16]) Maximum Bus Grant Duration for Masters */
#define MATRIX_SCFG_SLOT_CYCLE(value) ((MATRIX_SCFG_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG_SLOT_CYCLE_Pos)))
#define MATRIX_SCFG_DEFMSTR_TYPE_Pos 16
#define MATRIX_SCFG_DEFMSTR_TYPE_Msk (0x3u << MATRIX_SCFG_DEFMSTR_TYPE_Pos) /**< \brief (MATRIX_SCFG[16]) Default Master Type */
#define MATRIX_SCFG_DEFMSTR_TYPE(value) ((MATRIX_SCFG_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG_DEFMSTR_TYPE_Pos)))
#define MATRIX_SCFG_FIXED_DEFMSTR_Pos 18
#define MATRIX_SCFG_FIXED_DEFMSTR_Msk (0xfu << MATRIX_SCFG_FIXED_DEFMSTR_Pos) /**< \brief (MATRIX_SCFG[16]) Fixed Default Master */
#define MATRIX_SCFG_FIXED_DEFMSTR(value) ((MATRIX_SCFG_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG_FIXED_DEFMSTR_Pos)))
/* -------- MATRIX_PRAS : (MATRIX Offset: N/A) Priority Register A for Slave 0 -------- */
#define MATRIX_PRAS_M0PR_Pos 0
#define MATRIX_PRAS_M0PR_Msk (0x3u << MATRIX_PRAS_M0PR_Pos) /**< \brief (MATRIX_PRAS) Master 0 Priority */
#define MATRIX_PRAS_M0PR(value) ((MATRIX_PRAS_M0PR_Msk & ((value) << MATRIX_PRAS_M0PR_Pos)))
#define MATRIX_PRAS_M1PR_Pos 4
#define MATRIX_PRAS_M1PR_Msk (0x3u << MATRIX_PRAS_M1PR_Pos) /**< \brief (MATRIX_PRAS) Master 1 Priority */
#define MATRIX_PRAS_M1PR(value) ((MATRIX_PRAS_M1PR_Msk & ((value) << MATRIX_PRAS_M1PR_Pos)))
#define MATRIX_PRAS_M2PR_Pos 8
#define MATRIX_PRAS_M2PR_Msk (0x3u << MATRIX_PRAS_M2PR_Pos) /**< \brief (MATRIX_PRAS) Master 2 Priority */
#define MATRIX_PRAS_M2PR(value) ((MATRIX_PRAS_M2PR_Msk & ((value) << MATRIX_PRAS_M2PR_Pos)))
#define MATRIX_PRAS_M3PR_Pos 12
#define MATRIX_PRAS_M3PR_Msk (0x3u << MATRIX_PRAS_M3PR_Pos) /**< \brief (MATRIX_PRAS) Master 3 Priority */
#define MATRIX_PRAS_M3PR(value) ((MATRIX_PRAS_M3PR_Msk & ((value) << MATRIX_PRAS_M3PR_Pos)))
#define MATRIX_PRAS_M4PR_Pos 16
#define MATRIX_PRAS_M4PR_Msk (0x3u << MATRIX_PRAS_M4PR_Pos) /**< \brief (MATRIX_PRAS) Master 4 Priority */
#define MATRIX_PRAS_M4PR(value) ((MATRIX_PRAS_M4PR_Msk & ((value) << MATRIX_PRAS_M4PR_Pos)))
#define MATRIX_PRAS_M5PR_Pos 20
#define MATRIX_PRAS_M5PR_Msk (0x3u << MATRIX_PRAS_M5PR_Pos) /**< \brief (MATRIX_PRAS) Master 5 Priority */
#define MATRIX_PRAS_M5PR(value) ((MATRIX_PRAS_M5PR_Msk & ((value) << MATRIX_PRAS_M5PR_Pos)))
#define MATRIX_PRAS_M6PR_Pos 24
#define MATRIX_PRAS_M6PR_Msk (0x3u << MATRIX_PRAS_M6PR_Pos) /**< \brief (MATRIX_PRAS) Master 6 Priority */
#define MATRIX_PRAS_M6PR(value) ((MATRIX_PRAS_M6PR_Msk & ((value) << MATRIX_PRAS_M6PR_Pos)))
#define MATRIX_PRAS_M7PR_Pos 28
#define MATRIX_PRAS_M7PR_Msk (0x3u << MATRIX_PRAS_M7PR_Pos) /**< \brief (MATRIX_PRAS) Master 7 Priority */
#define MATRIX_PRAS_M7PR(value) ((MATRIX_PRAS_M7PR_Msk & ((value) << MATRIX_PRAS_M7PR_Pos)))
/* -------- MATRIX_PRBS : (MATRIX Offset: N/A) Priority Register B for Slave 0 -------- */
#define MATRIX_PRBS_M8PR_Pos 0
#define MATRIX_PRBS_M8PR_Msk (0x3u << MATRIX_PRBS_M8PR_Pos) /**< \brief (MATRIX_PRBS) Master 8 Priority */
#define MATRIX_PRBS_M8PR(value) ((MATRIX_PRBS_M8PR_Msk & ((value) << MATRIX_PRBS_M8PR_Pos)))
#define MATRIX_PRBS_M9PR_Pos 4
#define MATRIX_PRBS_M9PR_Msk (0x3u << MATRIX_PRBS_M9PR_Pos) /**< \brief (MATRIX_PRBS) Master 9 Priority */
#define MATRIX_PRBS_M9PR(value) ((MATRIX_PRBS_M9PR_Msk & ((value) << MATRIX_PRBS_M9PR_Pos)))
#define MATRIX_PRBS_M10PR_Pos 8
#define MATRIX_PRBS_M10PR_Msk (0x3u << MATRIX_PRBS_M10PR_Pos) /**< \brief (MATRIX_PRBS) Master 10 Priority */
#define MATRIX_PRBS_M10PR(value) ((MATRIX_PRBS_M10PR_Msk & ((value) << MATRIX_PRBS_M10PR_Pos)))
#define MATRIX_PRBS_M11PR_Pos 12
#define MATRIX_PRBS_M11PR_Msk (0x3u << MATRIX_PRBS_M11PR_Pos) /**< \brief (MATRIX_PRBS) Master 11 Priority */
#define MATRIX_PRBS_M11PR(value) ((MATRIX_PRBS_M11PR_Msk & ((value) << MATRIX_PRBS_M11PR_Pos)))
#define MATRIX_PRBS_M12PR_Pos 16
#define MATRIX_PRBS_M12PR_Msk (0x3u << MATRIX_PRBS_M12PR_Pos) /**< \brief (MATRIX_PRBS) Master 12 Priority */
#define MATRIX_PRBS_M12PR(value) ((MATRIX_PRBS_M12PR_Msk & ((value) << MATRIX_PRBS_M12PR_Pos)))
#define MATRIX_PRBS_M13PR_Pos 20
#define MATRIX_PRBS_M13PR_Msk (0x3u << MATRIX_PRBS_M13PR_Pos) /**< \brief (MATRIX_PRBS) Master 13 Priority */
#define MATRIX_PRBS_M13PR(value) ((MATRIX_PRBS_M13PR_Msk & ((value) << MATRIX_PRBS_M13PR_Pos)))
#define MATRIX_PRBS_M14PR_Pos 24
#define MATRIX_PRBS_M14PR_Msk (0x3u << MATRIX_PRBS_M14PR_Pos) /**< \brief (MATRIX_PRBS) Master 14 Priority */
#define MATRIX_PRBS_M14PR(value) ((MATRIX_PRBS_M14PR_Msk & ((value) << MATRIX_PRBS_M14PR_Pos)))
#define MATRIX_PRBS_M15PR_Pos 28
#define MATRIX_PRBS_M15PR_Msk (0x3u << MATRIX_PRBS_M15PR_Pos) /**< \brief (MATRIX_PRBS) Master 15 Priority */
#define MATRIX_PRBS_M15PR(value) ((MATRIX_PRBS_M15PR_Msk & ((value) << MATRIX_PRBS_M15PR_Pos)))
/* -------- MATRIX_MRCR : (MATRIX Offset: 0x0100) Master Remap Control Register -------- */
#define MATRIX_MRCR_RCB0 (0x1u << 0) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB1 (0x1u << 1) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB2 (0x1u << 2) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB3 (0x1u << 3) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB4 (0x1u << 4) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB5 (0x1u << 5) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB6 (0x1u << 6) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB7 (0x1u << 7) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB8 (0x1u << 8) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB9 (0x1u << 9) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB10 (0x1u << 10) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB11 (0x1u << 11) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB12 (0x1u << 12) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB13 (0x1u << 13) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB14 (0x1u << 14) /**< \brief (MATRIX_MRCR)  */
#define MATRIX_MRCR_RCB15 (0x1u << 15) /**< \brief (MATRIX_MRCR)  */
/* -------- MATRIX_SFR[16] : (MATRIX Offset: 0x0110) Special Function Register -------- */
#define MATRIX_SFR_SFR_Pos 0
#define MATRIX_SFR_SFR_Msk (0xffffffffu << MATRIX_SFR_SFR_Pos) /**< \brief (MATRIX_SFR[16]) Special Function Register Fields */
#define MATRIX_SFR_SFR(value) ((MATRIX_SFR_SFR_Msk & ((value) << MATRIX_SFR_SFR_Pos)))
/* -------- MATRIX_WPMR : (MATRIX Offset: 0x01E4) Write Protect Mode Register -------- */
#define MATRIX_WPMR_WPEN (0x1u << 0) /**< \brief (MATRIX_WPMR) Write Protect Enable */
#define MATRIX_WPMR_WPKEY_Pos 8
#define MATRIX_WPMR_WPKEY_Msk (0xffffffu << MATRIX_WPMR_WPKEY_Pos) /**< \brief (MATRIX_WPMR) Write Protect KEY (Write-only) */
#define MATRIX_WPMR_WPKEY(value) ((MATRIX_WPMR_WPKEY_Msk & ((value) << MATRIX_WPMR_WPKEY_Pos)))
/* -------- MATRIX_WPSR : (MATRIX Offset: 0x01E8) Write Protect Status Register -------- */
#define MATRIX_WPSR_WPVS (0x1u << 0) /**< \brief (MATRIX_WPSR) Write Protect Violation Status */
#define MATRIX_WPSR_WPVSRC_Pos 8
#define MATRIX_WPSR_WPVSRC_Msk (0xffffu << MATRIX_WPSR_WPVSRC_Pos) /**< \brief (MATRIX_WPSR) Write Protect Violation Source */

/*@}*/


#endif /* _SAMA5_MATRIX_COMPONENT_ */
>>>>>>> 16c66438 (Upload from PC.)

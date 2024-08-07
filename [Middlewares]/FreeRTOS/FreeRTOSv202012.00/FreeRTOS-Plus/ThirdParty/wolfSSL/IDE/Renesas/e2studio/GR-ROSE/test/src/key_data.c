<<<<<<< HEAD
/* key_data.c
 *
 * Copyright (C) 2006-2020 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */


#include "key_data.h"

/*-------------------------------------------------------------------------
      TSIP v1.09
--------------------------------------------------------------------------*/
#if defined(WOLFSSL_RENESAS_TSIP_TLS) && (WOLFSSL_RENESAS_TSIP_VER >=109)

/* Key type of the encrypted user_public_key 0: RSA-2048 2: ECDSA-P256*/
const uint32_t              encrypted_user_key_type = 0;

const st_key_block_data_t g_key_block_data =
{
    /* uint8_t encrypted_provisioning_key[R_TSIP_AES_CBC_IV_BYTE_SIZE * 2]; */
   {
      0xE9,0x67,0x79,0xF7,0x38,0x73,0xC8,0x59,0x94,0x62,0x7D,0xB9,0x83,0xDE,0x59,0x4A,
      0x92,0x53,0x6B,0x14,0x1B,0x2A,0x99,0xDF,0x95,0xFD,0x35,0x84,0x93,0xCE, 0xDB,0x10
    },
    /* uint8_t iv[R_TSIP_AES_CBC_IV_BYTE_SIZE]; */
    {
        0xF6, 0xA9, 0x83, 0x5A, 0xA1, 0x65, 0x1D, 0x28, 0xC8, 0x1A, 0xA6, 0x9D, 0x34, 0xB2, 0x4D, 0x92
    },
    /* uint8_t encrypted_user_rsa2048_ne_key[R_TSIP_RSA2048_NE_KEY_BYTE_SIZE + 16]; */
    {
        0x34, 0x59, 0xFF, 0xFE, 0xAA, 0xE9, 0x26, 0x60, 0x8C, 0xB8, 0x76, 0xD2, 0x98, 0x65, 0x72, 0x3B,
        0x19, 0x78, 0xB8, 0x9B, 0x0D, 0xD4, 0xFC, 0x2A, 0xF8, 0x54, 0x3B, 0x75, 0x0E, 0x40, 0x21, 0xF5,
        0xF2, 0x6D, 0x3F, 0x60, 0xD2, 0xDF, 0xE7, 0xDB, 0x67, 0xF1, 0xC7, 0x66, 0x5F, 0x37, 0xAF, 0x9D,
        0x08, 0xE7, 0xFD, 0xEF, 0x63, 0xA9, 0x78, 0x73, 0x1A, 0xE2, 0x47, 0x91, 0xB5, 0xA0, 0xCE, 0xA2,
        0xC7, 0x4F, 0x8A, 0xE5, 0x03, 0x6F, 0xC5, 0xB8, 0xC4, 0x40, 0x12, 0x2D, 0x37, 0x2F, 0xF2, 0xC5,
        0x73, 0x2D, 0xF8, 0xBF, 0x4A, 0xDC, 0xB7, 0x98, 0xDF, 0xE8, 0xED, 0xF8, 0x3B, 0x24, 0x8A, 0x01,
        0xAE, 0x64, 0x89, 0x9C, 0x79, 0x66, 0x99, 0xE4, 0xF8, 0xC1, 0x3E, 0x04, 0x56, 0x1E, 0x6E, 0xBA,
        0x2D, 0xAA, 0xB9, 0xE8, 0xA0, 0xC2, 0x27, 0xCF, 0x7C, 0x0F, 0xAD, 0x0A, 0x22, 0xEE, 0x61, 0xA8,
        0x32, 0xBE, 0xEE, 0xE7, 0x3F, 0x5D, 0xE5, 0xBD, 0x75, 0x6B, 0x35, 0xC1, 0x77, 0xCC, 0x7D, 0x0E,
        0x2E, 0x26, 0x67, 0xC4, 0x0E, 0x84, 0x34, 0xBD, 0x33, 0xB3, 0x0C, 0xD9, 0x07, 0xE5, 0x8E, 0x3E,
        0x7E, 0xCC, 0x56, 0x5D, 0x23, 0x5A, 0x96, 0x83, 0x0C, 0xD9, 0x7F, 0xB0, 0xF7, 0x53, 0xD9, 0x5C,
        0xE2, 0x1B, 0xDA, 0x63, 0x62, 0x19, 0x16, 0x9D, 0x75, 0x7B, 0xBB, 0x7E, 0xC9, 0xB5, 0xAD, 0x7D,
        0xBB, 0x5A, 0xFA, 0xA5, 0x5B, 0x54, 0xA1, 0x93, 0x6D, 0x53, 0x3C, 0x85, 0x69, 0x00, 0x15, 0x40,
        0x0E, 0x54, 0xD2, 0xBA, 0xB5, 0x80, 0x1C, 0x25, 0x85, 0x0E, 0x60, 0x87, 0x2A, 0x1A, 0xE7, 0x60,
        0xCB, 0x6A, 0xF5, 0xAF, 0x84, 0x4B, 0xB7, 0x0D, 0x0C, 0xC0, 0xB5, 0x02, 0xB2, 0x38, 0x9D, 0x7C,
        0xFA, 0x31, 0xF3, 0x50, 0xB3, 0x32, 0x69, 0x3A, 0x3C, 0x7A, 0xA5, 0x67, 0x19, 0x66, 0xD5, 0x62,
        0xA3, 0xF2, 0xF7, 0x77, 0x73, 0xF6, 0xE7, 0x8D, 0x51, 0x0C, 0x19, 0xA3, 0x0F, 0x8C, 0x79, 0xE0,
        0x7C, 0xCF, 0x8A, 0x03, 0x70, 0xC7, 0x25, 0x9D, 0xCE, 0x89, 0x77, 0x8E, 0x4C, 0xE6, 0x97, 0xC8
    },
    /* uint8_t encrypted_user_update_key[R_TSIP_AES256_KEY_BYTE_SIZE + 16]; */
    {
        0x69, 0xDB, 0xC6, 0x86, 0xA5, 0x06, 0x22, 0x59, 0x11, 0x14, 0x73, 0x56, 0x3A, 0x9E, 0x44, 0xC3,
        0x9C, 0xA8, 0x76, 0xC6, 0xF6, 0xE8, 0xD8, 0xE2, 0x17, 0x66, 0x90, 0x65, 0x08, 0xB5, 0x39, 0x7F,
        0xD5, 0xC5, 0x6F, 0xD1, 0xCB, 0xFB, 0xB2, 0x76, 0x33, 0xA1, 0x22, 0x0F, 0xBE, 0x83, 0x91, 0x24
    },
};


/* ./ca-cert.der.sign,  */
const unsigned char ca_cert_sig[] =
{
    0x25,0x7B,0x10,0x4D,0xAF,0xB1,0xC1,0x50,0x7B,0x63,0x17,0xA0,0x38,0xA7,0x03,0x44,
    0x7A,0x7E,0x8D,0x3D,0x38,0xEE,0x4B,0xE4,0xB2,0x48,0x76,0x07,0xF8,0x06,0xB1,0x9D,
    0xBB,0xD1,0x46,0xB5,0xF9,0x86,0x08,0x85,0x29,0x6F,0xED,0x26,0x2F,0x91,0x7B,0x2B,
    0x36,0xAC,0x7E,0x56,0x2D,0x2B,0x8E,0x81,0x1B,0x3C,0xFA,0x08,0x80,0x05,0x01,0xC1,
    0xF3,0x71,0xFE,0xE9,0x59,0xA7,0xB6,0x82,0x62,0x04,0xA5,0xE4,0x6E,0xC9,0x32,0xCC,
    0xB1,0x19,0xBC,0xDE,0x6A,0x9B,0xEB,0x60,0x92,0xC5,0x46,0xB7,0xFF,0xF4,0xC1,0x77,
    0x5A,0xF4,0x53,0x41,0x6A,0x44,0x8B,0x46,0x3B,0xBE,0x74,0xBA,0x62,0xAF,0xFF,0xF2,
    0x32,0xCD,0x7A,0x97,0xE1,0xA8,0xBF,0x62,0x76,0xDA,0xBF,0x93,0x8B,0x1E,0x87,0xCC,
    0xEE,0x5D,0xCF,0xE9,0xBE,0xA6,0x25,0x6C,0xC4,0x92,0x2E,0x69,0x29,0x8F,0xCD,0x4C,
    0x07,0x91,0x20,0xD1,0x16,0xF9,0x6A,0x23,0xC8,0x5E,0xD4,0x7C,0x38,0xA2,0x80,0xCB,
    0x59,0x32,0xDD,0x28,0x46,0x6E,0x19,0xE9,0xAD,0x68,0x2B,0x0C,0xA0,0xB5,0x2A,0x8F,
    0x73,0xC2,0xED,0xF2,0x60,0x4F,0xF3,0xCE,0xDC,0x1B,0xA7,0x88,0x66,0x42,0xF0,0xFD,
    0x9D,0x77,0x2C,0x04,0xC2,0x54,0x4C,0x1D,0x58,0x9E,0x6D,0x4E,0x21,0x73,0x7E,0x1A,
    0x2A,0xDC,0x54,0x24,0x66,0x63,0xBA,0xF1,0xF8,0x16,0xE7,0x29,0xB2,0x01,0x98,0xE5,
    0x49,0x6E,0x97,0x86,0x82,0x6C,0xF3,0x3B,0x54,0x57,0x2C,0xD8,0x8F,0xC5,0x70,0x3E,
    0x22,0xD7,0x6D,0x9F,0x27,0xEC,0xD6,0x12,0xE5,0x4F,0x1E,0x05,0x36,0x07,0xBA,0xB2
};
const int sizeof_ca_cert_sig = sizeof(ca_cert_sig);

/* ./client-cert.der.sign,  */
const unsigned char client_cert_der_sign[] =
{
        0x5D, 0x1F, 0x89, 0x41, 0xEC, 0x47, 0xC8, 0x90, 0x61, 0x79,
        0x8A, 0x16, 0x1F, 0x31, 0x96, 0x67, 0xD9, 0x3C, 0xEC, 0x6B,
        0x58, 0xC6, 0x5A, 0xED, 0x99, 0xB3, 0xEF, 0x27, 0x6F, 0x04,
        0x8C, 0xD9, 0x68, 0xB1, 0xD6, 0x23, 0x15, 0x84, 0x00, 0xE1,
        0x27, 0xD1, 0x1F, 0x68, 0xB7, 0x3F, 0x13, 0x53, 0x8A, 0x95,
        0x5A, 0x20, 0x7C, 0xB2, 0x76, 0x5B, 0xDC, 0xE0, 0xA6, 0x21,
        0x7C, 0x49, 0xCF, 0x93, 0xBA, 0xD5, 0x12, 0x9F, 0xEE, 0x90,
        0x5B, 0x3F, 0xA3, 0x9D, 0x13, 0x72, 0xAC, 0x72, 0x16, 0xFE,
        0x1D, 0xBE, 0xEB, 0x8E, 0xC7, 0xDC, 0xC4, 0xF8, 0x1A, 0xD8,
        0xA0, 0xA4, 0xF6, 0x04, 0x30, 0xF6, 0x7E, 0xB6, 0xC8, 0xE1,
        0xAB, 0x88, 0x37, 0x08, 0x63, 0x72, 0xAA, 0x46, 0xCC, 0xCA,
        0xF0, 0x9E, 0x02, 0x1E, 0x65, 0x67, 0xFF, 0x2C, 0x9D, 0x81,
        0x6C, 0x1E, 0xF1, 0x54, 0x05, 0x68, 0x68, 0x18, 0x72, 0x26,
        0x55, 0xB6, 0x2C, 0x95, 0xC0, 0xC9, 0xB2, 0xA7, 0x0B, 0x60,
        0xD7, 0xEB, 0x1D, 0x08, 0x1A, 0xA2, 0x54, 0x15, 0x89, 0xCB,
        0x83, 0x21, 0x5D, 0x15, 0x9B, 0x38, 0xAC, 0x89, 0x63, 0xD5,
        0x4B, 0xF4, 0x8B, 0x47, 0x93, 0x78, 0x43, 0xCB, 0x9B, 0x71,
        0xBF, 0x94, 0x76, 0xB5, 0xCE, 0x35, 0xA9, 0x1A, 0xD5, 0xA5,
        0xD8, 0x19, 0xA6, 0x04, 0x39, 0xB1, 0x09, 0x8C, 0x65, 0x02,
        0x58, 0x3A, 0x95, 0xEF, 0xA2, 0xC3, 0x85, 0x18, 0x61, 0x23,
        0x2D, 0xC5, 0xCD, 0x62, 0xC1, 0x19, 0x31, 0xE5, 0x36, 0x95,
        0x22, 0xDB, 0x3E, 0x1A, 0x3C, 0xE8, 0xC6, 0x2E, 0xDF, 0xD9,
        0x2F, 0x84, 0xC1, 0xF0, 0x38, 0x2B, 0xE5, 0x73, 0x35, 0x4F,
        0x05, 0xE2, 0xA5, 0x60, 0x79, 0xB0, 0x23, 0xDC, 0x56, 0x4C,
        0xE7, 0xD9, 0x1F, 0xCF, 0x6A, 0xFC, 0x55, 0xEB, 0xAA, 0x48,
        0x3E, 0x95, 0x2A, 0x10, 0x01, 0x05
};
const int sizeof_client_cert_der_sign = sizeof(client_cert_der_sign);

uint32_t s_inst1[R_TSIP_SINST_WORD_SIZE] = { 0 };
uint32_t s_inst2[R_TSIP_SINST2_WORD_SIZE]= { 0 };


/*-------------------------------------------------------------------------
      TSIP v1.06
--------------------------------------------------------------------------*/
#elif	defined(WOLFSSL_RENESAS_TSIP_TLS) && (WOLFSSL_RENESAS_TSIP_VER >= 106)

const st_key_block_data_t g_key_block_data =
{

   /* uint8_t encrypted_session_key[R_TSIP_AES_CBC_IV_BYTE_SIZE * 2]; */
   {
      0xCE, 0xE0, 0xE9, 0x86, 0x62, 0x59, 0xF9, 0x8F, 0x3C, 0xFB, 0x81, 0x39, 0xC2, 0x82, 0xC7, 0xC9,
      0xCD, 0xEA, 0x6B, 0x16, 0x66, 0x77, 0x38, 0xCA, 0xF5, 0x6E, 0x6D, 0x5B, 0xF0, 0x30, 0xA2, 0x94
   },
   /* uint8_t iv[R_TSIP_AES_CBC_IV_BYTE_SIZE]; */
   {
      0xF6, 0xA9, 0x83, 0x5A, 0xA1, 0x65, 0x1D, 0x28, 0xC8, 0x1A, 0xA6, 0x9D, 0x34, 0xB2, 0x4D, 0x92
   },
   /* uint8_t encrypted_user_rsa2048_ne_key[R_TSIP_RSA2048_NE_KEY_BYTE_SIZE + 16]; */
   {
      0xFC, 0xB4, 0x0F, 0x72, 0xFE, 0xB4, 0xB1, 0xF7, 0xDB, 0xA7, 0x49, 0x9E, 0x0F, 0xF6, 0x4B, 0xA7,
      0x08, 0x0D, 0x3A, 0xFD, 0xAB, 0x7D, 0x82, 0xD7, 0x26, 0x36, 0xFC, 0xED, 0x3E, 0x53, 0xBC, 0xA1,
      0x3D, 0x75, 0x03, 0x5B, 0x53, 0x6D, 0x63, 0xBB, 0xB0, 0x9A, 0xD7, 0xEB, 0x7C, 0x99, 0x3B, 0xE4,
      0xB7, 0xA3, 0x83, 0xE7, 0x27, 0xBE, 0x88, 0x06, 0x2B, 0x81, 0x66, 0xF8, 0x94, 0x3E, 0x86, 0x02,
      0x5F, 0x97, 0x05, 0xFD, 0x93, 0x78, 0x06, 0x3A, 0xC6, 0xD0, 0x3A, 0x82, 0x5D, 0x10, 0xC4, 0xE3,
      0x30, 0x68, 0x48, 0x25, 0x31, 0xCD, 0x50, 0xBC, 0x91, 0xAF, 0x00, 0x4B, 0xAA, 0x6E, 0x3F, 0x6E,
      0x7F, 0x6A, 0x43, 0xAB, 0xB7, 0x06, 0x8D, 0x05, 0x1D, 0x26, 0x17, 0xE9, 0xD9, 0x72, 0x35, 0xED,
      0x79, 0x13, 0xEB, 0x57, 0xED, 0x33, 0x3B, 0x9B, 0x75, 0x15, 0xAB, 0x13, 0xEE, 0xDB, 0xCC, 0x9F,
      0x78, 0xF0, 0x51, 0x67, 0x53, 0xC2, 0xC3, 0xEF, 0xB1, 0x16, 0x39, 0xCB, 0x24, 0x5D, 0x11, 0x43,
      0x3F, 0xDC, 0x90, 0xD2, 0xA9, 0x4B, 0x6C, 0x9C, 0xBC, 0x77, 0x7B, 0xA4, 0x02, 0x8A, 0xB3, 0x7A,
      0x99, 0x75, 0x76, 0x86, 0xE2, 0xEA, 0x83, 0x8D, 0x07, 0xB0, 0xF1, 0xF0, 0x6E, 0x21, 0x19, 0x2E,
      0x16, 0x6B, 0xA3, 0x81, 0xB2, 0xE6, 0x29, 0x16, 0xAA, 0xBC, 0x43, 0x73, 0x1C, 0xC4, 0xDB, 0x92,
      0x2A, 0xA9, 0x20, 0x37, 0x64, 0x4C, 0xE1, 0x95, 0x91, 0x8C, 0x1E, 0xCD, 0xA3, 0xFE, 0x8B, 0x23,
      0x89, 0x2B, 0x6D, 0xA8, 0x6D, 0xD1, 0x7C, 0x20, 0xB9, 0x32, 0xA3, 0x0C, 0x8A, 0x5E, 0xE8, 0x7B,
      0xC8, 0x32, 0xA2, 0x81, 0x30, 0x7D, 0x21, 0x56, 0x97, 0x9C, 0x0C, 0x68, 0xAD, 0xFD, 0x6D, 0xFD,
      0xE0, 0x04, 0xE5, 0xB3, 0xC7, 0xED, 0x84, 0xCB, 0xD4, 0xB0, 0x84, 0x09, 0x99, 0xC3, 0xFB, 0x8B,
      0x91, 0x55, 0x2C, 0xCB, 0x48, 0x06, 0xD1, 0x6C, 0xE0, 0x42, 0x13, 0xDF, 0x2B, 0x73, 0x25, 0xB3,
      0x15, 0xC5, 0x8A, 0xDF, 0x01, 0x2B, 0x96, 0x01, 0x95, 0x84, 0xE4, 0x8E, 0xBA, 0x32, 0xCB, 0x77
    },
};

const uint32_t s_flash[] =
{
    0xa6f0651c, 0xa17c5a15, 0xa23e1bfb, 0xc04e1bb9,
    0x5594fc81, 0x67fad158, 0xfda808ae, 0x7e01cb88,
    0xbf12d558, 0x9ec08adc, 0x21c25af2, 0x60d43062,
    0x82e6b470, 0x178879a6, 0x9ddb263f, 0xddb57b53,
    0x220ea793, 0x24de7b88, 0x9fa846e4, 0xdf9059f9,
    0x7ce55a19, 0x686689e5, 0x9aaef400, 0x88fd178a,
    0xf4e33b46, 0xc9394a88, 0x712823b9, 0xca75513f,
    0x63859e61, 0x45477873, 0x357b5776, 0x83cc1def,
    0x74cb65ab, 0xa919863c, 0x9f75e62e, 0x5fd62143,
    0xdbae440a, 0x34053525, 0x56e221e1, 0x8ffbaeb5,
    0xa75c55f0, 0x34727e44, 0x2c791463, 0x7670923f,
    0xc0287d97, 0x0a09b5c9, 0xfaecf18e, 0x09ceab85,
    0x687ad46f, 0x7e4d8adb, 0x6def5893, 0x6f236da3,
    0xab6e15e1, 0x653f41d0, 0x05652571, 0x9ec8ec15,
    0x2d4acb06, 0x7d5c2c26, 0xf49455cb, 0x9872dc50,
    0xb9fe50a2, 0x34bf45ae, 0x4cf2b6bf, 0xe1c75c7b,
    0x6e23718f, 0x227b0a55, 0x3a5e8b00, 0x83222dba,
    0x4041008f, 0x40fc8d01, 0xcd6c5c64, 0x0b8183b5,
    0x678bf9e7, 0x57844b52, 0xb4c81735, 0x559e77f3,
    0xb2b6800e, 0x715de4e2, 0x7a2720bb, 0x7b434710,
    0xee264103, 0x9db8c751, 0x78291c62, 0x77b883f4,
    0xa27d1216, 0x4e733ba6, 0x8a5f40dc, 0x32d2dd82,
    0x8a5fdc67, 0xd8fb0926, 0x9d5aec51, 0x08bfce4d,
    0x2a54839b, 0xe6601069, 0x564fbdbf, 0x9bb43dc7,
    0x9bb59d3a, 0xc3aaa60c, 0x2f2e75d7, 0x6a953972,
    0x6de4fd23, 0x546c212b, 0xe8aad33f, 0xca416c37,
    0xa74b36f9, 0x520330f0, 0x96145828, 0x09c21110,
    0x0b29365a, 0xfe9a9e60, 0x82b3a215, 0x752daa46,
    0x45bd59d6, 0x145ba47f, 0x75e40f92, 0x2f904860,
    0x609e3b0a, 0x8e6e6aa8, 0xe88ea1c3, 0x22a1db60,
    0x9947e0c7, 0x28416ca7, 0x3cb6abe6, 0x0e367da7,
    0x17b16976, 0x5323ccde, 0xc7337459, 0xf07293ad,
};

/* ./ca-cert.der.sign,  */
const unsigned char ca_cert_sig[] =
{
        0x86, 0xD6, 0xC5, 0xB0, 0xE1, 0x37, 0x4C, 0x21, 0xF7, 0x8D,
        0x7C, 0x36, 0x80, 0xDB, 0x51, 0x58, 0x9D, 0x32, 0x5A, 0x1C,
        0xF3, 0xAC, 0x24, 0x17, 0xD4, 0x61, 0x9F, 0x09, 0x73, 0xA0,
        0x1E, 0x30, 0xE7, 0x6F, 0x00, 0xF8, 0xDB, 0xAA, 0x34, 0x4E,
        0x96, 0xA3, 0x3D, 0xBC, 0xE8, 0xFF, 0xBE, 0x4E, 0x62, 0x70,
        0x7B, 0xC7, 0x65, 0x2E, 0x9D, 0x1C, 0xE1, 0x5A, 0x7C, 0x2B,
        0xCD, 0x57, 0xEA, 0xF4, 0x16, 0xBC, 0x47, 0x26, 0xF5, 0x41,
        0x1F, 0x4E, 0xFD, 0xA5, 0x65, 0xAE, 0x31, 0xEB, 0xDF, 0x10,
        0xAF, 0xCB, 0xCB, 0x27, 0x84, 0xB6, 0x59, 0x3C, 0x6B, 0x9B,
        0x68, 0xAF, 0xEF, 0x35, 0xAF, 0x59, 0x9B, 0x07, 0x69, 0x75,
        0x1A, 0x99, 0x92, 0x0F, 0x0D, 0x02, 0x5A, 0x2C, 0x14, 0xD5,
        0x38, 0x8B, 0xD2, 0xB5, 0x35, 0xC7, 0x2D, 0xEB, 0x97, 0x4C,
        0xC8, 0x53, 0xCF, 0x7C, 0x0C, 0xB3, 0x00, 0x90, 0x99, 0x0B,
        0xB1, 0xBE, 0x8B, 0xEA, 0x96, 0xB4, 0x75, 0x35, 0x9D, 0xA1,
        0x2E, 0xF3, 0xF3, 0xEA, 0xF5, 0x7B, 0x83, 0xEF, 0x03, 0x06,
        0x3C, 0x41, 0x1C, 0x32, 0x84, 0x4A, 0xB8, 0xB0, 0xAE, 0x67,
        0xE9, 0xE4, 0xEE, 0x58, 0x43, 0x0C, 0x0D, 0xAE, 0x6C, 0xB8,
        0x94, 0x7F, 0x80, 0x33, 0xD3, 0xDC, 0x04, 0x02, 0xDC, 0x6F,
        0x17, 0xDC, 0xAE, 0x79, 0xED, 0xE3, 0x99, 0xAA, 0xE8, 0x4E,
        0x6A, 0x43, 0x73, 0xE6, 0xF3, 0xF8, 0x5A, 0x51, 0x55, 0x5E,
        0x55, 0x2D, 0xD6, 0xF7, 0xD5, 0xAB, 0xBE, 0xBD, 0xC8, 0x7D,
        0xB0, 0xA7, 0x9A, 0x46, 0xC0, 0xDC, 0x16, 0x83, 0xE9, 0x2C,
        0x56, 0x6C, 0x45, 0x52, 0x3E, 0x05, 0x4D, 0x5F, 0x11, 0xD0,
        0x93, 0x0F, 0x82, 0x6D, 0x6E, 0xC0, 0x01, 0x38, 0x3B, 0x2F,
        0xD9, 0x80, 0x51, 0x6D, 0xD1, 0x1B, 0x22, 0x72, 0xBB, 0x15,
        0x5D, 0xBC, 0xB8, 0x07, 0xBB, 0x96
};
const int sizeof_ca_cert_sig = sizeof(ca_cert_sig);

/* ./client-cert.der.sign,  */
const unsigned char client_cert_der_sign[] =
{
        0x5D, 0x1F, 0x89, 0x41, 0xEC, 0x47, 0xC8, 0x90, 0x61, 0x79,
        0x8A, 0x16, 0x1F, 0x31, 0x96, 0x67, 0xD9, 0x3C, 0xEC, 0x6B,
        0x58, 0xC6, 0x5A, 0xED, 0x99, 0xB3, 0xEF, 0x27, 0x6F, 0x04,
        0x8C, 0xD9, 0x68, 0xB1, 0xD6, 0x23, 0x15, 0x84, 0x00, 0xE1,
        0x27, 0xD1, 0x1F, 0x68, 0xB7, 0x3F, 0x13, 0x53, 0x8A, 0x95,
        0x5A, 0x20, 0x7C, 0xB2, 0x76, 0x5B, 0xDC, 0xE0, 0xA6, 0x21,
        0x7C, 0x49, 0xCF, 0x93, 0xBA, 0xD5, 0x12, 0x9F, 0xEE, 0x90,
        0x5B, 0x3F, 0xA3, 0x9D, 0x13, 0x72, 0xAC, 0x72, 0x16, 0xFE,
        0x1D, 0xBE, 0xEB, 0x8E, 0xC7, 0xDC, 0xC4, 0xF8, 0x1A, 0xD8,
        0xA0, 0xA4, 0xF6, 0x04, 0x30, 0xF6, 0x7E, 0xB6, 0xC8, 0xE1,
        0xAB, 0x88, 0x37, 0x08, 0x63, 0x72, 0xAA, 0x46, 0xCC, 0xCA,
        0xF0, 0x9E, 0x02, 0x1E, 0x65, 0x67, 0xFF, 0x2C, 0x9D, 0x81,
        0x6C, 0x1E, 0xF1, 0x54, 0x05, 0x68, 0x68, 0x18, 0x72, 0x26,
        0x55, 0xB6, 0x2C, 0x95, 0xC0, 0xC9, 0xB2, 0xA7, 0x0B, 0x60,
        0xD7, 0xEB, 0x1D, 0x08, 0x1A, 0xA2, 0x54, 0x15, 0x89, 0xCB,
        0x83, 0x21, 0x5D, 0x15, 0x9B, 0x38, 0xAC, 0x89, 0x63, 0xD5,
        0x4B, 0xF4, 0x8B, 0x47, 0x93, 0x78, 0x43, 0xCB, 0x9B, 0x71,
        0xBF, 0x94, 0x76, 0xB5, 0xCE, 0x35, 0xA9, 0x1A, 0xD5, 0xA5,
        0xD8, 0x19, 0xA6, 0x04, 0x39, 0xB1, 0x09, 0x8C, 0x65, 0x02,
        0x58, 0x3A, 0x95, 0xEF, 0xA2, 0xC3, 0x85, 0x18, 0x61, 0x23,
        0x2D, 0xC5, 0xCD, 0x62, 0xC1, 0x19, 0x31, 0xE5, 0x36, 0x95,
        0x22, 0xDB, 0x3E, 0x1A, 0x3C, 0xE8, 0xC6, 0x2E, 0xDF, 0xD9,
        0x2F, 0x84, 0xC1, 0xF0, 0x38, 0x2B, 0xE5, 0x73, 0x35, 0x4F,
        0x05, 0xE2, 0xA5, 0x60, 0x79, 0xB0, 0x23, 0xDC, 0x56, 0x4C,
        0xE7, 0xD9, 0x1F, 0xCF, 0x6A, 0xFC, 0x55, 0xEB, 0xAA, 0x48,
        0x3E, 0x95, 0x2A, 0x10, 0x01, 0x05
};
const int sizeof_client_cert_der_sign = sizeof(client_cert_der_sign);

uint32_t s_inst1[R_TSIP_SINST_WORD_SIZE] = { 0 };
uint32_t s_inst2[R_TSIP_SINST2_WORD_SIZE]= { 0 };



=======
/* key_data.c
 *
 * Copyright (C) 2006-2020 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */


#include "key_data.h"

/*-------------------------------------------------------------------------
      TSIP v1.09
--------------------------------------------------------------------------*/
#if defined(WOLFSSL_RENESAS_TSIP_TLS) && (WOLFSSL_RENESAS_TSIP_VER >=109)

/* Key type of the encrypted user_public_key 0: RSA-2048 2: ECDSA-P256*/
const uint32_t              encrypted_user_key_type = 0;

const st_key_block_data_t g_key_block_data =
{
    /* uint8_t encrypted_provisioning_key[R_TSIP_AES_CBC_IV_BYTE_SIZE * 2]; */
   {
      0xE9,0x67,0x79,0xF7,0x38,0x73,0xC8,0x59,0x94,0x62,0x7D,0xB9,0x83,0xDE,0x59,0x4A,
      0x92,0x53,0x6B,0x14,0x1B,0x2A,0x99,0xDF,0x95,0xFD,0x35,0x84,0x93,0xCE, 0xDB,0x10
    },
    /* uint8_t iv[R_TSIP_AES_CBC_IV_BYTE_SIZE]; */
    {
        0xF6, 0xA9, 0x83, 0x5A, 0xA1, 0x65, 0x1D, 0x28, 0xC8, 0x1A, 0xA6, 0x9D, 0x34, 0xB2, 0x4D, 0x92
    },
    /* uint8_t encrypted_user_rsa2048_ne_key[R_TSIP_RSA2048_NE_KEY_BYTE_SIZE + 16]; */
    {
        0x34, 0x59, 0xFF, 0xFE, 0xAA, 0xE9, 0x26, 0x60, 0x8C, 0xB8, 0x76, 0xD2, 0x98, 0x65, 0x72, 0x3B,
        0x19, 0x78, 0xB8, 0x9B, 0x0D, 0xD4, 0xFC, 0x2A, 0xF8, 0x54, 0x3B, 0x75, 0x0E, 0x40, 0x21, 0xF5,
        0xF2, 0x6D, 0x3F, 0x60, 0xD2, 0xDF, 0xE7, 0xDB, 0x67, 0xF1, 0xC7, 0x66, 0x5F, 0x37, 0xAF, 0x9D,
        0x08, 0xE7, 0xFD, 0xEF, 0x63, 0xA9, 0x78, 0x73, 0x1A, 0xE2, 0x47, 0x91, 0xB5, 0xA0, 0xCE, 0xA2,
        0xC7, 0x4F, 0x8A, 0xE5, 0x03, 0x6F, 0xC5, 0xB8, 0xC4, 0x40, 0x12, 0x2D, 0x37, 0x2F, 0xF2, 0xC5,
        0x73, 0x2D, 0xF8, 0xBF, 0x4A, 0xDC, 0xB7, 0x98, 0xDF, 0xE8, 0xED, 0xF8, 0x3B, 0x24, 0x8A, 0x01,
        0xAE, 0x64, 0x89, 0x9C, 0x79, 0x66, 0x99, 0xE4, 0xF8, 0xC1, 0x3E, 0x04, 0x56, 0x1E, 0x6E, 0xBA,
        0x2D, 0xAA, 0xB9, 0xE8, 0xA0, 0xC2, 0x27, 0xCF, 0x7C, 0x0F, 0xAD, 0x0A, 0x22, 0xEE, 0x61, 0xA8,
        0x32, 0xBE, 0xEE, 0xE7, 0x3F, 0x5D, 0xE5, 0xBD, 0x75, 0x6B, 0x35, 0xC1, 0x77, 0xCC, 0x7D, 0x0E,
        0x2E, 0x26, 0x67, 0xC4, 0x0E, 0x84, 0x34, 0xBD, 0x33, 0xB3, 0x0C, 0xD9, 0x07, 0xE5, 0x8E, 0x3E,
        0x7E, 0xCC, 0x56, 0x5D, 0x23, 0x5A, 0x96, 0x83, 0x0C, 0xD9, 0x7F, 0xB0, 0xF7, 0x53, 0xD9, 0x5C,
        0xE2, 0x1B, 0xDA, 0x63, 0x62, 0x19, 0x16, 0x9D, 0x75, 0x7B, 0xBB, 0x7E, 0xC9, 0xB5, 0xAD, 0x7D,
        0xBB, 0x5A, 0xFA, 0xA5, 0x5B, 0x54, 0xA1, 0x93, 0x6D, 0x53, 0x3C, 0x85, 0x69, 0x00, 0x15, 0x40,
        0x0E, 0x54, 0xD2, 0xBA, 0xB5, 0x80, 0x1C, 0x25, 0x85, 0x0E, 0x60, 0x87, 0x2A, 0x1A, 0xE7, 0x60,
        0xCB, 0x6A, 0xF5, 0xAF, 0x84, 0x4B, 0xB7, 0x0D, 0x0C, 0xC0, 0xB5, 0x02, 0xB2, 0x38, 0x9D, 0x7C,
        0xFA, 0x31, 0xF3, 0x50, 0xB3, 0x32, 0x69, 0x3A, 0x3C, 0x7A, 0xA5, 0x67, 0x19, 0x66, 0xD5, 0x62,
        0xA3, 0xF2, 0xF7, 0x77, 0x73, 0xF6, 0xE7, 0x8D, 0x51, 0x0C, 0x19, 0xA3, 0x0F, 0x8C, 0x79, 0xE0,
        0x7C, 0xCF, 0x8A, 0x03, 0x70, 0xC7, 0x25, 0x9D, 0xCE, 0x89, 0x77, 0x8E, 0x4C, 0xE6, 0x97, 0xC8
    },
    /* uint8_t encrypted_user_update_key[R_TSIP_AES256_KEY_BYTE_SIZE + 16]; */
    {
        0x69, 0xDB, 0xC6, 0x86, 0xA5, 0x06, 0x22, 0x59, 0x11, 0x14, 0x73, 0x56, 0x3A, 0x9E, 0x44, 0xC3,
        0x9C, 0xA8, 0x76, 0xC6, 0xF6, 0xE8, 0xD8, 0xE2, 0x17, 0x66, 0x90, 0x65, 0x08, 0xB5, 0x39, 0x7F,
        0xD5, 0xC5, 0x6F, 0xD1, 0xCB, 0xFB, 0xB2, 0x76, 0x33, 0xA1, 0x22, 0x0F, 0xBE, 0x83, 0x91, 0x24
    },
};


/* ./ca-cert.der.sign,  */
const unsigned char ca_cert_sig[] =
{
    0x25,0x7B,0x10,0x4D,0xAF,0xB1,0xC1,0x50,0x7B,0x63,0x17,0xA0,0x38,0xA7,0x03,0x44,
    0x7A,0x7E,0x8D,0x3D,0x38,0xEE,0x4B,0xE4,0xB2,0x48,0x76,0x07,0xF8,0x06,0xB1,0x9D,
    0xBB,0xD1,0x46,0xB5,0xF9,0x86,0x08,0x85,0x29,0x6F,0xED,0x26,0x2F,0x91,0x7B,0x2B,
    0x36,0xAC,0x7E,0x56,0x2D,0x2B,0x8E,0x81,0x1B,0x3C,0xFA,0x08,0x80,0x05,0x01,0xC1,
    0xF3,0x71,0xFE,0xE9,0x59,0xA7,0xB6,0x82,0x62,0x04,0xA5,0xE4,0x6E,0xC9,0x32,0xCC,
    0xB1,0x19,0xBC,0xDE,0x6A,0x9B,0xEB,0x60,0x92,0xC5,0x46,0xB7,0xFF,0xF4,0xC1,0x77,
    0x5A,0xF4,0x53,0x41,0x6A,0x44,0x8B,0x46,0x3B,0xBE,0x74,0xBA,0x62,0xAF,0xFF,0xF2,
    0x32,0xCD,0x7A,0x97,0xE1,0xA8,0xBF,0x62,0x76,0xDA,0xBF,0x93,0x8B,0x1E,0x87,0xCC,
    0xEE,0x5D,0xCF,0xE9,0xBE,0xA6,0x25,0x6C,0xC4,0x92,0x2E,0x69,0x29,0x8F,0xCD,0x4C,
    0x07,0x91,0x20,0xD1,0x16,0xF9,0x6A,0x23,0xC8,0x5E,0xD4,0x7C,0x38,0xA2,0x80,0xCB,
    0x59,0x32,0xDD,0x28,0x46,0x6E,0x19,0xE9,0xAD,0x68,0x2B,0x0C,0xA0,0xB5,0x2A,0x8F,
    0x73,0xC2,0xED,0xF2,0x60,0x4F,0xF3,0xCE,0xDC,0x1B,0xA7,0x88,0x66,0x42,0xF0,0xFD,
    0x9D,0x77,0x2C,0x04,0xC2,0x54,0x4C,0x1D,0x58,0x9E,0x6D,0x4E,0x21,0x73,0x7E,0x1A,
    0x2A,0xDC,0x54,0x24,0x66,0x63,0xBA,0xF1,0xF8,0x16,0xE7,0x29,0xB2,0x01,0x98,0xE5,
    0x49,0x6E,0x97,0x86,0x82,0x6C,0xF3,0x3B,0x54,0x57,0x2C,0xD8,0x8F,0xC5,0x70,0x3E,
    0x22,0xD7,0x6D,0x9F,0x27,0xEC,0xD6,0x12,0xE5,0x4F,0x1E,0x05,0x36,0x07,0xBA,0xB2
};
const int sizeof_ca_cert_sig = sizeof(ca_cert_sig);

/* ./client-cert.der.sign,  */
const unsigned char client_cert_der_sign[] =
{
        0x5D, 0x1F, 0x89, 0x41, 0xEC, 0x47, 0xC8, 0x90, 0x61, 0x79,
        0x8A, 0x16, 0x1F, 0x31, 0x96, 0x67, 0xD9, 0x3C, 0xEC, 0x6B,
        0x58, 0xC6, 0x5A, 0xED, 0x99, 0xB3, 0xEF, 0x27, 0x6F, 0x04,
        0x8C, 0xD9, 0x68, 0xB1, 0xD6, 0x23, 0x15, 0x84, 0x00, 0xE1,
        0x27, 0xD1, 0x1F, 0x68, 0xB7, 0x3F, 0x13, 0x53, 0x8A, 0x95,
        0x5A, 0x20, 0x7C, 0xB2, 0x76, 0x5B, 0xDC, 0xE0, 0xA6, 0x21,
        0x7C, 0x49, 0xCF, 0x93, 0xBA, 0xD5, 0x12, 0x9F, 0xEE, 0x90,
        0x5B, 0x3F, 0xA3, 0x9D, 0x13, 0x72, 0xAC, 0x72, 0x16, 0xFE,
        0x1D, 0xBE, 0xEB, 0x8E, 0xC7, 0xDC, 0xC4, 0xF8, 0x1A, 0xD8,
        0xA0, 0xA4, 0xF6, 0x04, 0x30, 0xF6, 0x7E, 0xB6, 0xC8, 0xE1,
        0xAB, 0x88, 0x37, 0x08, 0x63, 0x72, 0xAA, 0x46, 0xCC, 0xCA,
        0xF0, 0x9E, 0x02, 0x1E, 0x65, 0x67, 0xFF, 0x2C, 0x9D, 0x81,
        0x6C, 0x1E, 0xF1, 0x54, 0x05, 0x68, 0x68, 0x18, 0x72, 0x26,
        0x55, 0xB6, 0x2C, 0x95, 0xC0, 0xC9, 0xB2, 0xA7, 0x0B, 0x60,
        0xD7, 0xEB, 0x1D, 0x08, 0x1A, 0xA2, 0x54, 0x15, 0x89, 0xCB,
        0x83, 0x21, 0x5D, 0x15, 0x9B, 0x38, 0xAC, 0x89, 0x63, 0xD5,
        0x4B, 0xF4, 0x8B, 0x47, 0x93, 0x78, 0x43, 0xCB, 0x9B, 0x71,
        0xBF, 0x94, 0x76, 0xB5, 0xCE, 0x35, 0xA9, 0x1A, 0xD5, 0xA5,
        0xD8, 0x19, 0xA6, 0x04, 0x39, 0xB1, 0x09, 0x8C, 0x65, 0x02,
        0x58, 0x3A, 0x95, 0xEF, 0xA2, 0xC3, 0x85, 0x18, 0x61, 0x23,
        0x2D, 0xC5, 0xCD, 0x62, 0xC1, 0x19, 0x31, 0xE5, 0x36, 0x95,
        0x22, 0xDB, 0x3E, 0x1A, 0x3C, 0xE8, 0xC6, 0x2E, 0xDF, 0xD9,
        0x2F, 0x84, 0xC1, 0xF0, 0x38, 0x2B, 0xE5, 0x73, 0x35, 0x4F,
        0x05, 0xE2, 0xA5, 0x60, 0x79, 0xB0, 0x23, 0xDC, 0x56, 0x4C,
        0xE7, 0xD9, 0x1F, 0xCF, 0x6A, 0xFC, 0x55, 0xEB, 0xAA, 0x48,
        0x3E, 0x95, 0x2A, 0x10, 0x01, 0x05
};
const int sizeof_client_cert_der_sign = sizeof(client_cert_der_sign);

uint32_t s_inst1[R_TSIP_SINST_WORD_SIZE] = { 0 };
uint32_t s_inst2[R_TSIP_SINST2_WORD_SIZE]= { 0 };


/*-------------------------------------------------------------------------
      TSIP v1.06
--------------------------------------------------------------------------*/
#elif	defined(WOLFSSL_RENESAS_TSIP_TLS) && (WOLFSSL_RENESAS_TSIP_VER >= 106)

const st_key_block_data_t g_key_block_data =
{

   /* uint8_t encrypted_session_key[R_TSIP_AES_CBC_IV_BYTE_SIZE * 2]; */
   {
      0xCE, 0xE0, 0xE9, 0x86, 0x62, 0x59, 0xF9, 0x8F, 0x3C, 0xFB, 0x81, 0x39, 0xC2, 0x82, 0xC7, 0xC9,
      0xCD, 0xEA, 0x6B, 0x16, 0x66, 0x77, 0x38, 0xCA, 0xF5, 0x6E, 0x6D, 0x5B, 0xF0, 0x30, 0xA2, 0x94
   },
   /* uint8_t iv[R_TSIP_AES_CBC_IV_BYTE_SIZE]; */
   {
      0xF6, 0xA9, 0x83, 0x5A, 0xA1, 0x65, 0x1D, 0x28, 0xC8, 0x1A, 0xA6, 0x9D, 0x34, 0xB2, 0x4D, 0x92
   },
   /* uint8_t encrypted_user_rsa2048_ne_key[R_TSIP_RSA2048_NE_KEY_BYTE_SIZE + 16]; */
   {
      0xFC, 0xB4, 0x0F, 0x72, 0xFE, 0xB4, 0xB1, 0xF7, 0xDB, 0xA7, 0x49, 0x9E, 0x0F, 0xF6, 0x4B, 0xA7,
      0x08, 0x0D, 0x3A, 0xFD, 0xAB, 0x7D, 0x82, 0xD7, 0x26, 0x36, 0xFC, 0xED, 0x3E, 0x53, 0xBC, 0xA1,
      0x3D, 0x75, 0x03, 0x5B, 0x53, 0x6D, 0x63, 0xBB, 0xB0, 0x9A, 0xD7, 0xEB, 0x7C, 0x99, 0x3B, 0xE4,
      0xB7, 0xA3, 0x83, 0xE7, 0x27, 0xBE, 0x88, 0x06, 0x2B, 0x81, 0x66, 0xF8, 0x94, 0x3E, 0x86, 0x02,
      0x5F, 0x97, 0x05, 0xFD, 0x93, 0x78, 0x06, 0x3A, 0xC6, 0xD0, 0x3A, 0x82, 0x5D, 0x10, 0xC4, 0xE3,
      0x30, 0x68, 0x48, 0x25, 0x31, 0xCD, 0x50, 0xBC, 0x91, 0xAF, 0x00, 0x4B, 0xAA, 0x6E, 0x3F, 0x6E,
      0x7F, 0x6A, 0x43, 0xAB, 0xB7, 0x06, 0x8D, 0x05, 0x1D, 0x26, 0x17, 0xE9, 0xD9, 0x72, 0x35, 0xED,
      0x79, 0x13, 0xEB, 0x57, 0xED, 0x33, 0x3B, 0x9B, 0x75, 0x15, 0xAB, 0x13, 0xEE, 0xDB, 0xCC, 0x9F,
      0x78, 0xF0, 0x51, 0x67, 0x53, 0xC2, 0xC3, 0xEF, 0xB1, 0x16, 0x39, 0xCB, 0x24, 0x5D, 0x11, 0x43,
      0x3F, 0xDC, 0x90, 0xD2, 0xA9, 0x4B, 0x6C, 0x9C, 0xBC, 0x77, 0x7B, 0xA4, 0x02, 0x8A, 0xB3, 0x7A,
      0x99, 0x75, 0x76, 0x86, 0xE2, 0xEA, 0x83, 0x8D, 0x07, 0xB0, 0xF1, 0xF0, 0x6E, 0x21, 0x19, 0x2E,
      0x16, 0x6B, 0xA3, 0x81, 0xB2, 0xE6, 0x29, 0x16, 0xAA, 0xBC, 0x43, 0x73, 0x1C, 0xC4, 0xDB, 0x92,
      0x2A, 0xA9, 0x20, 0x37, 0x64, 0x4C, 0xE1, 0x95, 0x91, 0x8C, 0x1E, 0xCD, 0xA3, 0xFE, 0x8B, 0x23,
      0x89, 0x2B, 0x6D, 0xA8, 0x6D, 0xD1, 0x7C, 0x20, 0xB9, 0x32, 0xA3, 0x0C, 0x8A, 0x5E, 0xE8, 0x7B,
      0xC8, 0x32, 0xA2, 0x81, 0x30, 0x7D, 0x21, 0x56, 0x97, 0x9C, 0x0C, 0x68, 0xAD, 0xFD, 0x6D, 0xFD,
      0xE0, 0x04, 0xE5, 0xB3, 0xC7, 0xED, 0x84, 0xCB, 0xD4, 0xB0, 0x84, 0x09, 0x99, 0xC3, 0xFB, 0x8B,
      0x91, 0x55, 0x2C, 0xCB, 0x48, 0x06, 0xD1, 0x6C, 0xE0, 0x42, 0x13, 0xDF, 0x2B, 0x73, 0x25, 0xB3,
      0x15, 0xC5, 0x8A, 0xDF, 0x01, 0x2B, 0x96, 0x01, 0x95, 0x84, 0xE4, 0x8E, 0xBA, 0x32, 0xCB, 0x77
    },
};

const uint32_t s_flash[] =
{
    0xa6f0651c, 0xa17c5a15, 0xa23e1bfb, 0xc04e1bb9,
    0x5594fc81, 0x67fad158, 0xfda808ae, 0x7e01cb88,
    0xbf12d558, 0x9ec08adc, 0x21c25af2, 0x60d43062,
    0x82e6b470, 0x178879a6, 0x9ddb263f, 0xddb57b53,
    0x220ea793, 0x24de7b88, 0x9fa846e4, 0xdf9059f9,
    0x7ce55a19, 0x686689e5, 0x9aaef400, 0x88fd178a,
    0xf4e33b46, 0xc9394a88, 0x712823b9, 0xca75513f,
    0x63859e61, 0x45477873, 0x357b5776, 0x83cc1def,
    0x74cb65ab, 0xa919863c, 0x9f75e62e, 0x5fd62143,
    0xdbae440a, 0x34053525, 0x56e221e1, 0x8ffbaeb5,
    0xa75c55f0, 0x34727e44, 0x2c791463, 0x7670923f,
    0xc0287d97, 0x0a09b5c9, 0xfaecf18e, 0x09ceab85,
    0x687ad46f, 0x7e4d8adb, 0x6def5893, 0x6f236da3,
    0xab6e15e1, 0x653f41d0, 0x05652571, 0x9ec8ec15,
    0x2d4acb06, 0x7d5c2c26, 0xf49455cb, 0x9872dc50,
    0xb9fe50a2, 0x34bf45ae, 0x4cf2b6bf, 0xe1c75c7b,
    0x6e23718f, 0x227b0a55, 0x3a5e8b00, 0x83222dba,
    0x4041008f, 0x40fc8d01, 0xcd6c5c64, 0x0b8183b5,
    0x678bf9e7, 0x57844b52, 0xb4c81735, 0x559e77f3,
    0xb2b6800e, 0x715de4e2, 0x7a2720bb, 0x7b434710,
    0xee264103, 0x9db8c751, 0x78291c62, 0x77b883f4,
    0xa27d1216, 0x4e733ba6, 0x8a5f40dc, 0x32d2dd82,
    0x8a5fdc67, 0xd8fb0926, 0x9d5aec51, 0x08bfce4d,
    0x2a54839b, 0xe6601069, 0x564fbdbf, 0x9bb43dc7,
    0x9bb59d3a, 0xc3aaa60c, 0x2f2e75d7, 0x6a953972,
    0x6de4fd23, 0x546c212b, 0xe8aad33f, 0xca416c37,
    0xa74b36f9, 0x520330f0, 0x96145828, 0x09c21110,
    0x0b29365a, 0xfe9a9e60, 0x82b3a215, 0x752daa46,
    0x45bd59d6, 0x145ba47f, 0x75e40f92, 0x2f904860,
    0x609e3b0a, 0x8e6e6aa8, 0xe88ea1c3, 0x22a1db60,
    0x9947e0c7, 0x28416ca7, 0x3cb6abe6, 0x0e367da7,
    0x17b16976, 0x5323ccde, 0xc7337459, 0xf07293ad,
};

/* ./ca-cert.der.sign,  */
const unsigned char ca_cert_sig[] =
{
        0x86, 0xD6, 0xC5, 0xB0, 0xE1, 0x37, 0x4C, 0x21, 0xF7, 0x8D,
        0x7C, 0x36, 0x80, 0xDB, 0x51, 0x58, 0x9D, 0x32, 0x5A, 0x1C,
        0xF3, 0xAC, 0x24, 0x17, 0xD4, 0x61, 0x9F, 0x09, 0x73, 0xA0,
        0x1E, 0x30, 0xE7, 0x6F, 0x00, 0xF8, 0xDB, 0xAA, 0x34, 0x4E,
        0x96, 0xA3, 0x3D, 0xBC, 0xE8, 0xFF, 0xBE, 0x4E, 0x62, 0x70,
        0x7B, 0xC7, 0x65, 0x2E, 0x9D, 0x1C, 0xE1, 0x5A, 0x7C, 0x2B,
        0xCD, 0x57, 0xEA, 0xF4, 0x16, 0xBC, 0x47, 0x26, 0xF5, 0x41,
        0x1F, 0x4E, 0xFD, 0xA5, 0x65, 0xAE, 0x31, 0xEB, 0xDF, 0x10,
        0xAF, 0xCB, 0xCB, 0x27, 0x84, 0xB6, 0x59, 0x3C, 0x6B, 0x9B,
        0x68, 0xAF, 0xEF, 0x35, 0xAF, 0x59, 0x9B, 0x07, 0x69, 0x75,
        0x1A, 0x99, 0x92, 0x0F, 0x0D, 0x02, 0x5A, 0x2C, 0x14, 0xD5,
        0x38, 0x8B, 0xD2, 0xB5, 0x35, 0xC7, 0x2D, 0xEB, 0x97, 0x4C,
        0xC8, 0x53, 0xCF, 0x7C, 0x0C, 0xB3, 0x00, 0x90, 0x99, 0x0B,
        0xB1, 0xBE, 0x8B, 0xEA, 0x96, 0xB4, 0x75, 0x35, 0x9D, 0xA1,
        0x2E, 0xF3, 0xF3, 0xEA, 0xF5, 0x7B, 0x83, 0xEF, 0x03, 0x06,
        0x3C, 0x41, 0x1C, 0x32, 0x84, 0x4A, 0xB8, 0xB0, 0xAE, 0x67,
        0xE9, 0xE4, 0xEE, 0x58, 0x43, 0x0C, 0x0D, 0xAE, 0x6C, 0xB8,
        0x94, 0x7F, 0x80, 0x33, 0xD3, 0xDC, 0x04, 0x02, 0xDC, 0x6F,
        0x17, 0xDC, 0xAE, 0x79, 0xED, 0xE3, 0x99, 0xAA, 0xE8, 0x4E,
        0x6A, 0x43, 0x73, 0xE6, 0xF3, 0xF8, 0x5A, 0x51, 0x55, 0x5E,
        0x55, 0x2D, 0xD6, 0xF7, 0xD5, 0xAB, 0xBE, 0xBD, 0xC8, 0x7D,
        0xB0, 0xA7, 0x9A, 0x46, 0xC0, 0xDC, 0x16, 0x83, 0xE9, 0x2C,
        0x56, 0x6C, 0x45, 0x52, 0x3E, 0x05, 0x4D, 0x5F, 0x11, 0xD0,
        0x93, 0x0F, 0x82, 0x6D, 0x6E, 0xC0, 0x01, 0x38, 0x3B, 0x2F,
        0xD9, 0x80, 0x51, 0x6D, 0xD1, 0x1B, 0x22, 0x72, 0xBB, 0x15,
        0x5D, 0xBC, 0xB8, 0x07, 0xBB, 0x96
};
const int sizeof_ca_cert_sig = sizeof(ca_cert_sig);

/* ./client-cert.der.sign,  */
const unsigned char client_cert_der_sign[] =
{
        0x5D, 0x1F, 0x89, 0x41, 0xEC, 0x47, 0xC8, 0x90, 0x61, 0x79,
        0x8A, 0x16, 0x1F, 0x31, 0x96, 0x67, 0xD9, 0x3C, 0xEC, 0x6B,
        0x58, 0xC6, 0x5A, 0xED, 0x99, 0xB3, 0xEF, 0x27, 0x6F, 0x04,
        0x8C, 0xD9, 0x68, 0xB1, 0xD6, 0x23, 0x15, 0x84, 0x00, 0xE1,
        0x27, 0xD1, 0x1F, 0x68, 0xB7, 0x3F, 0x13, 0x53, 0x8A, 0x95,
        0x5A, 0x20, 0x7C, 0xB2, 0x76, 0x5B, 0xDC, 0xE0, 0xA6, 0x21,
        0x7C, 0x49, 0xCF, 0x93, 0xBA, 0xD5, 0x12, 0x9F, 0xEE, 0x90,
        0x5B, 0x3F, 0xA3, 0x9D, 0x13, 0x72, 0xAC, 0x72, 0x16, 0xFE,
        0x1D, 0xBE, 0xEB, 0x8E, 0xC7, 0xDC, 0xC4, 0xF8, 0x1A, 0xD8,
        0xA0, 0xA4, 0xF6, 0x04, 0x30, 0xF6, 0x7E, 0xB6, 0xC8, 0xE1,
        0xAB, 0x88, 0x37, 0x08, 0x63, 0x72, 0xAA, 0x46, 0xCC, 0xCA,
        0xF0, 0x9E, 0x02, 0x1E, 0x65, 0x67, 0xFF, 0x2C, 0x9D, 0x81,
        0x6C, 0x1E, 0xF1, 0x54, 0x05, 0x68, 0x68, 0x18, 0x72, 0x26,
        0x55, 0xB6, 0x2C, 0x95, 0xC0, 0xC9, 0xB2, 0xA7, 0x0B, 0x60,
        0xD7, 0xEB, 0x1D, 0x08, 0x1A, 0xA2, 0x54, 0x15, 0x89, 0xCB,
        0x83, 0x21, 0x5D, 0x15, 0x9B, 0x38, 0xAC, 0x89, 0x63, 0xD5,
        0x4B, 0xF4, 0x8B, 0x47, 0x93, 0x78, 0x43, 0xCB, 0x9B, 0x71,
        0xBF, 0x94, 0x76, 0xB5, 0xCE, 0x35, 0xA9, 0x1A, 0xD5, 0xA5,
        0xD8, 0x19, 0xA6, 0x04, 0x39, 0xB1, 0x09, 0x8C, 0x65, 0x02,
        0x58, 0x3A, 0x95, 0xEF, 0xA2, 0xC3, 0x85, 0x18, 0x61, 0x23,
        0x2D, 0xC5, 0xCD, 0x62, 0xC1, 0x19, 0x31, 0xE5, 0x36, 0x95,
        0x22, 0xDB, 0x3E, 0x1A, 0x3C, 0xE8, 0xC6, 0x2E, 0xDF, 0xD9,
        0x2F, 0x84, 0xC1, 0xF0, 0x38, 0x2B, 0xE5, 0x73, 0x35, 0x4F,
        0x05, 0xE2, 0xA5, 0x60, 0x79, 0xB0, 0x23, 0xDC, 0x56, 0x4C,
        0xE7, 0xD9, 0x1F, 0xCF, 0x6A, 0xFC, 0x55, 0xEB, 0xAA, 0x48,
        0x3E, 0x95, 0x2A, 0x10, 0x01, 0x05
};
const int sizeof_client_cert_der_sign = sizeof(client_cert_der_sign);

uint32_t s_inst1[R_TSIP_SINST_WORD_SIZE] = { 0 };
uint32_t s_inst2[R_TSIP_SINST2_WORD_SIZE]= { 0 };



>>>>>>> 16c66438 (Upload from PC.)
#endif
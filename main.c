#include <reg51.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecc.h"

void UART_Init()
{
    TMOD |= 0x20;
    TH1 = 0xfd;
    TH0 = 0xfd;
    TR1 = 1;
    ET1 = 0;
    PCON &= 0x7f;
    SCON = 0x50;
    EA = 1;
    ES = 0;
}

void UART_Send_Data(unsigned char byte)
{
    SBUF = byte;
    while (!TI)
        ;
    TI = 0;
}

int ecsda_test(void)
{
    int ret = 0;
    uint8_t signatureR[NUM_ECC_DIGITS];
    uint8_t signatureS[NUM_ECC_DIGITS];
    uint8_t publicX[NUM_ECC_DIGITS];
    uint8_t publicY[NUM_ECC_DIGITS];


    EccPoint l_public;
    uint8_t l_private[NUM_ECC_DIGITS];
    uint8_t r[NUM_ECC_DIGITS];
    uint8_t s[NUM_ECC_DIGITS];
    uint8_t result[NUM_ECC_DIGITS] = {0};
    uint8_t l_random[NUM_ECC_DIGITS] = {0x09, 0xa2, 0x34, 0x01, 0x48, 0xfc, 0x54, 0x7b, 0xf1, 0xf6, 0x44, 0x93, 0x83, 0xf4, 0x88, 0x3b, 0xd2, 0xf6, 0x46, 0x39, 0xa4, 0x9b, 0x39, 0x8a, 0x1b, 0x48, 0x46, 0x8d, 0xa3, 0x82, 0x0d, 0x0a};

    // hello
    uint8_t l_hash[NUM_ECC_DIGITS] = {0};
    uint8_t tmp_hash[NUM_ECC_DIGITS] = {0x2c, 0xf2, 0x4d, 0xba, 0x5f, 0xb0, 0xa3, 0x0e, 0x26, 0xe8, 0x3b, 0x2a, 0xc5, 0xb9, 0xe2, 0x9e, 0x1b, 0x16, 0x1e, 0x5c, 0x1f, 0xa7, 0x42, 0x5e, 0x73, 0x04, 0x33, 0x62, 0x93, 0x8b, 0x98, 0x24};
    ecc_bytes2native(l_hash, tmp_hash);

    ecc_make_key(&l_public, l_private, l_random);

    ret = ecdsa_sign(r, s, l_private, l_random, l_hash);
    ecc_bytes2native(signatureR, r);
    ecc_bytes2native(signatureS, s);
    ecc_bytes2native(publicX, l_public.x);
    ecc_bytes2native(publicY, l_public.y);
    // if (!ecc_valid_public_key(&l_public))
    // {
    //     UART_Send_Data('x');
    //     UART_Send_Data('2');
    // }

    // if (!ecdsa_verify(&l_public, l_hash, r, s))
    // {
    //     UART_Send_Data('x');
    //     UART_Send_Data('3');
    // }
    return 1;
}

void show(char *str, int str_len)
{
    int index = 0;
    UART_Send_Data('-');

    for (; index < str_len; index++)
        UART_Send_Data(str[index]);
    UART_Send_Data('+');
}

void printHex(unsigned char *hex, int hex_len)
{
    int i = 0;
    for (; i < hex_len; i++)
    {
        printf("%.2x", hex[i]);
    }
    printf("\n");
}

void main()
{
    int i = 0;
    ecsda_test();
    i++;
}
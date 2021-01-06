#include <reg51.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "ecc.h"

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

void show(unsigned char *hex, int hex_size)
{
    int index = 0;
    unsigned char ch = 0;
    for (; index <= hex_size; index++){
        ch = hex[index] >= 10 ? 0x37 + hex[index] : 0x30 + hex[index];
        UART_Send_Data(ch);
    }
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
    unsigned char hexs[3];
    hexs[0] = 9;
    hexs[1] = 2;
    hexs[2] = 4;
    UART_Init();
    UART_Send_Data('w');
    UART_Send_Data('0' + hexs[0]);
    UART_Send_Data('0' + hexs[1]);
    UART_Send_Data('0' + hexs[2]);
    // show(hexs,3);
    UART_Send_Data('k');
    UART_Send_Data('x');
    while (1);
}
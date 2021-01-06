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

void show(char *str, int str_len)
{
    int index = 0;
    for (; index < str_len; index++)
        UART_Send_Data(str[index]);
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
    char name[] = "wangkaixuan";
    UART_Init();
    UART_Send_Data('w');
    show(name, strlen(name));
    UART_Send_Data('k');
    UART_Send_Data('x');
    while (1);
}
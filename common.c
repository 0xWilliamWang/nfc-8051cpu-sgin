#include "common.h"

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

void printHex(char *tips, unsigned char *hex, int hex_len)
{
    int i = 0;
    printf("%s: ", tips);
    for (; i < hex_len; i++)
    {
        printf("%.2x", hex[i]);
    }
    printf("\n");
}

char putchar(char ch)
{
    SBUF = ch;
    while (!TI)
        ;
    TI = 0;
    return ch;
}

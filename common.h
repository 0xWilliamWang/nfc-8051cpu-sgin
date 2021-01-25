#ifndef __COMMON_H_
#define __COMMON_H_

#include <reg51.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef signed char int8_t;
typedef int int16_t;
typedef long int int32_t;
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;

// These macros must exactly match those in the Windows SDK's intsafe.h.
void UART_Init();
void printHex(char *tips, unsigned char *hex, int hex_len);

#endif

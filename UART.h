#ifndef UART_H
#define UART_H

#include <msp430.h>

// UART Function Prototypes
void initUART();
void UART_writeChar(char c);
void UART_writeString(const char *str);
char UART_readChar();

#endif // UART_H
#include "UART.h"

void initUART() {
    PM5CTL0 &= ~LOCKLPM5;
    P1SEL0 |= BIT6 | BIT7;
    P1SEL1 &= ~(BIT6 | BIT7);

    UCA0CTLW0 = UCSWRST;         // Put eUSCI in reset mode
    UCA0CTLW0 |= UCSSEL_2;       // Use SMCLK as clock source
    UCA0BRW = 8;                 // Set baud rate to 9600 (assuming 1MHz clock)
    UCA0MCTLW = 0xD600;          // Modulation settings for 9600 baud
    UCA0CTLW0 &= ~UCSWRST;       // Release from reset

    UCA0IE |= UCRXIE;            // Enable UART receive interrupt
}

void UART_writeChar(char c) {
    while (!(UCA0IFG & UCTXIFG));
    UCA0TXBUF = c;
}

void UART_writeString(const char *str) {
    while (*str) {
        UART_writeChar(*str++);
    }
}

char UART_readChar() {
    while (!(UCA0IFG & UCRXIFG));
    return UCA0RXBUF;
}
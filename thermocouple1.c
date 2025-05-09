#include <msp430.h>
#include <stdio.h>

void uart_init(void);
void adc_init(void);
void uart_send_char(char c);
void uart_send_string(const char *str);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog timer

    uart_init();               // Initialize UART
    adc_init();                // Initialize ADC

    while (1) {
        ADCCTL0 |= ADCENC | ADCSC;  // Start ADC conversion
        while (ADCCTL1 & ADCBUSY);  // Wait for conversion to complete

        unsigned int adc_value = ADCMEM0;  // Read ADC result
        char buffer[20];
        sprintf(buffer, "ADC Value: %d\n", adc_value);
        uart_send_string(buffer);  // Send ADC value over UART

        __delay_cycles(100000);  // Delay for readability
    }
}

void uart_init(void) {
    P4SEL0 |= BIT2 | BIT3;  // Set P4.2 (TX) and P4.3 (RX) for UART
    UCA1CTLW0 = UCSWRST;    // Put eUSCI in reset
    UCA1CTLW0 |= UCSSEL__SMCLK;
    UCA1BRW = 6;            // Baud rate: 9600 (assuming 1MHz SMCLK)
    UCA1MCTLW = UCBRF_8 | UCBRS5 | UCOS16;
    UCA1CTLW0 &= ~UCSWRST;  // Initialize eUSCI
}

void adc_init(void) {
    P1SEL0 |= BIT3;         // Set P1.3 for ADC input (A3)
    ADCCTL0 = ADCSHT_2 | ADCON;      // 16 ADC clks, ADC on
    ADCCTL1 = ADCSHP;       // Sample-and-hold pulse mode
    ADCCTL2 = ADCRES_2;     // 12-bit conversion
    ADCMCTL0 = ADCINCH_3;   // A3 (P1.3)
}

void uart_send_char(char c) {
    while (!(UCA1IFG & UCTXIFG));  // Wait for TX buffer to be ready
    UCA1TXBUF = c;
}

void uart_send_string(const char *str) {
    while (*str) {
        uart_send_char(*str++);
    }
}

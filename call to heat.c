#include <msp430.h>
#include <stdio.h>

void uart_init(void);
void uart_send_char(char c);
void uart_send_string(const char *str);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog timer

    uart_init();               // Initialize UART

    // Configure P3.0 as input for Call for Heat with pull-up
    P3DIR &= ~BIT0;            // Set P3.0 as input
    P3REN |= BIT0;             // Enable pull-up/down resistor
    P3OUT |= BIT0;             // Select pull-up resistor
    P3SEL0 &= ~BIT0;           // Ensure P3.0 is set as GPIO
    P3SEL1 &= ~BIT0;

    // Configure P1.0 as output for LED indication
    P1DIR |= BIT0;             // Set P1.0 as output (LED)

    while (1) {
        // Debounce delay
        __delay_cycles(1000);  // Short delay for debounce
        
        // Check Call for Heat status
        if (P3IN & BIT0) {     // Check if Call for Heat is HIGH
            uart_send_string("Call for Heat: OFF\n");
            P1OUT &= ~BIT0;    // Turn off LED
        } else {               // Call for Heat is LOW (Active)
            uart_send_string("Call for Heat: ON\n");
            P1OUT |= BIT0;     // Turn on LED
        }

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

void uart_send_char(char c) {
    while (!(UCA1IFG & UCTXIFG));  // Wait for TX buffer to be ready
    UCA1TXBUF = c;
}

void uart_send_string(const char *str) {
    while (*str) {
        uart_send_char(*str++);
    }
}

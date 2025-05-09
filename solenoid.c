#include <msp430.h>

void delay_ms(unsigned int ms);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog timer

    // Set P5.4 as output
    P5DIR |= BIT4;
    P5OUT &= ~BIT4;  // Initially turn off solenoid

    while (1) {
        // Toggle solenoid on
        P5OUT |= BIT4;
        delay_ms(1000);  // 1-second delay

        // Toggle solenoid off
        P5OUT &= ~BIT4;
        delay_ms(1000);  // 1-second delay
    }
}

void delay_ms(unsigned int ms) {
    while (ms--) {
        __delay_cycles(1000);  // Assuming 1 MHz clock (1 ms per 1000 cycles)
    }
}

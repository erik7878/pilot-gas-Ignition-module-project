#include <msp430.h>

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    PM5CTL0 &= ~LOCKLPM5;

    P5DIR |= BIT0; // Ignitor LED (D2)
    
    while (1)
    {
        P5OUT ^= BIT0; // Toggle ignitor LED
        __delay_cycles(500);
    }
}

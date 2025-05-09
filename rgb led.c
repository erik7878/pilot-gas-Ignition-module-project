#include <msp430.h>

#define RED_LED BIT0    // Red LED connected to P1.0
#define GREEN_LED BIT1  // Green LED connected to P1.1
#define BLUE_LED BIT2   // Blue LED connected to P1.2

void setup();
void cycle_colors();

int main(void) {
    setup();
    
    while (1) {
        cycle_colors();
    }
}

void setup() {
    WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog timer

    // Set RGB LED pins as output
    P1DIR |= RED_LED | GREEN_LED | BLUE_LED;
    P1OUT &= ~(RED_LED | GREEN_LED | BLUE_LED); // Turn off all LEDs initially
}

void cycle_colors() {
    // Red
    P1OUT |= RED_LED;
    P1OUT &= ~(GREEN_LED | BLUE_LED);
    __delay_cycles(1000000);

    // Green
    P1OUT |= GREEN_LED;
    P1OUT &= ~(RED_LED | BLUE_LED);
    __delay_cycles(1000000);

    // Blue
    P1OUT |= BLUE_LED;
    P1OUT &= ~(RED_LED | GREEN_LED);
    __delay_cycles(1000000);

    // Yellow (Red + Green)
    P1OUT |= RED_LED | GREEN_LED;
    P1OUT &= ~BLUE_LED;
    __delay_cycles(1000000);

    // Cyan (Green + Blue)
    P1OUT |= GREEN_LED | BLUE_LED;
    P1OUT &= ~RED_LED;
    __delay_cycles(1000000);

    // Magenta (Red + Blue)
    P1OUT |= RED_LED | BLUE_LED;
    P1OUT &= ~GREEN_LED;
    __delay_cycles(1000000);

    // White (All colors on)
    P1OUT |= RED_LED | GREEN_LED | BLUE_LED;
    __delay_cycles(1000000);

    // Turn off LEDs before next cycle
    P1OUT &= ~(RED_LED | GREEN_LED | BLUE_LED);
    __delay_cycles(500000);
}

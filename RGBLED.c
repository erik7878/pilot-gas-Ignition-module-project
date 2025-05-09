#include "ignitorLED.h"

void initRGBLED() {
    // Set RGB LED pins (P6.0 = Red, P6.1 = Green, P6.2 = Blue) as outputs
    P6DIR |= BIT0 | BIT1 | BIT2;
    P6OUT &= ~(BIT0 | BIT1 | BIT2);  // Ensure all LEDs start OFF
}

void setRGBLED(unsigned char red, unsigned char green, unsigned char blue) {
    // Control RED
    if (red) {
        P6OUT |= BIT0;  // Turn RED ON
    } else {
        P6OUT &= ~BIT0; // Turn RED OFF
    }

    // Control GREEN
    if (green) {
        P6OUT |= BIT1;  // Turn GREEN ON
    } else {
        P6OUT &= ~BIT1; // Turn GREEN OFF
    }

    // Control BLUE
    if (blue) {
        P6OUT |= BIT2;  // Turn BLUE ON
    } else {
        P6OUT &= ~BIT2; // Turn BLUE OFF
    }
}

void turnOffRGBLED() {
    P6OUT &= ~(BIT0 | BIT1 | BIT2); // Turn OFF all RGB LEDs
}
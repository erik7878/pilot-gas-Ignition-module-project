#include "ignitorLED.h"

void initIgnitorLED() {
    P5DIR |= BIT0;   // Set P5.0 as output
    P5OUT &= ~BIT0;  // Ensure LED starts OFF
}

void ignitePilot() {
    P5OUT |= BIT0;   // Turn ON Ignitor LED
}

void extinguishPilot() {
    P5OUT &= ~BIT0;  // Turn OFF Ignitor LED
}
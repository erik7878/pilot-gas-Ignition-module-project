#include "GPIO.h"

// RGB LED Functions
void initRGBLED() {
    P6DIR |= BIT0 | BIT1 | BIT2;  // Configure RGB pins as outputs
    P6OUT &= ~(BIT0 | BIT1 | BIT2); // Ensure RGB LED is off
}

void setRGBLED(unsigned char red, unsigned char green, unsigned char blue) {
    P6OUT = (red ? BIT0 : 0) | (green ? BIT1 : 0) | (blue ? BIT2 : 0);
}

void turnOffRGBLED() {
    P6OUT &= ~(BIT0 | BIT1 | BIT2);
}

// Ignitor LED Functions
void initIgnitorLED() {
    P5DIR |= BIT0;   // Set P5.0 as output
    P5OUT &= ~BIT0;  // Ensure LED starts OFF
}

void ignitePilot() {
    P5OUT |= BIT0;
}

void extinguishPilot() {
    P5OUT &= ~BIT0;
}

// Pilot Valve Functions
void initPilotValve() {
    P5DIR |= BIT4;
    P5OUT &= ~BIT4;
}

void activatePilotValve() {
    P5OUT |= BIT4;
}

void deactivatePilotValve() {
    P5OUT &= ~BIT4;
}

// Call to Heat Functions
void initCallToHeat() {
    P3DIR &= ~BIT0;
    P3REN |= BIT0;
    P3OUT |= BIT0;
}

void requestHeat() {
    if (P3IN & BIT0) {  
        ignitePilot();
        activatePilotValve();
        __delay_cycles(1000000);
    }
}

void stopHeat() {
    deactivatePilotValve();
    extinguishPilot();
}
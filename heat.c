#include "heat.h"
#include "VALVE.h"
#include "ignitorLED.h"

void initCallToHeat() {
    P3DIR &= ~BIT0;  // Set P3.0 as INPUT (heat request signal)
    P3REN |= BIT0;   // Enable pull-up/down resistor
    P3OUT |= BIT0;   // Configure pull-up resistor
}

void requestHeat() {
    if (P3IN & BIT0) {  // Check if Call to Heat is active
        ignitePilot();      // Turn on Ignitor LED
        activatePilotValve(); // Open pilot solenoid
        __delay_cycles(1000000); // Allow pilot ignition time
        activateMainValve(); // Open main gas valve
    }
}

void stopHeat() {
    deactivateMainValve(); // Close main valve
    deactivatePilotValve(); // Close pilot solenoid
    extinguishPilot();   // Turn off Ignitor LED
}
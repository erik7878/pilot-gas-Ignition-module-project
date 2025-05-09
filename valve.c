#include "VALVE.h"

void initPilotValve() {
    P5DIR |= BIT4;  // Set P5.4 as output
    P5OUT &= ~BIT4; // Ensure solenoid starts OFF
}

void activatePilotValve() {
    P5OUT |= BIT4;  // Turn ON solenoid (Open Valve)
}

void deactivatePilotValve() {
    P5OUT &= ~BIT4; // Turn OFF solenoid (Close Valve)
}
#ifndef GPIO_H
#define GPIO_H

#include <msp430.h>

// RGB LED Function Prototypes
void initRGBLED();
void setRGBLED(unsigned char red, unsigned char green, unsigned char blue);
void turnOffRGBLED();

// Ignitor LED Function Prototypes
void initIgnitorLED();
void ignitePilot();
void extinguishPilot();

// Pilot Valve Function Prototypes
void initPilotValve();
void activatePilotValve();
void deactivatePilotValve();

// Call to Heat Function Prototypes
void initCallToHeat();
void requestHeat();
void stopHeat();

#endif // GPIO_H
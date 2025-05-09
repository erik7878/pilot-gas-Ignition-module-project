#ifndef LED_H
#define LED_H

#include <msp430.h>

// Function Prototypes
void initRGBLED();
void setRGBLED(unsigned char red, unsigned char green, unsigned char blue);
void turnOffRGBLED();

#endif // LED_H
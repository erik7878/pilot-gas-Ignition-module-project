#ifndef SENSORS_H
#define SENSORS_H

#include <msp430.h>

// Function Prototypes
void initThermocouple();
unsigned int readThermocouple();

#endif // SENSORS_H
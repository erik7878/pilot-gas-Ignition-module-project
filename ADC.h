#ifndef ADC_H
#define ADC_H

#include <msp430.h>

// Thermistor Function Prototypes
void initThermistor();
unsigned int readThermistor();

// Thermocouple Function Prototypes
void initThermocouple();
unsigned int readThermocouple();

// Potentiometer Function Prototypes
void initPotentiometer();
unsigned int readPotentiometer();

#endif // ADC_H
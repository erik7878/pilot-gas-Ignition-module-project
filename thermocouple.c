#include "thermocouple.h"

void initThermocouple() {
    ADCCTL0 |= ADCSHT_2 | ADCON;   // Enable ADC, sample for 16 clock cycles
    ADCCTL1 |= ADCSHP;             // Use sample-and-hold mode
    ADCCTL2 |= ADCRES;             // 10-bit resolution
    ADCMCTL0 |= ADCINCH_3;         // Select channel A3 (P1.3)
}

unsigned int readThermocouple() {
    ADCCTL0 |= ADCENC | ADCSC;     // Enable and start conversion
    while (ADCCTL1 & ADCBUSY);     // Wait for ADC conversion to complete
    return ADCMEM0;                // Return 10-bit ADC value
}
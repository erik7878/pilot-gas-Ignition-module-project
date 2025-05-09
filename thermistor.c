#include "thermistor.h"

void initThermistor() {
    ADCCTL0 |= ADCSHT_2 | ADCON;   // Enable ADC, sample for 16 clock cycles
    ADCCTL1 |= ADCSHP;             // Use sample-and-hold mode
    ADCCTL2 |= ADCRES;             // 10-bit resolution
    ADCMCTL0 |= ADCINCH_6;         // Select channel A6 (P1.6)
}

unsigned int readThermistor() {
    ADCCTL0 |= ADCENC | ADCSC;     // Enable and start conversion
    while (ADCCTL1 & ADCBUSY);     // Wait for ADC conversion to complete
    return ADCMEM0;                // Return 10-bit ADC value
}
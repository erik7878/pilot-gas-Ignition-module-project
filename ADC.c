#include "ADC.h"

// Thermistor Functions
void initThermistor() {
    ADCCTL0 |= ADCSHT_2 | ADCON;
    ADCCTL1 |= ADCSHP;
    ADCCTL2 |= ADCRES;
    ADCMCTL0 |= ADCINCH_6;
}

unsigned int readThermistor() {
    ADCCTL0 |= ADCENC | ADCSC;
    while (ADCCTL1 & ADCBUSY);
    return ADCMEM0;
}

// Thermocouple Functions
void initThermocouple() {
    ADCCTL0 |= ADCSHT_2 | ADCON;
    ADCCTL1 |= ADCSHP;
    ADCCTL2 |= ADCRES;
    ADCMCTL0 |= ADCINCH_3;
}

unsigned int readThermocouple() {
    ADCCTL0 |= ADCENC | ADCSC;
    while (ADCCTL1 & ADCBUSY);
    return ADCMEM0;
}

// Potentiometer Functions
void initPotentiometer() {
    ADCCTL0 |= ADCSHT_2 | ADCON;
    ADCCTL1 |= ADCSHP;
    ADCCTL2 |= ADCRES;
    ADCMCTL0 |= ADCINCH_5;
}

unsigned int readPotentiometer() {
    ADCCTL0 |= ADCENC | ADCSC;
    while (ADCCTL1 & ADCBUSY);
    return ADCMEM0;
}
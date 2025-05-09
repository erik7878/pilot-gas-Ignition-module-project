#include "PWM.h"

void servo_write_pulse(unsigned int pulse_width_us) {
    P2OUT |= BIT1;  // Start pulse
    delay_us(pulse_width_us);  // Pulse width
    P2OUT &= ~BIT1;  // End pulse
    delay_us(20000 - pulse_width_us);  // Complete 20ms frame
}

void setServoAngle(int angle) {
    if (angle < 0) angle = 0;
    if (angle > 180) angle = 180;

    unsigned int pulse_width = 1000 + (angle * 1000) / 180;  // Map 0–180 to 1000–2000us

    int i;
    for (i = 0; i < 25; i++) {  // Send ~0.5 seconds of pulses
        servo_write_pulse(pulse_width);
        delay_ms(20);
    }
}

void delay_us(unsigned int us) {
    while (us--) __delay_cycles(1);  // ~1us at 1MHz
}

void delay_ms(unsigned int ms) {
    while (ms--) __delay_cycles(1000);  // ~1ms at 1MHz
}
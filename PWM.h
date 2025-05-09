#ifndef PWM_H
#define PWM_H

#include <msp430.h>

// Servo Function Prototypes
void servo_write_pulse(unsigned int pulse_width_us);
void setServoAngle(int angle);

// Delay Function Prototypes
void delay_us(unsigned int us);
void delay_ms(unsigned int ms);

#endif // PWM_H
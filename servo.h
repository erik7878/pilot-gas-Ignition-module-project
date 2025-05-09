#ifndef SERVO_H_
#define SERVO_H_

void servo_init();                 // Initialize PWM on P2.1
void setServoAngle(int angle);     // Set angle between 0–180 degrees

#endif /* SERVO_H_ */

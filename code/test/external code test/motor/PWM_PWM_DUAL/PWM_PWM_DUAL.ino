
 #include "CytronMotorDriver.h"


// Configure the motor driver.
CytronMD motor1(PWM_PWM, 7, 6);   // PWM 1A = Pin 7, PWM 1B = Pin 6.
CytronMD motor2(PWM_PWM, 5, 4); // PWM 2A = Pin 5, PWM 2B = Pin 4.

.
void setup() {
  Serial.begin(9600);
}

void loop() {
 
  motor1.setSpeed(-255);  

  delay(1000);
  motor1.setSpeed(0);  
  delay(1000);
}
 
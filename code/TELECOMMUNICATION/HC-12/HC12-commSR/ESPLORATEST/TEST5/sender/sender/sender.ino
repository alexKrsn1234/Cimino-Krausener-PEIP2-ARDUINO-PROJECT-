#include <SoftwareSerial.h>
#include <Esplora.h>
SoftwareSerial HC12(14,15); // HC-12 TX Pin, HC-12 RX Pin

int potValue = 0;
int joyValueX = 0;
int joyValueY = 0;
boolean buttonValue = false;
int motorPower = 0;
int roll = 0;
int direction = 0;

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12

}

void loop() {     
  potValue = Esplora.readSlider();
  joyValueX = Esplora.readJoystickX();
  joyValueY = Esplora.readJoystickY();
  buttonValue = Esplora.readButton(SWITCH_UP);
  motorPower = map(potValue, 0, 1023, 20, 100); //fonction qui détermine à quel pourcentage de puissance le moteur tourne

  if(abs(joyValueX) < 10){direction = 0;}   //Correction de la sensibilité du Joystick en X
  else{direction=map(joyValueX,-512,512,255,-255);}

  if(abs(joyValueY)<10){roll=0;}
  else{roll = map(joyValueY,-512,512,255,-255)*motorPower/100;}
  
  Serial.println('s'+String(roll) + 'd' + String(direction)+'e');
  HC12.println('s'+String(roll) + 'd' + String(direction)+'e');

  delay(10);
  
}
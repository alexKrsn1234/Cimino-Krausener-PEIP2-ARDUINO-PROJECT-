#include <SoftwareSerial.h>
#include <CytronMotorDriver.h>

// Configure the motor driver.
CytronMD motor1(PWM_PWM, 7, 6);   // PWM 1A = Pin 7, PWM 1B = Pin 6.
CytronMD motor2(PWM_PWM, 5, 4); // PWM 2A = Pin 5, PWM 2B = Pin 4.

//Configure the software Serial blabla
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin

//variables
char incomingByte;
String readBuffer;
boolean start = false;
int roll=0;
int direction = 0;
char action;
int value;

//Pins
int trig = 12;
int echo = 13;
float t=0;
float d=0;

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  d = (t/2)/29;
  readBuffer = "";
  start = false;
  Serial.println(d);
  // Reads the incoming data
  while (HC12.available()) {             // If HC-12 has data
    incomingByte = HC12.read();          // Store each icoming byte from HC-12
    delay(5);
    // Reads the data between the start "s" and end marker "e"
    if (start == true) {
      if (incomingByte != 'e') {
        readBuffer += char(incomingByte);    // Add each byte to ReadBuffer string variable
      }
      else {
        start = false;
      }
    }
    // Checks whether the received message statrs with the start marker "s"
    else if ( incomingByte == 's') {
      start = true; // If true start reading the message
    }
  }

  if ((readBuffer!="")){
    Serial.println(readBuffer);
    int index = readBuffer.indexOf('d');
    roll = readBuffer.substring(0, index).toInt();
    direction = readBuffer.substring(index+1).toInt();
    }
  if((d>=roll/5)|| (roll<=0)){
  motor2.setSpeed(roll);  //envoie la valeur de roll aux moteurs
  motor1.setSpeed(direction); //envoie la valeur reçue au servo
    }
    else{
      motor2.setSpeed(0);
      motor1.setSpeed(direction);
    } 



}
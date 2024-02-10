#include <L298NX2.h>

#include <SoftwareSerial.h>

// Pin definition
const unsigned int EN_A = 3;
const unsigned int IN1_A = 4;
const unsigned int IN2_A = 5;

const unsigned int IN1_B = 6;
const unsigned int IN2_B = 7;
const unsigned int EN_B = 9;

// Initialize both motors
L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

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

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12

}

void loop() {
  //Serial.println(HC12.read());

  readBuffer = "";
  start = false;
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

  if (readBuffer!=""){
  Serial.println(readBuffer);
  int index = readBuffer.indexOf('d');
  roll = readBuffer.substring(0, index).toInt();
  direction = readBuffer.substring(index+1).toInt();
  Serial.println(roll);
  Serial.println(direction);
  motors.setSpeedA(roll);  //envoie la valeur de roll aux moteurs
  motors.setSpeedB(roll); //envoie la valeur reçue au servo


  }

}
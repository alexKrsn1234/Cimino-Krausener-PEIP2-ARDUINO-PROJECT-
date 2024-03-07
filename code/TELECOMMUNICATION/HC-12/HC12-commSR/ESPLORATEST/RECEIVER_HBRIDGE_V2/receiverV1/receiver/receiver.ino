//#include <L298NX2.h>

#include <SoftwareSerial.h>

// Pin definition
const unsigned int EN_A = 3;
const unsigned int IN1_A = 4;
const unsigned int IN2_A = 5;

const unsigned int IN1_B = 6;
const unsigned int IN2_B = 7;
const unsigned int EN_B = 9;

const unsigned int IN1_C = 12;
const unsigned int IN2_C = 13;
const unsigned int EN_C= 6;




// Initialize both motors
//L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

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
  pinMode(EN_A,OUTPUT);
  pinMode(IN1_A,OUTPUT);
  pinMode(IN2_A,OUTPUT);
  pinMode(EN_B,OUTPUT);
  pinMode(IN1_B,OUTPUT);
  pinMode(IN2_B,OUTPUT);
  pinMode(EN_C,OUTPUT);
  pinMode(IN1_C,OUTPUT);
  pinMode(IN2_C,OUTPUT);
}

void rolling(int roll){
  if(roll>=0){
    digitalWrite(IN1_A,LOW);
    digitalWrite(IN2_A,HIGH);
    digitalWrite(IN1_B,LOW);
    digitalWrite(IN2_B,HIGH);
  }
  else{
    digitalWrite(IN1_A,HIGH);
    digitalWrite(IN2_A,LOW);
    digitalWrite(IN1_B,HIGH);
    digitalWrite(IN2_B,LOW);
  }
  analogWrite(EN_A, abs(roll));
  analogWrite(EN_B, abs(roll));
}

void turning (int direction){
  if(direction>=0){
  digitalWrite(IN1_C,LOW);
  digitalWrite(IN2_C,HIGH);
  }
  else{
    digitalWrite(IN1_C,HIGH);
    digitalWrite(IN2_C,LOW);
  }
  analogWrite(EN_C, abs(direction));
}

/*void turning(int direction){

}*/

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
  rolling(roll);  //envoie la valeur de roll aux moteurs
  //motors.setSpeedB(roll); //envoie la valeur reçue au servo
  turning(direction);

  }

}
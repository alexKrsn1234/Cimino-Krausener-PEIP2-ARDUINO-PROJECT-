#include <SoftwareSerial.h>

// Pin definition
const unsigned int EN_A = 3;
const unsigned int IN1_A = 4;
const unsigned int IN2_A = 5;

const unsigned int IN1_B = 2;
const unsigned int IN2_B = 7;
const unsigned int EN_B = 9;

const unsigned int EN_C = 6;
const unsigned int IN1_C=12;
const unsigned int IN2_C=13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);             // Serial port to computer      
  pinMode(EN_A,OUTPUT);
  pinMode(IN1_A,OUTPUT);
  pinMode(IN2_A,OUTPUT);
  pinMode(EN_B,OUTPUT);
  pinMode(IN1_B,OUTPUT);
  pinMode(IN2_B,OUTPUT);
  digitalWrite(IN1_A,HIGH);
  digitalWrite(IN2_A,LOW);
  digitalWrite(IN1_B,HIGH);
  digitalWrite(IN2_B,LOW);
  digitalWrite(IN1_C,HIGH);
  digitalWrite(IN2_C,LOW);
  digitalWrite(EN_A, HIGH);
  digitalWrite(EN_B, HIGH);
  digitalWrite(EN_C, HIGH);
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
  analogWrite(EN_A, roll);
  analogWrite(EN_B, roll);
}

void loop() {
  // put your main code here, to run repeatedly:

}

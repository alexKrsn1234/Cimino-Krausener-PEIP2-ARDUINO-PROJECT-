#include <SoftwareSerial.h>
#include <CytronMotorDriver.h>

// Configure the motor driver.
CytronMD motor1(PWM_PWM, 7, 6);   // PWM 1A = Pin 7, PWM 1B = Pin 6.
CytronMD motor2(PWM_PWM, 5, 4); // PWM 2A = Pin 5, PWM 2B = Pin 4.

//Configure the software Serial blabla
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin

//variables
char incommingByte;
String buffer;
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
  start=false;
  while(HC12.available()){
    incommingByte=HC12.read();
    if(incommingByte=='S'){
      buffer="";
      start = true;
    }
    else if (start==true){
      if(incommingByte!='E'){
        buffer+=incommingByte;
      }
      else{Serial.println(buffer);}
    }

    //delay(10);
  }  
  action = buffer.charAt(0);  //on récup la 1ère lettre du buffer pour sélectionner l'action à effectur
  value = atoi(buffer.charAt(1)); //ici on récup la valeur transmise
  if(action=='R'){
    motor1.setSpeed(value);  //envoie la valeur de roll aux moteurs
  } 
  else if(action=='D'){
    motor2.setSpeed(value); //envoie la valeur reçue au servo
  }
  else if(action=='B'){
    //TODO : procédure de réenvoie de bit
  }
    delay(1000);

}
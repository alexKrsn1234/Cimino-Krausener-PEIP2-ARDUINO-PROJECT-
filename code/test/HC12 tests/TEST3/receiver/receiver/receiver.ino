#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
char incommingByte;
String buffer;
boolean start = false;

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
  }        // read the joystick's X position  
    delay(1000);

}
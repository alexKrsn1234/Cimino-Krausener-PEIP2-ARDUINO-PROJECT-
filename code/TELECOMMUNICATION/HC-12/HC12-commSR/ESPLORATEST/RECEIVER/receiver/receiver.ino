#include <SoftwareSerial.h>

SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12

}

void loop() {
  while(HC12.available()){
    Serial.write(HC12.read());
    delay(10);
  }        // read the joystick's X position  
    Serial.println("");
    delay(900);

}
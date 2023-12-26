#include <SoftwareSerial.h>
#include <Esplora.h>

SoftwareSerial HC12(15, 14); // HC-12 TX Pin, HC-12 RX Pin

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12

}

void loop() {
  int xValue = Esplora.readJoystickX();        // read the joystick's X position
  int yValue = Esplora.readJoystickY(); 
  Serial.println(xValue);      
  HC12.print(xValue);      // Send that data to HC-12
  delay(1000);
  
}
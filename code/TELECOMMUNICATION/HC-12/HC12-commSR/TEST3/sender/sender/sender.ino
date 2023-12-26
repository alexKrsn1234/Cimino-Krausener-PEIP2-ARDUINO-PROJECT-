#include <SoftwareSerial.h>
SoftwareSerial HC12(10,11); // HC-12 TX Pin, HC-12 RX Pin

int value = 0;

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12

}

void loop() {     
  //HC12.print('S');      // Send that data to HC-12
  //HC12.print(value);
  //HC12.print('E');
  HC12.print("S" + String(value) + "E");
  value=1-value;
  delay(1000);
  
}
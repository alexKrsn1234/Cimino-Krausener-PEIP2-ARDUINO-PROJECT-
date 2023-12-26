#include <SoftwareSerial.h>

SoftwareSerial HC12(11, 10); // HC-12 TX Pin, HC-12 RX Pin

void setup() {
  pinMode(11, INPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);     
  Serial.println("start");          // Serial port to HC12

}

void loop() {
  while (HC12.available()) {        // If HC-12 has data
    Serial.println("a");
    Serial.write(HC12.read());      // Send the data to Serial monitor
  }
  //Serial.println("b");
}
#include <SoftwareSerial.h>

char data;
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);
  pinMode(6,OUTPUT);               // Serial port to HC12

}

void loop() {
  while (HC12.available()) {        // If HC-12 has data
    data=HC12.read();
    Serial.println(data);      // Send the data to Serial monitor
    if(data=='1'){
      digitalWrite(6,HIGH);
      delay(1000);

    }
  }
    digitalWrite(6,LOW);
    delay(1000);
}
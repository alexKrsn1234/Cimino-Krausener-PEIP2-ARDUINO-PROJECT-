/*
  Esplora Joystick Mouse

 This  sketch shows you how to read the joystick and use it to control the movement
 of the cursor on your computer.  You're making your Esplora into a mouse!

 WARNING: this sketch will take over your mouse movement. If you lose control
 of your mouse do the following:
 1) unplug the Esplora.
 2) open the EsploraBlink sketch
 3) hold the reset button down while plugging your Esplora back in
 4) while holding reset, click "Upload"
 5) when you see the message "Done compiling", release the reset button.

 This will stop your Esplora from controlling your mouse while you upload a sketch
 that doesn't take control of the mouse.

 Created on 22 Dec 2012
 by Tom Igoe
 Updated 8 March 2014
 by Scott Fitzgerald
 
 http://www.arduino.cc/en/Reference/EsploraReadJoystickSwitch

 This example is in the public domain.
 */

#include <Esplora.h>

void setup()
{
  Serial.begin(9600);     // take control of the mouse
}

void loop()
{
  int xValue = Esplora.readJoystickX();        // read the joystick's X position
  int yValue = Esplora.readJoystickY();        // read the joystick's Y position
  int button = Esplora.readJoystickSwitch();
  int slider = Esplora.readSlider();
  int lightsensor = Esplora.readLightSensor();
  int switch1= Esplora.readButton(switch1);

     // read the joystick pushbutton
  Serial.println("Joystick X: ");                // print a label for the X value
  Serial.println(xValue);                        // print the X value
  Serial.println("\tY: ");                       // print a tab character and a label for the Y value
  Serial.println(yValue);                        // print the Y value
  Serial.println("\tButton: ");                  // print a tab character and a label for the button
  Serial.println(button);  
  Serial.println(slider);  
  Serial.println(lightsensor); 
  Serial.println(switch1);                   // print the button value


  delay(10);                                  // a short delay before moving again
}


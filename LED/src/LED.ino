#include "Arduino.h"
// constants won't change. Used here to set a pin number:
const int ledPin =  2;// the number of the LED pin
const int buttonPin = 0;
uint8_t value = 0;

void setup() {
  // set the digital pin as output/input:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  value = digitalRead(buttonPin);
  Serial.printf("Button = %d\n\r",value);
  if (value == 0) {
    // set the LED with 1 when button is pressed:
    digitalWrite(ledPin, 1);
  }
  else{
    digitalWrite(ledPin, 0);
  } 
}

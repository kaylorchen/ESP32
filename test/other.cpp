//
// Created by Administrator on 19/04/14.
//

#include "other.h"
#include "HardwareSerial.h"

void other::setup() {
    Serial.begin(115200);
}

void other::loop() {
 delay(1000);
 Serial.println("This is a test.");
 Serial.println("FUCK!!!");
}
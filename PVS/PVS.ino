// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       PVS.ino
    Created:	7/13/2021 2:45:55 PM
    Author:     HKCLR\jdhuang
*/


#include <Arduino.h>
#include "hardware/eValve/electricValve.h"
#include "config/configurations.h"

void eValveInit() {
    Hardware::ElectricValve valve0(road_to_valve[0]);
    Hardware::ElectricValve valve1(road_to_valve[1]);
    Hardware::ElectricValve valve2(road_to_valve[2]);
    Hardware::ElectricValve valve3(road_to_valve[3]);
    valve0.init();
    valve1.init();
    valve2.init();
    valve3.init();
    valve0.setDuration(1);
    valve0.enableDuration();
    valve1.setDuration(1);
    valve1.enableDuration();
    valve2.setDuration(1);
    valve2.enableDuration();
    valve3.setDuration(1);
    valve3.enableDuration();
}

void setup() {
    eValveInit();
    pinMode(road_to_sensor[0], INPUT);
    //Serial.begin(115200);
    //Serial.print("Start system");
}


void loop() {
    analogWrite(road_to_valve[0], 10);
    analogWrite(road_to_valve[1], 10);
    analogWrite(road_to_valve[2], 10);
    analogWrite(road_to_valve[3], 10);

    int reading = analogRead(road_to_sensor[0]);
    //Serial.print(reading);
    //Serial.print('\n');
    //delay(100);
}
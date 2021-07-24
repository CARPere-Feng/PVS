// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       PVS.ino
    Created:	7/13/2021 2:45:55 PM
    Author:     HKCLR\jdhuang
*/


#include "hardware/eValve/electricValve.h"


void setup() {
    Hardware::ElectricValve* valve1 = new Hardware::ElectricValve(0, 'B');
    valve1->setDuration(100);   // 100 of 255
    valve1->init();
}

// the loop routine runs over and over again forever:
void loop() {
    //// set the brightness of pin 9:
    analogWrite(4, 100);

    //// change the brightness for next time through the loop:
    //brightness = brightness + fadeAmount;

    //// reverse the direction of the fading at the ends of the fade:
    //if (brightness <= 0 || brightness >= 255) {
    //    fadeAmount = -fadeAmount;
    //}
    //// wait for 30 milliseconds to see the dimming effect
    delay(10);
}
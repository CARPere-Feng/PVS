// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       PVS.ino
    Created:	7/13/2021 2:45:55 PM
    Author:     HKCLR\jdhuang
*/



#include "hardware/PWM/iPWM.h"

int led = 4;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
    // declare pin 9 to be an output:
    TCCR0B = (TCCR0B & 0b11111000) | 0x05;
    pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
    // set the brightness of pin 9:
    analogWrite(led, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
}
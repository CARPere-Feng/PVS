/*
    Name:       PVS.ino
    Created:	7/13/2021 2:45:55 PM
    Author:     HKCLR\jdhuang
*/



#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "hardware/controller/selfPID.h"
#include "hardware/eValve/electricValve.h"
#include "hardware/sensor/Pres100300.h"
#include "systems/Origami.h"

void setup() {
    for (int i = 0; i < 5; i++)
    {
        // initialize electric valves
        valve_positive[i].init(); valve_positive[i].setDuration(0); valve_positive[i].enableDuration();
        valve_negtive[i].init(); valve_negtive[i].setDuration(0); valve_negtive[i].enableDuration();
    
        // initialize sensor
        sensors[i].init();
    }
    
    // initialize serial port
    Serial.begin(9600);    // initialize serial
}

void loop() {
    // update sensor input
    controlLoop();
}
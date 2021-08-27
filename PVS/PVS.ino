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

#include "hardware/controller/pidController.h"
#include "hardware/eValve/electricValve.h"
#include "hardware/sensor/Pres100300.h"
#include "systems/Origami.h"


void setup() {
    // initialize electric valves
    valve_pos1.init(); valve_pos1.setDuration(100); valve_pos1.enableDuration();
    valve_pos2.init(); valve_pos2.setDuration(100); valve_pos2.enableDuration(); 
    valve_pos3.init(); valve_pos3.setDuration(100); valve_pos3.enableDuration();
    valve_pos4.init(); valve_pos4.setDuration(100); valve_pos4.enableDuration();
    valve_pos5.init(); valve_pos5.setDuration(100); valve_pos5.enableDuration();
    valve_neg1.init(); valve_neg1.setDuration(100); valve_neg1.enableDuration();
    valve_neg2.init(); valve_neg2.setDuration(100); valve_neg2.enableDuration();
    valve_neg3.init(); valve_neg3.setDuration(100); valve_neg3.enableDuration();
    valve_neg4.init(); valve_neg4.setDuration(100); valve_neg4.enableDuration();
    valve_neg5.init(); valve_neg5.setDuration(100); valve_neg5.enableDuration();

    // initialize sensor
    sensor1.init();
    sensor2.init();
    sensor3.init();
    sensor4.init();
    sensor5.init();

    // initialize PID, turn the PID on
    pi1.SetMode(AUTOMATIC); pi1.SetOutputLimits(-255, 255);
    pi2.SetMode(AUTOMATIC); pi2.SetOutputLimits(-255, 255);
    pi3.SetMode(AUTOMATIC); pi3.SetOutputLimits(-255, 255);
    pi4.SetMode(AUTOMATIC); pi4.SetOutputLimits(-255, 255);
    pi5.SetMode(AUTOMATIC); pi5.SetOutputLimits(-255, 255);

    // initialize serial port
    Serial.begin(38400);    // initialize serial
}

void loop() {
    // electric valve pwm
    valve_pos1.setDuration(100);
    valve_pos1.enableDuration();

    // update sensor input
    double sensor1_Kpa = sensor1.pressureKPa();

    //// one control loop
    //input = sensor1_Kpa; setpoint = input - 3; // control it to 5 KPa
    //if (pi1.npCompute()) {
    //    valveve.setDuration(output);    // analogWrite(PIN_OUTPUT, output_value)
    //    valveve.enableDuration();
    //}

    // send serial message to computer
    Serial.print(sensor1_Kpa);
    // Serial.print(senser1.readVolt());   // print the data to the serial
    Serial.print('\n');
    delay(100);
}
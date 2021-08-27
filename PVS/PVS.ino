/*
    Name:       PVS.ino
    Created:	7/13/2021 2:45:55 PM
    Author:     HKCLR\jdhuang
*/



#include <Arduino.h>
#include "hardware/controller/pidController.h"
#include "hardware/eValve/electricValve.h"
#include "hardware/sensor/Pres100300.h"

int vpos[] = { 2, 3, 4, 5, 6, 7 };
int vneg[] = { 8, 9, 10, 11, 12, 13 };
int prsSensor[] = { A10, A11, A12, A13, A14, A15 };
double Kp = 2, Ki = 1, Kd = 0;
double input = 0, output = 0, setpoint = 0;

// create electric valve
Hardware::ElectricValve valveve(vpos[0]);
Hardware::PIDController pi1(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);
Hardware::Sensor::Pres100300 senser1(prsSensor[5]);

void setup() {
    // initialize electric valves
    valveve.init();
    valveve.setDuration(200);
    valveve.enableDuration();

    // initialize sensor
    senser1.init();

    // initialize PID, turn the PID on
    pi1.SetMode(AUTOMATIC);
    pi1.SetOutputLimits(-255, 255);

    // initialize serial port
    Serial.begin(38400);    // initialize serial
}

void loop() {
    // update sensor input
    double sensor1_Kpa = senser1.pressureKPa();

    // one control loop
    input = sensor1_Kpa; setpoint = input - 3; // control it to 5 KPa
    if (pi1.npCompute()) {
        valveve.setDuration(output);    // analogWrite(PIN_OUTPUT, output_value)
        valveve.enableDuration();
    }

    // send serial message to computer
    Serial.print(output);
    // Serial.print(senser1.readVolt());   // print the data to the serial
    Serial.print('\n');
    delay(100);
}
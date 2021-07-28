// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       PVS.ino
    Created:	7/13/2021 2:45:55 PM
    Author:     HKCLR\jdhuang
*/


#include <Arduino.h>
#include "hardware/eValve/electricValve.h"

int vpos[] = { 2, 3, 4, 5, 6, 7 };
int vneg[] = { 8, 9, 10, 11, 12, 13 };
//Hardware::ElectricValve* valve0 = new Hardware::ElectricValve(3, 'B', vpos[0]);
//Hardware::ElectricValve* valve1 = new Hardware::ElectricValve(3, 'C', vpos[1]);
//Hardware::ElectricValve* valve2 = new Hardware::ElectricValve(0, 'B', vpos[2]);
//Hardware::ElectricValve* valve3 = new Hardware::ElectricValve(3, 'A', vpos[3]);
//Hardware::ElectricValve* valve4 = new Hardware::ElectricValve(4, 'A', vpos[4]);
//Hardware::ElectricValve* valve5 = new Hardware::ElectricValve(4, 'B', vpos[5]);

void setup() {
    Hardware::ElectricValve valveve(vpos[3]);
    valveve.init();
    valveve.setDuration(1);
    valveve.enableDuration();
    
    //valve0->init();
    //valve1->init();
    //valve2->init();
    //valve3->init();
    //valve4->init();
    //valve5->init();
}


void loop() {
    analogWrite(vpos[3], 10);
    delay(100);
}
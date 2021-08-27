#ifndef _SYSTEMS_ORIGAMI_H_
#define _SYSTEMS_ORIGAMI_H_

#include "../hardware/controller/pidController.h"
#include "../hardware/eValve/electricValve.h"
#include "../hardware/sensor/Pres100300.h"
#include "../utils/definition.h"

int vpos[] = { 2, 3, 4, 5, 6, 7 };
int vneg[] = { 8, 9, 10, 11, 12, 13 };
int prsSensor[] = { A10, A11, A12, A13, A14, A15 };
double Kp = 2, Ki = 1, Kd = 0;
double input[] = { 0, 0, 0, 0, 0 };
double output[] = { 0, 0, 0, 0, 0 };
double setpoint[] = { 0, 0, 0, 0, 0 };

// create electric valves
Hardware::ElectricValve triCom(valve_, pos, 1)(vpos[0]);
Hardware::ElectricValve triCom(valve_, pos, 2)(vpos[1]);
Hardware::ElectricValve triCom(valve_, pos, 3)(vpos[2]);
Hardware::ElectricValve triCom(valve_, pos, 4)(vpos[3]);
Hardware::ElectricValve triCom(valve_, pos, 5)(vpos[4]);
Hardware::ElectricValve triCom(valve_, neg, 1)(vneg[5]);
Hardware::ElectricValve triCom(valve_, neg, 2)(vneg[4]);
Hardware::ElectricValve triCom(valve_, neg, 3)(vneg[3]);
Hardware::ElectricValve triCom(valve_, neg, 4)(vneg[2]);
Hardware::ElectricValve triCom(valve_, neg, 5)(vneg[1]);

// create sensors
Hardware::Sensor::Pres100300 sensor1(prsSensor[0]);
Hardware::Sensor::Pres100300 sensor2(prsSensor[1]);
Hardware::Sensor::Pres100300 sensor3(prsSensor[2]);
Hardware::Sensor::Pres100300 sensor4(prsSensor[3]);
Hardware::Sensor::Pres100300 sensor5(prsSensor[4]);

// create PID controllers
Hardware::PIDController pi1(input+0, output+0, setpoint+0, Kp, Ki, Kd, DIRECT);
Hardware::PIDController pi2(input+1, output+1, setpoint+1, Kp, Ki, Kd, DIRECT);
Hardware::PIDController pi3(input+2, output+2, setpoint+2, Kp, Ki, Kd, DIRECT);
Hardware::PIDController pi4(input+3, output+3, setpoint+3, Kp, Ki, Kd, DIRECT);
Hardware::PIDController pi5(input+4, output+4, setpoint+4, Kp, Ki, Kd, DIRECT);



#endif // !_SYSTEMS_ORIGAMI_H_

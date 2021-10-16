#ifndef _SYSTEMS_ORIGAMI_H_
#define _SYSTEMS_ORIGAMI_H_

#include "../hardware/controller/selfPID.h"
#include "../hardware/eValve/electricValve.h"
#include "../hardware/sensor/Pres4067.h"
#include "../utils/definition.h"

int vpos[] = { 2, 3, 4, 5, 6, 7 };
int vneg[] = { 8, 9, 10, 11, 12, 13 };
int prsSensor[] = { A10, A11, A12, A13, A14, A15 };
int prsDesired[] = { A0, A1 };
double headPrsMin = -30, headPrsMax = 20;
double legPrsMin = -30, legPrsMax = 20;
double Kp_head = 10, Ki_head = 0, Kd_head = 0;
double Kp = 10, Ki = 0, Kd = 0;
double input[] = { 0, 0, 0, 0, 0 };
double output[] = { 0, 0, 0, 0, 0 };
double setpoint[] = { 10, 0, 0, 0, 0 };

// create electric valves
Hardware::ElectricValve* valve_positive = new Hardware::ElectricValve[5]{
	Hardware::ElectricValve(vpos[0]),
	Hardware::ElectricValve(vpos[1]),
	Hardware::ElectricValve(vpos[2]),
	Hardware::ElectricValve(vpos[3]),
	Hardware::ElectricValve(vpos[4])
};
Hardware::ElectricValve* valve_negtive = new Hardware::ElectricValve[5]{
	Hardware::ElectricValve(vneg[1]),
	Hardware::ElectricValve(vneg[2]),
	Hardware::ElectricValve(vneg[3]),
	Hardware::ElectricValve(vneg[4]),
	Hardware::ElectricValve(vneg[5])
};

// create sensors
Hardware::Sensor::Pres4067* sensors = new Hardware::Sensor::Pres4067[5]{
	Hardware::Sensor::Pres4067(prsSensor[5]),
	Hardware::Sensor::Pres4067(prsSensor[4]),
	Hardware::Sensor::Pres4067(prsSensor[3]),
	Hardware::Sensor::Pres4067(prsSensor[2]),
	Hardware::Sensor::Pres4067(prsSensor[1])
	};

// create PID controllers
Hardware::SelfPid* piController = new Hardware::SelfPid[5]{
	Hardware::SelfPid(input + 0, output + 0, setpoint + 0, Kp_head, Ki_head, Kd_head),
	Hardware::SelfPid(input + 1, output + 1, setpoint + 1, Kp, Ki, Kd),
	Hardware::SelfPid(input + 2, output + 2, setpoint + 2, Kp, Ki, Kd),
	Hardware::SelfPid(input + 3, output + 3, setpoint + 3, Kp, Ki, Kd),
	Hardware::SelfPid(input + 4, output + 4, setpoint + 4, Kp, Ki, Kd)
};

void controlLoop() {
	double sensorValue[2];
	sensorValue[0] = (double)(analogRead(prsDesired[0]))/1023*(headPrsMax - headPrsMin) + headPrsMin;
	sensorValue[1] = (double)(analogRead(prsDesired[1])) / 1023 * (legPrsMax - legPrsMin) + legPrsMin;
	//Serial.println(sensorValue[0]); Serial.println(sensorValue[1]);
	setpoint[0] = sensorValue[0];
	setpoint[1] = sensorValue[1];

	for (int i = 0; i < 2; i++) {
		input[i] = sensors[i].pressureKPa();
		Serial.print(i); Serial.write(13); Serial.write(10);
		Serial.print(input[i]);Serial.write(13);Serial.write(10);
		if (piController[i].spcfCompute()) {
			valve_positive[i].setDuration(piController[i].getPosOutput());
			valve_negtive[i].setDuration(piController[i].getNegOutput());
			valve_positive[i].enableDuration();
			valve_negtive[i].enableDuration();
		}
	}
}


#endif // !_SYSTEMS_ORIGAMI_H_

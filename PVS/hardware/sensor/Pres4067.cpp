#include "Pres4067.h"

Hardware::Sensor::Pres4067::Pres4067(const int& pin) : AnalogSensor(pin) {}

double Hardware::Sensor::Pres4067::pressureMPa() {
	double kpa = pressureKPa();
	return kpa * 0.001;
}

double Hardware::Sensor::Pres4067::pressureKPa() {
	int read_voltage_num = this->readVolt();
	return (0.1262*read_voltage_num - 52.866);
}
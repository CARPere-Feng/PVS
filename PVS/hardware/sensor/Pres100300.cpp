#include "Pres100300.h"

Hardware::Sensor::Pres100300::Pres100300(const int& pin) : AnalogSensor(pin) {}

double Hardware::Sensor::Pres100300::pressureMPa() {
	int read_voltage_num = this->readVolt();
	return (0.0005 * read_voltage_num - 0.1441);
}

double Hardware::Sensor::Pres100300::pressureKPa() {
	double mpa = pressureMPa();
	return mpa * 1000;
}
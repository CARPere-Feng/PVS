#include "AnalogSensor.h"

Hardware::Sensor::AnalogSensor::AnalogSensor(const int& pin) {
	pin_num_ = pin;
}

void Hardware::Sensor::AnalogSensor::init() {
	pinMode(pin_num_, INPUT);
}

int Hardware::Sensor::AnalogSensor::readVolt() {
	return analogRead(pin_num_);
}
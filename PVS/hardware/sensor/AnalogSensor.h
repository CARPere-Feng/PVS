#ifndef _ANALOG_SENSOR_H_
#define _ANALOG_SENSOR_H_

#include <Arduino.h>

namespace Hardware {
	namespace Sensor {

		class AnalogSensor
		{
		public:
			explicit AnalogSensor(const int& pin);
			~AnalogSensor() = default;

			void init();
			int readVolt();
		private:
			int pin_num_;
		};

	}	// namespace Sensor
}	// namespace Hardware

#endif // !_ANALOG_SENSOR_H_

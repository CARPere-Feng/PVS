#ifndef _ANALOG_SENSOR_H_
#define _ANALOG_SENSOR_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

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

#ifndef _PRESSURE_SENSOR_4067_H_
#define _PRESSURE_SENSOR_4067_H_

#include "AnalogSensor.h"

namespace Hardware {
	namespace Sensor {
		class Pres4067 : public AnalogSensor
		{
		public:
			explicit Pres4067(const int& pin);
			~Pres4067() = default;

			double pressureMPa();
			double pressureKPa();
		private:

		};
	}
}

#endif
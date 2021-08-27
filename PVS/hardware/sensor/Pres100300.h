#ifndef _PRESSURE_SENSOR_100_300_H_
#define _PRESSURE_SENSOR_100_300_H_

#include "AnalogSensor.h"

namespace Hardware {
namespace Sensor {
	class Pres100300 : public AnalogSensor
	{
	public:
		explicit Pres100300(const int& pin);
		~Pres100300() = default;

		double pressureMPa();
		double pressureKPa();
	private:

	};
}
}
#endif // _PRESSURE_SENSOR_100_300_H_

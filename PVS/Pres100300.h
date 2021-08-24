#ifndef _PRESSURE_SENSOR_100_300_H_
#define _PRESSURE_SENSOR_100_300_H_

#define PRESSUREMPA(a) (0.0005*a - 0.1441)

namespace Hardware {
namespace Pres100300 {

	int pressureMPa(const int& num) {
		return 0.0005 * num - 0.1441;
	}

}	// namespace Pres100300
}	// namespace Hardware

#endif // !_PRESSURE_SENSOR_100_300_H_

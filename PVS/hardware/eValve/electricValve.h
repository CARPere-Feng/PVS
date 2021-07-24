#ifndef _ELECTRIC_VALVE_h
#define _ELECTRIC_VALVE_h

#include "../PWM/iFastPWM.h"

namespace Hardware {
class ElectricValve : public FastPWM
{
public:
	ElectricValve() = default;
	explicit ElectricValve(const int& timer_num, const char& port_num);
	~ElectricValve() = default;

	virtual void init();
};
}	// namespace Hardware
#endif
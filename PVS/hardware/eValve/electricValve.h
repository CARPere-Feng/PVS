#ifndef _ELECTRIC_VALVE_h
#define _ELECTRIC_VALVE_h

#include "../PWM/iFastPWM.h"

namespace Hardware {
class ElectricValve : public FastPWM
{
public:
	ElectricValve() = default;
	explicit ElectricValve(const int& pin_num);
	~ElectricValve() = default;

	//// no copy, no assign, no move
	//ElectricValve(const ElectricValve&) = delete;
	//ElectricValve& operator=(const ElectricValve&) = delete;


	virtual void init();
};
}	// namespace Hardware
#endif
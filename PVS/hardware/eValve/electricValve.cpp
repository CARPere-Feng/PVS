#include "electricValve.h"

namespace Hardware {
	ElectricValve::ElectricValve(const int& timer_num, const char& port_num) :
		FastPWM(timer_num, port_num){
		setFreqDiv(1024); // the electric valve's default divider is 1024
	}

	void ElectricValve::init() {
		initFastPWM();
	}
}
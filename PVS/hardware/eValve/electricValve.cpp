#include "electricValve.h"

namespace Hardware {
	ElectricValve::ElectricValve(const int& pin_num) :
		FastPWM(pin_num){
		setFreqDiv(1024); // the electric valve's default divider is 1024
	}

	void ElectricValve::init() {
		initFastPWM();
	}
}
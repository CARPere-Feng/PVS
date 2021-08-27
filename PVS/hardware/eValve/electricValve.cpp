#include "electricValve.h"

namespace Hardware {
	ElectricValve::ElectricValve(const int& pin_num) :
		FastPWM(pin_num){
	}

	void ElectricValve::init() {
		setFreqDiv(1024); // the electric valve's default divider is 1024
		initFastPWM();
	}
}
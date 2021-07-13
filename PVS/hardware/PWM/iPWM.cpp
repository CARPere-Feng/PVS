#include "iPWM.h"

namespace Hardware {
	template <typename T>
	PWM::PWM(const T pin_num) {
		pinNum = pin_num;
		initWidth = 0;
		increment = 5;
	}

	template <typename T>
	PWM::PWM(const T pin_num, const int wid, const int inc) {
		pinNum = pin_num;
		initWidth = wid;
		increment = inc;
	}

	void PWM::initPWM() {
		pinMode(pinNum, OUTPUT);
	}

} // namespace Hardware
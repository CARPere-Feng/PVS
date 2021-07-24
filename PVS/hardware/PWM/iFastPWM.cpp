#include "iFastPWM.h"

namespace Hardware {

	FastPWM::FastPWM(const int& timer_num, const char& port_num) {
		timer = timer_num;
		portNum = port_num;
	}

	void FastPWM::setPWMFreq(const int& divider) {
		if (timer == 2) {
			switch (divider)
			{
			case 1:
				TCCR2B &= 0xf8; TCCR2B |= 0x01; break;
			case 8:
				TCCR2B &= 0xf8; TCCR2B |= 0x02; break;
			case 32:
				TCCR2B &= 0xf8; TCCR2B |= 0x03; break;
			case 64:
				TCCR2B &= 0xf8; TCCR2B |= 0x04; break;
			case 128:
				TCCR2B &= 0xf8; TCCR2B |= 0x05; break;
			case 256:
				TCCR2B &= 0xf8; TCCR2B |= 0x06; break;
			case 1024:
				TCCR2B &= 0xf8; TCCR2B |= 0x07; break;
			default:
				break;
			}
		}
		else if (timer == 0) {
			switch (divider)
			{
			case 1:
				TCCR0B &= 0xf8; TCCR0B |= 0x01; break;
			case 8:
				TCCR0B &= 0xf8; TCCR0B |= 0x02; break;
			case 64:
				TCCR0B &= 0xf8; TCCR0B |= 0x03; break;
			case 256:
				TCCR0B &= 0xf8; TCCR0B |= 0x04; break;
			case 1024:
				TCCR0B &= 0xf8; TCCR0B |= 0x05; break;
			default:
				break;
			}
		}
		else if (timer == 1) {
			switch (divider)
			{
			case 1:
				TCCR1B &= 0xf8; TCCR1B |= 0x01; break;
			case 8:
				TCCR1B &= 0xf8; TCCR1B |= 0x02; break;
			case 64:
				TCCR1B &= 0xf8; TCCR1B |= 0x03; break;
			case 256:
				TCCR1B &= 0xf8; TCCR1B |= 0x04; break;
			case 1024:
				TCCR1B &= 0xf8; TCCR1B |= 0x05; break;
			default:
				break;
			}
		}
		else if (timer == 3) {
			switch (divider)
			{
			case 1:
				TCCR3B &= 0xf8; TCCR3B |= 0x01; break;
			case 8:
				TCCR3B &= 0xf8; TCCR3B |= 0x02; break;
			case 64:
				TCCR3B &= 0xf8; TCCR3B |= 0x03; break;
			case 256:
				TCCR3B &= 0xf8; TCCR3B |= 0x04; break;
			case 1024:
				TCCR3B &= 0xf8; TCCR3B |= 0x05; break;
			default:
				break;
			}
		}
		else if (timer == 4) {
			switch (divider)
			{
			case 1:
				TCCR4B &= 0xf8; TCCR4B |= 0x01; break;
			case 8:
				TCCR4B &= 0xf8; TCCR4B |= 0x02; break;
			case 64:
				TCCR4B &= 0xf8; TCCR4B |= 0x03; break;
			case 256:
				TCCR4B &= 0xf8; TCCR4B |= 0x04; break;
			case 1024:
				TCCR4B &= 0xf8; TCCR4B |= 0x05; break;
			default:
				break;
			}
		}
		else if (timer == 5) {
			switch (divider)
			{
			case 1:
				TCCR5B &= 0xf8; TCCR5B |= 0x01; break;
			case 8:
				TCCR5B &= 0xf8; TCCR5B |= 0x02; break;
			case 64:
				TCCR5B &= 0xf8; TCCR5B |= 0x03; break;
			case 256:
				TCCR5B &= 0xf8; TCCR5B |= 0x04; break;
			case 1024:
				TCCR5B &= 0xf8; TCCR5B |= 0x05; break;
			default:
				break;
			}
		}
	}

	int FastPWM::setDuration(const double& max, const double& value) {
		const int width = value / max * 255;
		setWidth(width);
		return 1;
	}

	int FastPWM::setDuration(const int& wid) {
		setWidth(wid);
		return 1;
	}

	int FastPWM::setFreqDiv(const int& divider) {
		div = divider;
		setPWMFreq(div);
	}

	void FastPWM::initFastPWM() {
		pinMode(4, OUTPUT);
	}
} // namespace Hardware
#include "iFastPWM.h"

namespace Hardware {

	FastPWM::FastPWM(const int& pin_num) {
		pin_num_ = pin_num;
	}

	void FastPWM::setPWMFreq(const int& divider) {
		switch (digitalPinToTimer(pin_num_) )
		{
		case TIMER2A :
		case TIMER2B :
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
			break;
		case TIMER0A :
		case TIMER0B :
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
			break;
		case TIMER1A:
		case TIMER1B:
		case TIMER1C:
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
			break;
		case TIMER3A:
		case TIMER3B:
		case TIMER3C:
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
			break;
		case TIMER4A:
		case TIMER4B:
		case TIMER4C:
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
			break;
		case TIMER5A:
		case TIMER5B:
		case TIMER5C:
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
			break;
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

	int FastPWM::enableDuration() {
		analogWrite(pin_num_, width);
	}


	int FastPWM::setFreqDiv(const int& divider) {
		div = divider;
		setPWMFreq(div);
	}

	void FastPWM::initFastPWM() {
		pinMode(pin_num_, OUTPUT);
	}
} // namespace Hardware
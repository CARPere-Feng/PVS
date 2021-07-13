// iPWM.h

#ifndef _IPWM_h
#define _IPWM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

namespace Hardware {
class PWM
{
public:
	PWM() = default;
	template <typename T>
	explicit PWM(const T);

	template <typename T>
	explicit PWM(const T, const int, const int);

	// no copy, no assign, no move
	PWM(const PWM&) = delete;
	PWM& operator=(const PWM&) = delete;
	~PWM() = default;

	void initPWM();
	void setPWM();
	void setInitWidth(const int& a) { initWidth = a; }
	void setIncrement(const int& a) { increment = a; }
private:
	int pinNum;
	int initWidth;
	int increment;
};	// class PWM
}	// namespace Hardware

#endif


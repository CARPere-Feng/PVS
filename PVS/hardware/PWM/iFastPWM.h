// iFastPWM.h

// PWM timer frequency and pin number, please refer to 
// https://docs.google.com/document/d/1m9kcWk5B24FywZJoS_uw5IurtLN0VFsLnJK7B0ozWGE/edit
#ifndef _IFASTPWM_h
#define _IFASTPWM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

namespace Hardware {
class FastPWM
{
public:
	FastPWM() = default;
	explicit FastPWM(const int& timer_num, const char& port_num);

	// no copy, no assign, no move
	FastPWM(const FastPWM&) = delete;
	FastPWM& operator=(const FastPWM&) = delete;
	~FastPWM() = default;

	// set the duration of high voltage within one cycle
	int setDuration(const double& max, const double& value);
	int setDuration(const int& wid);

	// set the PWM frequence divider
	int setFreqDiv(const int& divider);

	// the init function to init PWM device
	virtual void init() = 0;
	// the init function to init PWM interface
	void initFastPWM();

private:
	void setPWMFreq(const int&);
	void setWidth(const int& a) { width = a; }

public:
	int timer;	// which timer is this pwm port uses
	char portNum; // PWM output port number

protected:
	int div;
	int width;	// High voltage width

};	// class PWM
}	// namespace Hardware

#endif


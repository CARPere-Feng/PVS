#ifndef _PID_CONTROLLER_H_
#define _PID_CONTROLLER_H_

#include "Pres100300.h"

namespace Hardware {
class PIDController
{
public:
	PIDController() = default;
	~PIDController() = default;

	void input(const double& des, const double& prs);
	int compute();
	int output();

private:
	int ctrlOutput_ = 0;
	double desired_ = 0;
	int curpressure_ = 0;

	double P = 0;
	double I = 0;
	double D = 0;
};	// class PID
}	// namespace Hardware

#endif
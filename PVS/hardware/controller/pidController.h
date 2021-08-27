#ifndef _PID_CONTROLLER_H_
#define _PID_CONTROLLER_H_

#include <PID_v1.h>

namespace Hardware {
class PIDController : public ::PID
{
public:
	PIDController() = default;
	explicit PIDController(double*, double*, double*,        // * constructor.  links the PID to the Input, Output, and 
						   double, double, double, int);//   Setpoint.  Initial tuning parameters are also set here.
	~PIDController() = default;

	bool npCompute();

	double getPosOutput() { return pos_output_; }
	double getNegOutput() { return neg_output_; }
private:
	double neg_output_ = 0;
	double pos_output_ = 0;
	double* output_;
};	// class PID
}	// namespace Hardware

#endif
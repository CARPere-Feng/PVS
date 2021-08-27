#include "pidController.h"

Hardware::PIDController::PIDController(double* input, double* output, 
	double* setpoint, double Kp, double Ki, double Kd, int mode) :
	PID(input, output, setpoint, Kp, Ki, Kd, mode), output_(output){}

bool Hardware::PIDController::npCompute() {
	if (this->Compute()) {
		if (*output_ > 0) {
			pos_output_ = *output_;
			neg_output_ = 0;
		}
		else
		{
			pos_output_ = 0;
			neg_output_ = -(*output_);
		}
		return true;
	}
	return false;
}
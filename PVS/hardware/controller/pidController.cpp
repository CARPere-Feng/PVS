#include "pidController.h"

Hardware::PIDController::PIDController(double* input, double* output, 
	double* setpoint, double Kp, double Ki, double Kd, int mode) :
	PID(input, output, setpoint, Kp, Ki, Kd, mode){}

bool Hardware::PIDController::npCompute() {
	if (this->Compute()) {
		if (output > 0) {
			pos_output_ = output;
			neg_output_ = 0;
		}
		else
		{
			pos_output_ = 0;
			neg_output_ = -output;
		}
		return true;
	}
	return false;
}
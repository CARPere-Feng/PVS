#include "selfPID.h"

Hardware::SelfPid::SelfPid(double* input, double* output, double* setpoint, double kp, double ki, double kd) {
	input_ = input;
	output_ = output;
	setpoint_ = setpoint;
	Kp_ = kp; Ki_ = ki; Kd_ = kd;
}

void Hardware::SelfPid::Compute() {
	unsigned long now = micros();
	double timeChange = (double)(now - lastTime_);

	double error = *setpoint_ - *input_;
	errSum_ += (error * timeChange);
	if (timeChange == 0) timeChange = 1;
	double dErr = (error - lastErr_) / timeChange;

	*output_ = Kp_ * error + Ki_ * errSum_ + Kd_ * dErr;

	lastErr_ = error;
	lastTime_ = now;
}

bool Hardware::SelfPid::spcfCompute() {
	Compute();
	if (*output_ > 0) {
		if (*output_ > 255) *output_ = 255;
		posOutput_ = *output_;
		negOutput_ = 0;
	}
	else
	{
		if (*output_ < -255) *output_ = -255;
		posOutput_ = 0;
		negOutput_ = -(*output_);
	}
	return true;
}

void Hardware::SelfPid::setTunings(const double kp, const double ki, const double kd) {
	Kp_ = kp;
	Ki_ = ki;
	Kd_ = kd;
}
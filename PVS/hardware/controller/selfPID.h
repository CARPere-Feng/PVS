#ifndef _SELF_PID_CONTROLLER_H_
#define _SELF_PID_CONTROLLER_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Hardware {

	class SelfPid
	{
	public:
		SelfPid() = default;
		explicit SelfPid(double*, double*, double*,
						double, double, double);
		~SelfPid() = default;

		void Compute();
		virtual bool spcfCompute();	// seperate the positive and negtive computation
		void setTunings(const double kp, const double ki, const double kd);
		double getPosOutput() { return posOutput_; }
		double getNegOutput() { return negOutput_; }
		double getOutput() { return *output_; }
	private:
		double Kp_ = 0;
		double Ki_ = 0;
		double Kd_ = 0;
		double *input_, *output_, *setpoint_;
		double posOutput_ = 0, negOutput_ = 0;
		double errSum_, lastErr_;
		unsigned long lastTime_;
	};	// class SelfPid
}	// namespace Hardware

#endif // !_SELF_PID_CONTROLLER_H_

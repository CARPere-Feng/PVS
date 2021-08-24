#include "pidController.h"

/// <summary>
/// the input of controller
/// </summary>
/// <param name="des">desired output</param>
/// <param name="prs">pressure value deteceted from sensor</param>
void Hardware::PIDController::input(const double& des, const double& prs) {
	desired_ = des;
	curpressure_ = prs;
}

/// <summary>
/// compute control output
/// </summary>
/// <return>control output</return>
int Hardware::PIDController::compute() {

}

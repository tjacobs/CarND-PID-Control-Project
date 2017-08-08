#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
}

void PID::UpdateError(double cte) {

	// Save
	this->cte_old = this->cte;
	this->cte = cte;
	this->cte_total *= 0.9;
	this->cte_total += cte;

}

double PID::TotalError() {

	// P, I, D
	double total = - Kp * cte
				   - Ki * cte_total
				   - Kd * (cte - cte_old);
	return total;
}


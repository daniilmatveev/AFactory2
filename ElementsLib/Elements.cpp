#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "Elements.h"
#include <cmath>
#include <numeric>


Resistance::Resistance(const double& value)
{
	R = value;
}

std::complex<double> Resistance::CalcImpedance(const double& freq)
{
	return R;
}

Inductance::Inductance(const double& value)
{
	L = value;
}

std::complex<double> Inductance::CalcImpedance(const double& freq)
{
	return { 0, 2 * M_PI*freq*L };
}

Capacitance::Capacitance(const double& value)
{
	C = value;
}

std::complex<double> Capacitance::CalcImpedance(const double& freq)
{
	return { 0, -1 / M_PI / 2 / freq / C };
}

SeriesConnection::SeriesConnection()
{
	
}

std::complex<double> SeriesConnection::CalcImpedance(const double& freq)
{
	std::complex<double> res{ 0,0 };
	for (auto p : els)
		res += p->CalcImpedance(freq);
	return res;
}
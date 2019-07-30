#pragma once
#include "Interfaces.h"

class Resistance :
	public IElement
{
public:
	Resistance(const double& value = 1);
	std::complex<double> CalcImpedance(const double& freq);

private:
	double R;
};

class Inductance :
	public IElement
{
public:
	Inductance(const double& value = 0);
	virtual ~Inductance() {}
	std::complex<double> CalcImpedance(const double& freq);

private:
	double L;
};

class Capacitance :
	public IElement
{
public:
	Capacitance(const double& value = 1);
	virtual ~Capacitance() {}
	std::complex<double> CalcImpedance(const double& freq);

private:
	double C;
};

class SeriesConnection :
	public IElement
{
public:
	SeriesConnection();
	std::complex<double> CalcImpedance(const double& freq);

private:
	std::vector<IElement*> els;
};

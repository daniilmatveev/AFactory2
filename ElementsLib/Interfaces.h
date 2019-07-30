#pragma once
#include <memory>
#include <string>
#include <vector>
#include <complex>
class IElement
{
public:
	virtual std::complex<double> CalcImpedance(const double& freq) = 0;
	virtual ~IElement() {}
};

class IElementFactory
{
public:
	virtual std::unique_ptr<IElement> make(const std::string& type, const double& value) = 0;
	virtual std::vector<std::string> getElementNames() = 0;
};
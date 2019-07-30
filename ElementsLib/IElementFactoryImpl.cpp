#include "stdafx.h"
#include "IElementFactoryImpl.h"
#include "Interfaces.h"
#include "Elements.h"
#include <vector>
#include <string>
#include <memory>

std::unique_ptr<IElement> IElementFactoryImpl::make(const std::string& type, const double& value)
{
	std::unique_ptr<IElement> ret;
	if (type == "Resistance")
		ret = std::make_unique<Resistance>(value);
	else if (type == "Inductance")
		ret = std::make_unique<Inductance>(value);
	else if (type == "Capacitance")
		ret = std::make_unique<Capacitance>(value);
	else if (type == "SeriesConnection")
	{

	}
	return ret;
}

std::vector<std::string> IElementFactoryImpl::getElementNames()
{
	return std::vector<std::string> {"Resistance", "Inductance", "Capacitance", "SeriesConnection"};
}

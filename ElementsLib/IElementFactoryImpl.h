#pragma once
#include "Interfaces.h"
#include <string>
#include <map>
#include <memory>
class IElementFactoryImpl :
	public IElementFactory
{
public:
	virtual std::unique_ptr<IElement> make(const std::string& type, const double& value);
	virtual std::vector<std::string> getElementNames();

};


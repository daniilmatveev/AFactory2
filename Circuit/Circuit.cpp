// Circuit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "..\ElementsLib\Interfaces.h"
#include "..\ElementsLib\IElementFactoryImpl.h"

int main()
{
	std::unique_ptr<IElementFactory> pFactory= std::make_unique<IElementFactoryImpl>();
	std::vector<std::string> ElementNames = pFactory->getElementNames();
	int i{ 1 };
	for (auto& name : ElementNames)
	{
		std::unique_ptr <IElement> pEl = pFactory->make(name, i++);
		auto imp = pEl->CalcImpedance(1);
		std::cout << imp << "; ";
	}
	std::cout << std::endl;
}



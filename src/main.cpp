//============================================================================
// Name        : LogicSimulator.cpp
// Author      : AhmedSherif
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
//#include <memory>

#include "Gate.h"
#include "Node.h"
#include "GateGenerator.h"


int main() {
	std::string inputString;


	do {
		std::getline(std::cin, inputString);
	} while (GateGenerator::parse_input_string(inputString));

	return 0;
}


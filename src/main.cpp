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


#include "Trace.h"
#include "helperfunctions.h"
#include "Node.h"
#include "Gate.h"
#include "AND.h"
#include "OR.h"
#include "NOT.h"
#include "XOR.h"

#include "GateGenerator.h"
#include "Simulation.h"


int main() {
	std::string inputString;

	do {
		std::getline(std::cin, inputString);
	} while (GateGenerator::parse_input_string(inputString));

	return 0;
}


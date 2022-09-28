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



//#define TRACE_MACRO
//
//#if (TRACE_MACRO == 1)
//	#define PRINT(something) std::cout << something << std::endl;
//#else
//	#define PRINT(something)
//#endif

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


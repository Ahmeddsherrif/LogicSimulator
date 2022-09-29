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

#include "Node.h"
#include "Gate.h"
#include "GateGenerator.h"


int main() {
	std::string inputString;

	Node A{"A", true};
	Node B{"B", true};
	Node C{"C"};


	std::vector<Node> vec = {A, B, C};

	//Gate g{vec};

//	Node *ptr = nullptr;
//
//	if(Node::getNode("A", ptr)){
//		ptr->setValue(false);
//		std::cout << *ptr << std::endl;
//	}else{
//		std::cout << "Not Found" << std::endl;
//	}






//	do {
//		std::getline(std::cin, inputString);
//	} while (GateGenerator::parse_input_string(inputString));

	return 0;
}


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
#include "AND.h"
#include "OR.h"

#include "GateGenerator.h"


int main() {
	std::string inputString;

	Node *A = new Node {"A", true};
	Node *B = new Node {"B", false};
	Node *D = new Node {"D", true};
	Node *C = new Node {"C"};

	Gate *b = new OR;
	Gate *a = new AND;

	a->addNode(*A);
	a->addNode(*B);
	a->addNode(*D);
	a->addNode(*C);


	b->addNode(*A);
	b->addNode(*B);
	b->addNode(*D);
	b->addNode(*C);

	a->simulateGate();
	b->simulateGate();

	std::cout << a->get_output_node() << std::endl;
	std::cout << b->get_output_node() << std::endl;

	delete A;
	delete B;
	delete C;

	delete a;
	delete b;

//	if(vec[2].setValue(vec[0] & vec[1])){
//		std::cout << vec[2] << std::endl;
//	}else{
//		std::cout << "Error" << std::endl;
//	}
//
//

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


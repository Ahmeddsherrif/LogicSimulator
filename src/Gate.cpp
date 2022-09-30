/*
 * Gate.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */
#include <vector>
#include <iostream>

#include "Node.h"
#include "Gate.h"


Gate::Gate(const bool &isInverted)
	: isInverted {isInverted}, isSimulated {false}
{

}


Gate::Gate()
	: Gate(false)
{

}

Gate::~Gate(){

}

bool Gate::is_gate_simulated() const{
	return isSimulated;
}


void Gate::setNodes(const std::vector<Node *> &nodes) {
	(this->nodes).clear();
	for(auto itr = nodes.begin(); itr != nodes.end(); itr++){
		(this->nodes).push_back(*itr);								//calls copy constructor of nodes a lot
	}

	this->nodes.back()->setAsOutput();
}


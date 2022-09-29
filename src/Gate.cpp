/*
 * Gate.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */
#include <map>
#include <vector>

#include "Node.h"
#include "Gate.h"

unsigned int Gate::idGenerator = 0;

std::map<unsigned int, Gate *> Gate::gateLookup;

Gate::Gate(const std::vector<Node> &nodes)
	:Gate()
{
	this->nodes = nodes;
}

Gate::Gate(const bool &isInverted)
	:Gate()
{
	this->isInverted = isInverted;
}


Gate::Gate()
	:id {idGenerator}, nodeCount{0}, isInverted{false}
{
	idGenerator++;
	gateLookup.insert(std::make_pair(id, this));
}

Gate::~Gate() {
	gateLookup.erase(id);
}


void Gate::addNode(const Node &inNode){
	nodes.push_back(inNode);
}

Node Gate::get_output_node(){
	return nodes.back();
}

bool Gate::getGate(unsigned int gateID, Gate *&outNode){
	bool rtnState = true;

	auto gateIterator = gateLookup.find(gateID);

	if (gateIterator != gateLookup.end()){
		outNode = gateIterator->second;
	}else{
		rtnState = false;
	}

	return rtnState;
}

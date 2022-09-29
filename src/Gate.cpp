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
	:id {idGenerator}, nodes{nodes}
{
	idGenerator++;
	gateLookup.insert(std::make_pair(id, this));

}

Gate::~Gate() {
	gateLookup.erase(id);
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

/*
 * Node.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#include <string>

#include "Node.h"


std::string Node::getName() const {
	return name;
}

void Node::setName(char name) {
	this->name = name;
}

bool Node::isValue() const {
	return value;
}


void Node::setValue(bool value) {
	this->value = value;
}

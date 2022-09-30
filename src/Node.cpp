/*
 * Node.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#include <iostream>
#include <string>

#include <map>

#include "Trace.h"
#include "Node.h"


std::ostream& operator<<(std::ostream& os, const Node& node){
	os << node.name << ": " << node.value;
	return os;
}



bool Node::operator& (const Node& lhs){
	return ((this->value) & (lhs.value));
}
bool Node::operator| (const Node& lhs){
	return ((this->value) | (lhs.value));
}
bool Node::operator^ (const Node& lhs){
	return ((this->value) ^ (lhs.value));
}


Node::Node(const std::string& name, const bool& value)
	: name{name}, assigned{true}, value{value}
{

}

Node::Node(const std::string& name)
	: name{name}, assigned{false}, value{false}
{

}


void Node::setValue(bool value) {

	if(this->assigned == false){
		this->assigned = true;
	}

	this->value = value;
}

bool Node::getValue() const{
	return this->value;
}

bool Node::isAssigned() const {
	return assigned;
}

/*
 * Node.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#include <iostream>
#include <string>

#include "Trace.h"
#include "Node.h"


std::ostream& operator<<(std::ostream& os, const Node& node){
	if(node.assigned == true){
		os << node.name << ": " << node.value;
	}else{
		if(node.isOutput == true){
			os << node.name << ": " << "Simulate First";
		}else{
			os << node.name << ": " << "un-assigned";
		}
	}

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


Node::Node(const std::string& name)
	: name{name}, assigned{false}, value{false}, isOutput{false}
{

}

void Node::setAsOutput(){
	this->isOutput = true;
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

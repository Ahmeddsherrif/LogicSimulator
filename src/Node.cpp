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

std::map<std::string, Node *> Node::nodeLookup;

std::ostream& operator<<(std::ostream& os, const Node& node){
	os << node.name << ": " << node.value;
	return os;
}

Node& Node::operator= (const Node& lhs){
	TRACE_PRINT("ASSIGMENT OPERATOR OVERLOAD CALLED");
	this->name = lhs.name;
	this->assigned = lhs.assigned;
	this->value = lhs.value;

	return *this;
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
	nodeLookup.insert(std::make_pair(name, this));
}

Node::Node(const std::string& name)
	: Node(name, false)
{
	this->assigned = false;
}

Node::Node()
	: Node(0,false)
{
	this->assigned = false;
}

Node::Node (const Node& second)
	:	Node(second.name, second.value)
{
	TRACE_PRINT("COPY CONSTRUCTOR CALLED");
	this->assigned = second.assigned;
}

Node::~Node(){
	nodeLookup.erase(name);
}



bool Node::getNode(std::string nodeName, Node *&outNode){
	bool rtnState = true;

	auto nodeIterator = nodeLookup.find(nodeName);

	if (nodeIterator != nodeLookup.end()){
		outNode = (nodeIterator->second);
	}else{
		TRACE_PRINT("Node not Found");
		outNode = (Node *) 0xDEADBEEF;
		rtnState = false;
	}

	return rtnState;
}

std::string Node::getName() const {
	return name;
}

void Node::setName(char name) {
	this->name = name;
}

bool Node::getValue() const {
	return value;
}



bool Node::setValue(bool value) {
	bool rtnValue = true;

	if(this->assigned == false){
		this->value = value;
		this->assigned = true;
	}else{
		rtnValue = false;
	}

	return rtnValue;
}

bool Node::isAssigned() const {
	return assigned;
}

void Node::setAssigned(bool assigned) {
	this->assigned = assigned;
}

std::map<std::string, Node*>& Node::getNodeLookup(){
	return nodeLookup;
}

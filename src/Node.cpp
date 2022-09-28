/*
 * Node.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#include <iostream>
#include <string>
#include <map>

#include "Node.h"

std::map<std::string, Node *> Node::nodeLookup;

std::ostream& operator<<(std::ostream& os, const Node& node){
	os << node.name << ": " << node.value;
	return os;
}



Node::Node(const std::string& name, const bool& value)
	: name{name}, value{value}, state{false}
{
	nodeLookup.insert(std::make_pair(name, this));
}

Node::Node(const std::string& name)
	: Node(name, false)
{

}

Node::Node()
	: Node(0,false)
{

}

Node::~Node(){
	nodeLookup.erase(name);
}

bool Node::getNode(std::string nodeName, Node *outNode){
	bool rtnState = true;

	auto nodeIterator = nodeLookup.find(nodeName);

	if (nodeIterator != nodeLookup.end()){
		outNode = nodeIterator->second;
	}else{
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

bool Node::isValue() const {
	return value;
}


void Node::setValue(bool value) {
	this->value = value;
}

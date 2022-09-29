/*
 * GateGenerator.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Trace.h"
#include "Command.h"
#include "Node.h"
#include "Gate.h"
#include "AND.h"
#include "OR.h"
#include "NOT.h"
#include "XOR.h"
#include "GateGenerator.h"


std::vector<Gate *> GateGenerator::gateVector;

Error_t GateGenerator::create_gate(const Gate_t &gateType, Gate *&outGate) {
	Error_t rtnError = NO_ERROR;

	switch(gateType){
		case AND_GATE:{
			TRACE_PRINT("You want to create an AND Gate ");
			outGate = new AND();
			break;
		}
		case OR_GATE:{
			TRACE_PRINT("You want to create an OR Gate ");
			outGate = new OR();
			break;
		}
		case NOT_GATE:{
			TRACE_PRINT("You want to create an NOT Gate ");
			outGate = new NOT();
			break;
		}
		case XOR_GATE:{
			TRACE_PRINT("You want to create an XOR Gate ");
			outGate = new XOR();
			break;
		}
		case NAND_GATE:{
			TRACE_PRINT("You want to create an NAND Gate ");
			outGate = new AND(true);
			break;
		}
		case NOR_GATE:{
			TRACE_PRINT("You want to create an NOR Gate ");
			outGate = new OR(true);
			break;
		}
		case XNOR_GATE:{
			TRACE_PRINT("You want to create an XNOR Gate ");
			outGate = new XOR(true);
			break;
		}

	}

	return rtnError;
}

Error_t GateGenerator::create_node(std::string nodeName, Node *&outNode) {
	Error_t rtnError = NO_ERROR;

	outNode = new Node(nodeName);

	return rtnError;
}



Error_t GateGenerator::out_node(std::string nodeToOutput){
	Error_t rtnError = NO_ERROR;
	Node *tempNode;
	if(nodeToOutput == "ALL"){
		auto nodesLookup = Node::getNodeLookup();
		for(auto itr = nodesLookup.begin(); itr != nodesLookup.end(); itr++){
			std::cout << *(itr->second) << std::endl;
		}
	}else{
		if(Node::getNode(nodeToOutput, tempNode) == true){
			std::cout << tempNode << std::endl;
		}else{
			rtnError = OUT_NODE_ERROR;				//node does not exist
		}
	}

	return rtnError;
}

Error_t GateGenerator::set_node(Node *&node, std::string nodeValue){
	Error_t rtnError = NO_ERROR;

	if(nodeValue.length() == 1){
		if(nodeValue == "1"){
			node->setValue(true);
		}
		else if (nodeValue == "0"){
			node->setValue(false);
		}
		else{
			rtnError = SET_NODE_ERROR;
		}
	}else{
		rtnError = SET_NODE_ERROR;
	}

	return rtnError;
}

void GateGenerator::start_simulation(){
	TRACE_PRINT("Starting The Simulation ");

	for (auto itr = gateVector.begin(); itr != gateVector.end(); itr++){
		TRACE_PRINT("Simulating Gate");
		(*itr)->simulateGate();
	}
}

std::vector<std::string> GateGenerator::split_string(const std::string &s, const char &delim){
	std::vector<std::string> result;
	std::string item;

	std::stringstream ss { s };

	while (std::getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}


bool GateGenerator::parse_input_string(std::string inputString){

	bool rtnValue = true;

	std::vector<std::string> buffer = split_string(inputString, ' ');
	std::vector<Node> nodeVector;

	State_t state = EXECUTE_COMMAND_STATE;
	Error_t error = NO_ERROR;

	Node *currentNode = nullptr;
	Gate *currentGate = nullptr;

	for (auto itr = buffer.begin(); itr!= buffer.end() + 1 ; itr++) {
		switch (state) {
			case EXECUTE_COMMAND_STATE: {
				switch (Command::string_to_command(*itr)) {
					case AND_COMMAND: {
						TRACE_PRINT("You Have Entered AND");
						create_gate(AND_GATE, currentGate);
						state = ADD_NODE_STATE;
						break;
					}
					case OR_COMMAND: {
						TRACE_PRINT("You Have Entered OR");
						create_gate(OR_GATE, currentGate);
						state = ADD_NODE_STATE;
						break;
					}
					case NOT_COMMAND: {
						TRACE_PRINT("You Have Entered NOT");
						create_gate(NOT_GATE, currentGate);
						state = ADD_NODE_STATE;
						break;
					}
					case NAND_COMMAND: {
						TRACE_PRINT("You Have Entered NAND");
						create_gate(NAND_GATE, currentGate);
						state = ADD_NODE_STATE;
						break;
					}
					case NOR_COMMAND: {
						TRACE_PRINT("You Have Entered NOR");
						create_gate(NOR_GATE, currentGate);
						state = ADD_NODE_STATE;
						break;
					}
					case XOR_COMMAND: {
						TRACE_PRINT("You Have Entered XOR");
						create_gate(XOR_GATE, currentGate);
						state = ADD_NODE_STATE;
						break;
					}
					case XNOR_COMMAND: {
						TRACE_PRINT("You Have Entered XNOR");
						create_gate(XNOR_GATE, currentGate);
						state = ADD_NODE_STATE;
						break;
					}
					case SET_COMMAND: {
						TRACE_PRINT("You Have Entered SET");
						state = SET_NODE_STATE;
						break;
					}
					case SIM_COMMAND: {
						TRACE_PRINT("You Have Entered SIM");
						start_simulation();
						state = END_LINE_STATE;
						break;
					}
					case OUT_COMMAND: {
						TRACE_PRINT("You Have Entered OUT");
						state = OUT_NODE_STATE;
						break;
					}
					case INVALID_COMMAND:{
						state = ERROR_STATE;
						break;
					}
					case TERMINATE_COMMAND:{
						state = END_PARSE_STATE;
						break;
					}
				}
				break;
			}

			case ADD_NODE_STATE: {
				TRACE_PRINT("You want to create a Node");

				TRACE_PRINT("Searching if the Node Exists....");
				if(Node::getNode(*itr, currentNode) == true){				//Node Exists
					TRACE_PRINT("MATCH FOUND!");
					nodeVector.push_back(*currentNode);
				}else{														//Node doesn't Exist
					TRACE_PRINT("NODE Doesn't Exists");
					error = create_node(*itr, currentNode);
					nodeVector.push_back(*currentNode);
					if(currentNode != nullptr){
						delete currentNode;
					}
				}

				if(error == NO_ERROR){
					if(itr + 1 != buffer.end()){
						state = ADD_NODE_STATE;
					}else{
						currentGate->setNodes(nodeVector);
						gateVector.push_back(currentGate);
						state = END_LINE_STATE;
					}
				}else{
					state = ERROR_STATE;
				}

				break;
			}

			case OUT_NODE_STATE: {
				out_node(*itr);
				state = END_LINE_STATE;
				break;
			}

			case SET_NODE_STATE: {
				Node::getNode(*itr, currentNode);
				state = SET_VALUE_STATE;
				break;
			}

			case SET_VALUE_STATE: {
				error = set_node(currentNode, *itr);
				if(error == NO_ERROR){
					state = END_LINE_STATE;
				}else{
					state = ERROR_STATE;
				}
				break;
			}

			case ERROR_STATE: {
				TRACE_PRINT("This Line is corrupted");
				if(currentGate != nullptr){
					delete currentGate;
				}

				switch(error){

					case CREATE_NODE_ERROR:{
						//pop current gate from vector
						//pop all created nodes from vector
						break;
					}
					default:{

					}
				}

				state = END_LINE_STATE;
				break;
			}

			case END_LINE_STATE:{
				TRACE_PRINT("Ending the line");
				if(itr != buffer.end()){
					itr = buffer.end();
				}
				break;
			}
			case END_PARSE_STATE: {

				for (auto itr = gateVector.begin(); itr != gateVector.end(); itr++){
					TRACE_PRINT("Deleting gate Vector");
					delete *itr;
				}

				TRACE_PRINT("HASTA LA VISTA!");
				rtnValue = false;
				break;
			}
		}
	}

	return rtnValue;
}

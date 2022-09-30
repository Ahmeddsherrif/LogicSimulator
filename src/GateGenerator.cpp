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
#include "helperfunctions.h"
#include "Command.h"
#include "Node.h"
#include "Gate.h"
#include "AND.h"
#include "OR.h"
#include "NOT.h"
#include "XOR.h"
#include "GateGenerator.h"


std::vector<Gate *> GateGenerator::gateVector;
std::vector<Node *> GateGenerator::nodeVector;

Error_t GateGenerator::create_gate(const Gate_t &gateType, Gate *&outGate) {
	Error_t rtnError = NO_ERROR;

	if(outGate != nullptr){
		outGate = nullptr;
	}

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

	if(outGate == nullptr){
		rtnError = CREATE_GATE_ERROR;
	}

	return rtnError;
}

Error_t GateGenerator::create_node(std::string nodeName, Node *&outNode) {
	Error_t rtnError = NO_ERROR;

	if(outNode != nullptr){
		outNode = nullptr;
	}

	outNode = new Node(nodeName);

	if(outNode == nullptr){
		rtnError = CREATE_NODE_ERROR;
	}

	return rtnError;
}



Error_t GateGenerator::out_node(std::string nodeToOutput){
	Error_t rtnError = NO_ERROR;

	Node *tempNode;
	if(nodeToOutput == "ALL"){
		for(auto itr = nodeVector.begin(); itr != nodeVector.end(); itr++){
			std::cout << **itr << std::endl;
		}
	}else{
		if(getNode(nodeToOutput, tempNode) == true){
			std::cout << *tempNode << std::endl;
		}else{
			rtnError = OUT_NODE_ERROR;				//node does not exist
		}
	}

	return rtnError;
}

Error_t GateGenerator::getNode(std::string nodeName, Node *& node){
	Error_t rtnError = NO_ERROR;

	for(auto itr = nodeVector.begin(); itr != nodeVector.end(); itr++){
		if((*itr)->getName() == nodeName){
			node = *itr;
			rtnError = GET_NODE_ERROR;
			break;
		}
	}

	Error_t rtnError;
}


Error_t GateGenerator::set_node(Node *&node, std::string nodeValue){
	TRACE_PRINT("Setting Node Value");

	Error_t rtnError = NO_ERROR;

	if(nodeValue == "1"){
		node->setValue(true);
		TRACE_PRINT("Node Value is set to true");
	}
	else if (nodeValue == "0"){
		node->setValue(false);
		TRACE_PRINT("Node Value is set to false");
	}
	else{
		rtnError = SET_NODE_ERROR;
		TRACE_PRINT("Error Setting the node value");
	}

	return rtnError;
}

Error_t GateGenerator::start_simulation(){
	TRACE_PRINT("Starting The Simulation ");

	Error_t rtnError = NO_ERROR;

	bool isSimulationCompleted;
	bool isGateSimulated;

	do {
		isSimulationCompleted = true;
		isGateSimulated = false;

		for (auto itr = gateVector.begin(); itr != gateVector.end(); itr++) {
			TRACE_PRINT("Simulating Gate");

			// Check to see if it was simulated before or not
			if ((*itr)->is_gate_simulated() == false) {
				TRACE_PRINT("A Gate Has Been Simulated");

				if((*itr)->simulateGate() == true){
					isGateSimulated = true;
				}

				isSimulationCompleted = false;
			}
		}

		// Not a single gate in the iteration have been simulated successfully
		if(isGateSimulated == false){
			rtnError = SIMULATION_ERROR;
			break;
		}


	} while (isSimulationCompleted == false);

	return rtnError;
}



bool GateGenerator::parse_input_string(std::string inputString){

	bool rtnValue = true;

	std::vector<std::string> buffer = helper_functions::split_string(inputString, ' ');

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
						error = create_gate(AND_GATE, currentGate);
						if(error == NO_ERROR){
							state = ADD_NODE_STATE;
						}else{
							state = ERROR_STATE;
						}
						break;
					}
					case OR_COMMAND: {
						TRACE_PRINT("You Have Entered OR");
						error = create_gate(OR_GATE, currentGate);
						if(error == NO_ERROR){
							state = ADD_NODE_STATE;
						}else{
							state = ERROR_STATE;
						}
						break;
					}
					case NOT_COMMAND: {
						TRACE_PRINT("You Have Entered NOT");
						error = create_gate(NOT_GATE, currentGate);
						if(error == NO_ERROR){
							state = ADD_NODE_STATE;
						}else{
							state = ERROR_STATE;
						}
						break;
					}
					case NAND_COMMAND: {
						TRACE_PRINT("You Have Entered NAND");
						error = create_gate(NAND_GATE, currentGate);
						if(error == NO_ERROR){
							state = ADD_NODE_STATE;
						}else{
							state = ERROR_STATE;
						}
						break;
					}
					case NOR_COMMAND: {
						TRACE_PRINT("You Have Entered NOR");
						error = create_gate(NOR_GATE, currentGate);
						if(error == NO_ERROR){
							state = ADD_NODE_STATE;
						}else{
							state = ERROR_STATE;
						}
						break;
					}
					case XOR_COMMAND: {
						TRACE_PRINT("You Have Entered XOR");
						error = create_gate(XOR_GATE, currentGate);
						if(error == NO_ERROR){
							state = ADD_NODE_STATE;
						}else{
							state = ERROR_STATE;
						}
						break;
					}
					case XNOR_COMMAND: {
						TRACE_PRINT("You Have Entered XNOR");
						error = create_gate(XNOR_GATE, currentGate);
						if(error == NO_ERROR){
							state = ADD_NODE_STATE;
						}else{
							state = ERROR_STATE;
						}
						break;
					}
					case SET_COMMAND: {
						TRACE_PRINT("You Have Entered SET");
						state = SET_NODE_STATE;
						break;
					}
					case SIM_COMMAND: {
						TRACE_PRINT("You Have Entered SIM");
						error = start_simulation();
						if(error == NO_ERROR){
							TRACE_PRINT("Simulation Completed!");
							state = END_LINE_STATE;
						}else{
							state = ERROR_STATE;
						}
						break;
					}
					case OUT_COMMAND: {
						TRACE_PRINT("You Have Entered OUT");
						state = OUT_NODE_STATE;
						break;
					}
					case INVALID_COMMAND:{
						error = COMMAND_ERROR;
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
				if(getNode(*itr, currentNode) == true){				//Node Exists
					TRACE_PRINT("MATCH FOUND!");
					nodeVector.push_back(currentNode);
				}else{														//Node doesn't Exist
					TRACE_PRINT("NODE Doesn't Exists");
					error = create_node(*itr, currentNode);
					nodeVector.push_back(currentNode);
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
				error = getNode(*itr, currentNode);
				if(error == NO_ERROR){
					state = SET_VALUE_STATE;
				}else{
					state = ERROR_STATE;
				}
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
					if(*itr != nullptr){
						delete *itr;
						*itr = nullptr;
					}
				}

				for (auto itr = nodeVector.begin(); itr != nodeVector.end(); itr++){
					TRACE_PRINT("Deleting node Vector");

					if(*itr != nullptr){
						delete *itr;
						*itr = nullptr;
					}

				}

				TRACE_PRINT("HASTA LA VISTA!");
				rtnValue = false;
				break;
			}
		}
	}

	return rtnValue;
}

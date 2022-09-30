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
#include <unordered_map>
#include <vector>
#include <set>


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
#include "Simulation.h"

#define MINIMUM_NUMBER_OF_NODES_FOR_ANY_GATE	3
//NO MAXIMUM

#define MAXIMUM_NUMBER_OF_NODES_FOR_NOT_GATE	2
#define MINIMUM_NUMBER_OF_NODES_FOR_NOT_GATE	2


#define SET_NODE_PARAMETERS					2

#define	OUT_NODE_PARAMETERS					1

std::set<Gate *> GateGenerator::gateSet;
std::map<std::string, Node *> GateGenerator::nodeMap;

std::vector <Node *> GateGenerator::nodeVector;

std::vector<Node *> GateGenerator::inputNodevector;
std::vector<Node *> GateGenerator::outputNodevector;


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

		default:{

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
	}else{
		nodeMap.insert(std::make_pair(nodeName, outNode));
		nodeVector.push_back(outNode);
	}

	return rtnError;
}



Error_t GateGenerator::out_node(std::string nodeToOutput){
	Error_t rtnError = NO_ERROR;

	Node *tempNode = nullptr;

	if(nodeToOutput == "ALL"){
		for(auto itr = nodeVector.begin(); itr != nodeVector.end(); itr++){
			std::cout << **itr << std::endl;
		}
	}else{

		rtnError = getNode(nodeToOutput, tempNode);

		if(rtnError == NO_ERROR){
			std::cout << *tempNode << std::endl;
		}else{
			rtnError = OUT_NODE_ERROR;
		}
	}

	return rtnError;
}

Error_t GateGenerator::getNode(std::string nodeName, Node *& node){
	Error_t rtnError = NO_ERROR;

	auto itr = nodeMap.find(nodeName);

	if(itr != nodeMap.end()){
		node = itr->second;
	}else{
		rtnError = GET_NODE_ERROR;
	}

	return rtnError;
}


Error_t GateGenerator::set_node(Node *&node, std::string nodeValue){
	TRACE_PRINT("Setting Node Value");

	Error_t rtnError = NO_ERROR;

	if (node->isOutput() == false) {
		if(nodeValue == "1"){
			node->setValue(true);
		}
		else if (nodeValue == "0"){
			node->setValue(false);
		}
		else{
			rtnError = SET_NODE_VALUE_ERROR;
		}
	}else{
		rtnError = SET_NODE_OUTPUT_ERROR;
	}

	return rtnError;
}


bool GateGenerator::parse_input_string(std::string inputString){

	bool rtnValue = true;

	std::vector<std::string> buffer;
	State_t state;

	Error_t error;

	Node *currentNode = nullptr;
	Gate *currentGate = nullptr;

	Gate_t currentGateType = NONE;

	std::vector<Node *> nodeBuffer;


	bool isLineEnded = false;


	if(inputString.empty() == false){
		buffer= helper_functions::split_string(inputString, ' ');

		error = NO_ERROR;
		state = EXECUTE_COMMAND_STATE;

	}else{
		error = PASSING_EMPTY_STRING_ERROR;
		state = ERROR_STATE;
	}

	auto itr = buffer.begin();

	do{
		switch (state) {
			case EXECUTE_COMMAND_STATE: {
				switch (Command::string_to_command(*itr)) {
					case AND_COMMAND: {
						TRACE_PRINT("You Have Entered AND");
						currentGateType = AND_GATE;
						state = ADD_GATE_STATE;
						break;
					}
					case OR_COMMAND: {
						TRACE_PRINT("You Have Entered OR");
						currentGateType = OR_GATE;
						state = ADD_GATE_STATE;
						break;
					}
					case NOT_COMMAND: {
						TRACE_PRINT("You Have Entered NOT");
						currentGateType = NOT_GATE;
						state = ADD_GATE_STATE;
						break;
					}
					case NAND_COMMAND: {
						TRACE_PRINT("You Have Entered NAND");
						currentGateType = NAND_GATE;
						state = ADD_GATE_STATE;
						break;
					}
					case NOR_COMMAND: {
						TRACE_PRINT("You Have Entered NOR");
						currentGateType = NOR_GATE;
						state = ADD_GATE_STATE;
						break;
					}
					case XOR_COMMAND: {
						TRACE_PRINT("You Have Entered XOR");
						currentGateType = XOR_GATE;
						state = ADD_GATE_STATE;
						break;
					}
					case XNOR_COMMAND: {
						TRACE_PRINT("You Have Entered XNOR");
						currentGateType = XNOR_GATE;
						state = ADD_GATE_STATE;
						break;
					}
					case SET_COMMAND: {
						TRACE_PRINT("You Have Entered SET");
						state = SET_NODE_STATE;
						break;
					}
					case SIM_COMMAND: {
						TRACE_PRINT("You Have Entered SIM");
						state = SIMULATION_STATE;
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
						state = TERMINATE_STATE;
						break;
					}
				}

				itr++;		//to fetch the next instruction

				break;
			}

			case SIMULATION_STATE:{
				if(Simulation::start(gateSet) == true){
					TRACE_PRINT("Simulation Completed!");
					state = END_LINE_STATE;
				}else{
					error = SIMULATION_ERROR;
					state = ERROR_STATE;
				}
				break;
			}
			case ADD_GATE_STATE:{
				switch(currentGateType){
					case NOT_GATE:{
						if((buffer.size() - 1) > MAXIMUM_NUMBER_OF_NODES_FOR_NOT_GATE){
							error = TOO_MUCH_PARAMETERS_ERROR;
						}else if((buffer.size() - 1) < MINIMUM_NUMBER_OF_NODES_FOR_NOT_GATE){
							error = TOO_FEW_PARAMETERS_ERROR;
						}
					}
					default:{
						if((buffer.size() - 1) < MINIMUM_NUMBER_OF_NODES_FOR_ANY_GATE){
							error = TOO_FEW_PARAMETERS_ERROR;
						}
					}
				}

				if(error == NO_ERROR){
					error = create_gate(currentGateType, currentGate);
					if(error == NO_ERROR){
						state = ADD_NODE_STATE;
					}else{
						state = ERROR_STATE;
					}
				}else{
					state = ERROR_STATE;
				}

				break;
			}

			case ADD_NODE_STATE: {
				TRACE_PRINT("You want to create a Node");
				TRACE_PRINT("Searching if the Node Exists....");

				error = getNode(*itr, currentNode);


				if(error == NO_ERROR){
					TRACE_PRINT("MATCH FOUND!");
					nodeBuffer.push_back(currentNode);
				}else{
					TRACE_PRINT("NODE Doesn't Exists");
					error = create_node(*itr, currentNode);
					if(error == NO_ERROR){
						nodeBuffer.push_back(currentNode);
					}else{
						state = ERROR_STATE;
					}
				}

				itr++;	//to fetch the next instruction
				if(error == NO_ERROR){						// NODE ASSIGNED TO A GATE
					if(itr != buffer.end()){
						state = ADD_NODE_STATE;
					}else{
						currentGate->setNodes(nodeBuffer);
						gateSet.insert(currentGate);
						state = END_LINE_STATE;
					}
				}

				break;
			}

			case OUT_NODE_STATE: {
				if((buffer.size() - 1) > OUT_NODE_PARAMETERS){
					error = TOO_MUCH_PARAMETERS_ERROR;
				}else if ((buffer.size() - 1) < OUT_NODE_PARAMETERS){
					error = TOO_FEW_PARAMETERS_ERROR;
				}

				if(error == NO_ERROR){
					error = out_node(*itr);
					if(error == NO_ERROR){
						state = END_LINE_STATE;
					}else{
						state = ERROR_STATE;
					}
				}else{
					state = ERROR_STATE;
				}
				itr++;
				break;
			}

			case SET_NODE_STATE: {

				if((buffer.size() - 1) > SET_NODE_PARAMETERS){
					error = TOO_MUCH_PARAMETERS_ERROR;
				}else if ((buffer.size() - 1) < SET_NODE_PARAMETERS){
					error = TOO_FEW_PARAMETERS_ERROR;
				}


				if(error == NO_ERROR){
					error = getNode(*itr, currentNode);


					if(error == NO_ERROR){
						state = SET_VALUE_STATE;
					}else{
						state = ERROR_STATE;
					}
				}else{
					state = ERROR_STATE;
				}

				itr++;
				break;
			}

			case SET_VALUE_STATE: {
				error = set_node(currentNode, *itr);

				if(error == NO_ERROR){
					state = END_LINE_STATE;
				}else{
					state = ERROR_STATE;
				}

				itr++;
				break;
			}

			case ERROR_STATE: {
				TRACE_PRINT("This Line is corrupted");
				std::cout << "> ERROR: ";
				switch(error){
					case CREATE_GATE_ERROR:{
						TRACE_PRINT();
						break;
					}
					case CREATE_NODE_ERROR:{
						TRACE_PRINT();
						break;
					}
					case SIMULATION_ERROR:{
						std::cout << "SIMULATION FAILED" << std::endl;
						break;
					}
					case COMMAND_ERROR:{
						std::cout << "WRONG COMMAND, CHECK YOUR INPUT" << std::endl;
						break;
					}
					case GET_NODE_ERROR:{
						std::cout << "INPUT NODE IS NOT FOUND" << std::endl;
						break;
					}
					case SET_NODE_VALUE_ERROR:{
						std::cout << "NODE VALUE IS UNDIFINED" << std::endl;
						break;
					}
					case SET_NODE_OUTPUT_ERROR:{
						std::cout << "YOU CAN'T SET AN OUTPUT NODE" << std::endl;
						break;
					}
					case OUT_NODE_ERROR:{
						std::cout << "THE NODE YOU ARE TRYING TO VIEW IS NOT FOUND" << std::endl;
						break;
					}
					case TOO_FEW_PARAMETERS_ERROR:{
						if(currentGate != nullptr){
							delete currentGate;
							currentGate = nullptr;
						}
						std::cout << "TOO FEW PARAMETERS" << std::endl;
						break;
					}
					case TOO_MUCH_PARAMETERS_ERROR:{
						if(currentGate != nullptr){
							delete currentGate;
							currentGate = nullptr;
						}
						std::cout << "TOO MUCH PARAMETERS" << std::endl;
						break;
					}
					case PASSING_EMPTY_STRING_ERROR:{
						std::cout << "YOU HAVN'T ENTERED ANY COMMAND!" << std::endl;
						break;
					}
					case NO_ERROR:{
						std::cout << "TOTAL SOFTWARE FAILURE, CONTACT SOFTWARE DEVELOPERS" << std::endl;
						break;
					}


				}

				state = END_LINE_STATE;
				break;
			}

			case END_LINE_STATE:{
				TRACE_PRINT("Ending the line");
				isLineEnded = true;
				break;
			}
			case TERMINATE_STATE: {

				for (auto itr = gateSet.begin(); itr != gateSet.end(); itr++){
					TRACE_PRINT("Deleting gate Vector");
					if(*itr != nullptr){
						delete *itr;
					}
				}

				gateSet.clear();

				for (auto itr = nodeMap.begin(); itr != nodeMap.end(); itr++){
					TRACE_PRINT("Deleting node Vector");

					if(itr->second != nullptr){
						delete itr->second;
					}

				}

				nodeMap.clear();
				nodeVector.clear();

				TRACE_PRINT("HASTA LA VISTA!");
				rtnValue = false;
				break;
			}
		}
	}while(isLineEnded == false && rtnValue == true);

	return rtnValue;
}

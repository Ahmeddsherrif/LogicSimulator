/*
 * GateGenerator.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */
#include <sstream>
#include <iostream>

#include "Command.h"
#include "Gate.h"
#include "Node.h"
#include "GateGenerator.h"



std::string GateGenerator::inputString;
const char GateGenerator::stringDelimeter = ' ';
std::vector<std::string> GateGenerator::buffer;

State_t GateGenerator::state;
Error_t GateGenerator::error;

Node GateGenerator::currentNode;
Gate GateGenerator::currentGate;


void  GateGenerator::create_gate(const Gate_t& gateType, Gate& outGate){
	Gate genericGate;	//pointer to new gate type

	switch(gateType){
		case AND_GATE:{
			std::cout << "You want to create an AND Gate "<< std::endl;

//			genericGate = new AND();
			break;
		}
		case OR_GATE:{
			std::cout << "You want to create an AND Gate "<< std::endl;


			break;
		}
	}

	outGate = genericGate;
}

Error_t GateGenerator::create_node(std::string nodeName, Gate& gate, Node& outNode){
	Error_t rtnError = NO_ERROR;

	if(nodeName.length() == 1){

	}else{
		rtnError = CREATE_NODE_ERROR;
	}

	return rtnError;
}

Error_t GateGenerator::out_node(std::string nodeToDisplay){
	Error_t rtnError = NO_ERROR;

	if(nodeToDisplay == "ALL"){

	}else{

	}

	return rtnError;
}

Error_t GateGenerator::set_node(Node node, std::string nodeValue){
	Error_t rtnError = NO_ERROR;

	if(nodeValue.length() == 1){
		if(nodeValue == "1"){

		}
		else if (nodeValue == "0"){

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
	std::cout << "Starting The Simulation "<< std::endl;
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
	buffer = split_string(inputString, stringDelimeter);
	state = EXECUTE_COMMAND_STATE;


	for (auto itr = buffer.begin(); itr!= buffer.end() ; itr++) {
		switch (state) {
			case EXECUTE_COMMAND_STATE: {
				switch (Command::string_to_command(*itr)) {
					case AND_COMMAND: {
						std::cout << "You Have Entered AND" << std::endl;
						// check this function and produce error state
						create_gate(AND_GATE, currentGate);
						//Add gate to vector
						state = ADD_NODE_STATE;
						break;
					}
					case OR_COMMAND: {
						std::cout << "You Have Entered OR" << std::endl;
						create_gate(OR_GATE, currentGate);
						state = ADD_NODE_STATE;
						//Add gate to vector
						break;
					}
					case SET_COMMAND: {
						std::cout << "You Have Entered SET" << std::endl;
						state = SET_NODE_STATE;
						break;
					}
					case SIM_COMMAND: {
						std::cout << "You Have Entered SIM" << std::endl;
						start_simulation();
						state = EXECUTE_COMMAND_STATE;
						break;
					}
					case OUT_COMMAND: {
						std::cout << "You Have Entered OUT" << std::endl;
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
				error = create_node(*itr, currentGate, currentNode);
				if(error == NO_ERROR){
					//add currentNode to vector
					if(itr + 1 != buffer.end()){
						state = ADD_NODE_STATE;
					}else{
						state = EXECUTE_COMMAND_STATE;
					}
				}else{
					state = ERROR_STATE;
				}
				break;
			}

			case OUT_NODE_STATE: {
				out_node(*itr);
				state = EXECUTE_COMMAND_STATE;
				break;
			}

			case SET_NODE_STATE: {
				state = SET_VALUE_STATE;
				break;
			}

			case SET_VALUE_STATE: {
				error = set_node(currentNode, *itr);
				if(error == NO_ERROR){
					state = EXECUTE_COMMAND_STATE;
				}else{
					state = ERROR_STATE;
				}
				break;
			}

			case ERROR_STATE: {
				std::cout << "The Line is corrupted" << std::endl;

				switch(error){
					case CREATE_NODE_ERROR:{
						//pop current gate from vector
						//pop all created nodes from vector
						break;
					}
				}

				state = EXECUTE_COMMAND_STATE;
				break;
			}

			case END_PARSE_STATE: {
				rtnValue = false;
				break;
			}
		}
	}

	return rtnValue;
}

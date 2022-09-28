/*
 * GateGenerator.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */
#include <sstream>
#include <iostream>

#include "Command.h"
#include "GateGenerator.h"




std::string GateGenerator::inputString;
const char GateGenerator::stringDelimeter = ' ';
std::vector<std::string> GateGenerator::buffer;
State_t GateGenerator::state;
Flag_t GateGenerator::flag;


void GateGenerator::create_gate(Gate_t gateType){
	switch(gateType){
		case AND_GATE:{
			std::cout << "You want to create an AND Gate "<< std::endl;
			break;
		}
		case OR_GATE:{
			std::cout << "You want to create an AND Gate "<< std::endl;
			break;
		}
	}

}

void GateGenerator::create_node(std::string nodeName){

}

void GateGenerator::out_node(std::string nodeName){

}

void GateGenerator::set_node(std::string nodeName, std::string nodeValue){

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
						create_gate(AND_GATE);
						state = ADD_NODE_STATE;
						break;
					}
					case OR_COMMAND: {
						std::cout << "You Have Entered OR" << std::endl;
						create_gate(OR_GATE);
						state = ADD_NODE_STATE;
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
				}
				break;
			}

			case ADD_NODE_STATE: {
				create_node(*itr);
				if(itr + 1 == buffer.end()){
					state = EXECUTE_COMMAND_STATE;
				}else{
					state = ADD_NODE_STATE;
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
				set_node(*(itr-1), *itr);
				state = EXECUTE_COMMAND_STATE;
				break;
			}

			case ERROR_STATE: {
				std::cout << "The Line is corrupted" << std::endl;
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

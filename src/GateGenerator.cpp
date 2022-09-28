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
#include <memory>

#include "Command.h"
#include "Gate.h"
#include "Node.h"
#include "GateGenerator.h"


Error_t GateGenerator::create_gate(const Gate_t &gateType, std::unique_ptr<Gate> &outGate) {
	Error_t rtnError = NO_ERROR;

//	Gate *genericGate;	//pointer to new gate type
//
//	switch(gateType){
//		case AND_GATE:{
//			std::cout << "You want to create an AND Gate "<< std::endl;
//
////			genericGate = new AND();
//			break;
//		}
//		case OR_GATE:{
//			std::cout << "You want to create an OR Gate "<< std::endl;
//
//
//			break;
//		}
//	}

	return rtnError;
}

Error_t GateGenerator::create_node(std::string nodeName, std::unique_ptr<Gate> &gate, std::unique_ptr<Node> &outNode) {
	Error_t rtnError = NO_ERROR;

	//TODO: getNode the node from the lookup table
	//TODO: Node::Find()

	return rtnError;
}



Error_t GateGenerator::out_node(std::string nodeToOutput){
	Error_t rtnError = NO_ERROR;
//	std::unique_ptr<Node> tempNode;
//
//	if(nodeToOutput == "ALL"){
//		//TODO: loop through LUT and cout<< node
//	}else{
//		if(Node::getNode(nodeToOutput, tempNode) == true){
//			//TODO: cout << node
//		}else{
//			rtnError = OUT_NODE_ERROR;
//		}
//	}

	return rtnError;
}

Error_t GateGenerator::set_node(std::unique_ptr<Node> &node, std::string nodeValue){
	Error_t rtnError = NO_ERROR;

	//find the node from the lookup table
	//Node::Find()

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

	std::vector<std::string> buffer = split_string(inputString, ' ');
	State_t state = EXECUTE_COMMAND_STATE;
	Error_t error = NO_ERROR;


	std::unique_ptr<Node> currentNode;
	std::unique_ptr<Gate> currentGate;

	for (auto itr = buffer.begin(); itr!= buffer.end() ; itr++) {
		switch (state) {
			case EXECUTE_COMMAND_STATE: {
				switch (Command::string_to_command(*itr)) {
					case AND_COMMAND: {
						std::cout << "You Have Entered AND" << std::endl;
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
						state = END_LINE_STATE;
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
				std::cout <<"You want to create a Node" << std::endl;
				if(true){//Node::getNode(*itr, currentNode) == true){

				}else{
					error = create_node(*itr, currentGate, currentNode);
				}

				if(error == NO_ERROR){
					//add currentNode to vector
					if(itr + 1 != buffer.end()){
						state = ADD_NODE_STATE;
					}else{
						state = END_LINE_STATE;
					}
				}else{
					state = ERROR_STATE;
				}
				break;
			}

			case OUT_NODE_STATE: {
				//if out == ALL
				//Node::getNode(*itr, currentNode);
				//find_node_gate
				//output node

				state = END_LINE_STATE;
				break;
			}

			case SET_NODE_STATE: {
				//TODO: add the current node based on itr
				//Node::getNode(*itr, currentNode);
				state = SET_VALUE_STATE;
				break;
			}

			case SET_VALUE_STATE: {
				error = set_node(currentNode, *itr);
				if(error == NO_ERROR){
					//TODO: end line state
					state = END_LINE_STATE;
				}else{
					state = ERROR_STATE;
				}
				break;
			}

			case ERROR_STATE: {
				std::cout << "This Line is corrupted" << std::endl;

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
				std::cout << "Ending the line" <<std::endl;

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

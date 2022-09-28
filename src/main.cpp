//============================================================================
// Name        : LogicSimulator.cpp
// Author      : AhmedSherif
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <memory>

#include "Command.h"
#include "Node.h"


enum State_t {
	EXECUTE_COMMAND_STATE,

	ADD_NODE_STATE,
	SET_NODE_STATE,
	OUT_NODE_STATE,

	SET_VALUE_STATE,

	ERROR_STATE,
	END_PARSE_STATE
};


std::vector<std::string> parse_string(const std::string &s, const char &delim);



int main() {
	std::string inputString;
	const char stringDelimeter = ' ';

	State_t state;

	struct Flag_t{
		bool endParse;
		bool startSimulation;
		bool error;

		Flag_t(){
			endParse = false;
			startSimulation = false;
			error = false;
		}
	};

	Flag_t flag;


	do {
		state = EXECUTE_COMMAND_STATE;

		// get user Reading
		std::getline(std::cin, inputString);

		//Store every word in a buffer
		std::vector<std::string> buffer = parse_string(inputString, stringDelimeter);

		for (const auto &i : buffer) {
			switch (state) {
				case EXECUTE_COMMAND_STATE: {
					switch (Command::get_command(i)) {
						case AND_COMMAND: {
							std::cout << "You Have Entered AND" << std::endl;
							//create gate pointer that points to new And gate object
							state = ADD_NODE_STATE;
							break;
						}
						case OR_COMMAND: {
							std::cout << "You Have Entered OR" << std::endl;
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
							flag.startSimulation = true;
							break;
						}
						case OUT_COMMAND: {
							std::cout << "You Have Entered OUT" << std::endl;
							state = OUT_NODE_STATE;
							break;
						}
						case INVALID_INPUT:{

							break;
						}
					}
					break;
				}

				case ADD_NODE_STATE: {

					break;
				}

				case OUT_NODE_STATE: {

					break;
				}

				case SET_NODE_STATE: {

					break;
				}

				case SET_VALUE_STATE: {

					break;
				}

				case ERROR_STATE: {
					std::cout << "The Line is corrupted" << std::endl;
					state = END_PARSE_STATE;
					break;
				}

				case END_PARSE_STATE: {
					flag.endParse = true;
					break;
				}
			}
		}

		//Post-Command Process

	} while (flag.endParse == false);

	return 0;
}


std::vector<std::string> parse_string(const std::string &s, const char &delim){
	std::vector<std::string> result;
	std::string item;

	std::stringstream ss { s };

	while (std::getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}


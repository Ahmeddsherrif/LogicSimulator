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

#include "Node.h"

void print(const std::vector<std::string> &v) {
	for (const auto &it : v) {
		std::cout << it << std::endl;
	}
}

std::vector<std::string> parse_string(const std::string &s, const char &delim) {
	std::vector<std::string> result;
	std::string item;

	std::stringstream ss { s };

	while (std::getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

int main() {
	enum firstCommandKeyword_t {
		AND_COMMAND,
		OR_COMMAND,
		SET_COMMAND,
		SIM_COMMAND
	};

	enum secondCommandKeyword_t {
		ALL_COMMAND
	};

	std::map<std::string, firstCommandKeyword_t> firstCommandMap {
		{ "AND", AND_COMMAND },
		{ "OR", OR_COMMAND },
		{"SET", SET_COMMAND },
		{ "SIM", SIM_COMMAND }
	};

	std::map<std::string, secondCommandKeyword_t> secondCommandMap {
		{ "ALL", ALL_COMMAND },
	};

	enum state_t {
		GET_FIRST_COMMAND_STATE,
		GET_SECOND_COMMAND_STATE,
		GET_NODE_STATE,
		GET_VALUE_STATE,
		END_PARSE_STATE
	};

	auto firstCommandIterator = firstCommandMap.begin();
	std::string inputString;
	const char stringDelimeter = ' ';

	state_t state;

	struct flag_t{
			bool endParse;
			bool startSimulation;
			bool error;

			flag_t(){
				endParse = false;
				startSimulation = false;
				error = false;
			}
	};

	flag_t flag;


	do {
		// get user Reading
		std::getline(std::cin, inputString);

		//Store every word in a buffer
		std::vector<std::string> buffer = parse_string(inputString, stringDelimeter);

		state = GET_FIRST_COMMAND_STATE;

		for (const auto &i : buffer) {

			switch (state){
				case GET_FIRST_COMMAND_STATE: {

					firstCommandIterator = firstCommandMap.find(i);
					if (firstCommandIterator != firstCommandMap.end()) {
						switch (firstCommandIterator->second) {
							case AND_COMMAND: {
								std::cout << "You Have Entered AND" << std::endl;
								//create gate pointer that points to new And gate object
								state = GET_NODE_STATE;
								break;
							}
							case OR_COMMAND: {
								std::cout << "You Have Entered OR" << std::endl;
								state = GET_NODE_STATE;
								break;
							}
							case SET_COMMAND: {
								std::cout << "You Have Entered SET" << std::endl;
								state = GET_NODE_STATE;
								break;
							}
							case SIM_COMMAND: {
								std::cout << "You Have Entered SIM" << std::endl;
								flag.startSimulation = true;
								state = GET_FIRST_COMMAND_STATE;
								break;
							}
						}
					} else {
						std::cout << "WRONG COMMAND" << std::endl;
						flag.error = true;
						state = END_PARSE_STATE;
					}

					break;
				}

				case GET_NODE_STATE: {


					break;
				}

				case GET_SECOND_COMMAND_STATE: {

					break;
				}

				case GET_VALUE_STATE: {

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

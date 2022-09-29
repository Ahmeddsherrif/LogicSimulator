/*
 * Command.cpp
 *
 *  Created on: Sep 28, 2022
 *      Author: Master
 */

#include <string>
#include <map>

#include "Command.h"

std::map<std::string, Command_t> Command::commandMap{
		{ "AND", AND_COMMAND },
		{ "OR", OR_COMMAND },
		{ "NOT", NOT_COMMAND},
		{ "XOR", XOR_COMMAND},
		{ "XNOR", XNOR_COMMAND},
		{ "NAND", NAND_COMMAND},
		{ "NOR", NOR_COMMAND},
		{ "SET", SET_COMMAND },
		{ "SIM", SIM_COMMAND },
		{ "OUT", OUT_COMMAND },
		{ "TERMINATE", TERMINATE_COMMAND }
};

Command_t Command::string_to_command(const std::string& s){
	Command_t rtnCommand;
	auto commandIterator = commandMap.find(s);

	if (commandIterator != commandMap.end()){
		rtnCommand = commandIterator->second;
	}else{
		rtnCommand = INVALID_COMMAND;
	}

	return rtnCommand;
}

/*
 * Command.cpp
 *
 *  Created on: Sep 28, 2022
 *      Author: Master
 */

#include "Command.h"

std::map<std::string, Command_t> Command::commandMap{
		{ "AND", AND_COMMAND },
		{ "OR", OR_COMMAND },
		{ "SET", SET_COMMAND },
		{ "SIM", SIM_COMMAND }
};

Command_t Command::get_command(const std::string& s){
	Command_t rtnCommand;
	auto commandIterator = commandMap.find(s);

	if (commandIterator != commandMap.end()){
		rtnCommand = commandIterator->second;
	}else{
		rtnCommand = INVALID_INPUT;
	}

	return rtnCommand;
}

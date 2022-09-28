/*
 * Command.h
 *
 *  Created on: Sep 28, 2022
 *      Author: Master
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <map>

enum Command_t {
	AND_COMMAND,
	OR_COMMAND,
	SET_COMMAND,
	SIM_COMMAND,
	OUT_COMMAND,
	INVALID_INPUT
};

class Command {
	private:
		static std::map<std::string, Command_t> commandMap;
	public:
		static Command_t get_command(const std::string& s);
};

#endif /* COMMAND_H_ */

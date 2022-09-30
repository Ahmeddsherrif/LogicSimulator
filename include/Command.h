/*
 * Command.h
 *
 *  Created on: Sep 28, 2022
 *      Author: Master
 */

#ifndef COMMAND_H_
#define COMMAND_H_



enum Command_t {
	AND_COMMAND,
	OR_COMMAND,
	NOT_COMMAND,
	XOR_COMMAND,
	XNOR_COMMAND,
	NAND_COMMAND,
	NOR_COMMAND,
	SET_COMMAND,
	SIM_COMMAND,
	OUT_COMMAND,
	TERMINATE_COMMAND,
	INVALID_COMMAND
};

class Command {
	private:
		static const std::map<std::string, Command_t> commandMap;
	public:
		static Command_t string_to_command(const std::string& s);
};

#endif /* COMMAND_H_ */

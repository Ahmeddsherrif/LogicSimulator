/*
 * GateGenerator.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef GATEGENERATOR_H_
#define GATEGENERATOR_H_

#include <vector>
#include <string>

enum State_t {
	EXECUTE_COMMAND_STATE,

	ADD_NODE_STATE,
	SET_NODE_STATE,
	OUT_NODE_STATE,

	SET_VALUE_STATE,

	ERROR_STATE,

	END_PARSE_STATE
};

enum Gate_t {
	AND_GATE,
	OR_GATE
};


class GateGenerator {

	private:
		static std::string inputString;
		static const char stringDelimeter;
		static std::vector<std::string> buffer;
		static State_t state;

	private:
		static std::vector<std::string> split_string(const std::string &s, const char &delim);
		static void create_gate(Gate_t gateType);
		static void create_node(std::string nodeName);
		static void out_node(std::string nodeName);
		static void set_node(std::string nodeName, std::string nodeValue);
		static void start_simulation();

	public:
		static bool parse_input_string(std::string inputString);

};

#endif /* GATEGENERATOR_H_ */

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

#include "Gate.h"
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

enum Gate_t {
	AND_GATE,
	OR_GATE
};

enum Error_t{
	NO_ERROR,
	CREATE_NODE_ERROR,
	SET_NODE_ERROR,
	CREATE_GATE_ERROR
};


class GateGenerator {

	private:
		static std::string inputString;
		static const char stringDelimeter;
		static std::vector<std::string> buffer;

		static State_t state;
		static Error_t error;

		static Node currentNode;
		static Gate currentGate;

	private:
		static std::vector<std::string> split_string(const std::string &s, const char &delim);
		static void create_gate(const Gate_t& gateType, Gate& outGate);
		static Error_t create_node(std::string nodeName, Gate& gate, Node& outNode);
		static Error_t out_node(std::string nodeToDisplay);
		static Error_t set_node(Node node, std::string nodeValue);
		static void start_simulation();

	public:
		static bool parse_input_string(std::string inputString);

};

#endif /* GATEGENERATOR_H_ */

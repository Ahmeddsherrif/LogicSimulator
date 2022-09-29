/*
 * GateGenerator.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef GATEGENERATOR_H_
#define GATEGENERATOR_H_

enum State_t {
	EXECUTE_COMMAND_STATE,
	ADD_NODE_STATE,
	SET_NODE_STATE,
	OUT_NODE_STATE,
	SET_VALUE_STATE,
	ERROR_STATE,
	END_LINE_STATE,
	END_PARSE_STATE
};

enum Gate_t {
	AND_GATE,
	OR_GATE,
	NOT_GATE,
	NAND_GATE,
	NOR_GATE,
	XOR_GATE,
	XNOR_GATE
};

enum Error_t {
	NO_ERROR,
	SET_NODE_ERROR,
	CREATE_NODE_ERROR,
	OUT_NODE_ERROR
};

class GateGenerator {

	private:
		static std::vector<Gate *> gateVector;



		static std::vector<std::string> split_string(const std::string &s, const char &delim);

		static Error_t create_gate(const Gate_t &gateType, Gate *&outGate);
		static Error_t create_node(std::string nodeName, Node *&outNode);

		static Error_t set_node(Node *&node, std::string nodeValue);
		static Error_t out_node(std::string nodeToOutput);

		static void start_simulation();

	public:
		static bool parse_input_string(std::string inputString);

};

#endif /* GATEGENERATOR_H_ */

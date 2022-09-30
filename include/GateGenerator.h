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
	ADD_GATE_STATE,
	ADD_NODE_STATE,
	SET_NODE_STATE,
	OUT_NODE_STATE,
	SET_VALUE_STATE,
	SIMULATION_STATE,
	ERROR_STATE,
	END_LINE_STATE,
	TERMINATE_STATE
};

enum Gate_t {
	NONE,
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
	CREATE_GATE_ERROR,
	CREATE_NODE_ERROR,
	SIMULATION_ERROR,
	COMMAND_ERROR,
	GET_NODE_ERROR,
	SET_NODE_VALUE_ERROR,
	SET_NODE_OUTPUT_ERROR,
	OUT_NODE_ERROR,
	TOO_MUCH_PARAMETERS_ERROR,
	TOO_FEW_PARAMETERS_ERROR,
	PASSING_EMPTY_STRING_ERROR
};

class GateGenerator {

	private:
		static std::set<Gate *> gateSet;

		static std::map<std::string, Node *> nodeMap;
		static std::vector<Node *> nodeVector;

		static std::vector<Node *> inputNodevector;
		static std::vector<Node *> outputNodevector;

		static Error_t create_gate(const Gate_t &gateType, Gate *&outGate);
		static Error_t create_node(std::string nodeName, Node *&outNode);

		static Error_t set_node(Node *&node, std::string nodeValue);
		static Error_t getNode(std::string nodeName, Node *& node);
		static Error_t out_node(std::string nodeToOutput);

		static Error_t start_simulation();

	public:
		static bool parse_input_string(std::string inputString);
};

#endif /* GATEGENERATOR_H_ */

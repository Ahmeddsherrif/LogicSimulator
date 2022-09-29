/*
 * Gate.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef GATE_H_
#define GATE_H_


class Gate {
	private:
		unsigned int id;
		std::vector<Node> nodes;

	private:
		static unsigned int idGenerator;
		static std::map<unsigned int, Gate *> gateLookup;

	public:
		Gate(const std::vector<Node> &nodes);
		~Gate();

	public:
		static bool getGate(unsigned int gateID, Gate *&outNode);
};

#endif /* GATE_H_ */

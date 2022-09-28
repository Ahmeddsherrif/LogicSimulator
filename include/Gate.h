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
		static unsigned int idGenerator;
		static std::map<unsigned int, Gate *> gateLookup;
	public:
		Gate();
		~Gate();

	public:
		static bool getGate(unsigned int gateID, Gate *outNode);
};

#endif /* GATE_H_ */

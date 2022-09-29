/*
 * OR.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef OR_H_
#define OR_H_

#include "Gate.h"

class OR: public Gate {
	public:
		OR() : Gate() {}
		OR(const bool& isInverted)
			: Gate(isInverted)
		{

		}

		virtual void simulateGate() override final {
			bool output = false;

			for (auto itr = nodes.begin(); itr < nodes.end() - 2; itr++) {
				output |= itr->getValue() | (itr + 1)->getValue();
			}

			if(isInverted){
				output = !output;
			}

			nodes.back().setValue(output);
		}

};

#endif /* OR_H_ */

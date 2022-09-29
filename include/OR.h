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
		virtual void simulateGate() override final {
			bool output = false;

			for (auto itr = nodes.begin(); itr < nodes.end() - 2; itr++) {
				output |= itr->getValue() | (itr + 1)->getValue();
			}

			nodes.back().setValue(output);
		}

};

#endif /* OR_H_ */

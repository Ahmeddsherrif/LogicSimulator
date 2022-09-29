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

		virtual bool simulateGate() override final {
			bool output = false;
			bool rtnValue = true;

			//checks to see if all the gate input nodes are assigned or not
			for(auto itr = nodes.begin(); itr != nodes.end() - 1; itr++){
				if(itr->isAssigned() == false){
					rtnValue = false;
					break;
				}
			}

			if (rtnValue == true) {
				for (auto itr = nodes.begin(); itr < nodes.end() - 2; itr++) {
					output |= itr->getValue() | (itr + 1)->getValue();
				}

				if(isInverted){
					output = !output;
				}

				nodes.back().setValue(output);

				isSimulated = true;
			}

			return rtnValue;
		}

};

#endif /* OR_H_ */

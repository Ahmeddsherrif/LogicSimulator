/*
 * AND.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef AND_H_
#define AND_H_


#include "Gate.h"
//
class AND : public Gate{
	public:

		AND() : Gate() {}
		AND(const bool& isInverted)
			: Gate(isInverted)
		{

		}


		virtual bool simulateGate() override final{
			bool output = true;
			bool isAllAssigned = true;

			//checks to see if all the gate input nodes are assigned or not
			for(auto itr = nodes.begin(); itr != nodes.end() - 1; itr++){
				if((*itr)->isAssigned() == false){
					isAllAssigned = false;
					break;
				}
			}

			if (isAllAssigned == true) {
				for(auto itr = nodes.begin(); itr < nodes.end()- 2; itr++){
					output &= (*itr)->getValue() & (*(itr+1))->getValue();
				}

				if(isInverted){
					output = !output;
				}

				nodes.back()->setValue(output);
				isSimulated = true;
			}

			return isAllAssigned;
		}

};

#endif /* AND_H_ */

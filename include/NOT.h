/*
 * NOT.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef NOT_H_
#define NOT_H_

#include "Gate.h"
//
class NOT : public Gate{
	public:


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
				output = !(nodes.front()->getValue());
				nodes.back()->setValue(output);

				isSimulated = true;
			}

			return isAllAssigned;
		}

};

#endif /* NOT_H_ */

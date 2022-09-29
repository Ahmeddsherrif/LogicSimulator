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


		virtual void simulateGate() override final{
			bool output = true;

			for(auto itr = nodes.begin(); itr < nodes.end()- 2; itr++){
				output &= itr->getValue() & (itr+1)->getValue();
			}

			if(isInverted){
				output = !output;
			}

			nodes.back().setValue(output);
		}

};

#endif /* AND_H_ */

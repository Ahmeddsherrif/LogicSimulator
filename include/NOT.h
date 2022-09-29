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

		virtual void addNode(const Node &inNode){
			if(nodeCount < 2){
				Gate::addNode(inNode);
				nodeCount++;
			}
		}

		virtual bool simulateGate() override final{
			bool output = true;
			bool rtnValue = true;

			//checks to see if all the gate input nodes are assigned or not
			for(auto itr = nodes.begin(); itr != nodes.end() - 1; itr++){
				if(itr->isAssigned() == false){
					rtnValue = false;
					break;
				}
			}

			if (rtnValue == true) {
				output = !(nodes.front().getValue());
				nodes.back().setValue(output);

				isSimulated = true;
			}

			return rtnValue;
		}

};

#endif /* NOT_H_ */

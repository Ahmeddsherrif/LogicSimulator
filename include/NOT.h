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

		virtual void simulateGate() override final{
			bool output = true;
			output = !(nodes.front().getValue());
			nodes.back().setValue(output);
		}

};

#endif /* NOT_H_ */

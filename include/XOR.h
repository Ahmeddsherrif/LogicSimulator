/*
 * XOR.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef XOR_H_
#define XOR_H_

class XOR: public Gate {
	public:
		XOR() : Gate() {}
		XOR(const bool& isInverted)
			: Gate(isInverted)
		{

		}

		virtual bool simulateGate() override final {
			bool output = false;
			bool isAllAssigned = true;

			//checks to see if all the gate input nodes are assigned or not
			for(auto itr = nodes.begin(); itr != nodes.end() - 1; itr++){
				if((*itr)->isAssigned() == false){
					isAllAssigned = false;
					break;
				}
			}

			if (isAllAssigned == true) {
				for (auto itr = nodes.begin(); itr < nodes.end() - 2; itr++) {
					if(itr == nodes.begin()){
						output = (*itr)->getValue() ^ (*(itr + 1))->getValue();
					}else{
						output ^= (*itr)->getValue() ^ (*(itr + 1))->getValue();
					}
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

#endif /* XOR_H_ */

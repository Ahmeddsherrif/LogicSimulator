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

		virtual void simulateGate() override final {
			bool output = false;

			for (auto itr = nodes.begin(); itr < nodes.end() - 2; itr++) {
				if(itr == nodes.begin()){
					output = itr->getValue() ^ (itr + 1)->getValue();
				}else{
					output ^= itr->getValue() ^ (itr + 1)->getValue();
				}
			}

			if(isInverted){
				output = !output;
			}

			nodes.back().setValue(output);
		}

};

#endif /* XOR_H_ */

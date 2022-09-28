/*
 * Node.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef NODE_H_
#define NODE_H_

#include <string>

class Node {
	private:
		std::string name;
		bool value;
		bool state;
	public:
		std::string getName() const;
		void setName(char name);
		bool isValue() const;
		void setValue(bool value);
};

#endif /* NODE_H_ */

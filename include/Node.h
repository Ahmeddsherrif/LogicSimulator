/*
 * Node.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef NODE_H_
#define NODE_H_


class Node {
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	private:
		std::string name;
		bool assigned;
		bool value;
		bool output;


	public:
		Node(const std::string& name);

		void setValue(bool value);
		bool getValue() const;
		void setAsOutput();
		bool isOutput();
		bool isAssigned() const;

		bool operator& (const Node& lhs);
		bool operator| (const Node& lhs);
		bool operator^ (const Node& lhs);
};

#endif /* NODE_H_ */

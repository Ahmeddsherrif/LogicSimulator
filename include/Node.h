/*
 * Node.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef NODE_H_
#define NODE_H_

enum state_t{
	INPUT_NODE,
	OUTPUT_NODE,
	INNER_NODE,
	UNASSIGNED_NODE
};

class Node {
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	private:
		std::string name;
		bool assigned;
		bool value;

		static std::map<std::string, Node *> nodeLookup;

	public:
		Node();
		Node(const std::string& name);
		Node(const std::string& name, const bool& value);
		~Node();

		std::string getName() const;
		void setName(char name);
		bool getValue() const;
		bool setValue(bool value);
		bool isAssigned() const;
		void setAssigned(bool assigned);

		bool operator& (const Node& lhs);
		bool operator| (const Node& lhs);
		bool operator^ (const Node& lhs);

		static bool getNode(std::string nodeName, Node*& outNode);

};

#endif /* NODE_H_ */

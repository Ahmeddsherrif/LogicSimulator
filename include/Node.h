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
		bool value;
		bool state;

	private:
		static std::map<std::string, Node *> nodeLookup;

	public:
		Node();
		Node(const std::string& name);
		Node(const std::string& name, const bool& value);
		~Node();
		std::string getName() const;
		void setName(char name);
		bool isValue() const;
		void setValue(bool value);

		//TODO: Add AND, OR, XOR

	public:
		static bool getNode(std::string nodeName, Node *outNode);
};

#endif /* NODE_H_ */

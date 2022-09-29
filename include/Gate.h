/*
 * Gate.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#ifndef GATE_H_
#define GATE_H_


class Gate {
	private:
		unsigned int id;

		static unsigned int idGenerator;
		static std::map<unsigned int, Gate *> gateLookup;

	protected:
		unsigned char nodeCount;
		bool isInverted;
		bool isSimulated;
		std::vector<Node> nodes;

	public:
		Gate(const std::vector<Node> &nodes);
		Gate(const bool &isInverted);
		Gate();
		virtual ~Gate();

		virtual bool simulateGate()  = 0;
		virtual void addNode(const Node &inNode);

		bool is_gate_simulated() const;

		const std::vector<Node>& getNodes() const;
		void setNodes(const std::vector<Node *> &nodes);

		Node get_output_node();
		static bool getGate(unsigned int gateID, Gate *&outNode);

};

#endif /* GATE_H_ */

#include "logic_simulator.h"

int main() {
	std::string inputString;

	do {
		std::getline(std::cin, inputString);
	} while (GateGenerator::parse_input_string(inputString));

	return 0;
}

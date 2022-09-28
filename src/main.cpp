//============================================================================
// Name        : LogicSimulator.cpp
// Author      : AhmedSherif
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <memory>



#include "Node.h"


void print(const std::vector<std::string> & v){
	for (const auto & it : v){
	    std::cout << it << std::endl;
	}
}

std::vector<std::string> split(const std::string &s, const char &delim) {
    std::vector<std::string> result;
    std::string item;

    std::stringstream ss {s};

        while (std::getline(ss, item, delim)) {
            result.push_back (item);
        }

    return result;
}


int main() {
	enum keywords{
		AND,
		OR,
		SET,
		SIM
	};

	std::map<std::string, keywords>  parse {
		{"AND", AND},
		{"OR", OR},
		{"SET", SET},
		{"SIM", SIM}
	};

	std::map<std::string, keywords>::iterator itr = parse.begin();
	std::string input, parsedInput;
	const char stringDelimeter = ' ';

	bool isDone = false;


	do {
		std::getline(std::cin, input);
		std::vector<std::string> buffer = split(input, stringDelimeter);

		for (const auto & i : buffer){
			itr = parse.find(i);

			if (itr != parse.end()) {
				switch (itr->second) {
					case AND: {
						std::cout << "You Have Entered AND" << std::endl;
						break;
					}
					case OR: {
						std::cout << "You Have Entered OR" << std::endl;
						break;
					}
					case SET: {
						std::cout << "You Have Entered SET" << std::endl;
						break;
					}
					case SIM: {
						std::cout << "You Have Entered SIM" << std::endl;
						isDone = true;
						break;
					}
				}
			} else {
				std::cout << "WRONG INPUT" << std::endl;
			}
		}

	} while (isDone == false);

	return 0;
}

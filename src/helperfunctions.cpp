/*
 * helperfunctions.cpp
 *
 *  Created on: Sep 30, 2022
 *      Author: Master
 */

#include <vector>
#include <string>

#include "helperfunctions.h"



std::vector<std::string> helper_functions::split_string(const std::string &s, const char &delim){
	std::vector<std::string> result;
	std::string item;

	std::stringstream ss { s };

	while (std::getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

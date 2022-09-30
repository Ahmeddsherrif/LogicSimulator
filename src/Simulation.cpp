/*
 * Simulation.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: Master
 */

#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "Trace.h"
#include "Node.h"
#include "Gate.h"
#include "Simulation.h"


bool Simulation::start(std::set<Gate *> &gateSet){
	bool rtnValue = true;

	bool isSimulationCompleted;
	bool isGateSimulated;

	 do{

		isSimulationCompleted = true;
		isGateSimulated = false;

		for (auto itr = gateSet.begin(); itr != gateSet.end(); itr++) {

			// Check to see if it was simulated before or not
			if ((*itr)->is_gate_simulated() == false) {
				TRACE_PRINT("This Gate Has never Been Simulated before");

				if((*itr)->simulateGate() == true){
					isGateSimulated = true;
				}

				isSimulationCompleted = false;
			}else{
				TRACE_PRINT("This Gate Has Been Simulated before");
			}
		}

		// Not a single gate in the iteration have been simulated successfully
		if(isGateSimulated == false && isSimulationCompleted == false){
			rtnValue = false;
			break;
		}

	}while (isSimulationCompleted == false);

	return rtnValue;
}


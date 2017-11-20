/*
 * Simulator.h
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#ifndef SRC_SIMULATOR_H_
#define SRC_SIMULATOR_H_

#include <vector>

#include "Process.h"

class Simulator {
public:
	Simulator();
	virtual ~Simulator();
	void tick();
private:
	std::vector<Process> processes;
	int ticks;
};

#endif /* SRC_SIMULATOR_H_ */

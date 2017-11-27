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
	void simulate(int);
	void init_process(std::vector<Process*>* elements);
private:
	std::vector<Process*> processes;
	void tick();
	void init();

};

#endif /* SRC_SIMULATOR_H_ */

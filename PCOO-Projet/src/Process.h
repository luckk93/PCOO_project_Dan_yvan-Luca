/*
 * Process.h
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#ifndef SRC_PROCESS_H_
#define SRC_PROCESS_H_

#include <iostream>

class Process {
public:
	Process();
	virtual ~Process();
	virtual void run();
	virtual void init();
private:
	std::string name;
};

#endif /* SRC_PROCESS_H_ */

/*
 * Process.h
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#ifndef SRC_PROCESS_H_
#define SRC_PROCESS_H_

#include <iostream>
#include <iomanip>

using namespace std;
class Process {
public:
	Process();
	virtual ~Process();
	virtual void run() = 0;
	string getName(){return name;};
	// virtual void init() = 0;
protected:
	string name;
	std::ostringstream logstring;
};

#endif /* SRC_PROCESS_H_ */

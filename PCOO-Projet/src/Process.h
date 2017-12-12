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
#include <sstream>

using namespace std;
class Process {
public:
	Process();
	virtual ~Process();
	virtual void run() = 0;
	string getName(){return name;};
protected:
	string name;
	ostringstream logstring;
};

#endif /* SRC_PROCESS_H_ */

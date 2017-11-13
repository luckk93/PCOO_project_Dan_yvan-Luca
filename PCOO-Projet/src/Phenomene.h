/*
 * Phenomene.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_PHENOMENE_H_
#define SRC_PHENOMENE_H_

#include "Etat.h"

class Phenomene {
public:
	Phenomene();
	virtual ~Phenomene();
	void run();
private:
	Etat*etat;
	double generate();
};

#endif /* SRC_PHENOMENE_H_ */

/*
 * Phenomene.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_PHENOMENE_H_
#define SRC_PHENOMENE_H_


#include <cstdlib>
#include "Etat.h"

class Phenomene {
public:
	Phenomene();
	virtual ~Phenomene();
	void run();
	void init_etat(Etat*e){etat = e;};
private:
	Etat*etat;
	double generate();
};

#endif /* SRC_PHENOMENE_H_ */

/*
 * Phenomene.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_PHENOMENE_H_
#define SRC_PHENOMENE_H_


#include <cstdlib>
#include <time.h>
#include <cmath>
#include <cassert>

#include "Etat.h"

const double PI = 3.1416;

class Phenomene: public Process{
public:
	virtual void run();
protected:
	Serveur*serveur;
	Etat *etat;
	virtual double generate() = 0;
	long long int tick=0;
};

#endif /* SRC_PHENOMENE_H_ */

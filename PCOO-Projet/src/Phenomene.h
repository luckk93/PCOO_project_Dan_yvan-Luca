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


#include "Process.h"
#include "Etat.h"

class Phenomene: public Process{
public:
	Phenomene();
	virtual ~Phenomene();
	virtual void run();
	virtual void init(Etat*e,double min,double max,Serveur*s);
private:
	Serveur*serveur;
	Etat *etat;
	double generate();
	double valMin;
	double valMax;
};

#endif /* SRC_PHENOMENE_H_ */

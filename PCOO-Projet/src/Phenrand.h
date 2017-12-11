/*
 * Phenrand.h
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#ifndef SRC_PHENRAND_H_
#define SRC_PHENRAND_H_

#include "Phenomene.h"
using namespace std;
class Phen_rand: virtual public Phenomene {
public:
	Phen_rand();
	Phen_rand(string n,Etat*e, Serveur*s, double min, double max);
	virtual ~Phen_rand();
private:
	double valMin;
	double valMax;
	double generate();
};

#endif /* SRC_PHENRAND_H_ */

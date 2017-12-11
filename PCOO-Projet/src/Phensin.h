/*
 * Phensin.h
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#ifndef SRC_PHENSIN_H_
#define SRC_PHENSIN_H_

#include "Phenomene.h"
using namespace std;
class Phen_sin : virtual public Phenomene {
public:
	Phen_sin();
	Phen_sin(string n,Etat*e, Serveur*s, double a, double b, long int c, long int d, double random, double min, double max);
	virtual ~Phen_sin();
private:
    double generateRand();
	double generate();

	double offs =0;
	double ampl =1;
	long int phase=0;
    long int period=10;

    double rand_ampl=0.5;

    double sat_min = -50;
	double sat_max =50;
};

#endif /* SRC_PHENSIN_H_ */

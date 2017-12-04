/*
 * Phensin.h
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#ifndef SRC_PHENSIN_H_
#define SRC_PHENSIN_H_

#include "Phenomene.h"

class Phen_sin : Phenomene {
public:
	Phen_sin();
	virtual ~Phen_sin();
private:
	double generate();
	long long int tick=0;
	int signal_select=0;
	
	double offs =0;
	double ampl =1;
	long int phase=0;
	// long int period=10;
	double sat_max =50;
	double sat_min = -50;
};

#endif /* SRC_PHENSIN_H_ */

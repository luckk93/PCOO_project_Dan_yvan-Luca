/*
 * Phenomene.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_PHENOMENE_H_
#define SRC_PHENOMENE_H_

#define PI 3.1416


#include <cstdlib>
#include <time.h>
#include <cmath>


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
	
	long long int tick=0;
	int signal_select=0;
	
	double offs =0;
	double ampl =1;
	long int phase=0;
	long int period=10;
	double sat_max =50;
	double sat_min = -50;
	
	double v_low =0;
	double v_high = 10;
	long int t_del= 3;
	long int t_rise= 3;
	long int pwidth = 5;
	long int t_fall= 3;
	long int period = 13;
	
};

#endif /* SRC_PHENOMENE_H_ */

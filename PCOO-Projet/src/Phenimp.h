/*
 * Phenimp.h
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#ifndef SRC_PHENIMP_H_
#define SRC_PHENIMP_H_

#include "Phenomene.h"
using namespace std;
class Phen_imp : virtual public Phenomene {
public:
	// Phen_imp();
	Phen_imp(string n,Etat*e, Serveur*s, double a, double b, long int c, long int d, long int f, long int g, long int h, double min, double max,  double u, double o);
	virtual ~Phen_imp();
private:
    double generateRand();
	double generate();

	double v_low =0;
	double v_high = 10;
	long int t_del= 3;
	long int t_rise= 3;
	long int pwidth = 5;
	long int t_fall= 3;
	long int period = 13;

    double sat_min = -50;
	double sat_max =50;

	double mu;
	double sigma;
};

#endif /* SRC_PHENIMP_H_ */

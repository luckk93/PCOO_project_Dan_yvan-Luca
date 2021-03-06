/*
 * Controleur.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_CONTRONOFF_H_
#define SRC_CONTRONOFF_H_

#include <iostream>

#include "Controleur.h"
using namespace std;
class ContrOnOff: virtual public Controleur {
public:
	ContrOnOff(string n,Etat*e,Serveur*s,double tmin, double tmax, double vmin, double vmax);
	virtual ~ContrOnOff();
private:
	double trigMin, trigMax, valMin, valMax;
	virtual void compute_valCtrl();
};

#endif /* SRC_CONTRONOFF_H_ */
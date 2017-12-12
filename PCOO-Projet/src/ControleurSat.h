/*
 * Controleur.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_CONTRSAT_H_
#define SRC_CONTRSAT_H_

#include <iostream>

#include "Controleur.h"
using namespace std;
class ContrSat: virtual public Controleur {
public:
	// ContrSat();
	ContrSat(string n,Etat*e,Serveur*s,double sat);
	virtual ~ContrSat();
private:
    double valSat;
	virtual void compute_valCtrl();
};

#endif /* SRC_CONTRSAT_H_ */

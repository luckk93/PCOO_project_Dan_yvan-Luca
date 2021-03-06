/*
 * Controleur.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_CONTRP_H_
#define SRC_CONTRP_H_

#include <iostream>

#include "Controleur.h"
using namespace std;
class ContrP: virtual public Controleur {
public:
	ContrP(string n,Etat*e,Serveur*s,double val_o, double g);
	virtual ~ContrP();
private:
	double valOrder, gain, errorP = 0;
	virtual void compute_valCtrl();
};

#endif /* SRC_CONTRP_H_ */

/*
 * Controleur.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_CONTROLEUR_H_
#define SRC_CONTROLEUR_H_

#include <iostream>

#include "Etat.h"
#include "Serveur.h"

class Controleur: virtual public Process {
public:
	virtual void run();
protected:
	Serveur*serveur;
	Etat*etat;
	double valPhen, valEtat, valCtrl;
	virtual void send_valPhen();
	virtual void send_valEtat();
	virtual void send_valCtrl();
	virtual void compute_valCtrl() = 0;
	long long int tick=0;
};

#endif /* SRC_CONTROLEUR_H_ */

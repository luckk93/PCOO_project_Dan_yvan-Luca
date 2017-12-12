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
	Controleur();
	virtual ~Controleur() = 0;
	virtual void run();
protected:
	Serveur*serveur;
	Etat*etat;
	double valPhen, valEtat, valCtrl;
	void send_valPhen();
	void send_valEtat();
	void send_valCtrl();
	virtual void compute_valCtrl() = 0;
	long long int tick=0;
};

#endif /* SRC_CONTROLEUR_H_ */

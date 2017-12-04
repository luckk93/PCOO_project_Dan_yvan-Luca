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
	virtual ~Controleur();
	virtual void run();
	virtual void init(Etat*,Serveur*,double);
private:
	Serveur*serveur;
	Etat*etat;
	double valPhen, valEtat, valCtrl, valSat;
	void send_valPhen();
	void send_valEtat();
	void send_valCtrl();
	void compute_valCtrl();
};

#endif /* SRC_CONTROLEUR_H_ */

/*
 * Controleur.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_CONTROLEUR_H_
#define SRC_CONTROLEUR_H_
#include "Etat.h"
#include "Serveur.h"

class Controleur {
public:
	Controleur();
	virtual ~Controleur();
	void run();
	void init_etat(Etat*e){etat = e;};
	void init_serveur(Serveur*s){serveur = s;};
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

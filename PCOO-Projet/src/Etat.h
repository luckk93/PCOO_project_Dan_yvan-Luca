/*
 * Etat.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_ETAT_H_
#define SRC_ETAT_H_

#include <iostream>

#include "Process.h"
#include "Serveur.h"

class Etat: public Process {
public:
	Etat();
	virtual ~Etat();
	void store_phen(double v){val_phen = v;};
	void store_ctrl(double v){val_ctrl = v;};
	double get_valPhen(){return val_phen;};
	double get_etatCourant(){return etat_courant;};
	virtual void run();
	virtual void init(double e, double p, double c,Serveur*s);
private:
	Serveur*serveur;
	double etat_effectif;
	double etat_courant;
	double I_phen;
	double I_ctrl;
	double val_phen;
	double val_ctrl;
	void calcule();
};

#endif /* SRC_ETAT_H_ */

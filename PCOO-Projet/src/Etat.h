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
using namespace std;
class Etat: virtual public Process {
public:
	// Etat();
	Etat(string n, double e, double p, double c,Serveur*s);
	virtual ~Etat();
	void store_phen(double v){val_phen = v;};
	void store_ctrl(double v){val_ctrl = v;};
	double get_valPhen(){return val_phen;};
	double get_etatCourant(){return etat_courant;};
	virtual void run();
private:
	Serveur*serveur;
	double etat_effectif=0;
	double etat_courant=0;
	double I_phen=0;
	double I_ctrl=0;
	double val_phen=0;
	double val_ctrl=0;
	void calcule();
    long long int tick=0;
};

#endif /* SRC_ETAT_H_ */

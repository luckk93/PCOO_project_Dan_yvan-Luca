/*
 * Etat.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Etat.h"

using namespace std;
// Etat::Etat() {
// }

Etat::Etat(string n, double e, double p, double c, Serveur*s){
	etat_courant = e;
	I_phen = p;
	I_ctrl = c;
	serveur = s;
	name = n;

	logstring.str("");
	logstring.clear();
	logstring << "[" <<name << "]  Creation" << endl;
	logstring << "\tphen_factor = " << I_phen << " ctrl_factor = " << I_ctrl << endl;
    logstring << "\tphen_val = " << val_phen << ", ctrl_val = " << val_ctrl << ", state_val = " << etat_courant << endl;
	serveur->log(logstring.str());
}

Etat::~Etat() {
}

void Etat::calcule(){
	etat_effectif = etat_courant + (val_phen - etat_courant) * I_phen + (val_ctrl - etat_courant) * I_ctrl;
	etat_courant = etat_effectif;
}

void Etat::run(){
	calcule();

    logstring.str("");
	logstring.clear();
	logstring << "[" <<name << "]  tick = " << tick << ", state_val = " << etat_courant << endl;
	serveur->log(logstring.str());

	tick++;
}

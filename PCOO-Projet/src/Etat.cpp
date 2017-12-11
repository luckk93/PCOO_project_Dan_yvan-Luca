/*
 * Etat.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Etat.h"

using namespace std;
Etat::Etat() {
}

Etat::Etat(double e, double p, double c, Serveur*s){
	etat_courant = e;
	I_phen = p;
	I_ctrl = c;
	serveur = s;
	serveur->log("Etat initialized...\n");
}

Etat::~Etat() {
}

void Etat::calcule(){
	etat_effectif = etat_courant + (val_phen - etat_courant) * I_phen + (val_ctrl - etat_courant) * I_ctrl;
	etat_courant = etat_effectif;
}

void Etat::run(){
	serveur->log("Etat running...\n");
	calcule();
}

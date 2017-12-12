/*
 * Controleur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Controleur.h"

using namespace std;

// Controleur::Controleur() {
// }

// Controleur::~Controleur() {
// }

void Controleur::run(){
	send_valPhen();
	send_valEtat();
	compute_valCtrl();
	send_valCtrl();

	logstring.str("");
	logstring.clear();
	logstring << "[" <<name << "]  tick = " << tick << ", phen_val = " << valPhen << ", state_val = " << valEtat << ", ctrl_val = " << valCtrl << endl;
	serveur->log(logstring.str());

	tick++;
}

void Controleur::send_valPhen(){
	valPhen=etat->get_valPhen();
	serveur->store_phen(valPhen);
}

void Controleur::send_valEtat(){
	valEtat=etat->get_etatCourant();
	serveur->store_etat(valEtat);
}

void Controleur::send_valCtrl(){
	serveur->store_ctrl(valCtrl);
	etat->store_ctrl(valCtrl);
}

/*
 * Controleur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Controleur.h"

Controleur::Controleur() {
	// TODO Auto-generated constructor stub

}

Controleur::~Controleur() {
	// TODO Auto-generated destructor stub
}

void Controleur::run(){
	send_valPhen();
	send_valEtat();
	compute_valCtrl();
	send_valCtrl();
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
	valCtrl=valEtat;
	serveur->store_ctrl(valCtrl);
	etat->store_ctrl(valCtrl);
}

void Controleur::compute_valCtrl(){
	// On/Off controller
	if(valEtat > valSat){
		valCtrl = valSat;
	}
	else{
		valCtrl = valPhen;
	}
}

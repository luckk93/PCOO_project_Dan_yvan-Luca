/*
 * Controleur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "ControleurP.h"

#include <iostream>

using namespace std;

// ContrP::ContrP() {
// }

ContrP::ContrP(string n,Etat*e,Serveur*s,double val_o, double g){
	etat = e;
	serveur = s;
	valOrder = val_o;
	gain=g;
	name=n;
	serveur->log("Controller initialized...\n");
}

ContrP::~ContrP() {
}

void ContrP::compute_valCtrl(){
    errorP = (valEtat - valOrder);
	valCtrl= valCtrl - (errorP * gain);
}


/*
 * Controleur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "ControleurP.h"

#include <iostream>

using namespace std;

ContrP::ContrP(string n,Etat*e,Serveur*s,double val_o, double g):valOrder(val_o),gain(g){
	// Inherited attributes
	name=n;
	etat = e;
	serveur = s;

	logstring.str("");
	logstring.clear();
	logstring << "[" <<name << "]\tCreation" << endl;
	logstring << "\tOrder_val= " << valOrder << ", P_gain= " << gain << endl;
	serveur->log(logstring.str());
}

ContrP::~ContrP() {
}

void ContrP::compute_valCtrl(){
	errorP = (valEtat - valOrder);
	valCtrl= valCtrl - (errorP * gain);
}
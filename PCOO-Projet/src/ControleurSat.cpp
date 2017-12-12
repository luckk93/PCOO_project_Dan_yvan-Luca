/*
 * Controleur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "ControleurSat.h"

using namespace std;

ContrSat::ContrSat(string n,Etat*e,Serveur*s,double sat):valSat(sat){
	// Inherited attributes
	name = n;
	etat = e;
	serveur = s;

	logstring.str("");
	logstring.clear();
	logstring << "[" <<name << "]\tCreation" << endl;
	logstring << "\tSat_value= " << valSat << endl;
	serveur->log(logstring.str());
}

ContrSat::~ContrSat() {
}

void ContrSat::compute_valCtrl(){
	if(valPhen > valSat){
		valCtrl = valSat;
	}
	else{
		valCtrl = valPhen;
	}
}


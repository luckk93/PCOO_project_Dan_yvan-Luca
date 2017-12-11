/*
 * Controleur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "ControleurSat.h"
#include "logcall.h"

using namespace std;

ContrSat::ContrSat() {
}

ContrSat::ContrSat(Etat*e,Serveur*s,double sat){
	etat = e;
	serveur = s;
	valSat = sat;
	serveur->log("Controller initialized...\n");
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


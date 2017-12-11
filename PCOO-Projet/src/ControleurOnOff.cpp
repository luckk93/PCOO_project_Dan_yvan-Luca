/*
 * Controleur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "ControleurOnOff.h"

using namespace std;

ContrOnOff::ContrOnOff() {
}

ContrOnOff::ContrOnOff(Etat*e,Serveur*s,double tmin, double tmax, double vmin, double vmax){
	etat = e;
	serveur = s;
	trigMin = tmin;
	trigMax = tmax;
	valMin= vmin;
	valMax= vmax;
	serveur->log("Controller initialized...\n");
}

ContrOnOff::~ContrOnOff() {
}

void ContrOnOff::compute_valCtrl(){
	if(valEtat > trigMax) valCtrl = valMin;
	else if((valEtat < trigMin)) valCtrl = valMax;
	else valCtrl = valEtat;
}


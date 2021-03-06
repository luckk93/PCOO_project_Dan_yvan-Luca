/*
 * Controleur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "ControleurOnOff.h"

using namespace std;

ContrOnOff::ContrOnOff(string n,Etat*e,Serveur*s,double tmin, double tmax, double vmin, double vmax):trigMin(tmin),trigMax(tmax),valMin(vmin),valMax(vmax){
	// Inherited attributes
	name = n;
	etat = e;
	serveur = s;

	logstring.str("");
	logstring.clear();
	logstring << "[" <<name << "]\tCreation" << endl;
	logstring << "\tTrig_min= " << trigMin << ", Trig_max= " << trigMax << endl;
	logstring << "\tValue_min= " << valMin << ", Value_max= " << valMax << endl;
	serveur->log(logstring.str());
	}

ContrOnOff::~ContrOnOff() {
}

void ContrOnOff::compute_valCtrl(){
	if(valEtat > trigMax) valCtrl = valMin;
	else if((valEtat < trigMin)) valCtrl = valMax;
	else valCtrl = valEtat;
}
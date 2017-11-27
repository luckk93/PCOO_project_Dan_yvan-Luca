/*
 * Etat.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include <iostream>

#include "Etat.h"

using namespace std;
Etat::Etat() {
}

Etat::~Etat() {
}

void Etat::calcule(){
	etat_effectif = etat_courant + (val_phen - etat_courant) * I_phen + (val_ctrl - etat_courant) * I_ctrl;
	etat_courant = etat_effectif;
}

void Etat::run(){
	calcule();
}

void Etat::init(double e, double p, double c){
	etat_courant = e;
	I_phen = p;
	I_ctrl = c;
}
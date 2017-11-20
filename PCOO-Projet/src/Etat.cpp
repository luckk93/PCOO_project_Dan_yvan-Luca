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
	// TODO Auto-generated constructor stub

}

Etat::~Etat() {
	// TODO Auto-generated destructor stub
}

void Etat::calcule(){
	etat_effectif = etat_courant + (val_phen - etat_courant) * I_phen + (val_ctrl - etat_courant) * I_ctrl;
	etat_courant = etat_effectif;
}

void Etat::run(){
	calcule();
}

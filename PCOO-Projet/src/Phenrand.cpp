/*
 * Phenrand.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#include "Phenrand.h"

#define <cmath>

Phen_rand::Phen_rand() {
}

Phen_rand::Phen_rand(string n,Etat*e, Serveur*s, double min, double max){
	etat = e;
	srand(time(0));
	valMin = min;
	valMax = max;
	serveur = s;
	name = n;
	serveur->log("Phenomene initialized...\n");
}

Phen_rand::~Phen_rand() {
}

double Phen_rand::generate(){
	return valMin + (valMax - valMin)*((double)(rand())/RAND_MAX);
}


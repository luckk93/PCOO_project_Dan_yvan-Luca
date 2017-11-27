/*
 * Phenomene.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Phenomene.h"

Phenomene::Phenomene(){
}

Phenomene::~Phenomene(){
}

void Phenomene::run(){
	etat->store_phen(generate());
}

double Phenomene::generate(){
	return valMin + (valMax - valMin)*((double)(rand())/RAND_MAX);
}

void Phenomene::init(Etat*e,double min,double max){
	etat = e;
	srand(time(0));
	valMin = min;
	valMax = max;
}

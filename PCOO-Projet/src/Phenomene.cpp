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
	etat.store_phen(generate());
}

double Phenomene::generate(){
	return 20+ ((double)(rand()%1000)/100);
}

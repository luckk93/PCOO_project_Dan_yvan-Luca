/*
 * Phenomene.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Phenomene.h"

Phenomene::Phenomene() {
	// TODO Auto-generated constructor stub

}

Phenomene::~Phenomene() {
	// TODO Auto-generated destructor stub
}

void Phenomene::run(){
	etat->store_phen(generate());
}

double Phenomene::generate(){
	return rand();
}
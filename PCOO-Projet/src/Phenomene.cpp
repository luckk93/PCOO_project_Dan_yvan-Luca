/*
 * Phenomene.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Phenomene.h"

// Phenomene::Phenomene(){
// }

// Phenomene::~Phenomene(){
// }

void Phenomene::run(){
    double value=generate();
	etat->store_phen(value);

	logstring.str("");
	logstring.clear();
	logstring << "[" <<name << "]  tick = " << tick << ", val = " << value << endl;
	serveur->log(logstring.str());

	tick++;
}

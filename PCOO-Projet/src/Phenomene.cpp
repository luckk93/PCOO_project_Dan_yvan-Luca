/*
 * Phenomene.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Phenomene.h"

void Phenomene::run(){
	double value=generate();
	etat->store_phen(value);

	logstring.str("");
	logstring.clear();
	logstring << "[" <<name << "]\ttick = " << tick << ", val = " << value << endl;
	serveur->log(logstring.str());

	tick++;
}

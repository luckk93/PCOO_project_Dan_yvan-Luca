/*
 * Phenrand.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#include "Phenrand.h"

Phen_rand::Phen_rand() {
}

Phen_rand::~Phen_rand() {
}

double Phen_rand::generate(){
	return valMin + (valMax - valMin)*((double)(rand())/RAND_MAX);
}


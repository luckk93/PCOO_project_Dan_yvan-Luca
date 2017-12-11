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

Phen_rand::Phen_rand(string n,Etat*e, Serveur*s, double min, double max, double u, double o){
	etat = e;
	srand(time(0));
	satMin = min;
	satMax = max;
	serveur = s;
	name = n;
	mu = u;
	sigma = o;
	serveur->log("Phenomene initialized...\n");
}

Phen_rand::~Phen_rand() {
}

double Phen_rand::generate(){
    double x1=0, x2=0;
    while(x1==0) x1= ((double)(rand())/RAND_MAX);
    while(x2==0) x2= ((double)(rand())/RAND_MAX);

	return valMin + (valMax - valMin)*((double)(rand())/RAND_MAX);
}


/*
 * Phenrand.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#include "Phenrand.h"

#include <cmath>

// Phen_rand::Phen_rand() {
// }

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
    double x1=0, x2=0, y;
    while(x1==0) x1= ((double)(rand())/RAND_MAX);
    while(x2==0) x2= ((double)(rand())/RAND_MAX);
    y=sqrt((-2)*log(x1)) * cos (2*PI*x2);
	return mu + y * sigma;
}


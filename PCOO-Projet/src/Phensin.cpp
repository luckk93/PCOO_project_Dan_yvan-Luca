/*
 * Phensin.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#include "Phensin.h"

// Phen_sin::Phen_sin() {
// }

Phen_sin::Phen_sin(string n,Etat*e, Serveur*s, double a, double b, long int c, long int d, double random, double min, double max,  double u, double o){
	name = n;
    etat = e;
	serveur = s;
	srand(time(0));

    offs =a;
	ampl =b;
	phase=c;
    period=d;

    rand_ampl=random;

	sat_min = min;
	sat_max =max;

	mu = u;
	sigma = o;

	serveur->log("Phenomene initialized...\n");
}

Phen_sin::~Phen_sin() {
}

double Phen_sin::generateRand(){
	 double x1=0, x2=0, y;
    while(x1==0) x1= ((double)(rand())/RAND_MAX);
    while(x2==0) x2= ((double)(rand())/RAND_MAX);
    y=sqrt((-2)*log(x1)) * cos (2*PI*x2);
	return mu + y * sigma;
}

double Phen_sin::generate(){
	double sin_point = offs + ampl * sin(2*PI*(tick+phase)/period);
	double wave_point = (sin_point + generateRand());
	if(wave_point > sat_max) wave_point= sat_max;
	else if (wave_point < sat_min) wave_point = sat_min;
	return wave_point;
}

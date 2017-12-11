/*
 * Phenimp.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#include "Phenimp.h"

Phen_imp::Phen_imp() {
}

Phen_imp::Phen_imp(string n,Etat*e, Serveur*s, double a, double b, long int c, long int d, long int f, long int g, long int h, double random, double min, double max,  double u, double o){
	name = n;
	etat = e;
	serveur = s;
	srand(time(0));

	v_low =a;
	v_high = b;
	t_del= c;
	t_rise= d;
	pwidth = f;
	t_fall= g;
	period = h;

	rand_ampl=random;

	sat_min = min;
	sat_max =max;

	mu = u;
	sigma = o;
}

Phen_imp::~Phen_imp() {
}

double Phen_imp::generateRand(){
    double x1=0, x2=0, y;
    while(x1==0) x1= ((double)(rand())/RAND_MAX);
    while(x2==0) x2= ((double)(rand())/RAND_MAX);
    y=sqrt((-2)*log(x1)) * cos (2*PI*x2);
	return mu + y * sigma;}

double Phen_imp::generate(){
	long int period_tick = (tick - t_del);
	period_tick++;
	period_tick %= period;
	double imp_point;

	if(period_tick < 0) imp_point = v_low;
	else if(period_tick <= t_rise) imp_point = (((v_high-v_low)/t_rise)*period_tick) + v_low;
	else if(period_tick < (t_rise+pwidth)) imp_point = v_high;
	else if(period_tick < (t_rise+pwidth+t_fall)) imp_point = v_high-((v_high-v_low)/t_fall)*(period_tick-(t_rise+pwidth));
	else imp_point = v_low;

	double wave_point = (imp_point + generateRand());
	//double wave_point = (imp_point); // Debug
	if(wave_point > sat_max) wave_point= sat_max;
	else if (wave_point < sat_min) wave_point = sat_min;
	return wave_point;
}


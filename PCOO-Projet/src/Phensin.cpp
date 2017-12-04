/*
 * Phensin.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#include "Phensin.h"

Phen_sin::Phen_sin() {
}

Phen_sin::~Phen_sin() {
}

double Phen_sin::generate(){
	double sin_point = offs + ampl * sin(2*PI*(tick+phase)/period);
	double wave_point = (sin_point + generateRand());
	if(wave_point > sat_max) wave_point= sat_max;
	else if (wave_point < sat_min) wave_point = sat_min;
	return wave_point;
}

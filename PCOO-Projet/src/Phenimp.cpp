/*
 * Phenimp.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#include "Phenimp.h"

Phen_imp::Phen_imp() {
}

Phen_imp::~Phen_imp() {
}

double Phen_imp::generate(){
	long int period_tick = (tick - t_del) % period;
	double imp_point;
	
	if(period_tick < 0) imp_point = v_low;
	else if(period_tick <= t_rise) imp_point = ((v_high-v_low)/t_rise)*tick;
	if(period_tick < (t_rise+pwidth)) imp_point = v_high;
	if(period_tick < (t_rise+pwidth+t_fall)) imp_point = ((v_low-v_high)/t_fall)*(tick-(t_rise+pwidth));
	else imp_point = v_low;

	double wave_point = (imp_point + generateRand());
	if(wave_point > sat_max) wave_point= sat_max;
	else if (wave_point < sat_min) wave_point = sat_min;
	return wave_point;
}


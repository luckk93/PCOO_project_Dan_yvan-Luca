/*
 * main.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#include <iostream>
#include <string>

#include "Phenomene.h"
#include "Etat.h"
#include "Controleur.h"
#include "Serveur.h"

int main(){
	const double init_temp = 20.0; // Initial temperature
	const double i_phen = 0.5; // Influence factor from phenomenon to state
	const double i_ctrl = 0.1; // Influence factor from controller to state

	// Declare actors
	Phenomene phen;
	Etat etat;
	Controleur ctrl;
	Serveur serv;

	// Init the actors
	phen.init_etat(etat);
	etat.init_valEtat(20.0);
	etat.init_factor(i_phen, i_ctrl);
	ctrl.init_etat(&etat);
	ctrl.init_serveur(&serv);


	return 0;
}

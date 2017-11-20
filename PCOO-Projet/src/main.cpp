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

using namespace std;

int main(){
	const double INIT_TEMP = 20.0; // Initial temperature
	const double I_PHEN = 0.5; // Influence factor from phenomenon to state
	const double I_CTRL = 0.1; // Influence factor from controller to state
	const int NB_TICKS = 50; // Duration of the simulation

	// Declare actors
	Phenomene phen;
	Etat etat;
	Controleur ctrl;
	Serveur serv;

	// Init the actors
	cout << "Initialising simulation...\n";
	phen.init_etat(etat);
	etat.init_valEtat(INIT_TEMP);
	etat.init_factor(I_PHEN, I_CTRL);
	ctrl.init_etat(&etat);
	ctrl.init_serveur(&serv);
	serv.init();

	// Run the simulation
	cout << "Starting simulation\n";
	for(int i=0; i<NB_TICKS; i++){
		phen.run();
		ctrl.run();
		etat.run();
		serv.run();
	}

	return 0;
}

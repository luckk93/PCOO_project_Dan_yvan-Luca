/*
 * Simulator.h
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#ifndef SRC_SIMULATOR_H_
#define SRC_SIMULATOR_H_

#include <vector>

#include "Phenomene.h"
#include "Etat.h"
#include "Controleur.h"
#include "Serveur.h"
#include "Process.h"

#include "Phenrand.h"
#include "Phensin.h"
#include "Phenimp.h"

#include "ControleurSat.h"
#include "ControleurOnOff.h"
#include "ControleurP.h"

using namespace std;

class Simulator {
public:
	Simulator();
	Simulator(int tick_nbr, string t);
	void push_back(Process*p);
	virtual ~Simulator();
	void simulate();
private:
	string time_unit;
	vector<Process*> processes;
	void tick();
	int sim_lenght;
};

#endif /* SRC_SIMULATOR_H_ */

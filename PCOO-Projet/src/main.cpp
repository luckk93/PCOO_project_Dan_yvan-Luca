/*
 * main.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#include <iostream>
#include <string>
#include <vector>

#include "Process.h"
#include "Simulator.h"


using namespace std;

int main(){
	const double INIT_TEMP = 20.0; // Initial temperature
	const double I_PHEN = 0.1; // Influence factor from phenomenon to state
	const double I_CTRL = 0.8; // Influence factor from controller to state
	const int NB_TICKS = 50; // Duration of the simulation

	const double CTRL_SAT = 24.0; // Saturation value of the controller

    const double CTRL_TMIN = 19.0;
    const double CTRL_TMAX = 20.0;
    const double CTRL_VMIN = 5.0;
    const double CTRL_VMAX = 50.0;

    const double CTRL_P_ORDER = 19.0;
    const double CTRL_P_GAIN = 2.0;

    const double RAND1_MU = 20.0;
    const double RAND1_SIGMA = 0.2;
    const double RAND2_MU = 0.0;
    const double RAND2_SIGMA = 1.0;


	const double VAL_MIN = 20; // Minimum value of the phenomenon
	const double VAL_MAX = 30; // Maximum value of the phenomenon

	const double VAL_SIN_OFFS = 0;
	const double VAL_SIN_AMPL = 10;
	const long int VAL_SIN_PHASE = 0;
    const long int VAL_SIN_PERIOD = 10;
    const double VAL_RAND_AMPL = 0.1;
	const double VAL_SIN_SAT_MIN = -50;
	const double VAL_SIN_SAT_MAX = 50;

	const double VAL_IMP_LOW =0;
	const double VAL_IMP_HIGH = 10;
	const long int VAL_IMP_DEL= 3;
	const long int VAL_IMP_RISE= 3;
	const long int VAL_IMP_WIDTH = 5;
	const long int VAL_IMP_FALL= 3;
	const long int VAL_IMP_PERIOD = 13;
    const double VAL_IMP_RAND_AMPL=0.5;
    const double VAL_IMP_SAT_MIN = -50;
	const double VAL_IMP_SAT_MAX =50;

	cout << "-i- Building actors\n";

	// Create and init the  server
	Serveur serv;
	// serv.log("Server created and Initialised.\n");

	// Declare actors
	Etat etat("Etat",INIT_TEMP,I_PHEN,I_CTRL,&serv);
	// serv.log("Etat created and Initialised...\n");

	Phen_rand phenr("Phen random",&etat, &serv, VAL_MIN, VAL_MAX, RAND1_MU, RAND1_SIGMA);

	Phen_sin phens("Phen sin",&etat, &serv, VAL_SIN_OFFS, VAL_SIN_AMPL, VAL_SIN_PHASE,
                VAL_SIN_PERIOD, VAL_RAND_AMPL, VAL_SIN_SAT_MIN, VAL_SIN_SAT_MAX, RAND2_MU, RAND2_SIGMA);

    Phen_imp pheni("Phen imp",&etat, &serv, VAL_IMP_LOW, VAL_IMP_HIGH, VAL_IMP_DEL, VAL_IMP_RISE, VAL_IMP_WIDTH,
                   VAL_IMP_FALL, VAL_IMP_PERIOD, VAL_IMP_RAND_AMPL, VAL_IMP_SAT_MIN, VAL_IMP_SAT_MAX, RAND2_MU, RAND2_SIGMA);

	// serv.log("Phenomene created and Initialised...\n");

	//ctrl.init(&etat,&serv,CTRL_SAT);
	ContrSat ctrls("Ctrl Sat",&etat,&serv,CTRL_SAT);

	ContrOnOff ctrlo("Ctrl On/Off",&etat,&serv,CTRL_TMIN, CTRL_TMAX, CTRL_VMIN, CTRL_VMAX);

    ContrP ctrlp("Ctrl P",&etat,&serv,CTRL_P_ORDER, CTRL_P_GAIN);

	// serv.log("Controller created and Initialised...\n");

	vector<Process*> elements;
	elements.push_back(&pheni);
	elements.push_back(&ctrlp);
	elements.push_back(&etat);
	elements.push_back(&serv);

	// Run the simulation
	// serv.log("Starting simulation\n");

	Simulator mySimulator(NB_TICKS, &elements);
	mySimulator.simulate();
	// serv.log("End simulation...\n");

	// Plot the output
	serv.log("Use gnuplot to plot the output\n");
	system("gnuplot ../plot.sh");


	return 0;
}

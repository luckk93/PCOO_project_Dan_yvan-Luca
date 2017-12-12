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
	const double INIT_PH = 7.0; // Initial pH
	const double I_PHEN_TEMP = 0.1; // Influence factor from phenomenon to state
	const double I_CTRL_TEMP = 0.05; // Influence factor from controller to state
	const double I_PHEN_PH = 0.1; // Influence factor from phenomenon to state
	const double I_CTRL_PH = 0.2; // Influence factor from controller to state

	const int NB_TICKS = 192; // Duration of the simulation
	const string TIME_UNIT = "15 min";

	//const double CTRL_SAT = 24.0; // Saturation value of the controller

    const double CTRL_TMIN = 19.0;
    const double CTRL_TMAX = 20.0;
    const double CTRL_VMIN = 5.0;
    const double CTRL_VMAX = 50.0;

    const double CTRL_P_ORDER = 7.0;
    const double CTRL_P_GAIN = 2.0;

    const double RAND1_MU = 0.0;
    const double RAND1_SIGMA = 1.0;
    const double RAND2_MU = 0.0;
    const double RAND2_SIGMA = 1.0;

/*
	const double VAL_MIN = 20; // Minimum value of the phenomenon
	const double VAL_MAX = 30; // Maximum value of the phenomenon
*/
	const double VAL_SIN_OFFS = 16;
	const double VAL_SIN_AMPL = 3;
	const long int VAL_SIN_PHASE = 3;
    const long int VAL_SIN_PERIOD = 90;
	const double VAL_SIN_SAT_MIN = -50;
	const double VAL_SIN_SAT_MAX = 50;

	const double VAL_IMP_LOW =5;
	const double VAL_IMP_HIGH = 10;
	const long int VAL_IMP_DEL= 3;
	const long int VAL_IMP_RISE= 3;
	const long int VAL_IMP_WIDTH = 45;
	const long int VAL_IMP_FALL= 3;
	const long int VAL_IMP_PERIOD = 90;
    const double VAL_IMP_SAT_MIN = 14;
	const double VAL_IMP_SAT_MAX =0;

	cout << "-i-\tBuilding actors\n";

	// Create the  server
	Serveur serv("Serveur");

	// Declare actors
	Etat etat_temp("Etat temp",INIT_TEMP,I_PHEN_TEMP,I_CTRL_TEMP,&serv);
	Etat etat_ph("Etat temp",INIT_PH,I_PHEN_PH,I_CTRL_PH,&serv);

	//Phen_rand phenr("Phen random",&etat, &serv, VAL_MIN, VAL_MAX, RAND1_MU, RAND1_SIGMA);

	Phen_sin phen_temp("Phen temp",&etat_temp, &serv, VAL_SIN_OFFS, VAL_SIN_AMPL, VAL_SIN_PHASE,
                VAL_SIN_PERIOD, VAL_SIN_SAT_MIN, VAL_SIN_SAT_MAX, RAND1_MU, RAND1_SIGMA);

    Phen_imp phen_ph("Phen ph",&etat_ph, &serv, VAL_IMP_LOW, VAL_IMP_HIGH, VAL_IMP_DEL, VAL_IMP_RISE, VAL_IMP_WIDTH,
                   VAL_IMP_FALL, VAL_IMP_PERIOD, VAL_IMP_SAT_MIN, VAL_IMP_SAT_MAX, RAND2_MU, RAND2_SIGMA);


	//ContrSat ctrls("Ctrl Sat",&etat,&serv,CTRL_SAT);

	ContrOnOff ctrl_temp("Ctrl temp",&etat_temp,&serv,CTRL_TMIN, CTRL_TMAX, CTRL_VMIN, CTRL_VMAX);

    ContrP ctrl_ph("Ctrl ph",&etat_ph,&serv,CTRL_P_ORDER, CTRL_P_GAIN);

	cout << "-i-\tBuilding actors done\n";

	vector<Process*> elements;
	elements.push_back(&phen_temp);
	elements.push_back(&ctrl_temp);
	elements.push_back(&etat_temp);
	elements.push_back(&phen_ph);
	elements.push_back(&ctrl_ph);
	elements.push_back(&etat_ph);
	elements.push_back(&serv);

	// Run the simulation
	serv.log("\nStarting simulation\n");

	Simulator mySimulator(NB_TICKS, TIME_UNIT, &elements);
	mySimulator.simulate();
	serv.log("End simulation...\n");

	// Plot the output
	//serv.log("Use gnuplot to plot the output\n");
	system("gnuplot ../plot.sh");

	return 0;
}

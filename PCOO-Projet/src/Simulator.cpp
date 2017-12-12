/*
 * Simulator.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#include "Simulator.h"


Simulator::Simulator(int tick_nbr, string t) {
	sim_lenght=tick_nbr;
	time_unit = t;
	cout << "-i-\tSimulator created\n";
	cout << "\ttick max = " << sim_lenght << ", time_unit = " << time_unit << "\n";
}

Simulator::~Simulator() {
}

void Simulator::push_back(Process*p){
	processes.push_back(p);
	cout << "\tProcess '" << p->getName() << "' scheduled at position " << processes.size()-1 << "\n";
}

void Simulator::tick(){
	for(Process*p : processes){
		p->run();
	}
}

void Simulator::simulate(){
	cout << "-i-\tStarting simulation\n\t";
	for(int i=0; i<sim_lenght; i++){
		tick();
		cout << "|";
	}
	cout << "\n";
	cout << "-i-\tSimulation completed\n";
}

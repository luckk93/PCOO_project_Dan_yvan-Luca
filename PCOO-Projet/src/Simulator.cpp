/*
 * Simulator.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#include "Simulator.h"


Simulator::Simulator(int tick_nbr, string t, vector<Process*>* elements) {
    sim_lenght=tick_nbr;
    processes=elements;
    time_unit = t;
    cout << "-i-\tSimulator created\n";
    cout << "\ttick max = " << sim_lenght << ", time_unit = " << time_unit << "\n";
    int index = 0;
    for(Process*p : *processes){
    	cout << "\tProcess '" << p->getName() << "' scheduled at position " << index++ << "\n";
	}
}

Simulator::~Simulator() {
}

void Simulator::tick(){
	for(Process*p : *processes){
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

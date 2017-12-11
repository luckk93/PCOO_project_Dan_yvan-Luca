/*
 * Simulator.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#include "Simulator.h"


Simulator::Simulator(int tick_nbr, vector<Process*>* elements) {
    sim_lenght=tick_nbr;
    processes=elements;
}

Simulator::~Simulator() {
}

void Simulator::tick(){
	for(Process*p : *processes){
		p->run();
	}
}

void Simulator::simulate(){
	cout << "-i- Starting simulation\n"
	for(int i=0; i<sim_lenght; i++){
		tick();
		
	}
}

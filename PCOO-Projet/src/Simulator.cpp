/*
 * Simulator.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#include "Simulator.h"


Simulator::Simulator() {
}

Simulator::~Simulator() {
}

void Simulator::tick(){
	for(Process*p : processes){
		p->run();
	}
}

void Simulator::init(){
}

void Simulator::simulate(int tick_nbr){
	init();
	for(int i=0; i<tick_nbr; i++)
		tick();
}

void Simulator::init_process(std::vector<Process*>* elements){
	processes=*elements;
}

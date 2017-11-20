/*
 * Simulator.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: d01000100
 */

#include "Simulator.h"

Simulator::Simulator() {
	// TODO Auto-generated constructor stub

}

Simulator::~Simulator() {
	// TODO Auto-generated destructor stub
}

void Simulator::tick(){
	for(Process&p : processes){
		p.run();
		ticks++;
	}
}

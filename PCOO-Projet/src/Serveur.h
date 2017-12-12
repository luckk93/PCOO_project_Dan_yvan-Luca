/*
 * Serveur.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_SERVEUR_H_
#define SRC_SERVEUR_H_

#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Process.h"

using namespace std;

class Serveur: public Process {
public:
	Serveur(string);
	virtual ~Serveur();
	void store_phen(double v){buffer << std::setw(10)<< v << "\t";};
	void store_ctrl(double v){buffer << std::setw(10)<< v << "\t";};
	void store_etat(double v){buffer << std::setw(10)<< v << "\t";};
	void log(string);

	virtual void run();
private:
	ofstream data_storage;
	ofstream log_storage;
	double valPhen, valCtrl, valEtat;
	std::string str;
	std::ostringstream buffer;
	string wavePath = "waveforms.dat";
	string logPath = "journal.log";
	void write_data();
	int tick;
};

#endif /* SRC_SERVEUR_H_ */

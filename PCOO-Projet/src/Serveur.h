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
	void store_phen(double v){valPhen = v;};
	void store_ctrl(double v){valCtrl = v;};
	void store_etat(double v){valEtat = v;};
	void log(string);
	virtual void run();
	void init();
private:
	ofstream data_storage;
	ofstream log_storage;
	double valPhen, valCtrl, valEtat;
	string logPath;
	void write_data();
	int tick;
};

#endif /* SRC_SERVEUR_H_ */

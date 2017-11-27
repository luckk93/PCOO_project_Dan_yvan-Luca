/*
 * Serveur.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_SERVEUR_H_
#define SRC_SERVEUR_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Process.h"

class Serveur: public Process {
public:
	Serveur();
	virtual ~Serveur();
	void store_phen(double v){valPhen = v;};
	void store_ctrl(double v){valCtrl = v;};
	void store_etat(double v){valEtat = v;};
	void log(std::string);
	virtual void run();
	virtual void init();
private:
	double valPhen, valCtrl, valEtat;
	std::string logPath;
	void write_data();
	int tick;
};

#endif /* SRC_SERVEUR_H_ */

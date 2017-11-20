/*
 * Serveur.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_SERVEUR_H_
#define SRC_SERVEUR_H_
#include <iostream>
#include <fstream>

class Serveur {
public:
	Serveur();
	virtual ~Serveur();
	void store_phen(double v){valPhen = v;};
	void store_ctrl(double v){valCtrl = v;};
	void store_etat(double v){valEtat = v;};
	void run();
private:
    double valPhen, valCtrl, valEtat;
    void write_data();
};

#endif /* SRC_SERVEUR_H_ */

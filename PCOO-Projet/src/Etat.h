/*
 * Etat.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_ETAT_H_
#define SRC_ETAT_H_

class Etat {
public:
	Etat();
	virtual ~Etat();
	void init_valEtat(double v){etat_courant=v;};
	void init_factor(double q1, double q2){I_phen=q1; I_ctrl=q2;};
	void store_phen(double v){val_phen = v;};
	void store_ctrl(double v){val_ctrl = v;};
	double get_valPhen(){return val_phen;};
	double get_etatCourant(){return etat_courant;};
	void run();
private:
	double etat_effectif;
	double etat_courant;
	double I_phen;
	double I_ctrl;
	double val_phen;
	double val_ctrl;
	void calcule();
};

#endif /* SRC_ETAT_H_ */

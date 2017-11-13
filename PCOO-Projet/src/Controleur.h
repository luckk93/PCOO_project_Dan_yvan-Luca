/*
 * Controleur.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_CONTROLEUR_H_
#define SRC_CONTROLEUR_H_

class Controleur {
public:
	Controleur(Etat*,Serveur*);
	virtual ~Controleur();
	void run();
private:
	Serveur*serveur;
	Etat*etat;
};

#endif /* SRC_CONTROLEUR_H_ */

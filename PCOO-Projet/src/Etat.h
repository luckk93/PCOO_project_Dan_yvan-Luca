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
	void store(double);
private:
	double temperature;
};

#endif /* SRC_ETAT_H_ */

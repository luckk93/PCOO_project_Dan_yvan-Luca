/*
 * Phenimp.h
 *
 *  Created on: Dec 4, 2017
 *      Author: d01000100
 */

#ifndef SRC_PHENIMP_H_
#define SRC_PHENIMP_H_

class Phen_imp {
public:
	Phen_imp();
	virtual ~Phen_imp();
private:
	double generate();
	double v_low =0;
	double v_high = 10;
	long int t_del= 3;
	long int t_rise= 3;
	long int pwidth = 5;
	long int t_fall= 3;
	long int period = 13;
};

#endif /* SRC_PHENIMP_H_ */

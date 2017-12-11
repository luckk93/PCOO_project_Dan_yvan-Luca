/*
 * Serveur.h
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#ifndef SRC_LOGCALL_H_
#define SRC_LOGCALL_H_

#include <string>
#include "Serveur.h"

extern Serveur*serveurcall;

void initlogcall(Serveur*s);
void log(std::string str);

#endif /* SRC_LOGCALL_H_ */

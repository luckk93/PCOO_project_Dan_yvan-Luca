/*
 * Serveur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "logcall.h"

using namespace std;

Serveur*serveurcall;


void initlogcall(Serveur*s){
    serveurcall = s;
    }
void log(std::string str){
    serveurcall->log(str);
    }

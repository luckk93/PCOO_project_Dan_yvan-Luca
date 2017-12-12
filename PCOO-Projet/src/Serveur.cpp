/*
 * Serveur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Serveur.h"

Serveur::Serveur(string n){
	name = n;
	tick = 0;



	log_storage.open(logPath, ios::out | ios::trunc | ios::binary);

	auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    logstring.str("");
	logstring.clear();
	logstring << "[" <<name << "] Creation on " << std::put_time(&tm, "%d-%m-%Y %H:%M:%S") << endl;
	log(logstring.str());

	logstring.str("");
	logstring.clear();
	logstring << "[" <<name << "]  Log file " << logPath<< " created" << endl;
	log(logstring.str());

    data_storage.open(wavePath, ios::out | ios::trunc | ios::binary);
	data_storage << "#"<< setw(5) << "Tick" << "\t" <<  setw(10) << "valPhen1" << "\t" <<  setw(10) << "valEtat1" << "\t"
                <<  setw(10) << "valCtrl1" << "\t" <<  setw(10) << "valPhen2" << "\t" <<  setw(10) << "valEtat2" << "\t"
                <<  setw(10) << "valCtrl2" << endl;

    logstring.str("");
	logstring.clear();
    logstring << "[" <<name << "]  Data file " << wavePath<< " created" << endl;
	log(logstring.str());
}

Serveur::~Serveur() {
	data_storage.close();
	log_storage.close();
}

void Serveur::run(){
	write_data();
	tick++;
}

void Serveur::write_data(){

    logstring.str("");
	logstring.clear();
    logstring << "[" <<name << "]\ttick = " << tick << ", Contenent of buffer: " << buffer.str() << endl;
    data_storage << setw(6)<< tick << "\t" << buffer.str() << endl;
    log(logstring.str());
    buffer.str("");
    buffer.clear();

}

void Serveur::log(string s){

	log_storage << s;

}

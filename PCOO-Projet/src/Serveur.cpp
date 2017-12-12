/*
 * Serveur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Serveur.h"

using namespace std;

Serveur::Serveur(){
	tick = 0;

	data_storage.open("waveforms.dat", ios::out | ios::trunc | ios::binary);
	data_storage << "#"<< setw(5) << "Tick" << "\t" <<  setw(10) << "valPhen1" << "\t" <<  setw(10) << "valEtat1" << "\t"
                <<  setw(10) << "valCtrl1" << "\t" <<  setw(10) << "valPhen2" << "\t" <<  setw(10) << "valEtat2" << "\t"
                <<  setw(10) << "valCtrl2" << endl;

	log_storage.open("journal.log", ios::out | ios::trunc | ios::binary);
	this->log("Server initialized...\n");
}

Serveur::~Serveur() {
	data_storage.close();
	log_storage.close();
}

void Serveur::run(){
	this->log("Server running...\n");
	write_data();
	tick++;
}

void Serveur::write_data(){
	//cout << left <<  "Tick: "  << setw(5) << tick << "\t" ;
	//cout << left <<  "Phen: "  << setw(5) << valPhen << "\t" ;
	//cout << left <<  "Etat: "  << setw(5) << valEtat << "\t" ;
	//cout << left <<  "Ctrl: "  << setw(5) << valCtrl << endl ;

    data_storage << setw(6)<< tick << "\t" << buffer.str() << endl;
    log_storage << "Contenent of buffer: " << buffer.str() << endl;
    buffer.str("");
    buffer.clear();

}

void Serveur::log(string s){

	log_storage << s;

}

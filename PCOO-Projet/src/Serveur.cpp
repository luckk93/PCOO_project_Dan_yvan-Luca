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
	// initlogcall(this);
	// ofstream data_storage;
	// data_storage.open("waveforms.dat", ios::out | ios::trunc | ios::binary);
	// data_storage.close();

	data_storage.open("waveforms.dat", ios::out | ios::trunc | ios::binary);
	data_storage << "valPhen" << "\t" << "valEtat" << "\t" <<"valCtrl" << endl;
	// data_storage.close();

	// ofstream log_storage;
	log_storage.open("journal.log", ios::out | ios::trunc | ios::binary);
	// log_storage.close();
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
	cout << left <<  "Tick: "  << setw(5) << tick << "\t" ;
	cout << left <<  "Phen: "  << setw(5) << valPhen << "\t" ;
	cout << left <<  "Etat: "  << setw(5) << valEtat << "\t" ;
	cout << left <<  "Ctrl: "  << setw(5) << valCtrl << endl ;

	// ofstream data_storage;
	// data_storage.open("waveforms.dat", ios::out | ios::app | ios::binary);
	data_storage << valPhen << "\t" << valEtat << "\t" <<valCtrl << endl;
	// data_storage.flush();
	// data_storage.close();

	// ofstream log_storage;
	// log_storage.open("journal.log", ios::out | ios::app | ios::binary);
	log_storage << "Tick: " << tick << "\t" ;
	log_storage << "Phen: " << valPhen << "\t" ;
	log_storage << "Etat: " << valEtat << "\t" ;
	log_storage << "Ctrl: " << valCtrl << endl ;
	// log_storage.flush();
	// log_storage.close();
}

void Serveur::log(string s){
	// ofstream log_storage;
	// log_storage.open("journal.log", ios::out | ios::app | ios::binary);
	log_storage << s;
	// log_storage.close();
	cout << s;
}

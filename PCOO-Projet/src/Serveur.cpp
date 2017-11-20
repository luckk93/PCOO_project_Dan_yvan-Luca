/*
 * Serveur.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: d01000100
 */

#include "Serveur.h"

using namespace std;

Serveur::Serveur() {
	// TODO Auto-generated constructor stub

}

Serveur::~Serveur() {
	// TODO Auto-generated destructor stub
}

void Serveur::run(){
		write_data();
}

void Serveur::write_data(){
	cout << "Phen: " << valPhen << "\t" ;
	cout << "Etat: " << valEtat << "\t" ;
	cout << "Ctrl: " << valCtrl << endl ;

	ofstream data_storage;
	data_storage.open("PCOO_data.txt", ios::out | ios::app | ios::binary);
	data_storage << valPhen << "\t" << valEtat << "\t" <<valCtrl << endl;
	data_storage.close();
}

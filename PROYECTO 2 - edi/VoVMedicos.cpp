/*
 * VoVMedicos.cpp
 *
 *  Created on: 2 mar. 2023
 *      Author: alumno
 */

#include "VoVMedicos.h"

VoVMedicos::VoVMedicos() {
	this -> ocupadas = 0;

}

VoVMedicos::~VoVMedicos() {
	cout << "Iniciando destructor..." <<endl;
}

void VoVMedicos::insertar (Medico *m) {
	if (this->ocupadas < MAXMEDICOS) {
		this -> medicos [this->ocupadas] = m;
		this -> ocupadas++;
	}
}

void VoVMedicos::borrar (int pos) {
	if (pos < this->ocupadas && pos >= 0) {
		this -> medicos[pos] = this -> medicos [ocupadas - 1];
		this -> ocupadas--;
	}
}

Medico* VoVMedicos::getPosicion(int pos) {
	Medico *m = NULL;
	if (pos < this -> ocupadas && pos >= 0) {
		m = this -> medicos [pos];
	}
	return m;
}


int VoVMedicos::getOcupadas () {
	return this-> ocupadas;
}

bool VoVMedicos::estaVacio () {
	return (this-> ocupadas == 0);
}

bool VoVMedicos::estaLleno () {
	return (this-> ocupadas == MAXMEDICOS);
}



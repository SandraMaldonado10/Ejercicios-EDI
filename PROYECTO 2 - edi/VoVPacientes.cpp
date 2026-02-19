/*
 * VoVPacientes.cpp
 *
 *  Created on: 2 mar. 2023
 *      Author: alumno
 */

#include "VoVPacientes.h"

VoVPacientes::VoVPacientes() {
	this -> ocupadas = 0;

}

VoVPacientes::~VoVPacientes() {
	cout << "Iniciando destructor..." <<endl;
}

void VoVPacientes::insertar (Paciente *p) {
	if (this->ocupadas < MAXPACIENTES) {
		this -> pacientes [this->ocupadas] = p;
		this -> ocupadas++;
	}
}

void VoVPacientes::borrar (int pos) {
	if (pos < this->ocupadas && pos >= 0) {
		this -> pacientes[pos] = this -> pacientes [ocupadas - 1];
		this -> ocupadas--;
	}
}

Paciente* VoVPacientes::getPosicion(int pos) {
	Paciente *p = NULL;
	if (pos < this -> ocupadas && pos >= 0) {
		p = this -> pacientes [pos];
	}
	return p;
}


int VoVPacientes::getOcupadas () {
	return this-> ocupadas;
}

bool VoVPacientes::estaVacio () {
	return (this-> ocupadas == 0);
}

bool VoVPacientes::estaLleno () {
	return (this-> ocupadas == MAXPACIENTES);
}


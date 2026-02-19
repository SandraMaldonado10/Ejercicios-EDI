/*
 * VoVConsultas.cpp
 *
 *  Created on: 19 feb. 2023
 *      Author: alumno
 */

#include "VoVConsultas.h"

VoVConsultas::VoVConsultas() {  //constructor por defecto
	this-> ocupadas = 0;
}

VoVConsultas::~VoVConsultas() {
}

void VoVConsultas::insertar (Consulta *c) {  //consiste en copiar el puntero c en la primera posición libre
	if (this->ocupadas < MAXCONSULTAS) {
		this -> consultas [ocupadas] = c;  // no es necesario indicarlo con el this, pero prefiero ponerlo para indicar rapidamente que es un atributo de la clase
		this -> ocupadas++;
	}
	consultas [ocupadas] = c;
	ocupadas++;
}

void VoVConsultas::borrar (int pos) {  //se copia el que quiero borrar y lo pongo en vector 1
	if (pos < this->ocupadas && pos >= 0) {
		for (int i = pos; i<this->ocupadas; i++) {
			this -> consultas[i] = this->consultas [i+1];
		}
		this->ocupadas--;
	}
}


int VoVConsultas::getOcupadas () {
	return this-> ocupadas;
}

Consulta* VoVConsultas::getPosicion(int pos) {
	Consulta *c = NULL;
	if (pos < this->ocupadas && pos >= 0) {
		return this -> consultas [pos];
	}
	return c;
}


bool VoVConsultas::estaVacio () {
	return (this-> ocupadas == 0);
}

bool VoVConsultas::estaLleno () {
	return (this-> ocupadas == MAXCONSULTAS);
}


void VoVConsultas::insertarEnOrden (Consulta*&c) {  //el criterio de ordenación hemos elegido por la fecha
	//buscar una posicion para el nuevo elemento
	if ( this->ocupadas < MAXCONSULTAS) {
		bool encontrado = false;
		int pos = 0;
		int i;
		for (i=0; (i < this -> ocupadas) && !encontrado; i++)  {
			if (this-> consultas [i] -> getFechaYHora() > c -> getFechaYHora ()) {
				encontrado = true;
			}
		}
		pos = i;
		//abrir hueco en pos para el nuevo elemento
		for (i=this->ocupadas; i>pos; i++) {
			this -> consultas [i] = this -> consultas [i-1];
		}
		//insertar elelemento en pos
		this -> consultas[pos] = c;
		this -> ocupadas++;
	}
}


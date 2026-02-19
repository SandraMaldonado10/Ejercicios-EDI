/*
 * Consulta.cpp
 *
 *  Created on: 13 feb. 2023
 *      Author: alumno
 */

#include "Consulta.h"

Consulta::Consulta () { // constructor por defecto
	this -> p = NULL;
	this -> m = NULL;
	this -> fyh.setFechaYHora (2, 1, 6, 2, 3);
	this -> alta = false;
	this -> TipoConsulta = Pendiente;
	this -> informe = " ";
}

Consulta::Consulta(Paciente *p) {  //constructor parametrizado 1
	this -> p = p;
	this -> m = NULL;
	this -> fyh.setFechaYHora (2, 1, 6, 2, 3);
	this -> alta = false;
	this -> TipoConsulta = Pendiente;
	this -> informe = " ";
}

Consulta::Consulta(Paciente *p, Medico *m) { //constructor parametrizado 2
	this -> p = p;
	this -> m = m;
	this -> fyh.setFechaYHora (2, 1, 6, 2, 3);
	this -> alta = false;
	this -> TipoConsulta = Pendiente;
	this -> informe = " ";
}

Consulta::Consulta(Paciente *p, Medico *m, FechaYHora fyh, Tipo TipoConsulta) { //constructor parametrizado 3
	this -> p = p;
	this -> m = m;
	this -> fyh = fyh;
	this -> alta = false;
	this -> TipoConsulta = TipoConsulta;
	this -> informe = " ";
}

void Consulta::darDeAlta() {
	this -> alta = true;
}

void Consulta::adjuntarInforme(string informe) {
	this -> informe = this -> informe + informe;  // ó this->informe += informe
}

void Consulta::asignarMedico(Medico *m) {
	this -> m = m;
}

void Consulta::agendarFecha(FechaYHora f) {
	this -> fyh = f;
}

void Consulta::mostrar () {
	cout << "Mostrar consulta:..." <<endl;
	p -> mostrar ();
	m -> mostrar ();
	cout << "Fecha y hora de la consulta: ";
	fyh.mostrar ();
	if (this -> alta) {
		cout << "Alta: sí" <<endl;
	}
	else {
		cout << "Alta:no" <<endl;
	}
	cout << "Mostrar informe:..." <<this -> informe <<endl;
	cout << "Mostrar tipo de consulta:..." <<this-> TipoConsulta <<endl;
}

Consulta::~Consulta() {
	cout << "Iniciando destructor...:" << endl;
}

//  GETTERS:

FechaYHora Consulta::getFechaYHora() {
	return this -> fyh;
}

Medico* Consulta::getMedico() {
	return this -> m;
}

Paciente* Consulta::getPaciente() {
	return this -> p;
}

Tipo Consulta::getTipoConsulta() const {
	return TipoConsulta;
}

const string& Consulta::getInforme() const {
	return informe;
}
bool Consulta::getAlta() {
	return this -> alta;
}

//  SETTERS:

void Consulta::setInforme(const string &informe) {
	this->informe = informe;
}

void Consulta::setAlta(bool alta) {
	this->alta = alta;
}

void Consulta::setTipoConsulta (Tipo TipoConsulta) {
	this->TipoConsulta = TipoConsulta;
}



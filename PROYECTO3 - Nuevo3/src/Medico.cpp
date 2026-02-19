/*
 * médico.cpp
 *
 *  Created on: 12 feb. 2023
 *      Author: alumno
 */

#include "Medico.h"

Medico::Medico() {
	this -> nombre = "Sin asignar";
	this -> apellidosMedico = "Sin asignar";
	this -> especialidad = "Sin asignar";
}

Medico::Medico(string nombre,string apellidos, string especialidad) {
	cout << "Constructor parametrizado" <<endl;
	this -> nombre = nombre;
	this -> apellidosMedico = apellidosMedico;
	this -> especialidad = especialidad;
}
Medico::Medico(const Medico &m) {
	cout << "Constructor por copia" <<endl;
	this -> nombre = m.nombre;
	this -> apellidosMedico = m.apellidosMedico;
	this -> especialidad = m.especialidad;
}

Medico::~Medico() {
	cout << "destructor" <<endl;
}

void Medico::mostrar() {
	cout << "Nombre: " << this->nombre <<endl;
	cout << "Apellidos: " << this->apellidosMedico <<endl;
	cout << "Especialidad: " << this->especialidad <<endl;
}

//GETTERS

string Medico::getNombre ()const {
	return nombre;
}
string Medico::getApellidosMedico ()const {
	return apellidosMedico;
}
string Medico::getEspecialidad ()const {
	return especialidad;
}

//SETTERS

void Medico::setNombre (string nombre) {
	this->nombre = nombre;
}
void Medico::setApellidosMedico (string apellidosMedico) {
	this->apellidosMedico = apellidosMedico;
}
void Medico::setEspecialidad (string especialidad) {
	this->especialidad = especialidad;
}

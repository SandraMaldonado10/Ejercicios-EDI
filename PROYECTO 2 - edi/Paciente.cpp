/*
 * paciente.cpp
 *
 *  Created on: 6 feb. 2023
 *      Author: alumno
 */

#include "Paciente.h"

Paciente::Paciente() {  // constructor por defecto
	nombre = "No asignado";
	apellidos = "No asignado";
	DNI = "No asignado";
	edad = 0;
	genero = NoDefinido;
	pilaInf = new PilaInformes();
}

Paciente::Paciente(string nombre, string apellidos, string DNI, int edad, TipoGenero genero) { //constructor parametrizado
	this->nombre = nombre;  //el this indica que nombre es un atributo. Aunque no sea necesario,es mejor poner siempre el this
	this->apellidos = apellidos;
	this->DNI = DNI;
	this->genero = NoDefinido;
	this->edad = edad;
	this->pilaInf = new PilaInformes();
}

Paciente::Paciente(string nombre, string DNI) {  //constructor parametrizado
	this -> nombre = nombre;
	this -> DNI = DNI;
	this -> apellidos = "No asignado";
	this -> edad = -1;
	this -> genero = NoDefinido;
	this -> pilaInf = new PilaInformes();
}


Paciente::Paciente(const Paciente &p) { //constructor por copia
	this -> nombre = p.nombre;
	this -> apellidos = p.apellidos;
	this -> DNI = p.DNI;
	this -> genero = p.genero;
	this -> edad = p.edad;
	this -> pilaInf = p.pilaInf;
}

void Paciente::insertarInforme(Informe* in) {
	this->pilaInf->insertarInforme(in);
}

void Paciente::mostrar () {
	cout << this->nombre << " " << this->apellidos << " " << this->DNI << " " << this->edad << "años " << endl;
	if (this->genero == Hombre) {
		cout << "hombre" << endl;
	}
	if (this->genero == Mujer) {
		cout << "mujer" << endl;
	}
	if (this->genero == NoDefinido) {
		cout << "no definido" << endl;
	}
}

void Paciente::mostrarInformes() {
	this->pilaInf->mostrarInformesTotales();
}

Paciente::~Paciente() {  //destructor
	Informe* in;
	
	while (!this->pilaInf->estaVacia()) {
		this->pilaInf->consultarInforme(in);
		this->pilaInf->borrarInformesMedico(apellidos);
		delete in;
	}
	delete this->pilaInf;
}

//GETTERS

const string& Paciente::getApellidos() const {
	return apellidos;
}
const string& Paciente::getDni() const {
	return DNI;
}
int Paciente::getEdad() const {
	return edad;
}
TipoGenero Paciente::getGenero() const {
	return genero;
}
const string& Paciente::getNombre() const {
	return nombre;
}

//SETTERS

void Paciente::setApellidos(const string &apellidos) {
	this->apellidos = apellidos;
}
void Paciente::setDni(const string &dni) {
	DNI = dni;
}
void Paciente::setEdad(int edad) {
	this->edad = edad;
}
void Paciente::setGenero(TipoGenero genero) {
	this->genero = genero;
}
void Paciente::setNombre(const string &nombre) {
	this->nombre = nombre;
}

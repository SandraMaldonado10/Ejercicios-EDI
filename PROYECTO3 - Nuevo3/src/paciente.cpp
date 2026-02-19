/*
 * paciente.cpp
 *
 *  Created on: 6 feb. 2023
 *      Author: alumno
 */

#include "paciente.h"

Paciente::Paciente() {  // constructor por defecto
	nombre = "No asignado";
	apellidos = "No asignado";
	DNI = "No asignado";
	edad = -1;
	genero = NoDefinido;
	puntuacion = 0;
	pilaInformes = new PilaInformes();
}

Paciente::Paciente(string nombre, string apellidos, string DNI, int edad, TipoGenero genero) { //constructor parametrizado
	this->nombre = nombre;  //el this indica que nombre es un atributo. Aunque no sea necesario,es mejor poner siempre el this
	this->apellidos = apellidos;
	this->DNI = DNI;
	this->genero = NoDefinido;
	this->edad = edad;
	this->puntuacion = puntuacion;
	this->pilaInformes = new PilaInformes();
}

Paciente::Paciente(string nombre, string DNI) {  //constructor parametrizado
	this->nombre = nombre;
	this->DNI = DNI;
	this->apellidos = "No asignado";
	this->edad = -1;
	this->genero = NoDefinido;
	this->puntuacion = puntuacion;
	this->pilaInformes = new PilaInformes();
}


Paciente::Paciente(const Paciente& p) { //constructor por copia
	this->nombre = p.nombre;
	this->apellidos = p.apellidos;
	this->DNI = p.DNI;
	this->genero = p.genero;
	this->edad = p.edad;
	this->puntuacion = p.puntuacion;
	this->pilaInformes = p.pilaInformes;
}

void Paciente::insertarInforme(Informe* in) {
	this->pilaInformes->insertarInforme(in);
}

void Paciente::mostrarPuntuacion() {
	cout << nombre << " " << apellidos << ": " << DNI<< " [" << genero << "] *" << puntuacion << "*" <<endl;

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
	this->pilaInformes->mostrarInformesTotales();
}

Paciente::~Paciente() {  //destructor
	Informe *inf;
	while(!this->pilaInformes->estaVacia()){
		this->pilaInformes->consultarInforme(inf);
		this->pilaInformes->borrarPrimerInf();
		delete inf;
	}
	delete this->pilaInformes;
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
int Paciente::getPuntuacion() const {
	return puntuacion;
}
const string& Paciente::getNombre() const {
	return nombre;
}

//SETTERS

void Paciente::setApellidos(const string& apellidos) {
	this->apellidos = apellidos;
}
void Paciente::setDni(const string& dni) {
	this->DNI = dni;
}
void Paciente::setEdad(int edad) {
	this->edad = edad;
}
void Paciente::setGenero(TipoGenero genero) {
	this->genero = genero;
}
void Paciente::setPuntuacion(int puntuacion) {
	this->puntuacion = puntuacion + this->puntuacion;
}
void Paciente::setNombre(const string& nombre) {
	this->nombre = nombre;
}



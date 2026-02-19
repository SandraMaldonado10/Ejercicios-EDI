/*
 * PruebasVoVPacientes.cpp
 *
 *  Created on: 8 mar. 2023
 *      Author: alumno
 */

#include "PruebasVOVPacientes.h"

void probarConstructorPorDefectoP () {
	cout << "Comienzan las pruebas del constructor por defecto" <<endl;
	VoVPacientes* vovP1 = nullptr;
	if (vovP1->getOcupadas() != 0)
		cerr << "Error porque un vector recién creado debe tener ocupadas = 0" <<endl;
	cout << "Finalizan las pruebas del constructor por defecto" <<endl;
}

void probarInsertarP () {
	cout << "Comienzan las pruebas del módulo insertar" <<endl;

	VoVPacientes* vovP2 = nullptr;
	Paciente *p1 = new Paciente ("Mario", "Muñoz Torrero", "75227276C", 20, Hombre);
	vovP2->insertar(p1);
	if (vovP2->getOcupadas() != 1) {
		cout << "Error porque al insertar un paciente, las ocupadas tienen que ser 1" <<endl;
	}

	Paciente *p2 = new Paciente ("Sandra", "5906620C");
	vovP2->insertar (p2);
	if (vovP2->getOcupadas() != 1) {
		cout << "Error porque al insertar un paciente, las ocupadas tienen que ser 1" <<endl;
	}


	cout << "Finalizan las pruebas del módulo insertar" <<endl;
}

void probarBorrarP () {
	cout << "Comienzan las pruebas del módulo borrar" <<endl;

	VoVPacientes* vovP3 = nullptr;
	Paciente *p1 = new Paciente ("Antonia", "5906620C");
	Paciente *p2 = new Paciente ("Francisco", "18074883C");

	p1 = vovP3->getPosicion(2);
	vovP3->borrar (2);
	if (vovP3->getOcupadas() != 1) {
		cout << "Error al borrar el paciente" <<endl;
	}
	delete p1;

	p2 = vovP3->getPosicion(1);
	vovP3->borrar (1);
	if (vovP3->getOcupadas() != 0) {
		cout << "Error al borrar el paciente" <<endl;
	}
	delete p2;

	if (!vovP3->estaVacio()) {
		cout << "Error ya que un vector en el que se borran todos los elementos, debería estar vacío" <<endl;
	}

	cout << "Finalizan las pruebas del módulo borrar" <<endl;

}

void probarEstaLlenoP () {

	cout << "Comienzan las pruebas del módulo estaLleno" <<endl;
	VoVPacientes* vovP4 = nullptr;
	int i;

	if (vovP4->estaLleno() != false) {
		cout << "Error porque al crear un nuevo vector, este debe estar vacío inicialmente" <<endl;
	}

	for (i = 0; i < MAXPACIENTES; i++) {
		Paciente *p1 = new Paciente ("Paciente"+i, "DNI"+i);
		vovP4->insertar(p1);
	}
	for (i = 0; i < MAXPACIENTES/2; i++) {
		vovP4->borrar(i);
	}

	if (vovP4->estaLleno() != false) {
		cout << "Error porque al borrar algunos pacientes, la lista está llena" <<endl;
	}

	cout << "Finalizan las pruebas del módulo estaLleno" <<endl;
}


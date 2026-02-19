/*
 * PruebasVoVMedicos.cpp
 *
 *  Created on: 10 mar. 2023
 *      Author: alumno
 */

#include "PruebasVoVMedicos.h"

void probarConstructorPorDefectoM () {
	cout << "Comienzan las pruebas del constructor por defecto" <<endl;
	VoVMedicos *vovM1;
	if (vovM1->getOcupadas() != 0)
		cerr << "Error porque un vector recién creado debe tener ocupadas = 0" <<endl;
	cout << "Finalizan las pruebas del constructor por defecto" <<endl;
}

void probarInsertarM () {
	cout << "Comienzan las pruebas del módulo insertar" <<endl;

	VoVMedicos *vovM2;
	Medico *m1 = new Medico ("Juan Antonio", "Marín Bueno", "Tuerce tripas");
	vovM2->insertar(m1);
	if (vovM2->getOcupadas() != 1) {
		cout << "Error porque al insertar un médico, las ocupadas tienen que ser 1" <<endl;
	}

	Medico *m2 = new Medico ("Anglicista", "Fragoso", "Cirugía de cegañutos");
	vovM2->insertar (m2);
	if (vovM2->getOcupadas() != 1) {
		cout << "Error porque al insertar un médico, las ocupadas tienen que ser 1" <<endl;
	}

	cout << "Finalizan las pruebas del módulo insertar" <<endl;
}

void probarBorrarM () {
	cout << "Comienzan las pruebas del módulo borrar" <<endl;

	VoVMedicos *vovM3;
	Medico *m1 = new Medico ("Piluca", "Galeana", "Endereza huesos");
	Medico *m2 = new Medico ("Alfonso", "Díaz", "Pediatra");

	m1 = vovM3->getPosicion(2);
	vovM3->borrar (2);
	if (vovM3->getOcupadas() != 1) {
		cout << "Error al borrar el médico" <<endl;
	}
	delete m1;

	m2 = vovM3->getPosicion(1);
	vovM3->borrar (1);
	if (vovM3->getOcupadas() != 0) {
		cout << "Error al borrar el médico" <<endl;
	}
	delete m2;

	if (!vovM3->estaVacio()) {
		cout << "Error ya que un vector en el que se borran todos los elementos, debería estar vacío" <<endl;
	}

	cout << "Finalizan las pruebas del módulo borrar" <<endl;

}

void probarEstaLlenoM () {

	cout << "Comienzan las pruebas del módulo estaLleno" <<endl;
	VoVMedicos *vovM4;
	int i;

	if (vovM4->estaLleno() != false) {
		cout << "Error porque al crear un nuevo vector, este debe estar vacío inicialmente" <<endl;
	}

	for (i = 0; i < MAXMEDICOS; i++) {
		Medico *m1 = new Medico ("Nombre"+i, "Apellido"+i, "Especialidad"+i);
		vovM4->insertar(m1);
	}
	for (i = 0; i < MAXMEDICOS/2; i++) {
		vovM4->borrar(i);
	}

	if (vovM4->estaLleno() != false) {
		cout << "Error porque al borrar algunos pacientes, la lista está llena" <<endl;
	}

	cout << "Finalizan las pruebas del módulo estaLleno" <<endl;
}





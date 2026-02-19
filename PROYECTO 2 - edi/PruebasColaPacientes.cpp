/*
 * PruebasColaPacientes.h
 *
 *  Created on: 4 abr. 2023
 *      Author: alumno
 */

#include "PruebasColaPacientes.h"

void pruebasConstructorPorDefectoCP() {
	//  CASO 1:
	cout << "Comienzan las pruebas del constructor por defecto en ColaPacientes" << endl;
	ColaPacientes* cp1;
	if (!cp1->estaVacia()) 
		cerr << "Error al crear constructor por defecto" << endl;
	//  CASO 2:
	ColaPacientes* cp12;
	if (!cp12->estaVacia())
		cerr << "Error al crear constructor por defecto" << endl;
	cout << "Finalizan las pruebas del constructor por defecto en ColaPacientes" << endl;
}

void probarInsertarCP() {

	cout << "Comienzan las pruebas del módulo insertar en ColaPacientes" << endl;
	ColaPacientes* cp2;
	ColaPacientes* cp3;
	Paciente* p1 = new Paciente ("Álvaro", "92298807H");
	Paciente* p2 = new Paciente("Carlos", "18820302N");

	cp2->insertar(p1);
	cp3->insertar(p2);

	if (cp2->estaVacia()) {
		cout << "Error ya que al insertar p1, no debería de estar vacía la cola" << endl;
	}
	if (cp3->estaVacia()) {
		cout << "Error ya que al insertar p2, no debería de estar vacía la cola" << endl;
	}

	delete p1;
	delete p2;

	if (!cp2->estaVacia()) {
		cout << "Error ya que la cola debería de estar completamente vacía" << endl;
	}
	if (!cp3->estaVacia()) {
		cout << "Error ya que la cola debería de estar completamente vacía" << endl;
	}

	delete cp2;
	delete cp3;

	cout << "Finalizan las pruebas del módulo insertar en ColaPacientes" << endl;
}

void probarCuantosCP() {

	cout << "Comienzan las pruebas del módulo cuantos en ColaPacientes" << endl;
	// CASO 1:
	ColaPacientes* cp4;
	ColaPacientes* colaAux;
	Paciente* p3 = new Paciente("Estela", "40220037U");
	
	cp4->insertar(p3);
	cp4->cuantos();
	if (cp4->estaVacia()) {
		cout << "Error al insertar el paciente" << endl;
	}
	if (!colaAux->estaVacia()) {
		cout << "Error al eliminar la cola auxiliar, la cuál debe estar vacía ya que se pasaron todos los datos a la cola original y por ello se elimina la auxiliar" << endl;
	}

	delete cp4;
	delete p3;

	// CASO 2:
	ColaPacientes* cp5;

	cp5->cuantos();
	if (!cp5->estaVacia()) {
		cout << "Error al crear la cola por defecto" << endl;
	}
	delete cp5;
}

void probarObtenerCP() {
	
	cout << "Comienzan las pruebas del módulo obtener de ColaPacientes" << endl;
	// CASO 1:
	ColaPacientes* cp6;
	Paciente* p5 = new Paciente("Guillermo", "26101831C");

	cp6->obtener(p5);
	if (cp6->estaVacia()) {
		cout << "p5 ha sido correctamente obtenido" << endl;
	}
	else {
		cout << "Error al obtener el paciente, ya que debe ser eliminado" << endl;
	}
	delete cp6;
	// CASO 2:
	ColaPacientes* cp7;
	Paciente* p6 = new Paciente("Samuel", "96174459D");

	cp7->obtener(p6);
	if (cp7->estaVacia()) {
		cout << "p6 ha sido correctamente obtenido" << endl;
	}
	else {
		cout << "Error al obtener el paciente, ya que debe ser eliminado" << endl;
	}
	delete cp7;

	cout << "Finalizan las pruebas del módulo obtener de ColaPacientes" << endl;
}

void probarMostrarCP() {

	cout << "Comienzan las pruebas del módulo mostrar de ColaPacientes" << endl;
	
	// CASO 1:
	ColaPacientes* cp8;
	ColaPacientes* colaAux;
	Paciente* p7 = new Paciente("Estela", "40220037U");

	cp8->insertar(p7);
	cp8->mostrar();
	if (cp8->estaVacia()) {
		cout << "Error al mostrar el paciente" << endl;
	}
	if (!colaAux->estaVacia()) {
		cout << "Error al eliminar la cola auxiliar, la cuál debe estar vacía ya que se pasaron todos los datos a la cola original y por ello se elimina la auxiliar" << endl;
	}

	delete cp8;
	delete p7;

	// CASO 2:
	ColaPacientes* cp9;

	cp9->mostrar();
	if (!cp9->estaVacia()) {
		cout << "Error al mostrar la cola" << endl;
	}
	delete cp9;

	cout << "Finalizan las pruebas del módulo mostrar de ColaPacientes" << endl;
}

void probarDestructorCP() {
	ColaPacientes* cp10;
	delete cp10;

	if (!cp10->estaVacia()) {
		cout << "Error al destruir la cola cp10" << endl;
	}
}
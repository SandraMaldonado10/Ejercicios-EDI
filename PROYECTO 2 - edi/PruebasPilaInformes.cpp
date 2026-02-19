/*
 * PruebasColaPacientes.h
 *
 *  Created on: 4 abr. 2023
 *      Author: alumno
 */

#include "PruebasPilaInformes.h"

void pruebasConstructorPorDefectoPI() {
	
	cout << "Comienzan las pruebas del constructor por defecto en PilaInformes" << endl;
	//  CASO 1:
	PilaInformes* pi1;
	if (!pi1->estaVacia())
		cerr << "Error al crear el constructor por defecto" << endl;
	//  CASO 2:
	PilaInformes* pi2;
	if (!pi2->estaVacia())
		cerr << "Error al crear el constructor por defecto" << endl;
	cout << "Finalizan las pruebas del constructor por defecto en PilaInformes" << endl;
}

void probarInsertarPI() {

	cout << "Comienzan las pruebas del módulo insertar en PilaInformes" << endl;
	PilaInformes* pi3;
	PilaInformes* pi4;
	FechaYHora f1 (01,02,2022,10,00);
	FechaYHora f2(03, 06, 2023, 10, 45);
	Medico* m1 = new Medico("Pepe", "Muñoz", "Pediatra");
	Medico* m2 = new Medico("Alfonso", "Maldonado", "Traumatólogo");
	Informe* i1 = new Informe("Fractura tibia y peroné",f1, m1);
	Informe* i2 = new Informe("Rehabilitación 3 meses", f2, m2);

	pi3->insertarInforme(i1);
	pi4->insertarInforme(i2);

	if (pi3->estaVacia())
		cerr << "Error al insertar el informe i1" << endl;
	if (pi4->estaVacia())
		cerr << "Error al insertar el informe i2" << endl;

	delete i1;
	delete i2;

	if (!pi3->estaVacia())
		cerr << "Error al eliminar el informe de la cola" << endl;
	if (!pi4->estaVacia())
		cerr << "Error al aliminar el informe de la cola" << endl;

	delete pi3;
	delete pi4;

	cout << "Finalizan las pruebas del módulo insertar en PilaInformes" << endl;
}

void probarConsultarPI() {

	cout << "Comienzan las pruebas del módulo consultar en PilaInformes" << endl;
	//  CASO 1:
	PilaInformes* pi5;
	FechaYHora f1(01, 02, 2022, 10, 00);
	FechaYHora f2(03, 06, 2023, 10, 45);
	Medico* m1 = new Medico("Pepe", "Muñoz", "Pediatra");
	Medico* m2 = new Medico("Alfonso", "Maldonado", "Traumatólogo");
	Informe* i3 = new Informe("Paracetamol cada 8 horas, volver en 3 meses", f1, m1);

	pi5->insertarInforme(i3);
	pi5->consultarInforme();

	if (pi5->estaVacia())
		cerr << "Error al consultar la pila de informes, ya que hemos insertado un informe anteriormente" << endl;
	delete pi5;
	delete i3;

	//  CASO 2:
	PilaInformes* pi6;
	Informe* i4 = new Informe("Lesión de ligamento cruzado anterior", f2, m2);

	pi6->consultarInforme();

	if (!pi6->estaVacia())
		cerr << "Error al consultar la pila de informes, ya que no se insertó ningún informe" << endl;
	delete pi6;
	delete i4;

	cout << "Finalizan las pruebas del módulo consultar en PilaInfpormes" << endl;
}

void probarMostrarTotalesPI() {

	cout << "Comienzan las pruebas del módulo mostrar informes totales en PilaInformes" << endl;
	// CASO 1:
	PilaInformes* pi7;
	PilaInformes* pilaAux;
	FechaYHora f1(01, 02, 2022, 10, 00);
	FechaYHora f2(03, 06, 2023, 10, 45);
	Medico* m1 = new Medico("Pepe", "Muñoz", "Pediatra");
	Medico* m2 = new Medico("Alfonso", "Maldonado", "Traumatólogo");
	Informe* i5 = new Informe("Ciatica", f2, m1);

	pi7->insertarInforme(i5);
	pi7->mostrarInformesTotales();
	if (pi7->estaVacia()) {
		cout << "Error al mostrar los informes" << endl;
	}
	if (!pilaAux->estaVacia()) {
		cout << "Error al eliminar la pila auxiliar, la cuál debe estar vacía ya que se pasaron todos los datos a la pila original y por ello se elimina la auxiliar" << endl;
	}

	delete pi7;
	delete i5;

	// CASO 2:
	PilaInformes* pi8;

	pi8->mostrarInformesTotales();
	if (!pi8->estaVacia()) {
		cout << "Error al mostrar la la pila de informes" << endl;
	}
	delete pi8;

	cout << "Finalizan las pruebas del módulo mostrar informes totales en PilaInformes" << endl;
}

void probarMostrarInformesMedicoPI() {

	cout << "Comienzan las pruebas del módulo mostrar informes del médico en PilaInformes" << endl;
	// CASO 1:
	PilaInformes* pi9;
	PilaInformes* pilaAux;
	FechaYHora f1(01, 02, 2022, 10, 00);
	FechaYHora f2(03, 06, 2023, 10, 45);
	Medico* m1 = new Medico("Pepe", "Muñoz", "Pediatra");
	Medico* m2 = new Medico("Alfonso", "Maldonado", "Traumatólogo");
	Informe* i6 = new Informe("Reposo relativo durante 2 semanas", f2, m1);
	Medico* med = nullptr;
	string apellidos;

	apellidos = med->getApellidosMedico();
	pi9->insertarInforme(i6);
	pi9->mostrarInformesMedico(apellidos);
	if (pi9->estaVacia()) {
		cout << "Error al mostrar los informes del médico" << endl;
	}
	if (!pilaAux->estaVacia()) {
		cout << "Error al eliminar la pila auxiliar, la cuál debe estar vacía ya que se pasaron todos los datos a la pila original y por ello se elimina la auxiliar" << endl;
	}

	delete pi9;
	delete i6;

	// CASO 2:
	PilaInformes* pi10;

	pi10->mostrarInformesMedico(apellidos);
	if (!pi10->estaVacia()) {
		cout << "Error al mostrar los informes del médico" << endl;
	}
	delete pi10;
	delete m1;

	cout << "Finalizan las pruebas del módulo mostrar informes del médico en PilaInformes" << endl;
}

void probarBorrarInformesMedicoPI() {

	cout << "Comienzan las pruebas del módulo borrar los informes del médico en PilaInformes" << endl;
	//  CASO 1:
	PilaInformes* pi11;
	PilaInformes* pilaAux;
	FechaYHora f1(01, 02, 2022, 10, 00);
	FechaYHora f2(03, 06, 2023, 10, 45);
	Medico* m1 = new Medico("Pepe", "Muñoz", "Pediatra");
	Medico* m2 = new Medico("Alfonso", "Maldonado", "Traumatólogo");
	Informe* i7 = new Informe("Fractura tibia y peroné", f1, m2);
	Medico* med2;
	string apellidos;

	apellidos = med2->getApellidosMedico();
	pi11->insertarInforme(i7);
	pi11->borrarInformesMedico(apellidos);
	if (pi11->estaVacia()) {
		cout << "Error al borrar los informes del médico" << endl;
	}
	if (!pilaAux->estaVacia()) {
		cout << "Error al eliminar la pila auxiliar, la cuál debe estar vacía ya que se pasaron todos los datos a la pila original y por ello se elimina la auxiliar" << endl;
	}

	delete pi11;
	delete i7;

	// CASO 2:
	PilaInformes* pi12;

	pi12->borrarInformesMedico(apellidos);
	if (!pi12->estaVacia()) {
		cout << "Error al borrar los informes del médico" << endl;
	}
	delete pi12;
	delete m2;

	cout << "Finalizan las pruebas del módulo borrar los informes del médico en PilaInformes" << endl;
}

void probarBorrarPrimerInfPI() {

	cout << "Comienzan las pruebas del módulo borrar el primer informe" << endl;
	// CASO 1:
	PilaInformes* pi13;
	FechaYHora f1(01, 02, 2022, 10, 00);
	FechaYHora f2(03, 06, 2023, 10, 45);
	Medico* m1 = new Medico("Pepe", "Muñoz", "Pediatra");
	Medico* m2 = new Medico("Alfonso", "Maldonado", "Traumatólogo");
	Informe* i8 = new Informe("Inflamación tobillo izquierdo", f2, m1);
	Informe* i9 = new Informe("Lesión de slap tiempo de recuperación 2 meses", f2, m2);

	pi13->insertarInforme(i8);
	pi13->insertarInforme(i9);
	pi13->borrarPrimerInf();
	if (pi13->estaVacia()) {
		cout << "Error al borrar el primer informe" << endl;
	}
	pi13->borrarPrimerInf();
	if (!pi13->estaVacia()) {
		cout << "Error al borrar el primer informe" << endl;
	}

	delete pi13;
	delete i8;
	delete i9;

	//  CASO 2:
	PilaInformes* pi14;
	FechaYHora f1(01, 02, 2022, 10, 00);
	FechaYHora f2(03, 06, 2023, 10, 45);
	Medico* m1 = new Medico("Pepe", "Muñoz", "Pediatra");
	Medico* m2 = new Medico("Alfonso", "Maldonado", "Traumatólogo");
	Informe* i10 = new Informe("El paciente se queja de dolor intenso", f1, m1);
	Informe* i11 = new Informe("Fractura expuesta de fémur", f2, m2);

	pi14->insertarInforme(i10);
	pi14->insertarInforme(i11);
	pi14->borrarPrimerInf();
	if (pi14->estaVacia()) {
		cout << "Error al borrar el primer informe" << endl;
	}

	delete pi14;
	delete i10;
	delete i11;

	cout << "Finalizan las pruebas del módulo borrar el primer informe" << endl;
}

void probarDestructorPI() {
	PilaInformes* pi15;
	delete pi15;

	if (!pi15->estaVacia()) {
		cout << "Error al destruir la pila de informes pi15" << endl;
	}
}
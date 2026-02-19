/*
 * PruebasVoVConsultas.cpp
 *
 *  Created on: 8 mar. 2023
 *      Author: alumno
 */

#include "PruebasVoVConsultas.h"
#include "Consulta.h"

void probarConstructorPorDefectoC () {
	cout << "Comienzan las  pruebas del constructor por defecto" <<endl;
	VoVConsultas *vovC1;
	if (vovC1->getOcupadas() != 0)
		cerr << "Error porque un vector inicialmente creado debe tener ocupadas = 0" <<endl;
	cout << "Finalizan las pruebas del constructor por defecto" <<endl;
}

void probarInsertarOrdenYBorrarC () {
	cout << "Comienzan las pruebas de insertar en orden y borrado" <<endl;
	VoVConsultas *vovC2;

	Paciente *p1 = new Paciente ("Daniel", "335674F");
	Medico *m1 = new Medico ("Pedro", "Maldonado", "Pediatra");
	FechaYHora f1(12,04,2023,10,45);

	Paciente *p2 = new Paciente ("Hugo", "738390E");
	Medico *m2 = new Medico ("Teresa", "Picapiedra", "Nefróloga");
	FechaYHora f2(5,07,2023,13,00);

	Paciente *p3 = new Paciente ("María", "789446Y");
	Medico *m3 = new Medico ("Paco", "Fabián", "Dermatólogo");
	FechaYHora f3(2,03,2023,10,20);

	Consulta *c1 = new Consulta (p1, m1, f1, Externa);
	Consulta *c2 = new Consulta (p2, m2, f2, Urgente);
	Consulta *c3 = new Consulta (p3, m3, f3, Externa);

	vovC2->insertarEnOrden(c1);
	vovC2->insertarEnOrden (c2);
	vovC2->insertarEnOrden(c3);


	if (vovC2 -> getOcupadas() != 3) {
		cout << "Error porque se han insertado 3 consultas anteriormente" <<endl;
	}
	for (int i = 0; i < vovC2->getOcupadas(); i++) {
		vovC2 -> getPosicion(i)-> mostrar();
	}

	if (vovC2->estaVacio() != false) {
		cout << "Error porque el vector no debería de estar vacio" <<endl;
	}
	if (vovC2->estaLleno() != false) {
		cout << "Error porque el vector no debería de estar lleno" <<endl;
	}

	vovC2 -> borrar(0);
	vovC2 -> borrar(1);
	vovC2 -> borrar(2);

	if (vovC2 -> getOcupadas() != 0) {
		cout << "Error porque ya se borraron todas las consultas del vector" <<endl;
	}

	cout << "Finalizan las pruebas de insertar en orden y borrado" <<endl;
}






/*
 * PruebasColaPacientes.h
 *
 *  Created on: 4 abr. 2023
 *      Author: alumno
 */

#include "PruebasServicio.h"

void probarClaseServicio() {
	
	Medico* medico = new Medico("Juan", "Pérez", "Traumatología");

	Servicio* servicio = new Servicio("Traumatología");

	servicio->setMedico(medico);

	Paciente* paciente1 = new Paciente("Ana","12345678A");
	Paciente* paciente2 = new Paciente("Pedro","87654321B");
	Paciente* paciente3 = new Paciente("María","23456789C");

	servicio->insertar(0, paciente1);
	servicio->insertar(1, paciente2);
	servicio->insertar(2, paciente3);

	servicio->mostrar();

	servicio->mostrarCantidadesColas();

	servicio->procesarColas();

	paciente1->mostrarInformes();
	paciente2->mostrarInformes();
	paciente3->mostrarInformes();

	delete servicio;
	delete medico;
	delete paciente1;
	delete paciente2;
	delete paciente3;

}



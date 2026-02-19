/*
 * PruebasConsulta.cpp
 *
 *  Created on: 8 mar. 2023
 *      Author: alumno
 */

#include "PruebasCons.h"

void probarClaseConsulta() {

	cout << "Inicio de las pruebas de los constructores, getters y setters de la clase Consulta" << endl;

	cout << "Pruebas para constructor por defecto" << endl;

	Consulta c1;
	if (c1.getTipoConsulta() != Pendiente)
		cerr << "Error en el constructor por defecto" << endl;
	if (c1.getInforme() != " ")
		cerr << "Error en el constructor por defecto" << endl;

	cout << "Pruebas para constructor parametrizado" << endl;

	Paciente* p = new Paciente("Pepe", "93505624M");
	Medico* m = new Medico("Laura", "Diaz", "Medico cabecera");
	FechaYHora f;
	Consulta* c2 = new Consulta(p, m, f, Pendiente);
	if (c2->getPaciente() != p)
		cerr << "Error en el constructor parametrizado" << endl;
	if (c2->getFechaYHora() == f) {

	}
	else {
		cerr << "Error en el constructor parametrizado" << endl;
	}
	if (c2->getMedico() != m)
		cerr << "Error en el constructor parametrizado" << endl;

	cout << "Pruebas para los setters de clase Consulta" << endl;
	Consulta c3;
	c3.setInforme("Consulta realizada");
	if (c3.getInforme() != "Consulta realizada")
		cerr << "Error al modificar el informe de una consulta" << endl;
	c3.setAlta(true);
	if (c3.getAlta() != true)
		cerr << "Error al modificar el alta de una consulta" << endl;
	c3.setTipoConsulta(Externa);
	if (c3.getTipoConsulta() != Externa)
		cerr << "Error al modificar el informe de una consulta" << endl;

	cout << "Fin de las pruebas de los constructores, getters y setters de la clase Consulta" << endl;
}



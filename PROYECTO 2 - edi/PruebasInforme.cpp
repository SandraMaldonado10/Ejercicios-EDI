/*
 * PruebasColaPacientes.h
 *
 *  Created on: 4 abr. 2023
 *      Author: alumno
 */

#include "PruebasInforme.h"

void probarClaseInforme() {

	cout << "Comienzan las pruebas de los constructores, getters y setters de clase Informe" << endl;

	cout << "Pruebas para constructor por defecto" << endl;
	Informe *i1;
	if (i1->getTexto() != "Vacío")
		cerr << "Error en el constructor por defecto" << endl;
	if (i1->getMed() != nullptr) 
		cerr << "Error en el constructor por defecto" << endl;

	cout << "Pruebas del constructor parametrizado" << endl;
	Informe *i2 = new Informe("El paciente se queja de dolor intenso", "Salas");
	if (i2->getTexto() != "El paciente se queja de dolor intenso")
		cerr << "Error en el constructor parametrizado" << endl;
	if (i2->getMed() != "Salas")  // REVISAR EN REPLIT
		cerr << "Error en el constructor parametrizado" << endl;
	
	cout << "Pruebas para el constructor por copia" << endl;
	Informe* i4 = new Informe("Rehabilitación 3 meses", "Salas");
	Informe *i3 = i4;
	if (i3->getMed() != "Salas")
		cerr << "Error en el constructor por copia" << endl;
	if (i3->getTexto() != "Rehabilitación 3 meses")
		cerr << "Error en el constructor por copia" << endl;

	cout << "Pruebas para setters en clase Informe" << endl;
	i2->setMed("Galeana");
	if (i2->getMed() != "Galeana")
		cerr << "Error al cambiar el médico del informe" << endl;
	i2->setTexto("Lesión de ligamento cruzado anterior");
	if (i2->getTexto() != "Lesión de ligamento cruzado anterior")
		cerr << "Error al cambiar el médico del informe" << endl;
	i3->setTexto("Reposo relativo durante 2 semanas");
	if (i3->getTexto() != "Reposo relativo durante 2 semanas")
		cerr << "Error al cambiar el médico del informe" << endl;
	
	cout << "Finalizan las pruebas de los constructores, getters y setters de la clase Informe" << endl;
}
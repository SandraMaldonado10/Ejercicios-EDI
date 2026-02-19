/*
 * PruebasPaciente.cpp
 *
 *  Created on: 7 mar. 2023
 *      Author: alumno
 */

#include "PruebasPac.h"

void probarClasePaciente() {
	cout << "Inicio de las pruebas de los constructores, getters y setters de clase Paciente: " << endl;

	cout << "Pruebas para constructor por defecto" << endl;
	Paciente p1;
	if (p1.getNombre() != "No asignado")
		cerr << "Error en el constructor por defecto" << endl;
	if (p1.getApellidos() != "No asignado")
		cerr << "Error en el constructor por defecto" << endl;
	if (p1.getGenero() != NoDefinido)
		cerr << "Error en el constructor por defecto" << endl;

	cout << "Pruebas para constructor parametrizado" << endl;
	Paciente p2("Manuel", "Cerro Torres", "55257575H", 17, Hombre);
	if (p2.getNombre() != "Manuel")
		cerr << "Error en el constructor parametrizado" << endl;
	if (p2.getEdad() != 17)
		cerr << "Error en el constructor parametrizado" << endl;
	if (p2.getGenero() != Hombre)
		cerr << "Error en el constructor parametrizado" << endl;

	cout << "Pruebas para el constructor por copia" << endl;
	Paciente p3 = p2;
	if (p3.getApellidos() != "Cerro Torres")
		cerr << "Error en el constructor por copia" << endl;
	if (p3.getGenero() != Hombre)
		cerr << "Error en el constructor por copia" << endl;
	if (p3.getEdad() != 17)
		cerr << "Error en el constructor por copia" << endl;

	cout << "Pruebas para los Setters en clase Paciente" << endl;
	p2.setDni("21008792A");
	if (p2.getDni() != "21008792A")
		cerr << "Error al cambiar el dni del paciente" << endl;
	p3.setGenero(Mujer);
	if (p3.getGenero() != Mujer)
		cerr << "Error al cambiar el género del paciente" << endl;
	p2.setEdad(6);
	if (p2.getEdad() != 6)
		cerr << "Error al cambiar la edad del paciente" << endl;

	cout << "Fin de las pruebas de los constructores, getters y setters de clase Paciente: " << endl;
}





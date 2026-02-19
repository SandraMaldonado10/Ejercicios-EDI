/*
 * PruebasMedico.cpp
 *
 *  Created on: 8 mar. 2023
 *      Author: alumno
 */

#include "PruebasMedico.h"

void probarClaseMedico () {
	cout << "Inicio de las pruebas de los constructores, getters y setters de la clase Medico: " <<endl;

	cout << "Pruebas para constructor por defecto: " <<endl;
	Medico m1;
	if (m1.getNombre () != "Sin asignar")
		cerr << "Error en el constructor por defecto" <<endl;
	if (m1.getApellidosMedico () != "Sin asignar")
		cerr << "Error en el constructor por defecto" <<endl;
	if (m1.getEspecialidad () != "Sin asignar")
		cerr << "Error en el constructor por defecto" <<endl;

	cout << "Pruebas para constructor parametrizado: " <<endl;
	Medico m2 ("Rigoberto","Pérez", "Matasanos del coco");
	if (m2.getApellidosMedico() != "Pérez")
		cerr << "Error en el constructor parametrizado" <<endl;
	if (m2.getEspecialidad() != "Matasanos del coco")
		cerr << "Error en el constructor parametrizado" <<endl;
	if (m2.getNombre() != "Rigoberto")
		cerr << "Error en el constructor parametrizado" <<endl;

	cout << "Pruebas para constructor por copia" <<endl;
	Medico m3 = m2;
	if (m3.getEspecialidad() != "Matasanos del coco")
		cerr << "Error en el constructor por copia" <<endl;
	if (m3.getNombre() != "Rigoberto")
		cerr << "Error en el constructor por copia" <<endl;
	if (m3.getApellidosMedico() != "Matasanos del coco")
		cerr << "Error en el constructor por copia" <<endl;

	cout << "Pruebas para los Setters en clase Médico" <<endl;
	m2.setEspecialidad("Estira pellejos");
	if (m2.getEspecialidad() != "Estira pellejos")
		cerr << "Error al modificar la especialidad del médico" <<endl;
	m3.setNombre("Valentino");
	if (m3.getNombre() != "Valentino")
		cerr << "Error al modificar la especialidad del médico" <<endl;
	m1.setApellidosMedico("Galeana");
	if (m1.getApellidosMedico() != "Galeana")
		cerr << "Error al modificar la especialidad del médico" <<endl;

	cout << "Fin de las pruebas de los constructores, getters y setters de la clase Medico" <<endl;

}



/*
 * Hospital.h
 *
 *  Created on: 26 feb. 2023
 *      Author: alumno
 */

#ifndef HOSPITAL_H_
#define HOSPITAL_H_

#include "ListaPacientes.h"
#include "ListaMedicos.h"
#include "Servicio.h"
#include <fstream>

class Hospital {
private:
	string nombreHospital;
	ListaPacientes *lp;
	ListaMedicos *lm;
	Servicio* s;

	/**
	 * PRE: ---
	 * POST: abre el fichero de texto medicos.csv, lee sus datos y los inserta en el vector de médicos
	 * COMPLEJIDAD: O(n)
	 */
	void cargarMedicos (); //Se pone en private porque va a ser utilizado por otro método de la clase pero no por nadie exterior
	/**
	 * PRE: ---
	 * POST: abre el fichero de texto pacientes.csv, lee sus datos y los inserta en el vector de pacientes
	 * COMPLEJIDAD: O(n)
	 */
	void cargarPacientes();
	/**
	* PRE: ---
	* POST: abre el fichero de texto informes.csv, lee sus datos y los inserta en el vector de informes
	* COMPLEJIDAD: O(n)
	*/
	void cargarInformes();

public:

	/**
	 * PRE: ----
	 * POST: La instancia queda creada correctamente
	 * COMPLEJIDAD: O(1)
	 */
	Hospital(); // constructor por defecto
	/**
	* PRE: nombre que se le asigna al hospital
	* POST: la instancia queda con los valores indicados
	* COMPLEJIDAD: O(1)
	*/
	Hospital (string nombreHospital);  //constructor parametrizado
	/**
	 * PRE: ---
	 * POST: muestra por pantalla los pacientes de la posición indicada
	 * COMPLEJIDAD: O(n)
	 */
	void mostrarPacientes ();
	/**
	 * PRE: ---
	 * POST: muestra por pantalla los médicos en orden según sus apellidos
	 * COMPLEJIDAD: O(n)
	 */
	void mostrarMedicos();
	void mostrarEstadisticas();
	void mostrarEnEspera();

	bool obtenerPaciente(string DNI, Paciente *&p);
	bool obtenerMedico(string apellidos, Medico *&m);
	void medicoDelServicio();
	void procesarPacientes();
	/**
	 * PRE: ----
	 * POST: destructor
	 * COMPLEJIDAD: O(1)
	 */
	~Hospital();  

	// ------GETTERS------
	const string& getNombre() const;

	// ------SETTERS------
	void setNombre(const string& nombre);

};

#endif /* HOSPITAL_H_ */

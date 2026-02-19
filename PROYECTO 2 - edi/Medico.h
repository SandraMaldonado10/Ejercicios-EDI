/*
 * medico.h
 *
 *  Created on: 12 feb. 2023
 *      Author: alumno
 */

#ifndef MEDICO_H_
#define MEDICO_H_

#include <string>
#include <iostream>
using namespace std;

class Medico {
public:
	string nombre;
	string apellidosMedico;
	string especialidad;

public:
	/**
	* PRE: ----
	* POST: La instancia queda creada correctamente
	* COMPLEJIDAD: O(1)
	*/
	Medico();
	/**
	 * PRE: nombre que se le va a indicar al médico
	 * 	    apellidos que se les va a indicar al médico
	 * 	    especialidad que se le va a indicar al médico
	 * 	(estos datos quedarán registrados al paciente)
	 * POST: la instancia queda con los valores indicados
	 * COMPLEJIDAD: O(1)
	 */
	Medico (string nombre, string apellidosMedico, string especialidad);  //constructor parametrizado
	/**
	 * PRE: m está correctamente inicializado
	 * DESC: constructor por copia
	 * COMPLEJIDAD: O(1)
	 */
	Medico (const Medico &m);  //constructor por copia
	/**
	* PRE: instancia creada correctamente
	* POST: muestra por pantalla todos los datos del médico
	* COMPLEJIDAD: O(1)
	*/
	void mostrar();
	/**
	 * PRE: ----
	 * POST: destructor
	 * COMPLEJIDAD: O(1)
	 */
	~Medico();

	// -------GETTERS------:

	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve el nombre del médico
	 * COMPLEJIDAD: O(1)
	 */
	string getNombre () const;
	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve el apellido del médico
	 * COMPLEJIDAD: O(1)
	 */
	string getApellidosMedico () const;
	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve la especialidad del médico
	 * COMPLEJIDAD: O(1)
	 */
	string getEspecialidad () const;

	// ------SETTERS--------:

	/**
	* PRE: nombre que se le va a asignar al médico
	* POST: el médico queda con el nombre indicado
	* COMPLEJIDAD: O(1)
	*/
	void setNombre (string nombre);
	/**
	* PRE: apellido que se le va a asignar al médico
	* POST: el médico queda con el apellido indicado
	* COMPLEJIDAD: O(1)
	*/
	void setApellidosMedico (string apellidosMedico);
	/**
	* PRE: especialidad que se le va a asignar al médico
	* POST: el médico queda con la especialidad indicada
	* COMPLEJIDAD: O(1)
	*/
	void setEspecialidad (string especialidad);

};

#endif /* MEDICO_H_ */

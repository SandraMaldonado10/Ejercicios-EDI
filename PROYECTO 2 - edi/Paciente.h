/*
 * paciente.h
 *
 *  Created on: 6 feb. 2023
 *      Author: alumno
 */

#ifndef PACIENTE_H_
#define PACIENTE_H_

#include "PilaInformes.h"
#include <iostream>
#include <string>
using namespace std;

// enum TGenero TipoGenero {
//     Hombre, Mujer, NoDefinido  //0, 1, 2
//};
// typedef TGenero TipoGenero

enum Genero {Mujer, Hombre, NoDefinido};
typedef enum Genero TipoGenero;

class Paciente {
private:
	string nombre;
	string apellidos;
	string DNI;
	int edad;
	TipoGenero genero;
	PilaInformes *pilaInf;

public:
	/**
	 * PRE: ----
	 * POST: La instancia queda creada correctamente
	 * COMPLEJIDAD: O(1)
	 */
	Paciente();  // constructor por defecto

	/**
	 * PRE: nombre que se le va a indicar al paciente
	 * 	    apellidos que se les va a indicar al paciente
	 * 	    DNI que se le va a indicar al paciente
	 * 	    edad: >=0 & <120
	 * 	    género que se le va a indicar al paciente
	 * 	(estos datos quedarán registrados al paciente)
	 * POST: la instancia queda con los valores indicados
	 * COMPLEJIDAD: O(1)
	 */
	// los parametrizados son para los atributos que considere obligatorios para crear un paciente
	Paciente(string nombre, string apellidos, string DNI, int edad, TipoGenero genero); //constructor parametrizado
	/**
	* PRE: nombre que se le indica al paciente
	*      DNI que se le indica al paciente
	* POST: la instancia queda con los valores indicados
	* COMPLEJIDAD: O(1)
	*/
	Paciente (string nombre, string DNI);
	/**
	 * PRE: p está correctamente inicializado
	 * DESC: constructor por copia
	 * COMPLEJIDAD: O(1)
	 */
	Paciente (const Paciente &p);  //constructor por copia

	void insertarInforme(Informe* in);
	// --------GETTERS-----:

	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve el nombre del paciente
	 * COMPLEJIDAD: O(1)
	 */
	const string& getNombre() const;
	/**
	* PRE: que la instancia haya sido creada correctamente
	* POST: devuelve los apellidos del paciente
	* COMPLEJIDAD: O(1)
	*/
	const string& getApellidos() const;
	/**
	* PRE: que la instancia haya sido creada correctamente
	* POST: devuelve el dni del paciente
	* COMPLEJIDAD: O(1)
	*/
	const string& getDni() const;
	/**
	* PRE: que la instancia haya sido creada correctamente
	* POST: devuelve la edad del paciente
	* COMPLEJIDAD: O(1)
	*/
	int getEdad() const;
	/**
	* PRE: que la instancia haya sido creada correctamente
	* POST: devuelve el género del paciente
	* COMPLEJIDAD: O(1)
	*/
	TipoGenero getGenero() const;


	// ----------SETTERS---------:

	/**
	* PRE: nombre que se le van a asignar al paciente
	* POST: el paciente queda con el nombre indicado
	* COMPLEJIDAD: O(1)
	*/
	void setNombre(const string &nombre);
	/**
	* PRE: apellidos que se le van a asignar al paciente
	* POST: el paciente queda con los apellidos indicados
	* COMPLEJIDAD: O(1)
	*/
	void setApellidos(const string &apellidos);
	/**
	* PRE: dni que se le va a asignar al paciente
	* POST: el paciente queda con el dni indicado
	* COMPLEJIDAD: O(1)
	*/
	void setDni(const string &dni);
	/**
	* PRE: edad que se le va a asignar al paciente
	* POST: el paciente queda con la edad indicado
	* COMPLEJIDAD: O(1)
	*/
	void setEdad(int edad);
	/**
	* PRE: género que se le van a asignar al paciente
	* POST: el paciente queda con el género indicado
	* COMPLEJIDAD: O(1)
	*/
	void setGenero(TipoGenero genero);
// ----------------------------------------------------------------------
	/**
	 * PRE: instancia creada correctamente
	 * POST: muestra por pantalla todos los datos del paciente
	 * COMPLEJIDAD: O(1)
	 */
	void mostrar ();
	void mostrarInformes();
	/**
	 * PRE: ----
	 * POST: destructor
	 * COMPLEJIDAD: O(1)
	 */
	~Paciente();  // destructor
	};

#endif /* PACIENTE_H_ */

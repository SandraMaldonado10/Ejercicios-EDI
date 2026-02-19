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

enum Genero { Mujer, Hombre, NoDefinido };
typedef enum Genero TipoGenero;

class Paciente {
private:
	string nombre;
	string apellidos;
	string DNI;
	int edad;
	TipoGenero genero;
	int puntuacion;
	PilaInformes *pilaInformes;

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
	 * 	    g�nero que se le va a indicar al paciente
	 * 	(estos datos quedar�n registrados al paciente)
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
	Paciente(string nombre, string DNI);
	/**
	 * PRE: p est� correctamente inicializado
	 * DESC: constructor por copia
	 * COMPLEJIDAD: O(1)
	 */
	Paciente(const Paciente& p);  //constructor por copia

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
	* POST: devuelve el genero del paciente
	* COMPLEJIDAD: O(1)
	*/
	TipoGenero getGenero() const;
	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve la puntuación del paciente
	 * COMPLEJIDAD: O(1)
	 */
	int getPuntuacion() const;


	// ----------SETTERS---------:

	/**
	* PRE: nombre que se le van a asignar al paciente
	* POST: el paciente queda con el nombre indicado
	* COMPLEJIDAD: O(1)
	*/
	void setNombre(const string& nombre);
	/**
	* PRE: apellidos que se le van a asignar al paciente
	* POST: el paciente queda con los apellidos indicados
	* COMPLEJIDAD: O(1)
	*/
	void setApellidos(const string& apellidos);
	/**
	* PRE: dni que se le va a asignar al paciente
	* POST: el paciente queda con el dni indicado
	* COMPLEJIDAD: O(1)
	*/
	void setDni(const string& dni);
	/**
	* PRE: edad que se le va a asignar al paciente
	* POST: el paciente queda con la edad indicado
	* COMPLEJIDAD: O(1)
	*/
	void setEdad(int edad);
	/**
	* PRE: g�nero que se le van a asignar al paciente
	* POST: el paciente queda con el g�nero indicado
	* COMPLEJIDAD: O(1)
	*/
	void setGenero(TipoGenero genero);
	/**
	 * PRE: puntuación que se le va a asignar al paciente
	 * POST: el paciente queda con la puntuación indicada
	 * COMPLEJIDAD: =(1)
	 */
	void setPuntuacion(int puntuacion);

	// ----------------------------------------------------------------------
	/**
	 * PRE: instancia creada correctamente
	 * POST: muestra por pantalla todos los datos del paciente
	 * COMPLEJIDAD: O(1)
	 */
	void mostrar();
	/**
	 * PRE: instancia creada correctamente
	 * POST: muestra por pantalla los informes de los pacientes
	 * COMPLEJIDAD:O(1)
	 */
	void mostrarInformes();
	/**
	 * PRE: instancia creada correctamente
	 * POST: muestra por pantalla la puntuacion adignada al paciente, que puede ser 0,1 o 2
	 * COMPLEJIDAD: O(1)
	 */
	void mostrarPuntuacion();
	/**
	 * PRE: ----
	 * POST: destructor
	 * COMPLEJIDAD: O(1)
	 */
	~Paciente();  // destructor
};

#endif /* PACIENTE_H_ */

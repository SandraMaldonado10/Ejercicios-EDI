#pragma once

#ifndef LISTAMEDICOS_H_
#define LISTAMEDICOS_H_

#include "Medico.h"
#include "ListaDPI.h"

class ListaMedicos {
private:
	ListaDPI <Medico*> *lMedicos;

public:
	/*
	PRE: ---
	POST: la instancia queda creada correctamente
	COMPLEJIDAD: O(1)
	*/
	ListaMedicos();
	/*
	PRE: m es un puntero a la clase medico
	POST: inserta el médico según sus apellidos
	COMPLEJIDAD: O(n)
	*/
	void insertarPorApellido(Medico* m); 
	/*
	PRE: apellidosMedico que se le asigna al médico
	POST: devuelve true si existe el médico con sus apellidos indicados, y false en caso contrario
	COMPLEJIDAD: O(n)
	*/
	bool existePorApellido(string apellidosMedico);
	/*
	PRE: apellidosMedico que se le asigna al médico
		 m es un puntero de entrada salida de la clase medico
	POST: devuelve el médico, si los apellidos coinciden con los indicados
	COMPLEJIDAD: O(n)
	*/
	bool obtenerMedico(string apellidosMedico, Medico *&m);
	/*
	PRE: que la lista no esté vacía
	POST: devuelve el primer médico que se encuentre en la lista
	COMPLEJIDAD: O(1)
	*/
	Medico* obtenerPrimerMedico();
	/*
	PRE: ---
	POST: devuelve true si encuentra la lista vacía, y false en caso contrario
	COMPLEJIDAD: 0(1)
	*/
	bool estaVacia();
	/*
	PRE: ---
	POST: devuelve la cantidad de medicos que hay en la lista
	COMPLEJIDAD: O(n)
	*/
	int cuantosMedicos();
	/*
	PRE: ---
	POST: muestra por pantalla la lista de los médicos
	COMPLEJIDAD: O(n)
	*/
	void mostrar();
	/*
	PRE: especialidad que se le asigna al médico
	POST: devuelve el médico según la especialidad indicada
	COMPLEJIDAD: O(n)
	*/
	Medico* obtenerMedPorEspecialidad(string especialidad);
	/*
	PRE: ---
	POST: destructor
	COMPLEJIDAD: O(1)
	*/
	~ListaMedicos();
};

#endif /* LISTAMEDICOS_H_ */
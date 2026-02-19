#pragma once

#ifndef LISTAPACIENTES_H_
#define LISTAPACIENTES_H_

#include "ListaDPI.h"
#include "Paciente.h"

class ListaPacientes {
private:
	ListaDPI <Paciente*> *lPacientes;

public:
	/*
	PRE: ---
	POST: la instancia queda creada correctamente
	COMPLEJIDAD: O(1)
	*/
	ListaPacientes();
	/*
	PRE: p es un puntero a la clase paciente
	POST: inserta el paciente según su DNI
	COMPLEJIDAD: O(n)
	*/
	void insertarPorDNI(Paciente *p); 
	/*
	PRE: DNI que se le asigna al paciente
	POST: devuelve true si existe el paciente con su DNI indicado, y false en caso contrario
	COMPLEJIDAD: O(n)
	*/
	bool existePorDNI(string DNI);
	/*
	PRE: que la lista no esté vacía
	POST: devuelve el primer paciente que se encuentre en la lista
	COMPLEJIDAD: O(1)
	*/
	Paciente* obtenerPrimerPaciente();
	/*
	PRE: DNI que se le asigna al paciente
		 p es un puntero de entrada salida de la clase paciente
	POST: devuelve el paciente, si el DNI coincide con los indicados
	COMPLEJIDAD: O(n)
	*/
	bool obtenerPaciente(string DNI, Paciente *&p);
	/*
	PRE: ---
	POST: devuelve true si encuentra la lista vacía, y false en caso contrario
	COMPLEJIDAD: 0(1)
	*/
	bool estaVacia();
	/*
	PRE: ---
	POST: devuelve la cantidad de pacientes que hay en la lista
	COMPLEJIDAD: O(n)
	*/
	int cuantosPacientes();
	/*
	PRE: ---
	POST: muestra por pantalla la lista de los pacientes
	COMPLEJIDAD: O(n)
	*/
	void mostrar();
	/*
	PRE: ---
	POST: destructor
	COMPLEJIDAD: O(1)
	*/
	~ListaPacientes();

};

#endif /* LISTAPACIENTES_H_ */


#pragma once

#ifndef COLAPACIENTES_H_
#define COLAPACIENTES_H_

#include "Cola.h"
#include "Paciente.h"

class ColaPacientes {
private:
	Cola <Paciente*> *cp;

public:
	/*
	PRE: ---
	POST: la instancia queda creada correctamente
	COMLEJIDAD: O(1)
	*/
	ColaPacientes();
	/*
	PRE: *p: puntero de la clase pacientes
	POST: insertar un nuevo paciente en la cola
	COMPLEJIDAD:O(1)
	*/
	void insertar(Paciente* p);
	/*
	PRE: cont = 0
	POST: devuelve la cantidad de elementos que hay en la cola
	COMPLEJIDAD: O(n)
	*/
	int cuantos();
	/*
	PRE: *p: puntero que devuelve como salida, de la clase paciente
	POST: devuelve el primer paciente de la cola y lo elimina
	COMPLEJIDAD: O(1)
	*/
	void obtener(Paciente*& p); 
	/*
	PRE: ---
	POST: devuelve true si la cola está vacía, y false en caso contrario
	COMPLEJIDAD: O(1)
	*/
	bool estaVacia();
	/*
	PRE: instancia creada correctamente
	POST: muestra todos los pacientes que hay dentro de la cola
	COMPLEJIDAD:= O(n)
	*/
	void mostrar(); 
	/*
	PRE: ---
	POST: destructor
	COMPLEJIDAD: O(1)
	*/
	~ColaPacientes();

};


#endif /* COLAPACIENTES_H_ */

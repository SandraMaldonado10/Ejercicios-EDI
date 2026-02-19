#pragma once

#ifndef PILAINFORMES_H_
#define PILAINFORMES_H_

#include "Pila.h"
#include "Informe.h"
#include "Medico.h" 

class PilaInformes {
private:
	Pila <Informe*>* pInformes; // los <> son para decir lo que guarda la pila, en este caso son los informes por punteros

public:
	/*
	PRE: ---
	POST: la instancia queda creada correctamente
	COMPLEJIDAD: O(1)
	*/
	PilaInformes();
	/*
	PRE: in es un puntero a la clase informe
	POST: inserta el informe a la pila
	COMPLEJIDAD: O(1)
	*/
	void insertarInforme(Informe* in);
	/*
	PRE: que la pila no esté vacía
	POST: devuelve el primer informe que se encuentre en la pila
	COMPLEJIDAD: O(1)
	*/
	Informe* consultarInforme(); 
	/*
	PRE: in es un puntero de entrada salida de la clase informe 
	POST: devuelve el primer informe que se encuentre en la pila
	COMPLEJIDAD: O(1)
	*/
	void consultarInforme(Informe*& in);
	/*
	PRE: ---
	POST: muestra por pantalla los informes totales de la pila
	COMPLEJIDAD: O(n)
	*/
	void mostrarInformesTotales();
	/*
	PRE: apellidos que se le asigna al medico
	POST: muestra por pantalla los informes de los medicos de la pila indicada
	COMPLEJIDAD: O(n)
	*/
	void mostrarInformesMedico(string apellidos);
	/*
	PRE: apellidos que se le asigna al medico
	POST: elimina los informes de los pedicos de la pila indicada
	COMPLEJIDAD: O(n)
	*/
	void borrarInformesMedico(string apellidos);
	/*
	PRE: ---
	POST: devuelve true si encuentra la pila vacía, y false en caso contrario
	COMPLEJIDAD: 0(1)
	*/
	bool estaVacia();
	/*
	PRE: ---
	POST: elimina el primer informe de la pila indicada
	COMPLEJIDAD: O(n)
	*/
	void borrarPrimerInf();
	/*
	PRE: ---
	POST: destructor
	COMPLEJIDAD: O(1)
	*/
	~PilaInformes();
};

#endif /* PILAINFORMES_H_ */
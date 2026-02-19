/*
 * VoVMedicos.h
 *
 *  Created on: 2 mar. 2023
 *      Author: alumno
 */

#ifndef VOVMEDICOS_H_
#define VOVMEDICOS_H_

#include "Medico.h"

const int MAXMEDICOS = 300;

class VoVMedicos {
private:
	Medico *medicos [MAXMEDICOS];
	int ocupadas;
public:
	/**
	 * PRE: ----
	 * POST: La instancia queda creada correctamente
	 * COMPLEJIDAD: O(1)
	 */
	VoVMedicos();
	/**
	 * PRE: *m: puntero a objeto del médico indicado
	 * POST: copia el puntero m en la primera posición libre
	 * COMPLEJIDAD: O(n)
	 */
	void insertar (Medico *m);
	/**
	 * PRE: pos >= 0
	 * POST:se copia la posición que quiere borrar el usuario y se pone en el primer vector
	 * COMPLEJIDAD: O(n)
	 */
	void borrar (int pos);
	/**
	 * PRE: pos >= 0; Medico correctamente inicializado
	 * POST: devuelven la posición que indica el usuario
	 * COMPLEJIDAD: O(n)
	 */
	Medico *getPosicion (int pos);
	/**
	 * PRE: ---
	 * POST: devuelve los médicos totales que hay
	 * COMPLEJIDAD: O(1)
	 */
	int getOcupadas ();
	/**
	 * PRE: ---
	 * POST: devuelve true si el vector se encuentra vacío, y false en caso contrario
	 * COMPLEJIDAD: O(1)
	 */
	bool estaVacio ();
	/**
	 * PRE: ---
	 * POST: devuelve true si el vector se encuentra lleno (MAXMEDICOS), y false en caso contrario
	 * COMPLEJIDAD: O(1)
	 */
	bool estaLleno ();
	/**
	 * PRE: ----
	 * POST: destructor
	 * COMPLEJIDAD: O(1)
	 */
	~VoVMedicos();

};

#endif /* VOVMEDICOS_H_ */

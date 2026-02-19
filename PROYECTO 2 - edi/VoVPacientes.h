/*
 * VoVPacientes.h
 *
 *  Created on: 2 mar. 2023
 *      Author: alumno
 */

#ifndef VOVPACIENTES_H_
#define VOVPACIENTES_H_

#include "Paciente.h"

const int MAXPACIENTES = 300;

class VoVPacientes {
private:
	Paciente *pacientes [MAXPACIENTES];
	int ocupadas;

public:
	/**
	* PRE: ----
	* POST: La instancia queda creada correctamente
	* COMPLEJIDAD: O(1)
	*/
	VoVPacientes();

	/**
	 * PRE: *p: puntero a objeto del paciente indicado
	 * POST: copia el puntero p en la primera posición libre
	 * COMPLEJIDAD: O(n)
	 */
	void insertar (Paciente *p);
	/**
	 * PRE: pos >= 0
	 * POST: se copia la posición que quiere borrar el usuario y se pone en el primer vector
	 * COMPLEJIDAD: O(n)
	 */
	void borrar (int pos);
	/**
	 * PRE: pos >= 0; Paciente correctamente inicializado
	 * POST: devuelven la posición que indica el usuario
	 * COMPLEJIDAD: O(n)
	 */
	Paciente *getPosicion (int pos);
	/**
	 * PRE: ---
	 * POST: devuelve los pacientes totales que hay
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
	~VoVPacientes();
};

#endif /* VOVPACIENTES_H_ */

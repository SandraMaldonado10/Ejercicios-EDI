/*
 * VoVConsultas.h
 *
 *  Created on: 19 feb. 2023
 *      Author: alumno
 */

#ifndef VOVCONSULTAS_H_
#define VOVCONSULTAS_H_

#include "Consulta.h"
#include "FechaYHora.h"

using namespace std;

const int MAXCONSULTAS=300;

class VoVConsultas {
private:
	Consulta *consultas[MAXCONSULTAS];
	int ocupadas;

public:
	/**
	 * PRE: ----
	 * POST: La instancia queda creada correctamente
	 * COMPLEJIDAD: O(1)
	 */
	VoVConsultas();  //constructor por defecto

	/**
	 * PRE: *c: puntero a objeto de la consulta indicada
	 * POST: copia el puntero c en la primera posición libre
	 * COMPLEJIDAD: O(n)
	 */
	void insertar (Consulta *c);  //los elementos que se insertan son punteros a consultas, ojo --> Consulta*
	/**
	 * PRE: pos >= 0
	 * POST:se copia la posición que quiere borrar el usuario y se pone en el primer vector
	 * COMPLEJIDAD: O(n)
	 */
	void borrar (int pos);
	/**
	 * PRE: pos >= 0; *c: puntero a objeto de la consulta indicada
	 * POST: devuelven la posición que indica el usuario
	 * COMPLEJIDAD: O(n)
	 */
	Consulta* getPosicion (int pos);// lo hacemos devolviendolo como parámetro de salida
	/**
	 * PRE: ---
	 * POST: devuelve las consultas totales que hay
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
	 * POST: devuelve true si el vector se encuentra lleno (MAXCONSULTAS), y false en caso contrario
	 * COMPLEJIDAD: O(1)
	 */
	bool estaLleno ();
	/**
	 * PRE: c*: puntero a objeto de la consulta indicada
	 * POST: inserta las consultas en orden
	 * COMPLEJIDAD: O(n²)
	 */
	void insertarEnOrden (Consulta *&c);
	/**
	 * PRE: ----
	 * POST: destructor
	 * COMPLEJIDAD: O(1)
	 */
	~VoVConsultas();  //destructor
};

#endif /* VOVCONSULTAS_H_ */

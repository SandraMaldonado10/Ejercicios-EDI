/*
 * Consulta.h
 *
 *  Created on: 13 feb. 2023
 *      Author: alumno
 */

#ifndef CONSULTA_H_
#define CONSULTA_H_

#include <string>
using namespace std;
#include <iostream>

#include "FechaYHora.h"
#include "Paciente.h"
#include "Medico.h"

enum TipoConsulta {Urgente, Pendiente,Externa};
typedef enum TipoConsulta Tipo;

class Consulta {
private:
	Paciente *p;
	Medico *m;
	FechaYHora fyh;
	Tipo TipoConsulta;
	bool alta;
	string informe;

public:
	/**
	 * PRE: ---
	 * POST: la instancia queda creada correctamente
	 * COMPLEIJIDAD: O(1)
	 */
	Consulta();  //constructor por defecto

	/**
	 * PRE: *p: puntero a objeto del paciente indicado
	 * POST: la instancia queda creada con la consulta indicada
	 * COMPLEJIDAD: O(1)
	 */
	Consulta (Paciente *p);  //constructor parametrizado 1
	/**
	 * PRE: *p: puntero a objeto del paciente indicado
	 * 		*m: puntero a objeto del médico indicado
	 * POST: la instancia queda con los valores indicados
	 * COMPLEJIDAD: O(1)
	 */
	Consulta (Paciente *p, Medico *m); //constructor parametrizado 2
	 /**
	 * PRE: *p: puntero a objeto del paciente indicado
	 * 		*m: puntero a objeto del médico indicado
	 * 		fecha y hora que se le asigna a la consulta
	 * 		tipo: devuelve el tipo de consulta que se le asigna
	 * POST: la instancia queda con los valores indicados
	 * COMPLEJIDAD: O(1)
	 */
	Consulta (Paciente *p, Medico *m, FechaYHora fyh, Tipo TipoConsulta);  //constructor parametrizado 3
	/**
	 * PRE: ---
	 * POST: devuelve true si se da el alta al paciente, y false en caso contrario
	 * COMPLEJIDAD: 0(1)
	 */
	void darDeAlta ();
	/**
	 * PRE: informe que se le asigna a la consulta indicada
	 * POST: se añade un informe a la consulta indicada
	 * COMPLEJIDAD: 0(1)
	 */
	void adjuntarInforme (string informe);
	/**
	 * PRE: *m: puntero a objeto del médico indicado
	 * POST: se asigna un médico a la consulta indicada
	 * COMPLEJIDAD: 0(1)
	 */
	void asignarMedico (Medico *m);
	/**
	 * PRE: fyh: puntero a objeto de la fecha y hora indicadas
	 * POST: se asigna una fecha y hora a la consulta indicada
	 * COMPLEJIDAD: 0(1)
	 */
	void agendarFecha (FechaYHora f);

	// -----GETTERS----:
	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve la fecha y hora de la consulta
	 * COMPLEJIDAD: O(1)
	 */
	FechaYHora getFechaYHora ();
	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve el paciente de la consulta
	 * COMPLEJIDAD: O(1)
	 */
	Paciente* getPaciente ();
	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve el médico de la consulta
	 * COMPLEJIDAD: O(1)
	 */
	Medico* getMedico ();
	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve el tipo de consulta de dicha consulta
	 * COMPLEJIDAD: O(1)
	 */
	Tipo getTipoConsulta() const;
	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve el informe de dicha consulta
	 * COMPLEJIDAD: O(1)
	 */
	const string& getInforme() const;
	/**
	 * PRE: que la instancia haya sido creada correctamente
	 * POST: devuelve el tipo de consulta de dicha consulta
	 * COMPLEJIDAD: O(1)
	 */
	bool getAlta ();

	/**
	* PRE: tipo de consulta que se le va a asignar a dicha consulta
	* POST: la consulta queda con su tipo de conuslta asignada
	* COMPLEJIDAD: O(1)
	*/
	void setTipoConsulta(Tipo TipoConsulta); // SET
	/**
	 * PRE: instancia creada correctamente
	 * POST: muestra por pantalla todos los datos de la consulta
	 * COMPLEJIDAD: O(n)
	 */
	void setInforme(const string &informe);
	void setAlta(bool alta);

	void mostrar ();

	/**
	 * PRE: ----
	 * POST: destructor
	 * COMPLEJIDAD: O(1)
	 */
	~Consulta();


};

#endif /* CONSULTA_H_ */

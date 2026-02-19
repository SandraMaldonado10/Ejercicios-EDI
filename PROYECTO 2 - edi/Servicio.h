#pragma once

#ifndef SERVICIO_H_
#define SERVICIO_H_

#include "ColaPacientes.h"
#include <ctime>

const int MAX_PRIORIDAD = 5;    // 1...5

class Servicio {
private:
	string especialidad;
	ColaPacientes* colaPP[MAX_PRIORIDAD];
	Medico* med;
	string obtenerFecha();

public:
	/*
	PRE: ---
	POST: la instancia queda creada correctamente
	COMPLEJIDAD: O(1)
	*/
	Servicio(); 
	/*
	PRE: especialidad que se le asigna al servicio
	POST: la instancia queda creada correctamente
	COMPLEJIDAD: O(1)
	*/
	Servicio(string especialidad);
	/*
	PRE: p es un puntero a la clase paciente
		 prioridad que se le asigna al servicio
	POST: inserta servicio
	COMPLEJIDAD: O(n)
	*/
	void insertar(int prioridad, Paciente* p);
	/*
	PRE: prioridad que se le asigna al servicio
	POST: devuelve true si el servicio está vacio según la prioridad indicada y false en caso contrario
	COMPLEJIDAD: O(n)
	*/
	bool estaVaciaPrioridad(int prioridad);
	/*
	PRE: ---
	POST: devuelve true si encuentra el servicio vacío, y false en caso contrario
	COMPLEJIDAD: 0(1)
	*/
	bool estaVacia();
	/*
	PRE: prioridad que se le asigna al servicio
	POST: muestra el servicio según la prioridad indicada
	COMPLEJIDAD: 0(n)
	*/
	void mostrarPrioridad(int prioridad);
	/*
	PRE: ---
	POST: muestra el servicio por pantalla
	COMPLEJIDAD: 0(1)
	*/
	void mostrar();
	/*
	PRE: ---
	POST: muestra el número de colas en el servicio
	COMPLEJIDAD: 0(n)
	*/
	void mostrarCantidadesColas();
	/*
	PRE: ---
	POST: procesa las colas del servicio indicado
	COMPLEJIDAD: 0(n)
	*/
	void procesarColas();
	/*
	PRE: ---
	POST: destructor
	COMPLEJIDAD: O(1)
	*/
	~Servicio();

	// ---- GETTERS ----
	Medico* getMedico();
	const string& getEspecialidad() const;

	// ---- SETTERS ----
	void setMedico(Medico* medico);
	void setEspecialidad(const string& especialidad);
	
};

#endif /* SERVICIO_H_ */
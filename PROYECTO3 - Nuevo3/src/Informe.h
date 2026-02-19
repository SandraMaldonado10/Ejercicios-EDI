
#ifndef INFORME_H_
#define INFORME_H_

#include "FechaYHora.h"
#include "Medico.h"

#include <iostream>
using namespace std;

class Informe {
private:
	string texto;
	FechaYHora fecha;
	Medico* med;

public:
	/*
	PRE: ---
	POST: la instancia queda creada correctamente
	COMPLEJIDAD: O(1)
	*/
	Informe();
	/*
	PRE: texto propio del informe
		 fecha y hora propia del informe
		 médico propio  del informe
	POST: la instancia queda con los valores indicados
	COMPLEJIDAD:O(1)
	*/
	Informe(string texto, FechaYHora fecha, Medico* med);
	/*
	PRE: m: puntero a medico correctamente inicializado
	POST: constructor por copia
	COMPLEJIDAD: O(1)
	*/
	Informe(const Informe& in);
	/*
	PRE: ---
	POST: destructor
	COMPLEJIDAD: O(1)
	*/
	~Informe();
	/*
	PRE: instancia creada correctamente
	POST: muestra por pantalla todos los datos del informe
	COMPLEJIDAD:
	*/
	void mostrar();

	// ---- GETTERS ----:
	/*
	PRE: que la instancia haya sido creada correctamente
	POST: devuelve la fecha del informe
	COMPLEJIDAD: O(1)
	*/
	const FechaYHora& getFecha() const;
	/*
	PRE: que la instancia haya sido creada correctamente
	POST: devuelve el médico del informe
	COMPLEJIDAD: O(1)
	*/
	Medico* getMed() const;
	/*
	PRE: que la instancia haya sido creada correctamente
	POST: devuelve el texto del informe
	COMPLEJIDAD: O(1)
	*/
	const string& getTexto() const;

	// ----SETTERS----:
	/*
	PRE: fecha que se le asigna al informe
	POST: el informe queda con la fecha indicada
	COMPLEJIDAD: O(1)
	*/
	void setFecha(const FechaYHora& fecha);
	/*
	PRE: médico que se le asigna al informe
	POST: el informe queda con el médico indicado
	COMPLEJIDAD: O(1)
	*/
	void setMed(Medico *med);
	/*
	PRE: texto que se le asigna al informe
	POST: el informe queda con el texto indicado
	COMPLEJIDAD: O(1)
	*/
	void setTexto(const string& texto);

};


#endif /* INFORME_H_ */


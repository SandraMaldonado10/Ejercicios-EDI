//============================================================================
// Name        : ArbolPersonas.h
// Author      : Profesores de EDI
// Version     : 1.0
// Description : Interfaz de la clase ArbolPersona (BSTree de punteros a
//				 objetos de la clase Person)
//============================================================================


#ifndef ARBOLPERSONAS_H_
#define ARBOLPERSONAS_H_

#include "BSTree.h"
#include "KeyValue.h"
#include "Person.h"

class ArbolPersonas {
private:
	BSTree < KeyValue <string, Person * > > *arbol;

	void mostrarEnOrdenR ( BSTree < KeyValue <string, Person * > > *arbol ) const;
	int calcularProfundidadR ( BSTree < KeyValue <string, Person * > > *arbol ) const;
	int contarPersonasR ( BSTree < KeyValue <string, Person * > > *arbol ) const;

public:
	ArbolPersonas ( );
	KeyValue < string, Person * > getRaiz ( ) const;
	void insertar ( const KeyValue < string, Person * > & kv );
	void eliminar ( const KeyValue < string, Person * > & kv );
	int calcularProfundidad ( ) const;
	int contarPersonas ( ) const;
	void mostrarEnOrden ( ) const;
	~ArbolPersonas ( );
};

#endif /* ARBOLPERSONAS_H_ */

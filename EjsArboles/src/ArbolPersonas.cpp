//============================================================================
// Name        : Main.cpp
// Author      : Profesores de EDI
// Version     : 1.0
// Description : Implementación de la clase ArbolPersona (BSTree de punteros a
//				 objetos de la clase Person)
//============================================================================

#include "ArbolPersonas.h"

// ----------------------------------------------------------------------------
// Métodos privados
// ----------------------------------------------------------------------------

void ArbolPersonas::mostrarEnOrdenR ( BSTree < KeyValue <string, Person * > > *arbol ) const {
	if ( !arbol->estaVacio ( ) ) {
		if ( arbol->getIzq ( ) != nullptr )
			mostrarEnOrdenR ( arbol->getIzq ( ) );

		cout << "\t";
		arbol->getDato ( ).getValue()->display ( );

		if ( arbol->getDer ( ) != nullptr )
			mostrarEnOrdenR ( arbol->getDer ( ) );
	}
}

int ArbolPersonas::calcularProfundidadR ( BSTree < KeyValue <string, Person *> > *arbol ) const {
	int prof = 0;
	int prof_izq = 0;
	int prof_der = 0;
	if ( !arbol->estaVacio ( ) ) {
		if ( arbol->getIzq ( ) != nullptr )
			prof_izq = calcularProfundidadR ( arbol->getIzq ( ) );
		if ( arbol->getDer ( ) != nullptr )
			prof_der = calcularProfundidadR ( arbol->getDer ( ) );
		prof = max ( prof_izq, prof_der ) + 1;
	}
	return prof;
}

int ArbolPersonas::contarPersonasR ( BSTree < KeyValue <string, Person *> > *arbol ) const {
	int contador = 0;
	if ( !arbol->estaVacio ( ) ) {
		contador = 1;
		if ( arbol->getIzq ( ) != nullptr )
			contador = contador + contarPersonasR ( arbol->getIzq ( ) );
		if ( arbol->getDer ( ) != nullptr )
			contador = contador + contarPersonasR ( arbol->getDer ( ) );
	}
	return contador;
}

// ----------------------------------------------------------------------------
// Métodos públicos
// ----------------------------------------------------------------------------

ArbolPersonas::ArbolPersonas() {
	this->arbol = new BSTree < KeyValue < string, Person* > > ( );
}

ArbolPersonas::~ArbolPersonas() {
	delete arbol;
}

KeyValue < string, Person * > ArbolPersonas::getRaiz ( ) const {
	return this->arbol->getDato ( );
}

void ArbolPersonas::insertar ( const KeyValue < string, Person * > & kv ) {
	this->arbol->insertar ( kv );
}

void ArbolPersonas::eliminar ( const KeyValue < string, Person * > & kv ) {
	this->arbol->eliminar ( kv );
}

int ArbolPersonas::calcularProfundidad ( ) const {
	return calcularProfundidadR ( this->arbol );
}

int ArbolPersonas::contarPersonas ( ) const {
	return contarPersonasR ( this->arbol );
}

void ArbolPersonas::mostrarEnOrden ( ) const {
	mostrarEnOrdenR ( this->arbol );
}

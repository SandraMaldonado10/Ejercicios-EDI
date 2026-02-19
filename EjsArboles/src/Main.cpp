//============================================================================
// Name        : Main.cpp
// Author      : Profesores de EDI
// Version     : 1.0
// Description : Programa que crea un ArbolPersonas y trabaja con él para
//				 demostrar su funcionamiento.
//============================================================================

#include <iostream>
#include "ArbolPersonas.h"
using namespace std;

int main() {

	cout << "---------------------------------------" << endl;

	ArbolPersonas *arbol = new ArbolPersonas ( );

	Person *p1 = new Person ("Anna", "33333333C" );
	Person *p2 = new Person ("Juan", "44444444D" );
	Person *p3 = new Person ("Lara", "11111111A" );
	Person *p4 = new Person ("Luis", "22222222B" );

	KeyValue < string, Person * > kv1 ( p1->getId ( ), p1 );
	KeyValue < string, Person * > kv2 ( p2->getId ( ), p2 );
	KeyValue < string, Person * > kv3 ( p3->getId ( ), p3 );
	KeyValue < string, Person * > kv4 ( p4->getId ( ), p4 );

	arbol->insertar ( kv1 );
	arbol->insertar ( kv2 );
	arbol->insertar ( kv3 );
	arbol->insertar ( kv4 );

	cout << endl << "Después de insertar 4 personas, el árbol contiene: " << endl;
	arbol->mostrarEnOrden ( );
	cout << "La raíz del árbol es: ";
	arbol->getRaiz( ).getValue()->display();
	cout << "Ahora mismo el árbol tiene " << arbol->contarPersonas ( ) << " personas" << endl;
	cout << "Y su profundidad es " << arbol->calcularProfundidad ( ) << endl;

	arbol->eliminar ( kv4 ); // eliminamos a Luis

	cout << endl << "Después de borrar a Luis, el árbol contiene: " << endl;
	arbol->mostrarEnOrden ( );
	cout << "La raíz del árbol es: ";
	arbol->getRaiz( ).getValue()->display();
	cout << "Ahora mismo el árbol tiene " << arbol->contarPersonas ( ) << " personas" << endl;
	cout << "Y su profundidad es " << arbol->calcularProfundidad ( ) << endl;

	arbol->eliminar ( kv1 );  // eliminamos a Anna (raíz)

	cout << endl << "Después de borrar a Anna, el árbol contiene: " << endl;
	arbol->mostrarEnOrden ( );
	cout << "La raíz del árbol es: ";
	arbol->getRaiz( ).getValue()->display();
	cout << "Ahora mismo el árbol tiene " << arbol->contarPersonas ( ) << " personas" << endl;
	cout << "Y su profundidad es " << arbol->calcularProfundidad ( ) << endl;

	arbol->eliminar ( kv3 ); // borramos a Lara (raíz)

	cout << endl << "Después de borrar a Lara, el árbol contiene: " << endl;
	arbol->mostrarEnOrden ( );
	cout << "La raíz del árbol es: ";
	arbol->getRaiz( ).getValue()->display();
	cout << "Ahora mismo el árbol tiene " << arbol->contarPersonas ( ) << " personas" << endl;
	cout << "Y su profundidad es " << arbol->calcularProfundidad ( ) << endl;

	arbol->eliminar ( kv2 ); // borramos a Juan (raíz, último elemento)

	cout << endl << "Después de borrar a Juan, el árbol contiene: " << endl;
	arbol->mostrarEnOrden ( );
	cout << "La raíz del árbol es: ";
	arbol->getRaiz( ).getValue()->display();
	cout << "Ahora mismo el árbol tiene " << arbol->contarPersonas ( ) << " personas" << endl;
	cout << "Y su profundidad es " << arbol->calcularProfundidad ( ) << endl;

	delete arbol;
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	cout << "---------------------------------------" << endl;

	return 0;
}

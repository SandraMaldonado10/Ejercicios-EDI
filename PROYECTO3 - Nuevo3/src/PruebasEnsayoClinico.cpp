/*
 * PruebasEnsayoClinico.cpp
 *
 *  Created on: 12 may. 2023
 *      Author: alumno
 */
#include "PruebasEnsayoClinico.h"
#include "ensayoclinico.h"

void PruebasArchivo () {

	cout << "Comienzan las pruebas para abrir los archivos .csv" <<endl;

	//ifs.open("pacientes_ordenados.csv");
	ifstream ifs;
	ifs.open("pacientes_prueba.csv");
	if (ifs.fail()) {
		cout << "ERROR: fichero no encontrado" << endl;
	}

	cout << "Finalizan las pruebas para abrir los archivos.csv" <<endl;
}

void PruebasMostrarMayores () {

	cout << "Comienzan las pruebas de mostrarMayores" <<endl;

	// Crear las variables que nos hacen falta para probar el algoritmo

	EnsayoClinico *e1 = new EnsayoClinico;
	BSTree<KeyValue<string, Paciente*> > *a1 = new BSTree<KeyValue<string, Paciente*>>;
	BSTree<KeyValue<string, Paciente*> > *a2 = new BSTree<KeyValue<string, Paciente*>>;
	Paciente *p1 = new Paciente ("Juan", "233244");
	Paciente *p2 = new Paciente ("Sandra", "1866832");
	ListaDPI <Paciente*> *l1 = new ListaDPI<Paciente*>;
	ListaDPI <Paciente*> *l2 = new ListaDPI<Paciente*>;
	int cuantos;

	// Insertar a los árboles, los pacientes

	a1->insertar(KeyValue<string, Paciente*>(p1->getNombre(), p1));
	a2->insertar(KeyValue<string, Paciente*>(p2->getNombre(), p2));

	// Primera prueba en la que ponemos n=0, por lo cual no debería mostrar ningún paciente
	cuantos = 0;

	l1->moverPrimero();
	l1->consultar(p1);
	e1->mostrarMayores(cuantos);
	// Y al llamar al "mostrarMayores" no debería de salir nada por pantalla

	// Segunda prueba en la que ponemos n=400 > 199, por lo que no deben de salir pacientes
	cuantos = 400;

	l1->moverPrimero();
	l1->consultar(p1);
	e1->mostrarMayores(cuantos);
	// Y al llamar al "mostrarMayores" no debería de salir nada por pantalla

	//Tercera prueba en la que vamos a mostrar los dos pacientes creamos en orden
	cuantos = 2;

	l2->moverPrimero();
	l2->consultar(p1);
	if (p1->getNombre() != "Juan")
		cerr << "Error al insertar el paciente con más puntuación" <<endl;
	l2->avanzar();
	l2->consultar(p2);
	if (p2->getNombre() != "Sandra")
		cerr << "Error al insertar el siguiente paciente con mayor puntuación" <<endl;

	delete l1;
	delete l2;
	delete p1;
	delete p2;
	delete e1;

	cout << "Finalizan las pruebas de mostrarMayores" <<endl;
}

void PruebasMostrarApellidos() {

	cout << "Comienzan las pruebas de mostrar pacientes por apellidos" <<endl;

	EnsayoClinico *e2 = new EnsayoClinico;
	BSTree<KeyValue<string, Paciente*> > *a3 = new BSTree<KeyValue<string, Paciente*>>;
	Paciente *p3 = new Paciente ("Darío", "Martínez", "233244", 24, Hombre);
	Paciente *p4 = new Paciente ("Luís", "López", "1866832", 21, Hombre);
	string apellidos;
	string s_apellido;

	a3->insertar(KeyValue<string, Paciente*>(p3->getApellidos(), p3));
	a3->insertar(KeyValue<string, Paciente*>(p4->getApellidos(), p4));

	e2->mostrarPorApellido(s_apellido);

	if (p3->getApellidos() == "Maldonado")
		cerr << "Error ya que dicho apellido no existe en nuestro árbol"<<endl;
	if (p4->getApellidos() != "López")
		cerr << "Error al obtener el apellido del paciente"<<endl;

	delete e2;
	delete a3;
	delete p3;
	delete p4;

	cout << "Finalizan las pruebas de mostrar pacientes por apellidos" <<endl;

}

void PruebasMostrarPorDni () {

	cout << "Comienzan las pruebas de mostrar pacientes por su DNI" <<endl;

	EnsayoClinico *e3 = new EnsayoClinico;
	BSTree<KeyValue<string, Paciente*> > *a4 = new BSTree<KeyValue<string, Paciente*>>;
	Paciente *p5 = new Paciente ("Marta", "Bueno", "677456", 24, Mujer);
	Paciente *p6 = new Paciente ("Daniel", "Silva", "784994", 30, NoDefinido);
	string s_dni;

	a4->insertar(KeyValue<string, Paciente*>(p5->getDni(), p5));
	a4->insertar(KeyValue<string, Paciente*>(p6->getDni(), p6));

	e3->mostrarPorDNI(s_dni);

	if (p5->getDni() == "9098436")
		cerr << "Error ya que dicho DNI no existe en nuestro árbol"<<endl;
	if (p6->getDni() != "784994")
		cerr << "Error al obtener el DNI del paciente"<<endl;

	delete e3;
	delete a4;
	delete p5;
	delete p6;

	cout << "Finalizan las pruebas de mostrar pacientes por su DNI" <<endl;
}

void PruebasNumNiveles () {

	cout << "Comienzan las pruebas del número de niveles del árbol" <<endl;

	EnsayoClinico *e4 = new EnsayoClinico;
	BSTree<KeyValue<string, Paciente*> > *a5 = new BSTree<KeyValue<string, Paciente*>>;
	Paciente *p7 = new Paciente ("Antonia", "2256894");
	Paciente *p8 = new Paciente ("Daniel", "788958");


	e4->numNiveles();
	// Si por pantalla no se muestra un 0, daría error, porque el árbol está vacío

	a5->insertar(KeyValue<string, Paciente*>(p7->getNombre(), p7));
	a5->insertar(KeyValue<string, Paciente*>(p8->getNombre(), p8));

	if (!a5->estaVacio()) {
		e4->numNiveles();
		// Tiene que salir alguna cantidad mayor que 0, ya que ahora el árbol no está vacío
	}

	delete e4;
	delete a5;
	delete p7;
	delete p8;

	cout << "Finalizan las pruebas del número de niveles del árbol" <<endl;
}

void PruebasMostrarErrores () {

	cout << "Comienzan las pruebas de mostrar errores" <<endl;

	EnsayoClinico *e5 = new EnsayoClinico;
	BSTree<KeyValue<string, Paciente*> > *a6 = new BSTree<KeyValue<string, Paciente*>>;
	Paciente *p9 = new Paciente ("Raúl", "73927");
	Paciente *p10 = new Paciente ("Roberta", "112389");
	Paciente *p11 = new Paciente ("Julio", "468765");
	Paciente *p12 = new Paciente ("Arancha", "990464");

	a6->insertar(KeyValue<string, Paciente*>(p9->getDni(), p9));
	a6->insertar(KeyValue<string, Paciente*>(p10->getDni(), p10));

	e5->mostrarErrores();
	// Va a mostrar por pantalla los DNI que no sean ni de p9, ni de p10

	delete e5;
	delete a6;
	delete p9;
	delete p10;
	delete p11;
	delete p12;


	cout << "Finalizan las pruebas de mostrar errores" <<endl;
}








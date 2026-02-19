
#include "ensayoclinico.h"

// **************  // en Value estan los pacientes // en el Key está el DNI ******************

EnsayoClinico::EnsayoClinico() {
	this->nombre = "Sandra Maldonado Marín";

	this->arbolPacientes = new BSTree<KeyValue<string, Paciente*>>;
	this->ocupadas = 0;

	this->cargarPacientesVector(Vector);
	this->listaDeErrores = new ListaDPI<string>();
	this->anotar();
	//this->arbolDeErrores = new BSTree<string> ();

}

void EnsayoClinico::cargarPacientesVector(Paciente* Vector[MAX]) {
	ifstream ifs;
	string nombre;
	string apellidos;
	string DNI;
	string edad;  // Las lecturas no admiten otra lectura q no sea un tipo string
	int Edad;
	string genero;
	Paciente* p = nullptr;
	TipoGenero tg;

	ifs.open("pacientes_ordenados.csv");
	if (ifs.fail()) {
		cout << "ERROR: fichero no encontrado" << endl;
	}
	else {
		while (!ifs.eof()) {
			getline(ifs, DNI, ';');
			if (!ifs.eof()) {
				getline(ifs, nombre, ';');
				getline(ifs, apellidos, ';');
				getline(ifs, genero, ';');
				getline(ifs, edad, '\n');

				if (genero == "0") { //las comillas, pq no es tipo string
					tg = Hombre;
				}
				if (genero == "1") {
					tg = Mujer;
				}
				if (genero == "2") {
					tg = NoDefinido;
				}
				//tg = TipoGenero(stoi(genero))
				Edad = stoi(edad);
				p = new Paciente(nombre, apellidos, DNI, Edad, tg);

				this->Vector[ocupadas] = p;
				this->ocupadas++;

			}
		}
		ifs.close();
	}
	crearArbolPaciente(0, this->ocupadas-1);
}

void EnsayoClinico::crearArbolPaciente(int ini, int fin) {
	int medio;
	string DNI;
	Paciente *pac = nullptr;
	if (ini <= fin) {
			medio = (ini + fin) / 2;
			DNI = Vector[medio]->getDni(); // Se obtiene el DNI del paciente que voy a insertar
			pac = Vector[medio];

			KeyValue<string, Paciente*> dato(Vector[medio]->getDni(), Vector[medio]);
			arbolPacientes->insertar(dato);

			crearArbolPaciente(ini, medio-1);
			crearArbolPaciente(medio + 1, fin);
	}
}


bool EnsayoClinico::obtenerPaciente(string DNI, Paciente*& p) {
	bool enc = false;
	Paciente *pAUX = nullptr;

	if (!this->arbolPacientes->estaVacio()) {
		recorridoBuscarPacientePorDNI(this->arbolPacientes,DNI,pAUX);
		if (pAUX != nullptr) {
			p = pAUX;
			enc = true;
		}
	}
	return enc;
}

void EnsayoClinico::recorridoBuscarPacientePorDNI(BSTree<KeyValue<string, Paciente*>>* arbol, string DNI, Paciente* &p) {
	if (!arbol->estaVacio()) {

	// Si al obtener el keyvalue de este nodo y del keyvalue, al obtener el key (que es el DNI) coincide con el que estoy buscando
		if (arbol->getDato().getKey() == DNI){
			p = arbol->getDato().getValue(); // p apunta al paciente encontrado
		}
		else { // si no coincide el DNI
			if (DNI < arbol->getDato().getKey()){
				if (arbol->getIzq() != nullptr){
					recorridoBuscarPacientePorDNI(arbol->getIzq(), DNI, p);
				}
			}
			else {
				if (arbol->getDer() != nullptr) {
					recorridoBuscarPacientePorDNI(arbol->getDer(), DNI, p);
				}
			}
		}
	}
}

void EnsayoClinico::insertarListaOrden(ListaDPI<Paciente*> *l,Paciente *p) {
	Paciente *pAUX;
	bool enc = false;
	l->moverPrimero();
	while (!l->alFinal() && !enc) {
		l->consultar(pAUX);
		if (pAUX->getPuntuacion() >= p->getPuntuacion()) {
			enc =true;
		}
		else {
			l->avanzar();
		}
	}
	l->insertar(p);
}

void EnsayoClinico::recorridoMostrarMayores(BSTree<KeyValue<string, Paciente*> > *arbol, ListaDPI <Paciente*> *l, int cuantos, int &contador) { //recorrido in-orden
	Paciente *p1;
	Paciente *p2;

	if (!arbol->estaVacio()){
		if (arbol->getIzq() != nullptr) {
			recorridoMostrarMayores(arbol->getIzq(), l, cuantos, contador);
		}

		p1 = arbol->getDato().getValue();
		if (contador < cuantos) { // SE VAN A INSERTAR LOS 10 PRIMEROS MAYORES
			insertarListaOrden (l, p1);
			contador++;
		}
		else {
			l->moverPrimero();
			p2 = l->consultar();
			if (p1->getPuntuacion() > p2 ->getPuntuacion()) {
				l->eliminar(); // se elimina el que está el primero
				insertarListaOrden (l, p1); // y se inserta este nuevo en orden
			}
		}

		if (arbol->getDer() != nullptr) {
			recorridoMostrarMayores(arbol->getDer(), l, cuantos, contador);
		}
	}
}

void EnsayoClinico::mostrarMayores(int cuantos){
	ListaDPI<Paciente*> *l;
	int contador = 0;
	Paciente *p = nullptr;

	if (!this->arbolPacientes->estaVacio()) {
		l = new ListaDPI<Paciente*>();
		recorridoMostrarMayores(this->arbolPacientes, l, cuantos, contador);
		l->moverUltimo();

		while (!l->enPrimero()) {
			p = l->consultar();
			p->mostrarPuntuacion();
			l->retroceder();
		}
		p = l->consultar();
		p->mostrarPuntuacion();
		delete l;
	}
}

void EnsayoClinico::mostrarPorApellido(string s_apellido) {
	if (!arbolPacientes->estaVacio()) {
		recorridoSubCadenaDeApellidos(arbolPacientes, s_apellido);
	}
}

void EnsayoClinico::recorridoSubCadenaDeApellidos(BSTree<KeyValue<string, Paciente*> > *arbol, string s_apellido) {
	KeyValue<string, Paciente*> n;
	Paciente *paux = nullptr;
	string apellidos;

	if (!arbol->estaVacio()) {
		if (arbol->getIzq() != nullptr) {
			recorridoSubCadenaDeApellidos(arbol->getIzq(), s_apellido);
		}

		// Tratamiento de la raíz
		n = arbol->getDato();
		paux = n.getValue();
		apellidos = paux->getApellidos();
		if (apellidos.find(s_apellido) != -1) {
			paux->mostrarPuntuacion();
		}

		if (arbol->getDer() != nullptr) {
			recorridoSubCadenaDeApellidos(arbol->getDer(), s_apellido);
		}
	}
}

void EnsayoClinico::mostrarErrores() {
	 //Si muestro los errores por una LISTA
	listaDeErrores->moverPrimero();
	while (!listaDeErrores->alFinal()) {
		cout << listaDeErrores->consultar() <<endl;
		listaDeErrores->avanzar();
	}
}

void EnsayoClinico::recorridoMostrarArbolDeErrores(BSTree<string> *arbol) { // este modulo solo si muestro los errores a traves de un arbol
	if (!arbol->estaVacio()) {
		if (arbol->getIzq() != nullptr) {
			recorridoMostrarArbolDeErrores(arbol->getIzq());
		}

		if (arbol->getDer() != nullptr) {
			recorridoMostrarArbolDeErrores(arbol->getDer());
		}

		cout << arbol->getDato() <<endl;
	}
}

void EnsayoClinico::insertarSinRepeticiones(string DNI) {
	bool enc = false;
	listaDeErrores->moverPrimero();
	while (!listaDeErrores->alFinal() && !enc) {
		if (listaDeErrores->consultar() == DNI) {
			enc = true;
		}
		else { // Si se encuentra, no se inserta, paraque no haya repetidos
			listaDeErrores->avanzar();
		}
	}
	if (enc == false) { // Si no se encuentra, si que se inserta
		listaDeErrores->insertar(DNI);
	}
}

void EnsayoClinico::recorridoNiveles(BSTree<KeyValue<string, Paciente*> > *arbol, int nivActual,int &nivMaximo) {
	if (!arbol->estaVacio()) { // Por pantalla, tienen que salir que hay 8 niveles
		if (arbol->getIzq() != nullptr) {
			recorridoNiveles(arbol->getIzq(), nivActual+1, nivMaximo);
		}

		if (arbol->getDer() != nullptr) {
			recorridoNiveles(arbol->getDer(), nivActual+1, nivMaximo);
		}

		if (nivActual > nivMaximo) {
			nivMaximo = nivActual;
		}
	}
}

int EnsayoClinico::numNiveles() {
	int cuantos = 0;
	if (!arbolPacientes->estaVacio()) {
		recorridoNiveles(arbolPacientes, 1, cuantos);

	}
	return cuantos;
}

void EnsayoClinico::recorridoSubArbolDNI(BSTree<KeyValue<string, Paciente*> > *arbol, string s_dni, BSTree<KeyValue<string, Paciente*> > *&SUBarbol) {
	string DNI;
	KeyValue<string, Paciente*> n;
	if (!arbol->estaVacio()) {
		n = arbol->getDato();
		DNI = n.getKey();
		if (DNI.find(s_dni) == 0) {
			SUBarbol = arbol;
		}
		else {
			if (s_dni < DNI) {
				if (arbol->getIzq() != nullptr) {
					recorridoSubArbolDNI(arbol->getIzq(), s_dni, SUBarbol);
				}
			}
			else {
				if (arbol->getDer() != nullptr) {
					recorridoSubArbolDNI(arbol->getDer(), s_dni, SUBarbol);
				}
			}
		}
	}

}

void EnsayoClinico::mostrarEnOrdenDNI(BSTree<KeyValue<string, Paciente*> > *arbolPreOrden, string s_dni) {
	KeyValue<string, Paciente*> n;
	Paciente *paux;
	string DNI;
	if (!arbolPreOrden->estaVacio()) {
		n = arbolPreOrden->getDato();
		DNI = n.getKey();
		if (DNI.find(s_dni) == 0) {
			paux = n.getValue();
			paux->mostrarPuntuacion();
		}

		if (arbolPreOrden->getIzq() != nullptr) {
			mostrarEnOrdenDNI(arbolPreOrden->getIzq(), s_dni);
		}
		if (arbolPreOrden->getDer() != nullptr) {
			mostrarEnOrdenDNI(arbolPreOrden->getDer(), s_dni);
		}
	}

}

void EnsayoClinico::anotar() {
	ifstream ifs;
	string DNI;
	string puntuacion;
	Paciente* p = nullptr;

	ifs.open("ensayo.csv");
	if (ifs.fail()) {
		cout << "ERROR: fichero no encontrado" << endl;
	}
	else {
		while (!ifs.eof()) {
			getline(ifs, DNI, ';');
			if (!ifs.eof()) {
				getline(ifs, puntuacion, '\n');
				if (obtenerPaciente(DNI, p) == true) { // si al obtener el paciente por dni, me devuelve true
					p->setPuntuacion(stoi(puntuacion)); // se incrementa la puntuacion
				}
				else {
					//this->listaDeErrores->insertar(DNI);
					insertarSinRepeticiones (DNI); // se hace porque sino se insertan los errores duplicados muchas veces
				}
			}
		}
		ifs.close();
	}
}

void EnsayoClinico::mostrarPorDNI (string s_dni) {
	BSTree<KeyValue<string, Paciente*>>  *s_arbol = nullptr;
	if (!arbolPacientes->estaVacio()) {
		recorridoSubArbolDNI(arbolPacientes, s_dni, s_arbol);

		if (s_arbol != nullptr) {
			mostrarEnOrdenDNI(s_arbol, s_dni);
		}
	}
}

string EnsayoClinico::getNombre() {
	return this->nombre;
}

EnsayoClinico::~EnsayoClinico() {
	KeyValue <string, Paciente*> kv;
	Paciente* p;

	while (!arbolPacientes->estaVacio()) {
		kv = arbolPacientes->getDato();
		p = kv.getValue();
		arbolPacientes->eliminar(kv);
		delete p;
	}
	delete arbolPacientes;
	delete listaDeErrores;
}



#include "ColaPacientes.h"

ColaPacientes::ColaPacientes() {
	this->cp = new Cola <Paciente*>; // se pueden poner paréntesis
}

void ColaPacientes::insertar(Paciente* p) {
	this->cp->encolar(p);
}

int ColaPacientes::cuantos() {
	Paciente* p;
	Cola <Paciente*>* colaAux = new Cola <Paciente*>;
	int cont = 0;

	while (!this->cp->estaVacia()) { // para ir processando los datos, y se muestran por pantalla
		this->cp->getPrimero(p);
		this->cp->desencolar();
		cont++;
		colaAux->encolar(p);
	}
	while (!colaAux->estaVacia()) { // se devuelven los datos a la cola original
		p = colaAux->getPrimero();
		colaAux->desencolar();
		this->cp->encolar(p);
	}
	delete colaAux;
	return cont;
}

void ColaPacientes::obtener(Paciente*& p) {
	p = this->cp->getPrimero();
	this->cp->desencolar();
}

bool ColaPacientes::estaVacia() {
	return this->cp->estaVacia();
}

void ColaPacientes::mostrar() {
	// Pasando todo a la cola original de nuevo
	Paciente* p;
	Cola <Paciente*>* colaAux = new Cola <Paciente*>;

	while (!this->cp->estaVacia()) { // para ir processando los datos, y se muestran por pantalla
		this->cp->getPrimero(p);
		this->cp->desencolar();
		p->mostrar();
		colaAux->encolar(p);
	}
	while (!colaAux->estaVacia()) { // se devuelven los datos a la cola original
		p = colaAux->getPrimero();
		colaAux->desencolar();
		this->cp->encolar(p);
	}
	delete colaAux;
}

ColaPacientes::~ColaPacientes() {
	delete this->cp;
}

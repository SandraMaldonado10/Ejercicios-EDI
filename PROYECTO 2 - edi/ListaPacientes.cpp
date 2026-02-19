#include "ListaPacientes.h"

ListaPacientes::ListaPacientes() {
	this->lPacientes  = new ListaDPI <Paciente*>();
}

void ListaPacientes::insertarPorDNI(Paciente *p) {
	Paciente* paux = nullptr;
	bool enc = false;
	
	this->lPacientes->moverPrimero();
	while (!this->lPacientes->alFinal() && !enc) {
		paux = this->lPacientes->consultar();
		if (paux->getDni() > p->getDni()) {
			enc = true;
		}
		else {
			this->lPacientes->avanzar();
		}
	}
	this->lPacientes->insertar(p);
}

bool ListaPacientes::existePorDNI(string DNI) {
	Paciente* p = nullptr;
	bool existe = false;
	this->lPacientes->moverPrimero();
	while (!this->lPacientes->alFinal() && !existe) {
		lPacientes->consultar(p);
		if (p->getDni() == DNI) {
			existe = true;
		}
		else {
			lPacientes->avanzar();
		}
	}
	return existe;
}

bool ListaPacientes::obtenerPaciente(string DNI, Paciente *&p) {
	Paciente* paux = nullptr;
	bool existe = false;
	this->lPacientes->moverPrimero();
	while (!this->lPacientes->alFinal() && !existe) {
		lPacientes->consultar(paux);
		if (paux->getDni() == DNI) {
			existe = true;
			p = paux;
		}
		else {
			lPacientes->avanzar();
		}
	}
	return existe;
}

Paciente* ListaPacientes::obtenerPrimerPaciente() {
	Paciente* paux = nullptr;
	this->lPacientes->moverPrimero();
	this->lPacientes->consultar(paux);
	this->lPacientes->eliminar();
	return paux;
}

bool ListaPacientes::estaVacia() {
	return this->lPacientes->estaVacia();
}

int ListaPacientes::cuantosPacientes() {
	int cont = 0;
	this->lPacientes->enPrimero();
	if (!this->lPacientes->alFinal()) {
		cont++;
		this->lPacientes->avanzar();
	}
	return cont;
}

void ListaPacientes::mostrar() {
	Paciente* p = nullptr;
	lPacientes->moverPrimero();
	while (!this->lPacientes->alFinal()) {
		this->lPacientes->consultar(p);
		p->mostrar();
		this->lPacientes->avanzar();
	}
}

ListaPacientes::~ListaPacientes() {
	delete this->lPacientes;
}

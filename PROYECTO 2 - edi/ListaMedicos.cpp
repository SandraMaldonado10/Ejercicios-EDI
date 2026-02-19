#include "ListaMedicos.h"

ListaMedicos::ListaMedicos() {
	this->lMedicos = new ListaDPI <Medico*>();
}

void ListaMedicos::insertarPorApellido(Medico* m) {
	Medico* maux = nullptr;
	bool enc = false;

	this->lMedicos->moverPrimero();
	while (!lMedicos->alFinal() && !enc) {
		maux = this->lMedicos->consultar();
		if (maux->getApellidosMedico() > m->getApellidosMedico()) {
			enc = true;
		}
		else {
			this->lMedicos->avanzar();
		}
	}
	this->lMedicos->insertar(m);
}

bool ListaMedicos::existePorApellido(string apellidosMedico) {
	Medico* maux = nullptr;
	bool existe = false;
	lMedicos->moverPrimero();
	while (!lMedicos->alFinal() && !existe) {
		this->lMedicos->consultar(maux);
		if (maux->getApellidosMedico() == apellidosMedico) {
			existe = true;
		}
		else {
			this->lMedicos->avanzar();
		}
	}
	return existe;
}

bool ListaMedicos::obtenerMedico(string apellidosMedico, Medico *&m) {
	Medico* maux = nullptr;
	bool existe = false;
	this->lMedicos->moverPrimero();
	while (!this->lMedicos->alFinal() && !existe) {
		lMedicos->consultar(maux);
		if (maux->getApellidosMedico() == apellidosMedico) {
			existe = true;
			m = maux;
		}
		else {
			this->lMedicos->avanzar();
		}
	}
	return existe;
}

Medico* ListaMedicos::obtenerPrimerMedico() {
	Medico* maux = nullptr;
	this->lMedicos->moverPrimero();
	this->lMedicos->consultar(maux);
	this->lMedicos->eliminar();
	return maux;
}

bool ListaMedicos::estaVacia() {
	return this->lMedicos->estaVacia();
}

int ListaMedicos::cuantosMedicos() {
	int cont = 0;
	this->lMedicos->enPrimero();
	if (!this->lMedicos->alFinal()) {
		cont++;
		this->lMedicos->avanzar();
	}
	return cont;
}

void ListaMedicos::mostrar() {
	Medico* m;
	this->lMedicos->moverPrimero();
	while (!this->lMedicos->alFinal()) {
		this->lMedicos->consultar(m);
		m->mostrar();
		this->lMedicos->avanzar();
	}
}

Medico* ListaMedicos::obtenerMedPorEspecialidad(string especialidad) {
	Medico* maux = nullptr;
	bool existe = false;
	this->lMedicos->moverPrimero();
	while (!this->lMedicos->alFinal() && !existe) {
		lMedicos->consultar(maux);
		if (maux->getEspecialidad() == especialidad) {
			existe = true;
		}
		else {
			this->lMedicos->avanzar();
		}
	}
	return maux;
}

ListaMedicos::~ListaMedicos() {
	delete this->lMedicos;
}

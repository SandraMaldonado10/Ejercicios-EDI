#include "PilaInformes.h"

PilaInformes::PilaInformes() {
	this->pInformes = new Pila <Informe*>();
}

void PilaInformes::insertarInforme(Informe* in) { //el informe que tiene por par�metros lo mete dentro de la pila en la parte de arriba 
	this->pInformes->apilar(in);
}

Informe* PilaInformes::consultarInforme() {
	Informe* in;
	this->pInformes->getCima(in);
	return in;
}

void PilaInformes::consultarInforme(Informe*& in) {
	in = this->pInformes->getCima();
}

void PilaInformes::mostrarInformesTotales() {
	Pila <Informe*>* pilaAux = new Pila <Informe*>();
	Informe* in;

	while (!this->pInformes->estaVacia()) {  
		in = this->pInformes->getCima(); 
		in->mostrar();
		
		this->pInformes->desapilar(); 
		pilaAux->apilar(in); 
	}
	while (!pilaAux->estaVacia()) { 
		pilaAux->getCima(in);
		pilaAux->desapilar();
		this->pInformes->apilar(in);
	}
	delete pilaAux;
}

void PilaInformes::mostrarInformesMedico(string apellidos) {
	Pila <Informe*>* pilaAux = new Pila <Informe*>();
	Informe* in;
	Medico* m;

	while (!this->pInformes->estaVacia()) {  // miro si no est� vac�a
		in = this->pInformes->getCima(); // lo selecciono en la cima
		m = in->getMed(); // se obtiene el m�dico
		if (m->getApellidosMedico() == apellidos) { //miro si coinciden los apellidos del m�dico, con el que quiero
			in->mostrar(); // mostramos el informe
		}
		this->pInformes->desapilar(); // lo desapilo de la pila principal
		pilaAux->apilar(in); // lo apilo en la auxiliar
	}
	while (!pilaAux->estaVacia()) { // tengo que regresar los datos
		pilaAux->getCima(in);
		pilaAux->desapilar();
		this->pInformes->apilar(in);
	}
	delete pilaAux;
}

void PilaInformes::borrarInformesMedico(string apellidos) {
	Pila <Informe*>* pilaAux = new Pila <Informe*>();
	Informe* in;
	Medico* m;

	while (!this->pInformes->estaVacia()) {
		this->pInformes->getCima(in);
		this->pInformes->desapilar();
		m = in->getMed();
		if (m->getApellidosMedico() == apellidos) {
			delete in;
		}
		else {
			pilaAux->apilar(in);
		}
	}
	while (!pilaAux->estaVacia()) {
		pilaAux->getCima(in);
		pilaAux->desapilar();
		this->pInformes->apilar(in);
	}
	delete pilaAux;
}

bool PilaInformes::estaVacia() {
	return this->pInformes->estaVacia();
}

void PilaInformes::borrarPrimerInf() {
	this->pInformes->desapilar();
}

PilaInformes::~PilaInformes() {
}

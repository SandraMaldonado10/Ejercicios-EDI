#include "Informe.h"

Informe::Informe(){
	this->texto = "Vacío";
	this->med = nullptr;
}

Informe::Informe(string texto, FechaYHora fecha, Medico* med){
	this->texto = texto;
	this->fecha = fecha;
	this->med= med;
}

Informe::Informe(const Informe& in) {
	this->texto = in.texto;
	this->fecha = in.fecha;
	this->med = in.med;
}

void Informe::mostrar() {
	cout << "Mostrando el texto del informe: " << this->texto << endl;
	cout << "Mostrando fecha del informe: ";
	this->fecha.mostrar();
	cout << "Mostrando médico del informe: ";
	this->med->mostrar();
}

Informe::~Informe() {
	cout << "Iniciando destructor...:" << endl;
}

// GETTERS:
const FechaYHora& Informe::getFecha() const {
	return fecha;
}

Medico* Informe::getMed() const {
	return med;
}

const string& Informe::getTexto() const {
	return texto;
}


// SETTERS:
void Informe::setFecha(const FechaYHora& fecha) {
	this->fecha = fecha;
}

void Informe::setMed(Medico *med) {
	this->med = med;
}

void Informe::setTexto(const string& texto) {
	this->texto = texto;
}

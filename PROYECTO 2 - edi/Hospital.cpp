/*
 * Hospital.cpp
 *
 *  Created on: 26 feb. 2023
 *      Author: alumno
 */

#include "Hospital.h"

Hospital::Hospital() {
	this -> nombreHospital = "No asignado";
	this->lp = new ListaPacientes();
	this->lm = new ListaMedicos();
	this->s = new Servicio("Oftalmología");

	this->cargarPacientes();
	this->cargarMedicos();
	this->cargarInformes();
}

Hospital::Hospital(string nombreHospital) {
	this->nombreHospital = nombreHospital;
	this->lp = new ListaPacientes();
	this->lm = new ListaMedicos();
	this->s = new Servicio("Oftalmología");

	this->cargarPacientes();
	this->cargarMedicos();
	this->cargarInformes();
}

void Hospital::cargarMedicos(){
	ifstream ifs; //Flujo de lectura: comunica nuestro programa con un fichero de texto
	string nombre;
	string apellidos;
	string especialidad;
	Medico* m = nullptr;

	ifs.open("medicos.csv"); //Abre el fichero de texto que indiquemos para conectarlo con nuestro programa
	if (ifs.fail()) { // Si no se ha podido abrir el fichero de texto, hay error
		cout << "ERROR: fichero no encontrado" << endl;
	}
	else {
		while (!ifs.eof()) { // eof: end of file (devuelve true si el cursor se encuentra al final del fichero, es decir, hemos terminado)
			getline(ifs, nombre, ';'); // lee la linea, lee el nombre y llega hasta donde haya un ; en el texto
			if (!ifs.eof()) { // si no se llegó al final del fichero -> Es por si el fichero contiene lineas en blanco al final del mismo
				getline(ifs, apellidos, ';'); // vuelve a leer cuando encuentra otro ;
				getline(ifs, especialidad, '\n'); // vuelve a leer hasta que encuentra salto de linea

				m = new Medico(nombre, apellidos, especialidad);

				this->lm->insertarPorApellido(m);
			}
		}
		ifs.close();
	}
}

void Hospital::cargarPacientes(){
	ifstream ifs;
	string nombre;
	string apellidos;
	string DNI;
	string edad;  // Las lecturas no admiten otra lectura q no sea un tipo string
	string genero;
	Paciente* p = nullptr;
	TipoGenero tg;

	ifs.open("pacientes.csv");
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
				p = new Paciente(nombre, apellidos, DNI, stoi(edad), tg);
				this->lp->insertarPorDNI(p);
				this->s->insertar(rand() % 5, p); //rand crea un módulo aleatorio entre 0 y 4
			}
		}
		ifs.close();
	}
}

void Hospital::cargarInformes() {
	ifstream ifs;
	string DNI;
	string texto;
	string apellidos;
	string fecha;
	Informe* in;
	Paciente* p;
	Medico* m;


	ifs.open("informes.csv"); 
	if (ifs.fail()) { 
		cout << "ERROR: fichero no encontrado" << endl;
	}
	else {
		while (!ifs.eof()) { 
			getline(ifs, DNI, ';'); 
			if (!ifs.eof()) { 
				getline(ifs, texto, ';'); 
				getline(ifs, apellidos, '\n'); 
				getline(ifs, fecha, '\n');

				this->lp->obtenerPaciente(DNI,p);
				this->lm->obtenerMedico(apellidos, m);
				FechaYHora f(fecha);
				in = new Informe(texto, fecha, m);
				p->insertarInforme(in);
			}
		}
		ifs.close();
	}
}

void Hospital::mostrarPacientes() {
	this->lp->mostrar();
}


void Hospital::mostrarMedicos() {
	this->lm->mostrar();
}

void Hospital::mostrarEstadisticas() {
	cout << "Número de pacientes del hospital: " << this->lp->cuantosPacientes() << endl;
	cout << "Número de médicos del hospital: " << this->lm->cuantosMedicos() << endl;
	this->s->mostrarCantidadesColas();
}

void Hospital::mostrarEnEspera() {
	for (int i = 0; i < MAX_PRIORIDAD; i++) {
		this->s->mostrarPrioridad(i);
	}
}

bool Hospital::obtenerPaciente(string DNI, Paciente *&p) {
	return this->lp->obtenerPaciente(DNI, p);
}

bool Hospital::obtenerMedico(string apellidos, Medico *&m) {
	return this->lm->obtenerMedico(apellidos, m);
}

void Hospital::medicoDelServicio() {
	string especialidad;
	especialidad = this->s->getEspecialidad();
	Medico* m;

	m = this->lm->obtenerMedPorEspecialidad(especialidad);
	this->s->setMedico(m);
}

void Hospital::procesarPacientes() {
	if (s->getMedico() != nullptr) {
		cout << "Los pacientes de cada cola: " << endl;
		s->mostrarCantidadesColas();
		s->procesarColas();
		cout << "---------------------" << endl;
		cout << "Los pacientes de cada cola: " << endl;
		s->mostrarCantidadesColas();
	}
	else {
		cout << "No se procesa, porque no hay ningún médico asignado al servicio" << endl;
	}
}

Hospital::~Hospital() { //destructor
	Medico *m;
	while (!this -> lm -> estaVacia ()) {
		m = this -> lm -> obtenerPrimerMedico ();
		delete m;
	}

	Paciente *p;
	while (!this -> lp -> estaVacia ()) { // lp en verdad no es una lista, es un gestor de una lista
		p = this -> lp -> obtenerPrimerPaciente ();
		delete p;
	}
	delete this->s;
}
// HACER ESTE GET Y SET BIEN
const string& Hospital::getNombre() const {
	return this->nombreHospital;
}

void Hospital::setNombre(const string& nombre) {

}

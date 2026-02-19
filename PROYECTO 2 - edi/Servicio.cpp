#include "Servicio.h"

Servicio::Servicio() { // con esto cada una de las casillas, crea una nueva cola
	this->especialidad = "Vacío";
	for (int i = 0; i < MAX_PRIORIDAD; i++) {
		this->colaPP[i] = new ColaPacientes(); // la i es un puntero a la cola
	}
	this->med = nullptr;
}

Servicio::Servicio(string especialidad) {
	this->especialidad = especialidad;
	for (int i = 0; i < MAX_PRIORIDAD; i++) {
		this->colaPP[i] = new ColaPacientes(); // la i es un puntero a la cola
	}
	this->med = nullptr;
}

string Servicio::obtenerFecha() { // devuelve la fecha y hora del sistema. Para opción 8
	time_t t = std::time(nullptr);
	tm* now = std::localtime(&t);

	char buffer[128];
	string data;
	strftime(buffer, sizeof(buffer), "%d/%m/%Y %X", now);
	return buffer;
}

void Servicio::insertar(int prioridad, Paciente* p) {
	this->colaPP[prioridad]->insertar(p);
}

bool Servicio::estaVaciaPrioridad(int prioridad) {	
	return this->colaPP[prioridad]->estaVacia(); // a esto se le llama asociacion y agregacion de clases
}

bool Servicio::estaVacia() { // devuelve si están vacias en todas
	bool esta = false;
	int i = 0;
	while (i < MAX_PRIORIDAD && !esta) {
		if (!this->colaPP[i]->estaVacia()) {
			esta = true;
		}
		else {
			i++;
		}
	}
	return !esta;
}

void Servicio::mostrarPrioridad(int prioridad) { // mostrar los pacientes de una determinada prioridad
	this->colaPP[prioridad]->mostrar();
}

void Servicio::mostrar() { // muestra los pacientes de todas las colas
	int i;
	for (i = 0; i < MAX_PRIORIDAD; i++) {
		this->colaPP[i]->mostrar();
	}
}

void Servicio::mostrarCantidadesColas() {
	for (int i = 0; i < MAX_PRIORIDAD; i++) {
		cout << "Dentro de la prioridad " << i << "hay" << this->colaPP[i]->cuantos() << "pacientes" << endl;
	}
}

void Servicio::procesarColas() {
	Paciente* p;
	string texto;
	for (int i = 0; i < MAX_PRIORIDAD; i++) {
		while (!this->colaPP[i]->estaVacia()) {
			this->colaPP[i]->obtener(p);
			texto = "Paciente atendido en " + this->especialidad + "por el médico " + this->med->getNombre() + " " + this->med->getApellidosMedico();
			FechaYHora fecha(obtenerFecha());
			p->insertarInforme(new Informe(texto, fecha, med));
		}
	}
}

Servicio::~Servicio() { // se hace un delete a cada una de las colas
	int i;
	for (i = 0; i < MAX_PRIORIDAD; i++) {
		delete this->colaPP[i];
	}
}

//   GETTERS:
Medico* Servicio::getMedico() {
	return med;
}

const string& Servicio::getEspecialidad() const {
	return especialidad;
}

//   SETTERS:
void Servicio::setMedico(Medico* medico) {
	this->med = med;
}

void Servicio::setEspecialidad(const string& especialidad) {
	this->especialidad = especialidad;
}


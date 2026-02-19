//============================================================================
// Name        : Entrega 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Hospital.h"
using namespace std;

// Muestra el menu por pantalla y devuelve una opcion elegida.
int menu(string nombre) {

    int opcion;

    do {
        cout << endl;
        cout << "--------  " << nombre << "  --------" << endl << endl;

        cout << "     1. Mostrar Estadísticas                     " << endl;
        cout << "     2. Mostrar Pacientes                        " << endl;
        cout << "     3. Mostrar Médicos                          " << endl;
        cout << "     4. Mostrar Pacientes en Espera              " << endl;
        cout << "     5. Mostrar informes del paciente por su DNI " << endl;
        cout << "     6. Mostrar médico según su apellido         " << endl;
        cout << "     7. Asignar médico a un servicio             " << endl;
        cout << "     8. Procesamiento de pacientes               " << endl;

        cout << "     0. Finalizar.                               " << endl;
        cout << "                        Opción:  ";

        cin >> opcion;
        cin.ignore();

    } while ((opcion < 0) || (opcion > 8));

    return opcion;
}


// Programa principal:
int main() {

    Hospital* hospital = nullptr;
    bool       salir = false;
    int        opcion;
    string DNI;
    string apellidos;
    Paciente* p;
    Medico* m;
    srand(1992);

    // 1. Crear hospital (los datos se cargan automáticamente).
    hospital = new Hospital ("San Pedro de Alcántara");

    // 2. Muestra el menú hasta que  "salir" sea true

    while (!salir) {
        opcion = menu(hospital->getNombre());

        switch (opcion) {
        case 1:
            hospital->mostrarEstadisticas();
            break;

        case 2:
            hospital->mostrarPacientes();
            break;

        case 3:
            hospital->mostrarMedicos();
            break;
        case 4:
            hospital->mostrarEnEspera();
            break;

        case 5:
            cout << "Introducir DNI del paciente que hay que buscar: " << endl;
            cin >> DNI;
            if (hospital->obtenerPaciente(DNI, p)) {
                p->mostrar();
                p->mostrarInformes();
            }
            else {
                cout << "No existe ningún paciente con dicho DNI: " << DNI << endl;
            }
            break;

        case 6:
            cout << "Introducir apellidos del médico que hay que buscar: " << endl;
            cin >> apellidos;
            if (hospital->obtenerMedico(apellidos, m)) {
                m->mostrar();
            }
            else {
                cout << "No existe ningún médico con dicho apellido" << endl;
            }
            break;

        case 7:
            hospital->medicoDelServicio();
            break;

        case 8:
            hospital->procesarPacientes();
            break;

        case 0:
            salir = true;
            break;

        default:
            break;

        }

    }

    // 3. Elimina hospital (los datos se almacenan automáticamente).
    delete hospital;

    return 0;
}

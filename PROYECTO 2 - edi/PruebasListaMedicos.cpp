/*
 * PruebasListaMedicos.h
 *
 *  Created on: 4 abr. 2023
 *      Author: alumno
 */

#include "ListaMedicos.h"

void probarListaMedicos() {

    cout << "Comienzan las pruebas de ListaMedicos" << endl;

    // Creamos una lista de médicos
    ListaMedicos* lista = nullptr;

    // Creamos algunos médicos
    Medico* medico1 = new Medico("Juan", "Pérez", "Cardiología");
    Medico* medico2 = new Medico("María", "Gómez", "Pediatría");
    Medico* medico3 = new Medico("Carlos", "López", "Oncología");

    // Insertamos los médicos en la lista por orden alfabético de apellido
    lista->insertarPorApellido(medico2);
    lista->insertarPorApellido(medico1);
    lista->insertarPorApellido(medico3);

    // Mostramos la lista de médicos
    lista->mostrar();

    // Comprobamos si existe un médico con un apellido determinado
    if (lista->existePorApellido("Gómez")) {
        cout << "Sí existe un médico con apellido Gómez" << endl;
    }
    else {
        cout << "No existe un médico con apellido Gómez" << endl;
    }

    // Obtenemos un médico por su apellido
    Medico* medicoEncontrado;
    if (lista->obtenerMedico("Pérez", medicoEncontrado)) {
        cout << "Se encontró al médico con apellido Pérez" << endl;
        medicoEncontrado->mostrar();
    }
    else {
        cout << "No se encontró al médico con apellido Pérez" << endl;
    }

    // Obtenemos el primer médico de la lista
    Medico* primerMedico = lista->obtenerPrimerMedico();
    cout << "El primer médico de la lista es:" << endl;
    primerMedico->mostrar();

    // Comprobamos si la lista está vacía
    if (lista->estaVacia()) {
        cout << "La lista de médicos está vacía" << endl;
    }
    else {
        cout << "La lista de médicos no está vacía" << endl;
    }

    // Obtenemos un médico por su especialidad
    Medico* medicoPorEspecialidad = lista->obtenerMedPorEspecialidad("Cardiología");
    cout << "El médico con especialidad Cardiología es:" << endl;
    medicoPorEspecialidad->mostrar();

    // Liberamos la memoria de los médicos creados
    delete medico1;
    delete medico2;
    delete medico3;

    cout << "Finalizan las pruebas de ListaMedicos" << endl;
}
/*
 * PruebasListaPacientes.h
 *
 *  Created on: 4 abr. 2023
 *      Author: alumno
 */

#include "PruebasListaPacientes.h"

void probarListaPacientes() {
   
    Paciente* p1 = new Paciente("Juan", "12345678A");
    Paciente* p3 = new Paciente("Ana", "11111111C");
    Paciente* p4 = new Paciente("María", "99999999D");

    ListaPacientes* lista = nullptr;
    lista->insertarPorDNI(p1);
    lista->insertarPorDNI(p3);

    if (lista->cuantosPacientes() != 2) {
        cout << "Error al contar la cantidad de pacientes" << endl;
    }
    if (lista->existePorDNI("12345678A") != true)
        cerr << "Error al comprobar si existe el paciente por DNI" << endl;
    if (lista->existePorDNI("11111111C") != true)
        cerr << "Error al comprobar si existe el paciente por DNI" << endl;
    if (lista->existePorDNI("99999999D") != false) 
        cerr << "Error al comprobar si existe el paciente por DNI" << endl;

    Paciente* p = nullptr;
    bool encontrado = lista->obtenerPaciente("12345678A", p);
    if (encontrado != true)
        cerr << "Error al obtener el paciente por DNI" << endl;

    Paciente* p5;
    p5 = lista->obtenerPrimerPaciente();
    if (p5 != p1)
        cerr << "Error al obtener el primer paciente" << endl;

    cout << "Lista de pacientes:" << endl;
    lista->mostrar();

    delete p1;
    delete p3;
    delete p4;

}
/*
 * PruebasVOVPacientes.h
 *
 *  Created on: 8 mar. 2023
 *      Author: alumno
 */

#ifndef PRUEBASVOVPACIENTES_H_
#define PRUEBASVOVPACIENTES_H_
#include "VoVPacientes.h"
#include "Paciente.h"
#include <iostream>

/**
 *  CONSTRUCTOR POR DEFECTO - GETTERS:
 *           CASO 1 ---------------------> VoVPacientes vovP1 ---------> vovP1.getOcupadas()
 *                                                                       Da error si es distinto de 0, porque el vector recién creado debe ser igual a 0
 *  INSERTAR:
 *           CASO 2:  1- En la primera prueba, he creado un puntero del vector de pacientes, y un paciente p1, mediante un constructor parametrizado
 *                    2- He insertado ese paciente p1
 *                    3- Y si la insercción fue incorrecta, al obtener las ocupadas, no pueden ser distintas a 1.
 *                    4- He creado otro paciente p2, haciendo la misma prueba, pero mediante otro constructor parametrizado.
 *
 *  BORRAR:
 *  		CASO 3:   1- Creamos un puntero del vector pacientes, y dos pacientes, p1 y p2
 *  				  2- Le asignamos una posición a cada paciente.
 *  				  3- Borramos los dos pacientes, y lo comprobamos obteniendo las ocupadas.
 *  				  4- Al borrar el primer paciente, si las ocupadas son distintas de 1, da error
 *  				     Y al borrar el segundo paciente, si las ocupadas son distintas de 0, da error
 *					  5- Y para finalizar,comprobamos que el puntero al vector que hemos creado, esté vacío, si no es así dará error.
 *                       (con estas pruebas, también hemos probado el getOcupadas, getPosicion y estaVacio, por lo que no es necesario hacer otro módulo de prueba que se centre en ello)
 *
 *  ESTALLENO:
 *          CASO 4:   1- Creamos un puntero al vector de pacientes.
 *          		  2- Comprobamos que ese vector no esté lleno, ya que lo acabamos de crear y debería de estar vacío
 *          		  3- Insertamos pacientes hasta llenas la lista (MAXPACIENTES)
 *          		  4- Y en el siguiente for, borramos algunos de ellos.
 *          		  5- Para finalizar comprobamos que el vector no esté lleno, ya que supuestamente borró algunos pacientes.
 *
 */

void probarConstructorPorDefectoP ();
void probarInsertarP ();
void probarBorrarP ();
void probarEstaLlenoP ();

#endif /* PRUEBASVOVPACIENTES_H_ */

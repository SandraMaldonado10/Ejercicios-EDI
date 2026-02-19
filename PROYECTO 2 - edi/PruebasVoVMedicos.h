/*
 * PruebasVoVMedicos.h
 *
 *  Created on: 10 mar. 2023
 *      Author: alumno
 */

#ifndef PRUEBASVOVMEDICOS_H_
#define PRUEBASVOVMEDICOS_H_
#include "VoVMedicos.h"
#include "Medico.h"
#include <iostream>

/**
 *  CONSTRUCTOR POR DEFECTO - GETTERS:
 *           CASO 1 ---------------------> VoVMedicos vovM1 ---------> vovM1.getOcupadas()
 *                                                                       Da error si es distinto de 0, porque el vector recién creado debe ser igual a 0
 *  INSERTAR:
 *           CASO 2:  1- En la primera prueba, he creado un puntero del vector de médicos, y un médico m1, mediante un constructor parametrizado
 *                    2- He insertado ese médico m1
 *                    3- Y si la insercción fue incorrecta, al obtener las ocupadas, no pueden ser distintas a 1.
 *                    4- He creado otro médico m2, haciendo la misma prueba.
 *
 *  BORRAR:
 *  		CASO 3:   1- Creamos un puntero del vector médicos, y dos médicos, m1 y m2
 *  				  2- Le asignamos una posición a cada médico.
 *  				  3- Borramos los dos médicos, y lo comprobamos obteniendo las ocupadas.
 *  				  4- Al borrar el primer médico, si las ocupadas son distintas de 1, da error
 *  				     Y al borrar el segundo médico, si las ocupadas son distintas de 0, da error
 *					  5- Y para finalizar,comprobamos que el puntero al vector que hemos creado, esté vacío, si no es así dará error.
 *                       (con estas pruebas, también hemos probado el getOcupadas, getPosicion y estaVacio, por lo que no es necesario hacer otro módulo de prueba que se centre en ello)
 *
 *  ESTALLENO:
 *          CASO 4:   1- Creamos un puntero al vector de médicos.
 *          		  2- Comprobamos que ese vector no esté lleno, ya que lo acabamos de crear y debería de estar vacío
 *          		  3- Insertamos pacientes hasta llenas la lista (MAXMEDICOS)
 *          		  4- Y en el siguiente for, borramos algunos de ellos.
 *          		  5- Para finalizar comprobamos que el vector no esté lleno, ya que supuestamente borró algunos médicos.
 *
 */

void probarConstructorPorDefectoM ();
void probarInsertarM ();
void probarBorrarM ();
void probarEstaLlenoM ();


#endif /* PRUEBASVOVMEDICOS_H_ */

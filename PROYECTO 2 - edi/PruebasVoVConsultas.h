/*
 * PruebasVoVConsultas.h
 *
 *  Created on: 8 mar. 2023
 *      Author: alumno
 */

#ifndef PRUEBASVOVCONSULTAS_H_
#define PRUEBASVOVCONSULTAS_H_
#include "VoVConsultas.h"
#include <iostream>

/**
 *
 *  CONSTRUCTOR POR DEFECTO - GETTERS:
 *
 *          CASO 1:  1- Creamos un puntero del vector consulta.
 *                   2- Comprobamos si el vector no tiene las ocupadas=0, da un error, ya que un vector recién creado, debe estar vacío
 *
 *  INSERTAR EN ORDEN Y BORRAR:
 *
 *          CASO 2:  1- Creamos un puntero del vector consulta, y a continuación, 3 pacientes, 3 médicos y 3 objetos distintos de fecha y hora, para tener varias pruebas con valores distintos.
 *          		 2- Además creamos 3 punteros a consultas, con los datos anteriores
 *          		 3- Comprobamos que el insertar en orden funcione, para ello lo implementamos
 *          		 4- Comprobamos que el getOcupadas no sea distinto de 3, ya que si fuera así, daría error en la inserción
 *          		 5- También, recorre todo el vector y lo muestra por pantalla
 *          		 6- Comprobamos con estaVacio que el vector no esté vacío, ya que sino daría error
 *          		 7- Además comprobamos con estaLleno que no esté lleno, porque con esas 3 consultas, no puede llenarse el vector, sino también daría error
 *          		 8- Para probar el borrado, lo implementamos en las 3 posiciones de los punteros
 *          		 9- Y por último, comprobamos que el vector haya quedado vacío con el getOcupadas, si fuera distinto de 0, daría error
 *

 *
 */

void probarConstructorPorDefectoC ();
void probarInsertarOrdenYBorrarC ();

#endif /* PRUEBASVOVCONSULTAS_H_ */

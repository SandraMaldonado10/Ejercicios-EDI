/*
 * PruebasMedico.h
 *
 *  Created on: 8 mar. 2023
 *      Author: alumno
 */

#ifndef PRUEBASMEDICO_H_
#define PRUEBASMEDICO_H_
#include "Medico.h"
#include <iostream>

/**
 *
 * CONSTRUCTOR POR DEFECTO - GETTERS:
 *    CASO 1 -------> Medico m1  -------------------------------------------------------> getNombre () -------------> getApellidosMedico() ----> getEspecialidad ()
 *                                                                                       "Sin asignar"                  "Sin asignar"                "Sin asignar"
 * CONSTRUCTOR PARAMETRIZADO - GETTERS:
 *    CASO 2 -------> Medico m2 ("Rigoberto","Pérez", "Matasanos del coco") ------------> getApellidosMedico () ----> getEspecialidad () ------> getNombre ()
 *                                                                                            "Pérez"               "Matasanos del coco"        "Rigoberto"
 * CONSTRUCTOR POR COPIA - GETTERS:
 *	  CASO 3 -------> Medico m3=m2 -----------------------------------------------------> getEspecialidad() --------> getNombre() -------------> getApellidosMedico ()
 *                                                                                       "Matasanos del coco"         "Rigoberto"               "Matasanos del coco"
 *
 * SETTERS:
 *	  CASO 4 -------> m2.setEspecialidad ("Estira pellejos") ----> m3.setNombre ("Valentino") ----> m1.setApellidosMedico ("Galeana")
 *                         "Estira pellejos"                             "Valentino"                        "Galeana"

 */


void probarClaseMedico ();


#endif /* PRUEBASMEDICO_H_ */

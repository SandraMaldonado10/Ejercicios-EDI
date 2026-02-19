/*
 * PruebasPaciente.h
 *
 *  Created on: 7 mar. 2023
 *      Author: alumno
 */

#ifndef PRUEBASPACIENTE_H_
#define PRUEBASPACIENTE_H_
#include "Paciente.h"
#include <iostream>

 /**
  * CONSTRUCTOR POR DEFECTO - GETTERS:
  *    CASO 1 -------> Paciente p1  -------------------------------------------------------> getNombre () ----> getApellidos() ----> getGenero () 
  *                                                                                         "No asignado"        "No asignado"        NoDefinido   
  * CONSTRUCTOR PARAMETRIZADO - GETTERS:
  *    CASO 2 -------> Paciente p2 ("Manuel", "Cerro Torres", "55257575H", 17, Hombre) ----> getNombre () ----> getEdad () --------> getGenero () ----> getApellidos()
  *                                                                                           "Manuel"             17                   Hombre           "Cerro Torres"
  * CONSTRUCTOR POR COPIA - GETTERS:                                                         
  *	  CASO 3 -------> Paciente p3=p2 -----------------------------------------------------> getApellidos() --> getGenero() -------> getEdad ()
  *                                                                                          "Cerro Torres"       Hombre               17
  *
  * SETTERS:
  *	  CASO 4 -------> p2.setDni ("21008792A") ----> p3.setGenero (Mujer) ----> p2.setEdad (6)
  *                         "21008792A"                  Mujer                     6
  *
  */

void probarClasePaciente();


#endif /* PRUEBASPACIENTE_H_ */



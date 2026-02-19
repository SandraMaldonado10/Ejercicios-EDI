/*
 * PruebasConsulta.h
 *
 *  Created on: 8 mar. 2023
 *      Author: alumno
 */

#ifndef PRUEBASCONSULTA_H_
#define PRUEBASCONSULTA_H_
#include "Consulta.h"
#include "Paciente.h"
#include "Medico.h"

#include <iostream>

 /**
  * CONSTRUCTOR POR DEFECTO - GETTERS:
  *       CASO 1    -------->  Consulta c1 ---------------------------------------->  getTipo ()  -------------> getFechaYHora () --------->  getInforme ()
  *                                                                                   Pendiente                  2, 1, 6, 2, 3                  " "
  * CONSTRUCTOR PARAMETRIZADO - GETTERS:
  *       CASO 2    -------->  Consulta *c2 (p, m, "22/05/2023 14:15", Urgente) --->  getPaciente () ----------> getFechaYHora () --------->  getMedico ()
  *                                                                                        p                    "22/05/2023 14:15"               m
  * SETTERS:
  *       CASO 3    -------->  Consulta c3 ---------------->  c3.setInforme ("Consulta realizada") --------> c3.setAlta(true) ----> c3.setTipo(Externa)
  *                                                                  "Consulta realizada"                        true                     Externa
  *
  */

void probarClaseConsulta();


#endif /* PRUEBASCONSULTA_H_ */

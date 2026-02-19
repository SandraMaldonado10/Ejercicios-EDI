/*
 * PruebasColaPacientes.h
 *
 *  Created on: 4 abr. 2023
 *      Author: alumno
 */

#ifndef PRUEBASINFORME_H_
#define PRUEBASINFORME_H_
#include "Informe.h"
#include <iostream>

/*

CONSTRUCTOR POR DEFECTO - GETTERS:
      CASO 1 -------> Informe *i1  -------------------------------------------------------------> getTexto () ----------------------> getMed() 
                                                                                                    "Vacío"                           nullptr   
   CONSTRUCTOR PARAMETRIZADO - GETTERS:
      CASO 2 -------> Informe *i2 ("El paciente se queja de dolor intenso", "Salas") -----------> getTexto() -----------------------> getMed () 
                                                                                        "El paciente se queja de dolor intenso"       "Salas"  
   CONSTRUCTOR POR COPIA - GETTERS:
  	  CASO 3 -------> Informe *i4 ("Rehabilitación 3 meses", "Salas") --------------------------> getMed() -------------------------> getTexto() 
                      Informe *i3 = i4                                                             "Salas"                       "Rehabilitación 3 meses"                
   SETTERS:
  	  CASO 4 -------> i2->setMed ("Galeana") ----> i3->setTexto ("Lesión de ligamento cruzado anterior") ---------------------------> i3->setTexto("Reposo relativo durante 2 semanas")
                           "Galeana"                     "Lesión de ligamento cruzado anterior"                                            "Reposo relativo durante 2 semanas"
  

*/



#endif /* PRUEBASINFORME_H_ */
/*
 * PruebasColaPacientes.h
 *
 *  Created on: 4 abr. 2023
 *      Author: alumno
 */

#ifndef PRUEBASCOLAPACIENTES_H_
#define PRUEBASCOLAPACIENTES_H_
#include "ColaPacientes.h"
#include <iostream>

/*

   CONSTRUCTOR POR DEFECTO -->  1º Crear una cola mediante el constructor por defecto, por lo que esta cola debe estar vacía. 
								2º Comprobar que esta cola esté vacía mediante su módulo "estaVacia".
								3º Si se cumple, el constructor por defecto funciona correctamente, y sino da error
	

   INSERTAR ----------------->  1º Crear una cola por defecto, por lo que inicialmente está vacía.
								2º Crear un paciente, el cual lo insertamos en la cola, mediante su módulo "insertar".
								3º Comprobar que la cola no esté vacía ya que hemos insertado anteriormente el paciente. Si está vacía, da error.
								4º Para finalizar, eliminar el psciente, y comprobar de la misma manera si despues de esto, está vacía la cola. Si no está vacía dará error.
   
   CUANTOS ------------------>  PRIMER CASO: 1º Crear una cola por defecto, por lo que inicialmente está vacía.
											 2º Crear una cola auxiliar a la cual se van a pasar los datos de la original a esta.
											 3º Crear e insertar el paciente en la cola original, e implementar "cuantos" a la cola original
											 4º Comprobar que la cola no esté vacía. Si estuviera vacía, daría error al insertar el paciente
											 5º Comprobar también, si la cola auxiliar está vacía, ya que si no está vacía, da error al hacer el módulo "cuantos"
						      SEGUNDO CASO:  1º Crear una cola por defecto, por lo que inicialmente está vacía.
								    		 2º Crear una cola auxiliar a la cual se van a pasar los datos de la original a esta.
											 3º Implementar el módulo "cuantos" a la cola original
											 4º Comprobar que la cola esté vacía, ya que no se insertó ningún paciente en ella. Si no está vacía, dara error al crear la cola por defecto. 


   OBTENER ------------------>  1º Crear una cola por defecto, por lo que inicialmente estará vacía
								2º Crear un paciente, el cual se obtiene en dicha cola.
								3º Comprobar si la cola está vacía, si lo está el paciente fue correctamente obtenido, ya que el módulo obtiene el primero y lo borra, por lo que se queda la cola borrada.

   MOSTRAR ------------------>  PRIMER CASO:  1º Crear una cola por defecto, por lo que inicialmente está vacía
											  2º Crear una cola auxiliar a la cual se van a pasar los datos de la original a esta.
											  3º Crear e insertar el paciente en la cola original, e implementar "mostrar" a la cola original.
											  4º Comprobar que la cola no esté vacía. Si estuviera vacía, daría error al insertar el paciente
											  5º Comprobar también, si la cola auxiliar está vacía, ya que si no está vacía, da error al hacer el módulo "mostrar".
								SEGUNDO CASO: 1º Crear una cola por defecto, por lo que inicialmente está vacía.
								    		  2º Crear una cola auxiliar a la cual se van a pasar los datos de la original a esta.
											  3º Implementar el módulo "mostrar" a la cola original
											  4º Comprobar que la cola esté vacía, ya que no se insertó ningún paciente en ella. Si no está vacía, dara error al crear la cola por defecto. 

	DESTRUCTOR -------------->  1º Crear una cola por defecto, popr lo que inicialmente va a estar vacía
								2º Eliminar dicha cola
								3º Comprobar si está vacía la cola, si no lo está dará error en el destructor


*/ 


#endif /* PRUEBASCOLAPACIENTES_H_ */
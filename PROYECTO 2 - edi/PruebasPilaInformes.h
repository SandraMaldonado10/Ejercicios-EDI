/*
 * PruebasColaPacientes.h
 *
 *  Created on: 4 abr. 2023
 *      Author: alumno
 */

#ifndef PRUEBASPILAINFORMES_H_
#define PRUEBASPILAINFORMES_H_
#include "PilaInformes.h"
#include <iostream>

/*

   CONSTRUCTOR POR DEFECTO -->  1º Crear una pila de informes mediante el constructor por defecto, por lo que esta pila debe estar vacía. 
								2º Comprobar que esta pila esté vacía mediante su módulo "estaVacia".
								3º Si se cumple, el constructor por defecto funciona correctamente, y sino da error


   INSERTAR ----------------->  1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
								2º Crear un informe, el cual lo insertamos en la pila, mediante su módulo "insertarInforme".
								3º Comprobar que la pila no esté vacía ya que hemos insertado anteriormente el informe. Si está vacía, da error.
								4º Para finalizar, eliminar el informe, y comprobar de la misma manera si despues de esto, está vacía la pila. Si no está vacía dará error.

   CONSULTAR ---------------->  PRIMER CASO: 1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
											 2º Crear e insertar el informe en la pila, e implementar "consultarInforme" a la pila.
											 3º Comprobar que la pila no esté vacía. Si estuviera vacía, daría error al consultar la pila de informe.
							  SEGUNDO CASO:  1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
											 2º Crear un informe en la pila, e implementar "consultarInforme" a la pila.
											 3º Comprobar que la pila esté vacía. Si no estuviera vacía, daría error al consultar la pila de informes, ya que no hemos insertado el informe anteriormente.

   MOSTRAR INFORMES TOTALES ->  PRIMER CASO: 1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
											 2º Crear una pila auxiliar a la cual se van a pasar los datos de la original a esta.
											 3º Crear e insertar un informe en la pila original, e implementar "mostrarInformesTotales" a la pila original
											 4º Comprobar que la pila no esté vacía. Si estuviera vacía, daría error al mostrar los informes
											 5º Comprobar también, si la pila auxiliar está vacía, ya que si no está vacía, da error al eliminar la pila auxiliar
							  SEGUNDO CASO:  1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
								    		 2º Crear una pila de informes auxiliar a la cual se van a pasar los datos de la original a esta.
								  			 3º Implementar el módulo "mostrarInformesTotales" a la pila original
											 4º Comprobar que la pila esté vacía, ya que no se insertó ningún informe en ella. Si no está vacía, dara error al crear la pila por defecto. 

  MOSTRAR INFORMES DEL MÉDICO ->  PRIMER CASO:  1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
											    2º Crear una pila auxiliar a la cual se van a pasar los datos de la original a esta.
												3º Crear un médico y una variable que indica sus apellidos.
											    4º Crear e insertar un informe en la pila original, e implementar "mostrarInformesMedico" a la pila original
												5º Obtener los apellidos del médico que se van a igualar a la variable apellidos, creada anteriormente.
											    6º Comprobar que la pila no esté vacía. Si estuviera vacía, daría error al mostrar los informes
											    7º Comprobar también, si la pila auxiliar está vacía, ya que si no está vacía, da error al eliminar la pila auxiliar
								  SEGUNDO CASO: 1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
								    		    2º Crear una pila de informes auxiliar a la cual se van a pasar los datos de la original a esta.
								  			    3º Implementar el módulo "mostrarInformesMedico" a la pila original
											    4º Comprobar que la pila esté vacía, ya que no se insertó ningún informe en ella. Si no está vacía, dara error al crear la pila por defecto. 

  BORRAR INFORMES DEL MÉDICO ->  PRIMER CASO:   1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
											    2º Crear una pila auxiliar a la cual se van a pasar los datos de la original a esta.
												3º Crear un médico y una variable que indica sus apellidos.
											    4º Crear e insertar un informe en la pila original, e implementar "borrarInformesMedico" a la pila original
												5º Obtener los apellidos del médico que se van a igualar a la variable apellidos, creada anteriormente.
											    6º Comprobar que la pila no esté vacía. Si estuviera vacía, daría error al borrar los informes del médico, ya que tienen que estar el resto de datos del informe
											    7º Comprobar también, si la pila auxiliar está vacía, ya que si no está vacía, da error al eliminar la pila auxiliar
	                            SEGUNDO CASO:   1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
								    		    2º Crear una pila de informes auxiliar a la cual se van a pasar los datos de la original a esta.
												3º Crear un médico y una variable que indica sus apellidos.
								  			    4º Implementar el módulo "borrarInformesMedico" a la pila original
											    5º Comprobar que la pila esté vacía, ya que no se insertó ningún informe en ella. Si no está vacía, dara error al crear la pila por defecto. 
	
	BORRAR PRIMER INFORME ---->  PRIMER CASO:   1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
											    2º Crear e insertar dos informes en la pila, e implementar "borrarPrimerInf", una sola vez a la pila.
											    3º Comprobar que la pila no esté vacía. Si estuviera vacía, daría error al borrar el primer informe
												4º Implementar una segunda vez "borrarPrimerInf", y despues comprobar si está vacía la pila. Si no lo estuviera daría error al borrar el primer informe.
								 SEGUNDO CASO:  1º Crear una pila de informes por defecto, por lo que inicialmente está vacía.
											    2º Crear e insertar dos informes en la pila, e implementar "borrarPrimerInf", una sola vez a la pila.
											    3º Comprobar que la pila no esté vacía. Si estuviera vacía, daría error al borrar el primer informe
	
	
	DESTRUCTOR -------------->  1º Crear una pila de informes por defecto, por lo que inicialmente va a estar vacía
								2º Eliminar dicha pila
								3º Comprobar si está vacía la pila, si no lo está dará error en el destructor


*/

#endif /* PRUEBASPILAINFORMES_H_ */









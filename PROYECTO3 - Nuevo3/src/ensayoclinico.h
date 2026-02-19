/*
 * ensayoclinico.h
 *
 *  Autor: Juan A. Rico (jarico@unex.es)
 *  Fecha: 15 abril 2023
 */

#ifndef ENSAYO_CLINICO_H_
#define ENSAYO_CLINICO_H_

#include <iostream>
#include <string>
#include <fstream>

#include "ListaDPI.h"
#include "paciente.h"
#include "BSTree.h"
#include "KeyValue.h"
// Si necesitas alguna ED o clase adicional, puedes incluirla aqui

using namespace std;

const int MAX = 200;

class EnsayoClinico {

private:
   
   string  nombre; // Inicializa con tu NOMBRE Y APELLIDOS en el constructor
   int ocupadas;

   BSTree< KeyValue <string, Paciente *> > *arbolPacientes;
   Paciente* Vector[MAX];

   // Lista en la que los DNI de los pacientes no coinciden
   ListaDPI <string> *listaDeErrores; // QUEDAR ESTE

   //BSTree<string> *arbolDeErrores; // O ESTE
   /*
   PRE: ---
   DESC: se cargan los pacientes del archivo pacientes_ordenados.csv, creándose un árbol binario
   COMPLEJIDAD: 0(log(log(n)))
   */
   void cargarPacientesVector(Paciente* Vector[MAX]); //iterativo
   /*
   PRE: ini <= fin
   DESC: se crea un árbol binario de búsqueda, de los pacientes
   COMPLEJIDAD: O(n)
   */
   void crearArbolPaciente(int ini, int fin); // recursivo
   /*
    PRE: inicializado correctamente el paciente de entrada y salida
    POST: devuelve true si encuentra al paciente con su correspondiente DNI, y false en caso contrario
    COMPLEJIDAD: O(n²)
    */
   bool obtenerPaciente(string DNI, Paciente*& p);
   /*
    PRE: ---
    DESC: hace un recorrido al árbol entero, en orden de DNI de los pacientes
    COMPLEJIDAD: O(log(n))
    */
   void recorridoBuscarPacientePorDNI(BSTree <KeyValue<string, Paciente*> >* arbol, string DNI, Paciente* &p);
   /*
    PRE: ---
    DESC: recorrido In-Orden del árbol, y va a mostrar por pantalla los pacientes con mayor puntuación
    COMPLEJIDAD: O(log(n))
    */
   void recorridoMostrarMayores(BSTree<KeyValue<string, Paciente*>>* arbol, ListaDPI <Paciente*> *lista, int cuantos, int &contador);
   /*
    PRE: ListaDPI correctamente inicializado
    DESC: inserta una ListaDPI en orden de puntuación
    COMPLEJIDAD:O(n²)
    */
   void insertarListaOrden(ListaDPI<Paciente*> *lista, Paciente *p);
   /*
    PRE: el atributo DNI correctamente inicializado
    DESC: devuelve los errores de los pacientes, fijandose en si el DNI ya fue insertado, en ese caso no se vuelve a insertar, y asi no hay repeticiones de error
    COMPLEJIDAD:
    */
   void insertarSinRepeticiones (string DNI);
   /*
    PRE: que el arbol esté correctamente inicializado
    DESC: recorre el arbol y muestra los DNI que dan error, de los pacientes
    COMPLEJIDAD: O(n)
    */
   void recorridoMostrarArbolDeErrores(BSTree<string> *arbol);
   /*
    PRE: que los atributos de los niveles y el arbol estén correctamente inicializados
    POST: hace un recorrido Post-Orden del arbol y devuelve la cantidad de niveles de este
    COMPLEJIDAD: O(n)
    */
   void recorridoNiveles(BSTree<KeyValue<string, Paciente*>> *arbol, int nivActual, int &nivMaximo);
   /*
    PRE: que el atributo del subarbol de apellidos, y que el árbol estén correctamente inicializados
    DESC: recorre el árbol en Post-Orden y devuelve las subcadenas de apellidos, de los pacientes
    COMPLEJIDAD: O(n²)
    */
   void recorridoSubCadenaDeApellidos (BSTree<KeyValue<string, Paciente*>> *arbol, string s_apellido);
   /*
    PRE: que los árboles y el atributo de subcadena de DNI, estén correctamente inicializados
    DESC: recorre el árbol en Pre-Orden y devuelve las subcadenas de DNI, de los pacientes
    C0MPLEJIDAD: O(n²)
    */
   void recorridoSubArbolDNI (BSTree<KeyValue<string, Paciente*>> *arbol, string s_dni, BSTree<KeyValue<string, Paciente*>> *&SUBarbol);
   /*
    PRE: que el árbol y la subcadena de DNI estén correctamente inicializados
    DESC: devuelve el subárbol que contiene la primera aparición de la cadena que se está buscando
          Si me devuelve nullptr, en ese subárbol no hay ninguno que cumpla la condicion del DNI
    COMPLEJIDAD: O(n)
    */
   void mostrarEnOrdenDNI(BSTree<KeyValue<string, Paciente*>> *arbolPreOrden, string s_dni);

public:

   // Pone el nombre del alumno al ensayo y crea lo necesario
 /**
  * PRE: ----
  * POST: La instancia queda creada correctamente
  * COMPLEJIDAD: O(1)
  */
   EnsayoClinico      ();
   /**
   * PRE: ----
   * POST: destructor
   * COMPLEJIDAD: O(1)
   */
   ~EnsayoClinico      ();
   
   // devuelve el nombre del alumno
  /**
   PRE: que la instancia haya sido creada correctamente
   POST: devuelve el nombre del alumno
   COMPLEJIDAD: O(1)
   */
   string getNombre          ();
   
   // Lee el archivo ensayo.csv y añade la puntuación de los pacientes.
   /*
    PRE: ---
    DESC: lectura del archivo ensayo.csv y se añade la puntuación de los alumnos
    COMPLEJIDAD: O(log(n))
    */
   void   anotar             ();
   
   // Muestra el numero de niveles del arbol
   /**
    PRE: ---
    POST: devuelve el número de niveles que tiene el árbol
    COMPLEJIDAD: O(n)
    */
   int    numNiveles         ();
   
   // Muestra los DNI de los pacientes de ensayo.csv que no existen
   // se guardan los dni que son errores, en algun sitio, pq luego habrá que mostrarlos
   /*
    PRE: ---
    DESC: muestra los DNI de los alumnos que no existen en el archivo ensayo.csv
    COMPLEJIDAD: O(n)
    */
   void   mostrarErrores     ();
   
   // Muestra "cuantos" pacientes con mayor puntuacion
   /*
    PRE: que se inicialice cuantos correctamente
    DESC: muestra por pantalla los 10 primeros pacientes con mayor puntuación
    COMPLEJIDAD:
    */
   void   mostrarMayores     (int cuantos);
   
   // Muestra pacientes cuyo apellido contiene subcadena "s_apellido"
   /*
   PRE: que se inicialice correctamente el atributo de subcadena de apellidos de los alumnos
   DESC: muestra por pantalla los alumnos cuyo apellidos contienen una cadena en especifico
   COMPLEJIDAD: O(n)
   */
   void   mostrarPorApellido (string s_apellido);
   
   // Muestra pacientes cuyo DNI empieza por subcadena "s_dni"
   /*
    PRE:  que se inicialice correctamente el atributo de subcadena de DNI de los alumnos
    DESC: muestra por pantalla los alumnos cuyo DNI empiezan por una cadena en especifico
    COMPLEJIDAD: O(n)
    */
   void   mostrarPorDNI      (string s_dni);
};

#endif /* ENSAYO_CLINICO_H_ */


/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2017-2018
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 7
//
// Este programa utiliza la clase Matriz2D_1 ampliada. 
//
// A esta clase se han incorporado tres m�todos que usan un fichero de texto. 
// 		Los dos primeros datos del ficheros son dos datos int que indican el 
//		n�mero de filas y columnas de la matriz. Los datos que se guardar�n 
//		en la matriz son de tipo TipoBase y est�n separados en el fichero 
//		por caracteres separadores. 
//
// Los nuevos m�todos son:
//	1)	Constructor que recibe el nombre de un fichero y rellena las 
//		casillas de la matriz con los datos contenidos en el fichero. 
//	2)	M�todo que lea los datos a guardar en una matriz (que ya existe) 
//		desde un fichero.  
//  3)	M�tdo que escribe en un fichero de texto el contenido de una matriz. 
//
// Fichero: VI_Demo-Matriz2D-ES.cpp
//
/***************************************************************************/

#include "Matriz2D_1.h"

#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main(void) 
{

	const char * nombre1 = "datos_5x4.txt";
	Matriz2D m1(nombre1);

	cout << "Matriz m1 leida del fichero " << nombre1 << endl; 

	if (m1.EstaVacia())
		cout << "Matriz m1 esta vacia." << endl;
	else 
		cout << "Matriz m1 NO esta vacia." << endl;

	cout << "Dimensiones de m1 = " << m1.Filas() << " x " 
        << m1.Columnas() << endl;

	PintaMatriz (m1, "Creada matriz m1 (datos desde fichero)");
	cout << endl;	

	//........................................

	const char * nombre2 = "datos_5x4_out.txt";

	cout << "Guardando m1 en el fichero " << nombre2 << endl << endl; 
	m1.EscribirMatriz2D (nombre2);

	//........................................

	Matriz2D m2 (nombre2);

	cout << "Matriz m2 leida del fichero " << nombre2 << endl; 

	if (m2.EstaVacia())
		cout << "Matriz m2 esta vacia." << endl;
	else 
		cout << "Matriz m2 NO esta vacia." << endl;

	cout << "Dimensiones de m2 = " << m2.Filas() << " x "
        << m2.Columnas() << endl;

	PintaMatriz (m2, "Creada matriz m2 (datos desde fichero)");
	cout << endl;	

	//........................................

	if (m1 == m2) {
		cout << endl;	
		cout << "Se ha comprobado que m1 == m2 lo que significa que" << endl;
		cout << "se ha guardado el contenido de m1 en el fichero" << endl;  
		cout << nombre2 << " y se ha recuperado correctamente ese" << endl;
		cout << "contenido en la matriz m2" << endl;
		cout << endl;	
	}
	else {
		cout << endl;	
		cout << "Hay algun error de consistencia entre los datos" << endl;
		cout << "leidos y los guardados." << endl;
		cout << endl;	
	}

	//........................................

	Matriz2D m3;

	cout << "Leyendo contenido de m3 (ya existe m3) del fichero " 
		 << nombre2 << endl; 

	m3.LeerMatriz2D (nombre2);

	if (m3.EstaVacia())
		cout << "Matriz m3 esta vacia." << endl;
	else 
		cout << "Matriz m3 NO esta vacia."<< endl;
	
	cout << "Dimensiones de m3 = " << m3.Filas() << " x "
        << m3.Columnas() << endl;

	PintaMatriz (m3, "Matriz m3 (datos recuperados desde fichero)");
	cout << endl;	

	if ((m3 == m2) && (m3 == m1)) 
		cout << "m3 == m2 == m1--> Lectura correcta" << endl;
	else 
		cout << "m1, m2 y m3 diferentes --> Lectura incorrecta" << endl;

	cout << endl;	

	return 0;
}

/***************************************************************************/
/***************************************************************************/

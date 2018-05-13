/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 12 - Ejercicio 8 - Clase Matriz                 **/
/**                                                         **/
/*************************************************************/
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 8
//
// Disponemos de un fichero de texto que contiene n�meros enteros que
// se disponen en l�neas, y en cada l�nea est�n separados por espacios 
// en blanco. Todas las l�neas tienen el mismo n�mero de elementos.
// EL FICHERO NO TIENE CABECERA QUE INDIQUE EL N�MERO DE FILAS Y COLUMNAS 
//
// Este programa utiliza la clase Matriz2D_1 ampliada. 
// A esta clase se han incorporado los siguientes m�todos: 
//	1)	Constructor que recibe el nombre de un fichero (con la 
//		estructura descrita anteriormente) y rellena las casillas 
//		de la matriz con los datos contenidos en el fichero. 
//		Se sobreentiende que los datos est�n guardados por filas.
//	2)	M�todo que lea los datos a guardar en una matriz (que ya existe) 
//		desde un fichero con la estructura descrita.
//	3)  M�todo que escribe en un fichero el contenido de la matriz.   
//
// Las restricciones que se impon�an a este programa son:
// 
//	1)	El fichero s�lo puede ser le�do una �nica vez, y no
//		pueden copiarse completo en memoria. 
//	2)	Se desconoce a priori el n�mero de l�neas del fichero. 
//	3)	Las l�neas del fichero tiene una longitud indeterminada, aunque 
//		nunca mayor de 500. 
//	4)	El n�mero de datos de cada l�nea es indeterminado, aunque �ste 
//		es com�n para todas las l�neas. 
//	5)	No puede emplearse una matriz con un n�mero de filas "tentativo": 
//		matriz ocupar� en cada momento el espacio estrictamente  necesario 
//		y los datos se copiar�n conforme se lean cada una de las filas.
//
//	El n�mero de l�neas de datos del fichero debe coincidir con el n�mero 
//	de filas de la matriz, y el n�mero de elementos de cada fila con el 
//	n�mero de columnas.
//	
//	NOTA: Ha sido necesario a�adir nuevos m�todos a la clase "Matriz2D_1".
//
// Fichero: VI_Demo-Matriz2D-ES_FicheroSinCabecera.cpp
//
/***************************************************************************/

#include "Matriz2D_1_FicherosSinCabecera_sstream.h"
 
#include <iostream>
using namespace std;
 
/***************************************************************************/
/***************************************************************************/
 
int main(void) 
{ 

	const char * nombre1 = "datos.txt";
	Matriz2D m1(nombre1);

	cout << "Matriz m1 leida del fichero " << nombre1 << endl; 

	if (m1.EstaVacia())
		cout << "Matriz m1 esta vacia\n";
	else 
		cout << "Matriz m1 NO esta vacia\n";
	cout << "Dimensiones de m1 = " << m1.Filas() << " x " 
		<< m1.Columnas() << endl;

	PintaMatriz (m1, "Creada matriz m1 (datos desde fichero)");
	cout << endl;	
 
	//........................................

	const char * nombre2 = "datos_out.txt";
 
	cout << "Guardando m1 en el fichero " << nombre2 << endl << endl; 
	m1.EscribirMatriz2D (nombre2);

	//........................................

	Matriz2D m2 (nombre2);

	cout << "Matriz m2 leida del fichero " << nombre2 << endl; 

	if (m2.EstaVacia())
		cout << "Matriz m2 esta vacia\n";
	else 
		cout << "Matriz m2 NO esta vacia\n";
	cout << "Dimensiones de m2 = " << m2.Filas() << " x "
		<< m2.Columnas() << endl;

	PintaMatriz (m2, "Creada matriz m2 (datos desde fichero)");
	cout << endl;	

	//........................................

	if (m1 == m2) {
		cout << endl;	
		cout << "Se ha comprobado que m1 == m2 lo que significa que\n";
		cout << "se ha guardado el contenido de m1 en el fichero\n";  
		cout << nombre2 << " y se ha recuperado correctamente ese\n";
		cout << "contenido en la matriz m2" << endl;
		cout << endl;	
	}
	else {
		cout << endl;	
		cout << "Hay algun error de consistencia entre los datos\n";
		cout << "leidos y los guardados";
		cout << endl;	
	}

	//........................................

	Matriz2D m3;

	cout << "Leyendo contenido de m3 (ya existe m3) del fichero " 
		 << nombre2 << endl; 

	m3.LeerMatriz2D (nombre2);
	if (m3.EstaVacia())
		cout << "Matriz m3 esta vacia\n";
	else 
		cout << "Matriz m3 NO esta vacia\n";
	cout << "Dimensiones de m3 = " << m3.Filas() << " x "
		 << m3.Columnas() << endl;

	PintaMatriz (m3, "Matriz m3 (datos recuperados desde fichero)");
	cout << endl;	

	return 0;
} 

/***************************************************************************/
/***************************************************************************/

/*********************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// PRÁCTICA 1 
// 
/*	
	Demostración del uso de ficheros de cabecera y de biblioteca
*/
/*********************************************************************/

#include <iostream>
#include "utils.h"

using namespace std;

/*********************************************************************/
/*********************************************************************/

int main()
{   
	int dividendo, divisor; 

	cout << "Introduce dividendo (terminar con un negativo) --> "; 
	cin >> dividendo; 
	// Solo se pide el divisor si el dividendo es válido
	if (dividendo >= 0) {
		cout << "Introduce divisor (terminar con un negativo) --> "; 
		cin >> divisor; 
	}

	while ((dividendo>=0) && (divisor>=0)) {

		cout << "\tLa división entera es = "; 
		cout << DivisionEntera (dividendo, divisor) << endl;

		cout << "\tEl resto de la división es = "; 
		cout << RestoDivision (dividendo, divisor) << endl;

		cout << endl;

		cout << "Introduce dividendo (terminar con un negativo) --> "; 
		cin >> dividendo; 
		// Solo se pide el divisor si el dividendo es válido
		if (dividendo >= 0) {
			cout << "Introduce divisor (terminar con un negativo) --> "; 
			cin >> divisor; 
		}

	} // while ((dividendo>=0) && (divisor>=0)) 

	cout << "\n\n";

	return (0);
}

/*********************************************************************/
/*********************************************************************/
 

/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2017-2018
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//	
//	Definición de funciones de utilidad
//
//	Fichero: Util.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "Util.h"

using namespace std;

/***************************************************************************/
// Comprueba la  existencia y disponibilidad de un fichero

bool ExisteFichero (const char *nombre)
{
	ifstream fichero;
	bool problema;

	fichero.open (nombre, ifstream::binary);
	problema = fichero.fail();
	if (!problema) fichero.close();

	return ((problema) ? false : true);
}

bool ExisteFichero (const string & nombre)
{
	const char * el_nombre = nombre.c_str();

	return (ExisteFichero(el_nombre));
}

/***************************************************************************/
// Lee un número real (double). Termina si se lee un valor correcto o EOF.
// Recibe: msg, el mensaje que etiqueta la lectura  

double LeeNumeroReal (const char * msg) 
{	
	const int MAX_SIZE = 256;

	double valor; 

	cout << msg;
	cin >> valor; // Lectura de un double

	while (cin.fail() && !(cin.eof())) { 

		// Si falló, está activo "failbit"
		
		cin.clear(); // Reestablecer las banderas de cin
		cin.ignore (MAX_SIZE, '\n'); // Limpiar cin

		cout << msg;
		cin >> valor; // Lectura de un double
	}

	return (valor);
}

/***************************************************************************/
// Lee un número entero (int). Termina si se lee un valor correcto o EOF.
// Recibe: msg, el mensaje que etiqueta la lectura  

int LeeNumeroEntero (const char * msg) 
{	
	const int MAX_SIZE = 256;

	int valor; 

	cout << msg;
	cin >> valor; // Lectura de un int

	while (cin.fail() && !(cin.eof())) { 

		// Si falló, está activo "failbit"
		
		cin.clear(); // Reestablecer las banderas de cin
		cin.ignore (MAX_SIZE, '\n'); // Limpiar cin

		cout << msg;
		cin >> valor; // Lectura de un int
	}

	return (valor);
}

/***************************************************************************/
/***************************************************************************/
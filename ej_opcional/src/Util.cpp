
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "Util.h"

using namespace std;

/***************************************************************************/
// Función (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos números reales muy próximos sean considerados iguales.

bool SonIguales(double uno, double otro) 
{
	return (fabs(uno-otro) <= PRECISION_SON_IGUALES);
}

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
// Calcula el tamaño (número de bytes) de un fichero. 

int TamanioFichero (const char * nombre)
{
	int tam;

	ifstream fi (nombre);

	fi.seekg (0, ios::end);
	tam = fi.tellg();

	fi.close();

	return (tam);
}

int TamanioFichero (string nombre)
{
	return (TamanioFichero (nombre.c_str()));
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

double LeeNumeroEntero (const char * msg) 
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

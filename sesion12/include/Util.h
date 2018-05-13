/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2017-2018
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//	
//	Declaración de funciones de utilidad 
//	Fichero: Util.h
//
/***************************************************************************/

#ifndef UTIL
#define UTIL

#include <string>

using namespace std;

/***************************************************************************/
// Comprueba la  existencia y disponibilidad de un fichero

bool ExisteFichero (const char *nombre);
bool ExisteFichero (const string & nombre);

/***************************************************************************/
// Lee y devuelve un número. Termina si se lee un valor correcto o EOF.
// Recibe: msg, el mensaje que etiqueta la lectura  

double LeeNumeroReal (const char * msg);
int LeeNumeroEntero (const char * msg);

bool SonIguales(double uno, double otro);
/***************************************************************************/

#endif

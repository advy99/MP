/*************************************************************/
/**                                                         **/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 5                                               **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <cmath>
#include <cstring>
#include "Lectura.h"

using namespace std;


/*************************************************************/
/**                                                         **/                                                         
/**     Función para comprobar si los elementos de un array **/
/**  son digitos.                                           **/
/**                                                         **/
/**     Recibe: Una cadena tipo C                           **/
/**     Devuelve : Booleano                                 **/
/**                                                         **/
/**     Teniendo en cuenta si el primer elemento es el      **/
/**  es el signo, recorremos el array para comprobar si     **/
/**  estan en el intervalo de digitos en la tabla ASCII.    **/
/**                                                         **/
/*************************************************************/

bool TodosSonDigitos(const char * cadena){
	const char * p_char = cadena;
	bool son_digitos = true;

	if ( *p_char == '+' || *p_char == '-' )
		p_char++;

	while(*p_char && son_digitos){
		if(*p_char < '0' || *p_char > '9')
			son_digitos = false;
		p_char++;
	}

	return son_digitos;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**     Pasa una cadena a un entero, si todos sus elementos **/
/**  son digitos.                                           **/
/**                                                         **/
/**     Recibe : Una cadena tipo C                          **/
/**     Devuelve : Entero                                   **/
/**                                                         **/
/**     Lee la cadena elemento a elemento, haciendo un      **/
/**  casting a entero, y multiplicandolo por 10 elevado a   **/ 
/**  la posicion que tomaria como numero.                   **/
/**                                                         **/
/*************************************************************/

int CadenaAEntero(const char * cadena){
	const int CERO = '0';
	int entero = 0;
	int multiplo = pow(10,strlen(cadena) - 1);

	const char * puntero_char = cadena;

	if ( *puntero_char == '+' || *puntero_char == '-' ){
		puntero_char++;
		multiplo = multiplo / 10;
	}

	if ( TodosSonDigitos(cadena) ){
		while(*puntero_char){
			entero = entero + ( (int) *puntero_char - CERO ) * multiplo ;
			puntero_char++;
			multiplo = multiplo / 10;
		}
	}

	if (*cadena == '-')
		entero = entero * -1;

	return entero;
}

/******************************************************************************/

/********************************************************/
/**                                                    **/
/**     Pide una cadena de enteros, si no se cumple    **/
/**  la vuelve a pedir.                                **/
/**                                                    **/
/**     Recibe : Una cadena tipo C                     **/
/**              Entero con el tamaño maximo           **/
/**                                                    **/
/**     Devuelve : Cadena tipo C                       **/
/**                                                    **/
/********************************************************/

char * PedirCadenaEnteros (char * cadena, const int MAX){

	cin.getline(cadena, MAX);

	while(!TodosSonDigitos(cadena)){
			cout << "Vuelve a introducir la cadena : ";
			cin.getline(cadena, MAX);

	}

	return cadena;

}

/******************************************************************************/

/********************************************************/
/**                                                    **/
/**     Comprueba si un numero esta en un intervalo.   **/
/**																	 **/
/**     Recibe : Un entero (A comprobar)               **/
/**              Dos enteros (Extremos del intervalo)  **/
/**                                                    **/
/**     Devuelve : Un booleano                         **/
/**                                                    **/
/********************************************************/

bool PerteneceIntervalo(const int NUM, const int MIN, const int MAX){
	if (MIN > MAX)
		return false; //El intervalo a comprobar es vacio
	
	if (NUM < MAX && NUM > MIN)
		return true;
	else
		return false;
}

/******************************************************************************/

/********************************************************/
/**                                                    **/
/**     Lee un entero entre dos enteros dados por      **/
/**  parametro.                                        **/
/**                                                    **/
/**     Recibe : Dos entero                            **/
/**                                                    **/
/**     Devuelve : Un entero                           **/
/**                                                    **/
/**                                                    **/
/********************************************************/

int LeerEnIntervalo(const int MAX, const int MIN ){
	int numero;

	cout << "Introduzca un numero entre " << MIN << " y " << MAX << " : ";
	cin >> numero;

	while ( !PerteneceIntervalo(numero,MIN,MAX) ){
		cout << "Introduzca un numero entre " << MIN << " y " << MAX << " : ";
		cin >> numero;
	}

	return numero;
}
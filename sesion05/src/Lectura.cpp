#include <iostream>
#include <cmath>
#include <cstring>
#include "Lectura.h"

using namespace std;

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

char * PedirCadenaEnteros (char * cadena, const int MAX){

	cin.getline(cadena, MAX);

	while(!TodosSonDigitos(cadena)){
			cout << "Vuelve a introducir la cadena : ";
			cin.getline(cadena, MAX);

	}

	return cadena;
}
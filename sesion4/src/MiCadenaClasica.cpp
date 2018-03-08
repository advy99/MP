#include "MiCadenaClasica.h"

int longitud_cadena( char * cadena){
	int tamanio = 0;

	while ( *cadena != '\0' ){
		tamanio++;
		cadena++;
	}

	return tamanio;
}


bool es_palindromo( char * cadena){
	bool palindromo = true;
	int tam_util = longitud_cadena(cadena);
	char * p_fin_char = &cadena[tam_util - 1];

	while ( cadena < p_fin_char && palindromo){
		if(*cadena == *p_fin_char){
			cadena++;
			p_fin_char--;
		}
		else{
			palindromo = false;
		}

	}
	return palindromo;
}

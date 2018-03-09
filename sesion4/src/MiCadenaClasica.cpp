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
	char * p_fin_char = cadena + tam_util - 1;

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

int comparar_cadenas (char * cadena1, char * cadena2){
	int valor_cad1 = 0;

	for (int i = 0; i < longitud_cadena(cadena1); i++){
		valor_cad1 += *(cadena1 + i);
	}
	for (int i = 0; i < longitud_cadena(cadena2); i++){
		valor_cad1 -= *(cadena2 + i);
	}

	return valor_cad1;
}

void copiar_cadena(char * resultado, char * original){
	int longitud = longitud_cadena(original);

	for(int i = 0; i <= longitud ; i++){
		*(resultado + i) = *(original + i); 
	}
}

/*---------------------------------------------------------*/

void encadenar_cadena (char * original , char * a_copiar ){
	int longitud_original = longitud_cadena(original);
	int longitud_a_copiar = longitud_cadena(a_copiar);

	for (int i =0; i < longitud_a_copiar; i++){
		*(original+longitud_original +i) = * (a_copiar + i);
	}

}
/*
char extraer_subcadena (char * cadena , int pos , int lon){
	char subcadena;


	for (int i = pos; i < longitud ; i++)

}
*/
char * invertir_cadena (char * cadena){
	int longitud = longitud_cadena(cadena);

	char invertida[longitud];
	char * p_char = invertida;

	for (int i = 0; i < longitud; i++){
		*(p_char+i) = *(cadena+longitud - 1 -i);
	}
	*(p_char+longitud) = '\0';
	
	return p_char;
}
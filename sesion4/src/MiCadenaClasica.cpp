#include "MiCadenaClasica.h"

int longitud_cadena( char * cadena){
	int tamanio = 0;

	// Aumentamos el valor de tamanio hasta encontrar el
	//caracter de finalizacion '\0'
	while ( *cadena != '\0' ){
		tamanio++;
		cadena++;
	}

	return tamanio;
}


bool es_palindromo( char * cadena){
	bool palindromo = true;
	int tam_util = longitud_cadena(cadena);

	//Establecemos un puntero al final de la cadena
	char * p_fin_char = cadena + tam_util - 1;

	// Recorremos la cadena, comparando el primer y ultimo
	//elemento, hasta que se cruzen los punteros, o encuentre
	//algun caso que no se cumpla
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
	int valor_cad = 0;

	// Añadimos el valor ASCII de la cadena1 a valor_cad
	for (int i = 0; i < longitud_cadena(cadena1); i++){
		valor_cad += *(cadena1 + i);
	}

	// Restamos el valor ASCII de la cadena2 a valor_cad
	for (int i = 0; i < longitud_cadena(cadena2); i++){
		valor_cad -= *(cadena2 + i);
	}

	return valor_cad;
}

void copiar_cadena(char * resultado, char * original){
	int longitud = longitud_cadena(original);

	// Con punteros, igualamos las cadenas, y por ultimo asignamos
	//el valor '\0' al final
	for(int i = 0; i < longitud ; i++){
		*(resultado + i) = *(original + i); 
	}
	*(resultado + longitud) = '\0';
}

void encadenar_cadena (char * original , char * a_copiar ){
	int longitud_original = longitud_cadena(original);
	int longitud_a_copiar = longitud_cadena(a_copiar);

	// Añadimos la cadena al final de la original
	// Al igual que copiar solo que comenzando en el
	//final de la original
	for (int i =0; i < longitud_a_copiar; i++){
		*(original+longitud_original +i) = * (a_copiar + i);
	}
	*(original + longitud_original + longitud_a_copiar) = '\0';

}

void extraer_subcadena (char * subcadena,char * cadena , int pos , int lon){
	int lon_original = longitud_cadena(cadena);

	// Comprobamos si la longitud + posicion supera el tamaño
	//de la cadena
	if (lon + pos > lon_original)
		lon = lon_original - pos;

	// Copiamos la parte deseada en subcadena, y añadimos '\0'
	for (int i = 0; i < lon && i < lon_original; i++){
		*(subcadena + i) = *(cadena + pos + i);
	}
	*(subcadena + lon) = '\0';

}

void invertir_cadena (char * invertida ,char * cadena){
	int longitud = longitud_cadena(cadena);

	// Asignamos el final de cadena al inicio de invertida
	//saltandonos el ultimo caracter debido a que es '\0'
	for (int i = 0; i < longitud; i++){
		*(invertida+i) = *(cadena+longitud - 1 -i);
	}
	*(invertida+longitud) = '\0';
	
}
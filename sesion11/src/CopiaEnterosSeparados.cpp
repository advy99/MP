/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 10 - Copiar Enteros separados    **/
/**                                                         **/
/**  PRE: El ultimo caracter es '*'                         **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int main(){
	const int TAM_MAX = 256;
	const char MARCA = '*';


	//Caracter con el que leemos la entrada
	char c[TAM_MAX];
	int n;

	//Pedimos los caracteres
	cout << "Introduce una secuencia de enteros: ";
	//Leemos una cadena, delimitada por la marca
	cin.getline(c,TAM_MAX, MARCA);
	n = atoi(c);


	while ( !cin.eof() ){

		//Mostramos la cadena convertida a entero
		cout << endl << n << endl;

		//Volvemos a leer
		cin.getline(c,TAM_MAX, MARCA);
		n = atoi(c);

	}


	return 0;
}
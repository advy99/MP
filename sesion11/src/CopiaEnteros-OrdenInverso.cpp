/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 9 - Copiar Enteros inverso       **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "Pila.h"

using namespace std;

int main(){
	//Caracter con el que leemos la entrada
	int n;
	Pila p;

	//Pedimos los caracteres
	cout << "Introduce una secuencia de enteros: ";
	//Mientras no se alcance el fin de fichero, seguimos leyendo enteros
	while( cin >> n ){
		//Guardamos los enteros los enteros
		p = n + p;
	}

	for(int i = 1; i <= p.Tamanio();i++){
		cout << p[i] << endl;
	}


	return 0;
}
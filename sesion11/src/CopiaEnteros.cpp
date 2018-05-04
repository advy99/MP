/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 8 - Copiar Enteros               **/
/**                                                         **/
/*************************************************************/

#include <iostream>

using namespace std;

int main(){
	//Caracter con el que leemos la entrada
	int n;

	//Pedimos los caracteres
	cout << "Introduce una secuencia de enteros: ";
	//Mientras no se alcance el fin de fichero, seguimos leyendo enteros
	while( cin >> n ){
		//Mostramos los enteros
		cout << endl << n << endl;
	}


	return 0;
}
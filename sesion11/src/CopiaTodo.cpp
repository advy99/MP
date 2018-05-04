/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 1 - Copiar entrada en salida     **/
/**                                                         **/
/*************************************************************/

#include <iostream>

using namespace std;

int main(){
	//Caracter con el que leemos la entrada
	char c;

	//Pedimos los caracteres
	cout << "Introduce una secuencia de caracteres: ";
	//Mientras no se alcance el fin de fichero, seguimos leyendo
	while( cin.get(c) ){
		//Cada caracter leido, lo mandamos a la salida
		cout.put(c);
	}

	return 0;
}
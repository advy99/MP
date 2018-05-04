/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 6 - Eliminar separadores         **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <cctype>

using namespace std;

int main(){
	//Caracter con el que leemos la entrada
	char c;

	//Pedimos los caracteres
	cout << "Introduce una secuencia de caracteres: ";
	//Mientras no se alcance el fin de fichero, seguimos leyendo
	while( cin.get(c) ){

		// Si el caracter no es un espacio, o es un salto de linea,
		//se manda a la salida
		if (!isspace(c) || c == '\n')
			cout.put(c);
	}


	return 0;
}
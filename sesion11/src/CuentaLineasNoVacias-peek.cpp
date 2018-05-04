/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 4 - Contar lineas no vacias peek **/
/**                                                         **/
/*************************************************************/

#include <iostream>

using namespace std;

int main(){
	//Caracter con el que leemos la entrada
	char c;
	int contador = 0;

	//Pedimos los caracteres
	cout << "Introduce una secuencia de caracteres: ";
	//Mientras no se alcance el fin de fichero, seguimos leyendo
	while( cin.get(c) ){

		// Si la linea tiene un caracter, y el siguiente es el salto, 
		//la linea no esta vacia
		if ( c != '\n' && cin.peek() == '\n')
			contador++;
	}

	cout << endl <<  "Se han leido " << contador << " lineas no vacias" << endl;

	return 0;
}
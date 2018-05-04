/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 5 - Muestra lineas no vacias     **/
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

		// Si hay un caracter distinto del salto lo muestra
		if ( c != '\n'){
			cout.put(c);

			//Si el siguiente es un salto, hace el salto
			if( cin.peek() == '\n' )
				cout << endl;
		}
	}


	return 0;
}
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 3 - Contar caracteres            **/
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
	while( cin >> c ){
		//Cada caracter leido, sumamos uno al contador;
		contador++;
	}

	cout << endl <<  "Se han leido " << contador << " caracteres" << endl;

	return 0;
}
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 4 - Contar lineas no vacias      **/
/**                                                         **/
/*************************************************************/

#include <iostream>

using namespace std;

int main(){
	//Caracter con el que leemos la entrada
	char c;
	bool salto = true;
	int contador = 0;

	//Pedimos los caracteres
	cout << "Introduce una secuencia de caracteres: ";
	//Mientras no se alcance el fin de fichero, seguimos leyendo
	while( cin.get(c) ){
		// Comprobamos si el caracter no es el salto de linea, y si justo antes
		//teniamos un salto de linea, si esto se cumple, es una linea no vacia
		if (c != '\n'){
			if (salto){
				contador++;
				salto = false;
			}
		}
		else{
			salto = true;
		}
	}

	cout << endl <<  "Se han leido " << contador << " lineas no vacias" << endl;

	return 0;
}
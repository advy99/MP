/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 2 - Copiar entrada en salida     **/
/**                           sin vocales                   **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <cctype>

using namespace std;

int main(){
	//Caracter con el que leemos la entrada
	char c;
	char en_mayus;

	//Pedimos los caracteres
	cout << "Introduce una secuencia de caracteres: ";
	//Mientras no se alcance el fin de fichero, seguimos leyendo
	while( cin.get(c) ){
		//Cada caracter leido, guardamos su mayuscula
		en_mayus = toupper(c);


		//Comprobamos que no sea vocal, al convertirlo a mayuscula,
		//solo tenemos que comprobar con las mayusculas
		if(en_mayus != 'A' && en_mayus != 'E' && en_mayus != 'I' &&
		   en_mayus != 'O' && en_mayus != 'U')
			cout.put(c);
	}

	return 0;
}
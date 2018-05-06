/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 7 - Copiar lineas no marcadas    **/
/**                                                         **/
/*************************************************************/

#include <iostream>

using namespace std;

int main(){
	//Caracter con el que leemos la entrada
	char c;
	char primer_linea;
	bool mostrar = true;
	const char MARCA = '#';

	//Pedimos los caracteres
	cout << "Introduce una secuencia de caracteres: ";
	//Mientras no se alcance el fin de fichero, seguimos leyendo
	cin.get(c);
	primer_linea = c;

	mostrar = primer_linea != MARCA;

	do{
		//Si no esta marcada la linea, se muestra
		if(mostrar)
			cout.put(c);

		//Si hay un salto de linea, se actualiza el primer elemento de esta
		if(c == '\n'){
			primer_linea = cin.peek();		
			mostrar = primer_linea != MARCA;	
		}
		
	}while (cin.get(c) );


	return 0;
}
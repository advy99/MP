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
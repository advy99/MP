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
		//Cada caracter leido, lo mandamos a la salida
		en_mayus = toupper(c);

		if(en_mayus != 'A' && en_mayus != 'E' && en_mayus != 'I' &&
		   en_mayus != 'O' && en_mayus != 'U')
			cout.put(c);
	}

	return 0;
}
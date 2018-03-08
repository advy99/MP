#include <iostream>
#include "MiCadenaClasica.h"

using namespace std;

int main( void ){
	const int MAX = 100;
	char cadenaC [MAX];

	cout << "Introduce una cadena: ";
	cin.getline(cadenaC, MAX);

	cout << longitud_cadena(cadenaC) << endl;

	cout << "La cadena es palindromo " << es_palindromo(cadenaC) << endl;

	return (0);
}
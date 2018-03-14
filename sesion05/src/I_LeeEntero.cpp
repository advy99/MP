#include <iostream>
#include "Lectura.h"

using namespace std;

int main( void ){
	const int MAX = 100;
	char cadena[MAX];
	int valor;

	cout << "Introduce una cadena : ";
	PedirCadenaEnteros(cadena,MAX);

	cout << cadena;

	valor = CadenaAEntero(cadena);

	cout << endl << valor << endl;
}

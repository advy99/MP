#include <iostream>
#include "Lectura.h"

using namespace std;

int main( void ){
	const int MAX = 100;
	char cadena[MAX];
	int valor;
	int numero;
	int ext_inf, ext_sup;

	cout << "Introduce una cadena : ";
	PedirCadenaEnteros(cadena,MAX);

	cout << cadena;

	valor = CadenaAEntero(cadena);

	cout << endl << valor << endl;

	cout << "Introduce un extremo inferior : ";
	cin >> ext_inf;
	cout << "Introduce un extremo superior : ";
	cin >> ext_sup;

	numero = LeerEnIntervalo(ext_sup);

	cout << endl << numero << endl;

	return 0;
}

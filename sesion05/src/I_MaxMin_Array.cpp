#include <iostream>
#include "GestionVector.h"

/*****************************************************/

using namespace std;

/*****************************************************/

int main( void ){

	const int TOPE = 100;
	int vector[TOPE];
	int minimo;
	int maximo;
	int ext_inf, ext_sup;

	cout << "Introduce el extremo inferior y superior para rellenar el vector :";
	cin >> ext_inf;
	cin >> ext_sup;

	RellenarVectorAleatorios (vector, TOPE, ext_inf, ext_sup);

	MostrarVector(vector,TOPE);
	
	MinMaxVector(vector, 0, TOPE, minimo, maximo);

	cout << endl;
	cout << "El minimo es : " << minimo << endl;
	cout << "El maximo es : " << maximo << endl;


}
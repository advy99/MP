/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 1 - Clase vector dinamico        **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "TipoBase.h"
#include "VectorDinamico.h"

using namespace std;

int main(){
	VectorDinamico mi_vector;
	TipoBase valor;
	int casillas_ocupadas;
	int i = 0;

	if (mi_vector.EstaVacio())
		cout << "El vector esta vacio " << endl << endl;
	else
		cout << "El vector NO esta vacio" << endl << endl;
	
	cout << "Introduce un valor : ";
	cin >> valor;

	while (valor > 0){
		mi_vector[i] = valor;
		i++;

		cout << "Introduce un valor : ";
		cin >> valor;
	}

	if (mi_vector.EstaVacio())
		cout << "El vector esta vacio " << endl << endl;
	else
		cout << "El vector NO esta vacio" << endl << endl;

	casillas_ocupadas = mi_vector.CasillasOcupadas();
	cout << "El vector tiene " << casillas_ocupadas << " casillas ocupadas.";

	cout << endl;
	for (int i = 0; i < casillas_ocupadas; i++){
		cout << mi_vector[i] << " ";
	}
	cout << endl;

	VectorDinamico mi_vector2;
	cout << endl << "Creamos un nuevo vector, y le asignamos mi_vector" << endl;
	mi_vector2 = mi_vector;

	if (mi_vector2 == mi_vector)
		cout << endl << "Los vectores son iguales" << endl;
	else
		cout << endl << "Los vectores no son iguales" << endl;


	return 0;
}
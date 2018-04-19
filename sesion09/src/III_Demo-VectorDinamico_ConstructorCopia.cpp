/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 1 - Clase vector dinamico         **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "TipoBase.h"
#include "VectorDinamico_ConstructorCopia.h"

using namespace std;

int main(){
	VectorDinamico mi_vector;
	TipoBase valor;
	int casillas_ocupadas;

	if (mi_vector.EstaVacio())
		cout << "El vector esta vacio " << endl << endl;
	else
		cout << "El vector NO esta vacio" << endl << endl;
	
	cout << "Introduce un valor : ";
	cin >> valor;

	while (valor > 0){
		mi_vector.NuevoElemento(valor);

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
		cout << mi_vector.Valor(i) << " ";
	}


	return 0;
}
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 4 - Lista - Operadores           **/
/**                                                         **/
/*************************************************************/


#include <iostream>
#include "Lista.h"

using namespace std;

int main(){

	Lista mi_lista;
	TipoBase valor;

	cout << "Introduce un valor : ";
	cin >> valor;

	while (valor >= 0){
		mi_lista += valor;

		cout << "Introduce un valor : ";
		cin >> valor;
	}

	PintaLista(mi_lista, "Pintamos mi_lista");

	cout << endl << "Creamos otra lista" << endl;
	Lista lista_2 = mi_lista;

	if (mi_lista == lista_2)
		cout << endl << "Las dos listas son iguales" << endl;

	PintaLista (lista_2, "Pintamos lista_2");

	cout << "Introduce un valor a eliminar : ";
	cin >> valor;

	lista_2 -= valor;

	PintaLista (lista_2, "Pintamos lista_2");

	if (mi_lista > lista_2)
		cout << "mi_lista es mayor" << endl;

	cout << "Introduce una posicion : ";
	cin >> valor;

	cout << "El elemento " << valor << " de la lista es : " << lista_2[valor];


	return 0; 
}
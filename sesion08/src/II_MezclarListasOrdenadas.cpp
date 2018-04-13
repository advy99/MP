/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 8 - Ejercicio 15 - Mezclar lista ordenadamente  **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
	Lista lista_1, lista_2, lista_mezclada = 0; //lista_mezclada esta vacia

	LeeLista(lista_1);

	cout << endl << endl;
	
	LeeLista(lista_2);

	OrdenaSeleccionLista(lista_1);
	OrdenaSeleccionLista(lista_2);

	cout << "Lista 1: ";
	PintaLista(lista_1);

	cout << "Lista 2: ";
	PintaLista(lista_2);

	

	MezclaListas(lista_mezclada, lista_1, lista_2);

	cout << "Lista 1: ";
	PintaLista(lista_1);

	cout << "Lista 2: ";
	PintaLista(lista_2);

	cout << "Lista mezclada: ";
	PintaLista(lista_mezclada);

	LiberaLista(lista_mezclada);
}
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 8 - Ejercicio 14 - Insertar y eliminar en       **/
/**                          una lista ordenadamente        **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
	Lista lista;
	double valor;

	LeeLista(lista);

	OrdenaSeleccionLista(lista);

	PintaLista(lista);

	cout << "Introduce un nuevo valor:" ;
	cin >> valor;

	InsertaOrdenadamente(lista, valor);

	PintaLista(lista);

	LiberaLista(lista);
}
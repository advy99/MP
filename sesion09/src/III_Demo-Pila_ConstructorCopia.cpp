/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 5 - Pila memoria dinamica         **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "Pila_ConstructorCopia.h"

using namespace std;

int main(){
	TipoBase valor;
	Pila mi_pila;

	if (mi_pila.EstaVacia() ){
		cout << "La pila esta vacia." << endl;
	}
	else{
		cout << "La pila no esta vacia." << endl;
	}

	cout << "Introduce un valor: ";
	cin >> valor;

	while(valor > 0){
		mi_pila.AniadeValor(valor);

		cout << "Introduce un valor: ";
		cin >> valor;
	}

	if (mi_pila.EstaVacia() ){
		cout << "La pila esta vacia." << endl;
	}
	else{
		cout << "La pila no esta vacia." << endl;
	}

	Pila copia_mi_pila (mi_pila);

	cout << "El valor en el tope es : " << copia_mi_pila.ValorEnTope() << endl;

	cout << "Sacamos el valor " << endl;

	cout << "Se ha sacado el valor : " << copia_mi_pila.SacarValor() << endl; 

	cout << "El valor en el tope es : " << copia_mi_pila.ValorEnTope();


	return 0;

}
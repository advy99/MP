/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 6 - Cola memoria dinamica         **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "Cola_ConstructorCopia.h"

using namespace std;

int main(){
	TipoBase valor;
	Cola mi_cola;

	if (mi_cola.EstaVacia() ){
		cout << "La cola esta vacia." << endl;
	}
	else{
		cout << "La cola no esta vacia." << endl;
	}

	cout << "Introduce un valor: ";
	cin >> valor;

	while(valor > 0){
		mi_cola.AniadeValor(valor);

		cout << "Introduce un valor: ";
		cin >> valor;
	}

	if (mi_cola.EstaVacia() ){
		cout << "La cola esta vacia." << endl;
	}
	else{
		cout << "La cola no esta vacia." << endl;
	}

	Cola copia_mi_cola (mi_cola);

	cout << "El valor en la cabecera es : " 
	     << copia_mi_cola.ValorEnCabecera() << endl;

	cout << "Sacamos el valor " << endl;

	cout << "Se ha sacado el valor : " << copia_mi_cola.SacarValor() << endl; 

	cout << "El valor en la cabecera es : "
	     << copia_mi_cola.ValorEnCabecera();


	return 0;

}
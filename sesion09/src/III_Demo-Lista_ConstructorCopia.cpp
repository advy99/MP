/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 4 - Lista memoria dinamica        **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "TipoBase.h"
#include "Lista_ConstructorCopia.h"

using namespace std;

int main(){
	TipoBase valor;
	int pos;
	Lista l1;
	Lista l2(5);
	Lista l3(9,2);

	cout << "La lista l1 tiene: " << l1.NumeroNodos() << " nodos" << endl;
	cout << "La lista l2 tiene: " << l2.NumeroNodos() << " nodos" << endl;
	cout << "La lista l3 tiene: " << l3.NumeroNodos() << " nodos" << endl;

	cout << endl << "Mostramos l3: " << endl;
	for (int i = 1; i <= l3.NumeroNodos(); i++){
		cout << l3.LeerValor(i) << " ";
	}
	cout << endl << endl;

	if (l1.EstaVacio()){
		cout << "l1 esta vacio" << endl;
	}
	else{
		cout << "l1 no esta vacio" << endl;
	}

	cout << "Inserte un valor para l1 : ";
	cin >> valor;

	while(valor > 0){
		l1.AniadirValor(valor);
		cout << "Inserte un valor para l1 : ";
		cin >> valor;
	}

	cout << endl << "Mostramos l1: " << endl;
	for (int i = 1; i <= l1.NumeroNodos(); i++){
		cout << l1.LeerValor(i) << " ";
	}
	cout << endl << endl;


	cout << endl << "Modificamos valores de l2: " << endl;
	cout << endl << endl;
	for (int i = 1; i <= l2.NumeroNodos(); i++){
		cout << "Inserte un valor para l2 : ";
		cin >> valor;
		l2.ModificarValor(i, valor);
	}
	cout << endl << endl;


	cout << endl << "Mostramos l2: " << endl;
	cout << endl << endl;
	for (int i = 1; i <= l2.NumeroNodos(); i++){
		cout << l2.LeerValor(i) << " ";
	}
	cout << endl << endl;

	cout << "Introuce una posicion a eliminar en el la lista 2 : ";
	cin >> pos;
	l2.Borrar(pos);

	cout << endl << "Mostramos l2: " << endl;
	cout << endl << endl;
	for (int i = 1; i <= l2.NumeroNodos(); i++){
		cout << l2.LeerValor(i) << " ";
	}
	cout << endl << endl;

	return 0;
}
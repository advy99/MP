/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 3 - Matriz memoria dinamica       **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "TipoBase.h"
#include "Matriz2D_2_ConstructorCopia.h"

using namespace std;

int main(){
	TipoBase valor;
	int filas, columnas;
	
	cout << "Introduce el numero de filas : ";
	cin >> filas;

	cout << "Introduce el numero de columnas : ";
	cin >> columnas;

	Matriz2D_2 mi_matriz(filas, columnas, 0);

	for (int i = 0; i < mi_matriz.Filas(); i++){
		for (int j = 0; j < mi_matriz.Columnas(); j++){
			cout << "Introduce un valor : ";
			cin >> valor;
			mi_matriz.ModificarValor(i,j, valor);
		}
	}

	Matriz2D_2 mi_matriz_2 (mi_matriz);

	mi_matriz_2.RellenarAleatorios(1, 500);

	cout << endl << endl << "Matriz rellena de aleatorios :" << endl ;

	for (int i = 0; i < mi_matriz.Filas(); i++){
		for (int j = 0; j < mi_matriz.Columnas(); j++){
			cout << mi_matriz_2.LeerValor(i,j) << " ";
		}
		cout << endl;
	}
	
	
	if (mi_matriz.EstaVacia())
		cout << "La matriz esta vacia." << endl ;
	else
		cout << "La matriz no esta vacia." << endl ;


	cout << endl << "Cambiamos el tamaño de la matriz a 0,0 "<< endl;
	mi_matriz.CambiarTamanio(0,0);

	if (mi_matriz.EstaVacia())
		cout << "La matriz esta vacia." << endl ;
	else
		cout << "La matriz no esta vacia." << endl ;


	return 0;
}
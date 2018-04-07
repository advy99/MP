/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 7 - Ejercicio 9 - Asignacion tareas             **/
/**                          a tecnicos                     **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "Matriz2D_1.h"

using namespace std;


int main(){
	const int MAX_COSTE = 500;
	
	int min;
	int pos_min;
	int num;
	int coste = 0;

	cout << "Introduce el numero de tecnicos : ";
	cin >> num;

	Matriz2D_1 precio_pedidos = CreaYLeeMatriz(num, num);
	Matriz2D_1 asignaciones = CreaMatriz(num,num);
	bool * ya_asignados;

	ya_asignados = new bool [num];

	for (int i = 0; i < num; i++){
		ya_asignados[i] = false;
		for (int j = 0; j < num; j++){
			asignaciones.datos[i][j] = 0;
		}
	}
	
	for (int i = 0; i < precio_pedidos.filas; i++){
		min = MAX_COSTE;

		for (int j = 0; j < precio_pedidos.columnas; j++){
			if (min > precio_pedidos.datos[i][j] && !ya_asignados[j]){
				min = precio_pedidos.datos[i][j];
				pos_min = j;
			}
		}
		ya_asignados[pos_min] = true;
		asignaciones.datos[i][pos_min] = 1;
		coste = coste + precio_pedidos.datos[i][pos_min];
	}

	cout << "Matriz precios : " << endl << endl;
	MostrarMatriz(precio_pedidos);
	cout << endl << endl;

	cout << "Matriz asignaciones : " << endl << endl;
	MostrarMatriz(asignaciones);
	cout << endl << endl;

	cout << "El coste total es de " << coste << endl;

}
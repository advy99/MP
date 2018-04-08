/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 7 - Ejercicio 10 - Viajante de comercio         **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <cmath>
#include "Matriz2D_1.h"

using namespace std;

int main(){

	int num_ciudades;
	int num_visitadas = 0;
	int ciudad_inicial;
	int ciudad_actual;
	int pos_minimo;
	int coste_total = 0;
	double minimo;

	cout << "Introduce el numero de ciudades: ";
	cin >> num_ciudades;

	Matriz2D_1 costes = CreaMatriz(num_ciudades, num_ciudades);
	bool * ciudad_visitada = new bool [num_ciudades];
	int * orden_visitas = new int [num_ciudades];

	//Iniciamos las ciudades visitadas a false
	for (int i = 0; i < num_ciudades; i++){
		ciudad_visitada[i] = false;
	}

	//Recorremos los costes para rellenarlos
	for (int i = 0; i < costes.filas; i++){
		for (int j = 0; j < costes.columnas; j++){
			//Pedimos el coste de ir de la ciudad i a la j
			//el coste de viajar de una ciudad a ella misma, le asignamos un valor
			//nulo, ya que no tiene sentido
			if (i != j){
				cout << "Introduce el coste de viajar de " 
				     << i + 1 << " a " <<j + 1<< ": ";
				cin >> costes.datos[i][j];
			}
			else{
				costes.datos[i][j] = -1;
			}
		}
	}

	//Introducimos la ciudad inicial
	cout << "Introduce la ciudad inicial : ";
	cin >> ciudad_inicial;
	
	//Como las ciudades se nombran a partir de 1, pero trabajamos a partir de 0
	//le restamos uno a la ciudad inicial
	ciudad_inicial--;

	//Añadimos a los datos de la primera ciudad
	ciudad_actual = ciudad_inicial;
	ciudad_visitada[ciudad_inicial] = true;
	orden_visitas[num_visitadas] = ciudad_actual + 1;
	num_visitadas++;

	//Buscamos el coste minimo para cambiar de la ciudad actual, a otra aun no
	//visitada
	while (num_visitadas < num_ciudades){
		minimo = INFINITY;
		for (int i = 0; i < costes.columnas; i++){
			if (!ciudad_visitada[i] && minimo > costes.datos[ciudad_actual][i] &&
			                           costes.datos[ciudad_actual][i] > 0){
				minimo = costes.datos[ciudad_actual][i];
				pos_minimo = i;
			}
		}

		ciudad_actual = pos_minimo;

		ciudad_visitada[pos_minimo] = true;
		coste_total = coste_total + (int) minimo;
		orden_visitas[num_visitadas] = ciudad_actual + 1;
		num_visitadas++;

		if (num_visitadas == num_ciudades){
			coste_total = coste_total + costes.datos[ciudad_actual][ciudad_inicial];
		}

	}

	cout << "El orden de las visitas es el siguiente : ";
	for (int i = 0; i < num_ciudades; i++)
		cout << orden_visitas[i] << " ";
	cout << endl;

	cout << "El coste de viajar es de " << coste_total <<endl << endl;

	LiberaMatriz2D_1(costes);
	delete [] ciudad_visitada;
	delete [] orden_visitas;

}
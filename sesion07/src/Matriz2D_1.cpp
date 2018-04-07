#include "Matriz2D_1.h"
#include "TipoBase.h"


Matriz2D_1 CreaMatriz(int filas, int columnas){
	Matriz2D_1 nueva_matriz;

	nueva_matriz.filas = filas;
	nueva_matriz.columnas = columnas;

	nueva_matriz.datos = new int * [filas];

	for (int i = 0; i < filas; i++){
		nueva_matriz.datos[i] = new int [columnas];
	}
	
}


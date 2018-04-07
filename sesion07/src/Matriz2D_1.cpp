#include "Matriz2D_1.h"
#include "TipoBase.h"
#include "GeneradorAleatorioEnteros.h"


Matriz2D_1 CreaMatriz(int filas, int columnas){
	Matriz2D_1 nueva_matriz;

	nueva_matriz.filas = filas;
	nueva_matriz.columnas = columnas;

	nueva_matriz.datos = new int * [filas];

	for (int i = 0; i < filas; i++){
		nueva_matriz.datos[i] = new int [columnas];
	}

	return nueva_matriz
}

void LiberaMatriz2D_1 (Matriz2D_1 & matriz){
	for (int i = 0; i < matriz.filas; i++){
		delete [] matriz.datos[i];
	}

	delete [] matriz.datos;

	matriz.filas = 0;
	matriz.columnas = 0;

	matriz.datos = 0;
}

Matriz2D_1 CreaYLeeMatriz(int filas, int columnas){
	Matriz2D_1 nueva_matriz = CreaMatriz (filas, columnas);

	for (int i = 0; i < nueva_matriz.filas;i++){
		for (int j = 0; j < nueva_matriz.columnas;j++){
			cout << "Introduce el elemento " << i << ", " << j << " :";
			cin >> nueva_matriz.datos[i][j];
		}
	} 

	return nueva_matriz;
}

Matriz2D_1 CreaMatrizAleatorios(int filas, int columnas){
	Matriz2D_1 nueva_matriz = CreaMatriz (filas, columnas);
	GeneradorAleatorioEnteros generador(1,500);

	for (int i = 0; i < nueva_matriz.filas;i++){
		for (int j = 0; j < nueva_matriz.columnas;j++){
			nueva_matriz.datos[i][j] = generador.Siguiente();
		}
	} 

	return nueva_matriz;
}
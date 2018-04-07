#include "Matriz2D_1.h"
#include "TipoBase.h"
#include "GeneradorAleatorioEnteros.h"
#include <iostream>


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

void MostrarMatriz (Matriz2D_1 matriz){
	for (int i = 0; i < nueva_matriz.filas;i++){
		for (int j = 0; j < nueva_matriz.columnas;j++){
			cout << nueva_matriz.datos[i][j] << " ";
		}
		cout << endl;
	} 
}

Matriz2D_1 CopiaMatriz (Matriz2D_1 matriz){
	Matriz2D_1 nueva_matriz = CreaMatriz(matriz.filas, matriz.columnas);

	for (int i = 0; i < nueva_matriz.filas;i++){
		for (int j = 0; j < nueva_matriz.columnas;j++){
			nueva_matriz.datos[i][j] = matriz.datos[i][j];
		}
	} 
	
	return nueva_matriz;
}

Matriz2D_1 ExtraeSubmatriz (Matriz2D1 matriz,int fila_inicio, int columna_inicio,
                                             int fila_fin   , int columna_fin){
	Matriz2D_1 nueva_matriz = CreaMatriz(filas_inicio - filas_fin, 
	                                     columnas_inicio - columnas_fin);
	for (int i = 0; i < nueva_matriz.filas; i++){
		for(int j = 0; j < nueva_matriz.columnas; j++){
			nueva_matriz.datos[i][j] = 
			                         matriz[i + filas_inicio][j + columnas_inicio];
		}
	}
	return nueva_matriz;
}

Matriz2D_1 EliminaFila (int fila, Matriz2D_1 & matriz){
	Matriz2D_1 nueva_matriz = CreaMatriz(matriz.filas - 1, matriz.columnas);
	
	int i = 0;
	bool ha_pasado_fila = i > fila;

	while(i < nueva_matriz.filas){
		if (i != fila){
			if(!ha_pasado_fila)
				for (int j = 0; j < nueva_matriz.columnas;j++){
					nueva_matriz.datos[i][j] = matriz.datos[i][j];
				}
			else
				for (int j = 0; j < nueva_matriz.columnas;j++){
					nueva_matriz.datos[i][j] = matriz.datos[i+1][j];
				}
		}
		else{
			ha_pasado_fila = true;
		}
	}

	return nueva_matriz;
}
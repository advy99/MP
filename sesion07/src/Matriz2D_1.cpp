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

	return nueva_matriz;
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
	for (int i = 0; i < matriz.filas;i++){
		for (int j = 0; j < matriz.columnas;j++){
			cout << matriz.datos[i][j] << " ";
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

Matriz2D_1 ExtraeSubmatriz (Matriz2D_1 matriz,int fila_inicio, int columna_inicio,
                                             int fila_fin   , int columna_fin){
	Matriz2D_1 nueva_matriz = CreaMatriz(fila_inicio - fila_fin, 
	                                     columna_inicio - columna_fin);
	for (int i = 0; i < nueva_matriz.filas; i++){
		for(int j = 0; j < nueva_matriz.columnas; j++){
			nueva_matriz.datos[i][j] = 
			                     matriz.datos[i + fila_inicio][j + columna_inicio];
		}
	}
	return nueva_matriz;
}


//PRE: fila a eliminar valida
Matriz2D_1 EliminaFila (int fila, Matriz2D_1 matriz){
	Matriz2D_1 nueva_matriz = CreaMatriz(matriz.filas - 1, matriz.columnas);
	
	int i = 0;
	bool ha_pasado_fila = i > fila;

	while(i < nueva_matriz.filas){
		if (i != fila || ha_pasado_fila){
			if(!ha_pasado_fila)
				for (int j = 0; j < nueva_matriz.columnas;j++){
					nueva_matriz.datos[i][j] = matriz.datos[i][j];
				}
			else
				for (int j = 0; j < nueva_matriz.columnas;j++){
					nueva_matriz.datos[i][j] = matriz.datos[i+1][j];
				}
			i++;
		}
		else{
			ha_pasado_fila = true;
		}
		
	}

	return nueva_matriz;
}

//PRE: columna a eliminar valida

Matriz2D_1 EliminaColumna (int columna, Matriz2D_1 matriz ){
	Matriz2D_1 nueva_matriz = CreaMatriz(matriz.filas, matriz.columnas - 1);

	for (int i = 0; i < nueva_matriz.filas; i++){
		int j = 0;
		bool ha_pasado_columna = j > columna;

		while(j < nueva_matriz.columnas){
			
			if (j != columna || ha_pasado_columna){
				if (!ha_pasado_columna)
					nueva_matriz.datos[i][j] = matriz.datos[i][j];
				else
					nueva_matriz.datos[i][j] = matriz.datos[i][j+1];
				j++;
			}
			else
				ha_pasado_columna = true;
		}
	}

	return nueva_matriz;
}

Matriz2D_1 MatrizTraspuesta(Matriz2D_1 matriz){
	Matriz2D_1 nueva_matriz = CopiaMatriz(matriz);

	for (int i = 0; i < nueva_matriz.filas; i++){
		for (int  j = 0; j < nueva_matriz.columnas; j++){
			nueva_matriz.datos[j][i] = matriz.datos[i][j];
		}
	}

	return nueva_matriz;
}

Matriz2D_1 InvertirFilas (Matriz2D_1 matriz){
	Matriz2D_1 nueva_matriz = CopiaMatriz(matriz);
	int * copia_direccion_columnas [nueva_matriz.filas];

	for(int i = 0 ; i < nueva_matriz.filas; i++){
		copia_direccion_columnas[i] = nueva_matriz.datos[i];
	}

	for(int i = 0 ; i < nueva_matriz.filas; i++){
		nueva_matriz.datos[i] = copia_direccion_columnas[nueva_matriz.filas-1 -i];
	}

	return nueva_matriz;
}
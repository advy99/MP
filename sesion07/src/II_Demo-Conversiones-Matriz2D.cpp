/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 7 - Ejercicio 8 - Conversion entre matrices     **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "Matriz2D_1.h"
#include "Matriz2D_2.h"

using namespace std;

/******************************************************************************/

Matriz2D_2 FilasIndependientesAFilas (Matriz2D_1 &);
Matriz2D_1 FilasAFilasIndependientes (Matriz2D_2 &);

/******************************************************************************/

int main(){
	int filas, columnas;

	cout << "Introduce las filas : ";
	cin >> filas;
	cout << "Introduce las columnas : ";
	cin >> columnas;

	Matriz2D_1 matriz_1 = CreaMatrizAleatorios(filas, columnas);
	Matriz2D_2 matriz_2 = CreaMatrizAleatorios_2(filas, columnas);

	MostrarMatriz(matriz_1);
	cout << endl << endl;
	MostrarMatriz(matriz_2);

	cout << endl << "Ejecutamos las funciones "<< endl;

	Matriz2D_2 m1_convertida = FilasIndependientesAFilas(matriz_1);
	Matriz2D_1 m2_convertida = FilasAFilasIndependientes(matriz_2);

	MostrarMatriz(m1_convertida);
	cout << endl << endl;
	MostrarMatriz(m2_convertida);

	return 0;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      FilasIndependientesAFilas : Convierte Matriz2D_1 a Matriz2D_2       **/
/**                                                                          **/
/**   RECIBE : matriz                                                        **/
/**                                                                          **/
/**   DEVUELVE : matriz                                                      **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_2 FilasIndependientesAFilas (Matriz2D_1 & matriz){
	//Creamos una Matriz2D_2 del mismo tamaño que la Matriz2D_1
	Matriz2D_2 nueva_matriz = CreaMatriz_2(matriz.filas, matriz.columnas);

	//Copiamos su contenido
	for (int i = 0; i < nueva_matriz.filas; i++){
		for (int j = 0; j < nueva_matriz.filas; j++){
			nueva_matriz.datos[i][j] = matriz.datos[i][j];
		}
	}
	LiberaMatriz2D_1 (matriz);

	return nueva_matriz;
}

/******************************************************************************/
/**                                                                          **/
/**      FilasAFilasIndependientes : Convierte Matriz2D_2 a Matriz2D_1       **/
/**                                                                          **/
/**   RECIBE : matriz                                                        **/
/**                                                                          **/
/**   DEVUELVE : matriz                                                      **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_1 FilasAFilasIndependientes (Matriz2D_2 & matriz){
	//Creamos una Matriz2D_1 del mismo tamaño que la Matriz2D_2
	Matriz2D_1 nueva_matriz = CreaMatriz(matriz.filas, matriz.columnas);

	//Copiamos su contenido
	for (int i = 0; i < nueva_matriz.filas; i++){
		for (int j = 0; j < nueva_matriz.filas; j++){
			nueva_matriz.datos[i][j] = matriz.datos[i][j];
		}
	}
	LiberaMatriz2D_2(matriz);

	return nueva_matriz;
}
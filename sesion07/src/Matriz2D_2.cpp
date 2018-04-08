/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**                                                         **/
/*************************************************************/

#include "Matriz2D_2.h"
#include "TipoBase.h"
#include "GeneradorAleatorioEnteros.h"
#include <iostream>

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      CreaMatriz_2: Crea un matriz dinamica                               **/
/**                                                                          **/
/**   RECIBE : entero con las filas                                          **/
/**            entero con las columnas                                       **/
/**                                                                          **/
/**   DEVUELVE : Estructura en la que se almacena la matriz                  **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_2 CreaMatriz_2(int filas, int columnas){
	Matriz2D_2 nueva_matriz;

	//Establecemos filas y columnas
	nueva_matriz.filas = filas;
	nueva_matriz.columnas = columnas;

	//Creamos la columna principal, y la fila principal
	nueva_matriz.datos = new TipoBase * [filas];
	nueva_matriz.datos[0] = new TipoBase [filas*columnas];

	//A cada elemento de la columna principal, le asignamos una parte de
	//tamaño columnas en la fila principal
	for (int i = 1; i < filas; i++){
		nueva_matriz.datos[i] = nueva_matriz.datos[i - 1] + columnas;
	}

	return nueva_matriz;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      LiberaMatriz2D_1 : Libera un matriz dinamica                        **/
/**                                                                          **/
/**   RECIBE : Matriz                                                        **/
/**                                                                          **/
/******************************************************************************/


void LiberaMatriz2D_2 (Matriz2D_2 & matriz){

	//Elimina la fila principal
	delete [] matriz.datos[0];

	//Elimina la columna principal
	delete [] matriz.datos;


	//Establecemos filas y columnas a 0 y datos apuntara a una posicion nula
	matriz.filas = 0;
	matriz.columnas = 0;

	matriz.datos = 0;
}


/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      CreaMatriz: Crea un matriz dinamica y lee los valores               **/
/**                                                                          **/
/**   RECIBE : entero con las filas                                          **/
/**            entero con las columnas                                       **/
/**                                                                          **/
/**   DEVUELVE : Estructura en la que se almacena la matriz                  **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_2 CreaYLeeMatriz_2(int filas, int columnas){
	//Creamos la matriz
	Matriz2D_2 nueva_matriz = CreaMatriz_2 (filas, columnas);

	//Recorremos la matriz, pidiendo valores
	for (int i = 0; i < nueva_matriz.filas;i++){
		for (int j = 0; j < nueva_matriz.columnas;j++){
			cout << "Introduce el elemento " << i << ", " << j << " :";
			cin >> nueva_matriz.datos[i][j];
		}
	} 

	//Devolvemos la matriz
	return nueva_matriz;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      CreaMatrizAleatorios: Crea un matriz dinamica y la rellena de       **/
/**                           numeros aleatorios                             **/
/**                                                                          **/
/**   RECIBE : entero con las filas                                          **/
/**            entero con las columnas                                       **/
/**                                                                          **/
/**   DEVUELVE : Estructura en la que se almacena la matriz                  **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_2 CreaMatrizAleatorios_2(int filas, int columnas){
	//Crea la matriz
	Matriz2D_2 nueva_matriz = CreaMatriz (filas, columnas);
	//Establecemos el generador de aleatorios entre 1 y 500
	GeneradorAleatorioEnteros generador(1,500);

	//Recorremos la matriz, asignando numeros aleatorios
	for (int i = 0; i < nueva_matriz.filas;i++){
		for (int j = 0; j < nueva_matriz.columnas;j++){
			nueva_matriz.datos[i][j] = generador.Siguiente();
		}
	} 
	//Devolvemos la matriz
	return nueva_matriz;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      Mostrar: Muestra por consola una matriz                             **/
/**                                                                          **/
/**   RECIBE : Una matriz                                                    **/
/**                                                                          **/
/******************************************************************************/

void MostrarMatriz (Matriz2D_2 matriz){
	//Recorre la matriz, mostrando cada elemento por pantalla
	for (int i = 0; i < matriz.filas;i++){
		for (int j = 0; j < matriz.columnas;j++){
			cout << matriz.datos[i][j] << " ";
		}
		cout << endl;
	} 
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      CopiaMatriz: Copia una matriz dada en otra                          **/
/**                                                                          **/
/**   RECIBE : Matriz                                                        **/
/**                                                                          **/
/**   DEVUELVE : Copia de la matriz                                          **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_2 CopiaMatriz (Matriz2D_2 matriz){
	//Creamos una nueva matriz con las mismas dimensiones
	Matriz2D_2 nueva_matriz = CreaMatriz(matriz.filas, matriz.columnas);

	//Copiamos los elementos de una matriz en otra
	for (int i = 0; i < nueva_matriz.filas;i++){
		for (int j = 0; j < nueva_matriz.columnas;j++){
			nueva_matriz.datos[i][j] = matriz.datos[i][j];
		}
	} 
	
	//Devolvemos la nueva matriz
	return nueva_matriz;
}


/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      ExtraeSubmatriz: Extrae una submatriz a partir de otra              **/
/**                                                                          **/
/**   RECIBE : entero con la fila inicial                                    **/
/**            entero con la columna inicial                                 **/
/**            entero con la fila final                                      **/
/**            entero con la columna final                                   **/
/**            matriz                                                        **/
/**                                                                          **/
/**   DEVUELVE : Estructura en la que se almacena la submatriz               **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_2 ExtraeSubmatriz (Matriz2D_2 matriz,int fila_inicio, int columna_inicio,
                                             int fila_fin   , int columna_fin){
	//Creamos nueva matriz con las dimensiones necesarias
	Matriz2D_2 nueva_matriz = CreaMatriz_2(fila_inicio - fila_fin, 
	                                     columna_inicio - columna_fin);

	//Copiamos desde fila_inicio y columna_inicio hasta fila_fin, columna_fin
	for (int i = 0; i < nueva_matriz.filas; i++){
		for(int j = 0; j < nueva_matriz.columnas; j++){
			nueva_matriz.datos[i][j] = 
			                     matriz.datos[i + fila_inicio][j + columna_inicio];
		}
	}
	//Devolvemos la matriz
	return nueva_matriz;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      EliminaFila : Elimina una fila de la matriz                         **/
/**                                                                          **/
/**   RECIBE : entero con la fila                                            **/
/**            matriz                                                        **/
/**                                                                          **/
/**   DEVUELVE : Estructura en la que se almacena la matriz sin la fila      **/
/**                                                                          **/
/**   PRE: Numero de fila valido                                             **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_2 EliminaFila (int fila, Matriz2D_2 & matriz){
	Matriz2D_2 nueva_matriz = CreaMatriz_2(matriz.filas - 1, matriz.columnas);
	
	int i = 0;
	bool ha_pasado_fila = i > fila;

	//Mientras queden filas, si no ha llegado a la fila a eliminar, copia la
	//matriz normal, si llega o sobrepasa la fila, copia la siguiente

	//Sabemos que no nos saldremos de memoria ya que sabemos que matriz tiene
	//una fila mas
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

	LiberaMatriz2D_2(matriz);

	return nueva_matriz;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      EliminaColumna : Elimina una columna                                **/
/**                                                                          **/
/**   RECIBE : entero con la columna                                         **/
/**            matriz                                                        **/
/**                                                                          **/
/**   DEVUELVE : Estructura en la que se almacena la matriz sin la columna   **/
/**                                                                          **/
/**   PRE: Numero de columna valido                                          **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_2 EliminaColumna (int columna, Matriz2D_2 & matriz ){
	Matriz2D_2 nueva_matriz = CreaMatriz_2(matriz.filas, matriz.columnas - 1);

	//Mientras queden columnas, si no ha llegado a la columna a eliminar, copia la
	//matriz normal, si llega o sobrepasa la columna, copia la siguiente

	//Sabemos que no nos saldremos de memoria ya que sabemos que matriz tiene
	//una columna mas

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

	LiberaMatriz2D_2(matriz);

	return nueva_matriz;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      MatrizTraspuesta : Devuelve la traspuesta a una matriz              **/
/**                                                                          **/
/**   RECIBE : matriz                                                        **/
/**                                                                          **/
/**   DEVUELVE : Estructura en la que se almacena la matriz traspuesta       **/
/**                                                                          **/
/**   PRE: Numero de filas y columnas iguales                                **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_2 MatrizTraspuesta(Matriz2D_2 & matriz){
	
	//Si el numero de filas y columnas es distinto, devuelve la misma matriz

	if (matriz.filas != matriz.columnas)
		return matriz;

	Matriz2D_2 nueva_matriz = CopiaMatriz(matriz);

	//Copiamos las posiciones i,j en las casillas j,i para trasponerla

	for (int i = 0; i < nueva_matriz.filas; i++){
		for (int  j = 0; j < nueva_matriz.columnas; j++){
			nueva_matriz.datos[j][i] = matriz.datos[i][j];
		}
	}
	LiberaMatriz2D_2(matriz);


	return nueva_matriz;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      InvertirFilas : Invierte las filas a una matriz                     **/
/**                                                                          **/
/**   RECIBE : matriz                                                        **/
/**                                                                          **/
/**   DEVUELVE : Estructura en la que se almacena la matriz traspuesta       **/
/**                                                                          **/
/**   PRE: Numero de filas y columnas iguales                                **/
/**                                                                          **/
/******************************************************************************/

Matriz2D_2 InvertirFilas (Matriz2D_2 & matriz){
	Matriz2D_2 nueva_matriz = CopiaMatriz(matriz);
	int * copia_direccion_columnas [nueva_matriz.filas];

	for(int i = 0 ; i < nueva_matriz.filas; i++){
		copia_direccion_columnas[i] = nueva_matriz.datos[i];
	}

	//Asignamos las direcciones en orden inverso

	for(int i = 0 ; i < nueva_matriz.filas; i++){
		nueva_matriz.datos[i] = copia_direccion_columnas[nueva_matriz.filas-1 -i];
	}

	LiberaMatriz2D_2(matriz);

	return nueva_matriz;
}

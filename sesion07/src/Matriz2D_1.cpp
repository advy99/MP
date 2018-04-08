/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**                                                         **/
/*************************************************************/

#include "Matriz2D_1.h"
#include "TipoBase.h"
#include "GeneradorAleatorioEnteros.h"
#include <iostream>

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      CreaMatriz: Crea un matriz dinamica                                 **/
/**                                                                          **/
/**   RECIBE : entero con las filas                                          **/
/**            entero con las columnas                                       **/
/**                                                                          **/
/**   DEVUELVE : Estructura en la que se almacena la matriz                  **/
/**                                                                          **/
/******************************************************************************/


Matriz2D_1 CreaMatriz(int filas, int columnas){
	Matriz2D_1 nueva_matriz;

	//Establecemos las filas y columnas de la matriz
	nueva_matriz.filas = filas;
	nueva_matriz.columnas = columnas;

	//Creamos el vector de filas, de tipo TipoBase (ver TipoBase.h)
	nueva_matriz.datos = new TipoBase * [filas];

	//En cada fila, creamos un nuevo vector de columnas
	for (int i = 0; i < filas; i++){
		nueva_matriz.datos[i] = new TipoBase [columnas];
	}

	//Devolvemos la matriz
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

void LiberaMatriz2D_1 (Matriz2D_1 & matriz){
	//Eliminamos las filas una a una
	for (int i = 0; i < matriz.filas; i++){
		delete [] matriz.datos[i];
	}

	//Liberamos la columna que contenia a las filas
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

Matriz2D_1 CreaYLeeMatriz(int filas, int columnas){
	//Creamos la matriz
	Matriz2D_1 nueva_matriz = CreaMatriz (filas, columnas);

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

Matriz2D_1 CreaMatrizAleatorios(int filas, int columnas){
	//Crea la matriz
	Matriz2D_1 nueva_matriz = CreaMatriz (filas, columnas);
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

void MostrarMatriz (Matriz2D_1 matriz){
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
/**            Matriz donde realizar la copia                                **/
/**                                                                          **/
/**                                                                          **/
/******************************************************************************/

void CopiaMatriz (Matriz2D_1 matriz, Matriz2D_1 & nueva_matriz){
	//Liberamos y reservamos el espacio, por si tienen tamaño distinto
	LiberaMatriz2D_1(nueva_matriz);
	nueva_matriz = CreaMatriz(matriz.filas, matriz.columnas);

	//Copiamos los elementos de una matriz en otra
	for (int i = 0; i < nueva_matriz.filas;i++){
		for (int j = 0; j < nueva_matriz.columnas;j++){
			nueva_matriz.datos[i][j] = matriz.datos[i][j];
		}
	} 
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

Matriz2D_1 ExtraeSubmatriz (Matriz2D_1 matriz,int fila_inicio, int columna_inicio,
                                             int fila_fin   , int columna_fin){
	//Creamos nueva matriz con las dimensiones necesarias
	Matriz2D_1 nueva_matriz = CreaMatriz(fila_inicio - fila_fin, 
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

void EliminaFila (int fila, Matriz2D_1 & matriz){
	//Creamos matriz con una fla menos
	Matriz2D_1 nueva_matriz = CreaMatriz(matriz.filas - 1, matriz.columnas);
	
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
	//Cambiamos la nueva matriz
	CopiaMatriz(nueva_matriz, matriz);
	//Liberamos la nueva_matriz;
	LiberaMatriz2D_1(nueva_matriz);
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

void EliminaColumna (int columna, Matriz2D_1 & matriz ){
	//Crea una matriz con una columna menos
	Matriz2D_1 nueva_matriz = CreaMatriz(matriz.filas, matriz.columnas - 1);

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

	CopiaMatriz(nueva_matriz, matriz);
	//Liberamos la matriz copia
	LiberaMatriz2D_1(nueva_matriz);
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

void MatrizTraspuesta(Matriz2D_1 & matriz){

	//Si el numero de filas y columnas es distinto, no es posible
	if (matriz.filas == matriz.columnas){
		

		Matriz2D_1 nueva_matriz = CreaMatriz(matriz.filas,matriz.columnas);

		//Copiamos las posiciones i,j en las casillas j,i para trasponerla
		for (int i = 0; i < nueva_matriz.filas; i++){
			for (int  j = 0; j < nueva_matriz.columnas; j++){
				nueva_matriz.datos[j][i] = matriz.datos[i][j];
			}
		}
		CopiaMatriz(nueva_matriz, matriz);
		LiberaMatriz2D_1(nueva_matriz);
	}

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

void InvertirFilas (Matriz2D_1 & matriz){
	int * copia_direccion_columnas [matriz.filas];

	//Creamos una copia de las direcciones de las columnas
	for(int i = 0 ; i < matriz.filas; i++){
		copia_direccion_columnas[i] = matriz.datos[i];
	}

	//Asignamos las direcciones en orden inverso
	for(int i = 0 ; i < matriz.filas; i++){
		matriz.datos[i] = copia_direccion_columnas[matriz.filas-1 -i];
	}

}

#ifndef MATRIZ2D_1
#define MATRIZ2D_1

#include "TipoBase.h"

typedef struct {
	TipoBase ** datos;
	int filas;
	int columnas;

} Matriz2D_1 ; 

Matriz2D_1 CreaMatriz(int, int);
void LiberaMatriz2D_1 (Matriz2D_1 &);
Matriz2D_1 CreaYLeeMatriz(int, int);
Matriz2D_1 CreaMatrizAleatorios(int , int );
void MostrarMatriz (Matriz2D_1 );
void CopiaMatriz (Matriz2D_1 , Matriz2D_1 &);
Matriz2D_1 ExtraeSubmatriz (Matriz2D_1, int , int , int , int );
void EliminaFila (int , Matriz2D_1 & );
void EliminaColumna (int , Matriz2D_1 & );
void MatrizTraspuesta(Matriz2D_1 & );
void InvertirFilas (Matriz2D_1 & );

#endif
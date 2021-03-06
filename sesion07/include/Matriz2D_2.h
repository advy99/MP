#ifndef MATRIZ2D_2
#define MATRIZ2D_2

#include "TipoBase.h"

typedef struct {
	TipoBase ** datos;
	int filas;
	int columnas;

} Matriz2D_2 ; 

Matriz2D_2 CreaMatriz_2(int, int);
void LiberaMatriz2D_2 (Matriz2D_2 &);
Matriz2D_2 CreaYLeeMatriz_2(int, int);
Matriz2D_2 CreaMatrizAleatorios_2(int , int );
void MostrarMatriz (Matriz2D_2 );
void CopiaMatriz (Matriz2D_2, Matriz2D_2 &);
Matriz2D_2 ExtraeSubmatriz (Matriz2D_2, int , int , int , int );
void EliminaFila (int , Matriz2D_2 & );
void EliminaColumna (int , Matriz2D_2 & );
void MatrizTraspuesta(Matriz2D_2 & );
void InvertirFilas (Matriz2D_2 & );

#endif
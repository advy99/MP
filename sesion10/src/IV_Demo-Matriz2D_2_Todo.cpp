/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 3 - Matriz2D - Operadores        **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "TipoBase.h"
#include "Matriz2D_2.h"
#include <cstring>

using namespace std;

int main(){
	Matriz2D_2 mi_matriz(2,3);

	Matriz2D_2 mi_matriz2(2,3);

	mi_matriz.RellenarAleatorios(1, 20);
	mi_matriz2.RellenarAleatorios(1, 20);

	PintaMatriz(mi_matriz, "Matriz 1:");
	PintaMatriz(mi_matriz2, "Matriz 2:");

	PintaMatriz(mi_matriz + mi_matriz2 , "Matriz 1 + Matriz 2:");
	PintaMatriz(mi_matriz + 2 , "Matriz 1 + 2:");
	PintaMatriz(1 + mi_matriz2 , "1 + Matriz 2:");

	PintaMatriz(mi_matriz - mi_matriz2 , "Matriz 1 - Matriz 2:");
	PintaMatriz(mi_matriz - 2 , "Matriz 1 - 2:");
	PintaMatriz(1 - mi_matriz2 , " 1 - Matriz 2:");



	return 0;
}
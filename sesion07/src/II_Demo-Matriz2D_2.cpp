/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 7 - Ejercicio 7 - Matriz dinamica               **/
/**                          unica fila                     **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "Matriz2D_2.h"
#include "TipoBase.h"

using namespace std;

int main(){
	int filas, columnas;

	cout << "Introduce el numero de filas de la matriz : ";
	cin >> filas;

	cout << "Introduce el numero de columnas de la matriz : ";
	cin >> columnas;

	Matriz2D_2 matriz = CreaMatrizAleatorios_2(filas,columnas);

	cout << "Matriz :" << endl << endl;
	MostrarMatriz(matriz);
	cout << endl << endl;

	cout << "Introduce una fila a eliminar : ";
	cin >> filas;

	cout << "Matriz sin la fila " << filas <<" : " << endl << endl;
	EliminaFila(filas,matriz);
	MostrarMatriz(matriz);
	cout << endl<< endl;

	cout << "Introduce una columna a eliminar : ";
	cin >> columnas;

	cout << "Matriz sin la columna " << columnas <<" : " << endl << endl;
	EliminaColumna(columnas,matriz);
	MostrarMatriz(matriz);
	cout << endl<< endl;

	cout << "Matriz traspuesta : " << endl << endl;
	MatrizTraspuesta(matriz);
	MostrarMatriz(matriz);

	cout << endl<< endl;

	cout << "Matriz con filas invertidas : " << endl << endl;
	InvertirFilas(matriz);
	MostrarMatriz(matriz);
	cout << endl << endl;


	return 0;
}
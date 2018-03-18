/*************************************************************/
/**																			**/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 5                                               **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "GestionVector.h"
#include "Lectura.h"

using namespace std;

int main( int argc, char * argv[] ){
	const int TOPE = 100;
	int vector[TOPE];
	int total_utilizados = 0;
	int tope_izda = 0;
	int tope_dcha = TOPE;
	char mensaje [] = " Vector ";

	if (argc == 1){
		total_utilizados = TOPE;
	}
	else if(argc == 2){
		total_utilizados = CadenaAEntero( argv[1] );
		tope_dcha = total_utilizados;
	}else if(argc == 3){
		total_utilizados = CadenaAEntero( argv[1] );
		tope_dcha = CadenaAEntero( argv[2] );
	}else if(argc == 4){
		total_utilizados = CadenaAEntero( argv[1] );
		tope_izda = CadenaAEntero( argv[2] );
		tope_dcha = CadenaAEntero( argv[3] );
	}else
		return 1; // Error, numero incorrecto de parametros

	if (tope_izda > tope_dcha || tope_dcha > total_utilizados)
		return 2; //Error, entrada de datos erronea

	RellenarVectorAleatorios(vector, total_utilizados);

	MostrarVector( mensaje , vector, total_utilizados);

	cout << endl;
	cout << "El mayor elemento entre las casillas " << tope_izda << " y " 
        << tope_dcha - 1 << " es : " << *PosMayor(vector, tope_izda, tope_dcha);
	cout << endl;

	return 0;
}
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 11 - RedCiudades                 **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "RedCiudades.h"

using namespace std;

int main(){
	int num_c;

	cout << "Introduce el numero de ciudades: ";
	cin >> num_c;

	RedCiudades red(num_c);

	LeeRedCiudades(red);
	cout << endl << endl;

	for(int i = 0; i < red.NumCiudades(); i++){
		for(int j = 0; j < red.NumCiudades() ; j++){
			cout << red.Distancia(i,j) << "   ";
		}
		cout << endl;
	}
		cout << endl << endl;


	MejoresEscalas(red);
	//cout << endl << red.MejorEscalaEntre(0,3) << endl;

}
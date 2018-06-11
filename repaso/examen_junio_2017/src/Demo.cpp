/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 11 - RedCiudades                 **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <fstream>
#include "RedCiudades.h"

using namespace std;

int main(int argc, char * argv[]){
	if (argc != 2){
		cerr << "ERROR: Numero erroneo de argumentos " << endl
			  << "Uso: " << argv[0] << " <fichero>" << endl;
		exit(0);
	}

	ifstream fi;

	fi.open(argv[1]);

	if (fi.fail()){
		cerr << "ERROR: No se ha podido abrir " << argv[1] << endl;
		exit(1);
	}

	fi.close();

	RedCiudades red(argv[1]);


	int mejor_escala;

	for (int i = 1; i <= red.NumCiudades(); i++){
		for (int j = i + 1; j <= red.NumCiudades(); j++){
			if (red.Distancia(i,j) == 0){
				mejor_escala = red.MejorEscalaEntre(i,j);

				if (mejor_escala != -1){
					cout << "La mejor escala entre " << red.NombreCiudad(i)
					     << " y " << red.NombreCiudad(j) << " es " 
						  << red.NombreCiudad(mejor_escala) << endl;
				}
			}
		}
	}

	return 0;
}
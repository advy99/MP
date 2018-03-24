/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 6 - Ejercicio 17 - Encontrar inicio palabras    **/
/**                                                         **/
/*************************************************************/


#include <iostream>

using namespace std;

/*******************************************************************************/

int encuentra_palabras (char ** , char * );

/*******************************************************************************/

int main( void ){
	const int MAX_CARACTERES = 100;
	const int MAX_PALABRAS = 20;

	char la_cadena[MAX_CARACTERES];
	char * las_palabras[MAX_PALABRAS];

	int num_palabras;

	cout << "Introduce la cadena : ";
	cin.getline(la_cadena, MAX_CARACTERES);

	num_palabras = encuentra_palabras(las_palabras, la_cadena);

	cout << endl << la_cadena << endl;
	cout << endl << "Tiene " << num_palabras << " palabras." << endl;

	for (int i = 0; i < num_palabras; i++){
		cout << "La palabra " << i + 1 << " comienza por la letra "
		     << *las_palabras[i] << endl;
	}
}

/*******************************************************************************/


int encuentra_palabras (char ** palabras, char * cadena){
	int n_palabras = 0;
	int i = 1;


	if (cadena[0] != ' '){
		palabras[n_palabras] = cadena;
		n_palabras++;
	}

	while( cadena[i] ){
		if (cadena [i] != ' ' && cadena[i - 1] == ' ' ){
			palabras[n_palabras] = &cadena[i];
			n_palabras++;
		}

		i++;
	}

	return n_palabras;
}

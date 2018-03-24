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

const int MAX_CARACTERES = 100;
const int MAX_PALABRAS = 20;

/*******************************************************************************/

int encuentra_palabras (char ** , const char * );

/*******************************************************************************/

int main( void ){
	

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


int encuentra_palabras (char ** palabras, const char * cadena){
	int n_palabras = 0;
	int i = 1;
	bool salir = false;

	if (cadena[0] != ' '){
		palabras[n_palabras] = (char *) cadena;
		n_palabras++;
	}

	while( cadena[i] && !salir){
		

		if (cadena [i] != ' ' && cadena[i - 1] == ' ' ){
			
			if(n_palabras < MAX_PALABRAS){
				palabras[n_palabras] = (char *) &cadena[i];
				n_palabras++;
			}
			else{
				cerr << endl << "AVISO: Numero de palabras demasiado grande." << endl 
				     << "No se tendran en cuenta mas palabras" << endl;
				salir = true;
			}

		}

		i++;
	}

	return n_palabras;
}

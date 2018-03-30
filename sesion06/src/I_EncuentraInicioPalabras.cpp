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

int encuentra_palabras (char ** , char * );

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

	return 0;
}

/*******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Busca el inicio de las palabras en una frase          **/
/**                                                         **/
/**   Recibe: Cadena donde se almacenara el resultado       **/
/**           Frase a buscar el inicio de las palabras      **/
/**                                                         **/
/**   Devuelve: Numero de palabras de la cadena             **/
/**                                                         **/
/*************************************************************/


int encuentra_palabras (char ** palabras, char * cadena){
	int n_palabras = 0;
	int i = 1;
	bool salir = false;

	//Comprobamos si el primer caracter es un espacio y comienza una palabra
	if ( ! isspace(cadena[0]) ){
		palabras[n_palabras] = cadena;
		n_palabras++;
	}


	//Recorre la cadena 
	while( cadena[i] && !salir){

		//Si una casilla es un caracter y la anterior un espacio,
		//comienza una palabra
		if ( ! isspace(cadena[i]) && isspace (cadena[i - 1]) ){
			
			//Si queda capacidad se añade, si no avisa del error
			if(n_palabras < MAX_PALABRAS){
				palabras[n_palabras] = &cadena[i];
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

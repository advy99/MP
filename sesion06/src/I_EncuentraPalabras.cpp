/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 6 - Ejercicio 18 - Encontrar inicio y fin de    **/
/**                          las palabras                   **/
/**                                                         **/
/*************************************************************/


#include <iostream>

using namespace std;

const int MAX_CARACTERES = 100;
const int MAX_PALABRAS = 20;

/*******************************************************************************/

struct info_palabra {
	char * inicio;
	char * fin;
};

/*******************************************************************************/

int encuentra_palabras (info_palabra * , const char * );

/*******************************************************************************/

int main( void ){
	

	char la_cadena[MAX_CARACTERES];
	info_palabra las_palabras[MAX_PALABRAS];

	int num_palabras;

	cout << "Introduce la cadena : ";
	cin.getline(la_cadena, MAX_CARACTERES);

	num_palabras = encuentra_palabras(las_palabras, la_cadena);

	cout << endl << la_cadena << endl;
	cout << endl << "Tiene " << num_palabras << " palabras." << endl;

	for (int i = 0; i < num_palabras; i++){
		cout << "La palabra " << i + 1 << " comienza por la letra " 
		     << *las_palabras[i].inicio << " y finaliza con la letra "
			  << *las_palabras[i].fin << endl;
	}
}

/*******************************************************************************/


int encuentra_palabras (info_palabra * palabras, const char * cadena){
	int n_palabras = 0;
	int i = 1;
	bool salir = false;

	if (cadena[0] != ' '){
		palabras->inicio = (char *) cadena;
		n_palabras++;
		if (cadena[1] == ' ')
			palabras->fin = (char *) &cadena[0];
	}

	while( cadena[i] && !salir){
		
		if(n_palabras < MAX_PALABRAS){

			if (cadena [i] != ' ' &&
			   (cadena[i - 1] == ' ' || cadena[i + 1] == ' ' 
				                      || cadena[i + 1] == '\0' )){	
				
				if (cadena[i - 1] == ' '){
					(palabras+n_palabras)->inicio = (char *) &cadena[i];
					n_palabras++;

				}
				if (cadena[i + 1] == ' ' || cadena[i + 1] == '\0' ) {
					(palabras+n_palabras - 1 )->fin = (char *) &cadena[i];	
				}
			}
		}
		else{
				cerr << endl << "AVISO: Numero de palabras demasiado grande." << endl 
				     << "No se tendran en cuenta mas palabras" << endl;
				salir = true;
		}
		i++;
	}

	return n_palabras;
}

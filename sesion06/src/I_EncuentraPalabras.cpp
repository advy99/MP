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

int encuentra_palabras (info_palabra * , char * );
void muestra_palabras (info_palabra * , const int );

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


	muestra_palabras (las_palabras, num_palabras);

	return 0;
	
}

/*******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Busca el inicio y fin de las palabras en una frase    **/
/**                                                         **/
/**   Recibe: Estructura donde se almacenara el resultado   **/
/**           Frase a buscar el inicio de las palabras      **/
/**                                                         **/
/**   Devuelve: Numero de palabras de la cadena             **/
/**                                                         **/
/*************************************************************/

int encuentra_palabras (info_palabra * palabras, char * cadena){
	int n_palabras = 0;
	int i = 1;
	bool salir = false;

	//Comprobamos si el primer caracter es un espacio y comienza una palabra
	//si lo es, comprobamos el siguiente por si acaba la palabra
	if ( ! isspace(cadena[0]) ){
		palabras->inicio = cadena;
		n_palabras++;
		if ( isspace(cadena[1]) )
			palabras->fin = &cadena[0];
	}

	//Recorre la cadena 
	while( cadena[i] && !salir){
		
		
		if(n_palabras < MAX_PALABRAS){

		//Si una casilla es un caracter y la anterior o la siguien un espacio,
		//comienza o acaba una palabra
			if ( !isspace(cadena[i]) ){
				
				if (isspace(cadena[i - 1])){
					(palabras+n_palabras)->inicio = &cadena[i];
					n_palabras++;
				}
				if (isspace(cadena[i + 1]) || !( cadena[i + 1] ) ) {
					(palabras+n_palabras -1 )->fin = &cadena[i];	
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

/*******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Muestra las palabras de una cadena                    **/
/**                                                         **/
/**   Recibe: Estructura con inicio y fin de las palabras   **/
/**           Numero de palabras                            **/
/**                                                         **/
/**   Devuelve: Numero de palabras de la cadena             **/
/**                                                         **/
/*************************************************************/

void muestra_palabras (info_palabra * palabra, const int N_PALABRAS){

	for (int i = 0; i < N_PALABRAS; i++){
		int j = 0;
		cout << "La palabra " << i + 1 << " comienza por la letra " 
		     << *(palabra+i)->inicio << " y finaliza con la letra "
			  << *(palabra+i)->fin << endl;

		cout << "La palabra es " ;

		//Mientras el puntero al inicio sea menor que el puntero al fin
		//muestra el caracter al que apunta
		while ( ((palabra+i)->inicio)+j <= ((palabra+i)->fin) ){
			cout << *((palabra+i)->inicio + j);
			j++;
		}
 
		cout << endl;
	}
}
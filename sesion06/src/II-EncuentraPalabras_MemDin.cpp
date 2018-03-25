/*************************************************************/
/**                                                         **/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 6 - Ejercicio 2 - Encontrar palabras            **/
/**                          memoria dinamica               **/
/**                                                         **/
/*************************************************************/

#include <iostream>

using namespace std;

const int MAX_CARACTERES = 100;
const int MAX_PALABRAS = 20;

/*******************************************************************************/

struct info_palabra {
	char ** inicio = new char * [MAX_PALABRAS];
	char ** fin = new char * [MAX_PALABRAS];
};

/*******************************************************************************/

enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};
char ** Redimensiona (char ** , TipoRedimension , int & );
int encuentra_palabras (info_palabra * &, char * );
void muestra_palabras (info_palabra * & , const int );

/*******************************************************************************/

int main( void ){
	

	char la_cadena[MAX_CARACTERES];
	info_palabra * las_palabras = new info_palabra;

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
 

int encuentra_palabras (info_palabra * & palabras, char * cadena){
	int capacidad = MAX_PALABRAS;
	int n_palabras = 0;
	int i = 1;

	if ( ! isspace(cadena[0])){
		(palabras->inicio)[0] = cadena;
		n_palabras++;

		
		if ( isspace(cadena[1]) ){
			(palabras->fin)[0] = &cadena[0];
		}
	}

	while( cadena[i] ){
		
		if(n_palabras < capacidad){

			if ( ! isspace(cadena [i]) ){	
				
				if ( isspace(cadena[i - 1]) ){
					(palabras->inicio)[n_palabras] = &cadena[i];
					n_palabras++;

				}
				if ( isspace(cadena[i + 1]) || !( cadena[i + 1] ) ) {
					(palabras->fin)[n_palabras - 1] = &cadena[i];	

				}
			}
			i++;
		}
		else{
			TipoRedimension tipo = TipoRedimension::EnBloques;
			palabras->inicio = Redimensiona(palabras->inicio, tipo, capacidad);
			capacidad = n_palabras;
			palabras->fin = Redimensiona(palabras->fin, tipo, capacidad);
		}
	}

	TipoRedimension tipo = TipoRedimension::DeUnoEnUno;
	
	capacidad = n_palabras;
	palabras->inicio = Redimensiona(palabras->inicio, tipo, capacidad);
	capacidad = n_palabras;
	palabras->fin = Redimensiona(palabras->fin, tipo, capacidad);

	return n_palabras;
}

/*******************************************************************************/

void muestra_palabras (info_palabra * & palabra, const int N_PALABRAS){
	for (int i = 0; i < N_PALABRAS; i++){
		int j = 0;
		cout << "La palabra " << i + 1 << " comienza por la letra " 
		     << *(palabra->inicio)[i] << " y finaliza con la letra "
			  << *(palabra->fin)[i] << endl;

		cout << "La palabra es " ;

		while ( (palabra->inicio)[i]+j <= (palabra->fin)[i] ){
			cout << *(palabra->inicio[i]+j);
			j++;
		}

		cout << endl;
	}
}

/*******************************************************************************/

char ** Redimensiona (char ** p, TipoRedimension tipo, int & cap){
	
	const int TAM_BLOQUE = 10;
	int tam_redimensionado;

	if (tipo == TipoRedimension::DeUnoEnUno){
		tam_redimensionado = cap + 1;
		
	}else if (tipo == TipoRedimension::EnBloques){
		tam_redimensionado = cap + TAM_BLOQUE;

	}else if (tipo == TipoRedimension::Duplicando){
		tam_redimensionado = 2 * cap;
	}

	char ** nuevo_vector = new char * [tam_redimensionado];

	for (int i = 0; i < cap; i++){
		nuevo_vector[i] = p[i];
	}

	cap = tam_redimensionado;

	delete [] p;

	return nuevo_vector;
}
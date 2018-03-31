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

	delete [] las_palabras->inicio;
	delete [] las_palabras->fin;

	delete las_palabras;

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

int encuentra_palabras (info_palabra * & palabras, char * cadena){
	int capacidad = MAX_PALABRAS;
	int n_palabras = 0;
	int i = 1;

	//Comprobamos si el primer caracter es un espacio y comienza una palabra
	//si lo es, comprobamos el siguiente por si acaba la palabra
	if ( ! isspace(cadena[0])){
		(palabras->inicio)[0] = cadena;
		n_palabras++;

		
		if ( isspace(cadena[1]) ){
			(palabras->fin)[0] = &cadena[0];
		}
	}

	//Recorre la cadena 
	while( cadena[i] ){
		
		//Si la hay espacio para la palabra, la añade y pasa a la siguiente
		//casilla
		//Si no hay espacio redimensiona el vector de inicio y fin.
		if(n_palabras < capacidad){

			//Si una casilla es un caracter y la anterior o la siguien un espacio,
			//comienza o acaba una palabra
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

	//Ajusta la capacidad del vector al tamaño que esta utilizando,
	//usando el tamaño estrictamente necesario
	TipoRedimension tipo = TipoRedimension::DeUnoEnUno;
	
	capacidad = n_palabras;
	palabras->inicio = Redimensiona(palabras->inicio, tipo, capacidad);
	capacidad = n_palabras;
	palabras->fin = Redimensiona(palabras->fin, tipo, capacidad);

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

void muestra_palabras (info_palabra * & palabra, const int N_PALABRAS){
	for (int i = 0; i < N_PALABRAS; i++){
		int j = 0;
		cout << "La palabra " << i + 1 << " comienza por la letra " 
		     << *(palabra->inicio)[i] << " y finaliza con la letra "
			  << *(palabra->fin)[i] << endl;

		cout << "La palabra es " ;

		//Mientras el puntero al inicio sea menor que el puntero al fin
		//muestra el caracter al que apunta
		while ( (palabra->inicio)[i]+j <= (palabra->fin)[i] ){
			cout << *(palabra->inicio[i]+j);
			j++;
		}

		cout << endl;
	}
}

/*******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Redimensiona un vector de char                        **/
/**                                                         **/
/**   Recibe: Vector a redimensionar                        **/
/**           Tipo de redimension a realizar                **/
/**           Capacidad del vector                          **/
/**                                                         **/
/**   Devuelve: Direccion de memoria del vector             **/
/**           redimensionado                                **/
/**                                                         **/
/*************************************************************/


char ** Redimensiona (char ** p, TipoRedimension tipo, int & cap){
	
	const int TAM_BLOQUE = 10;
	int tam_redimensionado;

	//Ajusta el tamanio del nuevo vector segun el tipo de redimension
	if (tipo == TipoRedimension::DeUnoEnUno){
		tam_redimensionado = cap + 1;
		
	}else if (tipo == TipoRedimension::EnBloques){
		tam_redimensionado = cap + TAM_BLOQUE;

	}else if (tipo == TipoRedimension::Duplicando){
		tam_redimensionado = 2 * cap;
	}

	//Declara un nuevo vector con el nuevo tamaño;
	char ** nuevo_vector = new char * [tam_redimensionado];

	//Copia el contenido del antiguo vector en el nuevo
	for (int i = 0; i < cap; i++){
		nuevo_vector[i] = p[i];
	}
	//Actualiza la capacidad
	cap = tam_redimensionado;

	//Libera la memoria consumida por el vector anriguo
	delete [] p;

	//Devolvemos la direccion del nuevo vector
	return nuevo_vector;
}
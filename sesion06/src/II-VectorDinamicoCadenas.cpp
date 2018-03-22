/*************************************************************/
/**																			**/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 6 - Ejercicio 3 - Vector dinámico de cadenas    **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <cstring>

/*******************************************************************************/

enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};
int * Redimensiona (int * , TipoRedimension , int & );

/*******************************************************************************/


using namespace std;

int main(){
	string cadena;
	string cadena_completa = "";
	int num_lineas = 0;
	int tam_cadena_completa;
	int j = 0;

	while (getline (cin,cadena)){
		cadena_completa = cadena_completa + cadena;
		cadena_completa.push_back('\n');
		num_lineas++;
	}

	tam_cadena_completa = cadena_completa.size();

	char ** cadenas = new char * [num_lineas];

	for (int i = 0; i < num_lineas; i++){
		string fila = "";

		while (cadena_completa[j] != '\n'){
			fila = fila + cadena_completa[j];
			j++;
		}
		j++;

		char * linea = new char [fila.size()];

		strcpy(linea, fila.c_str());

		cadenas[i] = linea;
	}
	
	for (int i = 0; i < num_lineas; i++){
		cout << cadenas[i] << endl;
	}

}

/*******************************************************************************/

int * Redimensiona (int * p, TipoRedimension tipo, int & cap){
	
	const int TAM_BLOQUE = 10;
	int tam_redimensionado;

	if (tipo == TipoRedimension::DeUnoEnUno){
		tam_redimensionado = cap + 1;
		
	}else if (tipo == TipoRedimension::EnBloques){
		tam_redimensionado = cap + TAM_BLOQUE;

	}else if (tipo == TipoRedimension::Duplicando){
		tam_redimensionado = 2 * cap;
	}

	int * nuevo_vector = new int [tam_redimensionado];

	for (int i = 0; i < cap; i++){
		nuevo_vector[i] = p[i];
	}

	cap = tam_redimensionado;

	delete [] p;

	return nuevo_vector;
}
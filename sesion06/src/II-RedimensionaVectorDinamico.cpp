/*************************************************************/
/**                                                         **/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 6 - Ejercicio 1 - Redimensionar vector dinamico **/
/**                                                         **/
/**  PRE : Se introduce un valor entero o la cadena FIN     **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

/*******************************************************************************/

enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};
int * Redimensiona (int * , TipoRedimension , int & );

/*******************************************************************************/



int main (int argc, char * argv[]){
	const int TAM = 5;
	const char TERMINADOR [] = "FIN"; 

	TipoRedimension tipo_redimension;

	if (argc > 2){
		cerr << "ERROR: Numero erroneo de parametros";
		exit(1);
	}
	
	if (argc > 1){
		if ( atoi(argv[1]) == 1 ) tipo_redimension = TipoRedimension::DeUnoEnUno;

		else if ( atoi(argv[1]) == 2 )
			tipo_redimension = TipoRedimension::EnBloques;

		else if ( atoi(argv[1]) == 3 )
			tipo_redimension = TipoRedimension::Duplicando;

		else {
			cerr << "ERROR: Argumento no valido";
			exit(2);
		}

	}
	else
		tipo_redimension = TipoRedimension::DeUnoEnUno;
	

	int tam_util = TAM;
	int usados = 0;
	int * vector = new int [TAM];
	char valor[TAM];
	bool salir;

	cout << "Introduce un valor : ";
	cin.getline(valor,TAM);
	

	salir = strcmp(valor,TERMINADOR) == 0;


	while ( !salir ){

		if(usados == tam_util){
			vector = Redimensiona (vector, tipo_redimension, tam_util);
		}
		vector[usados] = atoi(valor);
		usados++;

		cout << "Introduce un valor : ";
		cin.getline(valor,TAM);

		salir = strcmp(valor,TERMINADOR) == 0;

	}

	cout << "Casillas usadas : " << usados << endl;
	cout << "Casillas totales : " << tam_util << endl; 
	for (int i = 0; i < usados; i++){
		cout << vector[i] << " " ;
	}

}

/*******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Redimensiona un vector de int                         **/
/**                                                         **/
/**   Recibe: Vector a redimensionar                        **/
/**           Tipo de redimension a realizar                **/
/**           Capacidad del vector                          **/
/**                                                         **/
/**   Devuelve: Direccion de memoria del vector             **/
/**             redimensionado                              **/
/**                                                         **/
/*************************************************************/

int * Redimensiona (int * p, TipoRedimension tipo, int & cap){
	
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
	int * nuevo_vector = new int [tam_redimensionado];

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
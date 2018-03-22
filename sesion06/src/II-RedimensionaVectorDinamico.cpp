/*************************************************************/
/**																			**/                                                         
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

/*******************************************************************************/

enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};
int * Redimensiona (int * , TipoRedimension , int & );

/*******************************************************************************/


using namespace std;

int main (int argc, char * argv[]){
	const int TAM = 30;
	const int TAM_BLOQUE = 20;

	TipoRedimension tipo_redimension;

	if (argc > 2){
		cerr << "ERROR: Numero erroneo de parametros";
		exit(1);
	}
	
	if (argc > 1){
		if ( atoi(argv[1]) == 1 ) tipo_redimension = DeUnoEnUno;
		else if ( atoi(argv[1]) == 2 ) tipo_redimension = EnBloques;
		else if ( atoi(argv[1]) == 3 ) tipo_redimension = Duplicando;
		else {
			cerr << "ERROR: Argumento no valido";
			exit(2);
		}

	}
	else
		tipo_redimension = DeUnoEnUno;
	

	int tam_util = TAM;
	int usados = 0;
	int * vector = new int [TAM];
	char valor[TAM];
	bool salir;

	cout << "Introduce un valor : ";
	cin.getline(valor,TAM);

	salir = strcmp(valor,"FIN") == 0;

	while ( !salir ){
		
		if(usados == tam_util){
			Redimensiona (vector, tipo_redimension, tam_util);
		}

		vector[usados] == atoi(valor);
		usados++;

		cout << "Introduce un valor : ";
		cin.getline(valor,TAM);

		salir = strcmp(valor,"FIN") == 0;

	}

}

int * Redimensiona (int * p, TipoRedimension tipo, int & cap){

}
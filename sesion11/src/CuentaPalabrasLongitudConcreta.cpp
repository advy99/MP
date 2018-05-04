/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 13 -Contar palabras con longitud **/
/**                                                         **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int main( int argc, char * argv [] ){

	const int TAM_MAX = 256;

	int longitud;

	//Cogemos el caracter dado por parametro
	if (argc == 2)
		longitud = atoi(argv[1]);
	else{
		cerr << "ERROR: Numero de argumentos erroneo" << endl;
		exit(1);
	}


	char c[TAM_MAX];
	char * p = c;
	int num_letras;
	int contador = 0;

	//Hacemos las lecturas
	while( cin >> c ){

		//Apuntamos al principio de la palabra
		p = c;
		num_letras = 0;
		//Contamos la longitud de la palabra
		while (*p){
			num_letras++;
			p++;
		}

		//Si la longitud concuerda, añadimos uno al contador
		if (num_letras == longitud){
			contador++;
		}
	}

	cout << "En el texto hay " << contador << " palabras con longitud "
	     << longitud << endl;

	return 0;
}
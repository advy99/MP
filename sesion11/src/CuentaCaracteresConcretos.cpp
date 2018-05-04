/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Ejercicio 12 - Contar caracteres           **/
/**                                                         **/
/**                                                         **/
/*************************************************************/

#include <iostream>

using namespace std;

int main( int argc, char * argv [] ){

	char a_contar;

	//Cogemos el caracter dado por parametro
	if (argc == 2)
		a_contar = argv[1][0];
	else{
		cerr << "ERROR: Numero de argumentos erroneo" << endl;
		exit(1);
	}


	char c;
	int contador = 0;

	//Hacemos las lecturas
	while( cin.get(c) ){
		//Si el caracter es el que queremos buscar, aumentados el contador
		if(c == a_contar)
			contador++;
	}

	cout << "En el texto aparece " << contador << " veces el caracter "
	     << a_contar << endl;

	return 0;
}
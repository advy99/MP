/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 12 - Ejercicio 1 - Numerar lineas               **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <fstream>
#include "Util.h"

using namespace std;

int main( int argc, char * argv[] ){

	//Comprobamos que tenemos un numero correcto de argumentos
	if( argc != 3 ){
		cerr << "ERROR: Numero erroneo de argumentos" << endl
			  << "Forma de uso : " << argv[0] << " <fichero>  <nuevo_fichero> ";
		exit(1);
	}

	//Comprobamos que el primer fichero existe
	if ( !ExisteFichero(argv[1]) ){
		cerr << "ERROR: No se pudo abrir " << argv[1] << endl;
		exit(1);
	}

	//Comprobamos si el segundo fichero existe
	if (ExisteFichero(argv[2])){
		//Avisamos de que continuar el programa implica vaciar el fichero 2
		cout << "ATENCION: Continuar con la ejecucion borrara el contenido de "
		     << argv[2] << endl << endl;

		char c;
		cout << "¿Esta seguro de que quiere continuar [S/N]?" << endl; 
		cin >> c;

		if (c != 'S'){
			exit(1);
		}
	}
	

	ifstream fi;
	ofstream fo;
	string linea;
	int contador = 1;

	fi.open(argv[1]);
	fo.open(argv[2]);

	//Comprobamos que se ha podido crear argv[2]
	if (!fo){
		cerr << "ERROR: No se ha podido crear " << argv[2] << endl;
		fi.close();
		exit(1);
	}

	//Comenzamos a leer
	getline(fi, linea);

	//Mientras no alcanze el final de fichero, mandamos a fo con contador y
	//la linea seguida de un salto de linea

	//PRE: El fin de fichero esta un una nueva linea, es decir, el fin de fichero
	//no esta precedido por nada en la misma linea

	while(!fi.eof()){
		fo << contador << " " << linea << endl;
		contador++;
		getline(fi, linea);

	}
	
	//Una vez acabamos de leer y escribir, cerramos los ficheros
	fi.close();
	fo.close();

	cout << endl << "Se ha ejecutado correctamente " << endl;

	return 0;
}

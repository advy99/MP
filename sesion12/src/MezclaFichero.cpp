/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 12 - Ejercicio 2 - Mezclar ficheros             **/
/**                                                         **/
/**  PRE: Los datos de los ficheros estan ordenados         **/
/**                                                         **/
/*************************************************************/


#include <iostream>
#include <fstream>

#include "Util.h"

using namespace std;

int main(int argc, char * argv[]){

	//Comprobamos que tenemos un numero correcto de argumentos
	if( argc != 4 ){
		cerr << "ERROR: Numero erroneo de argumentos" << endl
			  << "Forma de uso : " << argv[0] << " <fichero>  <fichero>"
			  << " <fichero_salida> " << endl;
		exit(1);
	}

	//Comprobamos que el primer fichero existe
	if ( !ExisteFichero(argv[1]) ){
		cerr << "ERROR: No se pudo abrir " << argv[1] << endl;
		exit(1);
	}

	//Comprobamos que el segundo fichero existe
	if ( !ExisteFichero(argv[2]) ){
		cerr << "ERROR: No se pudo abrir " << argv[2] << endl;
		exit(1);
	}

	//Comprobamos si el tercer fichero existe
	if (ExisteFichero(argv[3])){
		//Avisamos de que continuar el programa implica vaciar el fichero 3
		cout << "ATENCION: Continuar con la ejecucion borrara el contenido de "
		     << argv[3] << endl << endl;

		char c;
		cout << "¿Esta seguro de que quiere continuar [S/N]?" << endl; 
		cin >> c;

		if (c != 'S'){
			exit(1);
		}
	}


	ifstream fi;
	ifstream fi2;
	ofstream fo;
	double numero_f1;
	double numero_f2;

	//Abrimos archivos
	fi.open(argv[1]);
	fi2.open(argv[2]);
	fo.open(argv[3]);

	//Comprobamos que no hay error al crear el ultimo
	if (!fo){
		cerr << "ERROR: No se pudo crear " << argv[3];
		fi.close();
		exit(1);
	}

	//Comenzamos la lectura
	fi >> numero_f1;
	fi2 >> numero_f2;

	while (!fi.eof() && !fi2.eof()){

		//Leemos de un flujo o de otro, dependiendo de cual tiene numeros mas
		//pequeños
		if(numero_f1 < numero_f2){
			fo << numero_f1 << endl;
			fi >> numero_f1;
		}
		else{
			fo << numero_f2 << endl;
			fi2 >> numero_f2;
		}

	}

	//Completamos los numeros que quedan, por si fi no ha acabado
	while (!fi.eof()){
		fo << numero_f1 << endl;
		fi >> numero_f1;
	}

	//Completamos los numeros que quedan, por si fi2 no ha acabado
	while (!fi2.eof()){
		fo << numero_f2 << endl;
		fi2 >> numero_f2;
	}

	//Cerramos los ficheros
	fi.close();
	fi2.close();
	fo.close();

	cout << endl << "Se ha ejecutado correctamente " << endl;
		
	return 0;
}
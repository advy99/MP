/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 13 - Ejercicio 6 - Reconstruye                  **/
/**                                                         **/
/*************************************************************/


#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "Util.h"

using namespace std;

int main(int argc, char * argv[]){

	if (argc != 2){
		cerr << "ERROR: Numero de argumentos erroneo" << endl
			  << "Uso: " << argv[0] << " <fichero> "
		     << endl;
		exit(1);
	}

	string archivo_datos = ".";
	archivo_datos = ".";
	archivo_datos += argv[1];
	archivo_datos += ".ctrl";


	//Comprobamos que existe el fichero de control
	if (!ExisteFichero(archivo_datos)){
		cerr << "ERROR: No se puede leer " << archivo_datos
			  << ", necesario para ejecutar esta aplicacion." << endl;
		exit (1);
	}

	//Creamos el buffer
	const int TAM_BUFFER = 256;

	char buffer [TAM_BUFFER];

	ifstream fi;
	ofstream fo;

	string archivo_recuperar;
	int num_partes;

	//Sacamos el nombre del archivo y el numero de partes del archivo de control
	fi.open(archivo_datos.c_str());

	getline(fi, archivo_recuperar);

	fi >> num_partes;

	//Cerramos archivo de control
	fi.close();

	//Abrimos lo que sera el fichero reconstruido
	fo.open(archivo_recuperar, ios::app|ios::binary);

	ostringstream oss;

	//Sabemos el numero de partes, y que la primera parte comienza en 1
	for (int i = 1; i <= num_partes; i++){
		//Establecemos el nombre de la parte i
		oss << archivo_recuperar << '_' << setfill('0') << setw(3) << i;

		//Abrimos la parte i
		fi.open(oss.str(), ios::binary);

		//Leemos el contenido de la parte i y la mandamos al archivo unico
		while(fi.read(buffer, TAM_BUFFER)){
			fo.write(buffer, TAM_BUFFER);
		}

		fo.write(buffer, fi.gcount());

		//Acabamos con la parte i,cerramos fichero y reseteamos nombre de la parte
		fi.close();
		
		oss.str("");
		oss.clear();

	}

	
	return 0;
}
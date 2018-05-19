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



	if (!ExisteFichero(archivo_datos)){
		cerr << "ERROR: No se puede leer " << archivo_datos
			  << ", necesario para ejecutar esta aplicacion." << endl;
		exit (1);
	}

	const int TAM_BUFFER = 256;

	char buffer [TAM_BUFFER];

	ifstream fi;
	ofstream fo;

	string archivo_recuperar;
	int num_partes;

	fi.open(archivo_datos.c_str());

	getline(fi, archivo_recuperar);

	fi >> num_partes;

	fi.close();

	fo.open(archivo_recuperar, ios::app|ios::binary);

	ostringstream oss;

	for (int i = 1; i <= num_partes; i++){
		oss << archivo_recuperar << '_' << setfill('0') << setw(3) << i;

		fi.open(oss.str(), ios::binary);

		while(fi.read(buffer, TAM_BUFFER)){
			fo.write(buffer, TAM_BUFFER);
		}

		fo.write(buffer, fi.gcount());

		fi.close();

		oss.str("");
		oss.clear();

	}

	


	return 0;
}
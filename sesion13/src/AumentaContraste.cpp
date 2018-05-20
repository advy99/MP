/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 13 - Ejercicio 12 - Aumenta contraste           **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "Util.h"

using namespace std;

int main(int argc, char * argv[]){

	const string PGM = "P5";
	
	if (argc != 3){
		cerr << "ERROR: Numero erroneo de argumentos" << endl
			  << "Uso : " << argv[1] << " <imagen.pgm> <imagen_final.pgm>"
			  << endl;
		exit(1);
	}

	ifstream fi;
	ofstream fo;

	fi.open(argv[1]);
	fo.open(argv[2]);

	string tipo_archivo;

	fi >> tipo_archivo;
	fo << tipo_archivo;

	if (tipo_archivo != PGM){

		fi.close();

		cerr << "ERROR: No ha introducido un archivo PGM" << endl;
		exit(1);
	}

	getline(fi, tipo_archivo);

	while(!fi.eof() && (tipo_archivo[0] == '#' || tipo_archivo.empty())){
		fo << tipo_archivo << endl;
		getline(fi, tipo_archivo);
	}	

	int alto, ancho, valor_gris;

	istringstream iss;

	iss.str(tipo_archivo);

	iss >> alto;
	iss >> ancho;
	fo << alto << " " << ancho << endl;


	fi >> valor_gris;
	fo << valor_gris << endl;

	int pos_inicio = fi.tellg();

	fi.close();
	fo.close();


	fi.open(argv[1],  ios::binary);
	fo.open(argv[2],  ios::app|ios::binary);

	fi.seekg(pos_inicio);

	int tam_buffer = log2(valor_gris + 1) / 8;

	char buffer[tam_buffer];

	int valor_pixel;

	while (fi.read(reinterpret_cast<char*>(buffer), tam_buffer)){

		for(int i = 0; i < tam_buffer; i++){
			buffer[i] = valor_gris / buffer[i];			
		}

		fo.write(reinterpret_cast<char*>(buffer), tam_buffer);
	}

	fi.close();
	fo.close();



	return 0;

}

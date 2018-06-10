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

	string cad, cabecera;

	fi >> cad;
	cabecera = cad;

	if (cad != PGM){

		fi.close();

		cerr << "ERROR: No ha introducido un archivo PGM" << endl;
		exit(2);
	}

	//Lectura de cabecera, se duplica en el archivo final
	getline(fi, cad);
	

	while(!fi.eof() && (cad[0] == '#' || cad.empty())){
		getline(fi, cad);
	}	

	int columnas, filas, valor_gris;

	istringstream iss;

	iss.str(cad);

	iss >> columnas;
	iss >> filas;

	fi >> valor_gris;

	const int TAM_BUFFER = filas * columnas;

	unsigned char buffer [TAM_BUFFER];

	fi.read( (char *) buffer, TAM_BUFFER );
	fi.close();

	for (int i = 0; i < TAM_BUFFER; i++){
		if ( (int) buffer[i] > umbral )
			buffer[i] = (unsigned char) 255;
		else
			buffer[i] = (unsigned char) 0;
	}


	fo.open(argv[3]);

	if (fo.fail()){
		cerr << "ERROR: No se ha podido crear " << argv[2] << endl;
		exit(4);
	}

	fo << cabecera << endl;
	fo << "# imagen con contraste ampliado" << endl;
	fo << columnas << " " << filas << endl;
	fo << valor_gris << endl;
	
	fo.write( (char *) buffer, TAM_BUFFER );

	fo.close();

	return 0;



}

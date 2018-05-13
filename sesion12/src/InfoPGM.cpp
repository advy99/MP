#include <iostream>
#include <fstream>
#include <sstream>
#include "Util.h"

using namespace std;

int main(int argc, char * argv[]){

	string linea_comentario;

	//Comprobamos el numero de argumentos
	if (argc != 2){
		cerr << "ERROR: Numero incorrecto de argumentos" << endl;
		exit(1);
	}

	//Comprobamos que existe el fichero
	if(!ExisteFichero(argv[1])){
		cerr << "ERROR: No existe el fichero " << argv[1] << endl;
		exit(1);
	}

	ifstream fi;
	istringstream iss;
	fi.open(argv[1]);

	char tipo_fichero[100];
	int ancho, alto, valor_gris;

	//El primer dato es el tipo de fichero, lo leemos y lo mostramos
	fi >> tipo_fichero;
	cout << tipo_fichero << endl;

	//Leemos las lineas vacias y de comentarios, y las mostramos
	getline(fi, linea_comentario);

	while(!fi.eof() && (linea_comentario[0] == '#' || linea_comentario.empty())){
		cout << linea_comentario << endl;

		getline(fi, linea_comentario);
	}

	//En line_comentario, queda la linea con el tamaño de la imagen

	iss.str(linea_comentario);
	//Leemos el tamaño del string
	iss >> ancho;
	iss >> alto;

	//El siguiente valor a procesar es el tono de gris
	fi >> valor_gris;

	//Mostramos los valores tomados
	cout << ancho << " " << alto << endl;
	cout << valor_gris << endl;

	return 0;


}

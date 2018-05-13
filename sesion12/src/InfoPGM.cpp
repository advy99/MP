#include <iostream>
#include <fstream>
#include <sstream>
#include "Util.h"

using namespace std;

int main(int argc, char * argv[]){

	string linea_comentario;

	if (argc != 2){
		cerr << "ERROR: Numero incorrecto de argumentos" << endl;
		exit(1);
	}

	if(!ExisteFichero(argv[1])){
		cerr << "ERROR: No existe el fichero " << argv[1] << endl;
		exit(1);
	}

	ifstream fi;
	istringstream iss;
	fi.open(argv[1]);

	char tipo_fichero[100];
	int ancho, alto, valor_gris;

	fi >> tipo_fichero;
	cout << tipo_fichero << endl;

	getline(fi, linea_comentario);

	while(!fi.eof() && (linea_comentario[0] == '#' || linea_comentario.empty())){
		cout << linea_comentario << endl;

		getline(fi, linea_comentario);
	}

	iss.str(linea_comentario);
	iss >> ancho;
	iss >> alto;
	fi >> valor_gris;

	cout << ancho << " " << alto << endl;
	cout << valor_gris << endl;

	return 0;


}

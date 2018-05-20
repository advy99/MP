/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 13 - Ejercicio 11 - Binariza imagen             **/
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
	
	if (argc != 4){
		cerr << "ERROR: Numero erroneo de argumentos" << endl
			  << "Uso : " << argv[1] << " <imagen.pgm> <umbral> <imagen_final.pgm>"
			  << endl;
		exit(1);
	}

	int umbral = atoi(argv[2]);

	ifstream fi;
	ofstream fo;

	fi.open(argv[1]);
	fo.open(argv[3]);

	string tipo_archivo;

	fi >> tipo_archivo;
	fo << tipo_archivo;

	if (tipo_archivo != PGM){

		fi.close();

		cerr << "ERROR: No ha introducido un archivo PGM" << endl;
		exit(1);
	}

	//Lectura de cabecera, se duplica en el archivo final
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

	//Guardamos la posicion donde acaba la cabecera
	int pos_inicio = fi.tellg();

	//Cerramos los archivos
	fi.close();
	fo.close();

	//Abrimos los archivos, en modo binario

	fi.open(argv[1],  ios::binary);

	//El de salida, lo abrimos para añadir, colocandose al final del documento
	//es decir, el final de la cabecera
	fo.open(argv[3],  ios::app|ios::binary);

	//Avanzamos hasta pos_inicio en el original, que es donde acaba la cabecera
	fi.seekg(pos_inicio);

	//Calculamos el tamaño del buffer, es decir, cuantos bytes ocupa un pixel
	//(en principio, usando imagenes PGM de 255 niveles, se usara 1)
	int tam_buffer = log2(valor_gris + 1) / 8;

	char buffer[tam_buffer];

	int valor_pixel;

	//Comenzamos a leer
	while (fi.read(reinterpret_cast<char*>(buffer), tam_buffer)){
		//Calculamos el valor del pixel actual
		//NOTA
		//  Usando imagenes PGM de 255 niveles de gris, podriamos usar un unico
		//char, y este contendria toda la informacion, se realiza de esta forma
		//por si varia el nivel de gris de la imagen
		valor_pixel = 0;
		for(int i = 0; i < tam_buffer; i++){
			valor_pixel += buffer[i];
		}

		// Si esta por debajo del umbral se establece a 0 (negro), si esta
		//por encima a blanco
		if (valor_pixel <= umbral){
			for(int i = 0; i < tam_buffer; i++){
				buffer[i] = 0;

			}
		}
		else{
			for(int i = 0; i < tam_buffer; i++){
				buffer[i] = 255;

			}
		}

		fo.write(reinterpret_cast<char*>(buffer), tam_buffer);
	}

	fi.close();
	fo.close();

	return 0;
}
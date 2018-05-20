/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 13 - Ejercicio 5 - ParteFichero                 **/
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

	if (argc != 3){
		cerr << "ERROR: Numero de argumentos erroneo" << endl
			  << "Uso: " << argv[0] << " <fichero> <tamaño> "
		     << endl;
		exit(1);
	}

	if (!ExisteFichero(argv[1])){
		cerr << "ERROR: No se puede leer " << argv[1] << endl;
		exit (1);
	}

	//El tamaño del buffer sera el tamaño de cada parte
	int tam_bytes = atoi(argv[2]);

	char buffer [tam_bytes];

	ifstream fi;
	ofstream fo;
	ostringstream nombre_parte;	

	string nombre;
	

	int contador = 1;

	fi.open(argv[1], ios::binary);

	//Comenzamos a leer en el buffer
	while(fi.read(buffer, tam_bytes)){
		
		//Creamos el nombre de cada parte
		nombre_parte << argv[1] << '_' << setfill('0') << setw(3) << contador;

		nombre = nombre_parte.str();

		//"Abrimos" (creamos), cada parte
		fo.open(nombre, ios::binary);

		//Copiamos el contenido del buffer en esa parte, y cerramos el fichero
		fo.write(buffer, tam_bytes);

		fo.close();

		//Sumamos 1 al contador, y reseteamos el nombre
		contador++;
		nombre_parte.str("");
		nombre_parte.clear();

	}

	//Creamos la ultima parte, de tamaño 0 < parte < tam_buffer
	nombre_parte << argv[1] << '_' << setfill('0') << setw(3) << contador;

	nombre = nombre_parte.str();

	//Escribimos la ultima parte
	fo.open(nombre, ios::binary);

	//El tamaño de esta parte nos lo da gcount, ya que no ha sido capaz de 
	//leer el buffer completo
	fo.write(buffer, fi.gcount());

	fo.close();

	fi.close();

	nombre_parte.str("");
	nombre_parte.clear();

	//Creamos el archivo de control
	nombre_parte << '.' << argv[1] << ".ctrl";

	nombre = nombre_parte.str();

	fo.open(nombre);

	//Mandamos el nombre del archivo y el numero de partes al archivo de control
	fo << argv[1] << endl << contador << endl;

	fo.close();

	return 0;
}
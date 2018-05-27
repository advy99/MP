/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Ejercicio opcional - Eliminar cabecera de un PGM       **/
/**  Nos queda como resultado los bytes de la imagen        **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include "Util.h"

using namespace std;

int main (int argc, char **argv)
{

	/************************************************************************/
	// Comprobación del número y validez de los argumentos
	
	if (argc != 3) {
		cerr << "Error: Numero de argumentos incorrecto" << endl;
		cerr << "Formato: " << argv[0] << " <fich_in> <fich_out>" << endl;
		exit (1);
	}

	//Comprobar la existencia del fichero de entrada
	
	if (!ExisteFichero(argv[1])) {
		cerr << "Error: No pudo abrirse " << argv[1] << endl;
		exit (2);
	}

	int tam = TamanioFichero (argv[1]);  // Calcular el tamanio del fichero


	/************************************************************************/
	// Leer datos del fichero PGM y cargar los píxeles de la imagen en memoria
	
	int filas;
	int columnas;
	
	const int TAM = 256;
	char cad [TAM];


	// Abrir fichero y leer cabecera PGM
 
	ifstream fi (argv[1], ios::binary);  // Abrir el fichero para lectura

	fi.getline (cad, TAM); // Leer primera linea ("numero magico")

	if (strcmp("P5", cad)) {
		cerr << "Error: " << argv[1] << " NO es un fichero PGM." << endl;
		return (0);
	}

	// Lectura y salto de comentarios

	do {
		fi.getline (cad, TAM);
	} while (cad[0]=='#');

	istringstream iss_cad;
	iss_cad.str (cad); // Asociar cad-->iss_cad
	
	iss_cad >> columnas >> filas;

	// Leer el maximo valor
	fi.getline (cad, TAM);

	// Reservar espacio para la imagen
	unsigned char *image = new unsigned char[filas*columnas];

	// La imagen empieza en la posición actual del fichero 
	
	int pos_init_image = fi.tellg ();
	
	// Comprobamos si realmente quedan filas*columnas pixeles en el fichero
	
	if ((pos_init_image + (filas*columnas)) != tam) {
		cerr << "Error: La imagen es inconsistente con dimensiones." << endl;
		exit(3);
	}

	// Leer el bloque de imagen del fichero y guardarlo en "image"

	fi.seekg (tam-(filas*columnas), ios::beg); // Inicio del bloque imagen
											  // (por si acaso)

	fi.read (reinterpret_cast<char*> (image), filas*columnas);

	if (fi.gcount() != filas*columnas) {
		cerr << "Error: No se pudo leer correctamente la imagen." << endl;
		exit(4);
	}

	fi.close (); // Cerrar el fichero


	/************************************************************************/
	// Guardar la imagen sin la cabecera
	
	ofstream fo;

	fo.open (argv[2], ios::binary); // Abrir el fichero para escritura
	if (fo.fail()) {
		cerr << "Error: " << argv[2] << " no puede crearse" << endl << endl;
		exit (5);
	}
	
	// Escribir píxeles procesados
	
	fo.write ((const char *) image, filas*columnas); 

	if (fo.fail()) {
		cerr << "Error: No se pudo escribir totalmente el resultado" << endl;
		exit (6);
	}

	fo.close (); // Cerrar el fichero
	
	/***********************************************************************/
	// Finalizar: liberar memoria
	
	delete [] image;

	/***********************************************************************/

	return (0);

}
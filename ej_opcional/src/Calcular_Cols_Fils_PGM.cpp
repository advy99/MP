/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Ejercicio opcional - Calcular filas y columnas         **/
/**                                                         **/
/*************************************************************/

//Recibe un fichero de bytes, sin informacion alguna del PGM, por lo que sera
//necesario eliminar la cabecera del PGM antes de ejecutar este programa 
//(Ver binario : Eliminar_Cabecera_PGM )


#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "Util.h"

using namespace std;

int main(int argc, char * argv[]){
	if (argc != 3){
		cerr << "ERROR: Numero de argumentos." << endl
		     << "Uso: " << argv[0] << " <archivo_bytes> <img_final.pgm> " << endl
			  << "IMPORTANTE: El primer archivo no contiene informacion de "
			  << "cabecera sobre el PGM. (Ver: bin/Eliminar_Cabecera_PGM ) "
			  << endl;

		exit(1);
	}

	if (!ExisteFichero(argv[1])){
		cerr << "ERROR: No existe " << argv[1] << endl;
		exit(2);
	}

	if (ExisteFichero(argv[2])){
		char confirmacion;

		do {
			cout << "AVISO: Se eliminara el contenido de " << argv[2]
			<< "¿desea continuar? [S/N] :" ;

			cin >> confirmacion;
			confirmacion = tolower(confirmacion);
		}while (confirmacion != 'n' && confirmacion != 's');

		if (confirmacion == 'n')
			exit(3);
	}


	//Calculamos tamaño del archivo
	int num_bytes = TamanioFichero(argv[1]);

	cout << num_bytes << endl;

	// Reservar espacio para la imagen
	unsigned char *imagen = new unsigned char[num_bytes];

	// Abrir fichero sin cabecera 
	ifstream fi (argv[1], ios::binary);  // Abrir el fichero para lectura

	fi.read(reinterpret_cast<char*> (imagen), num_bytes);

	fi.close (); // Cerrar el fichero

	int filas = 1;
	int columnas = num_bytes;

	//Criterio para la evaluacion de una imagen:
	//
	//              Sumatoria(valor_pixel_superior - valor_pixel_inferior) ^ 2
	//              -----------------------------------------------------------
	//                                columnas
	//evaluacion= ---------------------------------------------------------------
	//                                  filas - 1


	double evaluacion = 0.0;

	// Si tiene 1 fila, la evaluacion de esa imagen tiende a infinito, al dividir
	//por 0.

	evaluacion = INFINITY;

	int nuevas_filas;
	int nuevas_columnas;
	double nueva_evaluacion;
	double dif_pixeles = 0.0;
	double ev_fila = 0.0;

	for (int i = 2; i < num_bytes; i++){
		nueva_evaluacion = 0.0;

		nuevas_filas = i;
		nuevas_columnas = num_bytes / i;

		if( nuevas_filas * nuevas_columnas == num_bytes ){

			//Evaluacion de una imagen de tamaño j x k
			for (int j = 0; j < nuevas_filas - 1; j++){
				ev_fila = 0.0;

				for (int k = 0; k < nuevas_columnas; k++){
									//Pixel k de la fila j
					dif_pixeles = (int) imagen[k + (nuevas_columnas * j) ] - 
									//Pixel k de la fila j + 1
									(int) imagen[k + (nuevas_columnas * (j+1)) ];


					ev_fila += pow (dif_pixeles, 2);
				}

				ev_fila = ev_fila / nuevas_columnas;

				nueva_evaluacion += ev_fila / (nuevas_filas - 1);

			}
			
			cout << endl << endl;
			cout << nuevas_filas << " " << nuevas_columnas << " " << nueva_evaluacion;

			if (nueva_evaluacion < evaluacion){
				evaluacion = nueva_evaluacion;
				filas = nuevas_filas;
				columnas = nuevas_columnas;
			}
		}
	}

	cout << endl << "La imagen tiene " << filas << " filas y " << columnas
	             << " columnas." << endl;


	ofstream fo (argv[2], ios::binary);

	if(fo.fail()){
		cerr << "ERROR: No se ha podido crear " << argv[2] << endl;
		exit (4);
	}

	fo << "P5" << endl;
	fo << "#imagen con filas y columnas recalculadas" << endl;
	fo << columnas << " " << filas << endl;
	fo  << "255" << endl; // Valor maximo
	
	fo.write ((const char *) imagen, filas*columnas); 

	if (fo.fail()) {
		cerr << "Error: No se pudo escribir totalmente el resultado" << endl;
		exit (5);
	}

	fo.close();


	delete [] imagen;

	return 0;
	

}
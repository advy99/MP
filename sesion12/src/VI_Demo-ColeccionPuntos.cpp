/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 12 - Ejercicio 9 - Clase Puntos                 **/
/**                                                         **/
/*************************************************************/
//
// RELACIÓN DE PROBLEMAS 6
// EJERCICIO 9
//
/*	
	Se emplea la clase "ColeccionPuntos2D" para almacenar y gestionar una 
	colección de datos de tipo "Punto2D".

	En primer lugar pide los datos necesarios para crear un objeto 
	"Circunferencia" y lo crea.  
	Después crea una colección tomando los puntos de un fichero y 
	seguidamente lee un número indeterminado de datos de tipo "Punto2D" 
	(del teclado) y los incorpora a la colección. 
	Finalmente muestra cuáles de los puntos almacenados en la colección están 
	en el círculo delimitado por la circunferencia.
*/

/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "Util.h"
#include "Punto2D.h"
#include "ColeccionPuntos2D.h"
#include "Circunferencia.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	/***********************************************************************/
	// Comprobar argumentos, y su validez

	if (argc !=2) {
		cerr << "Error: Faltan argumentos. Uso : "; 
		cerr << argv[0] << " <fich_puntos> " << endl;
		cerr << endl;
		exit (1); 
	} 

	if (!ExisteFichero(argv[1])) {
		cerr << "Error: Fichero "<< argv[1] << " no puede abrirse." << endl;
		cerr << endl;
		exit (2); 
	}

	/***********************************************************************/
	// Leer datos de la circunferencia y crear el objeto Circunferencia

	double un_radio; 
	double centro_x, centro_y;

	cout << endl;
	cout << "Introducir datos de la circunferencia: ";
	cout << endl;

	centro_x = LeeNumeroReal ("\tCoordenada X del centro = ");
	centro_y = LeeNumeroReal ("\tCoordenada Y del centro = ");

	// Crea un dato Punto2D y rellena las coordenadas con los 
	// valores leidos, para poder pasarlo al constructor de la 
	// clase Circunferencia

	Punto2D un_punto (centro_x, centro_y);


	// Aseguramos que se cumple la precondición sobre el radio
	do {
		un_radio = LeeNumeroReal ("\tRadio = ");
	} while (un_radio <= 0);

	// Creación de un objeto Circunferencia --> constructor
	
	Circunferencia mi_circunferencia (un_punto, un_radio);


	/***********************************************************************/
	// Mostrar datos de la circunferencia 

	Punto2D el_centro = mi_circunferencia.GetCentro(); 

	cout << endl;
	cout << "Circunferencia centrada en: " << el_centro.ToString() 
	     << " y diametro " << setw(6) << setprecision(2)
		 << mi_circunferencia.GetDiametro() << endl;
	cout << "\tLongitud de la circunferencia = " << setw(6) << setprecision(2) 
		 << mi_circunferencia.Longitud() << endl;
	cout << "\tArea del circulo = " << setw(6) << setprecision(2) 
		 << mi_circunferencia.Area() << endl;
	cout << endl;


	/***********************************************************************/
	// Crear la colección de puntos tomando los datos del fichero

	cout << "Creando una coleccion de puntos desde el fichero = ";
	cout << argv[1] << endl; 

	ColeccionPuntos2D la_coleccion (argv[1]);


	PintaColeccionPuntos2D ("Coleccion leida del fichero", la_coleccion);

	/***********************************************************************/
	// Añadir nuevos puntos a la colección

	double punto_x, punto_y;
	
	// Lectura adelantada de la coordenada x del primer punto

	punto_x = LeeNumeroReal ("Coordenada X del punto = ");

	while (!cin.eof()) { 

		punto_y = LeeNumeroReal ("Coordenada Y del punto = ");

		// Crea un dato Punto2D, lo rellena con los valores leidos
		// y los añade a la colección

		Punto2D un_punto (punto_x, punto_y);

		la_coleccion += un_punto;


		cout << endl;
		cout << "Aniadido "<<un_punto.ToString() << " a la coleccion" << endl;
		cout << "   Num.puntos = "<< setw(3) << la_coleccion.NumPuntos();  
		cout << endl << endl;

		// Lectura adelantada de la coordenada x del siguiente punto

		punto_x = LeeNumeroReal ("Coordenada X del punto = ");

	} // while (cadena != TERMINADOR) 

	
	PintaColeccionPuntos2D ("Coleccion tras aniadir puntos", la_coleccion);


	/***********************************************************************/
	// Cálculo de la pertenencia (o no) de los puntos.

	cout << endl;
	cout << "Comprobacion de pertenencia al circulo: " << endl;

	for (int num=0; num < la_coleccion.NumPuntos(); num++) {

		Punto2D un_punto = la_coleccion[num];

		cout << "\tPunto num. " << setw(3) << num+1 << " : " 
		     << un_punto.ToString(); 

		if (mi_circunferencia.Contiene (un_punto)) 
			cout << " --> El punto SI esta contenido";
		else 
			cout << " --> El punto NO esta contenido";
		cout << endl;
	}
	cout << endl;

	/***********************************************************************/

	return (0);
}

/***************************************************************************/
/***************************************************************************/


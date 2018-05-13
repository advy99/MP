#ifndef COLECCIONPUNTOS2D
#define COLECCIONPUNTOS2D

#include "Punto2D.h"

class ColeccionPuntos2D 
{
private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// los valores de la coleccion.


	Punto2D * vector_privado;
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas
	

public:
	
	/***********************************************************************/
	// Constructor sin par�metros. 

	ColeccionPuntos2D (void);

	ColeccionPuntos2D (const char * nombre);

	/***********************************************************************/
	// Constructor a partir de un punto. 
	//
	// Recibe: nuevo_punto, el �nico punto que forma la nueva colecci�n. 
	
	ColeccionPuntos2D (Punto2D nuevo_punto);

	~ColeccionPuntos2D ();
	/***********************************************************************/
	// M�todos de lectura (Get) sobre tama�o y capacidad de la colecci�n 

	// Devuelve el n�mero de puntos que componen la colecci�n.
	int NumPuntos () const;



	/***********************************************************************/
	// A�ade un punto a la colecci�n.
	// Recibe: nuevo_punto, el punto que se va a a�adir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adici�n se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (Punto2D nuevo_punto);

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	//
	// PRE: 0 <= indice < total_utilizados 

	Punto2D Elemento (int indice) const;

	ColeccionPuntos2D & operator += (const Punto2D p);
	Punto2D & operator [] (const int n);
	Punto2D operator [] (const int n) const;

	/***********************************************************************/

private:

	void ReservarMemoria(const int num);

	void LiberarMemoria();

};


void PintaColeccionPuntos2D(const char * msg, const ColeccionPuntos2D & puntos);

#endif
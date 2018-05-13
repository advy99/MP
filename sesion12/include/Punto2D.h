#ifndef PUNTO2D
#define PUNTO2D

#include "Util.h"

class Punto2D
{
private:
	
	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x;
	double y;

public:
	
	/***********************************************************************/
	// Constructor sin argumentos.
	//
	// MUY IMPORTANTE: Nos vemos obligados a escribir este constructor por la
	// clase "ColeccionPuntos2D": cuando actúa el constructor sin argumentos 
	// de esa clase crea un vector de objetos "Punto2D" y cada elemento del  
	// vector se crea usando este constructor. No hace nada, pero debe estar.
		
	Punto2D (void);
	


	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se est� creando.
	
	Punto2D (double abscisaPunto, double ordenadaPunto);

	/***********************************************************************/
	// M�todo Set para fijar simultaneamente las coordenadas. 
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se est� modificando.
	
	void SetCoordenadas (double abscisaPunto, double ordenadaPunto);

	/***********************************************************************/
	// M�todos Get para leer las coordenadas

	double GetX (void);

	double GetY (void);

	/***********************************************************************/
	// Calcula si dos puntos son iguales 
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto impl�cito. 
	// Devuelve: true, si se consideran iguales los dos objetos. 

	bool EsIgual (Punto2D otro);

	/***********************************************************************/
	// Calcula la distancia Eucl�dea del punto (objeto impl�cito) a otro que 
	// se recibe como argumento. 
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la 
	// distancia eucl�dea.
	// Devuelve: la distancia entre los dos puntos. 

	double DistanciaEuclidea (Punto2D otro);

	string ToString();
	/***********************************************************************/
};




#endif
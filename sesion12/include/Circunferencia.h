#ifndef CIRCUNFERENCIA
#define CIRCUNFERENCIA

#include "Punto2D.h"

class Circunferencia
{
private:

	// La constante "PI" es com�n a todos los objetos de la clase.
	static const double PI;		
	
	// Centro de la circunferencia
	Punto2D centro;	
	
	// Longitud del radio
	// PRE: radio >= 0
	double  radio;	

public:

	/***********************************************************************/
	// Constructor con argumentos
	// Recibe:
	//		el_centro, el punto central de la circunferencia. 
	//		radio, el valor del radio.
	// PRE: radio >= 0

	Circunferencia (Punto2D el_centro, double el_radio);
	/***********************************************************************/
	// Métodos Get
	
	// Devuelve el punto central de la circunferencia
	Punto2D GetCentro (void);

	// Devuelve el radio de la circunferencia
	double GetRadio (void);

	// Devuelve el di�metro de la circunferencia
	double GetDiametro (void);
	/***********************************************************************/
	// Calcula la longitud de la circunferencia

	double Longitud (void);

	/***********************************************************************/
	// Calcula el �rea del c�rculo
	
	double Area (void);

	/***********************************************************************/
	// Calcular si la circunferencia contiene a un punto dado.
	//
	// Recibe: un_punto, el punto del que se quiere evaluar su pertenencia. 
	/*
		Un punto (x, y) est� dentro de una circunferencia con 
		centro (x_0, y_0) y radio r si se verifica que:
			(x-0 - x)^2 + (y_0 - y)^2 <= r^2
	*/

	bool Contiene (Punto2D un_punto);

	/***********************************************************************/
	// Calcular si la circunferencia contiene a un punto dado usando un 
	// test expl�cito sobre la distancia Eucl�dea
	/*
		Un punto P(x, y) est� dentro de una circunferencia con centro 
		C(x_0, y_0) y radio r si DistaciaEuclidea (P, C) <= r
	*/

	bool ContieneAlternativo (Punto2D un_punto);

	/***********************************************************************/
};



#endif
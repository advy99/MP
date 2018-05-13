#include "Circunferencia.h"
#include "Punto2D.h"
#include <cmath>

Circunferencia :: Circunferencia (Punto2D el_centro, double el_radio) 
                  : centro (el_centro)
{
	// Observad cómo se ha iniciado "centro": como es de clase "Punto2D"
	// se ha empleado la lista de iniciaci�n para que actúe el constructor
	// de la clase "Punto2D" 
		
	radio  = el_radio; 
}


Punto2D Circunferencia :: GetCentro (void)
{
	return (centro);
}

double Circunferencia :: GetRadio (void)
{
	return (radio);
}

double Circunferencia :: GetDiametro (void)
{
	return (radio*2);
}

double Circunferencia :: Longitud (void)
{
	return (2.0 * PI * radio);
}

double Circunferencia :: Area (void)
{
	return (PI * radio * radio);
}


bool Circunferencia :: Contiene (Punto2D un_punto)
{
	double dif_x = pow (centro.GetX() - un_punto.GetX(), 2);
	double dif_y = pow (centro.GetY() - un_punto.GetY(), 2);
	return (dif_x + dif_y <= radio*radio);
}

bool Circunferencia :: ContieneAlternativo (Punto2D un_punto)
{
	Punto2D el_centro = GetCentro();
	double distancia = el_centro.DistanciaEuclidea (un_punto);
	return (distancia <= radio);
}

const double Circunferencia :: PI = 3.1415926;
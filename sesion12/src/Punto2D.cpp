#include "Punto2D.h"
#include <cmath>
#include <sstream>
#include <string>

Punto2D :: Punto2D (void)
{
}

Punto2D :: Punto2D (double abscisaPunto, double ordenadaPunto)
{
	SetCoordenadas (abscisaPunto, ordenadaPunto);
}


void Punto2D :: SetCoordenadas (double abscisaPunto, double ordenadaPunto)
{
	x = abscisaPunto;
	y = ordenadaPunto;
}


double Punto2D :: GetX (void)
{
	return (x);
}

double Punto2D :: GetY (void)
{
	return (y);
}

bool Punto2D :: EsIgual (Punto2D otro)
{
	return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
}

double Punto2D :: DistanciaEuclidea (Punto2D otro)
{
	double dif_x = pow (x - otro.x, 2);
	double dif_y = pow (y - otro.y, 2);

	return (sqrt(dif_x + dif_y));
}

string Punto2D :: ToString(){
	string salida;

	salida = "(" + to_string(x) + ", " + to_string(y) + ")";

	return salida;
}
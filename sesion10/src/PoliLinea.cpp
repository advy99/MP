#include "PoliLinea.h"
#include <cstring>

Punto :: Punto()
          :x(0),
			  y(0)
{
}

Punto :: Punto (const int X, const int Y)
          :x(X),
			  y(Y)
{}

int Punto :: X () const{
	return x;
}

int Punto :: Y () const{
	return y;
}

void Punto :: MoverX (const int nueva_x){
	x = nueva_x;
}

void Punto :: MoverY (const int nueva_y){
	y = nueva_y;
}

void Punto :: MoverPunto (const int nueva_x, const int nueva_y){
	x = nueva_x;
	y = nueva_y;
}

bool Punto :: operator == (const Punto & otro){
	bool es_igual;

	es_igual = (x == otro.x) && (y = otro.y);

	return es_igual;
}

bool Punto :: operator != (const Punto & otro){
	return ( !(*this == otro) );
}

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

PoliLinea :: PoliLinea()
             :p(0),
				  num(0)
{
}

PoliLinea :: PoliLinea (const PoliLinea & otra){

	ReservarMemoria(otra.num);

	CopiarDatos(otra);
	
}

PoliLinea :: ~PoliLinea(){
	LiberarMemoria();
	num = 0;
}

void PoliLinea :: AniadirPunto (const Punto nuevo_punto){
	
	Redimensiona (num+1);

	num++;

	p[num] = nuevo_punto;
}

void PoliLinea :: EliminarPunto (const int posicion){
	
	for (int i = posicion; i < num - 1; i++)
		p[i] = p[ i+1 ];
	
	Redimensiona (num - 1);

}

PoliLinea & PoliLinea :: operator = (const PoliLinea & otra){

	if (this != &otra){

		LiberarMemoria();

		ReservarMemoria(otra.num);

		CopiarDatos(otra);
	}

	return (*this);
}

Punto & PoliLinea :: operator [] (const int punto){

	return ( p[punto] );	
}

bool PoliLinea :: operator == (const PoliLinea & otra){
	bool es_igual = num == otra.num;

	if (es_igual){
		for (int i = 0; i < num && es_igual; i++){
			if (p[i] !=  otra[i] && p[i] != otra[num - i - 1])
				es_igual = false;
		}
	}

	return es_igual;
}

bool PoliLinea :: operator != (const PoliLinea & otra){
	return ( !(*this == otra) );
}

PoliLinea operator + (const PoliLinea & poli_linea, const Punto & punto){
	PoliLinea nueva = poli_linea;

	nueva.AniadirPunto (punto);

	return (nueva);
}

PoliLinea operator + (const Punto & punto, const PoliLinea & poli_linea){

	PoliLinea nueva = poli_linea;
	
	nueva.AniadirPunto(punto);

	for (int i = 0; i < poli_linea.num; i++){
		nueva.AniadirPunto( poli_linea[i] );
	}

	return nueva;

}

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/


void PoliLinea :: ReservarMemoria (const int num_puntos){
	LiberarMemoria ();
	
	p = new Punto [num_puntos];

	num = num_puntos;
}


void  PoliLinea :: LiberarMemoria(){
	delete [] p;

	num = 0;
}

void PoliLinea :: CopiarDatos (const PoliLinea & otra){
	memcpy(p, otra.p, otra.num * sizeof(Punto) );

	num = otra.num;
}

void Redimensiona (const int nuevo_tam){
	Punto * nuevo_vector = new Punto [nuevo_tam];

	memcpy(nuevo_vector, p, num * sizeof (Punto) );

	LiberarMemoria();

	p = nuevo_vector;
	num = nuevo_tam;

}

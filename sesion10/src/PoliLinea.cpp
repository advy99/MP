/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 9 - Clase PoliLinea (y Punto)    **/
/**                                                         **/
/*************************************************************/

#include "PoliLinea.h"
#include <cstring>

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor sin parametros, punto en el origen        **/
/**                                                         **/
/*************************************************************/

Punto :: Punto()
          :x(0),
			  y(0)
{
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor con dos parametros, punto con coordenadas **/
/**  x e y                                                  **/
/**                                                         **/
/*************************************************************/

Punto :: Punto (const int X, const int Y)
          :x(X),
			  y(Y)
{}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Devuelve la coordenada X del punto                    **/
/**                                                         **/
/*************************************************************/

int Punto :: X () const{
	return x;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Devuelve la coordenada Y del punto                    **/
/**                                                         **/
/*************************************************************/

int Punto :: Y () const{
	return y;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Cambia la coordenada X del punto                      **/
/**                                                         **/
/*************************************************************/

void Punto :: MoverX (const int nueva_x){
	x = nueva_x;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Cambia la coordenada Y del punto                      **/
/**                                                         **/
/*************************************************************/

void Punto :: MoverY (const int nueva_y){
	y = nueva_y;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Cambia ambas coordenadas del punto                    **/
/**                                                         **/
/*************************************************************/

void Punto :: MoverPunto (const int nueva_x, const int nueva_y){
	x = nueva_x;
	y = nueva_y;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operado ==, comparamos si dos puntos son iguales      **/
/**                                                         **/
/*************************************************************/

bool Punto :: operator == (const Punto & otro){
	bool es_igual;

	//Lo son si tienen las mismas coordenadas
	es_igual = (x == otro.x) && (y = otro.y);

	return es_igual;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operado !=, comparamos si dos puntos son distintos    **/
/**                                                         **/
/*************************************************************/

bool Punto :: operator != (const Punto & otro){
	return ( !(*this == otro) );
}

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor sin parametros, polilinea vacia           **/
/**                                                         **/
/*************************************************************/


PoliLinea :: PoliLinea(){
	p = 0;
	num = 0;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor de copia, copiamos una PoliLinea          **/
/**                                                         **/
/*************************************************************/

PoliLinea :: PoliLinea (const PoliLinea & otra){

	ReservarMemoria(otra.num);

	CopiarDatos(otra);
	
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Destructor, liberamos la memoria usada y ponemos a 0  **/
/**  el numero de puntos usados                             **/
/**                                                         **/
/*************************************************************/

PoliLinea :: ~PoliLinea(){
	LiberarMemoria();
	num = 0;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Añadimos un punto a la PoliLinea        **/
/**                                                         **/
/*************************************************************/

void PoliLinea :: AniadirPunto (const Punto nuevo_punto){
	
	//Pedimos espacio para un punto mas, la PoliLinea siempre tiene el tamaño
	// ajustado al numero de puntos
	Redimensiona (num+1);

	//El ultimo punto es el nuevo
	p[num - 1] = nuevo_punto;

}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Eliminamos el punto de la posicion dada               **/
/**                                                         **/
/*************************************************************/

void PoliLinea :: EliminarPunto (const int posicion){
	
	//Movemos los puntos para reorganizarlos, dejando libre la ultima casilla
	for (int i = posicion; i < num - 1; i++)
		p[i] = p[ i+1 ];
	
	//Cambiamos el tamaño, por el que teniamos menos 1
	Redimensiona (num - 1);

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Devuelve el numero de puntos usados                   **/
/**                                                         **/
/*************************************************************/

int PoliLinea :: NumPuntos () const{
	return num;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operador de asignacio, asigna una PoliLinea a otra    **/
/**                                                         **/
/*************************************************************/

PoliLinea & PoliLinea :: operator = (const PoliLinea & otra){

	//Evitamos autoasignacion
	if (this != &otra){

		LiberarMemoria();

		ReservarMemoria(otra.num);

		CopiarDatos(otra);
	}

	return (*this);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operador [], para acceder al punto que ocupa una      **/
/**  posicion dada                                          **/
/**                                                         **/
/*************************************************************/

Punto & PoliLinea :: operator [] (const int punto) const{

	return ( p[punto] );	
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operador ==, comprueba si dos PoliLineas son iguales  **/
/**                                                         **/
/*************************************************************/

bool PoliLinea :: operator == (const PoliLinea & otra) const{
	bool es_igual = num == otra.num;

	if (es_igual){
		//Recorremos los puntos
		for (int i = 0; i < num && es_igual; i++){
			//Nos da igual si esta en orden inverso
			if (p[i] !=  otra[i] && p[i] != otra[num - i - 1])
				es_igual = false;
		}
	}

	return es_igual;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**  Operador !=, comprueba si dos PoliLineas son distintas **/
/**                                                         **/
/*************************************************************/

bool PoliLinea :: operator != (const PoliLinea & otra) const{
	return ( !(*this == otra) );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operador +: Añade un punto al final de la PoliLinea   **/
/**                                                         **/
/*************************************************************/

PoliLinea operator + (const PoliLinea & poli_linea, const Punto & punto){

	PoliLinea nueva = poli_linea;

	nueva.AniadirPunto (punto);

	return (nueva);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/** Operador +: Añade un punto al principio de la PoliLinea **/
/**                                                         **/
/*************************************************************/

PoliLinea operator + (const Punto & punto, const PoliLinea & poli_linea){

	//Creamos una nueva PoliLinea y añadimos el punto
	PoliLinea nueva = poli_linea;

	nueva.AniadirPunto(punto);

	//Añadimos los puntos de la otra PoliLinea
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

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Reservamos memoria para num_puntos puntos             **/
/**                                                         **/
/*************************************************************/

void PoliLinea :: ReservarMemoria (const int num_puntos){
	
	p = new Punto [num_puntos];

	num = num_puntos;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Liberamos la memoria usada                            **/
/**                                                         **/
/*************************************************************/

void  PoliLinea :: LiberarMemoria(){

	if ( p != 0){
		delete [] p;
		num = 0;
	}
	
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Copiamos los puntos de otra PoliLinea                 **/
/**                                                         **/
/*************************************************************/

void PoliLinea :: CopiarDatos (const PoliLinea & otra){
	memcpy(p, otra.p, otra.num * sizeof(Punto) );

	num = otra.num;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Cambiamos el tamaño del vector de puntos              **/
/**                                                         **/
/*************************************************************/

void PoliLinea :: Redimensiona (const int nuevo_tam){
	//Pedimos nuevo tamaño
	Punto * nuevo_vector = new Punto [nuevo_tam];

	//Copiamos los datos antiguos en el nuevo
	memcpy(nuevo_vector, p, num * sizeof (Punto) );

	//Liberamos la memoria antigua
	LiberarMemoria();

	//Asignamos nueva memoria, y actualizamos los puntos usados
	p = nuevo_vector;
	num = nuevo_tam;

}

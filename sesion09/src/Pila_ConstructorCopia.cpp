/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 5 - Clase Pila                   **/
/**                                                         **/
/*************************************************************/


#include "Pila_ConstructorCopia.h"
#include "TipoBase.h"


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor sin parametros, inicializa a una pila     **/
/**  vacia                                                  **/
/**                                                         **/
/*************************************************************/

Pila::Pila(){
	valor = 0;
	sig = 0;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor de copia, crea una pila, copia de otra    **/
/**                                                         **/
/**   Recibe: Otra pila                                     **/
/**                                                         **/
/*************************************************************/


Pila::Pila(const Pila & otra){
	//Creamos la pila a la par que leemos la otra_pila, copiando sus
	//valores

	PNodo aux;
	PNodo aux_otra = otra.sig;
	if (aux_otra != 0){
		sig = new Pila;
		aux = sig;
		aux->valor = aux_otra->valor;
		aux_otra = aux_otra->sig;


		while (aux_otra->sig != 0){
			aux->sig = new Pila;
			aux = aux->sig;
			aux->valor = aux_otra->valor;

			aux_otra = aux_otra->sig;


		}
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Destructor, libera la memoria de la pila              **/
/**                                                         **/
/*************************************************************/


Pila::~Pila(){
	PNodo siguiente = sig;
	PNodo a_borrar;

	//El primer nodo, considerado nulo no hay que eliminarlo, ya que no usa
	//memoria dinamica

	while (siguiente != 0){
		a_borrar = siguiente;
		siguiente = siguiente->sig;

		delete a_borrar;
	}
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   EstaVacia: Comprueba si la pila esta vacia            **/
/**                                                         **/
/**   Devuelve: Booleano con el resultado                   **/
/**                                                         **/
/*************************************************************/


bool Pila::EstaVacia()const{
	return (sig == 0);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   AniadeValor: Añade un valor al final de la pila       **/
/**                                                         **/
/**   Recibe: Valor a añadir                                **/
/**                                                         **/
/*************************************************************/


void Pila::AniadeValor(const TipoBase v){
	PNodo nuevo_valor = new Pila;

	nuevo_valor->valor = v;
	nuevo_valor->sig = sig;

	sig = nuevo_valor;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   SacarValor: Saca un valor de la pila                  **/
/**                                                         **/
/**   Al ser una pila, saca el ultimo valor añadido         **/
/**                                                         **/
/*************************************************************/


TipoBase Pila::SacarValor(){
	TipoBase v;
	PNodo a_sacar = sig;

	sig = a_sacar->sig;
	
	v = a_sacar->valor;
	a_sacar->sig = 0;

	delete a_sacar;

	return v;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   ValorEnTope: Devuelve el valor en el tope de la pila  **/
/**                                                         **/
/**   Devuelve: Valor en el tope                                **/
/**                                                         **/
/*************************************************************/


TipoBase Pila::ValorEnTope()const{
	PNodo aux = sig;
	return (aux->valor);
}
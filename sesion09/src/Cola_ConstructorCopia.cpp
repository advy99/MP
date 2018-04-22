/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 6 - Clase Cola                    **/
/**                                                         **/
/*************************************************************/


#include "Cola_ConstructorCopia.h"
#include "TipoBase.h"


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor sin parametros, inicializa a una cola     **/
/**  vacia                                                  **/
/**                                                         **/
/*************************************************************/


Cola::Cola(){
	valor = 0;
	sig = 0;
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor de copia, crea una cola, copia de otra    **/
/**                                                         **/
/**   Recibe: Otra cola                                     **/
/**                                                         **/
/*************************************************************/

Cola::Cola(const Cola & otra){
	//Creamos la cola a la par que leemos la otra, copiando sus
	//valores

	PNodo aux;
	PNodo aux_otra = otra.sig;
	if (aux_otra != 0){
		sig = new Cola;
		aux = sig;
		aux->valor = aux_otra->valor;
		aux_otra = aux_otra->sig;


		while (aux_otra != 0){
			aux->sig = new Cola;
			aux = aux->sig;
			aux->valor = aux_otra->valor;

			aux_otra = aux_otra->sig;

		}
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Destructor, libera la memoria de la cola              **/
/**                                                         **/
/*************************************************************/


Cola::~Cola(){
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
/**   EstaVacia: Comprueba si la cola esta vacia            **/
/**                                                         **/
/**   Devuelve: Booleano con el resultado                   **/
/**                                                         **/
/*************************************************************/


bool Cola::EstaVacia()const{
	return (sig == 0);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   AniadeValor: Añade un valor al final de la cola       **/
/**                                                         **/
/**   Recibe: Valor a añadir                                **/
/**                                                         **/
/*************************************************************/


void Cola::AniadeValor(const TipoBase v){
	PNodo nuevo_valor = new Cola;

	nuevo_valor->valor = v;
	nuevo_valor->sig = sig;

	sig = nuevo_valor;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   SacarValor: Saca un valor de la cola                  **/
/**                                                         **/
/**   Al ser una cola, saca el primer valor añadido         **/
/**                                                         **/
/*************************************************************/


TipoBase Cola::SacarValor(){
	TipoBase v;
	PNodo a_sacar = sig;
	PNodo anterior = 0;

	while (a_sacar->sig != 0){
		anterior = a_sacar;
		a_sacar = a_sacar->sig;
	}
	
	v = a_sacar->valor;
	a_sacar->sig = 0;
	anterior->sig = 0;

	delete a_sacar;

	return v;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   ValorEnCabecera: Devuelve el valor en la cabecera de  **/
/**  la pila                                                **/
/**                                                         **/
/**   Devuelve: Valor en la cabecera                        **/
/**                                                         **/
/*************************************************************/


TipoBase Cola::ValorEnCabecera()const{
	PNodo aux = sig;
	while( aux->sig != 0){
		aux = aux->sig;
	}
	return (aux->valor);
}
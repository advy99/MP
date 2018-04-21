#include "Pila_ConstructorCopia.h"
#include "TipoBase.h"

Pila::Pila(){
	valor = 0;
	sig = 0;
}

Pila::Pila(const Pila & otra){
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

bool Pila::EstaVacia()const{
	return (sig == 0);
}

void Pila::AniadeValor(const TipoBase v){
	PNodo nuevo_valor = new Pila;

	nuevo_valor->valor = v;
	nuevo_valor->sig = sig;

	sig = nuevo_valor;
}

TipoBase Pila::SacarValor(){
	TipoBase v;
	PNodo a_sacar = sig;

	sig = a_sacar->sig;
	
	v = a_sacar->valor;
	a_sacar->sig = 0;

	delete a_sacar;

	return v;
}

TipoBase Pila::ValorEnTope()const{
	PNodo aux = sig;
	return (aux->valor);
}
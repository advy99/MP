#include "Pila_ConstructorCopia.h"
#include "TipoBase.h"

Pila::Pila(){
	valor = 0;
	ultimo_elemento = 0;
}

Pila::Pila(const Pila & otra){
	PNodo aux;
	PNodo aux_otra = otra.sig;
	if (aux_otra != 0){
		aux_otra = aux_otra->sig;
		sig = new Pila;
		aux = sig;
		aux->valor = aux_otra->valor;

		while (aux_otra->sig != 0){
			aux->sig = new Nodo;
			aux = aux->sig;
			aux_otra = aux_otra->sig;

			aux->valor = aux_otra.valor;

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

	nuevo_valor->valot = v;
	nuevo_valor->sig = sig;

	sig = nuevo_valor;
}

TipoBase Pila::SacarValor(){
	TipoBase valor;
	PNodo a_sacar = sig;

	sig = a_sacar->sig;
	
	valor = a_sacar->valor;
	a_sacar->sig = 0;

	delete a_sacar;

	return valor;
}

TipoBase Lista::ValorEnTope()const{
	return (sig->valor);
}
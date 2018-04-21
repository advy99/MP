#include "Cola_ConstructorCopia.h"
#include "TipoBase.h"

Cola::Cola(){
	valor = 0;
	sig = 0;
}

Cola::Cola(const Cola & otra){
	PNodo aux;
	PNodo aux_otra = otra.sig;
	if (aux_otra != 0){
		sig = new Cola;
		aux = sig;
		aux->valor = aux_otra->valor;
		aux_otra = aux_otra->sig;


		while (aux_otra->sig != 0){
			aux->sig = new Cola;
			aux = aux->sig;
			aux->valor = aux_otra->valor;

			aux_otra = aux_otra->sig;

		}
	}
}

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

bool Cola::EstaVacia()const{
	return (sig == 0);
}

void Cola::AniadeValor(const TipoBase v){
	PNodo nuevo_valor = new Cola;

	nuevo_valor->valor = v;
	nuevo_valor->sig = sig;

	sig = nuevo_valor;
}

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

TipoBase Cola::ValorEnCabecera()const{
	PNodo aux = sig;
	while( aux->sig != 0){
		aux = aux->sig;
	}
	return (aux->valor);
}
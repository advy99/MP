#include "Lista_ConstructorCopia.h"
#include "TipoBase.h"

Lista::Lista(){
	valor = 0;
	sig = 0;
}

Lista::Lista(const int num_nodos){

	int nodos_creados = 0;
	valor = 0;

	if(num_nodos > 0){
		sig = new Nodo;
		nodos_creados++;

		PNodo aux = sig;

		while (nodos_creados < num_nodos){
			aux->sig = new Nodo;
			aux = aux->sig;

			nodos_creados++;
		}
		aux->sig = 0;
	}
	else{
		sig = 0;
	}
}

Lista::Lista(const int num_nodos, const TipoBase valor){

	int nodos_creados = 0;
	valor = 0;

	if (num_nodos > 0){
		sig = new Nodo;
		nodos_creados++;

		PNodo aux = sig;
		aux->valor = valor;

		while (nodos_creados < num_nodos){
			
			aux->sig = new Nodo;
			aux = aux->sig;
			aux->valor = valor;

			nodos_creados++;
		}
	}
	else{
		sig = 0;
	}
}

Lista::Lista(const Lista & otra_lista){
	PNodo aux_otra = otra_lista;
	PNodo l_actual;
	if (aux_otra->sig != 0){
		aux_otra = aux_otra->sig;

		sig = new Nodo;
		l_actual = sig;
		l_actual->valor = aux_otra->valor;
	}

	while (aux_otra->sig != 0){
		l_actual->sig = new Nodo;
		l_actual = l_actual->sig;
		aux_otra = aux_otra->sig;

		l_actual->valor = aux_otra->valor;
	}

}

Lista::~Lista(){
	PNodo siguiente = sig;
	PNodo a_borrar;

	delete this;

	while (siguiente != 0){
		a_borrar = siguiente;
		siguiente = siguiente->sig;

		delete a_borrar;
	}
}

bool Lista::EstaVacio(){
	return (sig == 0);
}

int Lista::NumeroNodos(){
	int num_elementos;
	if (sig != 0){
		PNodo aux = sig;
		num_elementos++;

		while (aux != 0){
			aux = aux->sig;
			num_elementos++;
		}
	}

	return num_elementos;
}

void Lista::Insertar(const TipoBase valor, const int pos){

	PNodo aux = sig;

	
	for (int i = 1; i < pos; i++){
		aux = aux->sig;
	}
	PNodo nuevo = new Nodo;
	nuevo->valor = valor;
	nuevo->sig = aux;
	sig = nuevo;

}

void Lista::Borrar(const int pos){
	PNodo aux = sig;
	PNodo anterior;

	for (int i = 1; i < pos; i++){
		anterior = aux;
		aux = aux->sig;
	}
	anterior->sig = aux->sig;

	delete aux;

}

void Lista::AniadirValor(const TipoBase valor){
	PNodo aux = sig;

	while(aux->sig != 0){
		aux = aux->sig;
	}
	aux->sig = new Nodo;
	aux = aux->sig;
	aux->valor = valor;
	aux->sig = 0;
}

TipoBase Lista::LeerValor(const int pos) const{
	PNodo aux = sig;

	for (int i = 1; i < pos; i++){
		aux = aux->sig;
	}

	return (aux->valor);
}

void Lista::ModificarValor (const int pos, const TipoBase val){
	PNodo aux = sig;

	for (int i = 1; i < pos; i++){
		aux = aux->sig;
	}

	aux->valor = val;

}

void Lista::Inicializar(const TipoBase valor){
	PNodo aux = sig;

	while (aux != 0){
		aux->valor = valor;
		aux = aux->sig;
	}
}
#include <iostream>
#include "Lista.h"
#include "TipoBase.h"

using namespace std;

void LeeLista(Lista & l){

	PNodo ultimo;
	double valor;


	cout << "Introduce un valor: ";
	cin >> valor;

	if (valor >= 0){
		l = new Nodo;

		l->valor = valor;
		l->sig = 0;

		ultimo = l;

		cout << "Introduce un valor: ";
		cin >> valor;

		while (valor >= 0){

			ultimo->sig = new Nodo;

			ultimo = ultimo->sig;

			ultimo->valor = valor;
			ultimo->sig = 0;

			cout << "Introduce un valor: ";
			cin >> valor;

		}
	}


}

void PintaLista(const Lista l){

	PNodo p_ultimo_nodo = l;

	cout << endl;

	while (p_ultimo_nodo != 0){
		cout << p_ultimo_nodo->valor << endl;
		p_ultimo_nodo = p_ultimo_nodo->sig;
	}

	cout << endl;
}

void LiberaLista(Lista & l){

	if ( !ListaVacia(l) ){
		PNodo nodo_actual = l;

		while (nodo_actual->sig != 0){
			nodo_actual = nodo_actual->sig;
			delete l;
			l = nodo_actual;
		}

		delete nodo_actual;
	}
	l = 0;
}

bool ListaVacia(const Lista l){
	return (l==0);
}

int CuentaElementos (const Lista l){
	int num_elementos = 0;

	PNodo aux = l;

	while (aux != 0){
		num_elementos++;
		aux = aux->sig;
	}

	return num_elementos;
}

bool EstaOrdenada (const Lista l){
	bool esta_ordenada = true;

	PNodo aux = l;

	TipoBase elemento_anterior = aux->valor;
	aux = aux->sig;

	while (aux != 0 && esta_ordenada){

		if (elemento_anterior > aux->valor){
			esta_ordenada = false;
		}
		else{
			elemento_anterior = aux->valor;
			aux = aux->sig;
		}

	}

	return esta_ordenada;
}

void OrdenaSeleccionLista (Lista & l){
	int elementos_lista = CuentaElementos (l);

	PNodo minimo_nodo;

	for (PNodo aux = l; aux != 0; aux = aux->sig){
		minimo_nodo = aux;

		for (PNodo interno = aux->sig; interno != 0; interno = interno->sig){

			if (interno->valor < minimo_nodo->valor){
				minimo_nodo = interno;
			}

		}

		TipoBase intermedio = aux->valor;
		aux->valor = minimo_nodo->valor;
		minimo_nodo->valor = intermedio;

	}

	
}

//PRE : La lista esta ordenada
void InsertaOrdenadamente (Lista & l, TipoBase v){
	PNodo anterior = l;
	PNodo siguiente = l;

	//Buscamos la posicion del siguiente
	while (siguiente->sig != 0 && siguiente->valor <= v){
		siguiente = siguiente->sig;
	}

	//si estamos en el ultimo valor, añadimos el siguiente nodo
	if (siguiente->sig == 0){

		siguiente->sig = new Nodo;
		siguiente = siguiente->sig;

		siguiente->valor = v;
		siguiente->sig = 0;
	}
	else{
		//Buscamos el nodo anterior
		while (anterior->sig != siguiente){
			anterior = anterior->sig;
		}

		PNodo direccion_siguiente = siguiente;

		anterior->sig = new Nodo;
		anterior = anterior->sig;

		anterior->sig = direccion_siguiente;
		anterior->valor = v;
	}

}

bool ExisteElemento (const Lista & l, const TipoBase v ){
	PNodo aux = l;
	bool existe_elemento = false;

	while (aux->sig != 0 && !existe_elemento){
		if (aux->valor == v)
			existe_elemento = true;
		aux = aux->sig;
	}

	return existe_elemento;
}


void EliminaValor (Lista & l, TipoBase v){
	PNodo a_eliminar = l;
	PNodo anterior = l;
	PNodo siguiente;

	if (ExisteElemento (l, v)){

		while (a_eliminar->sig != 0 && a_eliminar->valor < v){
			a_eliminar = a_eliminar->sig;
		}

		while (anterior->sig != a_eliminar)
			anterior = anterior->sig;
		siguiente = a_eliminar->sig;

		anterior->sig = siguiente;

		delete a_eliminar;

	}
}
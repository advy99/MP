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

	while (p_ultimo_nodo != 0){
		cout << p_ultimo_nodo->valor << endl;
		p_ultimo_nodo = p_ultimo_nodo->sig;
	}

}
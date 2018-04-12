#include <iostream>
#include "Lista.h"

using namespace std;

/******************************************************************************/

double Media (const Lista l);
double Varianza (const Lista l);

/******************************************************************************/	

int main(){
	Lista lista;

	LeeLista(lista);
	
	PintaLista(lista);

	cout << "La lista tiene " << CuentaElementos(lista) << " elementos." << endl;
	cout << "La media de los elementos de la lista es " << Media(lista) << endl;

	cout << endl << "Vaciamos la lista " << endl;
	LiberaLista(lista);

	if( ListaVacia(lista) )
		cout << "La lista esta vacia" << endl;
	else
		PintaLista(lista);

	cout << "La lista tiene " << CuentaElementos(lista) << " elementos." << endl;



	return 0;
}

double Media(const Lista l){
	double media = 0;

	PNodo aux = l;

	while (aux != 0){
		media = media + aux->valor;
		aux = aux->sig;
	}

	media = media / CuentaElementos(l);

	return media;
}
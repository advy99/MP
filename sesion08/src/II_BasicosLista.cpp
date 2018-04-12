#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
	Lista lista;

	LeeLista(lista);
	
	PintaLista(lista);

	cout << "La lista tiene " << CuentaElementos(lista) << " elementos." << endl;

	cout << endl << "Vaciamos la lista " << endl;
	LiberaLista(lista);

	if( ListaVacia(lista) )
		cout << "La lista esta vacia" << endl;
	else
		PintaLista(lista);

	cout << "La lista tiene " << CuentaElementos(lista) << " elementos." << endl;



	return 0;
}
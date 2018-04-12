#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
	Lista lista;
	
	LeeLista(lista);
	
	PintaLista(lista);

	LiberaLista(lista);

	if( ListaVacia(lista) )
		cout << "La lista esta vacia" << endl;
	else
		PintaLista(lista);


	return 0;
}
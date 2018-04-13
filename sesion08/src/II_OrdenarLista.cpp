#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
	Lista mi_lista;

	LeeLista(mi_lista);
	
	PintaLista(mi_lista);

	if ( EstaOrdenada(mi_lista) ){
		cout << endl << "La lista esta ordenada" << endl;
	}
	else{
		cout << endl << "La lista no esta ordenada" << endl;
	}

	OrdenaSeleccionLista(mi_lista);

	PintaLista(mi_lista);

	LiberaLista(mi_lista);
}
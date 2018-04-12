#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
	Lista lista;
	
	LeeLista(lista);
	
	PintaLista(lista);

	LiberaLista(lista);

	PintaLista(lista);
	
	return 0;
}
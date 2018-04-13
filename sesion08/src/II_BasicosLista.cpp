/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 8 - Ejercicio 12 - Operaciones basicas listas   **/
/**                                                         **/
/*************************************************************/

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
	cout << "La varianza de los elementos es " << Varianza(lista) << endl;


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

double Varianza(const Lista l){
	double varianza;
	double media = Media (l);

	PNodo aux = l;

	while(aux != 0){
		varianza = varianza + aux->valor * aux->valor;
		aux = aux->sig;
	}

	varianza = varianza / CuentaElementos(l);
	varianza = varianza - media*media;

	return varianza;
}
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 8 - Listas                                      **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "Lista.h"
#include "TipoBase.h"

using namespace std;

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      LeeLista: Lee una lista de elementos positivos                      **/
/**                                                                          **/
/**   RECIBE : Lista a leer                                                  **/
/**                                                                          **/
/******************************************************************************/

void LeeLista(Lista & l){

	PNodo ultimo;
	TipoBase valor;

	//Leemos el primer valor
	cout << "Introduce un valor: ";
	cin >> valor;

	//Si es correcto creamos un nuevo nodo (el primero)
	if (valor >= 0){
		l = new Nodo;

		l->valor = valor;
		l->sig = 0;

		ultimo = l;

		//Ciclo de entrada con lectura anticipada
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

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      PintaLista: Muestra una lista por consola                           **/
/**                                                                          **/
/**   RECIBE : Lista a mostrar                                               **/
/**                                                                          **/
/******************************************************************************/
void PintaLista(const Lista l){

	PNodo p_ultimo_nodo = l;

	cout << endl;
	
	//Recorremos la lista, mostrando sus elementos, hasta que lleguemos
	//al final (sig apunta a direccion nula)
	while (p_ultimo_nodo != 0){
		cout << p_ultimo_nodo->valor << endl;
		p_ultimo_nodo = p_ultimo_nodo->sig;
	}

	cout << endl;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      LiberaLista: Libera la memoria que usa una lista l                  **/
/**                                                                          **/
/**   RECIBE : Lista a liberar                                               **/
/**                                                                          **/
/******************************************************************************/

void LiberaLista(Lista & l){

	//Comprobamos si hay algo que eliminar
	if ( !ListaVacia(l) ){
		PNodo nodo_actual = l;

		//Mientras queden elementos, eliminamos el actual, y pasamos al siguiente
		while (nodo_actual->sig != 0){
			nodo_actual = nodo_actual->sig;
			delete l;
			l = nodo_actual;
		}
		//Eliminamos el ultimo nodo
		delete nodo_actual;
	}
	//La lista quedara apuntando a la direccion 0
	l = 0;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      ListaVacia: Comprueba si una lista esta vacia                       **/
/**                                                                          **/
/**   RECIBE : Lista a comprobar                                             **/
/**                                                                          **/
/**   DEVUELVE : Booleano con el resultado                                   **/
/**                                                                          **/
/******************************************************************************/

bool ListaVacia(const Lista l){
	//Si la lista apunta a la direccion 0, esta vacia
	return (l==0);
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      CuentaElementos: Cuenta el numero de elementos de una lista         **/
/**                                                                          **/
/**   RECIBE : Lista                                                         **/
/**                                                                          **/
/**   DEVUELVE : Numero de elementos de la lista                             **/
/**                                                                          **/
/******************************************************************************/

int CuentaElementos (const Lista l){
	int num_elementos = 0;

	PNodo aux = l;
	//Recorre la lista, mientras no se apunte a la direccion 0, hay un elemento
	while (aux != 0){
		num_elementos++;
		aux = aux->sig;
	}
	return num_elementos;
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      EstaOrdenada: Comprueba si una lista esta ordenada                  **/
/**                                                                          **/
/**   RECIBE : Lista a comprobar                                             **/
/**                                                                          **/
/**   DEVUELVE : Booleano con el resultado                                   **/
/**                                                                          **/
/******************************************************************************/

bool EstaOrdenada (const Lista l){
	bool esta_ordenada = true;

	PNodo aux = l;
	//Guardamos el elemento anterior
	TipoBase elemento_anterior = aux->valor;
	aux = aux->sig;

	//Mientras queden elementos y este ordenada, comprobamos que el elemento
	//anterior sea menor que el siguiente
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

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      OrdenaSeleccionLista: Ordena una lista de valores                   **/
/**                                                                          **/
/**   RECIBE : Lista a ordenar                                               **/
/**                                                                          **/
/******************************************************************************/

void OrdenaSeleccionLista (Lista & l){
	//Si no esta ordenada
	if ( !EstaOrdenada(l) ){
		int elementos_lista = CuentaElementos (l);

		PNodo minimo_nodo;
		//Aplicamos algoritmo para ordenar por seleccion

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
	
}


/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      InsertaOrdenadamente: Inserta un valor en una lista manteniendo el  **/
/**                          orden de la lista                               **/
/**                                                                          **/
/**   RECIBE : Lista                                                         **/
/**            Elemento a insertar                                           **/
/**                                                                          **/
/**   PRE: La lista esta ordenada                                            **/
/**                                                                          **/
/******************************************************************************/
void InsertaOrdenadamente (Lista & l, TipoBase v){

	//Si tiene elementos:

	if (CuentaElementos(l) != 0){
		PNodo anterior = l;
		PNodo siguiente = l;

		//Buscamos la posicion del siguiente
		while (siguiente->sig != 0 && siguiente->valor <= v){
			siguiente = siguiente->sig;
		}

		//Si el siguiente es el ultimo, se ha de añadir al final
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

			//Creamos un nuevo nodo, guardando la direccion del siguiente
			//temporalmente
			PNodo direccion_siguiente = siguiente;

			anterior->sig = new Nodo;
			anterior = anterior->sig;

			//La direccion del siguiente se almacena en el nuevo nodo,
			//insertando este nodo entre el anterior y el siguiente
			anterior->sig = direccion_siguiente;
			anterior->valor = v;
		}
	}
	else{  //Si no tenia elementos, se añade el elemento a la lista vacia
		l = new Nodo;
		l->valor = v;
		l->sig = 0;
	}

}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      ExisteElemento: Comprueba si una lista esta ordenada                **/
/**                                                                          **/
/**   RECIBE : Lista                                                         **/
/**            Elemento a comprobar                                          **/
/**                                                                          **/
/**   DEVUELVE : Booleano con el resultado                                   **/
/**                                                                          **/
/******************************************************************************/

bool ExisteElemento (const Lista & l, const TipoBase v ){
	PNodo aux = l;
	bool existe_elemento = false;

	//Recorremos la lista, y si devolvemos si se ha encontrado el elemento

	while (aux->sig != 0 && !existe_elemento){
		if (aux->valor == v)
			existe_elemento = true;
		aux = aux->sig;
	}

	return existe_elemento;
}


/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      EliminaValor: Elimina un valor de la lista                          **/
/**                                                                          **/
/**   RECIBE : Lista                                                         **/
/**            Valor a eliminar                                              **/
/**                                                                          **/
/******************************************************************************/

void EliminaValor (Lista & l, TipoBase v){
	PNodo a_eliminar = l;
	PNodo anterior = l;
	PNodo siguiente;

	//Comprobamos que existe el valor a eliminar
	if (ExisteElemento (l, v)){

		//Buscamos el nodo en el que se almacena el valor
		while (a_eliminar != 0 && a_eliminar->valor != v){
			a_eliminar = a_eliminar->sig;
		}

		//Si el nodo a eliminar no es el primero, buscamos el nodo anterior
		if (a_eliminar != l){
			while (anterior->sig != a_eliminar)
				anterior = anterior->sig;
		
			//El siguiente nodo es la direccion que apunta el que queremos eliminar
			siguiente = a_eliminar->sig;


			//Hacemos el salto del anterior al siguiente, dejando el "hueco"
			//que ocupa el nodo a eliminar
			anterior->sig = siguiente;
		}
		else{
			l = l->sig;
		}

		//Eliminamos el nodo
		delete a_eliminar;

	}
}

/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**      MezclaListas: Mezcla dos lista ordenadamente                        **/
/**                                                                          **/
/**   RECIBE : Lista donde se mezclaran                                      **/
/**            Lista 1                                                       **/
/**            Lista 2                                                       **/
/**                                                                          **/
/**   ATENCION : Esta funcion dejara vacias la lista 1 y lista 2             **/
/**                                                                          **/
/******************************************************************************/


void MezclaListas(Lista & l, Lista & l1, Lista & l2){

	//La lista final ha de estar vacia
	LiberaLista(l);
	PNodo nuevo;

	OrdenaSeleccionLista(l1);
	OrdenaSeleccionLista(l2);

	//Leemos valores de ambas listas, hasta que finalicemos con una de ellas
	while (l1 != 0 && l2 != 0){
		
		//Si el valor de la lista 1 es menor que el de la lista 2, se inserta
		//ese valor a la lista l
		if (l1->valor < l2->valor){
			InsertaOrdenadamente(l,l1->valor);

			nuevo = l1->sig;
			EliminaValor(l1, l1->valor);

			//Se pasa al siguiente "primer valor" de la lista, ya que el antiguo
			//valor ha sido eliminado
			l1 = nuevo;
		}
		else{  //Si el de la lista 2 es menor, se añade el de la lista 2
			InsertaOrdenadamente(l,l2->valor);
			
			nuevo = l2->sig;

			//Se pasa al siguiente "primer valor" de la lista, ya que el antiguo
			//valor ha sido eliminado
			EliminaValor(l2, l2->valor);
			l2 = nuevo;
		}
	}


	//Si acabamos de leer la lista 1, se insertan los valores que queden en
	//la lista 2
	if( l1 == 0){

		while (l2 != 0){
			InsertaOrdenadamente(l,l2->valor);
			EliminaValor(l2, l2->valor);
			l2 = l2->sig;
		}
	}
	//Si acabamos de leer la lista 2, se insertan los valores que queden en
	//la lista 1
	else{
		while (l1 != 0){
			InsertaOrdenadamente(l,l1->valor);
			EliminaValor(l1, l1->valor);
			l1 = l1->sig;
		}
	}

}
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 4 - Clase Lista                   **/
/**                                                         **/
/*************************************************************/

#include "Lista_ConstructorCopia.h"
#include "TipoBase.h"

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor sin parametros, inicializa a una lista    **/
/**  vacia                                                  **/
/**                                                         **/
/*************************************************************/

Lista::Lista(){
	valor = 0;
	sig = 0;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor con un parametro, inicializa a una lista  **/
/**  con tantos nodos como indique num_nodos                **/
/**                                                         **/
/**   Recibe: Numero de nodos iniciales                     **/
/**                                                         **/
/*************************************************************/

Lista::Lista(const int num_nodos){

	int nodos_creados = 0;
	valor = 0;

	//Creamos tantos nodos como num_nodos indique, comprobando que sea un
	//numero mayor que 0
	if(num_nodos > 0){
		sig = new Lista;
		nodos_creados++;

		PNodo aux = sig;

		while (nodos_creados < num_nodos){
			aux->sig = new Lista;
			aux = aux->sig;

			nodos_creados++;
		}
		aux->sig = 0;
	}
	else{
		sig = 0;
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor con dos parametros, inicializa a una      **/
/**  lista con tantos nodos como indique num_nodos e        **/
/**  inicializa los nodos al valor v                        **/
/**                                                         **/
/**   Recibe: Numero de nodos iniciales                     **/
/**           Valor al que inicializar los nodos            **/
/**                                                         **/
/*************************************************************/

Lista::Lista(const int num_nodos, const TipoBase v){

	int nodos_creados = 0;
	valor = 0;

	if (num_nodos > 0){
		sig = new Lista;
		nodos_creados++;

		PNodo aux = sig;
		aux->valor = v;

		while (nodos_creados < num_nodos){
			
			aux->sig = new Lista;
			aux = aux->sig;
			aux->valor = v;

			nodos_creados++;
		}
	}
	else{
		sig = 0;
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor de copia, crea una lista, copia de otra   **/
/**                                                         **/
/**   Recibe: Otra lista                                    **/
/**                                                         **/
/*************************************************************/

Lista::Lista(const Lista & otra_lista){
	
	//Creamos la lista a la par que leemos la otra_lista, copiando sus
	//valores
	PNodo aux_otra = otra_lista.sig;
	PNodo l_actual;
	if (aux_otra != 0){
		sig = new Lista;
		l_actual = sig;
		l_actual->valor = aux_otra->valor;
		aux_otra = aux_otra->sig;

		while (aux_otra->sig != 0){
			l_actual->sig = new Lista;
			l_actual = l_actual->sig;

			l_actual->valor = aux_otra->valor;
			aux_otra = aux_otra->sig;
		}
	}

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Destructor, libera la memoria de la lista             **/
/**                                                         **/
/*************************************************************/

Lista::~Lista(){
	PNodo siguiente = sig;
	PNodo a_borrar;

	//El primer nodo, considerado nulo no hay que eliminarlo, ya que no usa
	//memoria dinamica

	while (siguiente != 0){
		a_borrar = siguiente;
		siguiente = siguiente->sig;

		delete a_borrar;
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   EstaVacio: Comprueba si la lista esta vacia           **/
/**                                                         **/
/**   Devuelve: Booleano con el resultado                   **/
/**                                                         **/
/*************************************************************/

bool Lista::EstaVacio() const {
	return (sig == 0);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   NumeroNodos: Cuenta el numero de nodos usados         **/
/**                                                         **/
/**   Devuelve: Entero con el numeor de nodos               **/
/**                                                         **/
/*************************************************************/

int Lista::NumeroNodos() const{
	int num_elementos = 0;
	if (sig != 0){
		PNodo aux = sig;

		while (aux != 0){
			aux = aux->sig;
			num_elementos++;
		}
	}

	return num_elementos;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Insertar: Inserta un valor en una posicion            **/
/**                                                         **/
/**   Recibe: Valor a insertar                              **/
/**           Entero con la posicion a insertar             **/
/**                                                         **/
/*************************************************************/

void Lista::Insertar(const TipoBase valor, const int pos){

	PNodo aux = sig;
	PNodo anterior = sig;

	//Avanzamos hasta la posicion a insertar
	for (int i = 1; i < pos; i++){
		anterior = aux;
		aux = aux->sig;
	}

	//Creamos un nuevo nodo, con los datos
	PNodo nuevo = new Lista;
	nuevo->valor = valor;

	//El nuevo apuntara el siguiente
	nuevo->sig = aux;

	//Si pos es 1, se inserta en el principio, si no, donde corresponda
	if(pos == 1)
		sig = nuevo;
	else
		anterior->sig = nuevo;

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Borrar: Borra una posicion de la lista                **/
/**                                                         **/
/**   Recibe: Entero con la posicion a borrar               **/
/**                                                         **/
/*************************************************************/

void Lista::Borrar(const int pos){

	PNodo aux = sig;

	//Si la posicion es 1, el nodo cabecera apunta al siguiente, saltando
	// el primer nodo
	if (pos == 1){
		sig = aux->sig;
	}
	else{
		PNodo anterior;

		//Buscamos el nodo a eliminar y el anterior

		for (int i = 1; i < pos; i++){
			anterior = aux;
			aux = aux->sig;
		}

		//El anterior apuntara al siguiente a borrar
		anterior->sig = aux->sig;
	}

	//Borramos el nodo a borrar
	aux->sig = 0;
	aux->valor = 0;
	delete aux;


}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   AniadirValor: Añade un valor al final de la lista     **/
/**                                                         **/
/**   Recibe: Valor a añadir                                **/
/**                                                         **/
/*************************************************************/

void Lista::AniadirValor(const TipoBase valor){
	PNodo aux = sig;

	//Si la lista no esta vacia, vamos al final de la lista, y añadimos el
	//valor, si esta vacia, añadimos el valor como un primer nodo
	if (sig != 0){
		while(aux->sig != 0){
			aux = aux->sig;
		}
		aux->sig = new Lista;
		aux = aux->sig;
		aux->valor = valor;
		aux->sig = 0;
	}
	else{
		sig = new Lista;
		aux = sig;
		aux->valor = valor;
		aux->sig = 0;
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   LeerValor: Devuelve el valor que hay en un nodo dado  **/
/**                                                         **/
/**   Recibe: Entero con la posicion a leer                 **/
/**                                                         **/
/**   Devuelve: Valor que hay en el nodo dado               **/
/**                                                         **/
/*************************************************************/

TipoBase Lista::LeerValor(const int pos) const{
	PNodo aux = sig;

	//Nos movemos hasta el nodo dado
	for (int i = 1; i < pos; i++){
		aux = aux->sig;
	}

	//Devolvemos el valor del nodo dado
	return (aux->valor);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   ModificarValor: Modificamos el valor de un nodo dado  **/
/**                                                         **/
/**   Recibe: Entero con la posicion a modificar            **/
/**           Nuevo valor                                   **/
/**                                                         **/
/*************************************************************/

void Lista::ModificarValor (const int pos, const TipoBase val){
	PNodo aux = sig;

	//Nos movemos hasta el nodo dado
	for (int i = 1; i < pos; i++){
		aux = aux->sig;
	}
	//Cambiamos el valor del nodo
	aux->valor = val;

}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Inicializar: Inicializamos la lista a un valor dado   **/
/**                                                         **/
/**   Recibe: Valor al que inicializar                      **/
/**                                                         **/
/*************************************************************/

void Lista::Inicializar(const TipoBase valor){
	PNodo aux = sig;

	//Recorremos toda la lista, cambiando el valor al valor dado
	while (aux != 0){
		aux->valor = valor;
		aux = aux->sig;
	}
}
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 12 - Ejercicio 6 - Clase Lista                  **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <fstream>

#include "Lista.h"
#include "TipoBase.h"
#include "Util.h"

using namespace std; 

/***************************************************************************/
// Constructor sin argumentos: crea una lista vacia.
Lista :: Lista (void)  : primero(0), tamanio(0)
{ }


Lista :: Lista (const char * fichero){
	tamanio = 0;
	primero = 0;

	

	if (ExisteFichero(fichero)){
		ifstream fi;

		TipoBase valor;

		fi.open(fichero);

		while (fi >> valor){
			*this += valor;
		}

		fi.close();

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

Lista :: Lista (int tam, TipoBase valor) 
               : tamanio(tam){
	ReservarMemoria (tamanio);
	Inicializar (valor);
}
	
/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor de copia, crea una lista, copia de otra   **/
/**                                                         **/
/**   Recibe: Otra lista                                    **/
/**                                                         **/
/*************************************************************/

Lista :: Lista (const Lista & otro){	
	// Reservar memoria para los nodos de la lista
	ReservarMemoria (otro.tamanio);

	// Copiar campos privados y los valores de la lista
	CopiarDatos (otro);
}		

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Destructor, libera la memoria de la lista             **/
/**                                                         **/
/*************************************************************/


Lista :: ~Lista (){
    LiberarMemoria ();
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   EstaVacia: Comprueba si la lista esta vacia           **/
/**                                                         **/
/**   Devuelve: Booleano con el resultado                   **/
/**                                                         **/
/*************************************************************/

bool Lista :: EstaVacia() const{
	return (tamanio == 0);
}	

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Inicializar: Inicializamos la lista a un valor dado   **/
/**                                                         **/
/**   Recibe: Valor al que inicializar                      **/
/**                                                         **/
/*************************************************************/

void  Lista :: Inicializar (const TipoBase valor){
	TipoNodo * p = primero; // Apuntar al primero.

	for(int i = 0; i < tamanio; i++) {
		p->info = valor; // Inicializar nodo.
		p = p->sig;		 // Adelantar "p".
	}						
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Tamanio: Cuenta el numero de nodos usados             **/
/**                                                         **/
/**   Devuelve: Entero con el numero de nodos               **/
/**                                                         **/
/*************************************************************/

int Lista :: Tamanio()	const{
	return tamanio;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Buscar: Buscamos un valor dado en la lista            **/
/**                                                         **/
/**   Recibe: Valor a buscar                                **/
/**                                                         **/
/*************************************************************/

int Lista :: Buscar (const TipoBase valor) const{
    TipoNodo * p = primero;

    bool sigo = true;
    bool encontrado = false;

	int pos = 0;
    	
    while ((p!=0) && sigo) {
    	
		pos++; // Actualizar posicion

        if (p->info == valor) {
            sigo = false;
            encontrado = true;
        }
        else 
            p = p->sig;
	}
	
	return (encontrado ? (pos) : -1); 
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


void  Lista :: Insertar (const TipoBase val, const int pos_insertar){
	TipoNodo * ant = primero;
	TipoNodo * resto = primero;

	TipoNodo * nuevo = new TipoNodo; 
	nuevo->info = val; 

	for (int i=1; i<pos_insertar; i++) { 
		ant = resto; 
		resto = resto->sig;
	}

	if (pos_insertar==1)   
		primero = nuevo;
	else		 
		ant->sig = nuevo;

	nuevo->sig = resto; 

	tamanio++; 
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Borrar: Borra una posicion de la lista                **/
/**                                                         **/
/**   Recibe: Entero con la posicion a borrar               **/
/**                                                         **/
/*************************************************************/

void  Lista :: Borrar ( const int pos_borrar){
	TipoNodo * ant = primero;
	TipoNodo * pos = primero;

	for (int i=1; i<pos_borrar; i++) { 
		ant = pos; 
		pos = pos->sig;
	}


	if (pos_borrar==1)   
		primero = primero->sig;
	else 
		ant->sig = pos->sig;

	delete pos;
	
	tamanio--; 
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator = : Operador de asignacion, asigna una lista **/
/**               a otra                                    **/
/**                                                         **/
/**   Recibe: Otra lista                                    **/
/**                                                         **/
/*************************************************************/

Lista & Lista :: operator = (const Lista & otra){

	//Evitamos autoasignacion
	if (this != &otra){
		//Liberamos memoria
		LiberarMemoria();

		//Reservamos memoria para la copia
		ReservarMemoria( otra.Tamanio() );

		//Copiamos los datos
		CopiarDatos(otra);
	}

	return (*this);
}
/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator = : Operador de asignacion, rellena la       **/
/**               lista con el valor dado                   **/
/**                                                         **/
/**   Recibe: Dato de tipo TipoBase                         **/
/**                                                         **/
/*************************************************************/

Lista & Lista :: operator = (const TipoBase valor){

	Inicializar(valor);

	return (*this);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator [] : Operador [] , devuelve una referencia   **/
/**               al elemento del nodo pos                  **/
/**                                                         **/
/**   Recibe: Posicion                                      **/
/**                                                         **/
/*************************************************************/

TipoBase & Lista :: operator [] (const int pos){
	TipoNodo * aux = primero;

	for (int i = 1; i < pos; i++){
		aux = aux->sig;
	}

	return (aux->info);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator += : Inserta valor en la lista               **/
/**                                                         **/
/**   Recibe: Dato de tipo TipoBase                         **/
/**                                                         **/
/*************************************************************/

Lista & Lista :: operator += (const TipoBase valor){
	AniadirValor(valor);

	return (*this);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator -= : Elimina la primera ocurrencia de valor  **/
/**                                                         **/
/**   Recibe: Dato de tipo TipoBase                         **/
/**                                                         **/
/*************************************************************/

Lista & Lista :: operator -= (const TipoBase valor){
	EliminarValor(valor);

	return (*this);
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator + : Concatena dos listas                     **/
/**                                                         **/
/**   Recibe: Listas a concatenar                           **/
/**                                                         **/
/*************************************************************/

Lista operator + (const Lista & l1, const Lista & l2){
	Lista nueva_lista = l1;

	TipoNodo * aux = l2.primero;

	while (aux != 0){
		nueva_lista += aux->info;
		aux = aux->sig;
	}

	return (nueva_lista);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator + : Concatena un valor a la lista            **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Valor                                         **/
/**                                                         **/
/*************************************************************/

Lista operator + (const Lista & l, const TipoBase valor){
	Lista l2;

	l2.AniadirValor(valor);

	return (l + l2);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator + : Concatena un valor a la lista, pone      **/
/**               el valor en primer lugar                  **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Valor                                         **/
/**                                                         **/
/*************************************************************/

Lista operator + (const TipoBase valor, const Lista & l){
	Lista l2;

	l2.AniadirValor(valor);

	return (l2 + l);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator - : Elimina los elementos de l2 de l1        **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Lista                                         **/
/**                                                         **/
/*************************************************************/

Lista operator - (const Lista & l1, const Lista & l2){
	Lista nueva_lista = l1;

	TipoNodo * aux = l2.primero;

	while (aux != 0){
		nueva_lista.EliminarValor(aux->info);
		aux = aux->sig;
	}

	return nueva_lista;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator - : Elimina las ocurrencias de valor         **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Valor                                         **/
/**                                                         **/
/*************************************************************/

Lista operator - (const Lista & l, const TipoBase valor){
	Lista l2;

	l2.AniadirValor(valor);

	return (l - l2);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator - : Elimina las ocurrencias de valor         **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Valor                                         **/
/**                                                         **/
/*************************************************************/

Lista operator - (const TipoBase valor, const Lista & l){
	Lista l2;

	l2.AniadirValor(valor);

	return (l2 - l);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator == : Comprueba si dos listas son iguales     **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Lista                                         **/
/**                                                         **/
/*************************************************************/

bool Lista :: operator == (const Lista & l){

	//Comprobamos el tamaño
	bool es_igual = Tamanio() == l.Tamanio() ;

	if (this != &l){
		TipoNodo * explicita = l.primero;
		TipoNodo * implicita = primero;

		//Recorremos la lista comparando los valores
		while (explicita != 0 && es_igual){
			es_igual = explicita->info == implicita->info;
			explicita = explicita->sig;
			implicita = implicita->sig;
		}
	}

	return es_igual;	
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator != : Comprueba si dos listas son distintas   **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Lista                                         **/
/**                                                         **/
/*************************************************************/


bool Lista :: operator != (const Lista & l){
	return ( !(*this == l) );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator > : Comprueba si una lista es mayor que otra **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Lista                                         **/
/**                                                         **/
/*************************************************************/


bool Lista :: operator > (const Lista & l){

	bool es_mayor = false;

	if (this != &l && *this != l){

		TipoNodo * implicita = primero;
		TipoNodo * explicita = l.primero;

		// Comparamos elemento a elemento, hasta que un elemento es mayor,
		//o acaba una lista
		while (implicita && explicita && !es_mayor ){

			if( implicita->info > explicita->info)
				es_mayor = true;

			implicita = implicita->sig;
			explicita = explicita->sig;
		} 
	}

	return es_mayor;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator >= : Comprueba si una lista es mayor o igual **/
/**                a otra                                   **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Lista                                         **/
/**                                                         **/
/*************************************************************/


bool Lista :: operator >= (const Lista & l){

	//Es mayor o igual si es mayor o si es igual
	return ( (*this > l) || (*this == l) );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator < : Comprueba si una lista es menor a otra   **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Lista                                         **/
/**                                                         **/
/*************************************************************/

bool Lista :: operator < (const Lista & l){

	//Es menor si no es mayor y si es distinta
	return ( !(*this > l) && !(*this == l) );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator <= : Comprueba si una lista es menor o igual **/
/**                a otra                                   **/
/**                                                         **/
/**   Recibe: Lista                                         **/
/**           Lista                                         **/
/**                                                         **/
/*************************************************************/

bool Lista :: operator <= (const Lista & l){

	//Es menor o igual si no es mayor
	return (! (*this > l) );
}



/******************************************************************************/
/******************************************************************************/
// METODOS PRIVADOS
/******************************************************************************/
/******************************************************************************/




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

TipoBase Lista :: LeerValor (const int pos) const{
	TipoNodo * p = primero;
	for (int i = 1; i < pos; i++) 
		p = p->sig;
	

	return (p->info);
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

void  Lista :: ModificarValor (const TipoBase valor, const int pos){
	TipoNodo * p = primero;
	for (int i = 1; i < pos; i++) 
		p = p->sig;


	p->info = valor;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   AniadirValor: Añade un valor al final de la lista     **/
/**                                                         **/
/**   Recibe: Valor a añadir                                **/
/**                                                         **/
/*************************************************************/


void  Lista :: AniadirValor (const TipoBase valor){

	TipoNodo * nuevo = new TipoNodo;
	nuevo->info = valor;
	nuevo->sig = 0;

	if (primero != 0) {  

		TipoNodo * p = primero;
		
		for(int i=1; i<tamanio; i++)
			p = p->sig;

					
		p->sig = nuevo;
	}
	else { 
		primero = nuevo; 
	}
	
	tamanio++;
}

void Lista :: EliminarValor (const TipoBase valor){
	int pos = Buscar (valor);

	if (pos > 0) Borrar (pos);
}



/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   ReservarMemoria: Reserva memoria para el numero       **/
/**                   de nodos dado                         **/
/**                                                         **/
/**   Recibe: Valor a con el numero de nodos                **/
/**                                                         **/
/*************************************************************/

void  Lista :: ReservarMemoria (const int num_elementos){
	if (num_elementos > 0) {
		
		primero = new TipoNodo;	

		TipoNodo * ultimo = primero;
		TipoNodo * p;

		for (int i = 1; i < num_elementos; i++) {

			p = new TipoNodo;	
			ultimo->sig = p;
			ultimo = p;	
		}						

		ultimo->sig = 0; 
	} 
	else primero = 0; 
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   LiberarMemoria: Libera la memoria usada               **/
/**                                                         **/
/**                                                         **/
/*************************************************************/

void  Lista :: LiberarMemoria (){
	if (primero !=0) {
		
		TipoNodo *p = primero; 

		while (primero->sig != 0) {

			primero = primero->sig; 
			delete p;
			p = primero;
		}

		delete primero;
		
		primero = 0; 
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   CopiarDatos: Copia los datos de una lista en otra     **/
/**                                                         **/
/**   Recibe: Lista con valores a copiar                    **/
/**                                                         **/
/*************************************************************/

void Lista :: CopiarDatos (const Lista & otro){

    tamanio = otro.tamanio;


	TipoNodo * p_este = primero; 
	TipoNodo * p_otro = otro.primero; 

	for(int i = 0; i < tamanio; i++) {

		p_este->info = p_otro->info; 

		p_este = p_este->sig;		 
		p_otro = p_otro->sig;		 
	}	
}



/***************************************************************************/
/***************************************************************************/
// Otras funciones no pertenecientes a la clase
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
// Muestra el contenido de una lista, precedido del mensaje "msg"
void PintaLista (const Lista & l, const char * msg)
{
	cout << endl; 
	cout << "--------------------------------------------------" << endl;
	cout << msg << endl;

	int tamanio = l.Tamanio();

	for(int pos=1; pos<=tamanio; pos++) 
		cout << l.LeerValor (pos) << ((pos != tamanio)?" - ":"");
	cout << endl; 

	cout << "--------------------------------------------------" << endl;  
	cout << endl;
}

/***************************************************************************/
/***************************************************************************/

/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 4 - Clase Lista                  **/
/**                                                         **/
/*************************************************************/

#include <iostream>

#include "Lista.h"

using namespace std; 

/***************************************************************************/
// Constructor sin argumentos: crea una lista vacia.
Lista :: Lista (void)  : primero(0), tamanio(0)
{ }


Lista :: Lista (int tam)
               : tamanio(tam){
	ReservarMemoria (tamanio);
}


Lista :: Lista (int tam, TipoBase valor) 
               : tamanio(tam){
	ReservarMemoria (tamanio);
	Inicializar (valor);
}
	

Lista :: Lista (const Lista & otro){	
	// Reservar memoria para los nodos de la lista
	ReservarMemoria (otro.tamanio);

	// Copiar campos privados y los valores de la lista
	CopiarDatos (otro);
}		


Lista :: ~Lista (){
    LiberarMemoria ();
}


bool Lista :: EstaVacia() const{
	return (tamanio == 0);
}	

void  Lista :: Inicializar (const TipoBase valor){
	TipoNodo * p = primero; // Apuntar al primero.

	for(int i = 0; i < tamanio; i++) {
		p->info = valor; // Inicializar nodo.
		p = p->sig;		 // Adelantar "p".
	}						
}
	
int Lista :: Tamanio()	const{
	return tamanio;
}


int Lista :: Buscar (const TipoBase valor) const{
    TipoNodo * p = primero;

    bool sigo = true;
    bool encontrado = false;

	int pos = 0;
    	
    while ((p!=0) && sigo) {
    	
		pos++; // Actualizar posici�n

        if (p->info == valor) {
            sigo = false;
            encontrado = true;
        }
        else 
            p = p->sig;
	}
	
	return (encontrado ? (pos) : -1); 
}	


TipoBase Lista :: LeerValor (const int pos) const{
	TipoNodo * p = primero;
	for (int i = 1; i < pos; i++) 
		p = p->sig;
	

	return (p->info);
}	

void  Lista :: ModificarValor (const TipoBase valor, const int pos){
	TipoNodo * p = primero;
	for (int i = 1; i < pos; i++) 
		p = p->sig;


	p->info = valor;
}

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


Lista & Lista :: operator = (const Lista & otra){

	if (this != &otra){
		LiberarMemoria();

		ReservarMemoria( otra.Tamanio() );

		CopiarDatos(otra);
	}

	return (*this);
}

Lista & Lista :: operator = (const TipoBase valor){

	Inicializar(valor);

	return (*this);
}

TipoBase & Lista :: operator [] (const int pos){
	TipoNodo * aux = sig;

	for (int i = 1; i < pos; i++){
		aux = aux->sig;
	}

	return (aux->info);
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

/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**                                                         **/
/*************************************************************/


// METODOS PUBLICOS

#include "Conjunto.h"

Conjunto :: Conjunto ()
				:num_elementos(0), primero(0)
{
}

Conjunto :: Conjunto(const TipoBase valor)
				:num_elementos(1)
{
	ReservarMemoria(num_elementos);
	
	primero->valor = valor;
	primero->siguiente = 0;

}

Conjunto :: Conjunto(const Conjunto & otro){

	ReservarMemoria(otro.NumElementos());

	CopiarDatos(otro);

}

Conjunto :: ~Conjunto(){
	LiberarMemoria();
}

bool Conjunto :: EstaVacio() const{
	return (primero == 0);
}

int Conjunto :: NumElementos() const{
	return num_elementos;
}


//Lo añade de forma ordenada
void Conjunto :: Aniadir (const TipoBase valor){
	if ( BuscarElemento(valor) == -1 ){
		PNodo next = primero;
		PNodo anterior = primero;
		PNodo nuevo;

		while (next->siguiente != 0 && valor < next->valor){
			next = next->siguiente;
		}

		if (valor < next->valor){

			while (anterior->siguiente != next){
				anterior = anterior->siguiente;
			}

			anterior->siguiente = new TipoNodo;

			nuevo = anterior->siguiente;

			nuevo->valor = valor;
			nuevo->siguiente = next;
			
		}
		//Si no, hay que añadirlo al final
		else{
			next->siguiente = new TipoNodo;
			next = next->siguiente;

			next->valor = valor;
			next->siguiente = 0;

		}
	}
}

void Conjunto :: Eliminar(const TipoBase valor){
	int pos_eliminar = BuscarElemento(valor);

	if (pos_eliminar != -1){
		PNodo a_eliminar = primero;
		PNodo anterior = primero;

		if(pos_eliminar == 1){
			primero = a_eliminar->siguiente;

		}
		else{
			for(int i = 1; i < pos_eliminar; i++){
				a_eliminar = a_eliminar->siguiente;
			}

			while (anterior->siguiente != a_eliminar){
				anterior = anterior->siguiente;
			}

			anterior->siguiente = a_eliminar->siguiente;

			

		}

		delete a_eliminar;
	}
}

//Si no lo encuentra devuelve -1
int Conjunto :: BuscarElemento (const TipoBase valor) const {
	int pos = -1;

	PNodo aux = primero;
	int contador = 1;

	while(aux->siguiente != 0){
		(aux->valor == valor) ? (pos = contador ) : contador++;
		aux = aux->siguiente;
	}

	return pos;

}

bool Conjunto :: PerteneceAlConjunto (const TipoBase valor )const{
	return (BuscarElemento(valor) != -1);
}


Conjunto & Conjunto :: operator = (const Conjunto & otro){
	if (this != &otro){
		LiberarMemoria();

		ReservarMemoria(otro.num_elementos);

		CopiarDatos(otro);
	}

	return (*this);
}


//Sabemos que los elementos estan ordenados
bool Conjunto :: operator == (const Conjunto & otro) const{
	
	bool esta_ordenado = num_elementos == otro.num_elementos;

	if (esta_ordenado){

		PNodo aux_implicito = primero;
		PNodo aux_explicito = otro.primero;

		while(aux_implicito->siguiente != 0 && esta_ordenado){
			esta_ordenado = aux_implicito->valor == aux_explicito->valor;

			aux_implicito = aux_implicito->siguiente;
			aux_explicito = aux_explicito->siguiente; 
		}
	}

	return esta_ordenado;

}

bool Conjunto :: operator != (const Conjunto & otro) const{
	return ( !( (*this) == otro ) );
}

Conjunto operator + (const Conjunto & este, const Conjunto & otro){
	
	Conjunto final;

	PNodo aux_este = este.primero;
	PNodo aux_otro = otro.primero;

	while (aux_este != 0 && aux_otro != 0){
		if(aux_este->valor < aux_otro->valor){
			final.Aniadir(aux_este->valor);
			aux_este = aux_este->siguiente;
		}
		else{
			final.Aniadir(aux_otro->valor);
			aux_otro = aux_otro->siguiente;
		}
	}

	while (aux_este != 0){
		final.Aniadir(aux_este->valor);
		aux_este = aux_este->siguiente;
	}

	while (aux_otro != 0){
		final.Aniadir(aux_otro->valor);
		aux_otro = aux_otro->siguiente;
	}

	return final;
}

Conjunto operator + (const Conjunto & este, const TipoBase valor){
	Conjunto aux(valor);

	return (este + aux);
}

Conjunto operator + (const TipoBase valor, const Conjunto & este){
	Conjunto aux(valor);

	return (aux + este);
}


// Metodos PRIVADOS

void Conjunto :: ReservarMemoria(const int num_reservas){
	num_elementos = num_reservas;

	primero = new TipoNodo;

	PNodo aux = primero;
	
	for (int i = 1; i < num_reservas; i++){
		aux->valor = NULO;

		aux->siguiente = new TipoNodo;

		aux = aux->siguiente;
	}

	aux->valor = NULO;

	aux->siguiente = 0;
}

void Conjunto :: LiberarMemoria(){
	
	if (primero != 0){

		PNodo aux = primero;
		PNodo p_sig = aux->siguiente;
		while(p_sig != 0){
			delete aux;
			aux = p_sig;
			p_sig = p_sig->siguiente;
		}

		delete aux;
	
		primero = 0;

	}

	num_elementos = 0;
}

void Conjunto :: CopiarDatos(const Conjunto & otro){
	num_elementos = otro.num_elementos;

	PNodo nuevo = primero;
	PNodo datos_otro = otro.primero;

	while(datos_otro != 0){
		nuevo->valor = datos_otro->valor;

		nuevo = nuevo->siguiente;
		datos_otro = datos_otro->siguiente;
	}

}
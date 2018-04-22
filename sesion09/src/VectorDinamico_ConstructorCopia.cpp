/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 1 - Clase vector                  **/
/**                                                         **/
/*************************************************************/

#include "VectorDinamico_ConstructorCopia.h"
#include "TipoBase.h"
#include "RedimensionVector.h"
#include <cstring>

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor sin parametros, reserva memoria e         **/
/**  inicializa las variables                               **/
/**                                                         **/
/*************************************************************/

VectorDinamico::VectorDinamico(){
	ReservarMemoria(TAM_INICIAL);
	ocupadas = 0;
	reservadas = TAM_INICIAL;
	tipo_redimension = TipoRedimension::DeUnoEnUno;
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor con un parametro, reserva memoria para el **/
/**  valor dado e inicializa las variables                  **/
/**                                                         **/
/*************************************************************/

VectorDinamico::VectorDinamico(const int valor){
	ReservarMemoria(valor);
	ocupadas = 0;
	reservadas = valor;
	tipo_redimension = TipoRedimension::DeUnoEnUno;

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor de copia, reserva la misma cantidad de    **/
/**  memoria que el vector dado, y copia los datos en el    **/
/**  nuevo vector                                           **/
/**                                                         **/
/*************************************************************/

VectorDinamico::VectorDinamico(const VectorDinamico & otro_vector){
	ocupadas = otro_vector.ocupadas;
	reservadas = otro_vector.reservadas;
	tipo_redimension = TipoRedimension::DeUnoEnUno;


	ReservarMemoria(reservadas);

	CopiarDatos(otro_vector);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Destructor, libera la memoria del vector y establece  **/
/**  los datos miembro a 0                                  **/
/**                                                         **/
/*************************************************************/

VectorDinamico::~VectorDinamico(){
	LiberarMemoria();
	ocupadas = 0;
	reservadas = 0;
	vector = 0;
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   ReservarMemoria: Reservamos memoria para tantas       **/
/**  casillas como num_a_reservar                           **/
/**                                                         **/
/**   Recibe: Numero entero                                 **/
/**                                                         **/
/*************************************************************/

void VectorDinamico::ReservarMemoria(const int num_a_reservar){
	vector = new TipoBase [num_a_reservar];
	reservadas = num_a_reservar;
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   CopiarDatos: Copiamos los datos de otro vector en     **/
/**  el objeto implicito                                    **/
/**                                                         **/
/**   Recibe: Vector a copiar                               **/
/**                                                         **/
/*************************************************************/

void VectorDinamico::CopiarDatos(const VectorDinamico & otro_vector){
	memcpy(vector, otro_vector.vector, ocupadas*sizeof(TipoBase));
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   LiberarMemoria: Liberamos la memoria reservada para   **/
/**  el vector                                              **/
/**                                                         **/
/*************************************************************/

void VectorDinamico::LiberarMemoria(){
	delete [] vector;
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   EstaVacio: Comprobamos si el vector esta vacio        **/
/**                                                         **/
/**   Devuelve: Booleano                                    **/
/**                                                         **/
/*************************************************************/

bool VectorDinamico::EstaVacio() const{
	return ocupadas == 0;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   CasillasOcupadas: Devuelve el numero de casillas      **/
/**  ocupadas                                               **/
/**                                                         **/
/**   Devuelve: Entero con las casillas ocupadas            **/
/**                                                         **/
/*************************************************************/

int VectorDinamico::CasillasOcupadas() const{
	return ocupadas;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Valor: Devuelve el valor de una posicion dada         **/
/**                                                         **/
/**   Devuelve: Valor que hay en la posicion dada           **/
/**                                                         **/
/**   PRE : La posicion es correcta y esta siendo usada por **/
/**  el vector                                              **/
/**                                                         **/
/*************************************************************/

TipoBase VectorDinamico::Valor(const int posicion) const{
	return vector[posicion];
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   NuevoElemento: Añade un elemento al final del vector  **/
/**                                                         **/
/**   Recibe:  Valor a añadir                               **/
/**                                                         **/
/*************************************************************/

void VectorDinamico::NuevoElemento(const TipoBase valor){

	//Si no hay espacio, pedimos mas casillas
	if(ocupadas == reservadas)
		Redimensiona();
	
	//Añadimos el valor, y aumentamos el numero de casillas ocupadas
	vector[ocupadas] = valor;
	ocupadas++;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   RedimensionUsada: Devuelve el tipo de redimension     **/
/**  usada                                                  **/
/**                                                         **/
/**   Devuelve: Tipo de redimension usada                   **/
/**                                                         **/
/*************************************************************/

TipoRedimension VectorDinamico::RedimensionUsada() const{
	return tipo_redimension;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   SetTipoRedimension: Cambia el tipo de redimension     **/
/**  usado                                                  **/
/**                                                         **/
/**   Recibe: Nuevo tipo de redimension                     **/
/**                                                         **/
/*************************************************************/

void VectorDinamico::SetTipoRedimension(const TipoRedimension tipo){
	tipo_redimension = tipo;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   CasillasReservadas: Devuelve el numero de casillas    **/
/**  reservadas                                             **/
/**                                                         **/
/**   Devuelve: Entero con las casillas reservadas          **/
/**                                                         **/
/*************************************************************/

int VectorDinamico::CasillasReservadas() const{
	return reservadas;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   AjustarTamanio: Ajusta el tamaño del vector para      **/
/**  que tenga reservadas el mismo numero de casillas que   **/
/**  ocupadas                                               **/
/**                                                         **/
/*************************************************************/

void VectorDinamico::AjustarTamanio(){

	//Creamos un nuevo vector con el numero de casillas ocupadas
	Vector nuevo_vector = new TipoBase [ocupadas];

	//Copiamos el vector original en el nuevo vector
	memcpy(nuevo_vector, vector, ocupadas*sizeof(TipoBase));

	//Liberamos el vector original
	LiberarMemoria();

	//El vector original pasa a ser el nuevo vector
	vector = nuevo_vector;

	//Reservadas pasa a ser ocupadas
	reservadas = ocupadas;

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Redimensiona: Cambia el tamaño de un vector dinamico  **/
/**                                                         **/
/*************************************************************/

void VectorDinamico::Redimensiona(){
	const int TAM_BLOQUE = 10;
	int tam_redimensionado;

	//Ajusta el tamanio del nuevo vector segun el tipo de redimension
	if (tipo_redimension == TipoRedimension::DeUnoEnUno){
		tam_redimensionado = reservadas + 1;
		
	}else if (tipo_redimension == TipoRedimension::EnBloques){
		tam_redimensionado = reservadas + TAM_BLOQUE;

	}else if (tipo_redimension == TipoRedimension::Duplicando){
		tam_redimensionado = 2 * reservadas;
	}

	//Declara un nuevo vector con el nuevo tamaño;
	Vector nuevo_vector = new TipoBase [tam_redimensionado];

	//Copia el contenido del antiguo vector en el nuevo
	memcpy(nuevo_vector, vector, ocupadas*sizeof(TipoBase));
	//Actualiza la capacidad
	reservadas = tam_redimensionado;

	//Libera la memoria consumida por el vector anriguo
	LiberarMemoria();

	vector = nuevo_vector;

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   SetValor: Cambia el valor de una posicion dada        **/
/**                                                         **/
/**   Recibe: Entero con la posicion a cambiar              **/
/**           Valor con el que se actualizara               **/
/**                                                         **/
/*************************************************************/

void VectorDinamico::SetValor(const int posicion, const TipoBase valor){
	vector[posicion] = valor;
}
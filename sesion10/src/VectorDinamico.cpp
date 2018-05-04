/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 1 - Clase vector                 **/
/**                                                         **/
/*************************************************************/

#include "VectorDinamico.h"
#include "TipoBase.h"
#include <cstring>

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor sin parametros, reserva memoria e         **/
/**  inicializa las variables                               **/
/**                                                         **/
/*************************************************************/

VectorDinamico::VectorDinamico(){
	ocupadas = 0;
	vector = 0;
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
	ocupadas = valor;
	Inicializar(0);

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


	ReservarMemoria(ocupadas);

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
	vector = 0;
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
	Redimensiona();
	
	//Añadimos el valor, y aumentamos el numero de casillas ocupadas
	vector[ocupadas] = valor;
	ocupadas++;
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

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operador de asignacion                                **/
/**                                                         **/
/*************************************************************/

VectorDinamico & VectorDinamico :: operator = (const VectorDinamico & otro){
	//Evitamos autoasignacion
	if (this != &otro){
		//Liberamos memoria
		LiberarMemoria();
		
		//Pedimos memoria para la nueva asignacion
		ReservarMemoria(otro.ocupadas);

		//Copiamos los datos
		CopiarDatos(otro);
	}

	return (*this);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operador de asignacion, establecemos los valores al   **/
/**  valor dado                                             **/
/**                                                         **/
/*************************************************************/

VectorDinamico & VectorDinamico :: operator = (const TipoBase valor){
	Inicializar(valor);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operador [], accedemos a una posicion dada            **/
/**                                                         **/
/*************************************************************/


TipoBase & VectorDinamico :: operator [] (const int indice){

	//Si esa posicion no es usada, pedimos memoria para ella
	if(ocupadas < indice + 1){
		Redimensiona(indice + 1);
	}

	return (vector[indice]);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operador ==: Comparamos si dos vectores son iguales   **/
/**                                                         **/
/*************************************************************/

bool VectorDinamico :: operator == (const VectorDinamico & otro){
	//Comprobamos su tamaño
	bool es_igual = ocupadas == otro.ocupadas;

	//Si tienen el mismo tamaño, comparamos elemento a elemento
	if (es_igual){
		for (int i = 0; i < ocupadas && es_igual; i++){
			es_igual = vector[i] == otro.vector[i];
		}
	}

	return es_igual;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**  Operador !=: Comprobamos si dos vectores son distintos **/
/**                                                         **/
/*************************************************************/

bool VectorDinamico :: operator != (const VectorDinamico & otro){
	return ( !(*this == otro) );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**  Operador >: Comprobamos si un vector es mayor a otro   **/
/**                                                         **/
/*************************************************************/

bool VectorDinamico :: operator > (const VectorDinamico & otro){
	bool es_mayor = false;

	if ( *this != otro){

		int i = 0;
		int j = 0;

		//Comprobamos elemento a elemento, hasta que uno es mayor

		while (i < ocupadas && j < otro.ocupadas && !es_mayor ){

			if( vector[i] > otro.vector[i])
				es_mayor = true;

			i++;
			j++;
		}
	}

	return es_mayor;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**  Operador >=: Comprobamos si un vectore es mayor o      **/
/**              igual a otro                               **/
/**                                                         **/
/*************************************************************/

bool VectorDinamico :: operator >= (const VectorDinamico & otro){
	//Es mayor o igual si es mayor o si es igual

	return ( (*this > otro) || (*this == otro) );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**  Operador <: Comprobamos si un vector es menor a otro   **/
/**                                                         **/
/*************************************************************/

bool VectorDinamico :: operator < (const VectorDinamico & otro){
	//Es menor si no es mayor y si no es igual
	return ( !(*this > otro) && !(*this == otro) );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**  Operador <=: Comprobamos si un vectore es menor o      **/
/**              igual a otro                               **/
/**                                                         **/
/*************************************************************/

bool VectorDinamico :: operator <= (const VectorDinamico & otro){
	//Es menor o igual si no es mayor
	return ( !(*this > otro) );
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Redimensiona: Cambia el tamaño de un vector dinamico  **/
/**                                                         **/
/*************************************************************/

void VectorDinamico::Redimensiona(const int casillas){
	int tam_redimensionado;

	if (casillas == 0)
		tam_redimensionado = ocupadas + 1;
	else
		tam_redimensionado = casillas;


	//Declara un nuevo vector con el nuevo tamaño;
	TipoBase * nuevo_vector = new TipoBase [tam_redimensionado];

	//Copia el contenido del antiguo vector en el nuevo
	memcpy(nuevo_vector, vector, ocupadas*sizeof(TipoBase));
	//Actualiza la capacidad
	ocupadas = tam_redimensionado;

	//Libera la memoria consumida por el vector anriguo
	LiberarMemoria();

	vector = nuevo_vector;

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
	ocupadas = num_a_reservar;
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

void VectorDinamico :: LiberarMemoria(){
	if (vector != 0)
		delete [] vector;

}


void VectorDinamico :: Inicializar (const TipoBase valor){
	for (int i = 0; i < ocupadas; i++)
		vector[i] = valor;
}
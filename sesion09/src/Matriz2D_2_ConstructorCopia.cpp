/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 4 - Clase Matriz_2                **/
/**                                                         **/
/*************************************************************/


#include "Matriz2D_2_ConstructorCopia.h"
#include "TipoBase.h"
#include "GeneradorAleatorioEnteros.h"
#include <cstring>

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor sin parametros, inicia a matriz vacia e   **/
/**  inicializa las variables                               **/
/**                                                         **/
/*************************************************************/

Matriz2D_2::Matriz2D_2(){
	filas = 0;
	columnas = 0;

	datos = 0;
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor con un parametro, reserva memoria para una**/
/**  matriz de tam*tam  e inicializa las variables          **/
/**                                                         **/
/*************************************************************/

Matriz2D_2::Matriz2D_2(const int tam){

	filas = tam;
	columnas = tam;
	ReservarMemoria(tam, tam);

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor con dos parametros, reserva memoria para  **/
/**  una matriz de nuevas_filas*nuevas_columnas  e          **/
/**  inicializa las variables                               **/
/**                                                         **/
/*************************************************************/

Matriz2D_2::Matriz2D_2(const int nuevas_filas, const int nuevas_columnas){

	filas = nuevas_filas;
	columnas = nuevas_columnas;

	ReservarMemoria(nuevas_filas, nuevas_columnas);
	
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor con tres parametros, reserva memoria para **/
/**  una matriz de nuevas_filas*nuevas_columnas  e          **/
/**  inicializa los valores al tercer parametro dado        **/
/**                                                         **/
/*************************************************************/


Matriz2D_2::Matriz2D_2(const int nuevas_filas, const int nuevas_columnas,
                   const TipoBase valor_inicial){
	filas = nuevas_filas;
	columnas = nuevas_columnas;

	ReservarMemoria(nuevas_filas, nuevas_columnas);
	
	Inicializar(valor_inicial);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor de copia, reserva la misma cantidad de    **/
/**  memoria que la matriz dada, y copia los datos en la    **/
/**  nuevo matriz                                           **/
/**                                                         **/
/*************************************************************/


Matriz2D_2::Matriz2D_2(const Matriz2D_2 & otra){
	filas = otra.filas;
	columnas = otra.columnas;

	ReservarMemoria(filas, columnas);

	CopiarDatos(otra);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Destructor,libera la memoria de la matriz y establece **/
/**  los datos miembro a 0                                  **/
/**                                                         **/
/*************************************************************/


Matriz2D_2::~Matriz2D_2(){
	LiberarMemoria();

	datos = 0;
	filas = 0;
	columnas = 0;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Inicializar: Rellena la matriz con el valor dado      **/
/**                                                         **/
/**   Recibe: Valor con el que se rellenara la matriz       **/
/**                                                         **/
/*************************************************************/


void Matriz2D_2::Inicializar(const TipoBase valor){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			datos[i][j] = valor;
		}
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   LiberarMemoria: Liberamos la memoria reservada para   **/
/**  la matriz                                              **/
/**                                                         **/
/*************************************************************/


void Matriz2D_2::LiberarMemoria(){
	delete [] datos[0];

	delete [] datos;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   ReservarMemoria: Reservamos memoria para una matriz   **/
/**  de casillas como nuevas_filas*nuevas_columnas          **/
/**                                                         **/
/**   Recibe: Numero entero con las filas                   **/
/**           Numero entero con las columnas                **/
/**                                                         **/
/*************************************************************/


void Matriz2D_2::ReservarMemoria(const int nuevas_filas, const int nuevas_columnas){
	datos = new TipoBase * [nuevas_filas];

	datos[0] = new TipoBase [nuevas_filas*nuevas_columnas];

	for (int i = 1; i < filas; i++){
		datos[i] = datos[i - 1] + columnas;
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   CopiarDatos: Copiamos los datos de otra matriz en     **/
/**  el objeto implicito                                    **/
/**                                                         **/
/**   Recibe: Matriz a copiar                               **/
/**                                                         **/
/*************************************************************/


void Matriz2D_2::CopiarDatos(const Matriz2D_2 & otra){
	for(int i = 0; i < filas; i++){
		memcpy(datos[i], otra.datos[i], otra.columnas*sizeof(TipoBase));
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   EstaVacio: Comprobamos si la matriz esta vacia        **/
/**                                                         **/
/**   Devuelve: Booleano                                    **/
/**                                                         **/
/*************************************************************/


bool Matriz2D_2::EstaVacia() const{
	return (filas == 0 || columnas == 0);
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   ModificarValor: Cambia el valor de una posicion dada  **/
/**                                                         **/
/**   Recibe: Entero con la fila a cambiar                  **/
/**           Entero con la columna a cambiar               **/
/**           Valor con el que se actualizara               **/
/**                                                         **/
/*************************************************************/

void Matriz2D_2::ModificarValor(const int fila, const int columna,
                              const TipoBase valor){
	datos[fila][columna] = valor;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Valor: Devuelve el valor de una posicion dada         **/
/**                                                         **/
/**   Devuelve: Valor que hay en la posicion dada           **/
/**                                                         **/
/**   PRE : La posicion es correcta y esta siendo usada por **/
/**  la matriz                                              **/
/**                                                         **/
/*************************************************************/


TipoBase Matriz2D_2::LeerValor(const int fila, const int columna) const{
	return datos[fila][columna];
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   CambiarTamanio: Cambia el tamaño de la matriz         **/
/**                                                         **/
/**   Recibe: Numero de nuevas filas                        **/
/**           Numero de nuevas columnas                     **/
/**                                                         **/
/*************************************************************/

void Matriz2D_2::CambiarTamanio(const int n_filas, const int n_columnas){
	
	Matriz2D_2 n_matriz (n_filas, n_columnas);

	for (int i = 0; i < n_filas; i++){
		memcpy(n_matriz.datos[i], datos[i], n_columnas * sizeof(TipoBase));
	}

	LiberarMemoria();

	filas = n_filas;
	columnas = n_columnas;
	ReservarMemoria(n_filas, n_columnas);
	CopiarDatos(n_matriz);

}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Filas: Devuelve el numero de filas usadas             **/
/**                                                         **/
/**   Devuelve: Numero de filas                             **/
/**                                                         **/
/*************************************************************/

int Matriz2D_2::Filas() const{
	return filas;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Columnas: Devuelve el numero de columnas usadas       **/
/**                                                         **/
/**   Devuelve: Numero de columnas                          **/
/**                                                         **/
/*************************************************************/


int Matriz2D_2::Columnas() const{
	return columnas;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   RellenarAleatorios: Rellena la matriz de numeros      **/
/**  aleatorios                                             **/
/**                                                         **/
/**   Recibe: Minimo y maximo para el generador             **/
/**                                                         **/
/*************************************************************/


void Matriz2D_2::RellenarAleatorios(const int min, const int max){
	GeneradorAleatorioEnteros generador(min, max);

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			ModificarValor(i,j, generador.Siguiente());
		}
	}

}
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 2 - Clase Matriz                 **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "Matriz2D_1.h"
#include "TipoBase.h"
#include "GeneradorAleatorioEnteros.h"
#include <cstring>

using namespace std;

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor sin parametros, inicia a matriz vacia e   **/
/**  inicializa las variables                               **/
/**                                                         **/
/*************************************************************/

Matriz2D::Matriz2D(){
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

Matriz2D::Matriz2D(const int tam){

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

Matriz2D::Matriz2D(const int nuevas_filas, const int nuevas_columnas){

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

Matriz2D::Matriz2D(const int nuevas_filas, const int nuevas_columnas,
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

Matriz2D::Matriz2D(const Matriz2D & otra){
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

Matriz2D::~Matriz2D(){
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

void Matriz2D::Inicializar(const TipoBase valor){
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

void Matriz2D::LiberarMemoria(){
	for (int i = 0; i < filas; i++){
		delete [] datos[i];
	}

	delete [] datos;

	filas = 0;
	columnas = 0;
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

void Matriz2D::ReservarMemoria(const int nuevas_filas, const int nuevas_columnas){
	datos = new TipoBase * [nuevas_filas];

	for (int i = 0; i < nuevas_filas; i++){
		datos[i] = new TipoBase[nuevas_columnas];
	}

	filas = nuevas_filas;
	columnas = nuevas_columnas;
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

void Matriz2D::CopiarDatos(const Matriz2D & otra){
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

bool Matriz2D::EstaVacia() const{
	return (datos == 0);
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

void Matriz2D::ModificarValor(const int fila, const int columna,
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

TipoBase Matriz2D::LeerValor(const int fila, const int columna) const{
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

void Matriz2D::CambiarTamanio(const int n_filas, const int n_columnas){
	
	//Creamos un nueva matriz, copia de la original, pero con el nuevo tamaño
	Matriz2D n_matriz (n_filas, n_columnas);

	for (int i = 0; i < n_filas; i++){
		memcpy(n_matriz.datos[i], datos[i], n_columnas * sizeof(TipoBase));
	}

	//Liberamos la memoria
	LiberarMemoria();

	//Actualizamos filas y columnas
	filas = n_filas;
	columnas = n_columnas;

	//Reservamos nueva memoria, y copiamos los datos
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

int Matriz2D::Filas() const{
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

int Matriz2D::Columnas() const{
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

void Matriz2D::RellenarAleatorios(const int min, const int max){
	GeneradorAleatorioEnteros generador(min, max);

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			ModificarValor(i,j, generador.Siguiente());
		}
	}

}


/******************************************************************************/
/******************************************************************************/
/**  OPERADORES
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator = : Operador de asignacion                   **/
/**                                                         **/
/**   Recibe: Otra matriz, que le sera asignada             **/
/**                                                         **/
/*************************************************************/
Matriz2D & Matriz2D :: operator = (const Matriz2D & otra){

	//Evitamos autoasignacion
	if (this != &otra){
		//Liberamos memoria
		LiberarMemoria();

		//Reservamos memoria para la nueva matriz
		ReservarMemoria(otra.filas, otra.columnas);

		//Copiamos los datos
		CopiarDatos(otra);
	}

	return (*this);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator = : Operador de asignacion, rellena la       **/
/**               matriz con el valor dado                  **/
/**                                                         **/
/**   Recibe: Dato de tipo TipoBase                         **/
/**                                                         **/
/*************************************************************/

Matriz2D & Matriz2D :: operator = (const TipoBase valor){

	Inicializar(valor);

	return (*this);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator () : Operador ()                             **/
/**                                                         **/
/**   Recibe: Entero -> fila                                **/
/**           Entero -> columna                             **/
/**                                                         **/
/**   Devuelve: Una referencia a la casilla fila, columna   **/
/**            de la matriz                                 **/
/**                                                         **/
/*************************************************************/

TipoBase & Matriz2D :: operator () (const int fila, const int columna) const{

	return (datos[fila][columna]);

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator + : Operador unario +                        **/
/**                                                         **/
/**   Devuelve: Matriz, aplicando el operador unario +      **/
/**                                                         **/
/*************************************************************/

Matriz2D Matriz2D :: operator + () const{

	return (*this);

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator - : Operador unario -                        **/
/**                                                         **/
/**   Devuelve: Matriz, aplicando el operador unario -,     **/
/**            es decir, cambia el signo de todos de los    **/
/**            elementos de la matriz                       **/
/**                                                         **/
/*************************************************************/

Matriz2D Matriz2D :: operator - (){

	Matriz2D otra(filas, columnas);

	for (int i = 0; i < otra.filas; i++){
		for (int j = 0; j < otra.columnas; j++){
			otra.datos[i][j] = -datos[i][j];
		}
	}

	return (otra);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator + : Operador binario +                       **/
/**                                                         **/
/**   Recibe: Dos matrices a sumar                          **/
/**                                                         **/
/**   Devuelve: Matriz, aplicando la suma de dos matrices   **/
/**                                                         **/
/*************************************************************/

Matriz2D operator + (const Matriz2D & m_izda,  const Matriz2D & m_dcha){

	Matriz2D otra;

	//Si las filas concuerdan, sumamos las matrices
	if (m_izda.filas == m_dcha.filas && m_izda.columnas == m_dcha.columnas){

		otra.ReservarMemoria (m_izda.filas, m_izda.columnas);

		for (int i = 0; i < otra.filas; i++){
			for (int j = 0; j < otra.columnas; j++){
				otra.datos[i][j] = m_izda.datos[i][j] + m_dcha.datos[i][j];
			}
		}

	}
	//Si no concuerdan, devolvemos la matriz vacia;

	return (otra);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator + : Operador binario +                       **/
/**                                                         **/
/**   Recibe: Matriz                                        **/
/**           Valor de tipo TipoBase                        **/
/**                                                         **/
/**   Devuelve: Matriz, aplicando la suma de dos matrices   **/
/**                                                         **/
/*************************************************************/

Matriz2D operator + (const Matriz2D & m_izda, const TipoBase valor){

	//Creamos una matriz, rellena con el valor dado
	Matriz2D m_dcha( m_izda.filas, m_izda.columnas, valor);

	//Devolvemos la suma de las dos matrices
	return ( m_izda + m_dcha );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator + : Operador binario +                       **/
/**                                                         **/
/**   Recibe: Valor de tipo TipoBase                        **/
/**           Matriz                                        **/
/**                                                         **/
/**   Devuelve: Matriz, aplicando la suma de dos matrices   **/
/**                                                         **/
/*************************************************************/

Matriz2D operator + (const TipoBase valor, const Matriz2D & m_dcha){

	//  La suma en matrices es conmutativa,
	//luego sumamos la matriz y luego el valor
	return ( m_dcha + valor );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator - : Operador binario -                       **/
/**                                                         **/
/**   Recibe: Matriz                                        **/
/**           Matriz                                        **/
/**                                                         **/
/**   Devuelve: Matriz, aplicando la resta de dos matrices  **/
/**                                                         **/
/*************************************************************/

Matriz2D operator - (const Matriz2D & m_izd, const Matriz2D & m_dcha){
								
	Matriz2D otra = m_dcha;
	//La resa es la suma del inverso
	return (m_izd + (-otra) );

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator - : Operador binario -                       **/
/**                                                         **/
/**   Recibe: Matriz                                        **/
/**           Valor de tipo TipoBase                        **/
/**                                                         **/
/**   Devuelve: Matriz, aplicando la resta de dos matrices  **/
/**                                                         **/
/*************************************************************/

Matriz2D operator - (const Matriz2D & m_izda, const TipoBase valor){

	//Sumamos la matriz, y el inverso de valor, nos da la resta
	//Funciona ya que tenemos implementado el operador binario +
	return (m_izda + (-valor) );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator - : Operador binario -                       **/
/**                                                         **/
/**   Recibe: Valor de tipo TipoBase                        **/
/**           Matriz                                        **/
/**                                                         **/
/**   Devuelve: Matriz, aplicando la resta de dos matrices  **/
/**                                                         **/
/*************************************************************/

Matriz2D operator - (const TipoBase valor, const Matriz2D & m_dcha){

	Matriz2D otra = m_dcha;

	//Sumamos la matriz, y el inverso de valor, nos da la resta
	//Funciona ya que tenemos implementado el operador binario +
	return ( valor + (-otra) );
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator += :                                         **/
/**                                                         **/
/**   Recibe: Valor de tipo TipoBase                        **/
/**                                                         **/
/**   Devuelve: Matriz, aplicando la suma de la matriz y    **/
/**            el valor                                     **/
/**                                                         **/
/*************************************************************/

Matriz2D & Matriz2D :: operator += (const TipoBase valor){

	(*this) = (*this) + valor;
	return (*this);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator -= :                                         **/
/**                                                         **/
/**   Recibe: Valor de tipo TipoBase                        **/
/**                                                         **/
/**   Devuelve: Matriz, aplicando la resta de la matriz y   **/
/**            el valor                                     **/
/**                                                         **/
/*************************************************************/

Matriz2D & Matriz2D :: operator -= (const TipoBase valor){

	(*this) = (*this) - valor;
	return (*this);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator == : Compara si dos matrices son iguales     **/
/**                                                         **/
/**   Recibe: Matriz a comparar                             **/
/**                                                         **/
/**   Devuelve: Booleano con el resultado                   **/
/**                                                         **/
/*************************************************************/

bool Matriz2D :: operator == (const Matriz2D & otra) const{
	//Comprobamos que las filas y columnas concuerden
	bool es_igual = (filas == otra.filas) && (columnas == otra.columnas);

	if (es_igual){
		//Comparamos elemento a elemento en las casillas
		for (int i = 0; i < filas && es_igual; i++){
			for (int j = 0; j < filas && es_igual ; j++){
				es_igual = datos[i][j] == otra.datos[i][j];
			}
		}
	}

	return es_igual;

}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   operator != : Compara si dos matrices son distintas   **/
/**                                                         **/
/**   Recibe: Matriz a comparar                             **/
/**                                                         **/
/**   Devuelve: Booleano con el resultado                   **/
/**                                                         **/
/*************************************************************/

bool Matriz2D :: operator != (const Matriz2D & otra) const{
	//La desigualdad es la negacion de la igualdad
	return ( !(*this == otra) );
}







// Muestra el contenido de una matriz, precedido del mensaje "msg"
void PintaMatriz (const Matriz2D m, const char * const msg)
{
	cout << endl; 
	cout << "--------------------------------------------------" << endl;
	cout << msg << endl;
	
	for (int f=0; f<m.Filas(); f++) {
		
		for (int c=0; c<m.Columnas(); c++)
			cout << m.LeerValor (f,c) << " ";	
		cout << endl;
	}
	cout << "--------------------------------------------------" << endl;  
	cout << endl;
}
/***************************************************************************/
/***************************************************************************/

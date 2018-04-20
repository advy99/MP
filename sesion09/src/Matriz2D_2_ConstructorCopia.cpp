#include "Matriz2D_2_ConstructorCopia.h"
#include "TipoBase.h"
#include "GeneradorAleatorioEnteros.h"
#include <cstring>

Matriz2D_2::Matriz2D_2(){
	filas = 0;
	columnas = 0;

	datos = 0;
}

Matriz2D_2::Matriz2D_2(const int tam){

	filas = tam;
	columnas = tam;
	ReservarMemoria(tam, tam);

	

}

Matriz2D_2::Matriz2D_2(const int nuevas_filas, const int nuevas_columnas){

	filas = nuevas_filas;
	columnas = nuevas_columnas;

	ReservarMemoria(nuevas_filas, nuevas_columnas);
	
}

Matriz2D_2::Matriz2D_2(const int nuevas_filas, const int nuevas_columnas,
                   const TipoBase valor_inicial){
	filas = nuevas_filas;
	columnas = nuevas_columnas;

	ReservarMemoria(nuevas_filas, nuevas_columnas);
	
	Inicializar(valor_inicial);
}

Matriz2D_2::Matriz2D_2(const Matriz2D_2 & otra){
	filas = otra.filas;
	columnas = otra.columnas;

	ReservarMemoria(filas, columnas);

	CopiarDatos(otra);
}

Matriz2D_2::~Matriz2D_2(){
	LiberarMemoria();

	datos = 0;
	filas = 0;
	columnas = 0;
}

void Matriz2D_2::Inicializar(const TipoBase valor){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			datos[i][j] = valor;
		}
	}
}

void Matriz2D_2::LiberarMemoria(){
	delete [] datos[0];

	delete [] datos;
}

void Matriz2D_2::ReservarMemoria(const int nuevas_filas, const int nuevas_columnas){
	datos = new TipoBase * [nuevas_filas];

	datos[0] = new TipoBase [nuevas_filas*nuevas_columnas];

	for (int i = 1; i < filas; i++){
		datos[i] = datos[i - 1] + columnas;
	}
}

void Matriz2D_2::CopiarDatos(const Matriz2D_2 & otra){
	for(int i = 0; i < filas; i++){
		memcpy(datos[i], otra.datos[i], otra.columnas*sizeof(TipoBase));
	}
}

bool Matriz2D_2::EstaVacia() const{
	return (filas == 0 || columnas == 0);
}

void Matriz2D_2::ModificarValor(const int fila, const int columna,
                              const TipoBase valor){
	datos[fila][columna] = valor;
}

TipoBase Matriz2D_2::LeerValor(const int fila, const int columna) const{
	return datos[fila][columna];
}

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

int Matriz2D_2::Filas() const{
	return filas;
}

int Matriz2D_2::Columnas() const{
	return columnas;
}

void Matriz2D_2::RellenarAleatorios(const int min, const int max){
	GeneradorAleatorioEnteros generador(min, max);

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			ModificarValor(i,j, generador.Siguiente());
		}
	}

}
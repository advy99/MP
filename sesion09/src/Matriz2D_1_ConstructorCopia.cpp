#include "Matriz2D_1_ConstructorCopia.h"
#include "TipoBase.h"
#include "GeneradorAleatorioEnteros.h"
#include <cstring>

Matriz2D::Matriz2D(){
	filas = 0;
	columnas = 0;

	datos = 0;
}

Matriz2D::Matriz2D(const int tam){

	filas = tam;
	columnas = tam;
	ReservarMemoria(tam, tam);

	

}

Matriz2D::Matriz2D(const int nuevas_filas, const int nuevas_columnas){

	filas = nuevas_filas;
	columnas = nuevas_columnas;

	ReservarMemoria(nuevas_filas, nuevas_columnas);
	
}

Matriz2D::Matriz2D(const int nuevas_filas, const int nuevas_columnas,
                   const TipoBase valor_inicial){
	filas = nuevas_filas;
	columnas = nuevas_columnas;

	ReservarMemoria(nuevas_filas, nuevas_columnas);
	
	Inicializar(valor_inicial);
}

Matriz2D::Matriz2D(const Matriz2D & otra){
	filas = otra.filas;
	columnas = otra.columnas;

	ReservarMemoria(filas, columnas);

	CopiarDatos(otra);
}

Matriz2D::~Matriz2D(){
	LiberarMemoria();

	datos = 0;
	filas = 0;
	columnas = 0;
}

void Matriz2D::Inicializar(const TipoBase valor){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			datos[i][j] = valor;
		}
	}
}

void Matriz2D::LiberarMemoria(){
	for (int i = 0; i < filas; i++){
		delete [] datos[i];
	}

	delete [] datos;
}

void Matriz2D::ReservarMemoria(const int nuevas_filas, const int nuevas_columnas){
	datos = new TipoBase * [nuevas_filas];

	for (int i = 0; i < nuevas_filas; i++){
		datos[i] = new TipoBase[nuevas_columnas];
	}
}

void Matriz2D::CopiarDatos(const Matriz2D & otra){
	for(int i = 0; i < filas; i++){
		memcpy(datos[i], otra.datos[i], otra.columnas*sizeof(TipoBase));
	}
}

bool Matriz2D::EstaVacia() const{
	return (filas == 0 || columnas == 0);
}

void Matriz2D::ModificarValor(const int fila, const int columna,
                              const TipoBase valor){
	datos[fila][columna] = valor;
}

TipoBase Matriz2D::LeerValor(const int fila, const int columna) const{
	return datos[fila][columna];
}

void Matriz2D::CambiarTamanio(const int n_filas, const int n_columnas){
	
	Matriz2D n_matriz (n_filas, n_columnas);

	for (int i = 0; i < n_filas; i++){
		memcpy(n_matriz.datos[i], datos[i], n_columnas * sizeof(TipoBase));
	}

	LiberarMemoria();

	filas = n_filas;
	columnas = n_columnas;
	ReservarMemoria(n_filas, n_columnas);
	CopiarDatos(n_matriz);

}

int Matriz2D::Filas() const{
	return filas;
}

int Matriz2D::Columnas() const{
	return columnas;
}

void Matriz2D::RellenarAleatorios(const int min, const int max){
	GeneradorAleatorioEnteros generador(min, max);

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			ModificarValor(i,j, generador.Siguiente());
		}
	}

}
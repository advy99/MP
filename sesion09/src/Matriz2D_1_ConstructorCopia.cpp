#include "Matriz2D_1ConstructorCopia.h"
#include "TipoBase.h"
#include <cstring>

Matriz2D::Matriz2D(){
	filas = 0;
	columnas = 0;

	datos = 0;
}

Matriz2D::Matriz2D(const int tam){
	ReservarMemoria(tam, tam);

	filas = tam;
	columnas = tam;

}

Matriz2D::Matriz2D(const int nuevas_filas, const int nuevas_columnas){
	ReservarMemoria(nuevas_filas, nuevas_columnas);

	filas = nuevas_filas;
	columnas = nuevas_columnas;
	
}

Matriz2D::Matriz2D(const int nuevas_filas, const int nuevas_columnas,
                   const TipoBase valor_inicial){
	ReservarMemoria(nuevas_filas, nuevas_columnas);

	filas = nuevas_filas;
	columnas = nuevas_columnas;
	
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

	for (int i = 0; i < filas; i++){
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
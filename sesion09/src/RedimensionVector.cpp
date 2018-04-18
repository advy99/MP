#include "RedimensionVector.h"

Vector Redimensiona (Vector p, TipoRedimension tipo, int & cap){
	
	const int TAM_BLOQUE = 10;
	int tam_redimensionado;

	//Ajusta el tamanio del nuevo vector segun el tipo de redimension
	if (tipo == TipoRedimension::DeUnoEnUno){
		tam_redimensionado = cap + 1;
		
	}else if (tipo == TipoRedimension::EnBloques){
		tam_redimensionado = cap + TAM_BLOQUE;

	}else if (tipo == TipoRedimension::Duplicando){
		tam_redimensionado = 2 * cap;
	}

	//Declara un nuevo vector con el nuevo tamaño;
	Vector nuevo_vector = new TipoBase [tam_redimensionado];

	//Copia el contenido del antiguo vector en el nuevo
	for (int i = 0; i < cap; i++){
		nuevo_vector[i] = p[i];
	}
	//Actualiza la capacidad
	cap = tam_redimensionado;

	//Libera la memoria consumida por el vector anriguo
	delete [] p;

	//Devolvemos la direccion del nuevo vector
	return nuevo_vector;
}
#include "VectorDinamico_ConstructorCopia.h"
#include "TipoBase.h"
#include "RedimensionVector.h"
#include <cstring>

VectorDinamico::VectorDinamico(){
	ReservarMemoria(TAM_INICIAL);
	ocupadas = 0;
	reservadas = TAM_INICIAL;
	tipo_redimension = TipoRedimension::DeUnoEnUno;
}

VectorDinamico::VectorDinamico(const int valor){
	ReservarMemoria(valor);
	ocupadas = 0;
	reservadas = valor;
	tipo_redimension = TipoRedimension::DeUnoEnUno;

}

VectorDinamico::VectorDinamico(const VectorDinamico & otro_vector){
	ocupadas = otro_vector.ocupadas;
	reservadas = otro_vector.reservadas;
	tipo_redimension = TipoRedimension::DeUnoEnUno;


	ReservarMemoria(reservadas);

	CopiarDatos(otro_vector);
}

VectorDinamico::~VectorDinamico(){
	LiberarMemoria();
	ocupadas = 0;
	usadas = 0;
}

void VectorDinamico::ReservarMemoria(const int num_a_reservar){
	vector = new TipoBase [num_a_reservar];
}

void VectorDinamico::CopiarDatos(const VectorDinamico & otro_vector){
	memcpy(vector, otro_vector.vector, ocupadas*sizeof(TipoBase));
}

void VectorDinamico::LiberarMemoria(){
	delete [] vector;
}

bool VectorDinamico::EstaVacio() const{
	return ocupadas == 0;
}

int VectorDinamico::CasillasOcupadas() const{
	return ocupadas;
}

TipoBase VectorDinamico::Valor(const int posicion) const{
	return vector[posicion];
}

void VectorDinamico::NuevoElemento(const TipoBase valor){
	if(ocupadas == reservadas)
		Redimensiona();
	
	vector[ocupadas] = valor;
	ocupadas++;
}

TipoRedimension VectorDinamico::RedimensionUsada() const{
	return tipo_redimension;
}

void VectorDinamico::SetTipoRedimension(const TipoRedimension tipo){
	tipo_redimension = tipo;
}


int VectorDinamico::CasillasReservadas() const{
	return reservadas;
}

void VectorDinamico::AjustarTamanio(){
	Vector nuevo_vector = new TipoBase [ocupadas];
	memcpy(nuevo_vector, vector, ocupadas*sizeof(TipoBase));
	LiberarMemoria();
	vector = nuevo_vector;
	reservadas = ocupadas;

}

void VectorDinamico::Redimensiona(){
	const int TAM_BLOQUE = 10;
	int tam_redimensionado;

	//Ajusta el tamanio del nuevo vector segun el tipo de redimension
	if (tipo_redimension == TipoRedimension::DeUnoEnUno){
		tam_redimensionado = cap + 1;
		
	}else if (tipo_redimension == TipoRedimension::EnBloques){
		tam_redimensionado = cap + TAM_BLOQUE;

	}else if (tipo_redimension == TipoRedimension::Duplicando){
		tam_redimensionado = 2 * cap;
	}

	//Declara un nuevo vector con el nuevo tamaño;
	Vector nuevo_vector = new TipoBase [tam_redimensionado];

	//Copia el contenido del antiguo vector en el nuevo
	memcpy(nuevo_vector, vector, ocupadas*sizeof(TipoBase));
	//Actualiza la capacidad
	cap = tam_redimensionado;

	//Libera la memoria consumida por el vector anriguo
	LiberarMemoria();

	vector = nuevo_vector;
	reservadas = tam_redimensionado;

}
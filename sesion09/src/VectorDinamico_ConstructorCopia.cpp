#include "VectorDinamico_ConstructorCopia.h"
#include "TipoBase.h"
#include "RedimensionVector.h"

VectorDinamico::VectorDinamico(){
	ReservarMemoria(TAM_INICIAL);
	ocupadas = 0;
	reservadas = TAM_INICIAL;
}

VectorDinamico::VectorDinamico(const int valor){
	ReservarMemoria(valor);
	ocupadas = 0;
	reservadas = valor;
}

VectorDinamico::VectorDinamico(const VectorDinamico & otro_vector){
	ocupadas = otro_vector.ocupadas;
	reservadas = otro_vector.reservadas;

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
	memcpy(vector, otro_vector.vector, ocupadas*sizeof(TipoBase);
}

void VectorDinamico::LiberarMemoria(){
	delete [] vector;
}
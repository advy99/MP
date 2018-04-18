#include "VectorDinamico_ConstructorCopia.h"
#include "TipoBase.h"
#include "RedimensionVector.h"

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
	memcpy(vector, otro_vector.vector, ocupadas*sizeof(TipoBase);
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


#ifndef VECTORDINAMICO
#define VECTORDINAMICO

#include "TipoBase.h"
#include "RedimensionVector.h";

class VectorDinamico{
	private:
		static const int TAM_INICIAL = 5;

		Vector vector;
		int ocupadas;
		int reservadas;

	public:

		VectorDinamico();
		VectorDinamico(const int );
		VectorDinamico(const VectorDinamico &);
		~VectorDinamico();

		bool EstaVacio();
		int CasillasOcupadas();
		
		TipoBase Valor(const int );
		void NuevoElemento(const TipoBase);
		
		TipoRedimension RedimensionUsada();
		void SetTipoRedimension();
	
	private:
		int CasillasReservadas();
		void AjustarTamanio();

};


#endif
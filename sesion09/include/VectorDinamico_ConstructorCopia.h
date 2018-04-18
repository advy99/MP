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

		bool EstaVacio() const;
		int CasillasOcupadas() const;
		
		TipoBase Valor(const int ) const;
		void NuevoElemento(const TipoBase);
		
		TipoRedimension RedimensionUsada() const;
		void SetTipoRedimension();
	
	private:
		int CasillasReservadas() const;
		void AjustarTamanio();

		void ReservarMemoria(const int);
		void LiberarMemoria();
		void CopiarDatos(const VectorDinamico &);

};


#endif
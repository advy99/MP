#ifndef VECTORDINAMICO
#define VECTORDINAMICO

#include "TipoBase.h"
#include "RedimensionVector.h"

class VectorDinamico{
	private:
		static const int TAM_INICIAL = 5;

		Vector vector;
		int ocupadas;
		int reservadas;
		TipoRedimension tipo_redimension;

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
		void SetTipoRedimension(const TipoRedimension );
	
	private:
		int CasillasReservadas() const;
		void AjustarTamanio();

		void ReservarMemoria(const int);
		void LiberarMemoria();
		void CopiarDatos(const VectorDinamico &);
		void Redimensiona();

};


#endif
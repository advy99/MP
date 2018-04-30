#ifndef VECTORDINAMICO
#define VECTORDINAMICO

#include "TipoBase.h"

class VectorDinamico{
	private:
		static const int TAM_INICIAL = 5;

		TipoBase * vector;
		int ocupadas;

	public:

		VectorDinamico();
		VectorDinamico(const int );
		VectorDinamico(const VectorDinamico &);
		~VectorDinamico();

		bool EstaVacio() const;
		int CasillasOcupadas() const;
		
		TipoBase Valor(const int ) const;
		void NuevoElemento(const TipoBase);
		
		void SetValor(const int, const TipoBase);

		VectorDinamico operator = (const VectorDinamico & otro);
		VectorDinamico operator = (const TipoBase valor);
		TipoBase & operator [] (const int indice);

		bool operator == (const VectorDinamico & otro);
		bool operator != (const VectorDinamico & otro);

		bool operator >  (const VectorDinamico & otro);
		bool operator >= (const VectorDinamico & otro);
		bool operator <  (const VectorDinamico & otro);
		bool operator <= (const VectorDinamico & otro);

	private:
		void ReservarMemoria(const int);
		void LiberarMemoria();
		void CopiarDatos(const VectorDinamico &);
		void Redimensiona(const int casillas = 0);
		void Inicializar (const int valor);

};


#endif
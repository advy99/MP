#ifndef PILA
#define PILA

#include "TipoBase.h"

class Pila{
	private:
		TipoBase valor;
		Pila * sig;

	public:
		Pila();
		Pila(const Pila &);
		~Pila();

		bool EstaVacia()const;
		void AniadeValor(const TipoBase);
		void SacarValor(const TipoBase);
		TipoBase ValorEnTope()const;
};

typedef Pila * PNodo;

#endif
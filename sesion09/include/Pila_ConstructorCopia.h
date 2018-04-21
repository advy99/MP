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
		TipoBase SacarValor();
		TipoBase ValorEnTope()const;
};

typedef Pila * PNodo;

#endif
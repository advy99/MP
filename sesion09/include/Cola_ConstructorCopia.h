#ifndef COLA
#define COLA

#include "TipoBase.h"

class Cola{
	private:
		TipoBase valor;
		Cola * sig;

	public:
		Cola();
		Cola(const Cola &);
		~Cola();

		bool EstaVacia()const;
		void AniadeValor(const TipoBase);
		TipoBase SacarValor();
		TipoBase ValorEnCabecera()const;
};

typedef Cola * PNodo;

#endif
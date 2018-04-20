#ifndef LISTA
#define LISTA

#include "TipoBase.h"


//El primer nodo lo consideramos nulo, la lista empieza a partir del segundo
//nodo
class Lista{
	private:
		TipoBase valor;
		Lista * sig;

	public:
		Lista();
		Lista(const int );
		Lista(const int, const TipoBase);
		Lista(const Lista &);
		~Lista();

		bool EstaVacio() const;
		int NumeroNodos() const;

		void Insertar (const TipoBase , const int );
		void Borrar (const int );
		void AniadirValor (const TipoBase );

		TipoBase LeerValor (const int ) const;
		void ModificarValor (const int , const TipoBase );

	private:

		void Inicializar(const TipoBase);

};

typedef Lista * PNodo;
typedef Lista * Nodo;


#endif
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**                                                         **/
/*************************************************************/

#ifndef CONJUNTO
#define CONJUNTO

#include "TipoBase.h"

struct TipoNodo{
	TipoBase valor;
	TipoNodo * siguiente;
};

typedef TipoNodo * PNodo;

class Conjunto{
	private:
		int num_elementos;
		TipoNodo * primero;


	public:
		Conjunto();
		Conjunto(const TipoBase valor);
		Conjunto(const Conjunto & otro);
		~Conjunto();

		bool EstaVacio() const;

		//Añade un elemento si no esta en el conjunto
		//Los añade de forma ordenada
		void Aniadir (const TipoBase valor);

		void Eliminar(const TipoBase valor);

		//Busca un elemento en el conjunto, devuelve la posicion
		// Si no lo encuentra devuelve -1
		int BuscarElemento(const TipoBase valor) const;

		//Numero de elementos
		int NumElementos() const;

		bool PerteneceAlConjunto(const TipoBase valor) const;

		Conjunto & operator = (const Conjunto & otro);

		//Sabemos que los elementos estan ordenados
		bool operator == (const Conjunto & otro) const;
		bool operator != (const Conjunto & otro) const;

		friend Conjunto operator + (const Conjunto & este, const Conjunto & otro);
		friend Conjunto operator + (const Conjunto & este, const TipoBase valor);
		friend Conjunto operator + (const TipoBase valor, const Conjunto & este);

	private:
		
		void ReservarMemoria(const int num_reservas);
		void LiberarMemoria();

		void CopiarDatos(const Conjunto & otro);

};


#endif
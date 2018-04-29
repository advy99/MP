

#ifndef LISTA_CONSTRUCTOR_COPIA
#define LISTA_CONSTRUCTOR_COPIA


#include "TipoBase.h"

struct TipoNodo{
	TipoBase info;  
	TipoNodo * sig;	  
};

class Lista {
	private:

		TipoNodo * primero;
		int tamanio;		

		// PRE: tamanio >= 0

	public:

		Lista ();
		Lista (int tam);
		Lista (int tam, TipoBase valor);

		
		Lista (const Lista & otro);

	   ~Lista (void);

		
		void Inicializar (const TipoBase valor=0);

		/***********************************************************************/
	    // Consulta si la lista esta vacia
		bool EstaVacia () const;

		int  Tamanio () const;
		
		int Buscar (const TipoBase valor) const;

		
		TipoBase LeerValor (const int pos) const;

		
		void ModificarValor (const TipoBase valor, const int pos);
	  
		void AniadirValor (const TipoBase valor);

		void EliminarValor (const TipoBase valor);

		
		void Insertar (const TipoBase TipoBase,const int pos_insertar);

		
		void Borrar (const int pos_borrar);


		//Operadores

		Lista & operator = (const Lista & otra);
		Lista & operator = (const TipoBase valor);
		TipoBase & operator [] (const int pos);

		Lista & operator += (const TipoBase valor);
		Lista & operator -= (const TipoBase valor);

		friend Lista operator + (const Lista & l1, const Lista & l2);
		friend Lista operator + (const Lista & l, const TipoBase valor);
		friend Lista operator + (const TipoBase valor, const Lista & l);

		friend Lista operator - (const Lista & l1, const Lista & l2);
		friend Lista operator - (const Lista & l, const TipoBase valor);
		friend Lista operator - (const TipoBase valor, const Lista & l);

		bool operator == (const Lista & l);
		bool operator != (const Lista & l);

		bool operator >  (const Lista & l);
		bool operator >= (const Lista & l);
		bool operator <  (const Lista & l);
		bool operator <= (const Lista & l);


	private:

		void ReservarMemoria (const int num_elementos);
		void LiberarMemoria (); 

	    // Copiar datos desde otro objeto de la clase
		void CopiarDatos (const Lista & otro);

};


// Muestra el contenido de una lista 
void PintaLista (const Lista & l, const char * const msg);

/***************************************************************************/
/***************************************************************************/

#endif


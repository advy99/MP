/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 11 - Pila - Operadores                          **/
/**                                                         **/
/*************************************************************/


#ifndef PILA
#define PILA


#include "TipoBase.h"

struct TipoNodo{
	TipoBase info;  
	TipoNodo * sig;	  
};

class Pila {
	private:

		TipoNodo * primero;
		int tamanio;		

		// PRE: tamanio >= 0

	public:

		Pila ();
		Pila (int tam, TipoBase valor);

		
		Pila (const Pila & otro);

	   ~Pila (void);

		
		void Inicializar (const TipoBase valor=0);

		/***********************************************************************/
	    // Consulta si la Pila esta vacia
		bool EstaVacia () const;

		int  Tamanio () const;
		
		int Buscar (const TipoBase valor) const;

		
		TipoBase LeerValor (const int pos) const;

		
		
		
		void Insertar (const TipoBase TipoBase,const int pos_insertar);

		
		void Borrar (const int pos_borrar);


		//Operadores

		Pila & operator = (const Pila & otra);
		Pila & operator = (const TipoBase valor);
		TipoBase & operator [] (const int pos);

		Pila & operator += (const TipoBase valor);
		Pila & operator -= (const TipoBase valor);

		friend Pila operator + (const Pila & l1, const Pila & l2);
		friend Pila operator + (const Pila & l, const TipoBase valor);
		friend Pila operator + (const TipoBase valor, const Pila & l);

		friend Pila operator - (const Pila & l1, const Pila & l2);
		friend Pila operator - (const Pila & l, const TipoBase valor);
		friend Pila operator - (const TipoBase valor, const Pila & l);

		bool operator == (const Pila & l);
		bool operator != (const Pila & l);

		bool operator >  (const Pila & l);
		bool operator >= (const Pila & l);
		bool operator <  (const Pila & l);
		bool operator <= (const Pila & l);


	private:

		void ReservarMemoria (const int num_elementos);
		void LiberarMemoria (); 

	    // Copiar datos desde otro objeto de la clase
		void CopiarDatos (const Pila & otro);

		void ModificarValor (const TipoBase valor, const int pos);
	  
		void AniadirValor (const TipoBase valor);

		void EliminarValor (const TipoBase valor);


};


/***************************************************************************/
/***************************************************************************/

#endif


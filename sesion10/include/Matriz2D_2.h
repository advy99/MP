/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 3 - Matrices - Operadores        **/
/**                                                         **/
/*************************************************************/

#ifndef MATRIZ2D_2
#define MATRIZ2D_2

#include "TipoBase.h"

class Matriz2D_2{
	private:
		TipoBase ** datos;
		int filas;
		int columnas;

	public:

		//Constructores y destructor
		Matriz2D_2();
		Matriz2D_2(const int);
		Matriz2D_2(const int, const int);
		Matriz2D_2(const int, const int, const TipoBase);
		Matriz2D_2(const Matriz2D_2 &);
		~Matriz2D_2();


		//Operadores
		Matriz2D_2 & operator = (const Matriz2D_2 &);
		Matriz2D_2 & operator = (const TipoBase);
		TipoBase & operator () (const int, const int) const; 
		Matriz2D_2 operator + () const;
		Matriz2D_2 operator - ();

		friend Matriz2D_2 operator + (const Matriz2D_2 &, const Matriz2D_2 &);
		friend Matriz2D_2 operator + (const Matriz2D_2 &, const TipoBase);
		friend Matriz2D_2 operator + (const TipoBase, const Matriz2D_2 &);

		friend Matriz2D_2 operator - (const Matriz2D_2 &, const Matriz2D_2 &);
		friend Matriz2D_2 operator - (const Matriz2D_2 &, const TipoBase);
		friend Matriz2D_2 operator - (const TipoBase, const Matriz2D_2 &);


		Matriz2D_2 & operator += (const TipoBase);
		Matriz2D_2 & operator -= (const TipoBase);

		bool operator == (const Matriz2D_2 &) const;
		bool operator != (const Matriz2D_2 &) const;


		//Metodos

		bool EstaVacia() const;
		void ModificarValor (const int ,const int ,const TipoBase );
		TipoBase LeerValor (const int ,const int ) const;
		void CambiarTamanio(const int, const int);
		int Filas() const;
		int Columnas() const;
		void RellenarAleatorios(const int, const int);

	private:
		void Inicializar(const TipoBase);
		void LiberarMemoria();
		void ReservarMemoria(const int, const int);
		void CopiarDatos(const Matriz2D_2 &);

};


void PintaMatriz (const Matriz2D_2 m, const char * const msg);


#endif
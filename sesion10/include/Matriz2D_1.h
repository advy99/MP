/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 2 - Matrices - Operadores        **/
/**                                                         **/
/*************************************************************/

#ifndef MATRIZ2D_1
#define MATRIZ2D_1

#include "TipoBase.h"

class Matriz2D{
	private:
		TipoBase ** datos;
		int filas;
		int columnas;

	public:

		//Constructores y destructor
		Matriz2D();
		Matriz2D(const int);
		Matriz2D(const int, const int);
		Matriz2D(const int, const int, const TipoBase);
		Matriz2D(const Matriz2D &);
		~Matriz2D();


		//Operadores
		Matriz2D & operator = (const Matriz2D &);
		Matriz2D & operator = (const TipoBase);
		TipoBase & operator () (const int, const int) const; 
		Matriz2D operator + () const;
		Matriz2D operator - ();

		friend Matriz2D operator + (const Matriz2D &, const Matriz2D &);
		friend Matriz2D operator + (const Matriz2D &, const TipoBase);
		friend Matriz2D operator + (const TipoBase, const Matriz2D &);

		friend Matriz2D operator - (const Matriz2D &, const Matriz2D &);
		friend Matriz2D operator - (const Matriz2D &, const TipoBase);
		friend Matriz2D operator - (const TipoBase, const Matriz2D &);


		Matriz2D & operator += (const TipoBase);
		Matriz2D & operator -= (const TipoBase);

		bool operator == (const Matriz2D &) const;
		bool operator != (const Matriz2D &) const;


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
		void CopiarDatos(const Matriz2D &);

};


void PintaMatriz (const Matriz2D m, const char * const msg);


#endif
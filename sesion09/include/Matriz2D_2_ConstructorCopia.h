#ifndef MATRIZ2D_2
#define MATRIZ2D_2

#include "TipoBase.h"

class Matriz2D_2{
	private:
		Matriz datos;
		int filas;
		int columnas;

	public:
		Matriz2D_2();
		Matriz2D_2(const int);
		Matriz2D_2(const int, const int);
		Matriz2D_2(const int, const int, const TipoBase);
		Matriz2D_2(const Matriz2D_2 &);
		~Matriz2D_2();

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



#endif
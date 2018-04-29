/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 9 - PoliLinea                    **/
/**                                                         **/
/*************************************************************/

#ifndef POLILINEA
#define POLILINEA

class Punto{
	private:
		int x;
		int y;

	public:
		Punto();
		Punto(const int x, const int y);

		int X() const;
		int Y() const;

		void MoverX(const int nueva_x);
		void MoverY(const int nueva_y);
		void MoverPunto(const int nueva_x, const int nueva_y);

		bool operator == (const Punto & otro);
		bool operator != (const Punto & otro);

};


class PoliLinea{
	private:
		Punto * p;
		int num;

	public:
		PoliLinea();
		PoliLinea( const PoliLinea & otra );
		~PoliLinea();

		void AniadirPunto(const Punto nuevo_punto);
		void EliminarPunto (const int posicion);
		int NumPuntos () const;

		PoliLinea & operator = (const PoliLinea & otra);
		Punto & operator [] (const int pos) const;
		
		bool operator == (const PoliLinea & otra) const ;
		bool operator != (const PoliLinea & otra) const;

		friend PoliLinea operator + (const PoliLinea & poli_linea,
		                             const Punto & punto);

		friend PoliLinea operator + (const Punto & punto,
		                             const PoliLinea & poli_linea);

	private:
		void ReservarMemoria (const int num_puntos);
		void LiberarMemoria();
		void CopiarDatos(const PoliLinea & otra);
		void Redimensiona(const int nuevo_tam);
};


#endif
/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**                                                         **/
/*************************************************************/



#ifndef RUTA
#define RUTA

#include <iostream>

using namespace std;

struct Localizacion{
	double longitud, latitud, altura;
};

class Ruta{
	private:
		Localizacion * locs;
		int n;


	public:
		Ruta();
		Ruta(const Ruta & otra);
		Ruta(const Localizacion & loc);

		~Ruta();

		bool LeerRuta(const char * fichero);
		bool EscribirRuta(const char * fichero);
		


		friend Ruta operator + (const Ruta & ruta,const Ruta & otra);
		friend Ruta operator + (const Ruta & ruta, const Localizacion & loc);
		friend Ruta operator + (const Localizacion & loc, const Ruta & ruta);

		friend ostream & operator << (ostream & out, const Ruta & ruta);
		friend istream & operator >> (istream & in, Ruta & ruta);

	private:
		void ReservarMemoria(const int valor);
		void LiberarMemoria();
		void CopiarDatos(const Ruta & otra);

};


double Distancia(const Localizacion & l1, const Localizacion & l2);


#endif
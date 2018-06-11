/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**                                                         **/
/*************************************************************/



#ifndef REDCIUDADES
#define REDCIUDADES

#include <iostream>
using namespace std;

const int TAM_NOMBRE = 50;

struct InfoCiudad{
	char * nombre;
	int poblacion;
};


class RedCiudades{
	private:
		int num_ciudades;
		InfoCiudad * info;
		double ** distancia;

	public:
		RedCiudades();
		RedCiudades(const RedCiudades & otra);

		RedCiudades(const char * fichero);

		~RedCiudades();

		bool EstaVacia() const;

		double Distancia(const int c1, const int c2) const;

		char * NombreCiudad(const int c1) const;

		int PoblacionCiudad(const int c1) const;

		int NumCiudades() const;

		void LeerRedCiudades(const char * fichero);
		void EscribirRedCiudades(const char * fichero) const;

		int CiudadMejorConectada() const;
		int MejorEscalaEntre(const int c1, const int c2) const;

		RedCiudades & operator = (const RedCiudades & otra);

		friend istream & operator >> (istream & in, RedCiudades & red);
		friend ostream & operator << (ostream & out, const RedCiudades & red);


	private:
		void ReservarMemoria(const int num_ciudades);
		void LiberarMemoria();
		void CopiarDatos(const RedCiudades & otra);
		void InicializarDistancia(const int valor);
};


#endif
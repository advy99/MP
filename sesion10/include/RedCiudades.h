#ifndef REDCIUDADES
#define REDCIUDADES

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
		RedCiudades(const int num);
		RedCiudades(const RedCiudades & otra);
		~RedCiudades();
		
		bool EstaVacia() const;
		int NumCiudades() const;
		double Distancia(const int c1, const int c2) const;
		char * NombreCiudad(const int ciudad) const;
		int PoblacionCiudad(const int ciudad) const;
		void SetNombreCiudad(const int ciudad, const char * nombre);
		void SetPoblacionCiudad(const int ciudad, const int p);
		void SetDistancia(const int c1, const int c2, const double d);

		int CiudadMejorConectada() const;
		int MejorEscalaEntre(const int c1, const int c2) const ;

		RedCiudades & operator = (const RedCiudades & otra);

	private:
		void LiberarMemoria();
		void ReservarMemoria(const int n);
		void CopiarDatos(const RedCiudades & otra);
};


void LeeRedCiudades(RedCiudades & red);
void MejoresEscalas(const RedCiudades & red);


#endif
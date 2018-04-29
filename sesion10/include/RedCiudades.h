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
		RedCiudades(const RedCiudades & otra);
		~RedCiudades();
		
		void EstaVacia() const;
		int NumCiudades() const;
		double Distancia(const int c1, const int c2) const;
		char * NombreCiudad(const int ciudad) const;
		int PoblacionCiudad(const int ciudad) const;

		int CiudadMejorConectada() const;
		int MejorEscalaEntre(const int c1, const int c2) const ;

		RedCiudades & operator = (const RedCiudades & otra);

	private:
		void LiberarMemoria();
		void ReservarMemoria();
		void CopiarDatos();
};

#endif
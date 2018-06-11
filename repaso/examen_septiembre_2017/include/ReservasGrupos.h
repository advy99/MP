/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**                                                         **/
/*************************************************************/


#ifndef RESERVASGRUPOS
#define RESERVASGRUPOS

#include "GrupoTuristas.h"



class ReservasGrupos{
	private:
		GrupoTuristas * grupos;
		int ngrupos;

	public:
		ReservasGupos();
		ReservasGrupos(const ReservasGrupos & otras);

		~ReservasGrupos();

		void Salvar(const char * fichero)const;
		void Cargar(const char * fichero);

		ReservasGrupos & operator = (const ReservasGrupos & otras);

		ReservasGrupos operator + (const ReservasGrupos & otras);

		friend ostream & operator << (ostream & out, const ReservasGrupos & reserva);
		friend istream & operator >> (istream & in, ReservasGrupos & reserva);

	private:
		void ReservarMemoria(const int num);
		void LiberarMemoria();
		void CopiarDatos(const ReservasGrupos & otras);
};

#endif
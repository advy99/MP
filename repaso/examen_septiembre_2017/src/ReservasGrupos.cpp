/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**                                                         **/
/*************************************************************/

#include "ReservasGrupos.h"
#include <cstring>

ReservasGrupos :: ReservasGrupos ()
	:grupos(0), ngrupos(0)
{
}

ReservasGrupos :: ReservasGrupos(const ReservasGrupos & otras)
	:ngrupos(otras.ngrupos)
{
	ReservarMemoria(ngrupos);

	CopiarDatos(otras);

}

ReservasGrupos :: ~ReservasGrupos(){
	LiberarMemoria();

	ngrupos = 0;
}


void Salvar(const char * fichero) const{

	ofstream fo;

	fo.open(fichero);

	if (!fo.fail()){
		fo << "RESERVASGRUPOS-ALHAMBRA" << endl;
		fo << (*this);

		fo.close();
	}
}

void Cargar(const char * fichero){
	const char * PALABRA_MAGICA = "RESERVASGRUPOS-ALHAMBRA";

	char cadena [TAM_CAD];

	ifstream fi;

	fi.open (fichero);

	if (!fi.fail()){
		fi >> cadena;

		if (!stcmp(cadena, PALABRA_MAGICA)){
			fi >> (*this);
		}
	}


}


ReservasGrupos & operator = (const ReservasGrupos & otra){
	if (this != &otra){
		LiberarMemoria();

		ReservarMemoria(otra.ngrupos);

		CopiarDatos(otra);
	}

	return (*this);
}

ReservasGrupos operator + (const ReservasGrupos & otras){
	int tam_total = ngrupos + otras.ngrupos;
	int eliminados = 0; 
	int contador;
	bool util[tam_total] = {1};

	GrupoTuristas * todos = new GrupoTuristas [tam_total];
	
	for (int i = 0; i < ngrupos; i++){
		todos[i] = grupos[i];
	}

	for (int i = ngrupos; i < tam_total; i++){
		todos[i] = otras.grupos[i - ngrupos];
	}

	for (int i = 0; i < tam_total - 1; i++){
		for (int j = i + 1; j < tam_total; j++){
			if (todos[i].hora == todos[j].hora && util[j]){
				todos[i] = todos[i] + todos[j];
				util[j] = false;
				eliminados++;
			}
		}
	}

	GrupoTuristas * seleccionados = new GrupoTuristas [tam_total- eliminados];

	for (int i = 0; i < tam_total; i++){
		if(util[i]){
			seleccionados[cont] = todos[i];
			cont++;
		}
	}

	ReservasGrupos final;

	final.ReservarMemoria(cont);

	memcpy(final.grupos, seleccionados, cont * sizeof(GrupoTuristas));

	return final;

}


ostream & operator << (ostream & out, const ReservasGrupos & reserva){
	out << reserva.ngrupos << endl;

	for (int i = 0; i < reserva.ngrupos; i++){
		out << reserva.grupos[i].nturistas << endl;
		for (int j = 0; j < reserva.grupos[i].nturistas; j++ ){
			out << reserva.grupos[i].turistas[j].id << " "
			    << reserva.grupos[i].turistas[j].nombre << " "
				 << reserva.grupos[i].turistas[j].nacionalidad << endl;
		}

		out << reserva.grupos[i].hora.hh << " " << reserva.grupos[i].hora.mm << endl;

	}

	return out;
	
}

istream & operator >> (istream & in, ReservasGrupos & reserva ){
	in >> reserva.ngrupos;

	for (int i = 0; i < reserva.ngrupos; i++){
		in >> reserva.grupos[i].nturistas;
		for (int j = 0; j < reserva.grupos[i].nturistas; j++ ){
			in >> reserva.grupos[i].turistas[j].id;
			in >> reserva.grupos[i].turistas[j].nombre;
			in >> reserva.grupos[i].turistas[j].nacionalidad;
		}

		in >> reserva.grupos[i].hora.hh;
		in >> reserva.grupos[i].hora.mm;

	}

	return (in);
}



// Metodos privados

void ReservasGrupos :: ReservarMemoria(const int valor){
	ngrupos = valor;

	grupos = new GrupoTuristas [ngrupos];
}

void ReservasGrupos :: LiberarMemoria(){
	if (grupos){
		delete [] grupos;

		grupos = 0;
	}

	ngrupos = 0;
}

void ReservasGrupos :: CopiarDatos(const ReservasGrupos & otra){
	ngrupos = otra.ngrupos;

	memcpy(grupos, otra.grupos, otra.ngrupos*sizeof(GrupoTuristas) );
}
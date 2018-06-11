/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**                                                         **/
/*************************************************************/

#include "Ruta.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

Ruta :: Ruta()
	:n(0),locs(0)
{

}

Ruta :: Ruta (const Localizacion & loc)
	:n(1)
{
	ReservarMemoria(n);

	locs[0].longitud = loc.longitud;
	locs[0].latitud = loc.latitud;
	locs[0].altura = loc.altura;
}

Ruta :: Ruta (const Ruta & otra)
	:n(otra.n)
{
	ReservarMemoria(n);

	CopiarDatos (otra);
}

Ruta :: ~Ruta(){

	LiberarMemoria();
	
}

bool Ruta :: LeerRuta(const char * fichero){

	bool exito = true;

	ifstream fi;

	fi.open (fichero);

	if (!fi.fail()){

		const int TAM_CAD = 100;
		const char * PALABRA_MAGICA = "RUTA-MP";
		char palabra[TAM_CAD];

		fi >> palabra;

		if (!strcmp(palabra, PALABRA_MAGICA)){
			fi >> (*this);
		}
		else{
			exito = false;
		}
	
	}
	else{
		exito = false;
	}


	return exito;

}

bool Ruta :: EscribirRuta(const char * fichero){
	bool exito = true;

	ofstream fo;

	fo.open(fichero);

	if (!fo.fail()){
		fo << "RUTA-MP" << endl;
		fo << (*this);
	}
	else{
		exito = false;
	}

	return exito;
}

Ruta operator + (const Ruta & una, const Ruta & otra){
	Ruta final;

	int tam_final = una.n + otra.n;

	final.ReservarMemoria(tam_final);

	final.CopiarDatos(una);

	for (int i = una.n; i < tam_final; i++){

		una.locs[i].longitud = otra.locs[i-una.n].longitud;
		una.locs[i].latitud = otra.locs[i-una.n].latitud;
		una.locs[i].altura = otra.locs[i-una.n].altura;
		//memcpy(final.locs[i], otra.locs[i - una.n], sizeof(Localizacion));
	}

	return final;
}

Ruta operator + (const Ruta & ruta, const Localizacion & loc){
	Ruta otra(loc);

	return (ruta+otra);

}

Ruta operator + (const Localizacion & loc, const Ruta & ruta){
	Ruta otra (loc);

	return (otra+ruta);
}


ostream & operator << (ostream & out, const Ruta & ruta){
	out << ruta.n << endl;
	
	for (int i = 0; i < ruta.n; i++){
		out << ruta.locs[i].longitud << " " << ruta.locs[i].latitud << " "
		    << ruta.locs[i].altura;
	}

	return (out);
}

istream & operator >> (istream & in, Ruta & ruta){
	ruta.LiberarMemoria();

	in >> ruta.n;

	ruta.ReservarMemoria(ruta.n);

	int contador = 0;

	double longitud, latitud, altura;

	while (in >> ruta.locs[contador].longitud){
		in >> ruta.locs[contador].latitud;
		in >> ruta.locs[contador].altura;

		contador++;
	}

	return in;
}





void Ruta :: ReservarMemoria(const int valor){
	locs = new Localizacion [valor];

}


void Ruta :: LiberarMemoria(){
	if(locs)
		delete [] locs;

	n = 0;
}

void Ruta :: CopiarDatos (const Ruta & otra){

	n = otra.n;
	memcpy(locs, otra.locs, n*sizeof(Localizacion));
}

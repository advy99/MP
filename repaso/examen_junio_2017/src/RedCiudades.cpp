/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**                                                         **/
/*************************************************************/


#include "RedCiudades.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;


//METODOS PUBLICOS

RedCiudades :: RedCiudades()
	:num_ciudades(0), info(0), distancia(0)
{}


RedCiudades :: RedCiudades(const RedCiudades & otra){
	ReservarMemoria(otra.num_ciudades);

	CopiarDatos(otra);
}

RedCiudades :: RedCiudades(const char * fichero)
	:num_ciudades(0), info(0), distancia(0)
{
	ifstream fi;

	fi.open(fichero);

	if(!fi.fail()){
		const char * PALABRA_MAGICA = "RED";
		char primera_linea[TAM_NOMBRE];

		fi.getline(primera_linea,TAM_NOMBRE);

		if (!strcmp(PALABRA_MAGICA, primera_linea))
			fi >> (*this);

	}
	else{
		cout << "\nAVISO: No se ha podido leer " << fichero << endl;
		cout << "Se ha proporcionado una red vacia en su lugar." << endl;
	}


}


RedCiudades :: ~RedCiudades(){
	LiberarMemoria();
}


bool RedCiudades :: EstaVacia() const{
	return (num_ciudades == 0);
}

int RedCiudades :: NumCiudades() const{
	return num_ciudades;
}

double RedCiudades :: Distancia(const int c1, const int c2)const{
	return distancia[c1][c2];
}

char * RedCiudades :: NombreCiudad(const int c1) const{
	return (info[c1].nombre);
}

int RedCiudades :: PoblacionCiudad(const int c1) const{
	return (info[c1].poblacion);
}

int RedCiudades :: CiudadMejorConectada() const{
	int mejor_conexion;
	int num_ceros_mejor = num_ciudades;
	int num_ceros;

	for (int i = 1; i <= num_ciudades; i++){
		for (int j = i + 1; i <= num_ciudades; i++){
			if(distancia[i][j] == 0) num_ceros++;
		}

		if (num_ceros < num_ceros_mejor){
			mejor_conexion = i;
			num_ceros_mejor = num_ceros;
		}
	}

	return mejor_conexion;
}

int RedCiudades :: MejorEscalaEntre(const int c1, const int c2) const{
	int mejor_escala = -1;
	double distancia_mejor_ruta = INFINITY;
	double distancia_ruta = distancia_mejor_ruta;

	if (distancia[c1][c2] == 0){
		for (int i = 1; i <= num_ciudades; i++){
			if (distancia[c1][i] != 0 && distancia[i][c2] != 0){
				distancia_ruta = distancia[c1][i] + distancia[i][c2];
			}
			if (distancia_ruta < distancia_mejor_ruta){
				mejor_escala = i;
				distancia_mejor_ruta = distancia_ruta;
			}
		}
	}

	return mejor_escala;
}


void RedCiudades :: LeerRedCiudades(const char * fichero){
	LiberarMemoria();

	RedCiudades temporal(fichero);

	(*this) = temporal;
}

void RedCiudades :: EscribirRedCiudades(const char * fichero)const{
	
	ofstream fo;
	ifstream fi;

	fo.open(fichero);

	if (!fo.fail()){
		fo << "RED" << endl;
		fo << (*this);
		fo.close();
	}
	else{
		cerr << "ERROR: No se pudo crear " << fichero << endl; 
	}
}



RedCiudades & RedCiudades :: operator = (const RedCiudades & otra){
	if (this != &otra){
		LiberarMemoria();

		ReservarMemoria(otra.num_ciudades);

		CopiarDatos(otra);
	}

	return (*this);
}


ostream & operator << (ostream & out, const RedCiudades & red){

	out << red.NumCiudades() << endl;

	for (int i = 1; i <= red.NumCiudades(); i++){
		out << i << " " << red.NombreCiudad(i) << " " << red.PoblacionCiudad(i) << endl;
	}

	for (int i = 1; i <= red.NumCiudades(); i++){
		for (int j = i + 1; j <= red.NumCiudades(); j++){
			if (red.Distancia(i,j) != 0)
				out << i << " " << j << " " << red.Distancia(i,j) << endl;
		}
	}

	return (out);
}

istream & operator >> (istream & in, RedCiudades & red){

	red.LiberarMemoria();

	in >> red.num_ciudades;

	red.ReservarMemoria(red.num_ciudades);

	red.InicializarDistancia(0);


	int indice, c1, c2;
	istringstream iss;
	string cadena;

	for (int i = 1; i <= red.num_ciudades; i++){

		in >> indice;

		in >> red.info[indice].nombre;

		in >> red.info[indice].poblacion;

	}



	while (in >> c1){


		in >> c2;


		in >> red.distancia[c1][c2];

	
		red.distancia[c2][c1] = red.distancia[c1][c2];

	}



	return (in);
}





// METODOS PRIVADOS

void RedCiudades :: ReservarMemoria(const int n){
	num_ciudades = n;
	
	info = new InfoCiudad [num_ciudades+1];

	for (int i = 1; i <= num_ciudades; i++){
		info[i].nombre = new char [TAM_NOMBRE];
	}

	distancia = new double * [num_ciudades+1];

	for (int i = 1; i <= num_ciudades; i++){
		distancia[i] = new double [num_ciudades+1];
		for(int  c2 = 0; c2 <= num_ciudades; c2++) 
			distancia[i][c2] = 0;
	}
}

void RedCiudades :: LiberarMemoria(){

	if (info){
		for (int i = 1; i <= num_ciudades; i++)
			delete [] info[i].nombre;

		delete info;

		info = 0;
	}

	if (distancia){
		for(int i = 0; i <= num_ciudades; i++){
			delete [] distancia[i];
		}

		delete [] distancia;

		distancia = 0;
	}

	num_ciudades = 0;
}

void RedCiudades :: InicializarDistancia(const int valor){
	for (int i = 1; i <= num_ciudades; i++){
		for (int j = 1; j <= num_ciudades; j++){
			distancia[i][j] = valor;
		}
	}
}

void RedCiudades :: CopiarDatos(const RedCiudades & otra){

	num_ciudades = otra.num_ciudades;

	for (int i = 0; i <= num_ciudades; i++){
		info[i].nombre = otra.info[i].nombre;
		info[i].poblacion = otra.info[i].poblacion;
	}

	for (int i = 0; i <= num_ciudades; i++){
		memcpy(distancia[i], otra.distancia[i],num_ciudades * sizeof(double));
	}


}
#include "ColeccionPuntos2D.h"
#include "Punto2D.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "Util.h"

ColeccionPuntos2D :: ColeccionPuntos2D (void) 
                   : total_utilizados(0), vector_privado (0) {}


ColeccionPuntos2D :: ColeccionPuntos2D (Punto2D nuevo_punto) 
                   :total_utilizados(1)
{ 
	ReservarMemoria(total_utilizados);
	Aniade (nuevo_punto);
}


ColeccionPuntos2D :: ColeccionPuntos2D (const char * nombre){
	total_utilizados = 0;
	const string INICIO = "PUNTOS";
	ifstream fi;

	//Si existe el fichero, lo abrimos
	if (ExisteFichero(nombre)){
		fi.open(nombre);

		string linea;

		//Leemos la primera linea
		getline(fi, linea);

		//Comprobamos que es correcta
		if (linea == INICIO){
			//Leemos la segunda linea
			getline(fi, linea);


			//Saltamos las lineas de comentarios
			while (!fi.eof() && linea[0] == '#')
				getline(fi, linea);


			while (!fi.eof()){
				istringstream iss;
				iss.str(linea);
				double x, y;

				//Si es capaz de encontrar un valor, el otro tiene que estar
				//en la linea
				if (iss >> x){
					iss >> y;
					//Creamos un punto a partir de esos valores, y lo añadimos
					Punto2D nuevo_punto(x,y);
					Aniade(nuevo_punto);
				}

				getline(fi, linea);
			}



		}
		//Cerramos el fichero
		fi.close();
	}
	
}


ColeccionPuntos2D :: ~ColeccionPuntos2D() {
	LiberarMemoria();
}



int ColeccionPuntos2D :: NumPuntos () const
{
	return (total_utilizados);
}


void ColeccionPuntos2D :: Aniade (Punto2D nuevo_punto)
{
	Punto2D * copia = vector_privado;



	ReservarMemoria(total_utilizados + 1);

	memcpy(vector_privado, copia, total_utilizados * sizeof(Punto2D) );

	vector_privado[total_utilizados - 1] = nuevo_punto;

}

Punto2D ColeccionPuntos2D :: Elemento (int indice) const
{
	return (vector_privado[indice]);
}


void ColeccionPuntos2D :: ReservarMemoria(const int num){
	vector_privado = new Punto2D [num];
	total_utilizados = num;
}

void ColeccionPuntos2D :: LiberarMemoria(){
	delete [] vector_privado;
	total_utilizados = 0;
}

ColeccionPuntos2D & ColeccionPuntos2D :: operator += (const Punto2D punto){
	Aniade( punto );

	return (*this);
}

Punto2D & ColeccionPuntos2D :: operator [] (const int p){
	return vector_privado[p];
}

Punto2D ColeccionPuntos2D :: operator [] (const int p)const {
	return vector_privado[p];
}


void PintaColeccionPuntos2D(const char * msg,const ColeccionPuntos2D & puntos){
	cout << endl << msg << endl;

	cout << puntos.NumPuntos() << endl ;
	for (int i = 0; i < puntos.NumPuntos(); i++){
		cout << puntos.Elemento(i).ToString() << endl;
	}
}
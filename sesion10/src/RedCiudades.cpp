#include <iostream>
#include "RedCiudades.h"
#include <cstring>
#include <cmath>

using namespace std;

RedCiudades :: RedCiudades()
               :num_ciudades(0),
					 info(0),
					 distancia(0)
{
}

RedCiudades :: RedCiudades(const int num)
               :num_ciudades(num){
	
	ReservarMemoria(num);

}

RedCiudades :: RedCiudades(const RedCiudades & otra)
                :num_ciudades(otra.num_ciudades)
{

	ReservarMemoria(otra.num_ciudades);

	CopiarDatos(otra);

}

RedCiudades :: ~RedCiudades(){
	LiberarMemoria();

	num_ciudades = 0;
}


bool RedCiudades :: EstaVacia() const{
	return (distancia == 0);
}

int RedCiudades :: NumCiudades() const{
	return num_ciudades;
}

double RedCiudades :: Distancia(const int c1, const int c2) const{
	return (distancia[c1][c2]);
}

char * RedCiudades :: NombreCiudad (const int ciudad) const{
	return (info[ciudad].nombre);
} 

int RedCiudades :: PoblacionCiudad (const int ciudad) const{
	return (info[ciudad].poblacion);
}

void RedCiudades :: SetNombreCiudad(const int ciudad, const char * n){
	info[ciudad].nombre = new char [100];

	strcpy(info[ciudad].nombre, n);
}

void RedCiudades :: SetPoblacionCiudad(const int ciudad, const int p){
	info[ciudad].poblacion = p;
}

void RedCiudades :: SetDistancia(const int c1, const int c2, const double d){
	distancia[c1][c2] = d;
}

int RedCiudades :: CiudadMejorConectada () const{
	int mejor_ciudad = 0;
	int num_ceros_mejor = num_ciudades;
	int num_ceros = num_ciudades;

	for (int i = 1; i < num_ciudades; i++){
		for (int j = 0; j < num_ciudades; j++){
			if (distancia == 0)
				num_ceros++;
		}

		if (num_ceros < num_ceros_mejor){
			num_ceros_mejor = num_ceros;
			mejor_ciudad = i;
		}
	}

	return mejor_ciudad;

}
// 0  -- 3
int RedCiudades :: MejorEscalaEntre (const int c1, const int c2) const{
	int mejor_escala = -1;
	double distancia_mejor_viaje = INFINITY;
	double distancia_viaje = INFINITY;


	if (distancia[c1][c2] != 0 || c1 == c2){
		mejor_escala = -1;
	}
	else{
		for (int i = 0; i < num_ciudades; i++){
			distancia_viaje = INFINITY;

			if (distancia[c1][i] != 0 && distancia[i][c2] != 0){
				distancia_viaje = distancia[c1][i] + distancia[i][c2];
			}

			if (distancia_viaje < distancia_mejor_viaje){
				mejor_escala = i;
				distancia_mejor_viaje = distancia_viaje;
			}
		}
	}

	return mejor_escala;
}



RedCiudades & RedCiudades :: operator = (const RedCiudades & otra){
	if (this != &otra){
		LiberarMemoria();

		ReservarMemoria(otra.num_ciudades);

		CopiarDatos(otra);
	}

	return (*this);
}

/******************************************************************************/


void RedCiudades :: LiberarMemoria(){
	if (info){
		delete [] info;
		info = 0;
	}

	if (distancia){

		for (int i = 0; i < num_ciudades; i++){
			delete [] distancia[i];
		}

		delete [] distancia;

		distancia = 0;
	}
}

void RedCiudades :: ReservarMemoria(const int num){
	info = new InfoCiudad [num];

	distancia = new double * [num];

	for (int i = 0; i < num; i++){
		distancia[i] = new double [num];
	}
}

void RedCiudades :: CopiarDatos(const RedCiudades & otra){
	memcpy(info, otra.info, otra.num_ciudades * sizeof(InfoCiudad) );

	for (int i = 0; i < otra.num_ciudades; i++){
		memcpy(distancia[i], otra.distancia[i], num_ciudades * sizeof(double) );
	}
	num_ciudades = otra.num_ciudades;
}




void LeeRedCiudades(RedCiudades & red){
	char nombre[100];
	int poblacion;
	double distancia;

	for (int i = 0; i < red.NumCiudades() ; i++){
		cout << endl;
		cout << "Introduce el nombre de la ciudad " << i << " : ";
		cin.ignore();
		cin.getline(nombre, 100);
		red.SetNombreCiudad(i, nombre );

		cout << "Introduce la poblacion de la ciudad " << i << " : ";
		cin >> poblacion;

		red.SetPoblacionCiudad(i, poblacion);
	}

	for (int i = 0; i < red.NumCiudades() ; i++){
		for (int j = i + 1; j < red.NumCiudades() ; j++){
			cout << "Introduce la distancia de la ciudad " << i << " a la ciudad "
			     << j << " (0 si no estan conectadas) : ";
			cin >> distancia;

			red.SetDistancia(i,j, distancia); 
		}
	}

	for (int i = 0; i < red.NumCiudades(); i++){
		for (int j = 0; j < i; j++){
			distancia = red.Distancia(j,i);
			red.SetDistancia(i,j, distancia); 
		}
	}
	for (int i = 0; i < red.NumCiudades(); i++){
		red.SetDistancia(i,i, 0);
	}


}


void MejoresEscalas(const RedCiudades & red){
	int mejor_escala;

	for (int i = 0; i < red.NumCiudades(); i++){
		cout << endl;
		for (int j = 0; j < red.NumCiudades(); j++){
			mejor_escala = red.MejorEscalaEntre(i,j);

			if (mejor_escala != -1){
				cout << endl;
				cout << "La mejor escala entre " << red.NombreCiudad(i) << " y " 
				     << red.NombreCiudad(j) << " es " 
					  << red.NombreCiudad(mejor_escala) << endl;
			}
			else{
				cout << endl;
				cout << "No hay escalas para las ciudades " << red.NombreCiudad(i)
				     << " y " << red.NombreCiudad(j) << endl;
				
			}
		}
	} 
}
#include "RedCiudades.h"

RedCiudades :: RedCiudades()
               :num_ciudades(0),
					 info(0),
					 distancia(0)
{
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


void RedCiudades :: EstaVacia() const{
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

int RedCiudades :: MejorEscalaEntre (const int c1, const int c2){
	int mejor_escala = -1;
	double distancia_mejor_viaje = INFINITY;
	double distancia_viaje;

	if (distancia[c1][c2] != 0){
		mejor_escala = -1;
	}
	else{
		for (int i = 0; i < num_ciudades; i++){
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

void CopiarDatos(const RedCiudades & otra){
	memcpy(info, otra.info, otra.num_ciudades * sizeof(InfoCiudad) );

	for (int i = 0; i < otra.num_ciudades; i++){
		memcpy(distancia[i], otra.distancia[i], num_ciudades * sizeof(double) );
	}
	num_ciudades = otra.num_ciudades;
}
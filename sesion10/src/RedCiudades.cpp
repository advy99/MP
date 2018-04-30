/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 11 - Clase RedCiudades           **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "RedCiudades.h"
#include <cstring>
#include <cmath>

using namespace std;


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor sin parametros, red vacia                 **/
/**                                                         **/
/*************************************************************/

RedCiudades :: RedCiudades()
               :num_ciudades(0),
					 info(0),
					 distancia(0)
{
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor con un parametro, pide memoria para el    **/
/**  numero de ciudades dado                                **/
/**                                                         **/
/*************************************************************/

RedCiudades :: RedCiudades(const int num)
               :num_ciudades(num){
	
	ReservarMemoria(num);

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Constructor de copia, copia una red de ciudades       **/
/**                                                         **/
/*************************************************************/

RedCiudades :: RedCiudades(const RedCiudades & otra)
                :num_ciudades(otra.num_ciudades)
{

	ReservarMemoria(otra.num_ciudades);

	CopiarDatos(otra);

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Destructor, libera la memoria usada                   **/
/**                                                         **/
/*************************************************************/

RedCiudades :: ~RedCiudades(){
	LiberarMemoria();

	num_ciudades = 0;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Comprueba si la red esta vacia, no hay ciudades       **/
/**                                                         **/
/*************************************************************/


bool RedCiudades :: EstaVacia() const{
	return (distancia == 0);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Devuelve el numero de ciudades                        **/
/**                                                         **/
/*************************************************************/

int RedCiudades :: NumCiudades() const{
	return num_ciudades;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Devuelve la distancia entre c1 y c2                   **/
/**                                                         **/
/*************************************************************/

double RedCiudades :: Distancia(const int c1, const int c2) const{
	return (distancia[c1][c2]);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Devuelve el nombre de la ciudad dada                  **/
/**                                                         **/
/*************************************************************/

char * RedCiudades :: NombreCiudad (const int ciudad) const{
	return (info[ciudad].nombre);
} 

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Devuelve la poblacion de la ciudad dada               **/
/**                                                         **/
/*************************************************************/

int RedCiudades :: PoblacionCiudad (const int ciudad) const{
	return (info[ciudad].poblacion);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Cambia el nombre de una ciudad                        **/
/**                                                         **/
/*************************************************************/

void RedCiudades :: SetNombreCiudad(const int ciudad, const char * n){
	info[ciudad].nombre = new char [100];

	strcpy(info[ciudad].nombre, n);
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Cambia la poblacion de una ciudad                     **/
/**                                                         **/
/*************************************************************/

void RedCiudades :: SetPoblacionCiudad(const int ciudad, const int p){
	info[ciudad].poblacion = p;
}


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Cambia el distancia entre dos ciudades                **/
/**                                                         **/
/*************************************************************/

void RedCiudades :: SetDistancia(const int c1, const int c2, const double d){
	distancia[c1][c2] = d;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Calcula la ciudad mejor conectada                     **/
/**                                                         **/
/*************************************************************/

int RedCiudades :: CiudadMejorConectada () const{
	int mejor_ciudad = 0;
	int num_ceros_mejor = num_ciudades;
	int num_ceros = num_ciudades;

	//Recorremos todas las ciudades, buscando distancias de 0
	for (int i = 1; i < num_ciudades; i++){
		for (int j = 0; j < num_ciudades; j++){
			if (distancia == 0)
				num_ceros++;
		}

		//La ciudad con menos ceros, tiene mas conexiones, luego esta
		//mejor conectada
		if (num_ceros < num_ceros_mejor){
			num_ceros_mejor = num_ceros;
			mejor_ciudad = i;
		}
	}

	return mejor_ciudad;

}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Calcula la mejor escala entre dos ciudades            **/
/**                                                         **/
/*************************************************************/

int RedCiudades :: MejorEscalaEntre (const int c1, const int c2) const{
	int mejor_escala = -1;
	double distancia_mejor_viaje = INFINITY;
	double distancia_viaje = INFINITY;


	//Si la distancia es distinta a 0, no es necesario hacer escalas
	if (distancia[c1][c2] != 0 || c1 == c2){
		mejor_escala = -1;
	}
	else{
		//Comprobamos cada ciudad
		for (int i = 0; i < num_ciudades; i++){
			distancia_viaje = INFINITY;

			//Si hay una ciudad i intermedia, calculamos la distancia de ese viaje
			if (distancia[c1][i] != 0 && distancia[i][c2] != 0){
				distancia_viaje = distancia[c1][i] + distancia[i][c2];
			}

			// Si esa distancia es menor que la del mejor viaje, esa ciudad
			//pasa a ser la nueva mejor escala
			if (distancia_viaje < distancia_mejor_viaje){
				mejor_escala = i;
				distancia_mejor_viaje = distancia_viaje;
			}
		}
	}

	return mejor_escala;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Operador de asignacion                                **/
/**                                                         **/
/*************************************************************/

RedCiudades & RedCiudades :: operator = (const RedCiudades & otra){
	//Evitamos autoasignacion
	if (this != &otra){
		LiberarMemoria();

		ReservarMemoria(otra.num_ciudades);

		CopiarDatos(otra);
	}

	return (*this);
}

/******************************************************************************/
/******************************************************************************/
//   Metodos privados
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Liberamos la memoria usada por info y distancia       **/
/**                                                         **/
/*************************************************************/

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

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Reservamos memoria para num ciudades                  **/
/**                                                         **/
/*************************************************************/

void RedCiudades :: ReservarMemoria(const int num){
	info = new InfoCiudad [num];

	distancia = new double * [num];

	for (int i = 0; i < num; i++){
		distancia[i] = new double [num];
	}
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Copiamos los datos de otra red de ciudades            **/
/**                                                         **/
/*************************************************************/

void RedCiudades :: CopiarDatos(const RedCiudades & otra){
	//Copiamos info
	memcpy(info, otra.info, otra.num_ciudades * sizeof(InfoCiudad) );

	//Copiamos las distancias
	for (int i = 0; i < otra.num_ciudades; i++){
		memcpy(distancia[i], otra.distancia[i], num_ciudades * sizeof(double) );
	}
	num_ciudades = otra.num_ciudades;
}



/******************************************************************************/
/******************************************************************************/
//   Funciones externas
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Leemos los datos de una red de ciudades               **/
/**                                                         **/
/*************************************************************/

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

	// Leemos las distancias, solo la parte superior a la diagonal de la
	//matriz, ya que es simetrica
	for (int i = 0; i < red.NumCiudades() ; i++){
		for (int j = i + 1; j < red.NumCiudades() ; j++){
			cout << "Introduce la distancia de la ciudad " << i << " a la ciudad "
			     << j << " (0 si no estan conectadas) : ";
			cin >> distancia;

			red.SetDistancia(i,j, distancia); 
		}
	}

	//Copiamos la parte superior de la matriz en la parte inferior
	for (int i = 0; i < red.NumCiudades(); i++){
		for (int j = 0; j < i; j++){
			distancia = red.Distancia(j,i);
			red.SetDistancia(i,j, distancia); 
		}
	}

	//Rellenamos la diagonal de 0
	for (int i = 0; i < red.NumCiudades(); i++){
		red.SetDistancia(i,i, 0);
	}


}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Calculamos las mejores escalas de todas las ciudades  **/
/**                                                         **/
/*************************************************************/

void MejoresEscalas(const RedCiudades & red){
	int mejor_escala;

	for (int i = 0; i < red.NumCiudades(); i++){
		cout << endl;
		// Solo es necesario hacerlas de la parte superior de la matriz
		//la parte inferior se repite
		//
		// Ej: La mejor escala entre c1 y c4 es la misma que la mejor escala
		// entre c4 y c1
		for (int j = i; j < red.NumCiudades(); j++){
			//Calculamos mejor escala entre i j
			mejor_escala = red.MejorEscalaEntre(i,j);

			//Si hay escala, la mostramos
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
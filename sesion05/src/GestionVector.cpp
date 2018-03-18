/*************************************************************/
/**																			**/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Makefile sesion 5                                      **/
/**                                                         **/
/*************************************************************/


#include "GestionVector.h"
#include <iostream>

/***************************************************************************/
// CLASE GeneradorAleatorioEnteros
//
//  Ejemplo de uso:
/*
	int menor, mayor;
	......
	
	// Objeto generador de n�meros aleatorios
	GeneradorAleatorioEnteros generador_aleat (menor, mayor);
	
	int valor_generado = generador_aleat.Siguiente();
*/   
   
/***************************************************************************/


#include<cstdlib>
#include<cctype>

#include <random>  
#include <chrono>  


using namespace std;

/////////////////////////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{  
private:
	
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;
   
   /************************************************************************/
   long long Nanosec(){
      return (chrono::high_resolution_clock::now().
              time_since_epoch().count());
   }
   /************************************************************************/ 

public:
	
   /************************************************************************/	
   GeneradorAleatorioEnteros()
      :GeneradorAleatorioEnteros(0, 1){
   }
   
   /************************************************************************/  
   GeneradorAleatorioEnteros(int min, int max) {
      const int A_DESCARTAR = 70000;
      // ACM TOMS Volume 32 Issue 1, March 2006
      
      auto semilla = Nanosec();
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme = uniform_int_distribution<int> (min, max);
   }
   
   /************************************************************************/
   int Siguiente(){
      return (distribucion_uniforme(generador_mersenne));
   }
   /************************************************************************/
};

/////////////////////////////////////////////////////////////////////////////

/******************************************************************************/

/********************************************************/
/**                                                    **/
/**     Muestra un mensaje y a continuacion un vector  **/
/**                                                    **/
/**     Recibe : Un mensaje                            **/
/**              Un vector                             **/
/**              El tamaño util del vector             **/
/**              El numero de filas a separar          **/
/**            el vector, por defecto 0                **/
/**                                                    **/
/********************************************************/

void MostrarVector(char * mensaje, int * vector, const int UTILIZADOS,
                   int filas){

	if (filas == 0)
		filas = UTILIZADOS;

	cout << endl << endl << mensaje << endl;

	for(int i = 0; i < UTILIZADOS; i++){

		if (i % filas == 0)
			cout << endl;

		cout << *(vector + i) << " ";
	}
} 

/******************************************************************************/

/********************************************************/
/**                                                    **/
/**     Rellena el vector de forma aleatoria           **/
/**                                                    **/
/**     Recibe : Un vector                             **/
/**              El tamaño util del vector             **/
/**              El intervalo de numeros validos       **/
/**           para rellenarlo con MIN y MAX            **/
/**                                                    **/
/********************************************************/

void RellenarVectorAleatorios(int * vector, const int UTILIZADOS , 
                              const int MIN , const int MAX){

	GeneradorAleatorioEnteros generador(MIN,MAX);

	int *p_int = vector;

	for (int i = 0; i < UTILIZADOS; i++){
		*p_int = generador.Siguiente();
		p_int++;	
	}

}

/******************************************************************************/

/********************************************************/
/**                                                    **/
/**     Encuentra el maximo y minimo de un vector y    **/
/**   los devuelve por referencia                      **/
/**                                                    **/
/**     Recibe : Un vector                             **/
/**              El intervalo a buscarctor             **/
/**              Dos enteros referenciados             **/
/**                                                    **/
/********************************************************/

void MinMaxVector(int * vector, const int INICIO, const int FIN,
                  int &minimo, int &maximo){
	int *p_int = vector + INICIO ;

	minimo = *p_int;
	maximo = *p_int;

	for (int i = INICIO; i < FIN; i++){
		if (*p_int < minimo)
			minimo = *p_int;
		if (*p_int > maximo)
			maximo = *p_int;
		p_int++;
	}

}

/******************************************************************************/

/********************************************************/
/**                                                    **/
/**     Encuentra la posicion de memoria del mayor     **/
/**   elemento                                         **/
/**                                                    **/
/**     Recibe : Un vector                             **/
/**              El intervalo donde buscar             **/
/**                                                    **/
/********************************************************/
int * PosMayor (int *pv,const int dcha,const int izda){
	int max;
	int min;
	int *p_int = pv;

	MinMaxVector(pv, izda, dcha, min, max);

	while(*p_int != max){
		p_int++;
	}

	return p_int;
}

/******************************************************************************/

/********************************************************/
/**                                                    **/
/**     Ordena un vector usando el metodo de           **/
/**   la burbuja                                       **/
/**                                                    **/
/**     Recibe : Un vector                             **/
/**              El tamaño util del vector             **/
/**                                                    **/
/********************************************************/

void OrdenarVector(int *v, const int UTIL){
	int izda, i;
	bool cambio;
	int * p_int = v;
	int valor_temporal;

	cambio = true;

	for (izda = 0; izda < UTIL && cambio; izda++){

		cambio = false;

		for (i = UTIL-1;  i > izda; i--)

			if (*(p_int+i) < *(p_int + i-1 ) ) {
				
				valor_temporal = *(p_int+i);
				*(p_int+i) = *(p_int + i-1 );
				*(p_int + i-1 ) = valor_temporal;

				cambio = true;
			}
	}
}

/******************************************************************************/

/********************************************************/
/**                                                    **/
/**     Mezcla ordenadamente dos vectores              **/
/**                                                    **/
/**     Recibe : Dos vectores                          **/
/**              El vector final                       **/
/**              El tamaño util de todos los vectore   **/
/**                                                    **/
/**     El tamaño util del resultado se devuelve       **/
/**   por referencia                                   **/
/**                                                    **/
/********************************************************/

void MezclaVectores (int mezcla[], int &total_util_mezcla , int v1[],
                     int util_v1, int v2[], int util_v2){
	int *p_v1 = v1;
	int *p_v2 = v2;
	int *p_mezcla = mezcla;

	total_util_mezcla = util_v1 + util_v2;

	for (int i = 0; i < total_util_mezcla; i++){
		if (*p_v1 < *p_v2){
			*p_mezcla = *p_v1;
			p_v1++;
		}
		else{
			*p_mezcla = *p_v2;
			p_v2++;
		}
		p_mezcla++;
	}
}

/********************************************************************************/

/********************************************************/
/**                                                    **/
/**     Ordena un vector de punteros para que este     **/
/**   apunte ordenadamente a los elementos de          **/
/**    un vector                                       **/
/**                                                    **/
/**     Recibe : Un vector                             **/
/**              Un vector de punteros                 **/
/**              El intervalo a trabajar               **/
/**                                                    **/
/********************************************************/

void Ordena (int *vec, int **ptr, int izda, int dcha){
	
	bool pos_ocupada [dcha-izda] = {false};

	*ptr = vec;
	int *pos_mayor = PosMayor(vec,dcha,izda);
	for (int i = izda; i < dcha; i++){
		*(ptr+i) = pos_mayor;
	}

	int ultima_pos = 0;


	for(int i = izda; i < dcha; i++){

		for(int j = izda; j < dcha; j++){
			if (*(vec+j) < **(ptr+i) && !pos_ocupada[j]){
				*(ptr+i) = vec+j;
				ultima_pos = j;
			}
		}
		pos_ocupada[ultima_pos] = true;



	}
	cout << endl;
	for(int i = 0; i < dcha ; i++){
		cout << pos_ocupada[i];
	}
}
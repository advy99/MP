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





void MostrarVector(char * mensaje, int * vector, const int UTILIZADOS,
                   int filas){

	if (filas == 0)
		filas = UTILIZADOS;
	const int * p_int = vector; 

	cout << endl << mensaje << endl;

	for(int i = 0; i < UTILIZADOS; i++){

		if (i % filas == 0)
			cout << endl;

		cout << *p_int << " ";
		p_int++;
	}
} 



void RellenarVectorAleatorios(int * vector, const int UTILIZADOS , 
                              const int MIN , const int MAX){

	GeneradorAleatorioEnteros generador(MIN,MAX);

	int *p_int = vector;

	for (int i = 0; i < UTILIZADOS; i++){
		*p_int = generador.Siguiente();
		p_int++;	
	}

}

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

int * PosMayor (int *pv, int izda, int dcha){
	int max;
	int min;
	int *p_int = pv;

	MinMaxVector(pv, izda, dcha, min, max);

	while(*p_int != max){
		p_int++;
	}

	return p_int;
}

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
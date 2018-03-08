#include <iostream>

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




int main( void ){
	const int TOPE = 20;
	int v [TOPE];
	GeneradorAleatorioEnteros generador(0,100);
	int *p_inicio, *p_fin;
	int paso_intercambio;

	for (int i = 0, *p = v; i < TOPE; i++){
		*(p+i) = generador.Siguiente();
	}

	p_inicio = v;
	p_fin		= &v[19];

	for (int i = 0, *p = v; i < TOPE; i++){
		cout << *(p+i) << " " ;
	}

	while ( p_inicio < p_fin ){
		if (*p_inicio <= v[0]){
			p_inicio++;
		}
		else if (*p_fin > v[0] ){
			p_fin--;
		}
		else{
			paso_intercambio = *p_inicio;
			*p_inicio = *p_fin;
			*p_fin = paso_intercambio;
			p_inicio = v;
			p_fin		= &v[19];
		}
		
	}

	cout << endl;
	for (int i = 0, *p = v; i < TOPE; i++){
		cout << *(p+i) << " " ;
	}
}
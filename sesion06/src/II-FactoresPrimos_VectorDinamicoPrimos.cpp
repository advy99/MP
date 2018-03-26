/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 6 - Ejercicio 3 - Descomposicion en factores    **/
/**                          primos                         **/
/**                                                         **/
/*************************************************************/

#include <iostream>

using namespace std;

/******************************************************************************/

enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};
int * Redimensiona (int * p, TipoRedimension tipo, int & cap);
int * CalcularPrimosMenoresQue (int , int &);

/******************************************************************************/

int main(int argc, char * argv[]){
	int num_primos;
	int * v = CalcularPrimosMenoresQue (20, num_primos);

	for (int i = 0; i < num_primos; i++){
		cout << v[i] << " ";
	}
}

/******************************************************************************/

int * CalcularPrimosMenoresQue (int numero, int & n_primos){
	numero--;
	int usados = 0;
	int * num = new int [numero];
	int * primos = new int [usados];
	

	for (int i = 0; i < numero; i++){
		num [i] = i + 2;
	}

	for (int i = 0;i < numero; i++){
		if (num [i] != -1){
			for (int j = i; j < numero; j++){
				if (num[j] != -1)
					if (num [j] != num [i] && num[j] % num[i] == 0)
						num [j] = -1;
			}
		}
	}

	for(int i = 0; i < numero; i++){
		if (num[i] != -1){
			primos = Redimensiona (primos, TipoRedimension::DeUnoEnUno, usados);
			primos[usados - 1] = num[i];
		}
	}
	n_primos = usados;

	return primos;
}

/******************************************************************************/

int * Redimensiona (int * p, TipoRedimension tipo, int & cap){
	
	const int TAM_BLOQUE = 10;
	int tam_redimensionado;

	if (tipo == TipoRedimension::DeUnoEnUno){
		tam_redimensionado = cap + 1;
		
	}else if (tipo == TipoRedimension::EnBloques){
		tam_redimensionado = cap + TAM_BLOQUE;

	}else if (tipo == TipoRedimension::Duplicando){
		tam_redimensionado = 2 * cap;
	}

	int * nuevo_vector = new int [tam_redimensionado];

	for (int i = 0; i < cap; i++){
		nuevo_vector[i] = p[i];
	}

	cap = tam_redimensionado;

	delete [] p;

	return nuevo_vector;
}
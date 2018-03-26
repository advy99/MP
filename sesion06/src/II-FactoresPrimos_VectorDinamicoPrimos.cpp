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

struct Vector{
	int * vector;
	int capacidad;
};

/******************************************************************************/

enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};
int * Redimensiona (int * p, TipoRedimension tipo, int & cap);
Vector CalcularPrimosMenoresQue (int );
//Vector DescomposicionPrimos (int, )

/******************************************************************************/

int main(int argc, char * argv[]){

	Vector v = CalcularPrimosMenoresQue (20);

	for (int i = 0; i < v.capacidad; i++){
		cout << v.vector[i] << " ";
	}
}

/******************************************************************************/

Vector CalcularPrimosMenoresQue (int numero){
	numero--;
	int * num = new int [numero];

	Vector vector_primos;
	vector_primos.capacidad = 0;
	vector_primos.vector = new int [vector_primos.capacidad];

	

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
			vector_primos.vector = Redimensiona (vector_primos.vector,
			                                     TipoRedimension::DeUnoEnUno,
															 vector_primos.capacidad);
			vector_primos.vector[vector_primos.capacidad - 1] = num[i];
		}
	}

	delete [] num;

	return vector_primos;
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
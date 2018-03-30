/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 6 - Ejercicio 3 - Descomposicion en factores    **/
/**                          primos                         **/
/**                                                         **/
/**      PRE: El numero es positivo                         **/
/**                                                         **/
/*************************************************************/

#include <iostream>

using namespace std;

struct Vector{
	int * vector;
	int capacidad = 0;
};

/******************************************************************************/

enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};
int * Redimensiona (int * p, TipoRedimension tipo, int & cap);
Vector * CalcularPrimosMenoresQue (int );
Vector * DescomposicionPrimos (int , int = 100);

/******************************************************************************/

int main(int argc, char * argv[]){

	int numero = 102, tope = 100;

	if (argc > 3){
		cout << "ERROR: Numero erroneo de argumentos " << endl;
		exit(1);
	}else if (argc > 2){
		numero = atoi (argv[1]);
		tope = atoi (argv[2]);
	}else if (argc > 1){
		numero = atoi (argv[1]);
	}else{
		cout << "ERROR: Numero erroneo de argumentos " << endl;
		exit(1);
	}

	Vector * v = DescomposicionPrimos (numero, tope);

	for (int i = 0; i < v->capacidad; i++){
		cout << v->vector[i] << " ";
	}

	delete v->vector;

	delete v;

	return 0;
}

/******************************************************************************/

Vector * CalcularPrimosMenoresQue (int numero){
	numero--;
	int * num = new int [numero];


	Vector * vector_primos = new Vector;


	vector_primos->vector = new int [vector_primos->capacidad];



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
			vector_primos->vector = Redimensiona (vector_primos->vector,
			                                     TipoRedimension::DeUnoEnUno,
															 vector_primos->capacidad);
			vector_primos->vector[vector_primos->capacidad - 1] = num[i];
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

/******************************************************************************/

Vector * DescomposicionPrimos(int numero, int tope){
	Vector * descomposicion = new Vector;
	Vector * primos = CalcularPrimosMenoresQue (tope);


	int multiplicacion_total = 1;
	int copia_num = numero;
	int i = 0;

	while (multiplicacion_total != numero && i < primos->capacidad){
		if (copia_num % primos->vector[i] == 0 ){
			multiplicacion_total = multiplicacion_total * primos->vector[i]; 

			descomposicion->vector = Redimensiona (descomposicion->vector,
			                                     TipoRedimension::DeUnoEnUno,
															 descomposicion->capacidad);
			descomposicion->vector[descomposicion->capacidad - 1] = primos->vector[i];

			copia_num = copia_num / primos->vector[i];
		}
		else
			i++;
	}

	delete primos->vector;
	delete primos;


	if (multiplicacion_total != numero){
		delete descomposicion;

		return new Vector; 
	}

	return descomposicion;
}
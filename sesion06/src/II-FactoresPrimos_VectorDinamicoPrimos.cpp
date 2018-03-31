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

	if (v->capacidad == 0)
		cout << "No se ha podido descomponer el numero " << numero
		     << " con el tope de " << tope << endl
			  << "Pruebe a cambiar de tope."; 

	for (int i = 0; i < v->capacidad; i++){
		cout << v->vector[i] << " ";
	}

	delete v->vector;

	delete v;

	return 0;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Calculamos los numeros primos menores que numero      **/
/**  usando la el metodo de la criba de Eratostenes         **/
/**                                                         **/
/**   Recibe: Numero entero                                 **/
/**                                                         **/
/**   Devuelve: Puntero a dato tipo Vector que contiene     **/
/**            el vector de primos y su capacidad           **/
/**                                                         **/
/*************************************************************/

Vector * CalcularPrimosMenoresQue (int numero){
	int * num = new int [numero];


	Vector * vector_primos = new Vector;

	//En principio el vector primos tendra capacidad 0
	vector_primos->vector = new int [vector_primos->capacidad];

	//Rellenamos un vector de numeros, desde el 2 hasta el numero que queremos
	for (int i = 0; i < numero; i++){
		num [i] = i + 2;
	}


	//Marcamos con -1 los que sean multiplos de los no tachados,
	//aplicando asi la criba
	for (int i = 0;i < numero; i++){
		if (num [i] != -1){
			for (int j = i; j < numero; j++){
				if (num[j] != -1)
					if (num [j] != num [i] && num[j] % num[i] == 0)
						num [j] = -1;
			}
		}
	}

	//Los numeros no tachados, son primos, luego los almacenamos en el vector
	//de primos, que adaptara su tamaño para cada nuevo elemento
	for(int i = 0; i < numero; i++){
		if (num[i] != -1){
			vector_primos->vector = Redimensiona (vector_primos->vector,
			                                     TipoRedimension::DeUnoEnUno,
															 vector_primos->capacidad);
			vector_primos->vector[vector_primos->capacidad - 1] = num[i];
		}
	}

	//Liberamos el vector de numeros, nos es inutil
	delete [] num;


	return vector_primos;
}

/******************************************************************************/


/*************************************************************/
/**                                                         **/
/**   Redimensiona un vector de int                         **/
/**                                                         **/
/**   Recibe: Vector a redimensionar                        **/
/**           Tipo de redimension a realizar                **/
/**           Capacidad del vector                          **/
/**                                                         **/
/**   Devuelve: Direccion de memoria del vector             **/
/**             redimensionado                              **/
/**                                                         **/
/*************************************************************/

int * Redimensiona (int * p, TipoRedimension tipo, int & cap){
	
	const int TAM_BLOQUE = 10;
	int tam_redimensionado;

	//Ajusta el tamanio del nuevo vector segun el tipo de redimension
	if (tipo == TipoRedimension::DeUnoEnUno){
		tam_redimensionado = cap + 1;
		
	}else if (tipo == TipoRedimension::EnBloques){
		tam_redimensionado = cap + TAM_BLOQUE;

	}else if (tipo == TipoRedimension::Duplicando){
		tam_redimensionado = 2 * cap;
	}

	//Declara un nuevo vector con el nuevo tamaño;
	int * nuevo_vector = new int [tam_redimensionado];

	//Copia el contenido del antiguo vector en el nuevo
	for (int i = 0; i < cap; i++){
		nuevo_vector[i] = p[i];
	}
	//Actualiza la capacidad
	cap = tam_redimensionado;

	//Libera la memoria consumida por el vector anriguo
	delete [] p;

	//Devolvemos la direccion del nuevo vector
	return nuevo_vector;
}

/******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Descompone un numero en numeros primos                **/
/**                                                         **/
/**   Recibe: Numero a descomponer                          **/
/**           Tope, numero mas grande con el que se         **/
/**          intentara la descomposicion                    **/
/**                                                         **/
/**   Devuelve: Direccion de memoria del vector             **/
/**            con la descomposicion                        **/
/**                                                         **/
/**   PRE : Solo admite numeros positivos                   **/
/**                                                         **/
/*************************************************************/

Vector * DescomposicionPrimos(int numero, int tope){
	Vector * descomposicion = new Vector;

	//Si el tope es mayor que el numero, actualizamos el tope
	if (tope > numero)
		tope = numero;
	//Buscamos los primos menores que el tope
	Vector * primos = CalcularPrimosMenoresQue (tope);



	int multiplicacion_total = 1;
	int copia_num = numero;
	int i = 0;

	//Mientras no se consiga el numero y queden primos por probar, si
	//un primo es multiplo se añade al vector con la descomposicion
	//y se vuelve a probar
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

	//Eliminamos el vector de primos
	delete primos->vector;
	delete primos;

	//Si no ha conseguido el numero, elimina la descomposicion y devuelve
	//un vector vacio, para indicar que no ha sido posible realizarlo
	if (multiplicacion_total != numero){
		delete descomposicion->vector;
		delete descomposicion;

		return new Vector; 
	}

	return descomposicion;
}
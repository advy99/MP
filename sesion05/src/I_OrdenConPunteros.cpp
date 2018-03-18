#include <iostream>
#include "GestionVector.h"
#include "Lectura.h"

using namespace std;

int main(int argc, char *argv[]){
	const int TOPE = 50; // Capacidad
	int  vec [TOPE]; // Array de datos
	int *ptr [TOPE]; // Indice al array "vector"
	char mensaje_original [] = "Vector original : "; 
	char mensaje_puntero [] = "Vector desde puntero : "; 


	int tope_inf, tope_sup;

	RellenarVectorAleatorios(vec, TOPE);

	for (int  i = 0; i < TOPE; i++){
		ptr[i] = (vec+i);
	}
	
	if(argc == 1){
		tope_inf = 0;
		tope_sup = TOPE;
	}else if(argc == 3 ){
		tope_inf = CadenaAEntero(argv[1]);
		tope_sup = CadenaAEntero(argv[2]);
	}else{
		cout << "ERROR: Numero incorrecto de argumentos." << endl;
		return 1;
	}

	Ordena(vec, ptr, tope_inf, tope_sup);
	
	MostrarVector(mensaje_original, vec, TOPE);
	
	cout << endl << endl <<  mensaje_puntero << endl;

	for (int i = 0; i < TOPE;i++){
		cout << *ptr[i] << " ";
	}


	return 0;
}
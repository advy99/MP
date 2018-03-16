#include <iostream>
#include "GestionVector.h"
#include "Lectura.h"

using namespace std;

int main(int argc, char * argv[]){
	const int TOPE = 100;
	int v1[TOPE];
	int v2[TOPE];
	int mezcla[2*TOPE];
	int tope_sup, tope_inf;
	int util_v1, util_v2, util_mezcla;
	char mensaje_v1 [] = " Vector 1 ";
	char mensaje_v2 [] = " Vector 2 "; 
	char mensaje_mezcla [] = " Vectores mezclados ";

	if ( argc == 1){
		tope_inf = 1;
		tope_sup = 100;
	}else if (argc == 2){
		tope_sup = CadenaAEntero(argv[1]);
	}else if(argc == 3){
		tope_sup = CadenaAEntero(argv[1]);
		tope_inf = CadenaAEntero(argv[2]);
	}else{
		return 1;
	}

	util_v1 = LeerEnIntervalo(TOPE);
	util_v2 = LeerEnIntervalo(TOPE);

	RellenarVectorAleatorios (v1, util_v1, tope_inf, tope_sup);
	RellenarVectorAleatorios (v2, util_v2, tope_inf, tope_sup);

	OrdenarVector(v1, util_v1);
	OrdenarVector(v2, util_v2);

	MostrarVector(mensaje_v1, v1, util_v1);
	MostrarVector(mensaje_v2, v2, util_v2);

	MezclaVectores(mezcla, util_mezcla, v1, util_v1, v2, util_v2);

	MostrarVector(mensaje_mezcla, mezcla, util_mezcla);

}

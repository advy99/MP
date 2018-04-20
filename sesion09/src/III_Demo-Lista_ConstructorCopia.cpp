/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 9 - Ejercicio 4 - Lista memoria dinamica        **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "TipoBase.h"
#include "Lista_ConstructorCopia.h"

using namespace std;

int main(){
	Lista l1;
	Lista l2(5);
	Lista l3(9,2);

	cout << "La lista l1 tiene: " << l1.NumeroNodos() << " nodos" << endl;
	cout << "La lista l2 tiene: " << l2.NumeroNodos() << " nodos" << endl;
	cout << "La lista l3 tiene: " << l3.NumeroNodos() << " nodos" << endl;

	cout << endl << endl;
	for (int i = 0; i < l3.NumeroNodos(); i++){
		cout << l3.LeerValor(i) << " ";
	}

	return 0;
}
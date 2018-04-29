/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 10 - Ejercicio 9 - PoliLinea                    **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "PoliLinea.h"

using namespace std;

int main(){
	PoliLinea mi_polilinea;
	Punto p;
	int x, y , x_ini, y_ini;
	bool seguir = true;

	cout << "Para parar, introduzca el punto inicial " << endl;

	cout << "Introduce un punto (x e y): ";
	cin >> x;
	cin >> y;

	x_ini = x;
	y_ini = y;

	while (seguir){
		p.MoverPunto(x, y);

		mi_polilinea = mi_polilinea + p;


		cout << "Introduce un punto (x e y): ";
		cin >> x;
		cin >> y;

		seguir = (x != x_ini) || (y != y_ini);
	}
	
	int pos;

	cout << "Introduce una posicion: ";
	cin >> pos;

	cout << "El punto " << pos << " es el punto " << mi_polilinea[pos].X()
        << " , " << mi_polilinea[pos].Y(); 

	
}
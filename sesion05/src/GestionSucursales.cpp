#include <iostream>
#include "GestionSucursales.h"

using namespace std;

void LeerVentas( int ventas[][PRODUCTOS] ){
	
	bool salir = false;
	char producto;
	int sucursal, num_productos;

	cout << "Introduce la sucursal : ";
	cin >> sucursal;

	salir = sucursal == -1;

	while (!salir){
		cout << "Introduce el producto : ";
		cin >> producto;
		cout << "Introduce el numero de productos vendidos : ";
		cin >> num_productos;

		ventas[sucursal][producto] = num_productos;

		cout << "Introduce la sucursal : ";
		cin >> sucursal;
		salir = sucursal == -1;
	}

}

void VentasPorSucursal(int ventas[][PRODUCTOS] , int * ventas_sucursal,
                       const int TOTAL_SUCURSALES, const int TOTAL_PRODUCTOS){
	for ( int i = 0; i < TOTAL_SUCURSALES; i++){
		for (int j = 0; j < TOTAL_PRODUCTOS; j++){
			ventas_sucursal[i] += ventas [i][j];
		}
	}
}

void VentasPorProducto(int ventas[][PRODUCTOS], int * ventas_productos,
                       const int TOTAL_SUCURSALES, const int TOTAL_PRODUCTOS){
	for ( int i = 0; i < TOTAL_SUCURSALES; i++){
		for (int j = 0; j < TOTAL_PRODUCTOS; j++){
			ventas_sucursal[j] += ventas [i][j];
		}
	}

}

int TotalVentas(int)
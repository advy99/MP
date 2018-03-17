#include <iostream>
#include "GestionSucursales.h"
#include "GestionVector.h"

using namespace std;

int main ( void ){
	const int SUCURSALES = 100;
	const char INICIO_PRODUCTOS = 'a';
	const char PRODUCTOS = 'j' + 1;

	int ventas [SUCURSALES] [PRODUCTOS] = { 0 };
	int ventas_sucursal [SUCURSALES] = { 0 };
	int ventas_productos [PRODUCTOS] = { 0 };
	int *punt_ventas[SUCURSALES];
	int sucursal_mas_ventas;

	for (int i = 0; i < SUCURSALES; i++){
		punt_ventas[i] = &ventas[i][0];
	}

	int num_operaciones = LeerVentas (punt_ventas);

	VentasPorSucursal(punt_ventas, ventas_sucursal, SUCURSALES, PRODUCTOS);
	VentasPorProducto(punt_ventas, ventas_productos, SUCURSALES, PRODUCTOS);

	sucursal_mas_ventas = PosMayor(ventas_sucursal,SUCURSALES) - ventas_sucursal;

	cout << endl << endl;
	cout << "Total de operaciones de ventas : "
	     << num_operaciones
		  << endl;
	cout << "La sucursal con mas ventas es la sucursal : "
		  << sucursal_mas_ventas << " con " 
		  << ventas_sucursal[sucursal_mas_ventas] << " ventas" << endl;

	ListadoVentas(ventas_sucursal, SUCURSALES);
	
	cout << ConVentas(ventas_sucursal, SUCURSALES) 
	     << " sucursales han tenido ventas." << endl;

	cout << "El total de las ventas por sucursal es " 
	     << SumaVentas(ventas_sucursal, SUCURSALES) << endl;	

  	ListadoVentas(ventas_productos, PRODUCTOS, false);

	cout << ConVentas(ventas_productos, PRODUCTOS) 
	     << " elementos han tenido ventas." << endl;

	cout << "El total de las ventas por productos es " 
	     << SumaVentas(ventas_productos, PRODUCTOS) << endl;	

	TablaResumen(punt_ventas,ventas_sucursal,ventas_productos, SUCURSALES, PRODUCTOS);
}
#include <iostream>
#include "GestionSucursales.h"

using namespace std;

int main ( void ){
	const int SUCURSALES = 100;
	const int PRODUCTOS = 10;

	int ventas [SUCURSALES] [PRODUCTOS] = { 0 };
	int ventas_sucursal [SUCURSALES] = { 0 };
	int ventas_productos [PRODUCTOS] = { 0 };

	LeerVentas (ventas);

	VentasPorSucursal(ventas, ventas_sucursal);
	VentasPorProducto(ventas, ventas_productos);

	
}
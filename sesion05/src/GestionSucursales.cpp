/*************************************************************/
/**																			**/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 5                                               **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include "GestionSucursales.h"

using namespace std;

/******************************************************************************/

int LeerVentas( int *ventas[] ){
	
	int num_operaciones = 0;
	bool salir = false;
	char producto;
	int sucursal, num_productos;

	cout << "Introduce la sucursal : ";
	cin >> sucursal;

	salir = sucursal == -1;

	while (!salir){
		num_operaciones++;
		cout << "Introduce el producto : ";
		cin >> producto;
		cout << "Introduce el numero de productos vendidos : ";
		cin >> num_productos;

		ventas[sucursal][producto] += num_productos;

		cout << "Introduce la sucursal : ";
		cin >> sucursal;
		salir = sucursal == -1;
	}

	return num_operaciones;
}

/******************************************************************************/

void VentasPorSucursal(int *ventas[] , int * ventas_sucursal,
                       const int TOTAL_SUCURSALES, const int TOTAL_PRODUCTOS,
							  const int INICIO_PRODUCTOS){
	for ( int i = 0; i < TOTAL_SUCURSALES; i++){
		for (int j = INICIO_PRODUCTOS; j < TOTAL_PRODUCTOS; j++){
			ventas_sucursal[i] += ventas [i][j];
		}
	}
}

/******************************************************************************/

void VentasPorProducto(int *ventas[], int * ventas_productos,
                       const int TOTAL_SUCURSALES, const int TOTAL_PRODUCTOS,
							  const int INICIO_PRODUCTOS){
	for ( int i = 0; i < TOTAL_SUCURSALES; i++){
		for (int j = INICIO_PRODUCTOS; j < TOTAL_PRODUCTOS; j++){
			ventas_productos[j] += ventas [i][j];
		}
	}

}

/******************************************************************************/

int TotalVentas(int *ventas[], const int TOTAL_SUCURSALES,
                const int TOTAL_PRODUCTOS, const int INICIO_PRODUCTOS){
	int total_ventas = 0;
	for ( int i = 0; i < TOTAL_SUCURSALES; i++){
		for (int j = INICIO_PRODUCTOS; j < TOTAL_PRODUCTOS; j++){
			total_ventas += ventas [i][j];
		}
	}
	return total_ventas;
}

/******************************************************************************/

void ListadoVentas( int *ventas, const int TOTAL,const bool POR_SUCURSAL){
	cout << endl;
	for (int i = 0; i < TOTAL; i++){
		if(*ventas != 0){
			if (POR_SUCURSAL)
				cout << i;
			else
				cout << (char) i;
			cout << " ha tenido " << *ventas << " ventas." << endl; 
		} 
		ventas++;
	}
}

/******************************************************************************/

int ConVentas(int *ventas, const int TOTAL){
	int con_ventas = 0;
	for (int i = 0; i < TOTAL; i++){
		if(*ventas != 0){
			 con_ventas++;
		} 
		ventas++;
	}

	return con_ventas;
}

/******************************************************************************/

int SumaVentas(int *ventas, const int TOTAL){
	int total = 0;
	for (int i = 0; i < TOTAL; i++){
		total += *ventas;
		ventas++;
	}

	return total;
}

/******************************************************************************/

void TablaResumen(int *ventas[],int *v_sucursal,int *v_producto,
                  const int SUCURSALES, const int PRODUCTOS,
                  const int INICIO_PRODUCTOS){
	int *p_sucursal = v_sucursal;
	int *p_producto = v_producto + INICIO_PRODUCTOS;
	bool mostrar[PRODUCTOS-INICIO_PRODUCTOS] = {false};
	cout << endl << endl;
	cout <<  "  " << "|" ;

	for(int i = INICIO_PRODUCTOS; i < PRODUCTOS; i++){
		if (*p_producto != 0){
			cout << "  " << (char) i << " ";
			mostrar[i-INICIO_PRODUCTOS] = true;
		}
		p_producto++;
	}
	p_producto = v_producto + INICIO_PRODUCTOS;
	cout <<  " " << "|"  << endl;
	cout << "------------------------------------------"<< endl;

	for(int i = 0; i < SUCURSALES; i++){
		if(*p_sucursal != 0){
			cout << i << " | ";

			int j = INICIO_PRODUCTOS;
			while(j < PRODUCTOS){
				if(mostrar[j-INICIO_PRODUCTOS])
					cout << "  " << ventas[i][j] << " ";
				j++;
			}
			cout << "   | " << *p_sucursal;
			cout << endl;
		}
		p_sucursal++;
	}
	cout << "------------------------------------------"<< endl;
	cout << "  |  ";
	for (int i = INICIO_PRODUCTOS; i < PRODUCTOS; i++){
		if(mostrar[i-INICIO_PRODUCTOS])
			cout << " " << *p_producto << " ";
		p_producto++;
	}
	cout << "  |  " << SumaVentas(v_sucursal,SUCURSALES);

}
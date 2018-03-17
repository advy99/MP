#ifndef GESTIONSUCURSALES
#define GESTIONSUCURSALES

/*******************************************************************************/

int LeerVentas( int **);
void VentasPorSucursal(int **, int *, const int, const int, const int = 'a');
void VentasPorProducto(int **, int *, const int, const int, const int = 'a');
int TotalVentas(int **, const int, const int, const int = 'a');
void ListadoVentas(int * , const int, const bool = true);
int ConVentas(int *, const int);
int SumaVentas(int *, const int);
void TablaResumen(int **,int *,int *, const int,const int, const int = 'a');

/*******************************************************************************/

#endif
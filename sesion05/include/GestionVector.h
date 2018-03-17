#ifndef GESTIONVECTOR
#define GESTIONVECTOR

/************************************************************/

void MostrarVector (char *, int *, const int, int = 0);
void RellenarVectorAleatorios(int *, const int ,const int = 1, const int = 500);
void MinMaxVector(int *, const int, const int, int &, int &);
int * PosMayor (int *,const int ,const int = 0 );
void OrdenarVector(int * ,const int);
void MezclaVectores (int *,int &, int *, int , int *, int );

/************************************************************/

#endif
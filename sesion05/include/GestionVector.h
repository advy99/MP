/*************************************************************/
/**																			**/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 5                                               **/
/**                                                         **/
/*************************************************************/

#ifndef GESTIONVECTOR
#define GESTIONVECTOR

/************************************************************/

void MostrarVector (char *, int *, const int, int = 0);
void RellenarVectorAleatorios(int *, const int ,const int = 1, const int = 500);
void MinMaxVector(int *, const int, const int, int &, int &);
int * PosMayor (int *,const int ,const int = 0 );
void OrdenarVector(int * ,const int);
void MezclaVectores (int *,int &, int *, int , int *, int );
void Ordena (int *, int **, int , int );

/************************************************************/

#endif
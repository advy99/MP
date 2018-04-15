/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 8 - Listas                                      **/
/**                                                         **/
/*************************************************************/

#ifndef LISTA
#define LISTA

#include "TipoBase.h"

struct Nodo{
	TipoBase valor;
	Nodo *sig;
};

typedef Nodo * PNodo;
typedef Nodo * Lista;

void LeeLista (Lista & l);
void PintaLista (const Lista l);
void LiberaLista (Lista & l);
bool ListaVacia (const Lista l);
int  CuentaElementos (const Lista l);

bool EstaOrdenada (const Lista l);
void OrdenaSeleccionLista (Lista &l);

bool ExisteElemento (const Lista & l, const TipoBase v );
void InsertaOrdenadamente (Lista &l, TipoBase v);
void EliminaValor (Lista &l, TipoBase v);

void MezclaListas (Lista &l, Lista &l1, Lista &l2);


#endif
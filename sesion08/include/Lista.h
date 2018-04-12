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


#endif
#ifndef REDIMENSIONVECTOR
#define REDIMENSIONVECTOR

#include "TipoBase.h"

enum class TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};

Vector Redimensiona(Vector , TipoRedimension, int &);

#endif
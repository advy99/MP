#ifndef UTIL
#define UTIL

#include <string>

using namespace std;


/***************************************************************************/
// Dos números son reales si su diferencia (en valor absoluto) es menor 
// que el valor de la constante PRECISION_SON_IGUALES

const double PRECISION_SON_IGUALES = 1e-6; // 0.000001

/***************************************************************************/


/***************************************************************************/
// Función (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos números reales muy próximos sean considerados iguales.

bool SonIguales(double uno, double otro);

/***************************************************************************/
// Comprueba la  existencia y disponibilidad de un fichero

bool ExisteFichero (const char *nombre);
bool ExisteFichero (const string & nombre);


/***************************************************************************/
// Calcula el tamaño (número de bytes) de un fichero. 

int TamanioFichero (const char * nombre);
int TamanioFichero (string nombre);

/***************************************************************************/
// Lee y devuelve un número. Termina si se lee un valor correcto o EOF.
// Recibe: msg, el mensaje que etiqueta la lectura  

double LeeNumeroReal (const char * msg);
double LeeNumeroEntero (const char * msg);

/***************************************************************************/

#endif

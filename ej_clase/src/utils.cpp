/*********************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// PRÁCTICA 1
/*	
	Ejemplo de fichero .cpp usado para crear un .obj que se incorpora 
	a una biblioteca .a
*/
/*********************************************************************/

#include "utils.h"

/*********************************************************************/
// Calcula la división entera 
// PRE: dividendo > 0  y divisor > 0 

int DivisionEntera (int dividendo, int divisor)
{
	/*
	Idea: Hay que plantearlo como la solución al siguiente problema:

		¿Cuantas veces puedo quitarle "divisor" a "dividendo" sin 
		llegar a un negativo? 

		En definitiva se trata de CONTAR el número de veces que es posible 
		realizar esta resta,m por lo que cada ejecución sumará uno.  

		Caso base:		Si "dividendo" < "divisor", la solución es 0
		Caso general:	Hallar la solución a la división entera entre 
						"dividendo"-"divisor" y "divisor", y sumarle 1

	*/

	int dif = dividendo - divisor;

	if (dif < 0)	// No puedo seguir restando más 
		return (0);
	else
		return (1 + DivisionEntera(dif, divisor));	// Sumar uno
}

/*********************************************************************/
// Calcula el resto de la división entera 
// PRE: dividendo > 0  y divisor > 0 

int RestoDivision (int dividendo, int divisor)
{

	/*
    Idea: Hay que plantearlo como la solución al siguiente problema:
            
		¿Qué queda después de quitarle divisor a dividendo tantas 
		veces como se pueda sin llegar a un negativo?

		No estamos interesados en saber CUÁNTAS VECES podemos hacer 
		esta sustracción, sino en saber el resultado de la ÚLTIMA 
		resta. Por eso, el valor de la diferencia del caso base es el 
		que se devuelve SIN MODIFICACIONES como solución final. 

		Caso base:		Si "dividendo" < "divisor", la solución es 0
		Caso general:	La solución es la misma solución que la del 
						problema de calcular el resto de la división 
						entre "dividendo"-"divisor" y "divisor"
   */

	if (dividendo - divisor < 0)	// No puedo seguir restando más 
		return (dividendo);			// Este valor será el resultado final
	else
		return RestoDivision(dividendo-divisor, divisor);
}

/*********************************************************************/
 

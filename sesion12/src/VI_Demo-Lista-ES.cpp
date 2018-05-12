/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2017-2018
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 6
//
// Demostración de la funcionalidad de la clase Lista.
// La clase Lista ha sido ampliada con los métodos:
// 
//  	Lista (const char * nombre);
//		void EscribirLista (const char * nombre) const;
//		void LeerLista (const char * nombre);
//
// Fichero: IV_Demo-Lista-ES.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	Lista lista(5);

	PintaLista (lista, "Despues de crear la lista con tamaño 5");
	cout << "Tamanio = " << lista.Tamanio() << endl;

	lista = 0;
	PintaLista (lista, "Despues de lista = 0");

	lista.Inserta(7,2);
	PintaLista (lista, "Despues de lista.Inserta(7,2)");
	cout << "Tamanio = " << lista.Tamanio() << endl;	

	lista.Inserta(9,lista.Tamanio()+1);
	PintaLista (lista, "Despues de lista.Inserta(9, lista.Tamanio()+1)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	
	lista.Inserta(6,3);
	PintaLista (lista, "Despues de lista.Inserta(6,3)");
	cout << "Tamanio = " << lista.Tamanio() << endl;
	
	PintaLista (lista, "Mostrando informacion");
	cout << "Tamanio = " << lista.Tamanio() << endl;

	for (int pos=1; pos<=lista.Tamanio(); pos++)
		cout << "Elemento " << setw(2) << pos 
		     << " = " << setw (3) << lista(pos)<< endl;
	cout << endl;

	// Guardar lista en un fichero

	lista.EscribirLista ("datos_de_lista.txt");

	PintaLista (lista, "Despues de lista.EscribirLista(---)");


	// Constructor leyendo datos de un fichero

	Lista lista_leida ("datos_de_lista.txt");

	PintaLista (lista_leida, "Despues de crear lista_leida");


	if (lista != lista_leida) 
		cout << "Ha habido algun problema guardando o leyendo datos." << endl;
	else 
		cout << "Perfecto: se ha guardado y leido correctamente." << endl;
	cout <<  endl;


	// Prueba del metodo de lectura desde un fichero

	Lista otra_lista_leida;

	otra_lista_leida.LeerLista ("datos_de_lista.txt");

	PintaLista (otra_lista_leida, "Despues de leer con LeerLista(---)");


	if (lista != otra_lista_leida) 
		cout << "Ha habido algun problema guardando o leyendo datos." << endl;
	else 
		cout << "Perfecto: se ha guardado y leido correctamente." << endl;
	cout <<  endl;


	cout <<  endl;

	return (0);
}

/***************************************************************************/
/***************************************************************************/
